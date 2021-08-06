#
# $Source: f:/miner/source/mem/rcs/makefile $
# $Revision: 1.1 $
# $Author: john $
# $Date: 1993/11/02 17:45:38 $
#
# Makefile for memory debugging
#

# What to install, and where to install it
INSTALL_TARGS = mem.lib mem.h

# What libs to make
LIBS = mem

mem_SRCS = mem.c

#rules and targets common to all Miner makefiles
include $(MINER)/init/makefile.def

mem.obj: mem.c error.h mono.h
