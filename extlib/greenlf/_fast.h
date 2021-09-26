#ifndef __FAST_DOT_H
#define __FAST_DOT_H

/*
 * _FAST.H      5.20A  June 8, 1995
 *
 *  The Greenleaf Comm Library
 *
 *  Copyright (C) 1991-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 * This header file contains constants, structures, and definitions
 * used by the Greenleaf Fast interface code.  There should generally
 * not be any reason for an end user of the library to include this file.
 *
 * MODIFICATIONS
 *
 * December 12, 1992  4.00A : Initial release
 */

/*
 * In order to change the buffer size, you need to edit the line here
 * and change the 1024 to some other power of 2.  Then change the
 * equivalent line in _FISRASM.EQU to the same number.  Finally,
 * BUILD X FAST_*.C F_*.ASM, and you have a new buffer size.
 */

#define FAST_BUFFER_SIZE      1024
#define FAST_HIGH_WATER_MARK  ( ( FAST_BUFFER_SIZE * 3 ) / 4 )
#define FAST_LOW_WATER_MARK   ( FAST_BUFFER_SIZE / 4 )

/*
 * #define FAST_ISR_IN_C
 */

/*
 * Note that real far pointers are saved as unsigned longs.  This
 * prevents protected mode code from accidentally choking if and
 * when it treats a real mode address as a pointer
 */

#define FAST_PORT  struct _tag_fast_port

#if defined( GF_X32 )
#pragma pack( 1 )
#endif

struct _tag_fast_port {
#if defined( GF_X32 )
    GF_FARPTR32 next_fast_port;
    GF_FARPTR16 real_next_fast_port;
#elif defined( GF_X16 )
    struct _tag_fast_port far *next_fast_port;
    GF_REALPTR16 real_next_fast_port;
#else
    struct _tag_fast_port GF_FAR *next_fast_port;
    unsigned long real_next_fast_port;
#endif
    int fast_id;
    int uart_base;
    int head_pointer;
    int tail_pointer;
    int interrupt_number;
    int line_status;
    int mcr_rx_handshake_bit;
    int msr_tx_handshake_bit;
    int blocking;
    int is_16550;
    int use_16550_TX_fifo;
    int trigger_level;
    char buffer[ FAST_BUFFER_SIZE ];
};

#undef FAST_PORT

typedef struct _tag_fast_port FAST_PORT;

/*
 * A short port is just the fast port minus the buffer.  I use this
 * a lot under the 32 bit DOS extenders, when I copy the port structure
 * into a shadow structure to dink with it.
 */

typedef struct _tag_short_fast_port {
#if defined( GF_X32 )
    GF_FARPTR32 next_fast_port;
    GF_FARPTR16 real_next_fast_port;
#elif defined( GF_X16 )
    struct _tag_fast_port far *next_fast_port;
    GF_REALPTR16 real_next_fast_port;
#else
    struct _tag_fast_port GF_FAR *next_fast_port;
    unsigned long real_next_fast_port;
#endif
    int fast_id;
    int uart_base;
    int head_pointer;
    int tail_pointer;
    int interrupt_number;
    int line_status;
    int mcr_rx_handshake_bit;
    int msr_tx_handshake_bit;
    int blocking;
    int is_16550;
    int use_16550_TX_fifo;
    int trigger_level;
} SHORT_FAST_PORT;
int GF_CONV _DumpPortStatusGreenleafFast( PORT *port, PORT_DUMPER printer );

#if defined( GF_X32 )
  void GF_CDECL _GreenleafFastRealIsr( GF_FARPTR16 fast_port );
  void GF_CDECL _GreenleafFastIsr( GF_FARPTR32 fast_port );
#elif defined( GF_X16 )
  void GF_CDECL far _GreenleafFastRealIsr( FAST_PORT far *fast_port );
  void GF_CDECL far _GreenleafFastIsr( FAST_PORT far *fast_port );
#else
  void GF_CDECL GF_FAR _GreenleafFastIsr( FAST_PORT GF_FAR *fast_port );
#endif

#if defined( GF_X32 )
#pragma pack()
#endif

#endif  /* #ifndef __FAST_DOT_H */

