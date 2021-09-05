#ifndef __SPARK_DOT_H
#define __SPARK_DOT_H

/*
 * _SPARK.H                5.20A  June 8, 1995
 *
 *  The Greenleaf Comm Library
 *
 *  Copyright (C) 1991-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 * This header file contains constants, structures, and definitions
 * used by the Greenleaf Sparkle interface code.  There should
 * generally not be any reason for an end user of the library to
 * include this file.
 *
 * MODIFICATIONS
 *
 * December 12, 1992  4.00A : Initial release
 */

typedef struct sparkle_port {
    int line_status;
    long baud_rate;
    char parity;
    int word_length;
    int stop_bits;
    int initial_bx;
    int initial_cx;
    unsigned int char_counter;
    char name[ 41 ];
} SPARKLE_PORT;

int GF_CONV _DumpPortStatusSparkle( PORT *port, PORT_DUMPER printer );


#endif  /* #ifndef __SPARK_DOT_H */

