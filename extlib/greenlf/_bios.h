#ifndef __BIOS_DOT_H
#define __BIOS_DOT_H

/*
 * _BIOS.H             5.20A  June 8, 1995
 *
 *
 *  The Greenleaf Comm Library
 *
 *  Copyright (C) 1991-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 * This header file contains constants, structures, and definitions
 * used by the Greenleaf Standard BIOS interface code.  There should
 * generally not be any reason for an end user of the library to
 * include this file.
 *
 * MODIFICATIONS
 *
 *  December 12, 1992  4.00A : Initial release
 */

typedef struct bios_port {
    int line_status;
    long baud_rate;
    char parity;
    int word_length;
    int stop_bits;
    int extended_initial_bx;
    int extended_initial_cx;
    unsigned int char_counter;
} BIOS_PORT;

int GF_CONV _DumpPortStatusBIOS( PORT *port, PORT_DUMPER printer );

#endif  /* #ifndef __BIOS_DOT_H */

