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

# What libs to make
LIBS = ui

# What programs to make
TEST_PROGS = testgui

# What source files for the lib
ui_SRCS = ui.c mouse.c window.c uidraw.c button.c \
		  gadget.c listbox.c message.c popup.c scroll.c \
		  radio.c checkbox.c inputbox.c userbox.c menu.c \
		  harderr.c file.c keytrap.c icon.c keypress.c \
		  menubar.c keypad.c 

testgui_DIRS = ../main/editor

# What source files and libs for the test programs
testgui_SRCS = testg.c func.c
testgui_LIBS = io.lib gr.lib ui.lib misc.lib mem.lib iff.lib cflib.lib cfile.lib # readfile.lib func.lib
testgui_LFLAGS = option stack=50k

#rules and targets common to all Miner makefiles
include $(MINER)/init/makefile.def

$(OBJDIR)/button.obj: button.c fix.h gr.h key.h mem.h mono.h types.h ui.h
$(OBJDIR)/checkbox.obj: checkbox.c fix.h gr.h key.h mem.h types.h ui.h
$(OBJDIR)/file.obj: file.c fix.h gr.h key.h mem.h mono.h types.h ui.h
$(OBJDIR)/gadget.obj: gadget.c fix.h gr.h key.h mem.h types.h ui.h
$(OBJDIR)/harderr.obj: harderr.c
$(OBJDIR)/icon.obj: icon.c fix.h gr.h key.h mem.h types.h ui.h
$(OBJDIR)/inputbox.obj: inputbox.c fix.h gr.h key.h mem.h types.h ui.h
$(OBJDIR)/keypad.obj: keypad.c cflib.h error.h fix.h func.h gr.h key.h mem.h mono.h types.h ui.h
$(OBJDIR)/keypress.obj: keypress.c fix.h gr.h key.h types.h ui.h
$(OBJDIR)/keytrap.obj: keytrap.c fix.h gr.h key.h types.h ui.h
$(OBJDIR)/listbox.obj: listbox.c fix.h gr.h key.h types.h ui.h
$(OBJDIR)/menu.obj: menu.c fix.h gr.h mem.h types.h ui.h
$(OBJDIR)/menubar.obj: menubar.c error.h fix.h func.h gr.h key.h mem.h mono.h types.h ui.h
$(OBJDIR)/message.obj: message.c fix.h gr.h key.h types.h ui.h
$(OBJDIR)/mouse.obj: mouse.c fix.h gr.h mem.h mouse.h types.h ui.h
$(OBJDIR)/popup.obj: popup.c fix.h gr.h mouse.h types.h ui.h
$(OBJDIR)/radio.obj: radio.c fix.h gr.h key.h mono.h types.h ui.h
$(OBJDIR)/scroll.obj: scroll.c fix.h gr.h key.h types.h ui.h
$(OBJDIR)/ui.obj: ui.c fix.h gr.h key.h mono.h mouse.h types.h ui.h
$(OBJDIR)/uidraw.obj: uidraw.c fix.h gr.h types.h ui.h
$(OBJDIR)/userbox.obj: userbox.c fix.h gr.h key.h types.h ui.h
$(OBJDIR)/window.obj: window.c fix.h gr.h key.h mem.h mono.h mouse.h types.h ui.h
