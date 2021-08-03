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

# What to clean
CLEAN_TARGS = $(OBJDIR)\*.obj

# What libs to make
LIBS = mem

mem_OBJS = mem.obj

#rules and targets common to all Miner makefiles
include $(INIT)\makefile.def

# mem.lib: $(MEM_OBJS)
# 	wlib mem.lib $(MEM_OBJS)
# 	copy *.lib $(LIBDIR)

mem.obj: mem.h mem.c
