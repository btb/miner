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
#cf.obj

# What test programs to make
PROGS = pslib
TEST_PROGS = cftest cftest2

# What source files and libs for the test programs
pslib_SRCS = pslib.c
pslib_LIBS = cflib.lib misc.lib mem.lib io.lib
cftest_SRCS = cftest.c
cftest_LIBS = cflib.lib misc.lib mem.lib io.lib
cftest2_SRCS = cftest2.c
cftest2_LIBS = cflib.lib misc.lib mem.lib io.lib

#rules and targets common to all Miner makefiles
include $(MINER)/init/makefile.def

bitio.obj: bitio.c cflib.h library.h mem.h types.h
library.obj: library.c cflib.h error.h library.h mem.h types.h
lzw.obj: lzw.c cflib.h library.h mem.h types.h
pslib.obj: pslib.c cflib.h library.h mem.h parsarg.h types.h
