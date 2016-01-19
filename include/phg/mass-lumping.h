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

/* $Id: mass-lumping.h,v 1.1 2014/04/04 04:30:01 zlb Exp $ */

#ifndef PHG_MASS_LUMPING_H

PHG_EXTERN extern DOF_TYPE *DOF_MLn[];

PHG_EXTERN extern DOF_TYPE DOF_ML1_;
#define DOF_ML1 (&DOF_ML1_)

PHG_EXTERN extern DOF_TYPE DOF_ML2_;
#define DOF_ML2 (&DOF_ML2_)

PHG_EXTERN extern DOF_TYPE DOF_ML3_;
#define DOF_ML3 (&DOF_ML3_)

PHG_EXTERN extern DOF_TYPE DOF_ML4_;
#define DOF_ML4 (&DOF_ML4_)

PHG_EXTERN extern DOF_TYPE DOF_P1B_;
#define DOF_P1B (&DOF_P1B_)

#define TEST_TYPES	DEBUG	/* 1 ==> enable DOF_TYPES DOF_TSTn[] */
#if TEST_TYPES	/*-------------------------------------------------------*/

PHG_EXTERN extern DOF_TYPE *DOF_TSTn[];

PHG_EXTERN extern DOF_TYPE DOF_TST2_;
#define DOF_TST2 (&DOF_TST2_)

PHG_EXTERN extern DOF_TYPE DOF_TST3_;
#define DOF_TST3 (&DOF_TST3_)

PHG_EXTERN extern DOF_TYPE DOF_TST4_;
#define DOF_TST4 (&DOF_TST4_)

PHG_EXTERN extern DOF_TYPE DOF_TST5_;
#define DOF_TST5 (&DOF_TST5_)

PHG_EXTERN extern DOF_TYPE DOF_TST6_;
#define DOF_TST6 (&DOF_TST6_)

PHG_EXTERN extern DOF_TYPE DOF_TST7_;
#define DOF_TST7 (&DOF_TST7_)

PHG_EXTERN extern DOF_TYPE DOF_TST8_;
#define DOF_TST8 (&DOF_TST8_)

PHG_EXTERN extern DOF_TYPE DOF_TST9_;
#define DOF_TST9 (&DOF_TST9_)

PHG_EXTERN extern DOF_TYPE DOF_TST10_;
#define DOF_TST10 (&DOF_TST10_)

PHG_EXTERN extern DOF_TYPE DOF_TEST_;
#define DOF_TEST (&DOF_TEST_)

#endif	/*------------------------------------------------------- TEST_TYPES */

typedef struct MASS_LUMPING_ {
    int order0;			/* vertex order */
    int order1;			/* edge order */
    int order2;			/* face order */
    int order3;			/* internal order */
    int norbit;			/* # orbits */
    int *orbits;		/* array of orbits */
    FLOAT *weights0;		/* weights0[np_vert+np_edge+np_face+np_elem] */
    /* buffers initialized in init() */
    FLOAT *weights;		/* weights[nbas] */
    /* buffers initialized in init_buffers() */
    BYTE *face_pow;		/* list of powers for monomials on a face */
    BYTE *elem_pow;		/* list of powers for interior monomials */
    FLOAT *coeff;		/* coefficients of the FE bases */
    /* caches */
    FLOAT *bas_lambda;		/* lambda for cached monomials */
    FLOAT *bas_values;		/* cached values of monomials */
    FLOAT *grad_lambda;		/* lambda for cached grad(monomials) */
    FLOAT *grad_values;		/* cached values of grad(monomials) */
} MASS_LUMPING;

#define PHG_MASS_LUMPING_H
#endif
