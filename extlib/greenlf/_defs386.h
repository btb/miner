/*
 * _DEFS386.H       5.20A  June 8, 1995
 *
 * The Greenleaf Comm Library
 *
 * Copyright (C) 1985-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 *  This header file contains prototypes and miscellaneous definitions
 *  for use with all 32 bit DOS Extenders.  The functions and macros
 *  in this file are intended to provide a transparent and uniform
 *  set of functions that can be used with any 386 DOS Extender.
 *
 * Things we need to define in order to support a 386 DOS Extender.
 * These can be macros, typedefs, functions, or whatever.  It
 * all depends on what DOS Extender and compiler you are using.
 *
 * Functions defined in all caps might be defined as Macros.
 *
 *  Defined by the compiler    Defined by the DOS Extender
 *
 *  GF_FARPTR32               _GetDosSelector
 *  GF_SEL32                  _AllocateDosMemory
 *  GF_OFF32                  _LockMemory
 *  GF_POKEC32                _SetVector
 *  GF_POKEVID32              _GetRealAddress
 *  GF_PEEKC32                _GetOldProtHandler
 *  GF_FARPTR16               _GetOldRealHandler
 *  GF_SEL16                  _SetHandlers
 *  GF_OFF16                  _LockRegion
 *  _GetCs()
 *  _GetDs()
 *  _FarMemSet()
 *  _CopyFromFarMem()
 *  _CopyToFarMem()
 *
 *  Always defined: GF_X32
 *
 * CONTENTS
 *
 * MODIFICATIONS
 *
 *  December 1, 1994   5.10A :  Initial release.
 */

#if !defined( _DOS32BIT_H )
#define _DOS32BIT_H

#include "compiler.h"
#include <dos.h>


/*
 * Identify the DOS Extender.
 */

#if defined( DOSX386 )
#  if defined( GF_WATCOM_C )
#    undef _M_IX86
#  endif
#  define GF_X32
#elif defined( DOS4G )
#  define GF_DPMI32
#  define GF_X32
#elif defined( GF_BORLAND_CPP ) && defined( __DPMI32__ )
#  define GF_DPMI32
#  define GF_X32
#elif defined( DOS4G )
#  define GF_DPMI32
#  define GF_X32
#endif

#if defined( GF_X32 )


/*
 * Fortunately, the definitions for real pointers are the same for
 * every compiler.
 */

/*
 * Under 32 bit DOS extenders, we will have to manipulate 16:16
 * real pointers from time to time.  This structure definition and
 * associated macros make that a little easier to do.
 */

#pragma pack( 1 )
typedef struct _tag_realptr {
    unsigned short int offset;
    unsigned short int segment;
} GF_FARPTR16;
#pragma pack()

#define GF_SEG16( x ) (x).segment  /* Tag: Misc private */
#define GF_OFF16( x ) (x).offset   /* Tag: Misc private */

/*
 * Watcom definitions
 */
#if defined( GF_WATCOM_C_386 )

#include <i86.h>

/*
 * Watcom is the one compiler we use right now that actually supports
 * far pointers.  This means that we can use efficient code in some
 * places by simply dereferencing a far pointer instead of performing
 * a far copy.  However, I still create a structure so that I have
 * easy access to the selector and offset parts of the pointer.
 */
#pragma pack( 1 )
typedef union { char _far * p;
                    struct _tag_farptr {
                        unsigned int offset;
                        unsigned short selector;
                    } s;
               } GF_FARPTR32;
#pragma pack()

#define GF_SEL32( x ) (x).s.selector         /* Tag: Extender private */
#define GF_OFF32( x ) (x).s.offset           /* Tag: Extender private */
#define GF_POKEC32( x, c ) (*((x).p) = (c))  /* Tag: Extender private */
#define GF_POKEVID32( x, c, att ) *(short int _far *) ((x).p) = ( (c) + ( (att) << 8 ) )  /* Tag: Extender private */
#define GF_PEEKC32( c, x ) (c = *((x).p))     /* Tag: Extender private */

#endif

/*
 * Symantec definitions
 */
#if defined( GF_SYMANTEC_CPP )

/*
 * Symantec actually supports far pointers.  This means that we can use
 * efficient code in some places by simply dereferencing a far pointer
 * instead of performing a far copy.  However, I still create a structure
 * so that I have easy access to the selector and offset parts of the
 *  pointer.
 */

#pragma pack( 1 )
typedef union { char _far * p;
                    struct _tag_farptr {
                        unsigned int offset;
                        unsigned short selector;
                    } s;
               } GF_FARPTR32;
#pragma pack()

#define GF_SEL32( x ) (x).s.selector         /* Tag: Extender private */
#define GF_OFF32( x ) (x).s.offset           /* Tag: Extender private */
#define GF_POKEC32( x, c ) (*((x).p) = (c))  /* Tag: Extender private */
#define GF_POKEVID32( x, c, att ) *(short int _far *) ((x).p) = ( (c) + ( (att) << 8 ) )  /* Tag: Extender private */
#define GF_PEEKC32( c, x ) (c = *((x).p))    /* Tag: Extender private */

#endif

/*
 * Visual C++ definitions
 */

#if defined( GF_VISUAL_CPP )

#pragma pack( 1 )
typedef struct _tag_farptr {
    unsigned int offset;
    unsigned short selector;
} GF_FARPTR32;
#pragma pack()

#define GF_SEL32( x ) (x).selector                  /* Tag: Extender private */
#define GF_OFF32( x ) (x).offset                    /* Tag: Extender private */
#define GF_POKEC32( x, c ) _gf_pokec32( (x), (c) )  /* Tag: Extender private */
#define GF_POKEVID32( x, c, att ) _gf_pokevid32( (x), (c), (att) )  /* Tag: Extender private */
#define GF_PEEKC32( c, x ) c = _gf_peekc32( (x) )   /* Tag: Extender private */

void GF_CONV _gf_pokec32( GF_FARPTR32 x, unsigned char c );
void GF_CONV _gf_pokevid32( GF_FARPTR32 x, unsigned char c, unsigned char att );
unsigned char GF_CONV _gf_peekc32( GF_FARPTR32 x );

#endif /* #if defined( GF_VISUAL_CPP ) */

/*
 * Borland definitions.
 */

#if defined( GF_BORLAND_CPP )

#pragma pack( 1 )
typedef struct _tag_farptr {
    unsigned int offset;
    unsigned short selector;
} GF_FARPTR32;
#pragma pack()

#define GF_SEL32( x ) (x).selector                  /* Tag: Extender private */
#define GF_OFF32( x ) (x).offset                    /* Tag: Extender private */
#define GF_POKEC32( x, c ) _gf_pokec32( (x), (c) )  /* Tag: Extender private */
#define GF_POKEVID32( x, c, att ) _gf_pokevid32( (x), (c), (att) )  /* Tag: Extender private */
#define GF_PEEKC32( c, x ) c = _gf_peekc32( (x) )   /* Tag: Extender private */

void GF_CONV _gf_pokec32( GF_FARPTR32 x, unsigned char c );
void GF_CONV _gf_pokevid32( GF_FARPTR32 x, unsigned char c, unsigned char att );
unsigned char GF_CONV _gf_peekc32( GF_FARPTR32 x );

#endif

/*
 * The following functions are prototyped for every DOS Extender and
 * compiler.  The prototypes are identical regardeless of the tool,
 * so you won't see any ifdefs here.
 */

#ifdef __cplusplus
extern "C" {
#endif

unsigned short int GF_CONV _GetDosSelector( void );
GF_FARPTR32 GF_CONV _AllocateDosMemory( int size );
int GF_CONV _FreeDosMemory( GF_FARPTR32 p );
void GF_CONV _FarMemSet( GF_FARPTR32 add, unsigned char val, int length );
void GF_CONV _CopyToFarMem( GF_FARPTR32 destination, void *source, int length );
void GF_CONV _CopyFromFarMem( void *destination, GF_FARPTR32 source, int length );
GF_FARPTR16 GF_CONV _GetRealAddress( GF_FARPTR32 protected_address );
GF_FARPTR32 GF_CONV _GetOldProtHandler( int interrupt_number );
GF_FARPTR16 GF_CONV _GetOldRealHandler( int interrupt_number );
int GF_CONV _SetHandlers( int interrupt_number, GF_FARPTR32 port_handler, GF_FARPTR16 real_handler );
int GF_CONV _LockRegion( GF_FARPTR32 base, int size );
unsigned short int GF_CONV _GetCs( void );
unsigned short int GF_CONV _GetDs( void );

#ifdef __cplusplus
}
#endif

/*
 * If you don't have REGS or int386 defined, we can make do with the
 * Phar Lap TNT versions.  However, there are some naming problems,
 * so we have to create a new structure.  This means that this code
 * can be broken by a new release of TNT.
 */
#if defined( DOSX386 )


#if defined( GF_BORLAND_CPP ) || defined( GF_VISUAL_CPP ) || defined( GF_SYMANTEC_CPP )

#include <pldos32.h>

#pragma pack( 1 )
#undef REGS
union REGS {
    struct _DWORDREGS x;
    struct _WORDREGS w;
    struct _BYTEREGS h;
};
#pragma pack()

#define SREGS _SREGS
#define int386( i, r1, r2 )    /* Tag: Extender private */ \
                               _int86( (i),                \
                               (union _REGS *)( r1 ),      \
                               (union _REGS *)( r2 ) )

#define int386x( i, r1, r2, s )   /* Tag: Extender private */ \
                                  _int86x( (i),               \
                                  (union _REGS *)( r1 ),      \
                                  (union _REGS *)( r2 ),      \
                                         (s) )
#endif /* #if defined( GF_BORLAND_CPP ) || defined( GF_VISUAL_CPP ) */
#endif /* #if defined( DOSX386 ) */

#endif /* #if defined( GF_X32 )       */

#endif /* #if !defined( _DOS32BIT_H ) */
