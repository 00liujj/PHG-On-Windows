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

/* $Id: hierarchical-basis.h,v 1.1 2014/04/04 04:30:01 zlb Exp $ */

#ifndef PHG_HIERARCHICAL_BASIS_H

/* Note: DOF_HBn[] are up to ORDER_MAX while others are up to ORDER_MAX-1
 * to allow construction of the G space in the AMS solver */
#define ORDER_MAX	16

#ifdef __cplusplus
extern "C" {
#endif

/* H1 conforming DOF types */

PHG_EXTERN extern DOF_TYPE *DOF_HBn[];

PHG_EXTERN extern DOF_TYPE DOF_HB1_;
#define DOF_HB1 (&DOF_HB1_)

PHG_EXTERN extern DOF_TYPE DOF_HB2_;
#define DOF_HB2 (&DOF_HB2_)

PHG_EXTERN extern DOF_TYPE DOF_HB3_;
#define DOF_HB3 (&DOF_HB3_)

PHG_EXTERN extern DOF_TYPE DOF_HB4_;
#define DOF_HB4 (&DOF_HB4_)

PHG_EXTERN extern DOF_TYPE DOF_HB5_;
#define DOF_HB5 (&DOF_HB5_)

PHG_EXTERN extern DOF_TYPE DOF_HB6_;
#define DOF_HB6 (&DOF_HB6_)

PHG_EXTERN extern DOF_TYPE DOF_HB7_;
#define DOF_HB7 (&DOF_HB7_)

PHG_EXTERN extern DOF_TYPE DOF_HB8_;
#define DOF_HB8 (&DOF_HB8_)

PHG_EXTERN extern DOF_TYPE DOF_HB9_;
#define DOF_HB9 (&DOF_HB9_)

PHG_EXTERN extern DOF_TYPE DOF_HB10_;
#define DOF_HB10 (&DOF_HB10_)

PHG_EXTERN extern DOF_TYPE DOF_HB11_;
#define DOF_HB11 (&DOF_HB11_)

PHG_EXTERN extern DOF_TYPE DOF_HB12_;
#define DOF_HB12 (&DOF_HB12_)

PHG_EXTERN extern DOF_TYPE DOF_HB13_;
#define DOF_HB13 (&DOF_HB13_)

PHG_EXTERN extern DOF_TYPE DOF_HB14_;
#define DOF_HB14 (&DOF_HB14_)

PHG_EXTERN extern DOF_TYPE DOF_HB15_;
#define DOF_HB15 (&DOF_HB15_)

PHG_EXTERN extern DOF_TYPE DOF_HB16_;
#define DOF_HB16 (&DOF_HB16_)

PHG_EXTERN extern HP_INFO hp_info_HB;
#define HP_HB (&hp_info_HB)

/* Hcurl conforming DOF types */

PHG_EXTERN extern DOF_TYPE *DOF_HCn[];

PHG_EXTERN extern DOF_TYPE DOF_HC0_;
#define DOF_HC0 (&DOF_HC0_)

PHG_EXTERN extern DOF_TYPE DOF_HC1_;
#define DOF_HC1 (&DOF_HC1_)

PHG_EXTERN extern DOF_TYPE DOF_HC2_;
#define DOF_HC2 (&DOF_HC2_)

PHG_EXTERN extern DOF_TYPE DOF_HC3_;
#define DOF_HC3 (&DOF_HC3_)

PHG_EXTERN extern DOF_TYPE DOF_HC4_;
#define DOF_HC4 (&DOF_HC4_)

PHG_EXTERN extern DOF_TYPE DOF_HC5_;
#define DOF_HC5 (&DOF_HC5_)

PHG_EXTERN extern DOF_TYPE DOF_HC6_;
#define DOF_HC6 (&DOF_HC6_)

PHG_EXTERN extern DOF_TYPE DOF_HC7_;
#define DOF_HC7 (&DOF_HC7_)

PHG_EXTERN extern DOF_TYPE DOF_HC8_;
#define DOF_HC8 (&DOF_HC8_)

PHG_EXTERN extern DOF_TYPE DOF_HC9_;
#define DOF_HC9 (&DOF_HC9_)

PHG_EXTERN extern DOF_TYPE DOF_HC10_;
#define DOF_HC10 (&DOF_HC10_)

PHG_EXTERN extern DOF_TYPE DOF_HC11_;
#define DOF_HC11 (&DOF_HC11_)

PHG_EXTERN extern DOF_TYPE DOF_HC12_;
#define DOF_HC12 (&DOF_HC12_)

PHG_EXTERN extern DOF_TYPE DOF_HC13_;
#define DOF_HC13 (&DOF_HC13_)

PHG_EXTERN extern DOF_TYPE DOF_HC14_;
#define DOF_HC14 (&DOF_HC14_)

PHG_EXTERN extern DOF_TYPE DOF_HC15_;
#define DOF_HC15 (&DOF_HC15_)

PHG_EXTERN extern HP_INFO hp_info_HC;
#define HP_HC (&hp_info_HC)

/* Hdiv conforming DOF types */

PHG_EXTERN extern DOF_TYPE *DOF_HDn[];

PHG_EXTERN extern DOF_TYPE DOF_HD1_;
#define DOF_HD1 (&DOF_HD1_)

PHG_EXTERN extern DOF_TYPE DOF_HD2_;
#define DOF_HD2 (&DOF_HD2_)

PHG_EXTERN extern DOF_TYPE DOF_HD3_;
#define DOF_HD3 (&DOF_HD3_)

PHG_EXTERN extern DOF_TYPE DOF_HD4_;
#define DOF_HD4 (&DOF_HD4_)

PHG_EXTERN extern DOF_TYPE DOF_HD5_;
#define DOF_HD5 (&DOF_HD5_)

PHG_EXTERN extern DOF_TYPE DOF_HD6_;
#define DOF_HD6 (&DOF_HD6_)

PHG_EXTERN extern DOF_TYPE DOF_HD7_;
#define DOF_HD7 (&DOF_HD7_)

PHG_EXTERN extern DOF_TYPE DOF_HD8_;
#define DOF_HD8 (&DOF_HD8_)

PHG_EXTERN extern DOF_TYPE DOF_HD9_;
#define DOF_HD9 (&DOF_HD9_)

PHG_EXTERN extern DOF_TYPE DOF_HD10_;
#define DOF_HD10 (&DOF_HD10_)

PHG_EXTERN extern DOF_TYPE DOF_HD11_;
#define DOF_HD11 (&DOF_HD11_)

PHG_EXTERN extern DOF_TYPE DOF_HD12_;
#define DOF_HD12 (&DOF_HD12_)

PHG_EXTERN extern DOF_TYPE DOF_HD13_;
#define DOF_HD13 (&DOF_HD13_)

PHG_EXTERN extern DOF_TYPE DOF_HD14_;
#define DOF_HD14 (&DOF_HD14_)

PHG_EXTERN extern DOF_TYPE DOF_HD15_;
#define DOF_HD15 (&DOF_HD15_)

PHG_EXTERN extern HP_INFO hp_info_HD;
#define HP_HD (&hp_info_HD)

#ifdef __cplusplus
}
#endif

#define PHG_HIERARCHICAL_BASIS_H
#endif
