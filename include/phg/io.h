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

/* $Id: io.h,v 1.1 2014/04/04 04:30:01 zlb Exp $ */

#ifndef PHG_IO_H

#ifdef __cplusplus
extern "C" {
#endif

PHG_EXTERN BOOLEAN phgIOOpen(GRID *g, const char *fn);
PHG_EXTERN int phgIOPrintf(GRID *g, char *fmt, ...);
PHG_EXTERN void phgIOWriteRoot(GRID *g, void *buf, size_t size, int count);
PHG_EXTERN void phgIOWrite(GRID *g, void *buffer, size_t size, size_t count,
		size_t nglobal, BTYPE flags[], INT map[], BOOLEAN map_flag);
PHG_EXTERN void phgIOClose(void);
PHG_EXTERN const char *phgIOAddExtension(const char *fn, const char *ext);

#ifdef __cplusplus
}
#endif

#define PHG_IO_H
#endif
