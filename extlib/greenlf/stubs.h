#ifndef __STUBS_DOT_H
#define __STUBS_DOT_H

/*
 * STUBS.H              5.20A  June 8, 1995
 *
 *
 *  The Greenleaf Comm Library
 *
 *  Copyright (C) 1991-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 * When is a header file not a header file?  Here is an example.
 * This header file is used to stub out all of the DumpPortStatus
 * routines normally found in CommLib. By including this file in
 * a single module, and compiling just that one module, you can
 * avoid linking in all the baggage that accompanies the dump
 * routines.
 *
 * MODIFICATIONS
 *
 * December 12, 1992  4.00A : Initial release
 */

#include "gsci.h"

int GF_CONV _DumpPortStatusGreenleafFast( PORT *port, PORT_DUMPER printer )
{
    if ( port != 0 )
        printer( "" );
    return( ASSUCCESS );
}

int GF_CONV _DumpPortStatusFossil( PORT *port, PORT_DUMPER printer )
{
    if ( port != 0 )
        printer( "" );
    return( ASSUCCESS );
}

int GF_CONV _DumpPortStatusGreenleaf( PORT *port, PORT_DUMPER printer )
{
    if ( port != 0 )
        printer( "" );
    return( ASSUCCESS );
}

int GF_CONV _DumpPortStatusSmartDigiboard( PORT *port, PORT_DUMPER printer )
{
    if ( port != 0 )
        printer( "" );
    return( ASSUCCESS );
}


int GF_CONV _DumpPortStatusModemAssist( PORT *port, PORT_DUMPER printer )
{
    if ( port != 0 )
        printer( "" );
    return( ASSUCCESS );
}

int GF_CONV _DumpPortStatusBIOS( PORT *port, PORT_DUMPER printer )
{
    if ( port != 0 )
        printer( "" );
    return( ASSUCCESS );
}

int GF_CONV _DumpPortStatusSparkle( PORT *port, PORT_DUMPER printer )
{
    if ( port != 0 )
        printer( "" );
    return( ASSUCCESS );
}

int GF_CONV _DumpPortStatusSmartArnet( PORT *port, PORT_DUMPER printer )
{
    if ( port != 0 )
        printer( "" );
    return( ASSUCCESS );
}

int GF_CONV _DumpPortStatusSmartStarGate( PORT *port, PORT_DUMPER printer )
{
    if ( port != 0 )
        printer( "" );
    return( ASSUCCESS );
}

int GF_CONV _DumpPortStatusNasi( PORT *port, PORT_DUMPER printer )
{
    if ( port != 0 )
        printer( "" );
    return ASSUCCESS;
}


#endif    /* #ifndef __STUBS_DOT_H  */

