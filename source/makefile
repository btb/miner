#
# Master makefile for Miner source
#
# Makes all the executable by visiting subdirs and making there
#

SUBDIRS = 2d 3d bios cfile div fix hogfile iff includes lbmcomp main mem \
	misc pal pslib texmap ui vecmat xcolor
	# pcxview unused

# The only thing to make is the subdirs
SUBSYSTEMS = misc includes fix cfile 2d bios iff div mem vecmat 3d texmap \
	pslib ui
#sosdigi sosmidi

# What to make in the subdirs if nothing specified
SUBTARGETS = clean optimize no_mono no_debug install
#SUBTARGETS = update install

# When making clean here, delete libs
CLEAN_TARGS = lib/*.lib lib/*.h lib/*.inc

default: linstallh linstall
	$(MAKE) -C main

#all Miner makefiles should include this
include $(MINER)/init/makefile.def
