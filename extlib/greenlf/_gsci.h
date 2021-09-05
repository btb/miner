#ifndef __GSCI_DOT_H
#define __GSCI_DOT_H

#include "gsci.h"
/*
 * _GSCI.H              5.20A  June 8, 1995
 *
 *  The Greenleaf Comm Library
 *
 *  Copyright (C) 1991-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 * This header file contains constants, structures, and definitions
 * used by the Greenleaf Standard Communications Interface code.
 * There should generally not be any reason for an end user of the
 * library to include this file.
 *
 * MODIFICATIONS
 *
 * December 12, 1992  4.00A : Initial release
 */

#define CRCTAB_LENGTH   90
#define _ISA_PORTS      4
#define _MC_PORTS       8

int GF_CONV _DumpPortStatusGreenleaf( PORT *port, PORT_DUMPER printer );
PORT * GF_CONV _PortAttachGreenleafHandle( int port_number );
void GF_CONV _InitializeGreenleafData( void );
extern unsigned int _isa_8250ports[ _ISA_PORTS ];
extern unsigned int _mc_8250ports[ _MC_PORTS ];
extern unsigned int as_8250port[ MAX_PORT ];
extern unsigned char _isa_intnums[ _ISA_PORTS ];
extern unsigned char _mc_intnums[ _MC_PORTS ];
extern unsigned char as_intnums[ MAX_PORT ] ;
extern unsigned as_8259ports[ MAX_PORT ];
extern unsigned char _isa_8259irq[ _ISA_PORTS ];
extern unsigned char _mc_8259irq[ _MC_PORTS ];
extern unsigned char as_8259irq[ MAX_PORT ];
extern int as_brkdly[ MAX_PORT ];
extern int as_wmodem[ MAX_PORT ];
extern int as_wtime[ MAX_PORT ];
extern int as_rtime[ MAX_PORT ];
extern unsigned int as_shioad[ MAX_PORT ];
extern unsigned int as_shbmask[ MAX_PORT ];
extern unsigned char as_out12_mask[ MAX_PORT ];
extern unsigned char as_ls_ms_ier[ MAX_PORT ];
extern int _GreenleafDataInitialized;
extern unsigned int inttbl[ MAX_PORT ];
extern char crctab[ CRCTAB_LENGTH ];


void GF_CDECL GF_FAR _GsciIsaIsrDispatcher( void GF_FAR *port );
void GF_CDECL GF_FAR _GsciMcIsrDispatcher( void GF_FAR *first_ptb );

/*
 * This is an experimental routine that I am using to try using
 * to read the modem status register directly...  This has caused
 * big time problems in the past!!!
 */

int               GF_CDECL _asigetmsr( struct PORT_TABLE *port_structure );
int               GF_CDECL _asgetc( unsigned base_8250_address );
int               GF_CDECL _asputc( unsigned base_8250_address, int c );
int               GF_CDECL _asigetc( struct PORT_TABLE *port_structure );
int               GF_CDECL _asiputc( struct PORT_TABLE *port_structure,
                                     int character );
int               GF_CDECL _asipekc( struct PORT_TABLE *port_structure );
void              GF_CDECL _asiprime( struct PORT_TABLE *port_structure );
int               GF_CONV  _asrts( unsigned io_address,
                                   int on_off,
                                   struct PORT_TABLE *port_structure );
int               GF_CONV  _asdtr( unsigned io_address, int on_off );
void              GF_CDECL _asiresume( unsigned port,
                                       int interrupt_register,
                                       struct PORT_TABLE *port_structure );
void              GF_CDECL _asihold( unsigned base_8250_address,
                                     int interrupt_register,
                                     struct PORT_TABLE *port_structure );
int               GF_CONV  _asiinit( unsigned io_address,
                                     int divisor,
                                     unsigned parity_stop_bits_word_length );
void              GF_CONV  _asibreak( unsigned io_address,int on_off );
int               GF_CONV  _asistart( struct PORT_TABLE *port_structure );
void              GF_CONV  _asidiag( unsigned io_address, int on_off );
void              GF_CONV  _asiquit( enum GSCI_HANDLER_TYPE latch,
                                     struct PORT_TABLE *port_structure);
int               GF_CONV  _asifirst( int port_number,
                                      enum GSCI_HANDLER_TYPE latch,
                                      struct PORT_TABLE *port_structure );

int               GF_CONV  InterruptInUseByOthers( int interrupt_number );


#endif   /* #ifndef __GSCI_DOT_H  */

