/*
 * INDEP.H            5.20A  June 8, 1995
 *
 * The Greenleaf Comm Library
 *
 *  Copyright (C)1986-1995 Greenleaf Software Inc. All Rights Reserved.
 *
 * NOTES
 *
 *  This file contains the prototpes for the language independent
 *  functions.
 *
 * MODIFICATIONS
 *
 * October 12, 1994  5.10A : Initial release
 *
 */
#ifndef _INDEP_DOT_H
#define _INDEP_DOT_H

#ifndef COMMLIB_DOT_H
#include "commlib.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

int GF_CONV CLGetPortStatus( PORT GF_DLL_FAR *port );
int GF_CONV CLGetPortHandle( PORT GF_DLL_FAR *port );
int GF_CONV CLGetPortDriverType( PORT GF_DLL_FAR *port );
int GF_CONV CLGetPortDialingMethod( PORT GF_DLL_FAR *port );
int GF_CONV CLGetPortCount( PORT GF_DLL_FAR *port );

int GF_CONV CLReadChar( PORT GF_DLL_FAR *port );
int GF_CONV CLPeekChar( PORT GF_DLL_FAR *port );
int GF_CONV CLWriteChar( PORT GF_DLL_FAR *port, int c );
int GF_CONV CLPortClose( PORT GF_DLL_FAR *port );
int GF_CONV CLPortSet( PORT GF_DLL_FAR *port,
                       long baud_rate,
                       char *parity,
                       int word_length,
                       int stop_bits );
int GF_CONV CLUseXonXoff( PORT GF_DLL_FAR *port, int control );
int GF_CONV CLUseRtsCts( PORT GF_DLL_FAR *port, int control );
int GF_CONV CLUseDtrDsr( PORT GF_DLL_FAR *port, int control );
int GF_CONV CLSetDtr( PORT GF_DLL_FAR *port, int control );
int GF_CONV CLSetRts( PORT GF_DLL_FAR *port, int control );
long GF_CONV CLSpaceFreeInTXBuffer( PORT GF_DLL_FAR *port );
long GF_CONV CLSpaceUsedInTXBuffer( PORT GF_DLL_FAR *port );
long GF_CONV CLSpaceFreeInRXBuffer( PORT GF_DLL_FAR *port );
long GF_CONV CLSpaceUsedInRXBuffer( PORT GF_DLL_FAR *port );
int GF_CONV CLClearTXBuffer( PORT GF_DLL_FAR *port );
int GF_CONV CLWriteBuffer( PORT GF_DLL_FAR *port, char GF_DLL_FAR *buffer, unsigned int count );
int GF_CONV CLReadBuffer( PORT GF_DLL_FAR *port, char GF_DLL_FAR *buffer, unsigned int count );
#if defined( GF_WINDOWS ) || defined( GF_WIN32 )
int GF_CONV CLDumpPortStatusVB( PORT GF_DLL_FAR *port, HWND status_window );
#endif
int GF_CONV CLSendBreak( PORT GF_DLL_FAR *port, int milliseconds );
int GF_CONV CLGetModemStatus( PORT GF_DLL_FAR *port );
int GF_CONV CLGetLineStatus( PORT GF_DLL_FAR *port );
int GF_CONV CLClearLineStatus( PORT GF_DLL_FAR *port );
int GF_CONV CLBlock( PORT GF_DLL_FAR *port, int control );
void GF_CONV CLClearError( PORT GF_DLL_FAR *port );

#ifdef __cplusplus
}
#endif

#endif

