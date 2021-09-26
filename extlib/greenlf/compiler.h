#ifndef _COMPILER_DOT_H
#define _COMPILER_DOT_H

/*
 * COMPILER.H      5.20A  June 8, 1995
 *
 * DESCRIPTION
 *
 * This is the header file used by library files to determine
 * compiler/model dependent information.  The compiler-dependent
 * information has in the past been found in a file called GF.H,
 * which also included a few macros, constants, and type definitions.
 *
 *  Copyright (C) 1991-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * MODIFICATIONS
 *
 *  December 12, 1992        : Released with CommLib 4.0
 *  December 1, 1994   5.10A : The usual changes associated with a new release.
 *  December 13, 1994  5.10A : Added patch 5.00D to this project.
 *  June 8, 1995       5.20A : Added NT support for Watcom and Symantec
 *  June 23, 1995      5.20A : Added support for the GF_CON32 macro.  *All*
 *                             of our BUILD INI files set this explicitly,
 *                             but we pick up the definition a couple of
 *                             other ways for users.
 */

#ifndef GF_BLANK
#define GF_BLANK
#endif

#if defined(__TURBOC__) && !defined(__BORLANDC__)
  #if ( __TURBOC__ > 0x201 )
    #define GF_COMPILER_NAME "Turbo C++"
    #define GF_TURBO_CPP
    #define GF_COMPILER_VERSION __TURBOC__
    #define GF_CDECL cdecl
    #define GF_CONV GF_BLANK
    #define ANSI_PROTOTYPES
    #define GF_INTERRUPT interrupt
    #define GF_UNUSED_PARAMETER( a ) (void) a
    #define GF_FAR far
    #ifdef __SMALL__
    #endif
    #ifdef __MEDIUM__
        #define _LCODE 1
    #endif
    #ifdef __COMPACT__
        #define _LDATA 1
    #endif
    #ifdef __LARGE__
        #define _LCODE 1
        #define _LDATA 1
    #endif
    #ifdef __HUGE__
        #define _LCODE 1
        #define _LDATA 2
        #define _HUGE 1
    #endif
  #endif /* __TURBOC__ > 0x201 */
/* End of Turbo C++ */

#elif defined(__TURBOC__) && defined(__BORLANDC__)   /* Borland C++ */
    #define GF_COMPILER_NAME "Borland C++"
    #define GF_BORLAND_CPP
    #define GF_COMPILER_VERSION __BORLANDC__
    #if defined( __CONSOLE__ ) /* Borland turns this on with bcc32 -WC */
      #define GF_CON32
    #endif
    #if defined( _Windows ) && !defined( __DPMI32__ ) && !defined( __DPMI16__ ) && !defined( DOSX386 )
      #define GF_WINDOWS
      #if defined( VGFD_DLL ) || defined( GF_DLL )
        #if defined( __WIN32__ )
          #define GF_CONV __stdcall
          #define GF_CDECL _cdecl
          #define GF_DLL_FAR
        #else
          #define GF_CONV _far pascal
          #define GF_CDECL _far _cdecl
          #define GF_DLL_FAR _far
        #endif
      #else
        #define GF_CONV _cdecl
        #define GF_CDECL _cdecl
      #endif
    #else
      #if ( __BORLANDC__ >= 0x300 )
        #if defined( GF_DLL ) && defined( __WIN32__ )
          #define GF_CONV __stdcall
        #else
          #define GF_CONV _cdecl
        #endif
      #else
          #define GF_CONV GF_BLANK
      #endif
      #define GF_CDECL _cdecl
    #endif
    #ifdef VGFD
      #define GF_STANDARD
    #endif
    #define ANSI_PROTOTYPES
    #define GF_INTERRUPT interrupt
    #define GF_UNUSED_PARAMETER( a ) (void) a
    #if defined( __WIN32__ )
      #define GF_WIN32
      #define GF_FAR
    #else
      #define GF_FAR _far
    #endif
    #ifdef __SMALL__
    #endif
    #ifdef __MEDIUM__
        #define _LCODE 1
    #endif
    #ifdef __COMPACT__
        #define _LDATA 1
    #endif
    #ifdef __LARGE__
        #define _LCODE 1
        #define _LDATA 1
    #endif
    #ifdef __HUGE__
        #define _LCODE 1
        #define _LDATA 2
        #define _HUGE 1
    #endif
/* End of Borland C++ */

/* I think that just adding the loadds statement will make
   all my ASM routines work properly with Watcom C */

#elif defined(__WATCOMC__) && !defined(__386__)
    #include <stddef.h>
    #define GF_COMPILER_NAME "Watcom C"
    #define GF_WATCOM_C
    #define GF_COMPILER_VERSION 900
    #define ANSI_PROTOTYPES
    #define GF_INTERRUPT interrupt _cdecl
    #define GF_UNUSED_PARAMETER( a ) (void) a
    #define GF_FAR _far
    #ifdef __WINDOWS__
      #define GF_WINDOWS
      #if defined( VGFD_DLL ) || defined( GF_DLL )
        #define GF_DLL_FAR _far
        #define GF_CONV _far pascal
        #define GF_CDECL _far _cdecl
      #else
        #define GF_DLL_FAR
        #define GF_CONV _cdecl
        #define GF_CDECL _cdecl
      #endif
    #else /* Not windows */
      #define GF_CDECL _cdecl __loadds
      #define GF_CONV GF_BLANK
    #endif
    #ifdef M_I86SM
    #endif
    #ifdef M_I86MM
        #define _LCODE 1
    #endif
    #ifdef M_I86CM
        #define _LDATA 1
    #endif
    #ifdef M_I86LM
        #define _LCODE 1
        #define _LDATA 1
    #endif
/* End of Watcom C */

#elif defined(__WATCOMC__) && defined(__386__)
    #include <stddef.h>
    #define GF_COMPILER_NAME "Watcom C"
    #define GF_WATCOM_C_386
    #define GF_COMPILER_VERSION 950
    #define GF_CDECL _cdecl
    #define GF_CONV GF_BLANK
    #define ANSI_PROTOTYPES
    #define GF_INTERRUPT __interrupt
    #define GF_UNUSED_PARAMETER( a ) (void) a
    #if defined( __WINDOWS_386__ ) || defined( __NT__ )
      #define GF_WINDOWS
      #define GF_WIN32
      #define GF_FAR
    #else
      #define GF_FAR far
    #endif
    #ifdef M_I86SM
    #endif
    #ifdef M_I86MM
        #define _LCODE 1
    #endif
    #ifdef M_I86CM
        #define _LDATA 1
    #endif
    #ifdef M_I86LM
        #define _LCODE 1
        #define _LDATA 1
    #endif
/* End of Watcom C 386 */

#elif defined( __SC__ )  /* Symantec C/C++ */
    #define GF_COMPILER_NAME "Symantec C/C++"
    #define GF_SYMANTEC_CPP
    #define GF_COMPILER_VERSION __SC__
    #define ANSI_PROTOTYPES
    #define GF_INTERRUPT GF_BLANK
    #define GF_UNUSED_PARAMETER( a ) (void) a
    #if defined( __NT__ )
      #define GF_WIN32
      #define GF_FAR
    #else
      #define GF_FAR _far
    #endif
    #define INPUT( port )        inp( port )
    #define OUTPUT( port, data ) outp( port, data )
    #define CLI()                int_off()
    #define STI()                int_on()
    #ifdef _WINDOWS
      #define GF_WINDOWS
      #if (defined( VGFD_DLL ) || defined( GF_DLL )) && !defined( GF_WIN32 )
        #define GF_DLL_FAR _far
        #define GF_CONV _far pascal
        #define GF_CDECL _far cdecl
      #else
        #define GF_CONV cdecl
        #define GF_CDECL cdecl
      #endif
    #else
      #define GF_CONV GF_BLANK
      #define GF_CDECL cdecl
    #endif
    #ifdef VGFD
      #define GF_STANDARD
    #endif
    #ifdef M_I86SM
    #endif
    #ifdef __MEDIUM__
        #define _LCODE 1
    #endif
    #ifdef __COMPACT__
        #define _LDATA 1
    #endif
    #ifdef __LARGE__
        #define _LCODE 1
        #define _LDATA 1
    #endif
    #ifdef _VCM__
        #define _LCODE 1
        #define _LDATA 1
    #endif
/* End of Symantec C/C++ */

#elif defined( __ZTC__ )                  /* Zortech C/C++         */
    #define GF_COMPILER_NAME "Zortech C/C++"
    #define GF_ZORTECH_CPP
    #define GF_COMPILER_VERSION __ZTC__
    #define ANSI_PROTOTYPES
    #define GF_INTERRUPT GF_BLANK
    #define GF_UNUSED_PARAMETER( a ) (void) a
    #define GF_FAR _far
    #ifdef _WINDOWS
      #define GF_WINDOWS
      #if defined( VGFD_DLL ) || defined( GF_DLL )
        #define GF_DLL_FAR _far
        #define GF_CONV _far pascal
        #define GF_CDECL _far cdecl
      #else
        #define GF_CONV cdecl
        #define GF_CDECL cdecl
      #endif
    #else
      #define GF_CONV GF_BLANK
      #define GF_CDECL cdecl
    #endif
    #ifdef VGFD
      #define GF_STANDARD
    #endif
    #ifdef M_I86SM
    #endif
    #ifdef M_I86MM
        #define _LCODE 1
    #endif
    #ifdef M_I86CM
        #define _LDATA 1
    #endif
    #ifdef M_I86LM
        #define _LCODE 1
        #define _LDATA 1
    #endif
    #ifdef M_I86VM
        #define _LCODE 1
        #define _LDATA 1
    #endif
/* End of Zortech C/C++ */

#elif defined( __TSC__ )                        /* TopSpeed C */
    #define GF_COMPILER_NAME  "TopSpeed C"
    #define GF_TOPSPEED_C
    #define GF_COMPILER_VERSION __TSC__
    #define GF_CDECL cdecl
    #define GF_CONV GF_BLANK
    #define ANSI_PROTOTYPES
    #define GF_INTERRUPT interrupt
    #define GF_UNUSED_PARAMETER( a ) if ( a != a ) a = 0
    #define GF_FAR far
    #if defined( M_I86SM )
    #elif defined( M_I86MM )
        #define _LCODE 1
    #elif defined( M_I86CM )
        #define _LDATA 1
    #elif defined( M_I86LM )
        #define _LCODE 1
        #define _LDATA 1
    #elif defined( M_I86MTM )
        #define _LCODE 1
        #define _LDATA 1
    #elif defined( M_I86XM )
        #define _LCODE 1
        #define _LDATA 1
        #define _HUGE 1
    #else
        #error Unsupported Topspeed memory model!
    #endif
/* End of TopSpeed C/C++ */

#elif defined(M_I86) && defined(MSDOS)
    #define GF_COMPILER_NAME "Microsoft C"
    #define GF_MICROSOFT_C
    #if defined( _CONSOLE ) /* MSC 32 bit environment sets this for Console apps */
      #define GF_CON32
    #endif
/*
 * MSC generates a warning message on GF_ASSERT when compiling in
 * release mode.  This turns it off.
 *
 * MSC 8.0 generates a warning message when it uses a precompiled header!
 * I have to turn this off.
 */
    #if ( _MSC_VER >= 800 )
      #pragma warning( disable : 4705 )
      #pragma warning( disable : 4699 )
    #endif
    #if ( _MSC_VER >= 600 )
        #define GF_COMPILER_VERSION _MSC_VER

        #ifdef _WINDOWS
          #define GF_WINDOWS
          #if defined( VGFD_DLL ) || defined( GF_DLL )
            #define GF_DLL_FAR _far
            #define GF_CONV _far pascal
            #define GF_CDECL _far _cdecl
          #else
            #define GF_CONV _cdecl
            #define GF_CDECL _cdecl
          #endif
        #else
          #define GF_CONV  _fastcall
          #define GF_CDECL _cdecl
        #endif
        #ifdef VGFD
          #define GF_STANDARD
        #endif
        #define ANSI_PROTOTYPES
        #define GF_INTERRUPT interrupt far
        #define GF_UNUSED_PARAMETER( a )   (a = a)
        #define GF_FAR _far
    #endif
    #if defined( M_I86SM )
    #elif defined( M_I86MM )
        #define _LCODE 1
    #elif defined( M_I86CM )
        #define _LDATA 1
    #elif defined( M_I86LM )
        #define _LCODE 1
        #define _LDATA 1
    #else
    #error Unsupported Microsoft C memory model!
    #endif
#elif defined( _M_IX86 )
    #define GF_COMPILER_NAME "Visual C++ 32-bit"
    #define GF_VISUAL_CPP
    #if ( _MSC_VER >= 800 )
        #define GF_COMPILER_VERSION _MSC_VER
        #ifdef _WINDOWS
          #define GF_WINDOWS
        #endif
        #if defined( GF_DLL )
          #define GF_DLL_FAR
          #define GF_CONV
          #define GF_CDECL _cdecl
        #else
          #define GF_CONV _fastcall
          #define GF_CDECL _cdecl
        #endif
        #if defined( _WIN32 )
          #define GF_WIN32
          #if !defined( WIN32 )
            #define WIN32
          #endif
        #endif
        #define ANSI_PROTOTYPES
        #define GF_INTERRUPT
        #define GF_UNUSED_PARAMETER( a )   (a = a)
        #define GF_FAR
        #define _LCODE  0
        #define _LDATA  0
        #define _HUGE   0
    #endif
#endif                                           /* Microsoft C           */

#ifndef GF_COMPILER_NAME
#error This is an unknown compiler!
#endif
#ifndef GF_DLL_FAR
#define GF_DLL_FAR
#endif

#endif  /* #ifdef _COMPILER_DOT_H */
