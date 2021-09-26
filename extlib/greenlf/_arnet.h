#ifndef __ARNET_DOT_H
#define __ARNET_DOT_H

/*
 * _ARNET.H             5.20A  June 8, 1995
 *
 *
 *  The Greenleaf Comm Library
 *
 *  Copyright (C) 1991-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 * This header file contains constants, structures, and definitions
 * used by the Greenleaf Smart Arnet interface code.  There should
 * generally not be any reason for an end user of the library to
 * include this file.
 *
 * MODIFICATIONS
 *
 *  December 12, 1992  4.00A : Initial release
 */

typedef struct arnet_port {
    int line_status;
    int xon_xoff;
    int rts_cts;
    int dtr_dsr;
    unsigned int char_counter;
    long baud_rate;
    char parity;
    int word_length;
    int stop_bits;
} ARNET_PORT;

int GF_CONV _DumpPortStatusSmartArnet( PORT *port, PORT_DUMPER printer );


#endif  /* #ifndef __ARNET_DOT_H */

