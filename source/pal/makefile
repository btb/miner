#
# $Source: f:/miner/source/bios/rcs/makefile $
# $Revision: 1.3 $
# $Author: matt $
# $Date: 1993/07/21 20:12:19 $
#
# Makefile for bios functions
#

LIBDIR = ../main
#

CCFLAGS = /dNETWORK /dRELEASE /dNDEBUG


# What to install, and where to install it
INSTALL_TARGS =

# What to clean
CLEAN_TARGS = *.obj

# What libs to make
LIBS =

# What test programs to make
TEST_PROGS = testp

# What source files and libs for the test programs
TESTP_SRCS = testp.c iff.c iff15bpp.c
TESTP_LIBS = io.lib gr.lib ui.lib misc.lib mem.lib bm.lib iff.lib readfile.lib

#rules and targets common to all Miner makefiles
include $(MINER)/init/makefile.def
