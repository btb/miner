#ifndef __STAR_DOT_H
#define __STAR_DOT_H

/*
 * _STAR.H      5.20A  June 8, 1995
 *
 *
 *  The Greenleaf Comm Library
 *
 *  Copyright (C) 1991-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 * This header file contains constants, structures, and definitions
 * used by the Greenleaf Stargate Intelligent board interface code.
 * There should generally not be any reason for an end user of the
 * library to include this file.
 *
 * MODIFICATIONS
 *
 * December 12, 1992  4.00A : Initial release
 */

/*
 * The next two structures are my recreations of the data structures
 * found in the dual ported RAM buffers on the Stargate board.
 */

typedef struct {
    unsigned int global_command_word;
    unsigned int global_status_word;
    unsigned int global_service_request;
    unsigned int buffer_space_remaining;
    unsigned int board_type;
    unsigned int acl_control_program_version;
    unsigned int number_of_channels;
    unsigned int ccb_offset;
    unsigned int ccb_size;
    unsigned int global_command_word_2;
    unsigned int global_status_word_2;
    unsigned int comm_error_service_request;
    unsigned int input_buffer_service_request;
    unsigned int output_buffer_service_request;
    unsigned int modem_status_service_request;
    unsigned int channel_command_service_request;
} GLOBAL_CONTROL_BLOCK;

typedef struct {
    unsigned int baud_rate;
    unsigned int data_format;
    unsigned int line_protocol;
    unsigned int input_buffer_size;
    unsigned int output_buffer_size;
    unsigned int input_buffer_trigger_rate;
    unsigned int output_buffer_low_water_mark;
    unsigned int input_xon_xoff_characters;
    unsigned int input_buffer_high_water_mark;
    unsigned int input_buffer_low_water_mark;
    unsigned int channel_command;
    unsigned int channel_status;
    unsigned int input_buffer_start;
    unsigned int input_buffer_end;
    unsigned int output_buffer_start;
    unsigned int output_buffer_end;
    unsigned int next_character_to_input;
    unsigned int next_character_from_input;
    unsigned int next_character_to_output;
    unsigned int next_character_from_output;
    unsigned int communication_error_status;
    unsigned int bad_character_pointer;
    unsigned int modem_control_word;
    unsigned int modem_status_word;
    unsigned int blocking_status;
    unsigned int character_received_flag;
    unsigned int output_xon_xoff_characters;
    unsigned int channel_status_2;
} CHANNEL_CONTROL_BLOCK;

typedef struct smart_stargate_port {
    CHANNEL_CONTROL_BLOCK volatile far * ccb;
    unsigned char volatile far * buffer;
    struct smart_stargate_port *next_port;
    int ram_latch;
    int ram_enable;
    int ram_disable;
    int port_number;
    int board_number;
    int line_status;
} STARGATE_PORT;

typedef struct smart_stargate_board {
    GLOBAL_CONTROL_BLOCK volatile far * gcb;
    unsigned int latch;
    STARGATE_PORT *first_port;
    int first_port_number;
    int number_of_ports;
    enum { ACL_UNKNOWN = 0, ACLII, ACL16 } board_type;
} STARGATE_BOARD;

#define MAX_BOARDS 4
int GF_CONV _DumpPortStatusSmartStarGate( PORT *port, PORT_DUMPER printer );
int GF_CONV _SendCCBCommand( CHANNEL_CONTROL_BLOCK volatile far * ccb, int cmd );

extern STARGATE_BOARD stargate_boards[ MAX_BOARDS ];

#endif    /* #ifndef __STAR_DOT_H  */


