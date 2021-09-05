#ifndef __KBD_DOT_H
#define __KBD_DOT_H

/*
 * _KBD.H               5.20A  June 8, 1995
 *
 * NOTES
 *
 * This private header file has the prototypes for the two assembly
 * language functions found in KBD.ASM.  This file should only be
 * used by routines found in KDBSUBS.C.
 *
 *  The Greenleaf Comm Library
 *
 *  Copyright (C) 1991-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 * This private header file has the prototypes for the two assembly
 * language functions found in KBD.ASM.  This file should only be
 * used by routines found in KDBSUBS.C.
 *
 * MODIFICATIONS
 *
 * December 12, 1992  4.00A : Initial release
 */

unsigned int GF_CDECL gf_kbd_status( int command );

#endif   /* #ifndef __KBD_DOT_H */

