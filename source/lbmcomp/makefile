#
# Makefile for lbmcomp
#

# What programs to make
PROGS = lbmcomp

# What source files and libs for the programs
lbmcomp_SRCS = lbmcomp.c 
lbmcomp_LIBS = gr.lib misc.lib mem.lib iff.lib readfile.lib ui.lib io.lib func.lib cflib.lib cfile.lib 
lbmcomp_LFLAGS = option stack=150k

#rules and targets common to all Miner makefiles
include $(MINER)/init/makefile.def
