#
# $Source: f:/miner/source/includes/rcs/makefile $
# $Revision: 1.1 $
# $Author: matt $
# $Date: 1993/11/04 10:24:14 $
#
# Makefile for macro and header files
#

# What to install
INSTALL_TARGS = types.h types.inc psmacros.inc

# What to clean
CLEAN_TARGS = *.obj

# What test programs to make
TEST_PROGS = test

# What source files and libs for the test programs
test_SRCS = test.c mactest.c
test_LIBS = io.lib

#rules and targets common to all Miner makefiles
include $(MINER)/init/makefile.def
