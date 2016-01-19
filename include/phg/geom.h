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

/* $Id: geom.h,v 1.1 2014/04/04 04:30:01 zlb Exp $ */

#ifndef PHG_GEOM_H

#ifdef __cplusplus
extern "C" {
#endif

PHG_EXTERN void _phg_compute_elem_data(const GRID *g, const ELEMENT *e,
					FLOAT *vol, FLOAT *diam);

PHG_EXTERN void phgGeomSaveNonLeafData_(GRID *g);
PHG_EXTERN void phgGeomClearNonLeafData_(void);

PHG_EXTERN void phgGeomCheck(GRID *g);
PHG_EXTERN void  phgGeomInit_(GRID *g, BOOLEAN init_data);
#define phgGeomInit(g)	phgGeomInit_(g, TRUE)
PHG_EXTERN FLOAT phgGeomGetVolume(GRID *g, ELEMENT *e);
PHG_EXTERN FLOAT phgGeomGetDiameter(GRID *g, ELEMENT *e);
#define phgGeomGetJacobian(g, e)               \
    phgGeomGetJacobian_(g, e, NULL, NULL)    
PHG_EXTERN const FLOAT *phgGeomGetJacobian_(GRID *g, SIMPLEX *e, const FLOAT *lambda, FLOAT *det);
#define phgGeomGetFaceArea(g, e, face_no)	\
    phgGeomGetFaceArea_(g, e, face_no, NULL, NULL)
PHG_EXTERN FLOAT phgGeomGetFaceArea_(GRID *g, SIMPLEX *e, int face, const FLOAT *lambda, FLOAT *normal);
PHG_EXTERN FLOAT phgGeomGetFaceAreaByIndex(GRID *g, INT face_no);
PHG_EXTERN FLOAT phgGeomGetFaceDiameter(GRID *g, ELEMENT *e, int face);
PHG_EXTERN const FLOAT *phgGeomGetFaceNormal(GRID *g, ELEMENT *e, int face);
PHG_EXTERN const FLOAT *phgGeomGetFaceOutNormal(GRID *g, ELEMENT *e, int face);
PHG_EXTERN const FLOAT *phgGeomXYZ2Lambda(GRID *g, ELEMENT *e, FLOAT x, FLOAT y, FLOAT z);
PHG_EXTERN void  phgGeomLambda2XYZ(GRID *g ,ELEMENT *e, const FLOAT *lambda,
				FLOAT *x, FLOAT *y, FLOAT *z);

#ifdef __cplusplus
}
#endif

#define PHG_GEOM_H
#endif
