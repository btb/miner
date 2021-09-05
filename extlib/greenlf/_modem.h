#ifndef _MODEM_DOT_H
#define _MODEM_DOT_H

/*
 * _MODEM.H           5.20A  June 8, 1995
 *
 * The Greenleaf Comm Library
 *
 * Copyright (C) 1984-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 *  This file contains the structure and prototype definitions used
 *  internally by all the modem support functions.  It does not need
 *  to ever be included by any end user source modules.
 *
 * MODIFICATIONS
 *
 * December 12, 1992  4.00A : Initial release
 *
 */


#include "modem.h"

extern unsigned int _hm_abort_key;
extern int ( GF_CONV * _AbortModemFunctionPtr )( PORT *port );

#endif /* #ifndef _MODEM_DOT_H */

