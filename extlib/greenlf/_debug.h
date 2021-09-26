#ifndef __DEBUG_H
#define __DEBUG_H

/*
 * _DEBUG.H       5.20A  June 8, 1995
 *
 * The Greenleaf Comm Library
 *
 * Copyright (C) 1985-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 *  This header file contains prototypes and miscellaneous definitions
 *  for two different subsytems that are used to help diagnose
 *  problems under CommLib.
 *
 *  The first set of functions are those used to replace all of the
 *  heap memory functions.  When the _DEBUG macro is turned on, normal
 *  function calls to malloc(), calloc(), and free() are replaced with
 *  special versions.  The special versions track memory leaks and
 *  heap over- and under-writes, as well as the general problem of
 *  heap destruction.  Several other memory allocation functions get
 *  replaced here as well.
 *
 *  The second subsytem controlled here is the GF_ASSERT() macro.  This
 *  macro is nearly identical to the assert() macro used in the C RTL,
 *  but it includes an extra argument that allows you to print out the
 *  reason for an assertion failure.
 *
 * MODIFICATIONS
 *
 *  June 6, 1995  5.20A : It really wasn't very nice to modify malloc()
 *                        et. al. when _DEBUG is turned on.  This turns
 *                        out to cause people some trouble.  So now, I
 *                        just debug my *own* function calls when _DEBUG
 *                        is turned on. If a user wants to debug malloc()
 *                        and friends in their own libraries, they need
 *                        to define GF_ENABLE_HEAP_DEBUGGING.  The old
 *                        macro, GF_DISABLE_HEAP_DEBUGGING, is gone.
 *                        Regardless of the new macro's setting, I am
 *                        going to debug Greenleaf internal allocation if
 *                        _DEBUG is turned on.
 */


#ifdef __cplusplus
extern "C" {
#endif

/*
 * Heap checking will only get turned on if the _DEBUG macro is defined.
 * This is normally done using an option in BUILD.INI.  The function
 * shown below lets you test at runtime for the presence of the heap
 * debugging code.
 */

int GF_CONV _DebuggingHeap( void );

#ifdef __cplusplus
}
#endif

#if defined( _DEBUG )
/*
 * The heapcheck code uses specific function calls in the Borland and
 * Microsoft run time libraries.  It may work properly with other compilers,
 * but that hasn't been checked yet.
 */
  #if defined( GF_TURBO_CPP ) || defined( GF_BORLAND_CPP ) || defined( GF_MICROSOFT_C )
/*
 * We are not going to enable heap debugging if any of the DOS extenders
 * are turned on, or if Powercomm is enabled.
 */
    #if !defined( GF_X32 )
      #if !defined( GF_X16 )
        #if !defined( VGFD ) && !defined( VGFD_DLL )
/*
 * All we have to do at this point is decide whether we are running Windows
 * or not.
 */
          #if !defined( GF_WINDOWS )
            #define GF_HEAP_DEBUGGER
          #else  /* Small data, everything goes, large model, MSC only */
            #if !defined( GF_DLL ) && !defined( _WINDOWS_DLL )
              #if ( _LDATA == 0 )
                #define GF_HEAP_DEBUGGER
              #elif defined( GF_MICROSOFT_C )
                #define GF_HEAP_DEBUGGER
              #endif
            #endif /* !defined( GF_DLL ) && !defined( _WINDOWS_DLL ) */
          #endif
        #endif /* !defined( VGFD ) */
      #endif /* !defined( GF_X32 ) */
    #endif /* !defined( GF_X16 ) */
  #endif
#endif

#ifdef GF_HEAP_DEBUGGER

/*
 * This only applies to CommLib, but I guess it won't hurt anything to have
 * these definitions elsewhere.
 */
/*
 * Need to pick up the definition for size_t.
 */
#include <stdlib.h>

#define AllocateGreenleafPortStructure( port, size ) _DebugCalloc( 1, size, __FILE__, __LINE__ )  /* Tag: Debug Public */
#define FreeGreenleafPortStructure( port, p ) _DebugFree( p, __FILE__, __LINE__ )                 /* Tag: Debug Public */
#define AllocateDriverStructure( size ) _DebugCalloc( 1, size, __FILE__, __LINE__ )               /* Tag: Debug Public */
#define FreeDriverStructure( p ) _DebugFree( p, __FILE__, __LINE__ )                              /* Tag: Debug Public */
#define AllocateGenericStructure( size ) _DebugCalloc( 1, size, __FILE__, __LINE__ )              /* Tag: Debug Public */
#define FreeGenericStructure( p ) _DebugFree( p, __FILE__, __LINE__ )                             /* Tag: Debug Public */
#define AllocateTXBuffer( port, size ) _DebugCalloc( 1, size, __FILE__, __LINE__ )                /* Tag: Debug Public */
#define FreeTXBuffer( port, p ) _DebugFree( p, __FILE__, __LINE__ )                               /* Tag: Debug Public */
#define AllocateRXBuffer( port, size ) _DebugCalloc( 1, size, __FILE__, __LINE__ )                /* Tag: Debug Public */
#define FreeRXBuffer( port, p ) _DebugFree( p, __FILE__, __LINE__ )                               /* Tag: Debug Public */
#define AllocateXferBuffer( size ) _DebugCalloc( 1, size, __FILE__, __LINE__ )                    /* Tag: Debug Public */
#define FreeXferBuffer( p ) _DebugFree( p, __FILE__, __LINE__ )                                   /* Tag: Debug Public */

#ifdef __cplusplus
extern "C" {
#endif

typedef void ( * _FailureRoutine )( int terminate, char *fmt, ... );
void * GF_CONV _DebugMalloc( size_t size, char *file, long line );
void * GF_CONV _DebugCalloc( size_t nitems, size_t size, char *file, long line );
void GF_CONV _DebugFree( void *p, char *file, long line );
char * GF_CONV _DebugStrdup( const char *p, char *file, long line );
int GF_CONV _DebuggingHeap( void );

#ifdef __cplusplus
}
#endif

/*
 * This stuff only gets turned on if a customer wants to
 * debug his or her own use of malloc(), etc.
 */

#if defined( _DEBUG ) && defined( GF_ENABLE_HEAP_DEBUGGING )
/*
 * I need to make sure any prototypes created by alloc.h or malloc.h are
 * set up before I define the replacement macros.
 */

#if defined( GF_MICROSOFT_C )
  #include <malloc.h>
#elif defined( GF_BORLAND_CPP ) || defined( GF_TURBO_CPP )
  #include <alloc.h>
#endif
#include <string.h>

#define malloc( i ) _DebugMalloc( i, __FILE__, __LINE__ )          /* Tag: Debug private */
#define calloc( i, j ) _DebugCalloc( i, j, __FILE__, __LINE__ )    /* Tag: Debug private */
#define free( p ) _DebugFree( p, __FILE__, __LINE__ )              /* Tag: Debug private */
#define strdup( p ) _DebugStrdup( p, __FILE__, __LINE__ )          /* Tag: Debug private */
#endif
#endif /* #if defined( _DEBUG ) && defined( GF_ENABLE_HEAP_DEBUGGING ) */

/*
 * _GFAssertFailure is the function called by AL_ASSERT() and
 * AL_ASSERT_OBJECT() when their assertion fails.
 */

#ifdef __cplusplus
extern "C" {
#endif

void GF_CDECL _GFAssertFailure( const char GF_DLL_FAR *condition,
                                const char GF_DLL_FAR *filename,
                                int line,
                                const char GF_DLL_FAR *message,
                                ... );
#ifdef __cplusplus
}
#endif

/*
 * By definition, assertions go away when you turn on NDEBUG.  Our assertions
 * aren't exactly the same as those in the RTL, but we will use the
 * same philosophy for consistency.
 */

#if defined( NDEBUG )

/*
 * Microsoft C++ 7.0 with /W4 and /Ox and /DNDEBUG gives an error on
 * my GF_ASSERT statements.  Not only that, I can't turn off the
 * error.  This ugly hack seems to help.
 */

#if defined( GF_MICROSOFT_C )
#if ( _MSC_VER < 0x800 )
#  define GF_ASSERT( condition, message ) { int p = 0; }
#endif
#endif

#if !defined( GF_ASSERT )
#  define GF_ASSERT( condition, message ) ((void) 0)
#endif

#else /* #if defined( NDEBUG ) */

/*
 * In debug mode, GF_ASSERT() tests the condition, and generates
 * an abort with an error message when the condition fails.
 */
#define GF_ASSERT( condition, message ) /* Tag: Debug private */ \
            ( ( condition ) ?                                    \
                   (void) 0 :                                    \
                   _GFAssertFailure( #condition,                 \
                                     __FILE__,                   \
                                     __LINE__,                   \
                                     message ) )

#endif /* #if defined( NDEBUG ) ... #else */

#endif /* !defined( __DEBUG_H ) */
