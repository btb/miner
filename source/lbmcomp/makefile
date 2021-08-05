#
# Master makefile for Miner source
#
# Makes all the executable by visiting subdirs and making there
#

CLEAN_TARGS = *.obj

PROGS = lbmcomp

LBMCOMP_SRCS = lbmcomp.c 

LBMCOMP_LIBS = gr.lib misc.lib mem.lib iff.lib readfile.lib ui.lib io.lib func.lib cflib.lib cfile.lib 

LBMCOMP_LFLAGS = option stack=150k

#rules and targets common to all Miner makefiles
include $(MINER)/init/makefile.def
