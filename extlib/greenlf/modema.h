#ifndef _MODEMA_DOT_H
#define _MODEMA_DOT_H

/*
 * MODEMA.H            5.20A  June 8, 1995
 *
 *  The Greenleaf Comm Library
 *
 *  Copyright (C) 1994-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 * This header file contains the definitions needed to use the Level 1
 * Modem Assist functions.  Note that you can redefine the port count
 * macro here, then rebuild MODEMA_?.C to up the port count.  Most
 * systems won't have anything close to 16 ports, so the odds are that
 * you won't ever have to do this.
 *
 * MODIFICATIONS
 *
 *
 */

#define MODEM_ASSIST_PORT_COUNT 16

/*
 * This is the structure used by Modem Assist in the Query Service Names
 * functions. Note that the character arrays are *not* null terminated
 * by the Modem Assist functions.
 */

struct service_names {
    short int length;
    char server[ 16 ];
    char group[ 16 ];
    char line[ 16 ];
    short int status;
};

/*
 * Level 1 functions to help using Modem Assist.
 */

#ifdef __cplusplus
extern "C" {
#endif

int GF_CONV SetModemAssistLineName( int port_number, char *name );
char * GF_CONV GetModemAssistLineName( int port_number );
int GF_CONV ModemAssistGetFirstServiceName( struct service_names *buffer );
int GF_CONV ModemAssistGetNextServiceName( struct service_names *buffer );
int GF_CONV ModemAssistPresent( void );
int GF_CONV ModemAssistPortAvailable( int port_number );
int GF_CONV ScanModemAssistNames( void );

#ifdef __cplusplus
}
#endif

#endif /* #ifndef _MODEMA_DOT_H */

