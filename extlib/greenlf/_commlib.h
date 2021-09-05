#ifndef _COMMLIB_DOT_H
#define _COMMLIB_DOT_H

/*
 * COMMLIB.H          5.20A  June 8, 1995
 *
 * The Greenleaf Comm Library
 *
 * Copyright (C) 1984-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 *  This file contains all the private structures and definitions
 *  used for Level 2 support throughout the library.  This header
 *  file gets included in lots of source modules, but shouldn't
 *  ever need to be included in any end user modules.
 *
 * MODIFICATIONS
 *
 * December 12, 1992  4.00A : Initial release
 *
 */

#include "commlib.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Prototypes used internal to CommLib drivers only
 */

void GF_CONV _InitializeDriverFunctions( PORT *port );
void GF_CONV _FreePort( PORT *port );
PORT * GF_CONV _OutOfMemoryPort( void );
#if defined( GF_MICROSOFT_C ) || defined( GF_VISUAL_CPP ) || \
    defined( GF_SYMANTEC_CPP ) || \
    ( defined( GF_BORLAND_CPP) && (GF_COMPILER_VERSION >= 0x300 ))
void GF_CDECL _close_all_ports( void );
#elif defined( GF_WATCOM_C )
void _close_all_ports( void );
#else
void GF_CONV _close_all_ports( void );
#endif

extern int ( GF_CONV * _PortIdleFunctionPtr )( PORT *port );

#ifdef __cplusplus
}
#endif

/*
 * sprintf() and strings need to handled one way under Windows,
 * but differently under DOS.  Here are a couple of things that
 * help with this.  Some of the automatic variables used under
 * MS-DOS need to be static when in a DLL, so that they reside
 * in DS territory instead of SS (e.g. REGS args to int86).  The
 * GF_DLL_STATIC macro does this for us.
 */

#if defined( GF_WINDOWS ) || ( defined( GF_WIN32 ) && !defined( GF_X32 ) )
  #include <windows.h>
  #define GF_SPRINTF      wsprintf          /* Tag: Misc private */
  #define GF_VSPRINTF     wvsprintf         /* Tag: Misc private */
  #define GF_STRING       char GF_FAR *     /* Tag: Misc private */

  #if defined( VGFD_DLL ) || defined( GF_DLL )
    #define GF_STATIC

/*
 * We need to put the prototypes in here of the functions that
 * are set up for the DLL during initialization of the global
 * structure of instance data.
 */
    #include "xfer.h"

int GF_CONV _WindowsDefaultIdleFunction( PORT GF_DLL_FAR *port );
int GF_CONV _WindowsDefaultAbortModemFunction( PORT GF_DLL_FAR *port );
int GF_CONV _WindowsDefaultAbortXferFunction( struct xfer GF_DLL_FAR *xfer );
char GF_DLL_FAR *GF_CONV _DefaultUserErrorNameFunction( int error_code );
FILE GF_DLL_FAR * GF_CONV _DefaultXferFileOpenFunction(
                                           struct xfer GF_DLL_FAR *status,
                                           char GF_DLL_FAR *name,
                                           char GF_DLL_FAR *mode );
  #else  /* #if defined( VGFD_DLL ) || defined( GF_DLL ) */
    #define GF_STATIC       static
  #endif /* #if defined( VGFD_DLL ) ... #else */
#else /* #if defined( GF_WINDOWS ) || ( defined( GF_WIN32 ) ... */
  #define GF_SPRINTF      sprintf     /* Tag: Misc private */
  #define GF_VSPRINTF     vsprintf    /* Tag: Misc private */
  #define GF_STRING       char *
  #define GF_STATIC       static
#endif /* #if defined( GF_WINDOWS ) || ( defined( GF_WIN32 ) ... #else */

#if defined( GF_WINDOWS ) && !defined( GF_WIN32 )
long _far _pascal _CreateVBString( char _far *string,
                                   unsigned short int l );
#endif
#endif  /* #ifndef _COMMLIB_DOT_H */
