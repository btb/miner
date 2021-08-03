#
# Master makefile for Miner source
#
# Makes all the executable by visiting subdirs and making there
#

CLEAN_TARGS = $(OBJDIR)\*.obj

INSTALL_TARGS = cfile.lib cfile.h nocfile.h

LIBS = cfile

cfile_OBJS = cfile.obj

#rules and targets common to all Miner makefiles
include $(INIT)\makefile.def

# cfile.lib: $(CFILE_OBJS)
# 	wlib cfile.lib $(CFILE_OBJS)
# 	copy *.lib $(LIBDIR)

cfile.obj: cfile.h cfile.c

test.obj: test.c
