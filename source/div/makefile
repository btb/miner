#
# $Source: f:/miner/source/div/rcs/makefile $
# $Revision: 1.3 $
# $Author: matt $
# $Date: 1994/11/21 11:34:49 $
#
# Makefile for bios functions
#

# What to install, and where to install it
INSTALL_TARGS = div0.lib div0.h div0.inc

# What to clean
CLEAN_TARGS = *.obj

# What libs to make
LIBS = div0

# What test programs to make
TEST_PROGS = testd

# What source files for the lib
div0_SRCS =  div0.asm

# What source files and libs for the test programs
testd_SRCS = testd.c testda.asm
testd_LIBS = div0.lib

#rules and targets common to all Miner makefiles
include $(MINER)/init/makefile.def
