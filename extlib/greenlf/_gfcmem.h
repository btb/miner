#ifndef _GFC_MEM_DOT_H
#define _GFC_MEM_DOT_H

/*
 * GFC_MEM.H               5.20A  June 8, 1995
 *
 *  The Greenleaf Comm Library
 *
 *  Copyright (C) 1991-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 * These declarations are used for internal memory allocation functions
 * used in CommLib.  The routines declared here and defined in
 * gfc_mem.c can be replaced by the user with functions that return
 * pointers to static memory areas.  This is useful when you don't
 * want to use the heap for some reason.  Note that "normal" applications
 * will never have to use these functions, and consequently will never
 * have to include this header file.
 *
 * MODIFICATIONS
 *
 * December 12, 1992  4.00A : Initial release
 */

#ifndef GF_HEAP_DEBUGGER

void * GF_CONV AllocateGreenleafPortStructure( int port, int size );
void GF_CONV FreeGreenleafPortStructure( int port, void *p );
void * GF_CONV AllocateGenericStructure( int size );
void GF_CONV FreeGenericStructure( void *p );
void * GF_CONV AllocateDriverStructure( int size );
void GF_CONV FreeDriverStructure( void *p );
void * GF_CONV AllocateRXBuffer( int port, unsigned int size );
void * GF_CONV AllocateTXBuffer( int port, unsigned int size );
void GF_CONV FreeTXBuffer( int port, void *p );
void GF_CONV FreeRXBuffer( int port, void *p );
void * GF_CONV AllocateXferBuffer( unsigned int size );
void GF_CONV FreeXferBuffer( void *p );

#endif    /* #ifndef GF_HEAP_DEBUGGER */

#endif   /* #ifndef _GFC_MEM_DOT_H*/

