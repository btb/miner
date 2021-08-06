#
# $Source: f:/miner/source/ui/rcs/makefile $
# $Revision: 1.8 $
# $Author: matt $
# $Date: 1994/11/27 14:53:50 $
#
# Makefile for user-interface functions
#

# What to install, and where to install it
INSTALL_TARGS = ui.lib ui.h func.h

# What to clean
CLEAN_TARGS = *.obj

# What libs to make
LIBS = ui

# What programs to make
TEST_PROGS = testg

# What source files for the lib
ui_SRCS = ui.c mouse.c window.c uidraw.c button.c \
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

button.obj: button.c fix.h gr.h key.h mem.h mono.h types.h ui.h
checkbox.obj: checkbox.c fix.h gr.h key.h mem.h types.h ui.h
file.obj: file.c fix.h gr.h key.h mem.h mono.h types.h ui.h
gadget.obj: gadget.c fix.h gr.h key.h mem.h types.h ui.h
harderr.obj: harderr.c
icon.obj: icon.c fix.h gr.h key.h mem.h types.h ui.h
inputbox.obj: inputbox.c fix.h gr.h key.h mem.h types.h ui.h
keypad.obj: keypad.c cflib.h error.h fix.h func.h gr.h key.h mem.h mono.h types.h ui.h
keypress.obj: keypress.c fix.h gr.h key.h types.h ui.h
keytrap.obj: keytrap.c fix.h gr.h key.h types.h ui.h
listbox.obj: listbox.c fix.h gr.h key.h types.h ui.h
menu.obj: menu.c fix.h gr.h mem.h types.h ui.h
menubar.obj: menubar.c error.h fix.h func.h gr.h key.h mem.h mono.h types.h ui.h
message.obj: message.c fix.h gr.h key.h types.h ui.h
mouse.obj: mouse.c fix.h gr.h mem.h mouse.h types.h ui.h
popup.obj: popup.c fix.h gr.h mouse.h types.h ui.h
radio.obj: radio.c fix.h gr.h key.h mono.h types.h ui.h
scroll.obj: scroll.c fix.h gr.h key.h types.h ui.h
ui.obj: ui.c fix.h gr.h key.h mono.h mouse.h types.h ui.h
uidraw.obj: uidraw.c fix.h gr.h types.h ui.h
userbox.obj: userbox.c fix.h gr.h key.h types.h ui.h
window.obj: window.c fix.h gr.h key.h mem.h mono.h mouse.h types.h ui.h
