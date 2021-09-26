#ifndef _MULTPORT_DOT_H
#define _MULTPORT_DOT_H

/*
 * MULTPORT.H         5.20A  June 8, 1995
 *
 * The Greenleaf Comm Library
 *
 * Copyright (C) 1984-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 *  This header file contains all the function prototypes, definitions,
 *  etc. needed to use any of the GSCI Level 1 multiport board installation
 *  functions.
 *
 * MODIFICATIONS
 *
 * December 12, 1992  4.00A : Initial release
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

int GF_CONV InstallStandardMCADigiboard( int board_number,
                                         int first_port_number );
int GF_CONV RemoveStandardMCADigiboard( int board_number );

int GF_CONV InstallStandardDigiboard( int irq,
                                      int shared_status_port,
                                      int first_port_number,
                                      int port_count,
                                      int GF_DLL_FAR port_addresses[] );
int GF_CONV RemoveStandardDigiboard( int irq );

int GF_CONV InstallStandardStargate( int irq,
                                     int first_port_number,
                                     int first_port_address );
int GF_CONV RemoveStandardStargate( int irq );

int GF_CONV InstallStandardQuaTech( int irq,
                                    int first_port_number,
                                    int first_port_address );
int GF_CONV RemoveStandardQuaTech( int irq );

int GF_CONV InstallStandardFastcom( int irq,
                                    int first_port_number,
                                    int port_count,
                                    int first_port_address );
int GF_CONV RemoveStandardFastcom( int irq );

int GF_CONV InstallStandardBocaBoard( int irq,
                                      int first_port_number,
                                      int port_count,
                                      int first_port_address );
int GF_CONV RemoveStandardBocaBoard( int irq );

int GF_CONV InstallStandardHostessBoard( int irq,
                                         int first_port_number,
                                         int port_count,
                                         int first_port_address );
int GF_CONV RemoveStandardHostessBoard( int irq );

int GF_CONV InstallStandardSeaLevel( int irq,
                                          int first_port_number,
                                          int port_count,
                                          int first_port_address );
int GF_CONV RemoveStandardSeaLevel( int irq );

int GF_CONV InstallStandardAst( int irq,
                                int first_port_number,
                                int first_port_address );
int GF_CONV RemoveStandardAst( int irq );

int GF_CONV InstallStandardContec( int irq,
                                   int first_port_number,
                                   int first_port_address );
int GF_CONV RemoveStandardContec( int irq );

int GF_CONV InstallStandardArnet( int irq,
                                  int shared_status_port,
                                  int first_port_number,
                                  int port_count,
                                  int first_port_address );
int GF_CONV RemoveStandardArnet( int irq );

#ifdef __cplusplus
}
#endif

#endif /* #ifndef _MULTPORT_DOT_H */

