#ifndef GFTERM_DOT_H
#define GFTERM_DOT_H

/*
 * GFTERM.H       5.20A  June 8, 1995
 *
 * The Greenleaf Comm Library
 *
 * Copyright (C) 1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 *  This is the master include file for the GFTerm windows control.
 *  This is the control that we use for terminal emulation under
 *  Windows.
 *
 * MODIFICATIONS
 *
 * June 8, 1995       5.20A : Initial release
 *
 * June 14, 1995      5.20A : Went on a renaming binge.  Everything that
 *                            use to be WinTerm is now GFTerm.
 */

#ifdef __cplusplus
extern "C" {
#endif

/*
 * I use GFTERM_CAST in some of the terminal code to make
 * warning messages go away.  I have to cast void pointers
 * to HWND objects in some places, and various compilers
 * get upset if the cast isn't done properly.
 */

#ifdef _LDATA
#define GFTERM_CAST long
#else
#define GFTERM_CAST int
#endif

/*
 * The public access routines used to
 * read and write to the GFTerm guys.
 */

int GF_CONV InitGFTerm( HINSTANCE instance );
void GF_CONV _GFTermPutc( void * hwnd, int c );
int GF_CONV GFTermKbhit( HWND hWnd );
void GF_CONV _GFTermPuts( void *hWnd, char *s);
void GF_CONV _GFTermClearWindow( void *hWnd );
void GF_CONV _GFTermGoto( void *hWnd, int r, int c );
void GF_CONV _GFTermBeep( void *hWnd );
void GF_CONV _GFTermSetForeground( void *hWnd, int c );
void GF_CONV _GFTermSetBackground( void *hWnd, int c );
void GF_CONV _GFTermClearToEol( void *hWnd );
void GF_CONV _GFTermSetNormal( void *hWnd );
void GF_CONV _GFTermSetReverse( void *hWnd );
void GF_CONV _GFTermSetBold( void *hWnd );
void GF_CONV _GFTermSetBlink( void *hWnd );
void GF_CONV _GFTermSetUnderline( void *hWnd );
void GF_CONV _GFTermSetInvisible( void *hWnd );
int GF_CONV _GFTermCurrentRow( void * hWnd );
int GF_CONV _GFTermCurrentCol( void * hWnd );
int GF_CONV _GFTermRows( void * hWnd );
int GF_CONV _GFTermCols( void *hWnd );
void GF_CONV _GFTermSetWrap( void * hWnd, int flag );

/*
 * Almost all of the access functions for GFTerm use
 * void pointers as their arguments.  I provide a set
 * of macros that take care of casting a void * to an
 * HWND, so that it appears that there is a function
 * that actually takes an HWND as an argument.
 */
/*
 * Do I still need all of these?
 *
#define GFTermPutc( hWnd, c ) _GFTermPutc( (void *)(hWnd), (c) )
#define GFTermPuts( hWnd, s ) _GFTermPuts( (void *) (hWnd), (s) )
#define GFTermClearWindow( hWnd ) _GFTermClearWindow( (void *)( hWnd ) )
#define GFTermGoto( hWnd, r, c ) _GFTermGoto( (void *) (hWnd), (r), (c) )
#define GFTermBeep( hWnd ) _GFTermBeep( (void *) (hWnd ) )
#define GFTermSetForeground( hWnd, c ) _GFTermSetForeground( (void *)( hWnd ), ( c ) )
#define GFTermSetBackground( hWnd, c ) _GFTermSetBackground( (void *)( hWnd ), ( c ) )
#define GFTermClearToEol( hWnd ) _GFTermClearToEol( (void *) hWnd )
#define GFTermSetNormal( hWnd ) _GFTermSetNormal( (void *)( hWnd ) )
#define GFTermSetReverse( hWnd ) _GFTermSetReverse( (void *)( hWnd ) )
#define GFTermSetBold( hWnd ) _GFTermSetBold( (void *)( hWnd ) )
#define GFTermSetBlink( hWnd ) _GFTermSetBlink( (void *)( hWnd ) )
#define GFTermSetUnderline( hWnd ) _GFTermSetUnderline( (void *)( hWnd ) )
#define GFTermSetInvisible( hWnd ) _GFTermSetInvisible( (void *)( hWnd ) )
#define GFTermCurrentRow( hWnd ) _GFTermCurrentRow( (void *)(hWnd ) )
#define GFTermCurrentCol( hWnd ) _GFTermCurrentCol( (void *)(hWnd ) )
#define GFTermRows( hWnd ) _GFTermRows( (void *)(hWnd ) )
#define GFTermCols( hWnd ) _GFTermCols( (void *)(hWnd ) )
#define GFTermSetWrap( hWnd, flag ) _GFTermSetWrap( (void *)(hWnd), (flag ) )
 */

/*
 * These are friendly versions for use in debugging
 * or whatever.
 */
void GF_CDECL GFTermPrintf( HWND hWnd, char FAR *fmt, ... );
int GF_CONV GFTermGetKey( HWND hWnd );

#ifdef __cplusplus
}
#endif

#endif  /* #ifndef GFTERM_DOT_H */
