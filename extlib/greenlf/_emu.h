#ifndef __EMU_H
#define __EMU_H

#include "emulator.h"

void GF_CONV _InitializeEmulator( EMULATOR *e );
int GF_CONV _DefaultInputScanner( EMULATOR *e, int c );
void GF_CDECL _EmulatorDebugMessage( EMULATOR *e, char *fmt, ... );

#endif /* #ifndef __EMU_H */
