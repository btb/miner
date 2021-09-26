#ifndef GSCI_DOT_H
#define GSCI_DOT_H

/*
 * GSCI.H             5.20A  June 8, 1995
 *
 * The Greenleaf Comm Library
 *
 * Copyright (C) 1984-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 *  This file contains all the structure definitions and function
 *  prototypes needed by user modules that are going to access GSCI
 *  Level 1 functions.
 *
 * MODIFICATIONS
 *
 * December 12, 1992  4.00A : Initial release
 *
 */
#include "commlib.h"

#define MAX_PORT        35
#define MAX_BUF_SIZE    65535U
#define MIN_BUF_SIZE    2

/*
 * port operating modes
 */
#define ASIN            1
#define ASOUT           2
#define ASINOUT         3
#define BINARY          0
#define ASCII           4
#define NORMALRX        0
#define WIDETRACKRX     128

/*
 *Parity types
 */
#define P_NONE          0
#define P_ODD           1
#define P_EVEN          2
#define P_S_STICK       3
#define P_M_STICK       4



/*
 * Error masks for widetrack rx buffer
 */
#define OVERRUN_ERR       2
#define PARITY_ERR        4
#define FRAMING_ERR       8
#define CTS_STATE        16
#define DSR_STATE        32
#define RI_STATE         64
#define CD_STATE        128

/*
 * Argument values for asicheck()
 */
#define ALERT_FLAG_STOPS_RX_AND_TX       1
#define CTS_LOW_STOPS_TX_INTERRUPTS      2
#define DSR_LOW_DISCARDS_RX_DATA         4
#define CD_LOW_DISCARDS_RX_DATA          8
#define MODEM_STATUS_CHANGES_SET_ALERT   16
#define LINE_STATUS_ERRORS_SET_ALERT     32

/*
 * For asirchk()
 */
#define CHKDISABLE 0
#define CHKDISCARD 1
#define CHKFLAGDISCARD 2
#define CHKFLAG 3
#define CHKRESET 4

/*
 *Define status modes for all those is...() functions
 */
#define IMMEDIATE       0
#define CUMULATIVE      1

/*
 *Buffer Flags (Masks)
 */
#define ALERT   1
#define RXEMPTY 2
#define RXFULL  4
#define RXOVFLOW 8
#define TXEMPTY 16
#define TXFULL  32
#define LINERR  64
#define MODCHG  128

/*
 * Names used as parameters passed to asicheck()
 */

#define IGALERT         1
#define IGCTS           2
#define IGDSR           4
#define IGCD            8
#define IGMSTAT         16
#define IGLSTAT         32

/*
 * Old argument values for the is...() functions
 */
#define DIRECT          0
#define STATIC          1

/*************************************************************************
 *  SUPPORT POLICY RE ALL STRUCTURES FROM HERE ON:                       *
 *                                                                       *
 *  These structures are used internally by the Comm functions and the   *
 *  interrupts.  Feel free to look around, but it's not a good idea to   *
 *  change anything here!                                                *
 *                                                                       *
 ************************************************************************/

/*
 * Port Status Bits (from interrupt process)
 */
struct AS_STBITS {
    unsigned alert     : 1;
    unsigned rxempty   : 1;
    unsigned rxfull    : 1;
    unsigned rxovflow  : 1;
    unsigned txempty   : 1;
    unsigned txfull    : 1;
    unsigned linerr    : 1;
    unsigned modchg    : 1;
    unsigned xchrun    : 1;
    unsigned rchrun    : 1;
    unsigned txwxon    : 1;
    unsigned txwcts    : 1;
    unsigned txwalert  : 1;
    unsigned xoffsent  : 1;
    unsigned rtsactive : 1;
    unsigned txiflag   : 1;
};

/*
 *Interrupt Options (written from application side, read by interrupts)
 */
struct AS_MODEBITS {
    unsigned is_txint                       : 1;
    unsigned is_rxint                       : 1;
    unsigned is_ascii                       : 1;
    unsigned is_rxerror                     : 1;
    unsigned is_receiver_xoffmode           : 1;
    unsigned cts_low_holds_tx_interrupts    : 1;
    unsigned alert_flag_stops_rx_and_tx     : 1;
    unsigned dsr_low_discards_rx_data       : 1;
    unsigned cd_low_discards_rx_data        : 1;
    unsigned modem_status_changes_set_alert : 1;
    unsigned line_errors_set_alert          : 1;
    unsigned is_16550                       : 1;
    unsigned is_blocking                    : 1;
    unsigned is_rchking                     : 1;
    unsigned is_rtscontrol                  : 1;
    unsigned is_transmitter_xoffmode        : 1;
};

/*
 *Port Information Table
 */
struct PORT_TABLE {
    int intrpt_num;                  /* 8250 interrupt no. 0C...            */
    unsigned base_8250;              /* base i/o address of 8250            */
    int p_8250[ 5 ];                 /* previous values for 8250 registers:
                                        0 = line control register,
                                        1 = modem control register, bits 5-7 are FCR
                                        2 = interrupt enable register,
                                        3 = divisor latch LSB,
                                        4 = divisor latch MSB
                                      */
    void ( GF_FAR * p_vector )( void ); /* previous value for interrupt vector */
    unsigned int line_stat;          /* Cumulative line status              */
    unsigned int modem_stat;         /* Cumulative modem status             */
    unsigned int wide_stat;          /* Current wide-track status           */

    int irq_8259;                    /* Interrupt # in 8259 (com0 = 4)      */
    int saved_8259_bits;             /* Previous value of irq_8259 bit      */
    unsigned int port_8259;          /* I/O Address of 8259                 */

    unsigned int rx_cell;            /* size of rx cell ( for wide-track )  */
    unsigned int rx_size;            /* size of receive buffer              */
    unsigned int rx_count;           /* number of bytes in receive buffer   */
    unsigned int rx_head;            /* offset of receive buffer head       */
    unsigned int rx_tail;            /* offset of receive buffer tail       */
#ifdef VGFD
    char GF_FAR *rx_buffer;          /* always points to base of rx buffer  */
#else
    char GF_DLL_FAR *rx_buffer;      /* always points to base of rx buffer  */
#endif
    unsigned int tx_cell;            /* size of tx cell (always 1)          */
    unsigned int tx_size;            /* size of transmit buffer             */
    unsigned int tx_count;           /* number of bytes in transmit buffer  */
    unsigned int tx_head;            /* offset of transmit buffer head      */
    unsigned int tx_tail;            /* offset of transmit buffer tail      */

#ifdef VGFD
    char GF_FAR *tx_buffer;          /* points to base of transmit buffer   */
#else
    char GF_DLL_FAR *tx_buffer;      /* points to base of transmit buffer   */
#endif
    struct AS_STBITS chst_bits;      /* port status bits                    */
    struct AS_MODEBITS chmode_bits;  /* port mode bits IN,OUT,XON,etc       */

    unsigned int rts_lowater;        /* when to assert RTS                  */
    unsigned int rts_hiwater;        /* when to de-assert RTS               */
    unsigned int rx_accum;           /* counter for received characters     */
    unsigned int rx_lowater;         /* When to send an XON                 */
    unsigned int rx_hiwater;         /* When to send an XOFF                */
    int stop_xmt;                    /* The incoming XOFF character         */
    int start_xmt;                   /* The incoming XON character          */
    int stop_rem_xmt;                /* The outbound XOFF character         */
    int start_rem_xmt;               /* The outbound XON character          */

    int break_delay;                 /* The number of ticks in a break      */

    int aswmodem;                    /* Polled mode timeout values          */
    int aswtime;
    int asrtime;

    unsigned int chkchr[ 3 ];        /* Each character occupies the low
                                        8 bits, the high order bit (bit 15)
                                        is set to 1 if rx-interrupts are to
                                        look at this character, bit 14 is set
                                        by interrupt routines and is to be
                                        checked by asirchk().  Bit 8 & 9
                                        determine the mode or option of what
                                        to do                               */
    unsigned int mscount;            /* Modem status interrupt counter      */
    unsigned int lscount;            /* Line status interrupt counter       */
    unsigned int txcount;            /* Transmit interrupt counter          */
    unsigned int rxcount;            /* Receive interrupt counter           */
    int out12_mask;                  /* The OUT1/OUT2 mask                  */
    int ls_ms_ier;                   /* The interrupt enable initial mask   */
    PORT GF_DLL_FAR *generic_driver; /* Pointer to Level 2 structure        */

#ifndef VGFD
    unsigned int tx_16550_limit;     /* FIFO buffer limit for 16550         */
#endif

#ifdef VGFD
    long reserved1; /* for VGFD */
    long reserved2; /* for VGFD */
#endif

};

/*************************************************************************
 *  ARRAYS OF FUNDAMENTAL THINGS THAT MUST BE KNOWN AT INTERRUPT TIME.   *
 *                                                                       *
 *  1.  Pointer to main parameter structure for the port.                *
 *  2.  I/O Address of status reg if shared-int hardware, zero if not.   *
 *  3.  If shared hardware, this is bitmask to compare for the port.     *
 *      Note:  when the int. reads the status port it searches for a     *
 *      match against an entry in this column in the array.              *
 *  4.  Value to be XOR'ed with value read from shared port, this will   *
 *      cover the case where bits in the board's interrupt I.D. register *
 *      are active when 0 instead of active when 1.                      *
 ************************************************************************/

enum GSCI_HANDLER_TYPE { GSCI_STANDARD_HANDLER = 0,
                         GSCI_SHARED_IRQ_HANDLER = 1,
                         GSCI_USER_INSTALLED_HANDLER = 2,
                         GSCI_DEFUNCT_HANDLER = 3 };

struct PORTINFO {
#ifdef VGFD
    struct PORT_TABLE GF_FAR *ptb;
#else
    struct PORT_TABLE GF_DLL_FAR *ptb;
#endif
    unsigned as_shport;
    unsigned as_shbits;
    unsigned as_mask;
    unsigned as_xorv;
    enum GSCI_HANDLER_TYPE handler_type;
#ifdef VGFD
    unsigned task_handle_port;  /* VGFD task handle */
    int vm_id_port;             /* VGFD VM id */
    long reserved2;             /* for VGFD */
#endif
};

#ifdef __cplusplus
extern "C" {
#endif

#ifdef VGFD
extern struct PORTINFO GF_FAR *as_chnl;
#else
extern struct PORTINFO as_chnl[ MAX_PORT ];
#endif
extern int _aserror, _asoprt, _asmask, _asxorv, _comvers;

#ifdef __cplusplus
}
#endif


#define isalert( p )                        _iswhat( ( p ), 1 )  /* Tag: GSCI public */
#define isrxempty( p )                      _iswhat( ( p ), 2 )  /* Tag: GSCI public */
#define isrxfull( p )                       _iswhat( ( p ), 3 )  /* Tag: GSCI public */
#define isrxovflow( p )                     _iswhat( ( p ), 4 )  /* Tag: GSCI public */
#define istxempty( p )                      _iswhat( ( p ), 5 )  /* Tag: GSCI public */
#define istxfull( p )                       _iswhat( ( p ), 6 )  /* Tag: GSCI public */
#define islinerr( p )                       _iswhat( ( p ), 7 )  /* Tag: GSCI public */
#define ismodemerr( p )                     _iswhat( ( p ), 8 )  /* Tag: GSCI public */
#define istxintrunning( p )                 _iswhat( ( p ), 9 )  /* Tag: GSCI public */
#define isrxintrunning( p )                 _iswhat( ( p ), 10 ) /* Tag: GSCI public */
#define AlertFlagStopsRXAndTX( p )          _iswhat( ( p ), 11 ) /* Tag: GSCI public */
#define CTSLowHoldsTXInterrupts( p )        _iswhat( ( p ), 12 ) /* Tag: GSCI public */
#define DSRLowDiscardsRXData( p )           _iswhat( ( p ), 13 ) /* Tag: GSCI public */
#define CDLowDiscardsRXData( p )            _iswhat( ( p ), 14 ) /* Tag: GSCI public */
#define ModemStatusChangesSetAlert( p )     _iswhat( ( p ), 15 ) /* Tag: GSCI public */
#define LineStatusErrorsSetAlert( p )       _iswhat( ( p ), 16 ) /* Tag: GSCI public */

#define isoverrun( p, o )          _isstat( ( p ), o, 1 )        /* Tag: GSCI public */
#define isparityerr( p, o )        _isstat( ( p ), o, 2 )        /* Tag: GSCI public */
#define isframerr( p, o )          _isstat( ( p ), o, 3 )        /* Tag: GSCI public */
#define isbreak( p, o )            _isstat( ( p ), o, 4 )        /* Tag: GSCI public */
#define iscts( p, o )              _isstat( ( p ), o, 5 )        /* Tag: GSCI public */
#define isdsr( p, o )              _isstat( ( p ), o, 6 )        /* Tag: GSCI public */
#define iscd( p, o )               _isstat( ( p ), o, 7 )        /* Tag: GSCI public */
#define isri( p, o )               _isstat( ( p ), o, 8 )        /* Tag: GSCI public */
#define ischgcts( p, o )           _isstat( ( p ), o, 9 )        /* Tag: GSCI public */
#define ischgdsr( p, o )           _isstat( ( p ), o, 10 )       /* Tag: GSCI public */
#define ischgcd( p, o )            _isstat( ( p ), o, 11 )       /* Tag: GSCI public */
#define ischgri( p, o )            _isstat( ( p ), o, 12 )       /* Tag: GSCI public */

#define isncts( p )                 _iswhat( ( p ), 17 )         /* Tag: GSCI public */
#define isndsr( p )                 _iswhat( ( p ), 18 )         /* Tag: GSCI public */
#define isncd( p )                  _iswhat( ( p ), 19 )         /* Tag: GSCI public */
#define isring( p )                 _iswhat( ( p ), 20 )         /* Tag: Defunct Public */
#define isxmrxing( p )              _iswhat( ( p ), 21 )         /* Tag: GSCI public */
#define isxoffblocked( p )          _iswhat( ( p ), 22 )         /* Tag: GSCI public */
#define isctsblocked( p )           _iswhat( ( p ), 23 )         /* Tag: GSCI public */
#define is16550( p )                _iswhat( ( p ), 24 )         /* Tag: GSCI public */
/*
 * The old Hayes Modem function names
 */
#define hmreset     HMReset                                      /* Tag: Modem Defunct */
#define hmregset    HMSetRegister                                /* Tag: Modem Defunct */
#define hmringnum   HMSetAutoAnswerRingCount                     /* Tag: Modem Defunct */
#define hmringcnt   HMGetIncomingRingCount                       /* Tag: Modem Defunct */
#define hmescset    HMSetEscapeCode                              /* Tag: Modem Defunct */
#define hms3set     HMSetEndOfLineCharacter                      /* Tag: Modem Defunct */
#define hms4set     HMSetLineFeedCharacter                       /* Tag: Modem Defunct */
#define hms5set     HMSetBackspaceCharacter                      /* Tag: Modem Defunct */
#define hmdialset   HMSetWaitForDialToneTime                     /* Tag: Modem Defunct */
#define hmcarrset   HMSetWaitTimeForCarrier                      /* Tag: Modem Defunct */
#define hmcomaset   HMSetPauseTimeForComma                       /* Tag: Modem Defunct */
#define hmcarrec    HMSetCDResponseTime                          /* Tag: Modem Defunct */
#define hmcarrdisc  HMSetCarrierDisconnectTime                   /* Tag: Modem Defunct */
#define hmdialrate  HMSetTouchToneDuration                       /* Tag: Modem Defunct */
#define hmescguard  HMSetEscapeCodeGuardTime                     /* Tag: Modem Defunct */
#define hmuart      HMGetUARTStatus                              /* Tag: Modem Defunct */
#define hmoption    HMGetOptionRegister                          /* Tag: Modem Defunct */
#define hmflags     HMGetFlagRegister                            /* Tag: Modem Defunct */
#define hmonline    HMGoOnline                                   /* Tag: Modem Defunct */
#define hmdialmode  HMSetDialingMethod                           /* Tag: Modem Defunct */
#define hmdial      HMDial                                       /* Tag: Modem Defunct */
#define hmrepeat    HMRepeatLastCommand                          /* Tag: Modem Defunct */
#define hmreverse   HMDialInAnswerMode                           /* Tag: Modem Defunct */
#define hmanswer    HMAnswer                                     /* Tag: Modem Defunct */
#define hmcarron    HMSetCarrier                                 /* Tag: Modem Defunct */
#define hmecho      HMSetEchoMode                                /* Tag: Modem Defunct */
#define hmduplex    HMSetFullDuplexMode                          /* Tag: Modem Defunct */
#define hmhook      HMSetHookSwitch                              /* Tag: Modem Defunct */
#define hmspeak     HMSetSpeaker                                 /* Tag: Modem Defunct */
#define hmquiet     HMReturnNoResultCodes                        /* Tag: Modem Defunct */
#define hmextend    HMSelectExtendedResultCodes                  /* Tag: Modem Defunct */
#define hmverbose   HMSetVerboseMode                             /* Tag: Modem Defunct */
#define hmstr       HMSendString                                 /* Tag: Modem Defunct */
#define hmregread   HMGetRegister                                /* Tag: Modem Defunct */


#ifdef __cplusplus
extern "C" {
#endif


int               GF_CONV asiflow( int port_number,
                                   int low_water,
                                   int hi_water,
                                   int rts_on_off,
                                   int cts_on_off );
struct PORT_TABLE * GF_CONV _aschkcnl( int port_number);
int               GF_CONV asdtr( int port_number, int on_off );
int               GF_CONV asgetc( int port_number );
int               GF_CONV asibreak( int port_number, int length_in_ticks );
unsigned int      GF_CONV asibstat( int port_number );
int               GF_CONV asiclear( int port_number, int option );
int               GF_CONV asidiag( int port_number, int on_off );
unsigned int      GF_CONV asierst( int port_number );
int               GF_CONV asifirst( int port_number,
                                    unsigned int operating_mode,
                                    unsigned int rx_buffer_length,
                                    unsigned int tx_buffer_length );
unsigned          int GF_CONV asigetb( int port_number,
                                       char GF_DLL_FAR *buffer,
                                       unsigned int length );
unsigned          int GF_CONV asigetb_timed( int port_number,
                                             char GF_DLL_FAR *buffer,
                                             unsigned int length,
                                             int ticks );
int               GF_CONV asigetc( int port_number );
int               GF_CONV asigetc_timed( int port_number, int ticks );
int               GF_CONV asigetparms( int port_number,
                                       long GF_DLL_FAR *baud_rate,
                                       int GF_DLL_FAR *word_length,
                                       int GF_DLL_FAR *parity,
                                       int GF_DLL_FAR *stop_bits,
                                       int GF_DLL_FAR *dtr,
                                       int GF_DLL_FAR *rts );
unsigned int      GF_CONV asigets( int port_number,
                                   char GF_DLL_FAR *buffer,
                                   unsigned int maximum_length,
                                   int terminating_character );
unsigned int     GF_CONV asigets_timed( int port_number,
                                        char GF_DLL_FAR *buffer,
                                        unsigned int maximum_length,
                                        int terminating_character,
                                        int ticks );
int               GF_CONV asihold( int port_number, unsigned int mode );
int               GF_CONV asicheck( int port_number, int condition,
                                    int on_off );
int               GF_CONV asiinit( int port_number,
                                   long baud_rate,
                                   int parity,
                                   int stop_bits,
                                   int word_length );
unsigned int      GF_CONV asilrst( int port_number );
unsigned int      GF_CONV asilstat( int port_number, 
                                    int immediate_or_cumulative);
unsigned int      GF_CONV asimrst( int port_number );
unsigned int      GF_CONV asimstat( int port_number, 
                                    int immediate_or_cumulative );
int               GF_CONV asiopen( int port_number,
                                   unsigned int mode,
                                   unsigned int rx_buffer_length,
                                   unsigned int tx_buffer_length,
                                   long baud_rate,
                                   int parity,
                                   int stop_bits,
                                   int word_length,
                                   int dtr,
                                   int rts );
int               GF_CONV asipeek( int port_number );
unsigned int      GF_CONV asiputb( int port_number, char * buffer,
                                   unsigned int length );
int               GF_CONV asiputc( int port_number, int character );
unsigned int      GF_CONV  asiputs( int port_number,
                                    char GF_DLL_FAR *output_string,
                                    int termination_sequence );
int               GF_CONV asiquit( int port_number );
int               GF_CONV asirchk( int port_number,
                                   int code_number,
                                   unsigned int code_to_check,
                                   int operation );
int               GF_CONV asireset( int port_number );
int               GF_CONV asiresume( int port_number, unsigned int mode );


int               GF_CONV asistart( int port_number, unsigned int option );
unsigned int      GF_CONV asiwgetb( int port_number,
                                    char GF_DLL_FAR *character_buffer,
                                    unsigned int maximum_length,
                                    char GF_DLL_FAR *status_buffer );
unsigned int      GF_CONV asiwgetb_timed( int port_number,
                                          char GF_DLL_FAR *character_buffer,
                                          unsigned int maximum_length,
                                          char GF_DLL_FAR *status_buffer,
                                          int ticks );
int               GF_CONV asiwgetc( int port_number,
                                    char GF_DLL_FAR *wide_track_buf );
int               GF_CONV asiwgetc_timed( int port_number,
                                          char GF_DLL_FAR *wide_track_buffer,
                                          int ticks );
unsigned int      GF_CONV asiwgets( int port_number,
                                    char GF_DLL_FAR *destination_string,
                                    unsigned int maximum_length,
                                    int terminating_character,
                                    char GF_DLL_FAR *status_buffer );
unsigned int      GF_CONV asiwgets_timed( int port_number,
                                          char GF_DLL_FAR *destination_string,
                                          unsigned int maximum_length,
                                          int terminating_character,
                                          char GF_DLL_FAR *status_buffer,
                                          int ticks );
int               GF_CONV asiwpeek( int port_number,
                                    char GF_DLL_FAR *status_buffer );
int               GF_CONV asixoff( int port_number );
int               GF_CONV asixon( int port_number,
                                  int low_water_mark,
                                  int high_water_mark,
                                  int xon_character,
                                  int xoff_character );
unsigned int      GF_CONV asixrst( int port_number );
int               GF_CONV asputc( int port_number, int character );
unsigned int      GF_CONV asputs(  int port_number,
                                   char GF_DLL_FAR *output_string,
                                   int termination_sequence );
int               GF_CONV asrts( int port_number, int on_or_off );
unsigned int      GF_CONV getrxcnt( int port_number );
unsigned int      GF_CONV gettxfree( int port_number );
int               GF_CONV isrchk( int port_number, int code_number );
int               GF_CONV _isstat( int port_number,
                                   int what_to_check,
                                   int what_to_do );
int               GF_CONV isxmrxcnt( int port_number, unsigned int count );
int               GF_CONV _iswhat( int port_number, int what_to_check );
int               GF_CONV ClearTXWaitConditions( int port );
#if defined( VGFD )
void              GF_CONV UseInterruptCounters( int engage );
#else
void              GF_CDECL UseInterruptCounters( int engage );
void              GF_CONV GreenleafSet16550UseTXFifos( int port, int control );
#endif
int               GF_CONV GreenleafSet16550TriggerLevel( TRIGGER_LEVEL level );
int               GF_CONV GreenleafUseRXXonXoff( int port,
                                                 int low_water,
                                                 int hi_water,
                                                 int xon,
                                                 int xoff );
int               GF_CONV GreenleafUseTXXonXoff( int port, int xon, int xoff );
int               GF_CONV GreenleafUseXonXoff( int port,
                                               int low_water,
                                               int hi_water,
                                               int xon,
                                               int xoff );
int               GF_CONV GreenleafDisableRXXonXoff( int port );
int               GF_CONV GreenleafDisableTXXonXoff( int port );
int               GF_CONV GreenleafDisableXonXoff( int port );
int               GF_CONV SetWidetrackMode( int port, int control );
int               GF_CONV GreenleafSetPortHardware( int port,
                                                    int irq,
                                                    int address );
int               GF_CONV GreenleafGetPortHardware( int port,
                                                    int GF_DLL_FAR *irq,
                                                    int GF_DLL_FAR *address );
int               GF_CONV GreenleafGetSavedPortParameters(
                                                int port,
                                                long GF_DLL_FAR *baud_rate,
                                                char GF_DLL_FAR *parity,
                                                int GF_DLL_FAR *word_length,
                                                int GF_DLL_FAR *stop_bits,
                                                int GF_DLL_FAR *dtr,
                                                int GF_DLL_FAR *rts,
                                                int GF_DLL_FAR *trigger_level );
int               GF_CONV GreenleafSetSavedPortParameters( int port,
                                                           long baud_rate,
                                                           char parity,
                                                           int word_length,
                                                           int stop_bits,
                                                           int dtr,
                                                           int rts,
                                                           int trigger_level );

#ifdef __cplusplus
}
#endif

#ifdef VGFD
#include "sacommon.h"
#endif

#define GREENLEAF_HANDLE_TO_PORT( h )  ( as_chnl[ h ].ptb )->generic_driver   /* Tag: GSCI public */

#endif /* #ifndef GSCI_DOT_H */
