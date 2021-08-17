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

$(OBJDIR)/bitblt.obj: bitblt.c fix.h gr.h grdef.h mem.h mono.h rle.h types.h
$(OBJDIR)/bitmap.obj: bitmap.c dpmi.h fix.h gr.h grdef.h mem.h types.h
$(OBJDIR)/box.obj: box.c fix.h gr.h grdef.h mem.h types.h
$(OBJDIR)/canvas.obj: canvas.c fix.h gr.h grdef.h mem.h types.h
$(OBJDIR)/circle.obj: circle.c fix.h gr.h grdef.h mem.h types.h
$(OBJDIR)/disc.obj: disc.c fix.h gr.h grdef.h mem.h types.h
$(OBJDIR)/font.obj: font.c cfile.h error.h fix.h gr.h grdef.h mem.h mono.h types.h
$(OBJDIR)/gpixel.obj: gpixel.c fix.h gr.h grdef.h mem.h types.h
$(OBJDIR)/gr.obj: gr.c dpmi.h error.h fix.h gr.h grdef.h mem.h mono.h palette.h types.h
$(OBJDIR)/ibitblt.obj: ibitblt.c error.h fix.h gr.h ibitblt.h mem.h types.h
$(OBJDIR)/lbitblt.obj: lbitblt.asm fix.inc gr.inc psmacros.inc types.inc
$(OBJDIR)/line.obj: line.c clip.h fix.h gr.h grdef.h mem.h types.h
$(OBJDIR)/linear.obj: linear.asm psmacros.inc vgaregs.inc
$(OBJDIR)/modex.obj: modex.asm psmacros.inc tweak.inc vgaregs.inc
$(OBJDIR)/palette.obj: palette.c cfile.h error.h fix.h gr.h grdef.h key.h mem.h mono.h types.h
$(OBJDIR)/pcx.obj: pcx.c cfile.h fix.h gr.h mem.h pcx.h types.h
$(OBJDIR)/pixel.obj: pixel.c fix.h gr.h grdef.h mem.h types.h
$(OBJDIR)/poly.obj: poly.c fix.h gr.h grdef.h mem.h types.h
$(OBJDIR)/rect.obj: rect.c fix.h gr.h grdef.h mem.h types.h
$(OBJDIR)/rle.obj: rle.c dpmi.h error.h fix.h gr.h grdef.h key.h mem.h mono.h types.h
$(OBJDIR)/scale.obj: scale.c error.h fix.h gr.h mono.h rle.h types.h
$(OBJDIR)/scalea.obj: scalea.asm psmacros.inc types.inc
$(OBJDIR)/scanline.obj: scanline.c fix.h gr.h grdef.h mem.h types.h
$(OBJDIR)/vesa.obj: vesa.asm fix.inc gr.inc psmacros.inc types.inc vgaregs.inc
