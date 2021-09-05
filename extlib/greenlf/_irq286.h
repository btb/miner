#ifndef _IRQ16_DOT_H
#define _IRQ16_DOT_H

/*
 * _IRQ286.H          5.20A  June 8, 1995
 *
 * The Greenleaf Comm Library
 *
 * Copyright (C) 1984-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 *  This file contains all the structures and constants used by
 *  the 16 bit IRQ Manager internal functions.  End users should never
 *  have to include this file in any of their source modules.
 *
 * MODIFICATIONS
 *
 * December 1, 1994   5.10A :  Initial release.
 *
 */

#define MAXIMUM_HANDLERS 10

#pragma pack( 1 )

typedef struct _tag_irqdata {
    void far * old_prot_handler;
    GF_REALPTR16 old_real_handler;
    void far *prot_handler;
    GF_REALPTR16 real_handler;
    void far *prot_handler_data;
    GF_REALPTR16 real_handler_data;
    void ( GF_CONV *tear_down_function )( void far *data );
#ifndef _LCODE
    int dummy_place_holder; /* I keep this struc constant size for ISR ease */
#endif
    int interrupt_number;
    int saved_8259_bit;
    int primary_8259;
    int secondary_8259;
    int mask_8259;
    int prot_int_count;
    int real_int_count;
} IRQDATA;

#pragma pack()

#ifdef __cplusplus
extern "C" {
#endif

int GF_CONV HookInterrupt( int interrupt_number,
                           void ( GF_CDECL *prot_handler )( void far *data ),
                           GF_REALPTR16 real_handler,
                           void far *handler_data,
                           void ( GF_CONV *tear_down_function ) ( void far *data ),
                           int primary_8259,
                           int secondary_8259,
                           int mask_8259 );
int GF_CONV UnHookInterrupt( int interrupt_number );
void far * GF_CONV _GetInterruptData( int interrupt_number );
int GF_CONV RelocateIsrData( void );
void far * GF_CONV CalcRR16Address( void far *p );

#ifdef __cplusplus
}
#endif

/*
 * These first two extern declarations are used to find the start and end
 * of the real isr data area.  We need this when it is time to perform
 * the relocation.
 */

extern char far _SegmentStartRR;
extern char far _SegmentEndRR;

/*
 * These two extern definitions are really important.  When
 * the 16 bit IRQ manager is initialized, it relocates the real portion
 * of the IRQ manager, plus the table of IRQDATA blocks down to
 * a block of real memory.  Thse two pointers let everyone else
 * know where that memory block is.
 */

extern GF_REALPTR16 RealBlockPtrReal;
extern void far *RealBlockPtrProt;

void GF_CDECL far _RealIret( GF_REALPTR16 int_flag );

#endif /* #ifndef _IRQ16_DOT_H */

