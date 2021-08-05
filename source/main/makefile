#
# Makefile for DESCENT execuable
#

INI_FILE = inferno.ini

# Load this person's personal settings
include $(INI_FILE)

# What to clean
CLEAN_TARGS = *.obj

# What programs to make
ifdef SHAREWARE
PROGS = dcntshr
else
PROGS = descentr
endif

# Files to link for Descent
descent_SRCS = inferno.c game.c gauges.c mglobal.c \
			 scores.c object.c laser.c physics.c bm.c \
 			 menu.c gamesave.c switch.c effects.c texmerge.c polyobj.c \
			 gamemine.c fireball.c ai.c aipath.c hostage.c \
			 powerup.c fuelcen.c digi.c render.c hash.c piggy.c args.c \
			 gameseg.c wall.c collide.c lighting.c \
			 robot.c morph.c vclip.c weapon.c fvi.c newdemo.c titles.c \
			 vfx.c gameseq.c controls.c automap.c text.c \
			 network.c newmenu.c netmisc.c victor.c\
			 gamefont.c joydefs.c hud.c playsave.c \
			 endlevel.c terrain.c kconfig.c modem.c  \
			 multi.c cntrlcen.c credits.c config.c soscodec.c kmatrix.c	\
			 paging.c mission.c iglasses.c songs.c bmread.c state.c multibot.c nocomlib.c slew.c dumpmine.c 
#demo.c garage.c radar.c coindev.c serial.c vfxread.c victor.c

descent_LIBS =	3d.lib gr.lib fix.lib io.lib iff.lib vecmat.lib \
        	 	cfile.lib \
        	 	mem.lib \
				div0.lib misc.lib texmap.lib
#		ui.lib
#		editor.lib
#		sosdigi.lib #sosmidi.lib
		#iglasses.lib gclfr32.lib loadpats.lib
		#lzw.lib sosdwxcr.lib sosmwxcr.lib 


# Link flags for Descent
descent_LFLAGS = option map,verbose,stack=50k

# Force include of settings for all files
GLOBAL_INCFILES += settings.h

# DescentR is really Descent
descentr_SRCS   = $(descent_SRCS)
descentr_LIBS   = $(descent_LIBS)
descentr_DIRS   = $(descent_DIRS)
descentr_LFLAGS = $(descent_LFLAGS)
descentr_DATA   = $(descent_DATA)





#rules and targets common to all Miner makefiles
include $(MINER)/init/makefile.def

# descentr.EXE: 	$(descent_OBJS)
# 	wcl386 /fe=descentr.exe /l=dos4g /k50000 $(descent_OBJS) $(descent_LIBS)
