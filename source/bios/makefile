#
# $Source: f:/miner/source/bios/rcs/makefile $
# $Revision: 1.18 $
# $Author: john $
# $Date: 1995/03/23 18:27:04 $
#
# Makefile for bios functions
#

LIBDIR = ../main
#

CCFLAGS = /dNETWORK /dRELEASE /dNDEBUG
CCFLAGS = $(CCFLAGS) /I../misc /I../includes /I../fix

# What to install, and where to install it
INSTALL_TARGS = io.lib joy.h key.h mono.h mouse.h timer.h dpmi.h ipx.h #swift.h

# What to clean
CLEAN_TARGS = *.obj

# What libs to make
LIBS = io

# What test programs to make
TEST_PROGS = demo
# testj testk testm testms

# What source files for the lib
io_SRCS = key.c joy.asm mouse.c timer.asm mono.c joyc.c dpmi.c ipx.c

# What source files and libs for the test programs
demo_SRCS = demo.c
demo_LIBS = io.lib 

#rules and targets common to all Miner makefiles
include $(MINER)/init/makefile.def
