#ifndef _VIDEO_DOT_H
#define _VIDEO_DOT_H

/*
 * VIDEO.H      5.20A  June 8, 1995
 *
 *  The Greenleaf Comm Library
 *
 *  Copyright (C) 1991-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 * This is the header file needed to use the video routines supplied
 * with CommLib 3.10 and up.  It supplies all the constants, structures,
 * and other definitions needed to use this stuff.
 *
 * MODIFICATIONS
 *
 *  December 12, 1992  4.00A : Initial release
 *  December 1, 1994   5.10A : A few changes to support the new DOS
 *                             extender stuff.
 */

#include "compiler.h"

typedef enum vidtype {
    VID_UNKNOWN = -1,
    VID_MDA,
    VID_CGA,
    VID_EGA,
    VID_MCGA,
    VID_VGA,
} VIDTYPE;

typedef enum vidattribute { VID_NORMAL=0, VID_REVERSE } VIDATTR;

typedef struct {
#if defined( GF_X32 )
    GF_FARPTR32 address;
    void *restore_buffer;
    unsigned char attribute;
#elif defined( GF_WIN32 ) && !defined( DOSX386 ) && !defined( GF_X32 )
    HANDLE hInput;
    HANDLE hOutput;
    CHAR_INFO *restore_buffer;
    WORD attribute;
#else
    unsigned int GF_FAR *address;
    void *restore_buffer;
    unsigned char attribute;
#endif
    int border;
    unsigned char page;
    unsigned char row;
    unsigned char col;
    unsigned char rows;
    unsigned char cols;
    unsigned char first_row;
    unsigned char first_col;
    unsigned char wrap;
} VID_WINDOW;

extern VID_WINDOW * const PhysicalWindow;
extern unsigned char         VidPage;
extern VID_WINDOW *   VidCursorOwner;

#ifdef __cplusplus
extern "C" {
#endif

VIDTYPE GF_CONV VidInitialize( VIDATTR attribute, int save_screen );
VID_WINDOW * GF_CONV VidDefineWindow( unsigned char ul_row,
                                      unsigned char ul_col,
                                      unsigned char lr_row,
                                      unsigned char lr_col,
                                      int border );
void GF_CONV VidTerminate( int restore_screen );
void GF_CONV VidGoto( VID_WINDOW *window, int row, int col );
void GF_CONV VidPhysicalGoto( unsigned char row, unsigned char col );
void GF_CONV VidReadPhysicalPosition( unsigned char *row,
                                      unsigned char *col );
void GF_CDECL VidPrintf( VID_WINDOW *window, char *fmt, ... );
void GF_CONV VidBeep( void );
char * GF_CONV VidGets( VID_WINDOW *window, char *buffer, int n );
void GF_CDECL VidPokef( VID_WINDOW *window, int row, int col,
                        char *fmt, ... );
void GF_CONV VidSetAttribute( VID_WINDOW *window, int attribute );
int GF_CONV VidMenu( unsigned char row, unsigned char col, char *menu[] );
void GF_CONV VidDrawBorder( VID_WINDOW *window );
void GF_CONV VidClearToEndOfWindow( VID_WINDOW *window );
void GF_CONV VidClearToEndOfLine( VID_WINDOW *window );
int GF_CONV VidSet40x25( void );
int GF_CONV VidSet80x25( void );
int GF_CONV VidSet80x28( void );
int GF_CONV VidSet80x43( void );
int GF_CONV VidSet80x50( void );
int GF_CONV VidSetMono( void );
int GF_CONV VidSet640x350( void );
void GF_CONV VidSelectPage( unsigned char c );
void GF_CONV VidSelectFastDrivers( void );
void GF_CONV VidSelectBIOSDrivers( void );
int GF_CONV VidSetWindowPage( VID_WINDOW *window, int page );
void GF_CONV OldVidGetLine( char *prompt, char *field, int length );
int GF_CONV VidGetLine( char *prompt, char *field, int length );
void GF_CONV VidInsertChar( VID_WINDOW *window, int row, int col, int c );
void GF_CONV VidDeleteChar( VID_WINDOW *window, int row, int col );


#if defined( GF_WIN32 ) && !defined( DOSX386 ) && !defined( GF_X32 )

void GF_CONV VidSaveWindow( VID_WINDOW *window );
void GF_CONV VidRestoreWindow( VID_WINDOW *window, int delete_flag );
void GF_CONV VidPuts( VID_WINDOW *window, char *string );
void GF_CONV VidScrollUp( VID_WINDOW *window, int line_count );
void GF_CONV VidPokec( VID_WINDOW *window, int row, int col, int c );
void GF_CONV VidPokes( VID_WINDOW *window, int row,
                                  int col, char *string );
void GF_CONV VidClearWindow( VID_WINDOW *window );
void GF_CONV VidPutc( VID_WINDOW *window, int c );
int GF_CONV VidPeekWord( VID_WINDOW *window, int row, int col );
void GF_CONV VidClearLine( VID_WINDOW *window, int row );
void GF_CONV VidScrollDown( VID_WINDOW *window, int line_count );

#else

extern void ( GF_CONV * VidSaveWindow )( VID_WINDOW *window );                 /* Tag: Video Public */
extern void ( GF_CONV * VidRestoreWindow )( VID_WINDOW *window,                /* Tag: Video Public */
                                            int delete_flag );
extern void ( GF_CONV * VidPuts)( VID_WINDOW *window, char *string );          /* Tag: Video Public */
extern void ( GF_CONV * VidScrollUp )( VID_WINDOW *window, int line_count );   /* Tag: Video Public */
extern void ( GF_CONV * VidPokec )( VID_WINDOW *window, int row,               /* Tag: Video Public */
                                    int col, int c );
extern void ( GF_CONV * VidPokes )( VID_WINDOW *window, int row,               /* Tag: Video Public */
                                    int col, char *string );
extern void ( GF_CONV * VidClearWindow)( VID_WINDOW *window );                 /* Tag: Video Public */
extern void ( GF_CONV * VidPutc)( VID_WINDOW *window, int c );                 /* Tag: Video Public */
extern int ( GF_CONV * VidPeekWord )( VID_WINDOW *window, int row, int col );  /* Tag: Video Public */
extern void ( GF_CONV * VidClearLine)( VID_WINDOW *window, int row );          /* Tag: Video Public */
extern void ( GF_CONV * VidScrollDown )( VID_WINDOW *window, int line_count ); /* Tag: Video Public */

#endif


#ifdef __cplusplus
}
#endif

#define UL_CORNER       218
#define UR_CORNER       191
#define LL_CORNER       192
#define LR_CORNER       217
#define HORIZONTAL_LINE 196
#define VERTICAL_LINE   179
#define TOP_TEE         194
#define RIGHT_TEE       180
#define BOTTOM_TEE      193
#define LEFT_TEE        195
#define CENTER_TEE      197

#if !defined( GF_WIN32 )
#define VID_MKFP( seg, offset ) ( void far *) (((unsigned long) (seg) << 16 ) + (offset) )  /* Tag: Misc private */
#endif

#endif /* _VIDEO_DOT_H */

