#ifndef FAST_DOT_H
#define FAST_DOT_H

/*
 * FAST.H             5.20A  June 8, 1995
 *
 * The Greenleaf Comm Library
 *
 * Copyright (C) 1984-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 * This file contains the prototypes and structure definitions needed to
 * use some of the FAST driver stuff.
 *
 * MODIFICATIONS
 *
 * December 12, 1992  4.00A : Initial release
 *
 */

#include "commlib.h"

#define MAX_DEFINED_FAST_PORTS 8

#ifdef __cplusplus
extern "C" {
#endif

int GF_CONV FastSetPortHardware( int port, int irq, int address );
int GF_CONV FastGetPortHardware( int port, int *irq, int *address );
int GF_CONV FastSet16550TriggerLevel( TRIGGER_LEVEL level );
void GF_CONV FastSet16550UseTXFifos( int control );

int GF_CONV FastSavePortParameters( int port );
int GF_CONV FastRestorePortParameters( int port );
int GF_CONV FastGetSavedPortParameters( int port,
                                        long *baud_rate,
                                        char *parity,
                                        int *word_length,
                                        int *stop_bits,
                                        int *dtr,
                                        int *rts,
                                        int *trigger_level );
int GF_CONV FastSetSavedPortParameters( int port,
                                        long baud_rate,
                                        char parity,
                                        int word_length,
                                        int stop_bits,
                                        int dtr,
                                        int rts,
                                        int trigger_level );

void GF_CONV EnableHP95LXPort( void );
void GF_CONV DisableHP95LXPort( void );
int  GF_CONV IsHP95LX( void );
int  GF_CONV ModifyFastBlockRoutine( PORT *port );

#ifdef __cplusplus
}
#endif

#endif /* #ifndef FAST_DOT_H */
