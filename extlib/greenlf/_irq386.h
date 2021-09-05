#ifndef _IRQ32_DOT_H
#define _IRQ32_DOT_H

/*
 * _IRQ386.H          5.20A  June 8, 1995
 *
 * The Greenleaf Comm Library
 *
 * Copyright (C) 1984-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 *  This file contains all the structures and constants used by
 *  the 32 bit IRQ Manager internal functions.  End users should never
 *  have to include this file in any of their source modules.
 *
 * MODIFICATIONS
 *
 *  December 1, 1994   5.10A :  Initial release.
 *
 */

#define MAXIMUM_HANDLERS 10

#pragma pack( 1 )

typedef struct _tag_irqdata {
    GF_FARPTR32 old_handler;
    GF_FARPTR16 old_real_handler;
    GF_FARPTR32 handler;
    GF_FARPTR16 real_handler;
    GF_FARPTR32 handler_data;
    GF_FARPTR16 real_handler_data;
    void ( GF_CONV *tear_down_function )( GF_FARPTR32 data );
    int interrupt_number;
    int saved_8259_bit;
    int primary_8259;
    int secondary_8259;
    int mask_8259;
    int int_count;
    int real_int_count;
} IRQDATA;

#pragma pack()

#ifdef __cplusplus
extern "C" {
#endif

int GF_CONV HookInterrupt( int interrupt_number,
                           void ( GF_CDECL *handler )( GF_FARPTR32 data ),
                           GF_FARPTR16 real_handler,
                           GF_FARPTR32 handler_data,
                           void ( GF_CONV *tear_down_function ) ( GF_FARPTR32 data ),
                           int primary_8259,
                           int secondary_8259,
                           int mask_8259 );
int GF_CONV UnHookInterrupt( int interrupt_number );
GF_FARPTR32 GF_CONV _GetInterruptData( int interrupt_number );
int GF_CONV RelocateIsrData( void );

#ifdef __cplusplus
}
#endif

/*
 * These two extern definitions are really important.  When
 * the 32 bit IRQ manager is initialized, it relocates the real portion
 * of the IRQ manager, plus the table of IRQDATA blocks down to
 * a block of real memory.  Thse two pointers let everyone else
 * know where that memory block is.
 */

extern GF_FARPTR16 RealBlockPtr16;
extern GF_FARPTR32 RealBlockPtr32;
/*
 * Anything that is stored in the reloacted real section of memory
 * can't be addressed directly.  Instead, we calculate an offset
 * into the real mode segment by subtracting _SegmentStartRR16.  It
 * is the first address in the real segment.  The next value defined
 * here marks the end of the relocated real segment.  We only need it
 * so we can figure out how much memory to relocate.
 */

extern char _SegmentStartRR16;
extern char _SegmentEndRR16;

/*
 * This is a dummy stub real mode interrupt that I use
 * to handle Ctrl-Break and Ctrl-C in real mode under PowerPack.
 *
 */

void GF_CDECL _RealIret( GF_FARPTR16 int_flag );
void GF_CDECL kbd_int_handler( GF_FARPTR32 data );


#endif /* #ifndef _IRQ32_DOT_H */

