#
# $Source: f:/miner/source/3d/rcs/makefile $
# $Revision: 1.9 $
# $Author: matt $
# $Date: 1994/03/15 21:22:47 $
#
# Makefile for 3d library
#

# What to install
INSTALL_TARGS = 3d.lib 3d.h 3d.inc

# What libs to build
LIBS = 3d

# What sources in the lib
3d_SRCS = globvars.asm setup.asm matrix.asm points.asm draw.asm clipper.asm \
	horizon.asm instance.asm rod.asm interp.asm

# What test programs to make
TEST_PROGS = 3dtest

# What source files and libs for the test programs
3dtest_SRCS = 3dtest.c segment.c trakball.c
3dtest_LIBS = 3d.lib vecmat.lib gr.lib io.lib fix.lib div0.lib texmap.lib misc.lib bm.lib

#rules and targets common to all Miner makefiles
include $(MINER)/init/makefile.def
