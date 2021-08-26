#
# Makefile for cfile library
#

# What to install
INSTALL_TARGS = cfile.lib cfile.h nocfile.h

# What libs to make
LIBS = cfile

# What test programs to make
TEST_PROGS = t

# What source files for the lib
cfile_SRCS = cfile.c

# What source files and libs for the test programs
t_SRCS = t.c

#rules and targets common to all Miner makefiles
include $(MINER)/init/makefile.def

$(OBJDIR)/cfile.obj: cfile.c cfile.h types.h
