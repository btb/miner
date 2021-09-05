#ifndef _TEXTWIN_DOT_H
#define _TEXTWIN_DOT_H

/*
 * TW.H              5.20A  June 8, 1995
 *
 * The Greenleaf Comm Library
 *
 * Copyright (C) 1984-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 *  This file contains all the function prototypes, structures, and other
 *  definitions needed to use the TW stuff under Windows.
 *
 * MODIFICATIONS
 *
 * December 12, 1992  4.00A : Initial release
 *
 * December 6, 1994   5.00D : TWGetLine() was modified for Win32 to accept
 *                            Unicode strings for the caption and prompt.
 *                            The function did not change for 16-bit Windows.
 *
 */

#include "compiler.h"
#if defined( GF_WINDOWS ) || defined( GF_WIN32 )
#include <windows.h>

#ifdef GF_ZORTECH_CPP
#include <dos.h>
#define _fcalloc farcalloc
#define _ffree farfree
#endif


typedef enum tw_attribute { TW_NORMAL=0, TW_REVERSE } TW_ATTR;

/*
 * VTW stands for Virtual Text Window.  A Text Window is nominally a virtual
 * 132x25 window, with scroll back capability of 75 lines.
 */

#define VTW_MAX_ROWS         25
#define VTW_MAX_COLS         132
#define VTW_BUFFER_ROWS      100
#define VTW_BUFFER_COLS      132
#define VTW_CARET_ROW_OFFSET ( VTW_BUFFER_ROWS - VTW_MAX_ROWS )

struct TWINSTANCEDATAtag {
    HINSTANCE ThisInstance;
    HINSTANCE WhatInstance;
    int ThisShow;
    HWND ClientHandle;
    int TWAppClosed;
    HMENU TWMainMenu;
    HMENU TWFileMenu;
    HMENU TWWindowMenu;
    HWND TWFrameHandle;
#if defined( GF_WINDOWS ) && !defined( GF_WIN32 )
    HTASK hTask;
#elif defined( GF_WIN32 )
    HANDLE hTask;
#else
    int hTask;
#endif
    int nRefCount;
};

typedef struct {
    HWND hwnd;
    LPSTR Title;
    int VTWRows;                     /* Rows in the Virtual Text Window    */
    int VTWCols;                     /* Cols in the Virtual Text Window    */
    int VTWCaretRow;                 /* Current Caret row in the VTW       */
    int VTWCaretCol;                 /* Current Caret col in the VTW       */
    int CharWidth;
    int CharHeight;
    int VisibleRows;
    int VisibleCols;
    int VisibleXPixels;
    int VisibleYPixels;
    int FirstVisibleCol;
    int FirstVisibleRow;
    int FirstVisibleRowOffset;
    int CaretOn;
    int HasFocus;
    int Scrollable;
    int CurrentAttribute;
    unsigned int KeyboardHead;
    unsigned int KeyboardTail;
    unsigned int KeyboardBuffer[ 128 ];
    char ScreenBuffer[ VTW_BUFFER_ROWS ][ VTW_BUFFER_COLS ];
    char AttributeBuffer[ VTW_BUFFER_ROWS ][ VTW_BUFFER_COLS ];
    HFONT Font;
    HFONT OldFont;
    int LastCommand;
    struct TWINSTANCEDATAtag far *lpThis;
#if !defined( GF_ZORTECH_CPP ) && !defined( GF_WATCOM_C ) && !defined( GF_SYMANTEC_CPP )
} GF_FAR TW_WINDOW;
#else
} STW_WINDOW;

#if defined( GF_SYMANTEC_CPP )
#if __INTSIZE__ == 2 && ( __SMALL__ || __COMPACT__ || __MEDIUM__ )
#define TW_WINDOW   STW_WINDOW GF_FAR
#else
#define TW_WINDOW   STW_WINDOW GF_FAR
#endif
#else
#define TW_WINDOW   STW_WINDOW GF_FAR
#endif
#endif

#define SetTWNotifyHandler  SetTWCommNotifyHandler

#ifdef __cplusplus
extern "C" {
#endif

extern int TWAppClosed;
extern HMENU TWMainMenu;
extern HMENU TWFileMenu;
extern HMENU TWWindowMenu;
extern HWND TWFrameHandle;


int GF_CONV TWInitialize( HANDLE hInstance,
                  HANDLE PreviousInstance,
                  int nCmdShow,
                  char GF_DLL_FAR *title );
TW_WINDOW * GF_CONV TWDefineWindow( int ul_row,
                                    int ul_col,
                                    int width,
                                    int height,
                                    int scrollable,
                                    char GF_DLL_FAR *name,
                                    char GF_DLL_FAR *font,
                                    int font_size );
void GF_CONV TWPutc( TW_WINDOW *window, int c );
void GF_CONV TWPuts( TW_WINDOW *window, char GF_DLL_FAR *string );
void GF_CDECL TWPrintf( TW_WINDOW *window, char GF_DLL_FAR *fmt, ... );

int GF_CONV TWKbhit( TW_WINDOW *vw );
unsigned int GF_CONV TWGetkey( TW_WINDOW *vw );
void GF_CONV TWPokec( TW_WINDOW *window, int row,
                       int col, int c );
void GF_CONV TWScrollUp( TW_WINDOW *window, int line_count );
void GF_CONV TWScrollDown( TW_WINDOW *window, int line_count );
void GF_CONV TWYield( void );
void GF_CONV TWSetAttribute( TW_WINDOW *window, int attribute );
void GF_CONV TWPokes( TW_WINDOW *window, int row,
                       int col, char GF_DLL_FAR *string );
void GF_CONV TWGoto( TW_WINDOW *window, int row, int col );
void GF_CDECL TWPokef( TW_WINDOW *window, int row, int col,
                           char GF_DLL_FAR *fmt, ... );
void GF_CONV TWClearWindow( TW_WINDOW *window );
void GF_CONV TWInsertChar( TW_WINDOW *window, int row, int col, int c );
void GF_CONV TWDeleteChar( TW_WINDOW *window, int row, int col );
void GF_CONV TWClearToEndOfLine( TW_WINDOW *window, int row, int col );
void GF_CONV TWClearToEndOfWindow( TW_WINDOW *window, int row, int col );
#if defined( GF_WIN32 )
int GF_CONV TWGetLine( LPWSTR caption, LPWSTR prompt,
                       char GF_DLL_FAR *buffer, int n );
#else
int GF_CONV TWGetLine( char GF_DLL_FAR *caption, char GF_DLL_FAR *prompt,
                       char GF_DLL_FAR *buffer, int n );
#endif
int GF_CONV TWMenu( TW_WINDOW *tw, unsigned char row, unsigned char col, char GF_DLL_FAR *menu[] );


char * GF_CONV TWGets( TW_WINDOW *window, char GF_DLL_FAR *string, int length );
struct TWINSTANCEDATAtag far * GF_CONV GetTWInstanceDataPtr( void );

void GF_CONV TWFreeInstanceData( void );
void GF_CONV TWFreeWindow( TW_WINDOW *tw );

#ifdef GF_ZORTECH_CPP
void far * _fmemset( void far *buf, int val, size_t count );
char far * _fstrcpy( char far *string1, const char far *string2 );
void far * _fmemmove( void far *dest, const void far *srce, size_t count );
#endif

#ifndef VGFD_DLL
extern int ( GF_CONV * TWCommNotifyHandler )( TW_WINDOW *tw, HWND hwnd,
                            WPARAM wParam, LPARAM lParam );

void GF_CONV SetTWCommNotifyHandler( int (GF_CONV *f)( TW_WINDOW *tw,
                                                       HWND hwnd,
                                                       WPARAM wParam,
                                                       LPARAM lParam ) );
#endif


#ifdef __cplusplus
}
#endif

#endif /* ifdef GF_WINDOWS */

#endif /* #ifndef _TEXTWIN_DOT_H */

