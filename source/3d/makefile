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

clipper.obj: clipper.asm 3d.inc fix.inc gr.inc psmacros.inc types.inc vecmat.inc
draw.obj: draw.asm 3d.inc fix.inc gr.inc psmacros.inc types.inc vecmat.inc
globvars.obj: globvars.asm 3d.inc fix.inc psmacros.inc types.inc vecmat.inc
horizon.obj: horizon.asm 3d.inc fix.inc gr.inc psmacros.inc types.inc vecmat.inc
instance.obj: instance.asm 3d.inc fix.inc psmacros.inc types.inc vecmat.inc
interp.obj: interp.asm 3d.inc fix.inc gr.inc psmacros.inc types.inc vecmat.inc
matrix.obj: matrix.asm 3d.inc fix.inc gr.inc psmacros.inc types.inc vecmat.inc
points.obj: points.asm 3d.inc fix.inc gr.inc psmacros.inc types.inc vecmat.inc
rod.obj: rod.asm 3d.inc fix.inc gr.inc psmacros.inc types.inc vecmat.inc
setup.obj: setup.asm 3d.inc div0.inc fix.inc gr.inc psmacros.inc types.inc vecmat.inc
