#ifndef __XFER_DOT_H
#define __XFER_DOT_H

/*
 * _XFER.H              5.20A  June 8, 1995
 *
 *  The Greenleaf Comm Library
 *
 *  Copyright (C) 1984-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 * This header file has the declarations necessary for accessing the "private"
 * transfer routines.  Every private routine has a name that starts with
 * an underscore. Since the private routines are actually found in three
 * different files, there is no way to make them truly private, but the
 * high end user would be best off just ignoring these routines.
 *
 * MODIFICATIONS
 *
 * December 12, 1992  4.00A : Initial release
 *
 */

#include "xfer.h"

void GF_CONV _YmodemReceive( XFER *xmodem );
void GF_CONV _XmodemReceive( XFER *xmodem );
void GF_CONV _ZmodemReceive( XFER *zmodem );

void GF_CONV _YmodemSend( XFER *xmodem );
void GF_CONV _XmodemSend( XFER *xmodem );
void GF_CONV _ZmodemSend( XFER *zmodem );

int  GF_CONV _XferInitialize( XFER *xfer );
int  GF_CONV _XferOpenFile( XFER *xfer );
void GF_CONV _XferCleanup( XFER *xfer );
int  GF_CONV _XferFlushInput( XFER *xfer );
int  GF_CONV _XferAbortKeyPressed( XFER *xfer );
void GF_CDECL _XferMessage( XFER *xfer, const char *format, ... );

int GF_CONV _AsciiSend( XFER *ascii );
int GF_CONV _AsciiReceive( XFER *ascii );

int GF_CONV _KermitSendPacket( XFER *kermit, char type, int length,
                               char *buffer );
char GF_CONV _KermitReceivePacket( XFER *kermit );
int GF_CONV _KermitInitParameters( XFER *kermit, char data[ 10 ] );
int GF_CONV _KermitUpdateErrorCount( XFER *kermit );
void GF_CONV _KermitLoadInitParameters( XFER *kermit );
void GF_CONV _KermitCleanup( XFER *xfer );

int GF_CONV _KermitReceive( XFER *kermit );
int GF_CONV _KermitSend( XFER *kermit );

int GF_CONV _WriteCharProtocol( XFER *xmodem, int c );
int GF_CONV _WriteBufferProtocol( XFER *xmodem, char *buffer, int length );

#if defined( GF_WINDOWS )
void GF_CONV _WindowsXferDisplayIdle( XFER *xmodem );
void GF_CONV CLFileTransferAbort( void );
int GF_CONV _SetIdleDisplay( HWND hIdle );
#endif


/***********************The usual Kermit macros****************************/

#define tochar( x )   ( ( x ) + 32 )                  /* Tag: File Xfer private */
#define unchar( x )   ( ( x ) - 32 )                  /* Tag: File Xfer private */
#define ctl( x )      ( ( x ) ^ (unsigned char) 64 )  /* Tag: File Xfer private */

extern int _DefaultAbortKey;
extern FILE * ( GF_CONV * _XferFileOpenFunctionPtr )
                        ( XFER *status,
                          char *name,
                          char *mode );
extern int ( GF_CONV * _AbortXferFunctionPtr )( XFER *status );

#endif  /* #ifndef __XFER_DOT_H */

