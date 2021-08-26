#
# $Source: f:/miner/source/bios/rcs/makefile $
# $Revision: 1.18 $
# $Author: john $
# $Date: 1995/03/23 18:27:04 $
#
# Makefile for bios functions
#

# What to install, and where to install it
INSTALL_TARGS = io.lib joy.h key.h mono.h mouse.h timer.h dpmi.h ipx.h #swift.h

# What libs to make
LIBS = io

# What test programs to make
TEST_PROGS = demo testj testk testm testmem testms testt

# What source files for the lib
io_SRCS = key.c joy.asm mouse.c timer.asm mono.c joyc.c dpmi.c ipx.c

# What source files and libs for the test programs
demo_SRCS = demo.c
demo_LIBS = io.lib 

testj_SRCS = testj.c
testj_LIBS = io.lib

testk_SRCS = testk.c
testk_LIBS = io.lib

testm_SRCS = testm.c
testm_LIBS = io.lib

testmem_SRCS = testmem.c
testmem_LIBS = io.lib

testms_SRCS = testms.c
testms_LIBS = io.lib

testt_SRCS = testt.c
testt_LIBS = io.lib

#rules and targets common to all Miner makefiles
include $(MINER)/init/makefile.def

$(OBJDIR)/demo.obj: demo.c dpmi.h error.h fix.h ipx.h key.h mono.h timer.h types.h
$(OBJDIR)/dpmi.obj: dpmi.c dpmi.h error.h mono.h types.h
$(OBJDIR)/ipx.obj: ipx.c dpmi.h error.h fix.h ipx.h key.h timer.h types.h
$(OBJDIR)/joy.obj: joy.asm
$(OBJDIR)/joyc.obj: joyc.c dpmi.h fix.h joy.h mono.h types.h
$(OBJDIR)/key.obj: key.c dpmi.h error.h fix.h key.h timer.h types.h
$(OBJDIR)/mono.obj: mono.c fix.h key.h types.h
$(OBJDIR)/mouse.obj: mouse.c dpmi.h error.h fix.h mouse.h timer.h types.h
$(OBJDIR)/timer.obj: timer.asm psmacros.inc
