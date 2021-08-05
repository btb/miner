#
# $Source: f:/miner/source/iff/rcs/makefile $
# $Revision: 1.5 $
# $Author: john $
# $Date: 1994/02/15 12:51:20 $
#
# Makefile for IFF library
#

# What to install
INSTALL_TARGS = iff.lib iff.h

# What to clean
CLEAN_TARGS = *.obj

# What libs to build
LIBS = iff

# What sources in the iff lib
iff_SRCS = iff.c

# What test programs to make
TEST_PROGS = ifftest ifftestv

# What source files and libs for the test programs
ifftest_SRCS = ifftest.c
ifftest_LIBS = iff.lib gr.lib mem.lib bm.lib misc.lib cflib.lib cfile.lib

ifftestv_SRCS = ifftestv.c
ifftestv_LIBS = iff.lib vesa.lib cflib.lib cfile.lib

#rules and targets common to all Miner makefiles
include $(MINER)/init/makefile.def
