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

/* $Id: dof-utils.h,v 1.1 2014/04/04 04:30:00 zlb Exp $ */

#ifndef PHG_DOF_UTILS_H

/* function prototypes */

#ifdef __cplusplus
extern "C" {
#endif

PHG_EXTERN DOF_TYPE *phgDofCreateSimpleType(const char *name,
                        int np_vert, int np_edge, int np_face, int np_elem);

PHG_EXTERN FLOAT *phgDofEval_(DOF *dof, ELEMENT *e, const FLOAT lambda[],
			const FLOAT *basvalues, int bas_stride,
			FLOAT *values, FLOAT **data);
#define phgDofEval(dof, e, lambda, values) \
	phgDofEval_(dof, e, lambda, NULL, 0, values, NULL)

PHG_EXTERN FLOAT *phgDofEvalGradient(DOF *dof, ELEMENT *e, const FLOAT lambda[],
			const FLOAT *gradbas, FLOAT *values);
#define phgDofGradient(src, dest, newtype, name) \
	phgDofGradient_(src, dest, newtype, name, __FILE__, __LINE__)
PHG_EXTERN DOF *phgDofGradient_(DOF *src, DOF **newdof, DOF_TYPE *newtype,
			const char *name, const char *srcfile, int srcline);

PHG_EXTERN FLOAT *phgDofEvalDivergence(DOF *dof, ELEMENT *e, const FLOAT lambda[],
			const FLOAT *gradbas, FLOAT *values);
#define phgDofDivergence(src, dest, newtype, name) \
	phgDofDivergence_(src, dest, newtype, name, __FILE__, __LINE__)
PHG_EXTERN DOF *phgDofDivergence_(DOF *src, DOF **newdof, DOF_TYPE *newtype,
			const char *name, const char *srcfile, int srcline);
PHG_EXTERN FLOAT *phgDofEvalCurl(DOF *dof, ELEMENT *e, const FLOAT lambda[],
			const FLOAT *gradbas, FLOAT *values);
#define phgDofCurl(src, dest, newtype, name) \
	phgDofCurl_(src, dest, newtype, name, __FILE__, __LINE__)
PHG_EXTERN DOF *phgDofCurl_(DOF *src, DOF **newdof, DOF_TYPE *newtype,
			const char *name, const char *srcfile, int srcline);

/* Utility functions */

/* Note: The use of 'dof_index' instead of 'bas_no' in phgDofDirichletBC__ is
 * for supporting multiple DB masks through the array DOF->DB_masks[] */
#define phgDofDirichletBC(u, e, bas_no, func, mat, rhs, proj)	\
    phgDofDirichletBC_(u, e, bas_no * u->dim, func, mat, rhs, proj)
#define phgDofDirichletBC_(u, e, dof_index, func, mat, rhs, proj)	\
    phgDofDirichletBC__(u, e, dof_index, func, NULL, NULL, mat, rhs, proj)
PHG_EXTERN BOOLEAN phgDofDirichletBC__(DOF *u, ELEMENT *e, int dof_index,
	DOF_USER_FUNC func, DOF_USER_FUNC_LAMBDA func_lambda, DOF *func_dof,
	FLOAT mat[], FLOAT rhs[], DOF_PROJ proj);

/* BLAS-like functions */
#define phgDofCopy(src, dest, newtype, name) \
	phgDofCopy_(src, dest, newtype, name, __FILE__, __LINE__)
PHG_EXTERN DOF *phgDofCopy_(DOF *src, DOF **dest, DOF_TYPE *newtype,
		 const char *name, const char *srcfile, int srcline);

PHG_EXTERN FLOAT phgDofDotL2Vec(DOF *x, DOF *y);
#define phgDofNormL2Vec(x)	Sqrt(phgDofDotL2Vec(x, x))
PHG_EXTERN FLOAT phgDofNormLpVec(DOF *x, FLOAT p);
PHG_EXTERN FLOAT phgDofNormL1Vec(DOF *x);
PHG_EXTERN FLOAT phgDofNormInftyVec(DOF *x);
PHG_EXTERN FLOAT phgDofMinValVec(DOF *x);
PHG_EXTERN FLOAT phgDofMaxValVec(DOF *x);

PHG_EXTERN FLOAT phgDofNormL1(DOF *u);
PHG_EXTERN FLOAT phgDofNormL2(DOF *u);
PHG_EXTERN FLOAT phgDofDotL2(DOF *u, DOF *v);
PHG_EXTERN FLOAT phgDofNormH1(DOF *u);

PHG_EXTERN void phgDofRandomize(DOF *u, long int seed);

#define phgDofMM(transa, transb, M, N, K, alpha, A, blka, B, beta, C) \
	phgDofMM_(transa, transb, M, N, K, alpha, A, blka, B, beta, C, \
		  __FILE__, __LINE__, TRUE)
PHG_EXTERN DOF *phgDofMM_(MAT_OP transa, MAT_OP transb, int M, int N, int K,
        FLOAT alpha, DOF *A, int blka, DOF *B, FLOAT beta, DOF **Cptr,
        const char *srcfile, int srcline, BOOLEAN check);

PHG_EXTERN DOF *phgDofAXPBY_(FLOAT a, DOF *x, FLOAT b, DOF **y,
	const char *srcfile, int srcline, BOOLEAN check);
#define phgDofAXPBY(a, x, b, y) \
	phgDofAXPBY_(a, x, b, y, __FILE__, __LINE__, TRUE)
#define phgDofAXPY(a, x, y)	phgDofAXPBY(a, x, (FLOAT)1.L, y)

PHG_EXTERN DOF *phgDofMatVec_(FLOAT alpha, DOF *A, DOF *x, FLOAT beta, DOF **y_ptr,
		const char *srcfile, int srcline, BOOLEAN check);
#define phgDofMatVec(alpha, A, x, beta, y) \
	phgDofMatVec_(alpha, A, x, beta, y, __FILE__, __LINE__, TRUE)

PHG_EXTERN DOF *phgDofAFXPBY_(FLOAT a, void (*f)(FLOAT *in, FLOAT *out), DOF *x, FLOAT b,
		   DOF **yptr, const char *srcfile, int srcline);
#define phgDofAFXPBY(a, f, x, b, yptr) \
	phgDofAFXPBY_(a, f, x, b, yptr, __FILE__, __LINE__)

PHG_EXTERN DOF *phgDofAFXPBY1_(FLOAT a, FLOAT (*f)(FLOAT xvalue), DOF *x,
		    FLOAT b, DOF **yptr, const char *srcfile, int srcline);
#define phgDofAFXPBY1(a, f, x, b, yptr) \
	phgDofAFXPBY1_(a, f, x, b, yptr, __FILE__, __LINE__)

PHG_EXTERN int phgDofEigenSolve_(MAT *A, MAT *B, int n, int which, FLOAT tau, int *nit,
		      FLOAT *evals, void *ssd, struct MAP_ *map, DOF **u, ...);
PHG_EXTERN int phgDofEigenSolve(MAT *A, MAT *B, int n, int which, FLOAT tau, int *nit,
		     FLOAT *evals, struct MAP_ *map, DOF **u, ...);

PHG_EXTERN DOF *phgDofGetSameOrderDG_(DOF *dof, int dim, const char *name,
			const char *file, int line);
#define phgDofGetSameOrderDG(dof, dim, name) \
	phgDofGetSameOrderDG_(dof, dim, name, __FILE__, __LINE__)

/*void phgDofMapDataInElement(DOF_TYPE *type, const ELEMENT *e, int dim,
			  FLOAT *values);*/
PHG_EXTERN MAT *phgDofGetTransferMatrix(DOF *u, DOF *v, MAP *map_u, MAP *map_v);

#ifdef __cplusplus
}
#endif

#define PHG_DOF_UTILS_H
#endif
