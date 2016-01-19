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

/* $Id: quad.h,v 1.5 2014/10/21 03:00:08 zlb Exp $ */

#ifndef PHG_QUAD_H

typedef struct QUAD_ {
    char *name;			/* name of the quadrature formulae */
    int dim;			/* dimension, 1: edge, 2: face, 3: tetra */
    int order;			/* exact for polynomials of order 'order' */
    int npoints;		/* number of points */
    FLOAT *points;		/* barycentric coordinates of quad. points */
    FLOAT *weights;		/* weights */
    SHORT id;			/* id (for use with reference count) */
} QUAD;

typedef struct {
    ELEMENT *e;			/* cache at element 'e' */
    FLOAT *data;		/* cached values */
} QUAD_CACHE;

typedef struct {
    QUAD_CACHE **caches;
    SHORT n;
} QUAD_CACHE_LIST;

#define QUAD_DEFAULT	-1

/* 1D quadrature rules */
PHG_EXTERN extern QUAD QUAD_1D_P1_;
#define QUAD_1D_P1 (&QUAD_1D_P1_)
PHG_EXTERN extern QUAD QUAD_1D_P3_;
#define QUAD_1D_P2 (&QUAD_1D_P3_)
#define QUAD_1D_P3 (&QUAD_1D_P3_)
PHG_EXTERN extern QUAD QUAD_1D_P5_;
#define QUAD_1D_P4 (&QUAD_1D_P5_)
#define QUAD_1D_P5 (&QUAD_1D_P5_)
PHG_EXTERN extern QUAD QUAD_1D_P7_;
#define QUAD_1D_P6 (&QUAD_1D_P7_)
#define QUAD_1D_P7 (&QUAD_1D_P7_)
PHG_EXTERN extern QUAD QUAD_1D_P9_;
#define QUAD_1D_P8 (&QUAD_1D_P9_)
#define QUAD_1D_P9 (&QUAD_1D_P9_)
PHG_EXTERN extern QUAD QUAD_1D_P11_;
#define QUAD_1D_P10 (&QUAD_1D_P11_)
#define QUAD_1D_P11 (&QUAD_1D_P11_)
PHG_EXTERN extern QUAD QUAD_1D_P13_;
#define QUAD_1D_P12 (&QUAD_1D_P13_)
#define QUAD_1D_P13 (&QUAD_1D_P13_)
PHG_EXTERN extern QUAD QUAD_1D_P15_;
#define QUAD_1D_P14 (&QUAD_1D_P15_)
#define QUAD_1D_P15 (&QUAD_1D_P15_)
PHG_EXTERN extern QUAD QUAD_1D_P17_;
#define QUAD_1D_P16 (&QUAD_1D_P17_)
#define QUAD_1D_P17 (&QUAD_1D_P17_)
PHG_EXTERN extern QUAD QUAD_1D_P19_;
#define QUAD_1D_P18 (&QUAD_1D_P19_)
#define QUAD_1D_P19 (&QUAD_1D_P19_)
PHG_EXTERN extern QUAD QUAD_1D_P21_;
#define QUAD_1D_P20 (&QUAD_1D_P21_)
#define QUAD_1D_P21 (&QUAD_1D_P21_)

/* 2D quadrature rules */
PHG_EXTERN extern QUAD QUAD_2D_P1_;
#define QUAD_2D_P1 (&QUAD_2D_P1_)
PHG_EXTERN extern QUAD QUAD_2D_P2_;
#define QUAD_2D_P2 (&QUAD_2D_P2_)
PHG_EXTERN extern QUAD QUAD_2D_P3_;
#define QUAD_2D_P3 (&QUAD_2D_P3_)
PHG_EXTERN extern QUAD QUAD_2D_P4_;
#define QUAD_2D_P4 (&QUAD_2D_P4_)
PHG_EXTERN extern QUAD QUAD_2D_P5_;
#define QUAD_2D_P5 (&QUAD_2D_P5_)
PHG_EXTERN extern QUAD QUAD_2D_P6_;
#define QUAD_2D_P6 (&QUAD_2D_P6_)
PHG_EXTERN extern QUAD QUAD_2D_P7_;
#define QUAD_2D_P7 (&QUAD_2D_P7_)
PHG_EXTERN extern QUAD QUAD_2D_P8_;
#define QUAD_2D_P8 (&QUAD_2D_P8_)
PHG_EXTERN extern QUAD QUAD_2D_P9_;
#define QUAD_2D_P9 (&QUAD_2D_P9_)
PHG_EXTERN extern QUAD QUAD_2D_P10_;
#define QUAD_2D_P10 (&QUAD_2D_P10_)
PHG_EXTERN extern QUAD QUAD_2D_P11_;
#define QUAD_2D_P11 (&QUAD_2D_P11_)
PHG_EXTERN extern QUAD QUAD_2D_P12_;
#define QUAD_2D_P12 (&QUAD_2D_P12_)
PHG_EXTERN extern QUAD QUAD_2D_P13_;
#define QUAD_2D_P13 (&QUAD_2D_P13_)
PHG_EXTERN extern QUAD QUAD_2D_P14_;
#define QUAD_2D_P14 (&QUAD_2D_P14_)
PHG_EXTERN extern QUAD QUAD_2D_P15_;
#define QUAD_2D_P15 (&QUAD_2D_P15_)
PHG_EXTERN extern QUAD QUAD_2D_P16_;
#define QUAD_2D_P16 (&QUAD_2D_P16_)
PHG_EXTERN extern QUAD QUAD_2D_P17_;
#define QUAD_2D_P17 (&QUAD_2D_P17_)
PHG_EXTERN extern QUAD QUAD_2D_P18_;
#define QUAD_2D_P18 (&QUAD_2D_P18_)
PHG_EXTERN extern QUAD QUAD_2D_P19_;
#define QUAD_2D_P19 (&QUAD_2D_P19_)
PHG_EXTERN extern QUAD QUAD_2D_P20_;
#define QUAD_2D_P20 (&QUAD_2D_P20_)
PHG_EXTERN extern QUAD QUAD_2D_P21_;
#define QUAD_2D_P21 (&QUAD_2D_P21_)
PHG_EXTERN extern QUAD QUAD_2D_P22_;
#define QUAD_2D_P22 (&QUAD_2D_P22_)
PHG_EXTERN extern QUAD QUAD_2D_P23_;
#define QUAD_2D_P23 (&QUAD_2D_P23_)
PHG_EXTERN extern QUAD QUAD_2D_P24_;
#define QUAD_2D_P24 (&QUAD_2D_P24_)
PHG_EXTERN extern QUAD QUAD_2D_P25_;
#define QUAD_2D_P25 (&QUAD_2D_P25_)
PHG_EXTERN extern QUAD QUAD_2D_P26_;
#define QUAD_2D_P26 (&QUAD_2D_P26_)
PHG_EXTERN extern QUAD QUAD_2D_P27_;
#define QUAD_2D_P27 (&QUAD_2D_P27_)
PHG_EXTERN extern QUAD QUAD_2D_P28_;
#define QUAD_2D_P28 (&QUAD_2D_P28_)
PHG_EXTERN extern QUAD QUAD_2D_P29_;
#define QUAD_2D_P29 (&QUAD_2D_P29_)

/* 3D quadrature rules */
PHG_EXTERN extern QUAD QUAD_3D_P1_;
#define QUAD_3D_P1 (&QUAD_3D_P1_)
PHG_EXTERN extern QUAD QUAD_3D_P2_;
#define QUAD_3D_P2 (&QUAD_3D_P2_)
PHG_EXTERN extern QUAD QUAD_3D_P3_;
#define QUAD_3D_P3 (&QUAD_3D_P3_)
PHG_EXTERN extern QUAD QUAD_3D_P4_;
#define QUAD_3D_P4 (&QUAD_3D_P4_)
PHG_EXTERN extern QUAD QUAD_3D_P5_;
#define QUAD_3D_P5 (&QUAD_3D_P5_)
PHG_EXTERN extern QUAD QUAD_3D_P6_;
#define QUAD_3D_P6 (&QUAD_3D_P6_)
PHG_EXTERN extern QUAD QUAD_3D_P7_;
#define QUAD_3D_P7 (&QUAD_3D_P7_)
PHG_EXTERN extern QUAD QUAD_3D_P8_;
#define QUAD_3D_P8 (&QUAD_3D_P8_)
PHG_EXTERN extern QUAD QUAD_3D_P9_;
#define QUAD_3D_P9 (&QUAD_3D_P9_)
PHG_EXTERN extern QUAD QUAD_3D_P10_;
#define QUAD_3D_P10 (&QUAD_3D_P10_)
PHG_EXTERN extern QUAD QUAD_3D_P11_;
#define QUAD_3D_P11 (&QUAD_3D_P11_)
PHG_EXTERN extern QUAD QUAD_3D_P12_;
#define QUAD_3D_P12 (&QUAD_3D_P12_)
PHG_EXTERN extern QUAD QUAD_3D_P13_;
#define QUAD_3D_P13 (&QUAD_3D_P13_)
PHG_EXTERN extern QUAD QUAD_3D_P14_;
#define QUAD_3D_P14 (&QUAD_3D_P14_)

#ifdef __cplusplus
extern "C" {
#endif

    PHG_EXTERN void phgQuadFree(QUAD **quad);

    PHG_EXTERN void phgQuadReset(void);
    PHG_EXTERN void phgQuadClearDofCache(void **clist, QUAD *quad, BOOLEAN final);

    PHG_EXTERN QUAD *phgQuadGetQuad1D(int order);
    PHG_EXTERN QUAD *phgQuadGetQuad2D(int order);
    PHG_EXTERN QUAD *phgQuadGetQuad3D(int order);

    /* functions for caching basis functions and derivativesi or user functions
     * at quadrature points */
    PHG_EXTERN const FLOAT *phgQuadGetFuncValues(GRID *g, ELEMENT *e, int dim,
					DOF_USER_FUNC userfunc, QUAD *quad);
    PHG_EXTERN const FLOAT *phgQuadGetBasisValues(ELEMENT *e, DOF *u, int n, QUAD *quad);
    PHG_EXTERN const FLOAT *phgQuadGetBasisGradient(ELEMENT *e, DOF *u, int n, QUAD *quad);
    PHG_EXTERN const FLOAT *phgQuadGetBasisCurl(ELEMENT *e, DOF *u, int n, QUAD *quad);
    PHG_EXTERN const FLOAT *phgQuadGetDofValues(ELEMENT *e, DOF *u, QUAD *quad);

    /*-------------------- 2D functions --------------------*/
    PHG_EXTERN FLOAT phgQuadFaceDofDotBas(ELEMENT *e, int face, DOF *u, DOF_PROJ proj,
				DOF *v, int n, int order);
    PHG_EXTERN FLOAT phgQuadFaceDofABas(ELEMENT * e, int face, DOF *u, DOF *A,
			     DOF *v, int m, int order);
    PHG_EXTERN FLOAT phgQuadFaceBasDotBas(ELEMENT *e, int face, DOF *u, int n,
				DOF *v, int m, int order);
    PHG_EXTERN FLOAT phgQuadFaceBasABas(ELEMENT * e, int face, DOF *u, int n, DOF *A,
				DOF *v, int m, int order);
    PHG_EXTERN FLOAT phgQuadFaceDofDotDof(ELEMENT *e, int face, DOF *u, DOF_PROJ proj,
				DOF *v, int order);
    PHG_EXTERN FLOAT  *phgQuadFaceADofCrossDof(ELEMENT *e, int face, DOF *A, 
				DOF *u, DOF_PROJ u_proj,
				DOF *v, DOF_PROJ v_proj, 
				int order, FLOAT *reval);
    PHG_EXTERN DOF *phgQuadFaceJumpN(DOF *u, DOF_PROJ proj, const char *name, int order,
				DOF *gn);
#define phgQuadFaceJump(u, proj, name, order) \
	phgQuadFaceJumpN(u, proj, name, order, NULL)

    /*-------------------- 3D functions --------------------*/
    PHG_EXTERN FLOAT phgQuadDofNormP(ELEMENT *e, DOF *u, int order, int p);

    PHG_EXTERN FLOAT phgQuadDofDotDof(ELEMENT *e, DOF *u, DOF *v, int order);
/*
FLOAT phgQuadGradBasDotGradBas(ELEMENT *e, DOF *u, int n, DOF *v, int m,
				int order);
				*/
#define phgQuadGradBasDotGradBas(e, u, n, v, m, order) \
	phgQuadGradBasAGradBas(e, u, n, NULL, v, m, order)
    PHG_EXTERN FLOAT phgQuadGradBasAGradBas(ELEMENT *e, DOF *u, int n, DOF *A, DOF *v,
				 int m, int order);
    PHG_EXTERN FLOAT *phgQuadDofTimesBas(ELEMENT *e, DOF *u, DOF *v, int n, int order,
			      FLOAT *res);
/*
 * FLOAT phgQuadBasDotBas(ELEMENT *e, DOF *u, int n, DOF *v, int m, int order); */
#define  phgQuadBasDotBas(e, u, n, v, m, order) \
	phgQuadBasABas(e, u, n, NULL, v, m, order)
    PHG_EXTERN FLOAT phgQuadBasABas(ELEMENT *e, DOF *u, int n, DOF *A, DOF *v, int m,
			 int order);
/*FLOAT phgQuadCurlBasDotCurlBas(ELEMENT *e, DOF *u, int n, DOF *v, int m,
				 int order); */
#define phgQuadCurlBasDotCurlBas(e, u, n, v, m, order)	\
	phgQuadCurlBasACurlBas(e, u, n, NULL, v, m, order)
    PHG_EXTERN FLOAT phgQuadCurlBasACurlBas(ELEMENT *e, DOF *u, int n, DOF *A, DOF *v,
				 int m, int order);
    PHG_EXTERN FLOAT phgQuadBasACurlBas(ELEMENT *e, DOF *u, int n, DOF *A, DOF *v, int m,
		       int order);
    PHG_EXTERN FLOAT phgQuadDofDotBas(ELEMENT *e, DOF *u, DOF *v, int n, int order);
    PHG_EXTERN FLOAT phgQuadDofABas(ELEMENT *e, DOF *u, DOF *A, DOF *v, int m, int order);
    PHG_EXTERN FLOAT phgQuadFuncDotBas(ELEMENT *e, DOF_USER_FUNC userfunc, DOF *u, int n,
			    int order);
#define phgQuadDofDotGradBas(e, u, v, m, order) \
	phgQuadDofAGradBas(e, u, NULL, v, m, order)
    PHG_EXTERN FLOAT phgQuadDofAGradBas(ELEMENT *e, DOF *u, DOF *A, DOF *v, int m,
			     int order);
#define phgQuadDofDotCurlBas(e, u, v, m, order) \
	phgQuadDofACurlBas(e, u, NULL, v, m, order)
    PHG_EXTERN FLOAT phgQuadDofACurlBas(ELEMENT *e, DOF *u, DOF *A, DOF *v, int m,
			     int order);
    PHG_EXTERN FLOAT *phgQuadDofDotCurlBas_(ELEMENT *e, DOF *u, DOF *v, int m,
			     int order, FLOAT *res);
    PHG_EXTERN FLOAT phgQuadGradBasDotBas(ELEMENT *e, DOF *s, int m, DOF *v, int n,
			       int order);
#define phgQuadDivBasDotDivBas(e, u, n, v, m, order) \
	phgQuadDivBasADivBas(e, u, n, NULL, v, m, order)
    PHG_EXTERN FLOAT phgQuadDivBasADivBas(ELEMENT *e, DOF *u, int n, DOF *A, DOF *v,
				 int m, int order);

#ifdef __cplusplus
}
#endif
#define PHG_QUAD_H
#endif
