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

/* $Id: grid.h,v 1.1 2014/04/04 04:30:01 zlb Exp $ */

#ifndef PHG_GRID_H

typedef struct SIMPLE_TET_ {
    int verts[4];
    BTYPE bound_type[4];
} SIMPLE_TET;

PHG_EXTERN GRID *phgImportParallelGrid(int nvert, int nelem,
			    int nvert_global, int nelem_global,
			    INT *L2Gmap_vert, INT *L2Gmap_elem,
			    double *coord, SIMPLE_TET *tet,
			    MPI_Comm comm);

PHG_EXTERN GRID *phgGetSubGrid(GRID *g, BOOLEAN *elem_marker);



#define PHG_GRID_H
#endif

