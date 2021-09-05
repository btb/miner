#ifndef _IRQMAN_DOT_H
#define _IRQMAN_DOT_H

/*
 * _IRQ88.H          5.20A  June 8, 1995
 *
 * The Greenleaf Comm Library
 *
 * Copyright (C) 1984-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 *  This file contains all the structures and constants used by
 *  the IRQ Manager internal functions.  End users should never
 *  have to include this file in any of their source modules.
 *
 * MODIFICATIONS
 *
 *  December 12, 1992  4.00A : Initial release
 *  December 1, 1994   5.10A : All of the DOS Extender stuff has been
 *                             yanked from here.  The extended versions
 *                             of the IRQ manager haver their own header
 *                             files now.
 */

#define MAXIMUM_HANDLERS 10

/*
 *  Note that real far pointers are saved as unsigned longs.  This
 *  prevents protected mode code from accidentally choking if and
 *  when it treats a real mode address as a pointer.
 *
 *  All of the 16 bit DOS Extender remnants here could get trashed.
 *  The only problem right now is that we need to match the structure
 *  up exactly with the structure used in PowerComm.  So, to avoid
 *  problems, all this stuff is being left alone right now.
 */

typedef struct _tag_irqdata {
    void ( GF_FAR *old_handler )( void );
    unsigned long old_real_handler;
    void ( GF_CDECL GF_FAR *handler )( void GF_FAR *data );
    unsigned long real_handler;

#ifndef VGFD
    void GF_FAR *data;
#else /* ifndef VGFD */
    void GF_FAR *data_PM;
    void GF_FAR *data_V86;
#endif

    unsigned long real_data;
    void ( GF_CONV *tear_down_function )( void GF_FAR *data );
#ifndef _LCODE
    int dummy_place_holder; /* I keep this struc constant size for ISR ease */
#endif
    int interrupt_number;
    int saved_8259_bit;
    int primary_8259;
    int secondary_8259;
    int mask_8259;
    int int_count;
    int real_int_count;
#ifdef VGFD
    unsigned task_handle_irq; /* VGFD task handle */
    int vm_id_irq;            /* VGFD VM id */
#endif
} IRQDATA;

#ifdef __cplusplus
extern "C" {
#endif

int GF_CONV HookInterrupt( int interrupt_number,
#ifndef VGFD
                           void ( GF_CDECL GF_FAR *handler )( void GF_FAR *data ),
#else
                           long handler,
#endif
                           void ( GF_CDECL GF_FAR *real_handler )( void GF_FAR *data ),
                           void GF_FAR *data,
                           void ( GF_CONV *tear_down_function ) ( void GF_FAR *data ),
                           int primary_8259,
                           int secondary_8259,
                           int mask_8259 );

int GF_CONV UnHookInterrupt( int interrupt_number );
IRQDATA GF_FAR * GF_CONV _GetInterruptData( int interrupt_number );

#if !defined( VGFD )
extern IRQDATA GF_FAR _irqtable[ MAXIMUM_HANDLERS ];
#else
extern IRQDATA GF_FAR *_irqtable;
#endif


extern void GF_FAR *_dispatcher_stubs[ MAXIMUM_HANDLERS ] ;

#ifdef __cplusplus
}
#endif

#endif /* #ifndef _IRQMAN_DOT_H */

