#
# $Source: f:/miner/source/ui/rcs/makefile $
# $Revision: 1.8 $
# $Author: matt $
# $Date: 1994/11/27 14:53:50 $
#
# Makefile for user-interface functions
#

LIBDIR = ../main
#

CCFLAGS = /dNETWORK /dRELEASE /dNDEBUG


# What to install, and where to install it
INSTALL_TARGS = ui.lib ui.h func.h

# What to clean
CLEAN_TARGS = *.obj

# What libs to make
LIBS = ui

# What programs to make
TEST_PROGS = testg

# What source files for the lib
ui_OBJS = ui.c mouse.c window.c uidraw.c button.c \
		  gadget.c listbox.c message.c popup.c scroll.c \
		  radio.c checkbox.c inputbox.c userbox.c menu.c \
		  harderr.c file.c keytrap.c icon.c keypress.c \
		  menubar.c keypad.c 
#func.c #Couldn't find func.c - where are the functions??

# What source files and libs for the test programs
testg_SRCS = testg.c
testg_LIBS = io.lib gr.lib ui.lib misc.lib mem.lib readfile.lib iff.lib func.lib cflib.lib cfile.lib
testg_LFLAGS = option stack=50k

#rules and targets common to all Miner makefiles
include $(MINER)/init/makefile.def
