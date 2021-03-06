/* Parallel Hierarchical Grid -- an adaptive finite element library.
 *
 * Copyright (C) 2005-2010 State Key Laboratory of Scientific and
 * Engineering Computing, Chinese Academy of Sciences. */

/* This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA  02110-1301  USA */

/* $Id: map.h,v 1.1 2014/04/04 04:30:01 zlb Exp $ */

#ifndef PHG_MAP_H

#if USE_MPI
typedef struct COMM_INFO_ {
    INT		*sind;
    const INT	*rind;		/* same pointer as map->ordering */
    int		*scnts, *sdsps, *rcnts, *rdsps;
    MPI_Request	*requests;
    FLOAT	*buffer;
    MPI_Comm	comm;
    INT		ssize, rsize, size;
    int		nsends, nrecvs;
} COMM_INFO;
#endif	/* USE_MPI */

/* The MAP struct for handling DOFs ==> VEC mapping
 *
 * - The DOF index of an unknown is just it's natural numbering in the DOF
 *   For multiple DOFs map, the DOF indices are simply concatenated.
 *   The member offsets[ndof] records starting index for each DOF in the map.
 *
 * - The local indices are obtained by (optionally) removing the unreferenced
 *   and periodic DOF from the DOF indices. The size of local indices is
 *   stored in the member 'localsize', which is equal to the sum of
 *   DofGetDataCount(dofs) minus the number of unreferenced and periodic DOF.
 *   The optional array D2Lmap maps a DOF index to its local index. 
 *
 *   The user should always use the macro phgMapD2L to map DOF indices to
 *   local indices.
 *
 * - The vector is partitioned into blocks, each process holds a (local) block
 *   which is composed of the DOF owned by the process. The vector indices
 *   are assigned to owned DOF in each process. The size of the local block
 *   is stored in the member 'nlocal'.
 *
 * - The member 'partition' stores vector partitioning, partition[rank] is
 *   the starting global vector index for process 'rank', partition[nprocs]
 *   is the global length of the vector. The 'partition' member is identical
 *   across all processes.
 *
 *   If nprocs == 1, the DOF indices, local indices, and vector indices are
 *   all identical.
 *
 *   The array L2Vmap[localsize] maps a local index to its vector index,
 *   in the range [0, nlocal - 1] if the unknown is owned by the submesh,
 *   and in the range [nlocal, localsize - 1] if the unknown is not owned
 *   by the submesh (off-process entry), for the latter case, the array
 *   O2Gmap[localsize - nlocal] is used to map the unknown to its global
 *   index. L2Vmap may be NULL if the local and vector indices are the same.
 *
 * The maps between different kinds of indices are illustrated by the following
 * diagram:
 *
 *		      phgDofMapE2D		    phgMapD2L
 *	elem index -----------------> DOF index ----------------> local index
 *						 offsets/D2Lmap
 *
 *	    L2Vmap			       O2Gmap
 *	---------------> local vector index ------------> global vector index
 *					      partition
 */
typedef struct MAP_ {
    FLOAT	lif;		/* load imbalance factor */
    DOF		**dofs;		/* list of DOFs ([ndof]) */

    struct MAP_	*map_nb;	/* the map with bdry entries removed */

    INT		*D2Lmap;	/* DOF index to local index map ([D2Lmap_size],
				   removing unreferenced and duplicate periodic
				   entries) */
    INT		*L2Vmap;	/* local index to local vector index map
				   ([L2Vmap_size], taking into account SFC
				   reordering, and removing Dirichlet boundary
				   entries (mapped to -1) in map_nb) */
    INT		*O2Gmap;	/* local-vector to global index map for
				   off-process entries ([localsize - nlocal]) */
    INT		*ordering;	/* O2Gmap[ordering[.]] is increasing
				   ([localsize - nlocal])*/
    INT		*partition;	/* vector partitioning ([nprocs + 1]) */

#if USE_MPI
    COMM_INFO	*cinfo;		/* for gathering/scattering of vectors */
#endif	/* USE_MPI */

    INT		*offset;	/* offset[i] = first local index of dofs[i]
				   ([ndof]) */

    INT		*bdry;		/* sorted vector indices of boundary entries
				   ([bdry_localsize]])*/
    INT		*bdry_partition;/* partitioning of boundary rows ([nprocs+1]) */
    INT		bdry_nlocal;	/* number of boundary entries owned */
    INT		bdry_localsize;	/* total number of local boundary entries */
    INT		bdry_nglobal;	/* global number of boundary entries */

    INT		D2Lmap_size;	/* size of D2Lmap (sum of DOF) */
    INT		L2Vmap_size;	/* size of L2Vmap (range of D2Lmap[]),
				   normally equals localsize, unless altered by,
				   e.g., phgMapRemoveBoundaries() */

    INT		nlocal;		/* local matrix/vector size */
    INT		nglobal;	/* global matrix/vector size */
    INT		localsize;	/* local size, including off-proc entries */

    MPI_Comm	comm;
    int		rank, nprocs;

    int		refcount;	/* reference count */
    BYTE	ndof;		/* number of DOFs in 'dofs[]' */
} MAP;

#ifdef __cplusplus
extern "C" {
#endif

PHG_EXTERN INT phgMapL2G(MAP *map, INT index);
#define phgMapD2L(map, dof_no, index) \
	((map)->D2Lmap == NULL ? (map)->offset[dof_no] + index : \
				 (map)->D2Lmap[(map)->offset[dof_no] + index])

#define phgMapE2L_(map, dof_no, e, index, flag) \
	phgMapD2L(map, dof_no, \
		  phgDofMapE2D_((map)->dofs[dof_no], e, index, flag))
#define phgMapE2L(map, dof_no, e, index) phgMapE2L_(map, dof_no, e, index, TRUE)

#define phgMapE2G_(map, dof_no, e, index, flag) \
	phgMapL2G(map, phgMapE2L_(map, dof_no, e, index, flag))
#define phgMapE2G(map, dof_no, e, index) phgMapE2G_(map, dof_no, e, index, TRUE)

#define phgMapL2V(map, index) \
	((map)->L2Vmap == NULL ? (index) : (map)->L2Vmap[index])
#define phgMapD2V(map, dof_no, index) \
	phgMapL2V(map, phgMapD2L(map, dof_no, index))
#define phgMapD2G(map, dof_no, index) \
	phgMapL2G(map, phgMapD2L(map, dof_no, index))

PHG_EXTERN void _phg_build_ordering(size_t size, const INT map[], INT **ordering);
PHG_EXTERN MAP *phgMapCreateSimpleMap(MPI_Comm comm, INT n, INT N);
PHG_EXTERN MAP *phgMapCreateN(int ndof, DOF **dofs);
PHG_EXTERN MAP *phgMapCreate(DOF *u, ...);
PHG_EXTERN void phgMapDestroy(MAP **map_ptr);

PHG_EXTERN MAP *phgMapRemoveBoundaryEntries_(MAP *map, BOOLEAN dof_flag);
#define phgMapRemoveBoundaryEntries(m) phgMapRemoveBoundaryEntries_(m, TRUE)

#if USE_MPI
PHG_EXTERN COMM_INFO *phgMapCreateCommInfo(MPI_Comm comm, int nprocs, int rank,
	INT nlocal, INT localsize, const INT O2Gmap[], const INT ordering[],
	const INT partition[]);
PHG_EXTERN void phgMapDestroyCommInfo(COMM_INFO **cinfo);

PHG_EXTERN void phgMapGatherBegin(COMM_INFO *cinfo, int nvec, FLOAT *data,
			FLOAT *offp_data);
PHG_EXTERN void phgMapGatherEnd(COMM_INFO *cinfo, int nvec, FLOAT *data,
			FLOAT *offp_data);
PHG_EXTERN void phgMapGather(COMM_INFO *cinfo, int nvec, FLOAT *data, FLOAT *offp_data);

PHG_EXTERN void phgMapScatterBegin(COMM_INFO *cinfo, int nvec, FLOAT *data,
			FLOAT *offp_data);
PHG_EXTERN void phgMapScatterEnd(COMM_INFO *cinfo, int nvec, FLOAT *data,
			FLOAT *offp_data);
PHG_EXTERN void phgMapScatter(COMM_INFO *cinfo, int nvec, FLOAT *data, FLOAT *offp_data);
#endif	/* USE_MPI */

PHG_EXTERN int phgMapLocalDataToDof(MAP *map, int ndof, DOF **dofs, FLOAT *data);
PHG_EXTERN int phgMapDofToLocalData(MAP *map, int ndof, DOF **dofs, FLOAT *data);

PHG_EXTERN VEC *phgMapDofArraysToVecN(MAP *map, int nvec, BOOLEAN remove_bdry,
				VEC **vecptr, int ndof, DOF ***dofs);
PHG_EXTERN VEC *phgMapDofArraysToVec(MAP *map, int nvec, BOOLEAN remove_bdry,
				VEC **vecptr, DOF **u, ...);
PHG_EXTERN void phgMapVecToDofArraysN(MAP *map, VEC *vec, BOOLEAN remove_bdry,
				int ndof, DOF ***dofs);
PHG_EXTERN void phgMapVecToDofArrays(MAP *map, VEC *vec, BOOLEAN remove_bdry, DOF **u,...);

PHG_EXTERN VEC *phgMapCreateVec(MAP *map, int nvec);
PHG_EXTERN MAT *phgMapCreateMat(MAP *rmap, MAP *cmap);
PHG_EXTERN MAT *phgMapCreateMatrixFreeMat(MAP *rmap, MAP *cmap, MV_FUNC mv_func,
	void *mv_data, ...);

PHG_EXTERN BOOLEAN phgMapCompare(MAP *map1, MAP *map2);

#ifdef __cplusplus
}
#endif

#ifdef NEED_GetVariableArgs

# define MAX_ARGS 255

# define GetVariableArgs0(narg, args, u, type, ap) 			\
    (args) = phgAlloc(MAX_ARGS * sizeof(*(args)));			\
    for ((narg) = 0; (narg) < MAX_ARGS; (narg)++) {			\
	if (u == NULL)							\
	    break;							\
	args[narg] = u;							\
	u = va_arg(ap, type);						\
    }									\
    (args) = phgRealloc_(args, (narg) * sizeof(*(args)),		\
			 (narg) * sizeof(*(args)));

# define GetVariableArgs(narg, args, u, type) {				\
    va_list ap;								\
    va_start(ap, u);							\
    GetVariableArgs0(narg, args, u, type, ap)				\
    va_end(ap);								\
}

#endif	/* NEED_GetVariableArgs */

#define PHG_MAP_H
#endif
