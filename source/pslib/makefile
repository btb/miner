#
# $Source: f:/miner/source/pslib/rcs/makefile $
# $Revision: 1.19 $
# $Author: john $
# $Date: 1994/08/05 17:25:56 $
#
# Makefile for compress library
#

# What to install, and where to install it
INSTALL_TARGS = cflib.lib cflib.h pslib.exe

# What libs to make
LIBS = cflib 

# What source files for the lib
cflib_SRCS = lzw.c bitio.c library.c 

# What programs to make
PROGS = pslib

# What source files and libs for the programs
pslib_SRCS = pslib.c
pslib_LIBS = cflib.lib misc.lib mem.lib io.lib

#rules and targets common to all Miner makefiles
include $(MINER)/init/makefile.def

$(OBJDIR)/bitio.obj: bitio.c cflib.h library.h mem.h types.h
$(OBJDIR)/library.obj: library.c cflib.h error.h library.h mem.h types.h
$(OBJDIR)/lzw.obj: lzw.c cflib.h library.h mem.h types.h
$(OBJDIR)/pslib.obj: pslib.c cflib.h library.h mem.h parsarg.h types.h
