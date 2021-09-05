#ifndef EMULATOR_DOT_H
#define EMULATOR_DOT_H

/*
 * EMULATOR.H       5.20A  June 8, 1995
 *
 * The Greenleaf Comm Library
 *
 * Copyright (C) 1985-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 *  This is the master include file for CommLib terminal emulation.
 *  The important thing needed here is the definiton of the EMULATOR
 *  structure, which carries around all of the information needed to
 *  run an emulator.
 *
 * MODIFICATIONS
 *
 * Jun 8, 1995  5.20A : Initial release
 */

/*
 * I need to include video.h in order to pick up the definitions
 * of the VID_WINDOW objects for my function prototypes.  Note that
 * I also need definitions of HWND and HANDLE for my canned terminal
 * objects I use under Windows and Win32 console mode.
 */

#include "video.h"

/*
 * I do some funny things with structure definitions in order to
 * make all this stuff work in a C++ like fashion.  The basic deal
 * is that is defined here a core structure called EMULATOR that contains
 * all of the base class definitions used for terminal emulation.
 * Derived classes, such as the Ansi emulation class, will define
 * a copy of EMULATOR that starts with all the same data, but addes
 * new data members onto the end.
 *
 * Here is the way you do it:
 *
 * #define EMULATOR struct _my_emulator
 * struct _my_emulator;
 *
 * #include "emulator.h"
 * #include "_emu.h"
 *
 * struct _my_emulator {
 *   EMULATOR_MEMBERS;
 *   int my_data_1;
 *   int ...
 * };
 *
 *  The macro called EMULATOR_MEMBERS contains all of the members that
 *  have to be placed at the start of the structure.
 *
 *  So this goofy arrangement means that inside my emulator code, I can
 *  do things like this:
 *
 *  foo ( EMULATOR *e )
 *  {
 *    ClearWindow( e );
 *    ...
 *
 *  Even though the structure I am using isn't exactly the same as the
 *  base version of EMULATOR, I can be secure in my knowledged that the
 *  pointer to the clear_window function is in the same place.
 *
 *  I also let you play around with the members that point to the
 *  keyboard and video data.  These have to be the same size as
 *  regular pointers, or the size of the EMULATOR structure
 *  will change, leading to disaster.
 *
 *  The only reason I let you override these is to provide full
 *  type safety in Attach...() routines.  A routine like
 *  VidPutc( VID_WINDOW *v ) can be safely assigned to emulator member
 *  vputc like this:
 *
 *  #define VIDEO_TYPE VID_WINDOW *
 *  #include "emulator.h"
 *
 *  Attach...()
 *  {
 *      emulator->vputc = VidPutc.
 *
 *  This trick means I get the compiler to perform type checking when
 *  I do this assignement.  Without it, I would have to use void pointers
 *  everywhere, and I would lose all my type safety that I worked so
 *  hard to gain.
 *
 *  Unfortunately, things are quite this easy when I pass something funky
 *  like an HWND.  In those cases, I had to resort to void pointers.
 *
 */

#if !defined(  EMULATOR )
#define EMULATOR struct _emulator
#endif

#if !defined( VIDEO_TYPE )
#define VIDEO_TYPE void GF_DLL_FAR *
#endif

#if !defined( KEYBOARD_TYPE )
#define KEYBOARD_TYPE void GF_DLL_FAR *
#endif

/*
 * The base class has built in support for keyboard macros and incoming
 * triggers.  They are both stored in linked lists of structures that
 * are defined here.  Note that derived classes are free to override
 * these, but if I did my job correctly, they shouldn't have to.
 */

struct _incoming_cmd_def {
    struct _incoming_cmd_def GF_DLL_FAR *next_cmd;
    int command;
    char GF_DLL_FAR *string;
};

struct _kbd_macro_def {
    struct _kbd_macro_def GF_DLL_FAR *next_macro;
    int key;
    char GF_DLL_FAR *s;
};

/*
 * The members that show up at the start of the emulator
 * structur, regardless of what follows.
 */

#define EMULATOR_MEMBERS                                                   \
    PORT GF_DLL_FAR *port;                                                 \
    VIDEO_TYPE video;                                                      \
    KEYBOARD_TYPE keyboard;                                                \
    char trace[ 16 ];                                                      \
    int trace_index;                                                       \
    char triggers[ 256 ];                                                  \
    struct _incoming_cmd_def GF_DLL_FAR *first_incoming_cmd_def;           \
    struct _kbd_macro_def GF_DLL_FAR *first_kbd_macro;                     \
    int test_mode;                                                         \
    int input_mask;                                                        \
    char GF_DLL_FAR *current_key;                                          \
    int ( GF_CONV *process_keyboard )( EMULATOR GF_DLL_FAR *emulator );    \
    int ( GF_CONV *process_input )( EMULATOR GF_DLL_FAR *emulator );       \
    void ( GF_CONV *destroy )( EMULATOR GF_DLL_FAR *emulator );            \
    int ( GF_CONV *read_raw_key )( EMULATOR GF_DLL_FAR *emulator );        \
    void ( GF_CONV *clear_window )( VIDEO_TYPE v );                        \
    void ( GF_CONV *clear_to_eol )( VIDEO_TYPE v );                        \
    void ( GF_CONV *goto_rc )( VIDEO_TYPE v, int row, int col );           \
    void ( GF_CONV *vputc )( VIDEO_TYPE v, int c );                        \
    void ( GF_CONV *vputs )( VIDEO_TYPE v, char GF_DLL_FAR *s );           \
    void ( GF_CONV *vset_normal )( VIDEO_TYPE v );                         \
    void ( GF_CONV *vset_reverse )( VIDEO_TYPE v );                        \
    void ( GF_CONV *vset_bold )( VIDEO_TYPE v );                           \
    void ( GF_CONV *vset_blink )( VIDEO_TYPE v );                          \
    void ( GF_CONV *vset_underline )( VIDEO_TYPE v );                      \
    void ( GF_CONV *vset_invisible )( VIDEO_TYPE v );                      \
    void ( GF_CONV *vset_foreground )( VIDEO_TYPE v, int c );              \
    void ( GF_CONV *vset_background )( VIDEO_TYPE v, int c );              \
    void ( GF_CONV *vset_wrap )( VIDEO_TYPE v, int f );                    \
    void ( GF_CONV *vbeep )( VIDEO_TYPE v );                               \
    int ( GF_CONV *row )( VIDEO_TYPE v );                                  \
    int ( GF_CONV *col )( VIDEO_TYPE v );                                  \
    int ( GF_CONV *rows )( VIDEO_TYPE v );                                 \
    int ( GF_CONV *cols )( VIDEO_TYPE v );                                 \
    int ( GF_CONV *define_kbd_macro )( EMULATOR GF_DLL_FAR *e, int key, char GF_DLL_FAR *string );   \
    int ( GF_CONV *undefine_kbd_macro )( EMULATOR GF_DLL_FAR *e, int key );                          \
    int ( GF_CONV *define_incoming_cmd )( EMULATOR GF_DLL_FAR *e, char GF_DLL_FAR *s, int cmd );     \
    int ( GF_CONV *undefine_incoming_cmd )( EMULATOR GF_DLL_FAR *e, char GF_DLL_FAR *s );            \
    void ( GF_CONV *debug_trace )( int c )

/*
 * The default emulator structure.
 */

struct _emulator {
    EMULATOR_MEMBERS;
};

/*
 * Here is how we call the virtual functions in
 * an easier to read manner.  Macros.
 */

#define ProcessKeys( e ) e->process_keyboard( e )                /* Tag: Terminal Public  */
#define ReadRawKey( e ) e->read_raw_key( e )                     /* Tag: Terminal Private */
#define ProcessInput( e ) e->process_input( e )                  /* Tag: Terminal Public  */
#define SetNormal( e ) e->vset_normal( e->video )                /* Tag: Terminal Private */
#define SetReverse( e ) e->vset_reverse( e->video )              /* Tag: Terminal Private */
#define SetBold( e ) e->vset_bold( e->video )                    /* Tag: Terminal Private */
#define SetBlink( e ) e->vset_blink( e->video )                  /* Tag: Terminal Private */
#define SetUnderline( e ) e->vset_underline( e->video )          /* Tag: Terminal Private */
#define SetInvisible( e ) e->vset_invisible( e->video )          /* Tag: Terminal Private */
#define SetBackground( e, c ) e->vset_background( e->video, c )  /* Tag: Terminal Private */
#define SetForeground( e, c ) e->vset_foreground( e->video, c )  /* Tag: Terminal Private */
#define ClearWindow( e ) e->clear_window( e->video )             /* Tag: Terminal Private */
#define ClearToEol( e ) e->clear_to_eol( e->video )              /* Tag: Terminal Private */
#define GotoRc( e, r, c ) e->goto_rc( e->video, r, c )           /* Tag: Terminal Private */
#define Row( e ) e->row( e->video )                              /* Tag: Terminal Private */
#define Col( e ) e->col( e->video )                              /* Tag: Terminal Private */
#define Rows( e ) e->rows( e->video )                            /* Tag: Terminal Private */
#define Cols( e ) e->cols( e->video )                            /* Tag: Terminal Private */
#define SetWrap( e, f ) e->vset_wrap( e->video, f )              /* Tag: Terminal Private */
#define Beep( e ) e->vbeep( e->video )                           /* Tag: Terminal Private */
#define DestroyEmulator( e ) e->destroy( e )                     /* Tag: Terminal Public  */
#define Putc( e, c ) e->vputc( e->video, c )                     /* Tag: Terminal Private */
#define Puts( e, s ) e->vputs( e->video, s )                     /* Tag: Terminal Private */
#define DefineKeyboardMacroString( e, k, s ) e->define_kbd_macro( e, k, s ) /* Tag: Terminal Public  */
#define DefineKeyboardMacroCommand( e, k ) e->define_kbd_macro( e, k, 0 )   /* Tag: Terminal Public  */
#define UndefineKeyboardMacro( e, k ) e->undefine_kbd_macro( e, k )         /* Tag: Terminal Public  */
#define DefineIncomingCommand( e, s, c ) e->define_incoming_cmd( e, s, c )  /* Tag: Terminal Public  */
#define UndefineIncomingCommand( e, s ) e->undefine_incoming_cmd( e, s )    /* Tag: Terminal Public  */
/*
 * This helps fix a documentation error.
 */
#define UndefineIncomingCmd( e, s ) e->undefine_incoming_cmd( e, s )    /* Tag: Terminal Public  */

#ifdef __cplusplus
extern "C" {
#endif

/*
 * For right now, I am including all the prototypes for each
 * and every derived class.  When we have more video types and
 * more emulators, some of these things will have to be broken
 * out into separate header files.
 */

/*
 * All of the supported emulators:  Just 1!  We do need to add
 * basic TTY emulation.  A patch maybe?
 */

EMULATOR GF_DLL_FAR * GF_CONV CreateAnsiEmulator( PORT GF_DLL_FAR *p );

/*
 * The two functions for Greenleaf Text based Vid Windows.  The generic attach
 * function, and the shortcut function that creates *and* attaches.
 */

void GF_CONV AttachVidToEmulator( EMULATOR GF_DLL_FAR *e,
                                  VID_WINDOW GF_DLL_FAR *w );
EMULATOR * GF_CONV CreateAnsiVidEmulator( PORT *p, VID_WINDOW *w );

/*
 * The two functions for Greenleaf WinVid Windows for Win16 and Win32.
 * The generic attach function, and the shortcut function that creates
 * *and* attaches.
 */

#ifdef GF_WINDOWS
EMULATOR GF_DLL_FAR * GF_CONV CreateAnsiGFTermEmulator( PORT GF_DLL_FAR *p,
                                                        HWND hWnd );
void GF_CONV AttachGFTermToEmulator( EMULATOR GF_DLL_FAR *e, HWND hWnd );
#endif

/*
 * The two functions for Greenleaf Win32 native console mode.
 * The generic attach function, and the shortcut function that creates
 * *and* attaches.  Plus, one simple API function to help those
 * Win32 programmers.
 */

#ifdef GF_WIN32
void GF_CONV AttachConsoleToEmulator( EMULATOR GF_DLL_FAR *e,
                                     HANDLE hInput,
                                     HANDLE hOutput );
EMULATOR GF_DLL_FAR * GF_CONV
CreateAnsiConsoleEmulator( PORT GF_DLL_FAR *p,
                           HANDLE hInput,
                           HANDLE hOutput );
void GF_CONV ConsumeAllConsoleInput( EMULATOR GF_DLL_FAR *e,
                                     int flag );
#endif

#ifdef __cplusplus
}
#endif

#endif /* #ifndef EMULATOR_DOT_H */
