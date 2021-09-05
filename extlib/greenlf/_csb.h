#ifndef __CSB_DOT_H
#define __CSB_DOT_H

/*
 * _CSB.H                5.20A  June 8, 1995
 *
 *  The Greenleaf Comm Library
 *
 *  Copyright (C) 1984-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 * This header file has the declarations necessary for accessing the
 * "private" CompuServe B+transfer support routines.  Every private
 * routine has a name that starts with an underscore.  Since the private
 * routines are actually found in several different files, there is no
 * way to make them truly private, but the high end user would be best
 * off just ignoring these routines.
 *
 * MODIFICATIONS
 *
 * April 29, 1994  5.00A : Initial release
 */

#define BPLUS_SEND_AHEAD_BUFFERS        5 /* Number of buffers before ACK */
                                          /* is expected                  */
#define BPLUS_DEFAULT_PACKET_SIZE       1031
#define BPLUS_MASK_LO_RANGE             0x01
#define BPLUS_MASK_HI_RANGE             0x10

/*
 * CompuServe B+ quoting levels and mask
 */
#define BPLUS_QUOTING_LEVEL_0     0       /* No qouting level */
#define BPLUS_QUOTING_LEVEL_1     1
#define BPLUS_QUOTING_LEVEL_2     2
#define BPLUS_QUOTING_LEVEL_3     3
#define BPLUS_QUOTING_MASK        4


typedef enum {
    BPLUS_GET_DLE,
    BPLUS_DLE_SEEN,
    BPLUS_DLE_B_SEEN,
    BPLUS_GET_DATA,
    BPLUS_GET_CHECKSUM,
    BPLUS_GET_CRC_16,
    BPLUS_GET_CRC_32,
    BPLUS_VERIFY_CRC,
    BPLUS_VERIFY_CHECKSUM,
    BPLUS_VERIFY_PACKET,
    BPLUS_SEND_NAK,
    BPLUS_SEND_ACK,
    BPLUS_SEND_ENQ,
    BPLUS_RESEND_PACKETS
} BPLUS_ACTION;


#define NORMAL_MODE      0
#define ESCAPE_SEQ_MODE  1
#define BPLUS_LOW_RANGE  7
#define BPLUS_HIGH_RANGE 11
#define BPLUS_PLUS_PACKET_SIZE  18


typedef struct pending_info {
  int seq_num;
  int packet_size;
  unsigned char *packet;
} PENDING_PACKET;

typedef struct _csb_options {
        int transfer_complete;
        int s_seq_num;
        int buffer_size;
        int char_timeout;
        int last_character;
        int not_masked;
        int packets_not_acked;
        PENDING_PACKET pending[ BPLUS_SEND_AHEAD_BUFFERS ];
        int pending_count;
        int next_packet;
        char check_crc;
        int sent_enq;
        int last_ack;
        int quoting;
        char mask[ 32 ];
} _CSB_DATA;

int GF_CONV _BPTransfer( XFER *bplus );
unsigned short int GF_CONV _CalculateBPlusCRC16( unsigned short crc,
                                                 unsigned char c );

#endif   /* #ifdef __CSB_DOT_H */

