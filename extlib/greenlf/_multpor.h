#ifndef __MULTPORT_DOT_H
#define __MULTPORT_DOT_H

/*
 * _MULTPOR.H           5.20A  June 8, 1995
 *
 * The Greenleaf Comm Library
 *
 * Copyright (C) 1984-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 *  This file contains all the structure definitions and function
 *  prototypes used internally by all the Multiport board front end
 *  dispatcher routines.  You should never need to include this header
 *  file in an end user application.
 *
 * MODIFICATIONS
 *
 * December 12, 1992  4.00A : Initial release
 *
 */

#include "commlib.h"
#include "gsci.h"

struct digiboard_isr_data {
#ifndef  VGFD
    struct PORTINFO GF_FAR *first_port_info;
#else
    struct PORTINFO GF_FAR *first_port_info_PM;
    struct PORTINFO GF_FAR *first_port_info_V86;
    long reserved; /* for VGFD */
#endif
    int shared_status_port;
    int status_port_mask;
    int port_count;
    void *myself;
};

struct stargate_isr_data {
#ifndef  VGFD
    struct PORTINFO GF_FAR *first_port_info;
#else
    struct PORTINFO GF_FAR *first_port_info_PM;
    struct PORTINFO GF_FAR *first_port_info_V86;
    long reserved; /* for VGFD */
#endif
    int shared_status_port;
    int status_port_mask;
    int port_count;
    void *myself;
};

struct arnet_isr_data {
#ifndef  VGFD
    struct PORTINFO GF_FAR *first_port_info;
#else
    struct PORTINFO GF_FAR *first_port_info_PM;
    struct PORTINFO GF_FAR *first_port_info_V86;
    long reserved; /* for VGFD */
#endif
    int shared_status_port;
    int status_port_mask;
    int port_count;
    void *myself;
};

struct ast_isr_data {
#ifndef  VGFD
    struct PORTINFO GF_FAR *first_port_info;
#else
    struct PORTINFO GF_FAR *first_port_info_PM;
    struct PORTINFO GF_FAR *first_port_info_V86;
    long reserved; /* for VGFD */
#endif
    int shared_status_port;
    int irq_clear_port;
    int port_count;
    void *myself;
};

struct contec_isr_data {
#ifndef  VGFD
    struct PORTINFO GF_FAR *first_port_info;
#else
    struct PORTINFO GF_FAR *first_port_info_PM;
    struct PORTINFO GF_FAR *first_port_info_V86;
    long reserved; /* for VGFD */
#endif
    int shared_status_port;
    int port_count;
    void *myself;
};

void GF_CDECL GF_FAR _DigiIsaIsrDispatcher( void GF_FAR *port );
void GF_CDECL GF_FAR _DigiMcaIsrDispatcher( void GF_FAR *port );
void GF_CDECL GF_FAR _StargateIsrDispatcher( void GF_FAR *port );
void GF_CDECL GF_FAR _AstIsrDispatcher( void GF_FAR *port );
void GF_CDECL GF_FAR _ArnetIsrDispatcher( void GF_FAR *port );
void GF_CDECL GF_FAR _ContecIsrDispatcher( void GF_FAR *port );

void GF_CONV tear_down_stargate( struct stargate_isr_data GF_FAR *isr_data );

#endif /* #ifndef __MULTPORT_DOT_H */

