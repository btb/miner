#ifndef _STAR_DOT_H
#define _STAR_DOT_H

/*
 * STARGATE.H              5.20A  June 8, 1995
 *
 *  The Greenleaf Comm Library
 *
 *  Copyright (C) 1991-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 * This header file contains the prototypes need to call the single
 * Level 1 functions that come with the Stargate Intelligent board driver.
 *
 * MODIFICATIONS
 *
 * December 12, 1992  4.00A : Initial release
 */

enum RS485_TYPE { TWO_WIRE, FOUR_WIRE, NONE };


int GF_CONV ConfigureSmartStarGateBoard( int board,
                                         unsigned int board_segment,
                                         unsigned int port,
                                         int first_port_number,
                                         int number_of_ports
                                       );

int GF_CONV StarGateEnable485( PORT *port, enum RS485_TYPE type );

#endif  /* #ifndef _STAR_DOT_H */

