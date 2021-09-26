#ifndef XFER_DOT_H
#define XFER_DOT_H

/*
 *  XFER.H                 5.20A  June 8, 1995
 *
 *  The Greenleaf Comm Library
 *
 *  Copyright (C) 1984-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * MODIFICATIONS
 *
 * December 12, 1992  4.00A : Initial release
 *
 * December 13, 1994  5.10A : Added the 5.00D patch.
 *
 * August 18, 1995    5.20B : Added the error_code member to the FILE_ENGINE
 *                            structure.
 */

 /*
 * This header file contains all the public definitions for the code
 * that supports various types of file transfers.  This header file
 * defines the universal XFER protocol structure, plus a bunch of
 * constants.  Any defined file transfer taking place has a parameter
 * block associated with it.  This block contains nearly all of the
 * information needed to figure out what is going on in the transfer at
 * any given time.  The only time the high level code really needs to care
 * about the contents of this structure is if the idle routine is doing
 * any processing on the data.  The definitions of the structure elements
 * follows:
 *
 * file_engine:              This is a pointer to the file engine structure
 *                           that helps the file transfer routines expand
 *                           wild cards and open files.  This is still
 *                           undocumented, so it isn't real easy for a user
 *                           to replace this with a function of their own.
 *
 * filename :                A pointer to the name of the file presently
 *                           being transferred.
 *
 * block_number:             This is the file block number, which starts
 *                           at 0 and keeps incrementing each time a new
 *                           block is transferred.
 *
 * byte_count:               This is the total byte count for the transfer.
 *                           It starts at 0 and goes up when receiving a
 *                           file.  When sending a file it starts at the
 *                           file size and counts down to 0.
 *
 * file_length:              This is the number of bytes that are expected
 *                           for the file to be transfered.  This number is
 *                           presently only used during YMODEM file reception.
 *
 * file_time:                The time stamp for the file currently being
 *                           transferred, in UNIX format.
 *
 * message_routine:          This is a routine used to print out periodic
 *                           transfer status messages.  The parameter is a
 *                           simple character string.
 *
 * idle_routine:             This is the user defined idle routine which
 *                           can print out more detailed information
 *                           than the message_routine. It gets a pointer
 *                           to the current status block.
 *
 * buffer:                   This is a pointer to the packet buffer.  It
 *                           gets set up during initialization, and is
 *                           freed when the driver exits.
 *
 * file:                     This is a file pointer to the currently open
 *                           file.  It gets opened and closed by the driver
 *                           routine.
 *
 * port:                     This is the port structure for the port being
 *                           used for the transfer.  It needs to be an open
 *                           port.  This was changed to be a PORT * in 3.10.
 *
 * abort_key:                Anytime the user hits a key, the driver reads
 *                           it out, and checks to see if it is the same
 *                           as the abort_key in the structure.  If it is,
 *                           the protocol driver cleans up and exits.
 *
 * return_status:            This is the current return status the driver
 *                           has.  This normally is the XFER_SUCCESS
 *                           constant, unless an error has occurred.
 *
 * current_block_size:       This is the size of the block currently being
 *                           sent or received.
 *
 * current_block_checksum:   After the block is read in, the block checksum
 *                           is stored in this structure element.
 *
 * current_block_number:     This is the block number that went out with
 *                           the buffer currently being sent or received.
 *
 * monitor_cd:               If this flag is set, the abort function will
 *                           periodically check for loss of carrier.  If
 *                           carrier goes low, the transfer aborts.
 *
 * subdirectories:           This flag is set if wildcard expansion is
 *                           supposed to search through subdirectories.
 *
 * error_count:              This counter keeps track of the number of errors
 *                           that have occurred during this transfer.
 *
 * block_error_count:        This int keeps track of the number of errors
 *                           encountered during the current block.
 *
 * transfer_type:            The protocol being used during this transfer.
 *
 * sending:                  This flag is set to be TRUE during uploads, and
 *                           false during downloads.
 *
 * strip_path_from_filename: Some of the protocols in use here send and
 *                           receive file names before each file.  This
 *                           element controls whether the path component is
 *                           stripped from those file names, either before
 *                           sending the name or after receiving it.
 *
 * x.xmodem.ack_timeout:     This int contains the length in milliseconds of
 *                           the XMODEM ACK timeout.  It defaults to 10
 *                           seconds, but some installations may want to
 *                           jack up the value.
 *
 * x.xmodem.last_control_character:
 *                           This is the last character received while waiting
 *                           for a control character, such as NAK, ACK or CAN
 *                           during an xmodem file transfer.
 *
 * x.xmodem.crc_mode:        This flag is set true if the 16 bit CRC checksum
 *                           calculation method is in use, and false if
 *                           the additive checksum system is in used during
 *                           an xmodem file transfer.
 *
 * x.zmodem.cancel_count:    During a ZMODEM file transfer, this element
 *                           keeps track of the count of ZCAN characters.
 *
 * x.zmodem.garbage_count:   Used to keep track of the number of garbage
 *                           characters received during a ZMODEM receive.
 *
 * x.zmodem.rx_flag:         The ZMODEM rx flags received from the remote
 *                           end.
 *
 * x.zmodem.error_recovery:  This element is set when the ZMODEM sender
 *                           is undergoing an error recovery.
 *
 * x.zmodem.rx_buffer_size:  The size of the receiver's RX buffer, sent
 *                           during initialization.
 *
 * x.zmodem.rx_frame_output_count :
 *                           This element keeps track of how many bytes have
 *                           been sent in the current frame.  The receiver
 *                           may have sent a buffer size, and we don't
 *                           want to exceed it.
 *
 *
 * x.zmodem.header:          A copy of the header bytes received when the
 *                           last header was read in.
 *
 * x.zmodem.header_type:     The type of the most recent header.
 *
 * x.zmodem.crash_recovery:  If this flag is set, the ZMODEM receiver will
 *                           always check to see if a file exsists before
 *                           beginning to download.  If the file does exist,
 *                           ZMODEM will attempt to perform a crash recovery.
 *
 * x.zmodem.block_before_write:
 *                           If this flag is set, ZMODEM will always try
 *                           to block the sender before writing to the disk.
 *                           This may be necessary to prevent hardware
 *                           overrun errors during disk access.
 *
 * x.zmodem.use_window :     If this flag is set, a window will be used for
 *                           sending a file, which causes the sender to
 *                           wait for a ZACK before continuing to next
 *                           window.  This is on by default and can be
 *                           turned off with the XFER_ZMODEM_NO_WINDOW
 *                           option.
 *
 * x.zmodem.window_size :    This indicates the size of the window that
 *                           the sender will use if use_window is set.
 *
 * x.zmodem.management_options :
 *                           This will indicate which file management
 *                           option is used.
 *
 * x.kermit.max_length:      This is the maximum buffer size that the other
 *                           end wants me to send.  This size refers to
 *                           the actual data size sent in the packet, which
 *                           is the size of the data block plus 3.
 *
 * x.kermit.qbin:            This flag is used to indicate whether binary
 *                           characters should be quoted, i.e. eighth bit
 *                           prefixing.  It is set during the startup
 *                           negotiation.
 *
 * x.kermit.text_mode:       This flag indicates whether upper bits are to
 *                           be stripped out of the file before it is sent,
 *                           or as it is received.
 *
 * x.kermit.timeout:         This is the time in seconds that the remote
 *                           end wants me to use to time out his
 *                           transmissions.
 *
 * x.kermit.pad_count:       This is the number of pad characters that the
 *                           remote end wants me to send before every packet.
 *
 * x.kermit.pad_char:        This is the pad character the remote end expects.
 *
 * x.kermit.eol:             This is the the line terminator that the remote
 *                           end wants.
 *
 * x.kermit.quote_char:      This is the quote character that the remote end
 *                           will be using.
 *
 * x.kermit.his_qbin_char:   This is the quote character that the remote end
 *                           will be using for eight bit prefixing.
 *
 * x.kermit.my_qbin_char:    This is the quote character that I will be
 *                           using for eighth bit prefixing.
 *
 * x.kermit.repeat_flag:     This is used to indicate whether or not run
 *                           length encoding is to be used.  It is set
 *                           during the startup negotiation phase.
 *
 * x.kermit.his_repeat_char: This is the character the remote end has
 *                           sent to tell what he wants as a repeat char
 *                           when performing run length encoding.
 *
 * x.kermit.my_repeat_char:  This is the character I want to use when
 *                           when performing run length encoding.
 *
 * x.kermit.his_capbilities: A copy of the remote end's capability bits.
 *                           We get this during startup.
 *
 * x.ascii.timeout_time:     This is the timeout value that determines how
 *                           long an ASCII receive will sit idle with no
 *                           characters coming in.  This used to be hardcoded,
 *                           but now it is adjustable.
 *
 * x.ascii.received_character_printer:
 *                           This is a pointer to a function used during ASCII
 *                           file transfers.  It is a user supplied function
 *                           that will print out a character at a time to serve
 *                           as a line monitor during the file transfer.
 *
 * x.ascii.delay_milliseconds_per_line:
 *                           This is the value for the number of ms to be
 *                           delayed after every line is sent during an ASCII
 *                           file transfer.
 *
 * x.ascii.strip_lf:         This is a flag which is used to tell whether or
 *                           or not line feed characters should be stripped
 *                           during Ascii file transfers.
 *
 */

#include <stdio.h>
#include "commlib.h"

typedef struct t_file_engine {
    int ( GF_CONV *get_next_filename )( struct t_file_engine GF_DLL_FAR *engine );
    int ( GF_CONV *destroy_file_engine )( struct t_file_engine GF_DLL_FAR *engine );
    void GF_DLL_FAR *local_data;
    char output_name[ 512 ];
    long length;
    long unix_time;
    int year;
    int month;
    int day;
    int hour;
    int minutes;
    int seconds;
    int error_code;
} FILE_ENGINE;

typedef struct xfer{
                    FILE_ENGINE GF_DLL_FAR *file_engine;
                    char GF_DLL_FAR *filename;  /* File presntly being xfered */
                    long block_number;
                    long byte_count;
                    long file_length;
                    long file_time;
                    void (GF_CONV *message_routine)(char GF_DLL_FAR *message);
                    void (GF_CONV *idle_routine)(struct xfer GF_DLL_FAR *x);
                    char GF_DLL_FAR *buffer;
                    FILE GF_DLL_FAR *file;
                    PORT GF_DLL_FAR *port;
                    unsigned int abort_key;
                    int file_count;
                    int return_status;
                    int current_block_size;
                    int current_block_checksum;
                    int current_block_number;
                    int monitor_cd;
                    int subdirectories;
                    int error_count;
                    int block_error_count;
                    char sending;
                    char strip_path_from_filename;
                    int idle_window;
                    char transfer_type;
                    union {
                              struct x_options {
                                         long ack_timeout;
                                         int last_control_char;
                                         char crc_mode;
                              } xmodem;
                              struct csb_options {
                                         void GF_DLL_FAR *bplus_data;
                                         int use_b_plus;
                                         int want_7_bit;
                                         char resume_download;
                                         char resume_upload;
                                         char send_file_info;
                                         char window_size;
                                         char rec_window_size;
                                         char use_transport;
                                         char check_method;
                              } csb;
                              struct z_options {
                                         int cancel_count;
                                         int garbage_count;
                                         int rx_flags;
                                         int error_recovery;
                                         unsigned int rx_buffer_size;
                                         unsigned int rx_frame_output_count;
                                         unsigned char header[ 4 ];
                                         int header_type;
                                         int crash_recovery;
                                         int block_before_write;
                                         int use_window;
                                         int window_size;
                                         int conversion_options;
                                         int management_options;
                                         int read_full_packet;
                                         int max_errors;
                                         int subpacket_size;
                              } zmodem;
                              struct k_options {
                                         int  max_length;
                                         int  qbin;
                                         int  text_mode;
                                         char timeout;
                                         char pad_count;
                                         char pad_char;
                                         char eol;
                                         char quote_char;
                                         char his_qbin_char;
                                         char my_qbin_char;
                                         char repeat_flag;
                                         char his_repeat_char;
                                         char my_repeat_char;
                                         char his_capabilities;
                              } kermit;
                              struct a_options {
                                         long timeout_time;
                                         void (GF_CONV *received_character_printer)(char c);
                                         int  delay_milliseconds_per_line;
                                         int  delay_milliseconds_per_char;
                                         char strip_lf;
                              } ascii;
                          } x;
                   } XFER;

/*
 * These seven constants define all the possible protocols used during
 * file transfers.  Note that type 0, standard XMODEM, can have crc_mode set
 * to be true or false, so it looks kind of like two protocols in one.
 */
#define XFER_TYPE_XMODEM     0
#define XFER_TYPE_XMODEM_1K  1
#define XFER_TYPE_YMODEM     2
#define XFER_TYPE_XMODEM_1KG 3
#define XFER_TYPE_YMODEM_G   4
#define XFER_TYPE_KERMIT     5
#define XFER_TYPE_ASCII      6
#define XFER_TYPE_ZMODEM     7
#define XFER_TYPE_BPLUS      8
/*
 * These are several global constants used to define basic parameters used
 * to define some of the transfer parameters for the various families.
 */
#define XMODEM_RECEIVE_TIMEOUT        10000L /*Buffer receive timeout in seconds */
#define XMODEM_STARTUP_TIMEOUT        5000L  /*Sender startup timeout            */
#define XMODEM_ACK_TIMEOUT            10000L /*Time to wait for ACK after buff   */
#define XMODEM_MAX_ERRORS             10 /*Maximum number of block retries   */

#define KERMIT_MY_MAX_SIZE            94  /*My maximum kermit buffer size.    */
#define KERMIT_MY_PACKET_TIMEOUT      10  /*Buffer receive timeout in seconds */
#define KERMIT_MY_EOL                 '\r'/*The EOL character I want.         */
#define KERMIT_MY_PAD_COUNT           0   /*My incoming pad character count.  */
#define KERMIT_MY_PAD_CHAR            0   /*My incoming pad characer.         */
#define KERMIT_MY_QUOTE_CHAR          '#' /*My quote character.               */
#define KERMIT_MY_QBIN_CHAR           '&' /*My default QBIN quoting character */
#define KERMIT_MY_QBIN_DEFAULT        'Y' /*My default QBIN receive state     */
#define KERMIT_MY_MARK_CHARACTER      1   /*My mark character, normally ^A    */
#define KERMIT_MY_REPEAT_CHARACTER    '~' /*My repeat char                    */
#define KERMIT_MAX_ERRORS             10  /*Maximum number of errors in Kermit*/
/* Change to 5 during debugging */
#define ZMODEM_MAX_ERRORS             10 /*Maximum number of block retries    */
#define BPLUS_MAX_ERRORS              10 /*Maximum number of errors in        */
                                         /*CompuServe B+                      */
#define BPLUS_DEFAULT_PACKET_SIZE     1031 /* Size of B+ packet                */

#define ASCII_RECEIVE_TIMEOUT         10000 /* Timeout timer for ASCII download */

/*
 * These are all the possible return values that can result from an
 * transfer.  They should all be somewhat self-explanatory.  For deeper
 * explanations, it is necessary to go to the source code.
 */

#define XFER_RETURN_SUCCESS         0   /* Successfull file transfer        */
#define XFER_RETURN_CANT_GET_BUFFER -601/* Failed to allocate comm buffer   */
#define XFER_RETURN_CANT_OPEN_FILE  -602/* Couldn't open transfer file      */
#define XFER_RETURN_CANT_SEND_NAK   -603/* Buffer full, can't send NAK      */
#define XFER_RETURN_CANT_SEND_ACK   -604/* Buffer full, can't send ACK      */
#define XFER_RETURN_KEYBOARD_ABORT  -605/* User hit the abort key           */
#define XFER_RETURN_REMOTE_ABORT    -606/* CAN-CAN abort from remote end    */
#define XFER_RETURN_FILE_ERROR      -607/* Failure during file I/O          */
#define XFER_RETURN_PACKET_TIMEOUT  -608/* Timed out waiting for packet     */
#define XFER_RETURN_BAD_PACKET_SIZE -609/* Got an invalid packet size       */
#define XFER_RETURN_TOO_MANY_ERRORS -610/* Got too many errors to go on     */
#define XFER_RETURN_LOGIC_ERROR     -611/* Internal error, will never happen*/
#define XFER_RETURN_CANT_PUT_BUFFER -612/* Error transmitting buffer        */
#define XFER_RETURN_CANT_SEND_EOT   -613/* Buffer full, can't send EOT      */
#define XFER_RETURN_PROTOCOL_ERROR  -614/* Usually a bad packet type in kerm*/
#define XFER_RETURN_CANT_PUT_CHAR   -615/* Error transmitting a character   */
#define XFER_RETURN_CANT_GET_CHAR   -616/* Error receiving a character      */
#define XFER_RETURN_ASCII_TIMEOUT   -617/* Nothing happening during ASCII   */
#define XFER_RETURN_LOST_CARRIER    -618/* Lost carrier during Xfer         */
#define XFER_RETURN_NO_FILES        -619/* Sent no files                    */
#define XFER_SEND_ZSKIP             -620/* Receiver should send ZSKIP       */
#define XFER_RETURN_BAD_PACKET_SEQ  -621/* CompuServe B+ packet sequence err*/
#define XFER_RETURN_PACKET_ARRIVED  -622/* CompuServe B+ packet arrived     */
#define XFER_RETURN_FILE_ENGINE_ERR -623/* File engine failed               */

/*
 * File management options supported by Zmodem
 */
#define ZMRECOV   3
#define ZMNEWL    1
#define ZMAPND    3
#define ZMCLOB    4
#define ZMNEW     5
#define ZMDIFF    6
#define ZMPROT    7

enum FileTransferOptions { XFER_END_OPTIONS = 0,
                           XFER_NOP = 1001,
                           XFER_KERMIT_BINARY_PREFIX = 1002,
                           XFER_KERMIT_TEXT_MODE = 1003,
                           XFER_KERMIT_DISABLE_RLE = 1004,
                           XFER_USE_FULL_PATH_NAME = 1005,
                           XFER_MONITOR_CARRIER = 1006,
                           XFER_ABORT_KEY = 1007,
                           XFER_ADDITIVE_CHECKSUM = 1008,
                           XFER_SUBDIRECTORIES = 1009,
                           XFER_FILE_ENGINE_CONSTRUCTOR = 1010,
                           XFER_USE_G_OPTION = 1011,
                           XFER_ASCII_TIMEOUT_TIME = 1012,
                           XFER_ASCII_CHAR_DELAY = 1013,
                           XFER_ZMODEM_CRASH_RECOVERY = 1014,
                           XFER_ZMODEM_BLOCK_BEFORE_WRITE = 1015,
                           XFER_XMODEM_ACK_TIMEOUT = 1016,
                           XFER_ZMODEM_NO_WINDOW = 1017,
                           XFER_ZMODEM_OVERWRITE_NEWL = 1018,
                           XFER_ZMODEM_OVERWRITE_APPEND = 1019,
                           XFER_ZMODEM_OVERWRITE_ALWAYS = 1020,
                           XFER_ZMODEM_OVERWRITE_DIFF = 1021,
                           XFER_ZMODEM_OVERWRITE_PROT = 1022,
                           XFER_ZMODEM_OVERWRITE_NEW = 1023,
                           XFER_BPLUS_CHECK_METHOD = 1024,
                           XFER_BPLUS_SEND_FILE_INFO = 1025,
                           XFER_BPLUS_RESUME_DOWNLOAD = 1026,
                           XFER_DISPLAY_IDLE = 1027,
                           XFER_ZMODEM_SET_MAX_ERRORS = 1028,
                           XFER_ZMODEM_SET_WINDOW_SIZE = 1029
                         };

typedef struct xfer_options {
    int kermit_bin_prefix;
    int kermit_text_mode;
    int kermit_disable_rle;
    int full_path;
    int monitor_cd;
    int abort_key_opt;
    int abort_key;
    int additive_checksum;
    int xmodem_ack_timeout_opt;
    int xmodem_ack_timeout;
    int subdirectories;
    int g_option;
    int ascii_timeout_opt;
    int ascii_timeout;
    int crash_recovery;
    int blocking;
    int zmodem_window;
    int ovw_mgmt;
    int bp_check_opt;
    int bp_check_method;
    int bp_file_info;
    int bp_resume_dl;
    int idle_display;
    int idle_hwnd;
    int zmodem_errors_opt;
    int zmodem_max_errors;
    int zmodem_window_opt;
    int zmodem_window_size;
} XFER_OPTIONS;


/*                  FILE TRANSFER FUNCTION PROTOTYPES
 *
 * These are the function prototypes for the user interface routines.
 *
 */

#ifdef __cplusplus

extern "C" {
#endif

#define XmodemReceive( p, f, m, i )            /* Tag: File Xfer public */ \
          XmodemReceiveWithOptions( p, f, m, i, XFER_END_OPTIONS )

#define Xmodem1KReceive( p, f, m, i )          /* Tag: File Xfer public */ \
          Xmodem1KReceiveWithOptions( p, f, m, i, XFER_END_OPTIONS )

#define YmodemReceive( p, m, i )               /* Tag: File Xfer public */ \
          YmodemReceiveWithOptions( p, m, i, XFER_END_OPTIONS )

#define KermitReceive( p, m, i )               /* Tag: File Xfer public */ \
          KermitReceiveWithOptions( p, m, i, XFER_END_OPTIONS )

#define AsciiReceive( p, f, m, i, e, s )       /* Tag: File Xfer public */ \
          AsciiReceiveWithOptions( p, f, m, i, e, s, XFER_END_OPTIONS )

#define ZmodemReceive( p, m, i )               /* Tag: File Xfer public */ \
          ZmodemReceiveWithOptions( p, m, i, XFER_END_OPTIONS )

#define XmodemSend( p, f, m, i )               /* Tag: File Xfer public */ \
          XmodemSendWithOptions( p, f, m, i, XFER_END_OPTIONS )

#define Xmodem1KSend( p, f, m, i )             /* Tag: File Xfer public */ \
          Xmodem1KSendWithOptions( p, f, m, i, XFER_END_OPTIONS )

#define YmodemSend( p, f, m, i )               /* Tag: File Xfer public */ \
          YmodemSendWithOptions( p, f, m, i, XFER_END_OPTIONS )

#define KermitSend( p, f, m, i )               /* Tag: File Xfer public */ \
          KermitSendWithOptions( p, f, m, i, XFER_END_OPTIONS )

#define AsciiSend( p, f, m, i, e, s, l )       /* Tag: File Xfer public */ \
          AsciiSendWithOptions( p, f, m, i, e, s, l, XFER_END_OPTIONS )

#define ZmodemSend( p, f, m, i )               /* Tag: File Xfer public */ \
          ZmodemSendWithOptions( p, f, m, i, XFER_END_OPTIONS )

int GF_CDECL YmodemReceiveWithOptions(
                 PORT GF_DLL_FAR *port,
                 void ( GF_DLL_FAR GF_CONV *message_routine )( char GF_DLL_FAR *message ),
                 void ( GF_DLL_FAR GF_CONV *idle_routine )( XFER GF_DLL_FAR *status_block ),
                 enum FileTransferOptions first_option,
                 ... );

int GF_CDECL KermitReceiveWithOptions(
                 PORT GF_DLL_FAR *port,
                 void ( GF_DLL_FAR GF_CONV *message_routine )( char GF_DLL_FAR *message ),
                 void ( GF_DLL_FAR GF_CONV *idle_routine )( XFER GF_DLL_FAR *status_block ),
                 enum FileTransferOptions first_option,
                 ... );

int GF_CDECL ZmodemReceiveWithOptions(
                 PORT GF_DLL_FAR *port,
                 void ( GF_DLL_FAR GF_CONV *message_routine )( char GF_DLL_FAR *message ),
                 void ( GF_DLL_FAR GF_CONV *idle_routine )( XFER GF_DLL_FAR *status_block ),
                 enum FileTransferOptions first_option,
                 ... );

int GF_CDECL YmodemSendWithOptions(
                PORT GF_DLL_FAR *port,
                char GF_DLL_FAR *file_name_list,
                void ( GF_DLL_FAR GF_CONV *message_routine )( char GF_DLL_FAR *message ),
                void ( GF_DLL_FAR GF_CONV *idle_routine )( XFER GF_DLL_FAR *status_block ),
                enum FileTransferOptions first_option,
                ... );

int GF_CDECL KermitSendWithOptions(
                 PORT GF_DLL_FAR *port,
                 char GF_DLL_FAR *file_name_list,
                 void ( GF_DLL_FAR GF_CONV *message_routine )( char GF_DLL_FAR *message ),
                 void ( GF_DLL_FAR GF_CONV *idle_routine )( XFER GF_DLL_FAR *status_block ),
                 enum FileTransferOptions first_option,
                 ... );

int GF_CDECL ZmodemSendWithOptions(
                 PORT GF_DLL_FAR *port,
                 char GF_DLL_FAR *file_name,
                 void ( GF_DLL_FAR GF_CONV *message_routine )( char GF_DLL_FAR *message ),
                 void ( GF_DLL_FAR GF_CONV *idle_routine )( XFER GF_DLL_FAR *status_block ),
                 enum FileTransferOptions first_option,
                 ... );

int GF_CDECL XmodemReceiveWithOptions(
                 PORT GF_DLL_FAR *port,
                 char GF_DLL_FAR *file_name,
                 void ( GF_DLL_FAR GF_CONV *message_routine )( char GF_DLL_FAR *message ),
                 void ( GF_DLL_FAR GF_CONV *idle_routine )( XFER GF_DLL_FAR *status_block ),
                 enum FileTransferOptions first_option,
                 ... );

int GF_CDECL Xmodem1KReceiveWithOptions(
                 PORT GF_DLL_FAR *port,
                 char GF_DLL_FAR *file_name,
                 void ( GF_DLL_FAR GF_CONV *message_routine )( char GF_DLL_FAR *message ),
                 void ( GF_DLL_FAR GF_CONV *idle_routine )( XFER GF_DLL_FAR *status_block ),
                 enum FileTransferOptions first_option,
                 ... );

int GF_CDECL AsciiReceiveWithOptions(
                 PORT GF_DLL_FAR *port,
                 char GF_DLL_FAR *file_name,
                 void ( GF_DLL_FAR GF_CONV *message_routine )( char GF_DLL_FAR *message ),
                 void ( GF_DLL_FAR GF_CONV *idle_routine )( XFER GF_DLL_FAR *status_block ),
                 void ( GF_DLL_FAR GF_CONV *echo_routine )( char c ),
                 char strip_lf,
                 enum FileTransferOptions first_option,
                 ... );

int GF_CDECL XmodemSendWithOptions(
                PORT GF_DLL_FAR *port,
                char GF_DLL_FAR *file_name,
                void ( GF_DLL_FAR GF_CONV *message_routine )( char GF_DLL_FAR *message ),
                void ( GF_DLL_FAR GF_CONV *idle_routine )( XFER GF_DLL_FAR *status_block ),
                enum FileTransferOptions first_option,
                ... );

int GF_CDECL Xmodem1KSendWithOptions(
                PORT GF_DLL_FAR *port,
                char GF_DLL_FAR *file_name,
                void ( GF_DLL_FAR GF_CONV *message_routine )( char GF_DLL_FAR *message ),
                void ( GF_DLL_FAR GF_CONV *idle_routine )( XFER GF_DLL_FAR *status_block ),
                enum FileTransferOptions first_option,
                ... );

int GF_CDECL AsciiSendWithOptions(
                PORT GF_DLL_FAR *port,
                char GF_DLL_FAR *file_name,
                void ( GF_DLL_FAR GF_CONV *message_routine )( char GF_DLL_FAR *message ),
                void ( GF_DLL_FAR GF_CONV *idle_routine )( XFER GF_DLL_FAR *status_block ),
                void ( GF_DLL_FAR GF_CONV *echo_routine )( char c ),
                char strip_lf,
                int line_delay,
                enum FileTransferOptions first_option,
                ... );

int GF_CDECL CompuServeBPlusWithOptions(
                PORT GF_DLL_FAR *port,
                void ( GF_DLL_FAR GF_CONV *message_routine )( char GF_DLL_FAR *message ),
                void ( GF_DLL_FAR GF_CONV *idle_routine )( XFER GF_DLL_FAR *status_block ),
                enum FileTransferOptions first_option,
                ... );

int GF_CONV CompuServeBPlusRespond( PORT GF_DLL_FAR *port, int use_bplus );
XFER_OPTIONS GF_DLL_FAR * GF_CONV CLSetFileTransferOptions( int GF_DLL_FAR options[] );
int GF_CONV CLFileSend( PORT GF_DLL_FAR *port,
                        int transfer_type,
                        char GF_DLL_FAR *file_name_list,
                        int ascii_strip_lf,
                        int ascii_line_delay,
                        XFER_OPTIONS GF_DLL_FAR *send_options );
int GF_CONV CLFileReceive( PORT GF_DLL_FAR *port,
                           int transfer_type,
                           char GF_DLL_FAR *file_name,
                           int ascii_strip_lf,
                           XFER_OPTIONS GF_DLL_FAR *rec_options );


/*
 * A couple of file transfer utilities.
 */

FILE_ENGINE GF_DLL_FAR * GF_CONV CreateDosFileEngine( char GF_DLL_FAR *input_names,
                                                      int recurse_flag );
char GF_DLL_FAR * GF_CONV XferStripPathComponent( char GF_DLL_FAR *name );
void GF_CONV ProcessTXFile( FILE_ENGINE GF_DLL_FAR *engine );
void GF_CONV CloseXferFile( XFER GF_DLL_FAR *xfer );
long GF_CONV CreateUnixTime( int year,
                             int month,
                             int day,
                             int hour,
                             int minute,
                             int second );

/*
 * Global variables used by the file transfer routines.
 */

void GF_CONV SetXferFileOpenFunctionPtr( FILE *(GF_CONV *f)( XFER GF_DLL_FAR *status,
                                                             char GF_DLL_FAR *name,
                                                             char GF_DLL_FAR *mode ) );
void GF_CONV SetDefaultAbortKey( int abort_key );
void GF_CONV SetGlobalXmodemPadCharacter( int new_pad_char );

/*
 * To get around a compiler warning from Watcom, I have to
 * typedef the function called by the abort function.
 * void GF_CONV SetAbortXferFunctionPtr( int (GF_CONV *f)( XFER GF_DLL_FAR *status ) );
 */

typedef int (GF_DLL_FAR GF_CONV *GF_ABORT_FN)(XFER GF_DLL_FAR *);
void GF_CONV SetAbortXferFunctionPtr( GF_ABORT_FN );

#ifdef __cplusplus
}
#endif

#endif /* #ifndef XFER_DOT_H */

