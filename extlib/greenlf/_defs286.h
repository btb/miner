/*
 * _DEFS286.H       5.20A  June 8, 1995
 *
 * The Greenleaf Comm Library
 *
 * Copyright (C) 1985-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 *  This header file contains prototypes and miscellaneous definitions
 *  for use with all 16 bit DOS Extenders.  The functions and macros
 *  in this file are intended to provide a transparent and uniform
 *  set of functions that can be used with any 286 DOS Extender.
 *
 * Things we need to define in order to support a 285DOS Extender.
 * These can be macros, typedefs, functions, or whatever.  It
 * all depends on what DOS Extender and compiler you are using.
 *
 * Functions defined in all caps might be defined as Macros.
 *
 *  Defined by the compiler    Defined by the DOS Extender
 *
 *  GF_REALPTR16              GF_DPMI16
 *  GF_SEG16                  _GetDosSelector
 *  GF_OFF16                  _GetRealAddress
 *  _GetDs                    _GetOldProtHandler
 *                            _GetOldRealHandler
 *                            _SetHandlers
 *                            _AllocateDosMemory
 *                            _FreeDosMemory
 *                            _LockRegion
 *  Always defined: GF_X16
 *
 * CONTENTS
 *
 * MODIFICATIONS
 *
 *  December 1, 1994   5.10A :  Initial release.
 */

#if !defined( _DEFS286_H )
#define _DEFS286_H

#include "compiler.h"
#include <dos.h>

/*
 * Identify the DOS Extender.
 */

#if defined( DOSX286 )
#  define GF_X16
#elif defined( DOS16M )
#  define GF_DPMI16
#  define GF_X16
#elif defined( GF_BORLAND_CPP ) && defined( __DPMI16__ )
#  define GF_DPMI16
#  define GF_X16
#endif

#ifdef GF_X16

/*
 * Under 16 bit DOS extenders, we will have to manipulate 16:16
 * real pointers from time to time.  This structure definition and
 * associated macros make that a little easier to do.  Note that you
 * don't *ever* want to load a real mode pointer into a pointer variable,
 * this will cause a fast GPF.  These structures are nice and safe.
 */

typedef struct _tag_realptr {
    unsigned int offset;
    unsigned int segment;
} GF_REALPTR16;
#define GF_SEG16( x ) (x).segment  /* Tag: Extender private */
#define GF_OFF16( x ) (x).offset   /* Tag: Extender private */

/*
 * The following functions are prototyped for every DOS Extender and
 * compiler.  The prototypes are identical regardeless of the tool,
 * so you won't see any ifdefs here.
 */

#ifdef __cplusplus
extern "C" {
#endif

unsigned int GF_CONV _GetDosSelector( unsigned int segment );
GF_REALPTR16 GF_CONV _GetRealAddress( void far *protected_address );
void far *GF_CONV _GetOldProtHandler( int interrupt_number );
GF_REALPTR16 GF_CONV _GetOldRealHandler( int interrupt_number );
int GF_CONV _SetHandlers( int interrupt_number, void far *prot_handler, GF_REALPTR16 real_handler );
void far *GF_CONV _AllocateDosMemory( int size );
int GF_CONV _FreeDosMemory( void far *p );
int GF_CONV _LockRegion( void far *base, int size );
unsigned int GF_CONV _GetDs( void );

#ifdef __cplusplus
}
#endif
#endif /* #ifdef GF_X16 */
#endif /* #if !defined( _DEFS286_H ) */
