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

/* $Id: hp.h,v 1.1 2014/04/04 04:30:01 zlb Exp $ */

#ifndef PHG_HP_H
#define PHG_HP_H

struct HP_INFO_ {
    DOF_TYPE	**types;	/* DOF_TYPE* array */
    const char	*name;		/* name */
    FE_SPACE	fe_space;	/* finite element space */
    BYTE	dim;		/* space dimensions (1 or 3) */
    BYTE	min_order;	/* minimum order available */
    BYTE	max_order;	/* maximum order available */
};

/* Note: It is assumed at present that the order on the vertices is constant */

struct HP_TYPE_ {
    /* caches for 3D quadrature */
    void	*cache_basfunc, *cache_basgrad; /* cached bases & D/Dlambda */
    void	*cache_gradient, *cache_curl;   /* cached D/Dxyz */

    GRID	*g;		/* pointer to the GRID object */
    HP_INFO	*info;		/* pointer to HP_INFO struct */
    DOF		**dof;		/* NULL terminated list of DOFs attached to
				 * the HP_TYPE */
    BOOLEAN	derived;	/* whether it is a derived HP_TYPE */
    struct HP_TYPE_ *derivative; /* != NULL ==> HP_TYPE with orders - 1 */
    struct HP_TYPE_ *dg;	/* != NULL ==> DG HP_TYPE of the same order */

    /* lists of orders */
    BYTE	*edge_order;	/* list of basis orders on edges */
    BYTE	*face_order;	/* list of basis orders on faces */
    BYTE	*elem_order;	/* list of basis orders on elements */

    /* indices to DOF data */
    INT		*edge_index;	/* indices of edge DOF data */
    INT		*face_index;	/* indices of face DOF data */
    INT		*elem_index;	/* indices of element DOF data */

    /* global data counts */
    INT		edge_data_count_global;
    INT		face_data_count_global;
    INT		elem_data_count_global;

    /* other informations */
    size_t	refcount;
    char	*srcfile;	/* source file */
    int		srcline;	/* source line number */
    SHORT	id;		/* used during mesh refinement/coarsening */
    BYTE	min_order, max_order;
};

#ifdef __cplusplus
extern "C" {
#endif

PHG_EXTERN HP_TYPE *phgHPNew_(GRID *g, HP_INFO *info, int order,
				const char *file, int line);
#define phgHPNew(g, info) \
	phgHPNew_(g, info, (info)->min_order, __FILE__, __LINE__)

PHG_EXTERN void phgHPSetupDataPointers_(HP_TYPE *hp, INT nedge, INT nface, INT nelem,
				BOOLEAN use_types, BOOLEAN update_counters);
#define phgHPSetupDataPointers(hp) \
	phgHPSetupDataPointers_(hp, hp->g->nedge, hp->g->nface, hp->g->nelem, \
				TRUE, TRUE)
PHG_EXTERN void phgHPSetupOrders(HP_TYPE *hp);

PHG_EXTERN HP_TYPE *phgHPGetDerivative_(HP_TYPE *old_hp, const char *srcfile, int srcline);
#define phgHPGetDerivative(old_hp) \
	phgHPGetDerivative_(old_hp, __FILE__, __LINE__)

PHG_EXTERN HP_TYPE *phgHPGetDG_(HP_TYPE *old_hp, const char *srcfile, int srcline);
#define phgHPGetDG(old_hp) \
	phgHPGetDG_(old_hp, __FILE__, __LINE__)

PHG_EXTERN void phgHPSetup(HP_TYPE *hp, BOOLEAN interpolate);
PHG_EXTERN void phgHPAttachDof(HP_TYPE *hp, DOF *u, BOOLEAN interpolate);
PHG_EXTERN HP_TYPE *phgHPDup__(HP_TYPE *hp, BOOLEAN free_orig_data);
PHG_EXTERN void phgHPFreeBuffers__(HP_TYPE *hp);
PHG_EXTERN void phgHPFree(HP_TYPE **hp_ptr);

#ifdef __cplusplus
}
#endif

#endif	/* PHG_HP_H */
