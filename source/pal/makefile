#
# $Source: f:/miner/source/bios/rcs/makefile $
# $Revision: 1.3 $
# $Author: matt $
# $Date: 1993/07/21 20:12:19 $
#
# Makefile for pal functions
#

# What to install, and where to install it
INSTALL_TARGS =

# What libs to make
LIBS =

# What test programs to make
TEST_PROGS = testp

testp_DIRS = ../main/editor

# What source files and libs for the test programs
testp_SRCS = testp.c iff.c iff15bpp.c func.c
testp_LIBS = io.lib gr.lib ui.lib misc.lib mem.lib iff.lib cfile.lib vga.lib #readfile.lib #bm.lib

#rules and targets common to all Miner makefiles
include $(MINER)/init/makefile.def
