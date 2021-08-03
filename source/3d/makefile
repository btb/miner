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

# What object files and libs for the test programs
3dtest_SRCS = 3dtest.c segment.c trakball.c
3dtest_LIBS = 3d.lib vecmat.lib gr.lib io.lib fix.lib div0.lib texmap.lib misc.lib bm.lib

#rules and targets common to all Miner makefiles
include $(INIT)\makefile.def

# 3d.lib: $(3D_OBJS)
# 	wlib 3d.lib $(3D_OBJS)
# 	copy *.lib $(LIBDIR)

3dtest.obj: 3dtest.c

clipper.obj: clipper.asm
draw.obj: draw.asm
globvars.obj: globvars.asm
horizon.obj: horizon.asm
instance.obj: instance.asm 

interp.obj: interp.asm
matrix.obj: matrix.asm

objects.obj: objects.asm

out.obj: out.asm

points.obj: points.asm

rod.obj: rod.asm

segment.obj: segment.asm

setup.obj: setup.asm

#trakball.obj: trackball.asm

upvecs.obj: upvecs.asm

upvecs2.obj: fix.h types.h vecmat.h

