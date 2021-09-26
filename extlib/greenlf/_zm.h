#ifndef __ZM_DOT_H
#define __ZM_DOT_H

/*
 * _ZM.H                5.20A  June 8, 1995
 *
 *  The Greenleaf Comm Library
 *
 *  Copyright (C) 1984-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 * This header file has the declarations necessary for accessing the "private"
 * zmodem transfer support routines.  Every private routine has a name that
 * starts with an underscore. Since the private routines are actually found
 * in several different files, there is no way to make them truly private,
 * but the high end user would be best off just ignoring these routines.
 *
 * MODIFICATIONS
 *
 * December 12, 1992  4.00A : Initial release
 */

/*
 * Note that these constants are taken from Chuck Forsberg's
 * Public Domain code, and are therefore not copyrighted by
 * Greenleaf Software.
 */

#define ZRQINIT 0       /* Request receive init */
#define ZRINIT  1       /* Receive init */
#define ZSINIT 2        /* Send init sequence (optional) */
#define ZACK 3          /* ACK to above */
#define ZFILE 4         /* File name from sender */
#define ZSKIP 5         /* To sender: skip this file */
#define ZNAK 6          /* Last packet was garbled */
#define ZABORT 7        /* Abort batch transfers */
#define ZFIN 8          /* Finish session */
#define ZRPOS 9         /* Resume data trans at this position */
#define ZDATA 10        /* Data packet(s) follow */
#define ZEOF 11         /* End of file */
#define ZFERR 12        /* Fatal Read or Write error Detected */
#define ZCRC 13         /* Request for file CRC and response */
#define ZCHALLENGE 14   /* Receiver's Challenge */
#define ZCOMPL 15       /* Request is complete */
#define ZCAN 16         /* Other end canned session with CAN*5 */

#define ZPAD            '*'
#define ZDLE            CAN
#define ZBIN            'A'
#define ZHEX            'B'
#define ZVBIN           'a'
#define ZVHEX           'b'
#define ZBIN32          'C'
#define ZMAXHLEN        16
#define ZMAXSPLEN       1024

#define ZCRCE 'h'       /* CRC next, frame ends, header packet follows */
#define ZCRCG 'i'       /* CRC next, frame continues nonstop */
#define ZCRCQ 'j'       /* CRC next, frame continues, ZACK expected */
#define ZCRCW 'k'       /* CRC next, ZACK expected, end of frame */
#define ZRUB0 'l'       /* Translate to rubout 0177 */
#define ZRUB1 'm'       /* Translate to rubout 0377 */

#define CANFDX  01      /* Rx can send and receive true FDX */
#define CANOVIO 02      /* Rx can receive data during disk I/O */

int GF_CONV _ZmodemReadFrameHeader( XFER *zmodem, int immediate_return );

int GF_CONV _ZmodemSendBinaryPacket( XFER *zmodem,
                                     int length,
                                     char terminator );
int GF_CONV _ZmodemReadBinaryPacket( XFER *zmodem );
int GF_CONV _ZmodemSendBinaryHeader( XFER *zmodem, char frame_type,
                                     char *header_data );
int GF_CONV _ZmodemSendHexHeader( XFER *zmodem, char frame_type,
                                  unsigned char *header_data );

#endif   /* #ifdef __ZM_DOT_H */

