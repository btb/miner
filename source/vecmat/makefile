#
# $Source: f:/miner/source/vecmat/rcs/makefile $
# $Revision: 1.2 $
# $Author: matt $
# $Date: 1993/09/24 21:17:56 $
#
# Makefile for vector/matrix library
#

# What to install
INSTALL_TARGS = vecmat.lib vecmat.h vecmat.inc

# What libs to build
LIBS = vecmat

# What sources in the lib
vecmat_SRCS = vecmat.asm

# What test programs to make
TEST_PROGS = vectest 

# What source files and libs for the test programs
vectest_SRCS = vectest.c
vectest_LIBS = vecmat.lib io.lib fix.lib

#rules and targets common to all Miner makefiles
include $(MINER)/init/makefile.def

$(OBJDIR)/vecmat.obj: vecmat.asm fix.inc psmacros.inc types.inc vecmat.inc
