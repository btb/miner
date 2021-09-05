#ifndef _COMWIN_DOT_H
#define _COMWIN_DOT_H

/*
 * _COMWIN.H          5.20A  June 8, 1995
 *
 * The Greenleaf Comm Library
 *
 * Copyright (C) 1984-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 * This file contains the internal structures and function definitions
 * used by the MSWindows comm driver.  Probably this file should have
 * been named _mswin.h for consistency, but it's too late to change
 * that now.
 *
 * MODIFICATIONS
 *
 * December 12, 1992  4.00A : Initial release
 *
 * February 7, 1995   5.10C : Added OVERLAPPED element to win_data
 *                            structure to allow overlapped I/O in
 *                            Win32.
 *
 */

#include "commlib.h"

#if defined( GF_WINDOWS ) || defined( GF_WIN32 )

#include <windows.h>

struct win_data {
    UINT input_buffer_size;
    UINT output_buffer_size;
    DCB dcb;
    int windows_status;
#if defined( GF_WIN32 )
    DWORD event_mask;
#else
    char GF_FAR *event_mask;
#endif
    int base_8250;
    int notification;
    int notify_disabled;
    int rx_notify;
    int tx_notify;
    unsigned int notify_events;
    HWND hwnd;
#if defined( GF_WIN32 )
    HANDLE com_handle;
    COMMTIMEOUTS comm_timeouts;
    OVERLAPPED ov;
#endif
};

#if defined( GF_WIN32 )
int GF_CONV _DumpPortStatusMSWin32( PORT *port, PORT_DUMPER printer );
#elif defined( GF_WINDOWS )
int GF_CONV _DumpPortStatusMSWindows( PORT *port, PORT_DUMPER printer );
#endif

#endif /* #ifdef GF_WINDOWS */

#endif /* #ifndef _COMWIN_DOT_H */
