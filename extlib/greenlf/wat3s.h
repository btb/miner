#ifndef _WAT3S_DOT_H
#define _WAT3S_DOT_H

/*
 * WAT3S.H      5.20A  June 8, 1995
 *
 * DESCRIPTION
 *
 * Watcom modifies its symbol naming conventions slightly if you
 * compile with the /3s option.  Our assembly language code
 * just flat out doesn't know how to modify its nameing convention.
 * Therefore, we have to work around the problem by specifying
 * hardcoded symbol names for all data found in ASM modules, or
 * data used in ASM modules.
 *
 * If you decide you want to build some Watcom libraries with the
 * /3s option, you better be sure you define GF_WATCOM_S so that you
 * get these symbol definitions sucked in.
 *
 *  Copyright (C) 1991-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * MODIFICATIONS
 *
 *  December 7, 1994   5.10A : Initial release.
 */

#pragma aux _SegmentStartPC32     "__SegmentStartPC32";
#pragma aux _SegmentEndPC32       "__SegmentEndPC32";
#pragma aux _SegmentStartPD32     "__SegmentStartPD32";
#pragma aux _SegmentEndPD32       "__SegmentEndPD32";
#pragma aux _VideoBasePD16        "__VideoBasePD16";
#pragma aux _VideoBasePD32        "__VideoBasePD32";
#pragma aux _SegmentStartRR16     "__SegmentStartRR16";
#pragma aux _RealStubOffsetsPD32  "__RealStubOffsetsPD32";
#pragma aux _ProtStubOffsetsPD32  "__ProtStubOffsetsPD32";
#pragma aux _SegmentEndRR16       "__SegmentEndRR16";
#pragma aux _IrqDataArrayRR16     "__IrqDataArrayRR16";
#pragma aux _IrqDataPD32          "__IrqDataPD32";
#pragma aux _DgroupSelectorPD32   "__DgroupSelectorPD32";
#pragma aux _DgroupSelectorPD32   "__DgroupSelectorPD32";
#pragma aux _kbd_i23_count        "__kbd_i23_count";
#pragma aux _SizeOfIrqDataPD32    "__SizeOfIrqDataPD32";
#pragma aux _SizeOfFastDataPD32   "__SizeOfFastDataPD32";

#endif /* #ifndef _WAT3S_DOT_H */
