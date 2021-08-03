#
# $Source: f:/miner/source/fix/rcs/makefile $
# $Revision: 1.5 $
# $Author: matt $
# $Date: 1994/11/27 23:21:18 $
#
# Makefile for fixed-point library
#

# What to install, and where to install it
INSTALL_TARGS = fix.lib fix.h fix.inc

# What to clean
CLEAN_TARGS = $(OBJDIR)\*.obj

# What libs to make
LIBS = fix

# What test programs to make
TEST_PROGS = fixtest

# What object files for the lib
fix_OBJS = fix.obj

# What object files and libs for the test programs
fixtest_SRCS = fixtest.c
fixtest_LIBS = fix.lib io.lib

#rules and targets common to all Miner makefiles
include $(INIT)\makefile.def

# fix.lib: $(FIX_OBJS)
# 	wlib fix.lib $(FIX_OBJS)
# 	copy *.lib $(LIBDIR)

asingen.obj: math.h stdio.h

fix.obj: fix.inc fix.asm

fixtest.obj: conio.h fix.h graph.h stdio.h stdlib.h types.h

singen.obj: math.h

test.obj: psmacros.inc
