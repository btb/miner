#
# $Source: f:/miner/source/texmap/rcs/makefile $
# $Revision: 1.23 $
# $Author: john $
# $Date: 1995/02/20 18:23:00 $
#
# Makefile for hack3df testbed
#

#Uncomment the following 3 lines if you want to build with only C code.
#NASM = 1
#GLOBAL_CFLAGS+=/dNASM
#GLOBAL_AFLAGS+=/DNASM

# What to install
INSTALL_TARGS = texmap.lib texmap.h

# What libs to build
LIBS = texmap

# What sources in the texmap lib
#texmap_SRCS = ntmap.c tmapsky.c tmapv.c tmapflat.c tmap_per.asm tmap_p2.asm tmap_lin.asm tmap_ll.asm tmap_kl.asm\
#		tmap_ld.asm tmap_flt.asm tmap_sky.asm tmap_skv.asm tmap_fl1.asm tmapz.c tmap_z.asm tmapfade.asm tmap_mul.asm

texmap_SRCS = 	ntmap.c tmapflat.c

ifndef NASM
texmap_SRCS +=	tmap_per.asm tmap_lin.asm tmap_ll.asm tmap_flt.asm tmapfade.asm tmap_fl1.asm
else
texmap_SRCS += scanline.c
endif

# What to clean
CLEAN_TARGS = *.obj

# What test programs to make
# TEST_PROGS = textest

# What source files and libs for the test programs
# textest_SRCS = textest.obj
# textest_LIBS = texmap.lib

#rules and targets common to all Miner makefiles
include $(MINER)/init/makefile.def
