#
# $Source: f:/miner/source/misc/rcs/makefile $
# $Revision: 1.4 $
# $Author: matt $
# $Date: 1994/11/27 22:27:23 $
#
# Makefile for misc libaray
#

# What to install
INSTALL_TARGS = misc.lib parsarg.h error.h

# What libs to build
LIBS = misc

# What sources in the lib
misc_SRCS = parsarg.c error.c

# What test programs to make
TEST_PROGS = errtest parstest

# What source files and libs for the test programs
parstest_SRCS = parstest.c
parstest_LIBS = misc.lib

errtest_SRCS = errtest.c
errtest_LIBS = misc.lib

#rules and targets common to all Miner makefiles
include $(MINER)/init/makefile.def

$(OBJDIR)/error.obj: error.c error.h mono.h
$(OBJDIR)/parsarg.obj: parsarg.c parsarg.h
