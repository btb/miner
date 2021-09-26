#ifndef __DIGI_DOT_H
#define __DIGI_DOT_H

/*
 * _DIGI.H              5.20A  June 8, 1995
 *
 *  The Greenleaf Comm Library
 *
 *  Copyright (C) 1991-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 * This header file contains constants, structures, and definitions
 * used by the smart digiboard interface code.  There should generally
 * not be any reason for an end user of the library to include this file.
 *
 * MODIFICATIONS
 *
 * December 12, 1992  4.00A : Initial release
 */

#define DIGIBOARD_XON_XOFF              0x01
#define DIGIBOARD_RTS_CTS               0x02
#define DIGIBOARD_INPUT_FLOW_CONTROL    0x04
#define DIGIBOARD_OUTPUT_FLOW_CONTROL   0x08
#define DIGIBOARD_XON_CHARACTER         0x10
#define DIGIBOARD_XOFF_CHARACTER        0x20

typedef struct smart_digiboard {
    int line_status;
    int xon_xoff;
    int rts_cts;
    int dtr_dsr;
    char far *char_ready_flag;
    char driver_name[ 9 ];
    char port_name[ 9 ];
} DIGIBOARD;

int GF_CONV _DumpPortStatusSmartDigiboard( PORT *port, PORT_DUMPER printer );

#endif    /* #ifndef __DIGI_DOT_H  */

