#ifndef __FOSSIL_DOT_H
#define __FOSSIL_DOT_H

/*
 * _FOSSIL.H            5.20A  June 8, 1995
 *
 *  The Greenleaf Comm Library
 *
 *  Copyright (C) 1991-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 * This header file contains constants, structures, and definitions
 * used by the Greenleaf FOSSIL interface code.  There should generally
 * not be any reason for an end user of the library to include this file.
 *
 * MODIFICATIONS
 *
 * December 12, 1992  4.00A : Initial release
 */

typedef struct fossil_port {
    int line_status;
    int flow_control_bits;
    char far *fossil_name;
} FOSSIL_PORT;

typedef struct fossil_data {
    int structure_size;
    int revisions;
    char far *ascii_id;
    int input_buffer_size;
    int input_bytes_available;
    int output_buffer_size;
    int output_bytes_available;
    int screen_data;
    int baud_rate_mask;
} FOSSIL_DATA;

void GF_CONV _LoadFossilData( int port, FOSSIL_DATA far *fossil_data );
int GF_CONV _DumpPortStatusFossil( PORT *port, PORT_DUMPER printer );


#endif  /* #ifndef __FOSSIL_DOT_H */

