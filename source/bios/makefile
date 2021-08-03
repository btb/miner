#
# $Source: f:/miner/source/bios/rcs/makefile $
# $Revision: 1.18 $
# $Author: john $
# $Date: 1995/03/23 18:27:04 $
#
# Makefile for bios functions
#

LIBDIR = ..\main
#

CCFLAGS = /dNETWORK /dRELEASE /dNDEBUG
CCFLAGS = $(CCFLAGS) /I..\misc /I..\includes /I..\fix

# What to install, and where to install it
INSTALL_TARGS = io.lib joy.h key.h mono.h mouse.h timer.h dpmi.h ipx.h #swift.h

# What to clean
CLEAN_TARGS = $(OBJDIR)\*.obj

# What libs to make
LIBS = io

# What test programs to make
TEST_PROGS = demo
# testj testk testm testms

# What object files for the lib
io_OBJS = key.obj joy.obj mouse.obj timer.obj mono.obj joyc.obj dpmi.obj ipx.obj

# What object files and libs for the test programs
demo_SRCS = demo.c
demo_LIBS = io.lib 

#rules and targets common to all Miner makefiles
include $(INIT)\makefile.def

# io.lib: $(IO_OBJS)
# 	wlib io.lib $(IO_OBJS)
# 	copy *.lib $(LIBDIR)

cdrom.obj: cdrom.c

demo.obj: demo.c
dpmi.obj: dpmi.c
ipx.obj: ipx.c
joyc.obj: joyc.c
joy.obj: joy.asm
key.obj: key.c
mono.obj: mono.c
mouse.obj: mouse.c
testj.obj: testj.c
testk.obj: testk.c
testm.obj: testm.c
testmem.obj: testmem.c
testms.obj: testms.c
testt.obj: testt.c
timer.obj: timer.asm
