#ifndef __MODEMA_DOT_H
#define __MODEMA_DOT_H

/*
 * _MODEMA.H            5.20A  June 8, 1995
 *
 *  The Greenleaf Comm Library
 *
 *  Copyright (C) 1991-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 * This header file contains constants, structures, and definitions
 * used by the Modem Assist interface code.  There should generally
 * not be any reason for an end user of the library to include this file.
 *
 * MODIFICATIONS
 *
 *
 */

#include "modema.h"

typedef struct modem_assist_port {
    int line_status;
    int peek_char;
    unsigned int input_count;
    unsigned int output_count;
    int rts;
    int xon_xoff;
    int rts_cts;
    char name[ 17 ];
} MODEM_ASSIST_PORT;

int GF_CONV _DumpPortStatusModemAssist( PORT *port, PORT_DUMPER printer );

#endif  /* #ifndef __MODEMA_DOT_H */
