#
# $Source: f:/miner/source/2d/rcs/makefile $
# $Revision: 1.35 $
# $Author: john $
# $Date: 1995/01/29 17:08:57 $
#
# Makefile for bios functions
#

# What to install, and where to install it
INSTALL_TARGS = effect2d.h gr.h gr.lib grdef.h gr.inc palette.h ibitblt.h rle.h pcx.h

# What to clean
CLEAN_TARGS = *.obj

# What libs to make
LIBS = gr

# What test programs to make
#TEST_PROGS = testg testp vesatest
TEST_PROGS = testg

# What source files for the lib
gr_SRCS = linear.asm vesa.asm modex.asm canvas.c bitmap.c gr.c font.c \
	bitblt.c scanline.c pixel.c poly.c disc.c rect.c box.c  \
	gpixel.c palette.c line.c lbitblt.asm        \
	scale.c scalea.asm circle.c ibitblt.c rle.c pcx.c
#effects.c roller.c 

# What source files and libs for the test programs
testg_SRCS = testg.c tmapbits.c
testg_LIBS = io.lib gr.lib misc.lib mem.lib iff.lib  cfile.lib

#testp_OBJS = testp.obj
#testp_LIBS = io.lib gr.lib misc.lib mem.lib cflib.lib 

#vesatest_SRCS = vesatest.c
#vesatest_LIBS = io.lib gr.lib misc.lib mem.lib cflib.lib 

#rules and targets common to all Miner makefiles
include $(MINER)/init/makefile.def
