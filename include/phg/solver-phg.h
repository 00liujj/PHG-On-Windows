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

/* $Id: solver-phg.h,v 1.1 2014/04/04 04:30:01 zlb Exp $ */

#ifndef PHG_SOLVER_PHG_H
#define PHG_SOLVER_PHG_H

#define phgSolverJacobi(A,b,x_ptr,maxit,rtol,res) \
	phgSolverJacobi__(A,b,x_ptr,maxit,rtol,1.0e-30, 1.0e-30,res,0) 
#define phgSolverPCG(A,b,x_ptr,pc,maxit,rtol,res) \
	phgSolverPCG__(A,b,x_ptr,pc,maxit,rtol,1.0e-30, 1.0e-30,res,FALSE,0) 
#define phgSolverGMRES(A,b,x_ptr,pc,restart,maxit,rtol,res) \
	phgSolverGMRES__(A,b,x_ptr,pc,restart,maxit,rtol,1.0e-30,1.0e-30,res,0)

#ifdef __cplusplus
extern "C" {
#endif
		
    PHG_EXTERN int phgSolverJacobi__(MAT *A, VEC *b, VEC **x, int max_its, 
		    FLOAT rtol,FLOAT btol, FLOAT atol, FLOAT *res, INT verb);
    PHG_EXTERN int phgSolverPCG__(MAT *A, VEC *b, VEC **x_ptr, SOLVER_PC *pc, 
		    int max_its, FLOAT rtol, FLOAT btol, FLOAT atol,
		FLOAT *res, BOOLEAN *warned, INT verb);
    PHG_EXTERN int phgSolverGMRES__(MAT *A, VEC *b, VEC **x_ptr, SOLVER_PC *pc,
		int restart, int max_its, FLOAT rtol, 
		FLOAT btol, FLOAT atol, FLOAT *res, INT verb);
    PHG_EXTERN void phgSolverGMRESSetRestart(SOLVER *solver, int restart);
#ifdef __cplusplus
}
#endif

#endif	/* !defined(SOLVER_PHG_H) */
