#ifndef MODEM_DOT_H
#define MODEM_DOT_H

/*
 * MODEM.H            5.20A  June 8, 1995
 *
 * The Greenleaf Comm Library
 *
 * Copyright (C) 1984-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 *  This file contains all the constants, prototypes, and definitions
 *  needed to use CommLib modem functions.  Include this in any source
 *  module that needs to use modem functions.
 *
 * MODIFICATIONS
 *
 * December 12, 1992  4.00A : Initial release
 *
 */

#include "commlib.h"
/*
 * Define dialing methods for HMSetDialingMethod()
 */

#define TOUCH_TONE             0
#define PULSE                  1
#define DEFAULT_DIALING_METHOD 2

/*
 * Define hookswitch states for HMSetHookSwitch()
 */

#define ONHOOK           0
#define OFFHOOK          1
#define SPECIAL_OFFHOOK  2
/*
 * Define special speaker state for HMSetSpeaker()
 */
#define ON_ALWAYS        2

typedef void ( GF_CONV *CHAR_PRINTER)( char c );

#ifdef __cplusplus
extern "C" {
#endif

int  GF_CONV HMReset( PORT GF_DLL_FAR *port );
int  GF_CONV HMGetRegister( PORT GF_DLL_FAR *port,
                            int modem_register );
int  GF_CONV HMSetRegister( PORT GF_DLL_FAR *port,
                            int modem_register, int value );
int  GF_CONV HMSetAutoAnswerRingCount( PORT GF_DLL_FAR *port,
                                       int count );
int  GF_CONV HMGetIncomingRingCount( PORT GF_DLL_FAR *port );
int  GF_CONV HMSetEscapeCode( PORT GF_DLL_FAR *port,
                              char escape_char );
int  GF_CONV HMSetEndOfLineCharacter( PORT GF_DLL_FAR *port,
                                      char end_of_line_char );
int  GF_CONV HMSetLineFeedCharacter( PORT GF_DLL_FAR *port,
                                     char line_feed_char );
int  GF_CONV HMSetBackspaceCharacter( PORT GF_DLL_FAR *port,
                                      char backspace_char );
int  GF_CONV HMSetWaitForDialToneTime( PORT GF_DLL_FAR *port,
                                       int wait_for_dt_time);
int  GF_CONV HMSetWaitTimeForCarrier( PORT GF_DLL_FAR *port,
                                      int wait_for_cd_time );
int  GF_CONV HMSetPauseTimeForComma( PORT GF_DLL_FAR *port,
                                     int pause_time_for_comma );
int  GF_CONV HMSetCDResponseTime( PORT GF_DLL_FAR *port,
                                  int carrier_detect_response );
int  GF_CONV HMSetCarrierDisconnectTime( PORT GF_DLL_FAR *port,
                                         int disc_timer );
int  GF_CONV HMSetTouchToneDuration( PORT GF_DLL_FAR *port,
                                     int dial_speed );
int  GF_CONV HMSetEscapeCodeGuardTime( PORT GF_DLL_FAR *port,
                                       int escape_guard_time );
int  GF_CONV HMGetUARTStatus( PORT GF_DLL_FAR *port );
int  GF_CONV HMGetOptionRegister( PORT GF_DLL_FAR *port );
int  GF_CONV HMGetFlagRegister( PORT GF_DLL_FAR *port );
int  GF_CONV HMGoOnline( PORT GF_DLL_FAR *port );
int  GF_CONV HMSetDialingMethod( PORT GF_DLL_FAR *port,
                                 int method );
int  GF_CONV HMDial( PORT GF_DLL_FAR *port,
                     char GF_DLL_FAR *digit_string );
int  GF_CONV HMRepeatLastCommand( PORT GF_DLL_FAR *port );
int  GF_CONV HMDialInAnswerMode( PORT GF_DLL_FAR *port,
                                 char GF_DLL_FAR *digits );
int  GF_CONV HMDialAndReturnToCommandMode( PORT GF_DLL_FAR *port,
                                           char GF_DLL_FAR *digit_string );
int  GF_CONV HMAnswer( PORT GF_DLL_FAR *port );
int  GF_CONV HMSetCarrier( PORT GF_DLL_FAR *port, int on_off );
int  GF_CONV HMSetEchoMode( PORT GF_DLL_FAR *port, int on_off );
int  GF_CONV HMSetFullDuplexMode( PORT GF_DLL_FAR *port,
                                  int full_or_half );
int  GF_CONV HMSetHookSwitch( PORT GF_DLL_FAR *port,
                              int on_or_off_hook );
int  GF_CONV HMSetSpeaker( PORT GF_DLL_FAR *port,
                           int speaker_control );
int  GF_CONV HMReturnNoResultCodes( PORT GF_DLL_FAR *port,
                                    int on_or_off );
int  GF_CONV HMSelectExtendedResultCodes( PORT GF_DLL_FAR *port,
                                          int extended_codes );
int  GF_CONV HMSetVerboseMode( PORT GF_DLL_FAR *port,
                               int on_of_off );
void GF_CONV HMSetUpEchoRoutine( CHAR_PRINTER character_printer );
/*                            void ( GF_CONV *character_printer)( char c ) );
 */
void GF_CONV HMSetUpAbortKey( unsigned int key );
int  GF_CONV HMSendString( PORT GF_DLL_FAR *port,
                                        char GF_DLL_FAR *string );
int  GF_CONV HMSendStringNoWait( PORT GF_DLL_FAR *port,
                                 char GF_DLL_FAR *string,
                                 int termination_sequence );

void GF_CONV HMWaitForOK( long milliseconds,
                          char GF_DLL_FAR *match_string );
void GF_CONV HMFixedDelay( long milliseconds );

long GF_CONV HMInputLine( PORT GF_DLL_FAR *port,
                          long milliseconds,
                          char GF_DLL_FAR *buffer,
                          int length );
#ifdef __cplusplus
}
#endif

#endif /* #ifndef MODEM_DOT_H */

