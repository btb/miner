#
# Makefile for vga functions
#

# What to install, and where to install it
INSTALL_TARGS = vga.lib

# What libs to make
LIBS = vga

# What source files for the lib
vga_SRCS = vga.c palette.c vesa.asm modex.asm

#rules and targets common to all Miner makefiles
include $(MINER)/init/makefile.def

$(OBJDIR)/modex.obj: modex.asm psmacros.inc tweak.inc vgaregs.inc
$(OBJDIR)/palette.obj: palette.c cfile.h error.h fix.h gr.h grdef.h key.h mem.h mono.h types.h
$(OBJDIR)/vesa.obj: vesa.asm fix.inc gr.inc psmacros.inc types.inc vgaregs.inc
