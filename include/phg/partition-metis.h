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

/* $Id: partition-metis.h,v 1.1 2014/04/04 04:30:01 zlb Exp $ */

#ifndef PHG_METIS_H

#ifdef __cplusplus
extern "C" {
#endif

#if 0 * USE_METIS
PHG_EXTERN BOOLEAN phgPartitionMetis(GRID *g, MPI_Comm newcomm, DOF *weights, FLOAT power);
#endif	/* USE_METIS */

#if USE_PARMETIS
PHG_EXTERN BOOLEAN phgPartitionParMetis(GRID *g, MPI_Comm newcomm, DOF *weights,
				FLOAT power);
#endif	/* USE_PARMETIS */

#ifdef __cplusplus
}
#endif

#define PHG_METIS_H
#endif
