#
# Makefile for DESCENT execuable
#

# What programs to make
PROGS = findtext

# What source files and libs for the programs
findtext_SRCS = findtext.c

# Where to find libraries we didn't write
EXTLIB_DIR = $(MINER)/extlib
EXTLIBS = $(if $(USE_SOS),$(EXTLIB_DIR)/sos,)

# What programs to make
GAMES = $(if $(BUILD_EDITOR),editor,\
		  $(if $(SHAREWARE),dcntshr,\
		  $(if $(DEST_SAT),descent,\
		  descentr)))

# Files to link for Descent
descent_SRCS = inferno.c game.c gauges.c mglobal.c \
			 scores.c object.c laser.c physics.c bm.c \
 			 menu.c gamesave.c switch.c effects.c texmerge.c polyobj.c \
			 gamemine.c fireball.c ai.c aipath.c hostage.c \
			 powerup.c fuelcen.c render.c hash.c piggy.c args.c \
			 gameseg.c wall.c collide.c lighting.c \
			 robot.c morph.c vclip.c weapon.c fvi.c newdemo.c titles.c \
			 vfx.c gameseq.c controls.c automap.c text.c \
			 network.c newmenu.c netmisc.c victor.c\
			 gamefont.c joydefs.c hud.c playsave.c \
			 endlevel.c terrain.c kconfig.c modem.c  \
			 multi.c cntrlcen.c credits.c config.c soscodec.c kmatrix.c	\
			 paging.c mission.c iglasses.c songs.c bmread.c state.c multibot.c nocomlib.c slew.c dumpmine.c \
			 $(if $(USE_SOS),digi.c,nodigi.c)
#demo.c garage.c radar.c coindev.c serial.c vfxread.c victor.c

descent_LIBS =	3d.lib gr.lib fix.lib io.lib iff.lib vecmat.lib \
        	 	cfile.lib \
        	 	mem.lib \
				div0.lib misc.lib texmap.lib \
				$(if $(USE_SOS),sosdigi.lib sosmidi.lib,)
		#iglasses.lib gclfr32.lib loadpats.lib
		#lzw.lib sosdwxcr.lib sosmwxcr.lib 

descent_DIRS = editor

# Link flags for Descent
descent_LFLAGS = option map,verbose,stack=50k,nocaseexact

# DescentR is really Descent
descentr_SRCS   = $(descent_SRCS)
descentr_LIBS   = $(descent_LIBS)
descentr_DIRS   = $(descent_DIRS)
descentr_LFLAGS = $(descent_LFLAGS)
descentr_DATA   = $(descent_DATA)

dcntshr_SRCS   = $(descent_SRCS)
dcntshr_LIBS   = $(descent_LIBS)
dcntshr_DIRS   = $(descent_DIRS)
dcntshr_LFLAGS = $(descent_LFLAGS)
dcntshr_DATA   = $(descent_DATA)

# Files in the editor subdirectory
editor_SRCS = $(descent_SRCS) \
	med.c einit.c eglobal.c mine.c curves.c kcurve.c \
	khelp.c ksegsel.c kbuild.c kview.c kmine.c seguvs.c ksegsize.c \
	ksegmove.c ktmap.c kfuncs.c autosave.c group.c texture.c \
	fixseg.c eobject.c elight.c texpage.c objpage.c medmisc.c \
	medsel.c kgame.c info.c medwall.c eswitch.c medrobot.c meddraw.c \
	segment.c ehostage.c centers.c func.c

# These sources are always built optimized
editor_SRCS_OPT =

editor_LIBS = $(descent_LIBS) ui.lib #medlisp.lib 

editor_DIRS = $(descent_DIRS)
editor_LFLAGS = $(descent_LFLAGS)

# Editor data files to check out with source
editor_DATA = segmove.pad segsize.pad texture.pad object.pad curve.pad \
	      group.pad objmov.pad lighting.pad test.pad med.mnu #global.key


#rules and targets common to all Miner makefiles
include $(MINER)/init/makefile.def

# descentr.EXE: 	$(descent_OBJS)
# 	wcl386 /fe=descentr.exe /l=dos4g /k50000 $(descent_OBJS) $(descent_LIBS)

$(OBJDIR)/ai.obj: ai.c 3d.h ai.h aistruct.h bm.h cntrlcen.h collide.h digi.h effects.h error.h fireball.h fix.h fuelcen.h fvi.h game.h gameseg.h gameseq.h gauges.h gr.h inferno.h key.h laser.h mission.h mono.h morph.h multi.h multibot.h network.h object.h physics.h piggy.h player.h polyobj.h powerup.h render.h robot.h segment.h settings.h sounds.h switch.h text.h timer.h types.h vclip.h vecmat.h wall.h weapon.h
$(OBJDIR)/aipath.obj: aipath.c 3d.h ai.h aistruct.h digi.h editor.h error.h fireball.h fix.h fvi.h game.h gameseg.h gr.h inferno.h mono.h object.h physics.h piggy.h player.h robot.h segment.h settings.h sounds.h types.h ui.h vecmat.h wall.h weapon.h
$(OBJDIR)/args.obj: args.c settings.h
$(OBJDIR)/automap.obj: automap.c 3d.h aistruct.h bm.h digi.h endlevel.h error.h fix.h fuelcen.h game.h gamefont.h gameseg.h gameseq.h gauges.h gr.h hostage.h iff.h inferno.h joy.h kconfig.h key.h mem.h mission.h mono.h mouse.h multi.h network.h object.h palette.h pcx.h piggy.h player.h polyobj.h powerup.h render.h robot.h screens.h segment.h segpoint.h settings.h sounds.h switch.h text.h textures.h timer.h types.h vclip.h vecmat.h wall.h weapon.h
$(OBJDIR)/bm.obj: bm.c 3d.h aistruct.h bm.h cfile.h cflib.h cntrlcen.h digi.h effects.h endlevel.h error.h fix.h fuelcen.h game.h gameseg.h gameseq.h gauges.h gr.h hostage.h iff.h inferno.h mem.h mission.h mono.h multi.h object.h piggy.h player.h polyobj.h powerup.h robot.h segment.h settings.h sounds.h switch.h textures.h types.h vclip.h vecmat.h wall.h weapon.h
$(OBJDIR)/bmread.obj: bmread.c settings.h
$(OBJDIR)/cntrlcen.obj: cntrlcen.c ai.h aistruct.h cntrlcen.h digi.h error.h fix.h fuelcen.h game.h gameseg.h gameseq.h gr.h inferno.h laser.h mission.h mono.h multi.h object.h piggy.h player.h robot.h segment.h settings.h sounds.h switch.h types.h vecmat.h wall.h weapon.h
$(OBJDIR)/collide.obj: collide.c 3d.h ai.h aistruct.h bm.h cntrlcen.h collide.h digi.h effects.h endlevel.h error.h fireball.h fix.h fuelcen.h fvi.h game.h gameseg.h gameseq.h gauges.h gr.h hostage.h inferno.h key.h laser.h mission.h mono.h multi.h multibot.h network.h newdemo.h newmenu.h object.h physics.h piggy.h player.h polyobj.h powerup.h render.h rle.h robot.h scores.h segment.h settings.h slew.h sounds.h switch.h texmap.h text.h textures.h types.h vclip.h vecmat.h wall.h weapon.h
$(OBJDIR)/config.obj: config.c aistruct.h args.h digi.h fix.h game.h gameseg.h gr.h inferno.h joy.h kconfig.h mission.h object.h palette.h piggy.h player.h segment.h settings.h sounds.h types.h vecmat.h weapon.h
$(OBJDIR)/controls.obj: controls.c 3d.h aistruct.h args.h controls.h digi.h error.h fix.h game.h gameseg.h gr.h inferno.h joy.h joydefs.h kconfig.h key.h mono.h mouse.h object.h palette.h piggy.h player.h render.h segment.h settings.h sounds.h timer.h types.h vecmat.h victor.h weapon.h
$(OBJDIR)/credits.obj: credits.c aistruct.h cfile.h compbit.h digi.h error.h fix.h game.h gamefont.h gameseg.h gameseq.h gr.h iff.h inferno.h joy.h key.h mem.h mission.h mono.h mouse.h multi.h network.h newmenu.h object.h palette.h pcx.h piggy.h player.h screens.h segment.h settings.h songs.h sounds.h timer.h types.h vecmat.h vfx.h weapon.h
$(OBJDIR)/digi.obj: digi.c aistruct.h args.h cfile.h digi.h dpmi.h error.h fix.h game.h gameseg.h gr.h inferno.h joy.h kconfig.h key.h mono.h newdemo.h object.h piggy.h segment.h settings.h sounds.h text.h timer.h types.h vecmat.h wall.h
$(OBJDIR)/dumpmine.obj: dumpmine.c 3d.h aistruct.h bm.h digi.h error.h fix.h fuelcen.h game.h gamemine.h gamesave.h gameseg.h gameseq.h gr.h hostage.h inferno.h key.h menu.h mission.h mono.h newmenu.h object.h palette.h piggy.h player.h polyobj.h powerup.h robot.h segment.h settings.h sounds.h switch.h textures.h types.h vclip.h vecmat.h wall.h weapon.h
$(OBJDIR)/effects.obj: effects.c aistruct.h bm.h digi.h effects.h error.h fix.h fuelcen.h game.h gameseg.h gr.h inferno.h mem.h mono.h object.h piggy.h segment.h settings.h sounds.h switch.h textures.h types.h vclip.h vecmat.h
$(OBJDIR)/endlevel.obj: endlevel.c 3d.h aistruct.h bm.h cfile.h compbit.h digi.h endlevel.h error.h fireball.h fix.h fvi.h game.h gameseg.h gameseq.h gauges.h gr.h iff.h inferno.h joy.h key.h mem.h mission.h mono.h multi.h network.h newdemo.h object.h palette.h piggy.h player.h polyobj.h robot.h segment.h settings.h songs.h sounds.h terrain.h texmap.h text.h types.h vclip.h vecmat.h wall.h weapon.h
$(OBJDIR)/fireball.obj: fireball.c 3d.h ai.h aistruct.h bm.h collide.h digi.h endlevel.h error.h fireball.h fix.h fuelcen.h fvi.h game.h gameseg.h gameseq.h gauges.h gr.h inferno.h laser.h mission.h mono.h multi.h network.h newmenu.h object.h physics.h piggy.h player.h polyobj.h powerup.h robot.h scores.h segment.h settings.h sounds.h switch.h timer.h types.h vclip.h vecmat.h wall.h weapon.h
$(OBJDIR)/fuelcen.obj: fuelcen.c 3d.h ai.h aistruct.h bm.h collide.h digi.h error.h fireball.h fix.h fuelcen.h game.h gamemine.h gamesave.h gameseg.h gameseq.h gauges.h gr.h inferno.h laser.h mission.h mono.h morph.h multi.h multibot.h network.h object.h piggy.h player.h polyobj.h robot.h segment.h settings.h sounds.h switch.h types.h vclip.h vecmat.h wall.h weapon.h
$(OBJDIR)/fvi.obj: fvi.c aistruct.h bm.h digi.h error.h fix.h fvi.h game.h gameseg.h gr.h inferno.h laser.h mono.h object.h piggy.h player.h rle.h robot.h segment.h settings.h sounds.h texmerge.h textures.h types.h vecmat.h wall.h weapon.h
$(OBJDIR)/game.obj: game.c 3d.h ai.h aistruct.h args.h automap.h bm.h cntrlcen.h coindev.h collide.h controls.h desc_id.h digi.h dpmi.h effect2d.h effects.h endlevel.h error.h fireball.h fix.h fuelcen.h fvi.h game.h gamefont.h gamesave.h gameseg.h gameseq.h gauges.h gr.h hostage.h ibitblt.h iff.h inferno.h joy.h joydefs.h kconfig.h key.h laser.h lighting.h mem.h menu.h mission.h mono.h morph.h mouse.h multi.h multibot.h network.h newdemo.h newmenu.h object.h palette.h pcx.h physics.h piggy.h player.h powerup.h render.h scores.h screens.h segment.h settings.h slew.h sounds.h state.h switch.h texmap.h text.h textures.h timer.h titles.h types.h vclip.h vecmat.h vfx.h victor.h wall.h weapon.h
$(OBJDIR)/gamefont.obj: gamefont.c fix.h gamefont.h gr.h settings.h types.h
$(OBJDIR)/gamemine.obj: gamemine.c aistruct.h bm.h cfile.h digi.h error.h fix.h fuelcen.h game.h gamemine.h gameseg.h gr.h hash.h inferno.h key.h mono.h newmenu.h object.h piggy.h segment.h settings.h sounds.h switch.h textures.h types.h vecmat.h wall.h
$(OBJDIR)/gamesave.obj: gamesave.c 3d.h aistruct.h automap.h bm.h cfile.h cflib.h digi.h error.h fix.h fuelcen.h game.h gamefont.h gamemine.h gamesave.h gameseg.h gameseq.h gr.h hostage.h inferno.h key.h menu.h mission.h mono.h newdemo.h newmenu.h object.h palette.h piggy.h player.h polyobj.h powerup.h robot.h screens.h segment.h settings.h sounds.h switch.h text.h types.h vclip.h vecmat.h wall.h weapon.h
$(OBJDIR)/gameseg.obj: gameseg.c aistruct.h digi.h error.h fix.h fuelcen.h game.h gameseg.h gr.h inferno.h mono.h object.h piggy.h segment.h settings.h sounds.h switch.h types.h vecmat.h wall.h
$(OBJDIR)/gameseq.obj: gameseq.c 3d.h state.h ai.h aistruct.h arcade.h args.h automap.h bm.h cfile.h cntrlcen.h collide.h config.h digi.h effect2d.h effects.h endlevel.h error.h fireball.h fix.h fuelcen.h fvi.h game.h gamefont.h gamesave.h gameseg.h gameseq.h gauges.h gr.h hostage.h ibitblt.h iff.h inferno.h joy.h kconfig.h key.h laser.h lighting.h mem.h menu.h mission.h modem.h mono.h morph.h multi.h netmisc.h network.h newdemo.h newmenu.h object.h paging.h palette.h pcx.h physics.h piggy.h player.h playsave.h powerup.h render.h robot.h scores.h screens.h segment.h settings.h slew.h songs.h sounds.h switch.h texmap.h texmerge.h text.h textures.h timer.h titles.h types.h vclip.h vecmat.h wall.h weapon.h
$(OBJDIR)/gauges.obj: gauges.c 3d.h aistruct.h bm.h collide.h digi.h endlevel.h error.h fix.h fvi.h game.h gamefont.h gameseg.h gameseq.h gauges.h gr.h hostage.h inferno.h menu.h mission.h mono.h multi.h network.h newdemo.h object.h physics.h piggy.h player.h powerup.h render.h screens.h segment.h settings.h sounds.h text.h types.h vclip.h vecmat.h wall.h weapon.h
$(OBJDIR)/hash.obj: hash.c error.h fix.h hash.h key.h mono.h settings.h types.h
$(OBJDIR)/hostage.obj: hostage.c 3d.h aistruct.h digi.h error.h fireball.h fix.h game.h gameseg.h gauges.h gr.h hostage.h inferno.h lighting.h mono.h newdemo.h object.h piggy.h player.h segment.h settings.h sounds.h text.h types.h vclip.h vecmat.h weapon.h
$(OBJDIR)/hud.obj: hud.c aistruct.h arcade.h collide.h digi.h error.h fix.h fvi.h game.h gamefont.h gameseg.h gauges.h gr.h inferno.h menu.h mono.h newdemo.h object.h physics.h piggy.h player.h screens.h segment.h settings.h sounds.h text.h types.h vecmat.h wall.h weapon.h
$(OBJDIR)/iglasses.obj: iglasses.c args.h error.h fix.h iglasses.h key.h mono.h nocomlib.h settings.h text.h timer.h types.h
$(OBJDIR)/inferno.obj: inferno.c 3d.h aistruct.h arcade.h args.h bm.h cdrom.h cfile.h cflib.h coindev.h config.h desc_id.h digi.h div0.h dpmi.h effects.h error.h fix.h game.h gamefont.h gameseg.h gameseq.h gr.h iff.h iglasses.h inferno.h ipx.h joy.h joydefs.h kconfig.h key.h mem.h menu.h mission.h modem.h mono.h mouse.h multi.h network.h newdemo.h newmenu.h object.h palette.h pcx.h piggy.h player.h polyobj.h robot.h screens.h segment.h segpoint.h settings.h songs.h sounds.h switch.h texmap.h texmerge.h text.h textures.h timer.h titles.h types.h ui.h vclip.h vecmat.h vers_id.h victor.h wall.h weapon.h
$(OBJDIR)/joydefs.obj: joydefs.c 3d.h aistruct.h args.h controls.h digi.h error.h fix.h game.h gameseg.h gr.h inferno.h joy.h joydefs.h kconfig.h key.h mono.h newmenu.h object.h palette.h piggy.h player.h playsave.h render.h segment.h settings.h sounds.h text.h timer.h types.h vecmat.h victor.h weapon.h
$(OBJDIR)/kconfig.obj: kconfig.c 3d.h aistruct.h arcade.h args.h digi.h endlevel.h error.h fix.h game.h gamefont.h gameseg.h gameseq.h gauges.h gr.h iff.h iglasses.h inferno.h joy.h joydefs.h kconfig.h key.h mem.h menu.h mission.h mono.h mouse.h multi.h newmenu.h object.h palette.h piggy.h player.h render.h screens.h segment.h settings.h sounds.h text.h timer.h types.h vecmat.h vfx1.h victor.h weapon.h
$(OBJDIR)/kmatrix.obj: kmatrix.c aistruct.h digi.h error.h fix.h game.h gamefont.h gameseg.h gameseq.h gauges.h gr.h inferno.h joy.h key.h kmatrix.h mem.h menu.h mission.h mono.h mouse.h multi.h network.h newmenu.h object.h palette.h pcx.h piggy.h player.h screens.h segment.h settings.h sounds.h text.h timer.h types.h vecmat.h weapon.h
$(OBJDIR)/laser.obj: laser.c 3d.h ai.h aistruct.h bm.h digi.h error.h fireball.h fix.h fvi.h game.h gameseg.h gameseq.h gr.h inferno.h key.h laser.h mission.h modem.h mono.h multi.h network.h object.h physics.h piggy.h player.h polyobj.h powerup.h render.h robot.h segment.h segpoint.h settings.h sounds.h texmap.h textures.h timer.h types.h vclip.h vecmat.h weapon.h
$(OBJDIR)/lighting.obj: lighting.c 3d.h aistruct.h digi.h error.h fix.h game.h gameseg.h gr.h inferno.h laser.h lighting.h mono.h object.h piggy.h player.h powerup.h render.h segment.h settings.h sounds.h timer.h types.h vclip.h vecmat.h weapon.h
$(OBJDIR)/menu.obj: menu.c 3d.h aistruct.h args.h bm.h cflib.h config.h credits.h digi.h effects.h error.h fix.h game.h gamefont.h gamemine.h gamesave.h gameseg.h gameseq.h gr.h iff.h inferno.h joy.h joydefs.h kconfig.h key.h mem.h menu.h mission.h modem.h mono.h multi.h network.h newdemo.h newmenu.h object.h palette.h piggy.h player.h playsave.h polyobj.h robot.h scores.h screens.h segment.h settings.h slew.h songs.h sounds.h state.h texmap.h text.h timer.h titles.h types.h vclip.h vecmat.h weapon.h
$(OBJDIR)/mglobal.obj: mglobal.c 3d.h aistruct.h bm.h digi.h fix.h game.h gameseg.h gr.h inferno.h object.h piggy.h segment.h settings.h sounds.h types.h vecmat.h
$(OBJDIR)/mission.obj: mission.c aistruct.h cfile.h digi.h error.h fix.h game.h gameseg.h gameseq.h gr.h inferno.h mission.h mono.h object.h piggy.h player.h segment.h settings.h sounds.h titles.h types.h vecmat.h weapon.h
$(OBJDIR)/modem.obj: modem.c aistruct.h args.h collide.h digi.h dpmi.h endlevel.h error.h fix.h fuelcen.h game.h gamesave.h gameseg.h gameseq.h gauges.h gr.h inferno.h laser.h menu.h mission.h modem.h mono.h multi.h multibot.h netmisc.h network.h newmenu.h nocomlib.h object.h palette.h pcx.h piggy.h player.h scores.h segment.h settings.h sounds.h switch.h text.h timer.h types.h vecmat.h weapon.h
$(OBJDIR)/morph.obj: morph.c 3d.h aistruct.h bm.h digi.h error.h fix.h game.h gameseg.h gr.h inferno.h lighting.h mono.h morph.h newdemo.h object.h piggy.h polyobj.h robot.h segment.h settings.h sounds.h texmap.h types.h vecmat.h
$(OBJDIR)/multi.obj: multi.c 3d.h aistruct.h bm.h cntrlcen.h collide.h config.h digi.h endlevel.h error.h fireball.h fix.h fuelcen.h fvi.h game.h gameseg.h gameseq.h gauges.h gr.h inferno.h key.h kmatrix.h laser.h mission.h modem.h mono.h multi.h multibot.h network.h newdemo.h newmenu.h nocomlib.h object.h physics.h piggy.h player.h playsave.h polyobj.h powerup.h robot.h scores.h segment.h settings.h sounds.h state.h switch.h text.h timer.h types.h vclip.h vecmat.h wall.h weapon.h
$(OBJDIR)/multibot.obj: multibot.c ai.h aistruct.h digi.h effects.h error.h fireball.h fix.h fuelcen.h fvi.h game.h gameseg.h gameseq.h gauges.h gr.h inferno.h laser.h mission.h modem.h mono.h morph.h multi.h multibot.h network.h object.h physics.h piggy.h player.h powerup.h robot.h scores.h segment.h settings.h sounds.h switch.h text.h timer.h types.h vclip.h vecmat.h weapon.h
$(OBJDIR)/netmisc.obj: netmisc.c mono.h settings.h types.h
$(OBJDIR)/network.obj: network.c aistruct.h args.h bm.h digi.h effects.h endlevel.h error.h fireball.h fix.h fuelcen.h fvi.h game.h gamemine.h gamesave.h gameseg.h gameseq.h gauges.h gr.h inferno.h ipx.h key.h kmatrix.h laser.h menu.h mission.h mono.h multi.h multibot.h netmisc.h network.h newdemo.h newmenu.h object.h palette.h physics.h piggy.h player.h segment.h settings.h sounds.h switch.h text.h timer.h types.h vclip.h vecmat.h wall.h weapon.h
$(OBJDIR)/newdemo.obj: newdemo.c 3d.h ai.h aistruct.h args.h bm.h cntrlcen.h collide.h digi.h error.h fireball.h fix.h fuelcen.h fvi.h game.h gamemine.h gamesave.h gameseg.h gameseq.h gauges.h gr.h hostage.h inferno.h key.h laser.h lighting.h mission.h mono.h morph.h multi.h network.h newdemo.h newmenu.h object.h palette.h physics.h piggy.h player.h polyobj.h powerup.h render.h robot.h segment.h settings.h slew.h sounds.h switch.h texmap.h text.h types.h vclip.h vecmat.h wall.h weapon.h
$(OBJDIR)/newmenu.obj: newmenu.c aistruct.h digi.h endlevel.h error.h fix.h game.h gamefont.h gameseg.h gameseq.h gr.h iff.h inferno.h joy.h kconfig.h key.h mem.h mission.h mono.h mouse.h multi.h network.h newmenu.h object.h palette.h pcx.h piggy.h player.h screens.h segment.h settings.h sounds.h text.h timer.h types.h vecmat.h vfx.h weapon.h
$(OBJDIR)/nocomlib.obj: nocomlib.c nocomlib.h settings.h
$(OBJDIR)/nodigi.obj: nodigi.c fix.h settings.h types.h vecmat.h
$(OBJDIR)/object.obj: object.c 3d.h ai.h aistruct.h arcade.h args.h bm.h cntrlcen.h collide.h digi.h error.h fireball.h fix.h fuelcen.h fvi.h game.h gameseg.h gameseq.h gauges.h gr.h hostage.h inferno.h key.h laser.h lighting.h menu.h mission.h mono.h morph.h multi.h network.h newdemo.h newmenu.h object.h physics.h piggy.h player.h polyobj.h powerup.h render.h robot.h segment.h settings.h slew.h sounds.h switch.h texmap.h text.h textures.h types.h vclip.h vecmat.h wall.h weapon.h
$(OBJDIR)/paging.obj: paging.c 3d.h aistruct.h bm.h cntrlcen.h digi.h effects.h error.h fireball.h fix.h fuelcen.h game.h gamemine.h gameseg.h gauges.h gr.h inferno.h mono.h object.h palette.h piggy.h polyobj.h powerup.h robot.h segment.h settings.h sounds.h switch.h texmerge.h text.h textures.h timer.h types.h vclip.h vecmat.h wall.h weapon.h
$(OBJDIR)/physics.obj: physics.c ai.h aistruct.h collide.h digi.h error.h fix.h fvi.h game.h gameseg.h gr.h inferno.h joy.h key.h laser.h mono.h newdemo.h object.h physics.h piggy.h segment.h settings.h sounds.h timer.h types.h vecmat.h wall.h
$(OBJDIR)/piggy.obj: piggy.c aistruct.h args.h bm.h cfile.h cflib.h digi.h dpmi.h error.h fix.h game.h gamefont.h gameseg.h gr.h hash.h inferno.h mono.h newmenu.h object.h paging.h palette.h piggy.h rle.h screens.h segment.h settings.h sounds.h texmerge.h text.h types.h vecmat.h
$(OBJDIR)/playsave.obj: playsave.c aistruct.h config.h digi.h error.h fix.h game.h gameseg.h gameseq.h gr.h inferno.h joy.h joydefs.h kconfig.h menu.h mission.h mono.h multi.h newmenu.h object.h palette.h piggy.h player.h playsave.h segment.h settings.h sounds.h state.h text.h types.h vecmat.h weapon.h
$(OBJDIR)/polyobj.obj: polyobj.c 3d.h aistruct.h args.h bm.h cfile.h digi.h error.h fix.h game.h gameseg.h gr.h inferno.h lighting.h mem.h mono.h object.h piggy.h polyobj.h robot.h segment.h settings.h sounds.h texmap.h textures.h types.h vecmat.h
$(OBJDIR)/powerup.obj: powerup.c 3d.h aistruct.h digi.h fireball.h fix.h game.h gameseg.h gameseq.h gauges.h gr.h inferno.h laser.h mission.h mono.h multi.h newdemo.h object.h piggy.h player.h powerup.h scores.h segment.h settings.h sounds.h text.h types.h vclip.h vecmat.h wall.h weapon.h
$(OBJDIR)/render.obj: render.c 3d.h aistruct.h automap.h bm.h digi.h endlevel.h error.h fix.h fuelcen.h fvi.h game.h gameseg.h gr.h inferno.h key.h laser.h lighting.h mem.h mono.h newdemo.h newmenu.h object.h physics.h piggy.h render.h screens.h segment.h segpoint.h settings.h sounds.h switch.h texmap.h texmerge.h textures.h types.h vclip.h vecmat.h wall.h
$(OBJDIR)/robot.obj: robot.c 3d.h aistruct.h digi.h error.h fix.h game.h gameseg.h gr.h inferno.h mono.h object.h piggy.h polyobj.h robot.h segment.h settings.h sounds.h types.h vecmat.h
$(OBJDIR)/scores.obj: scores.c aistruct.h digi.h error.h fix.h game.h gamefont.h gameseg.h gr.h inferno.h joy.h key.h mem.h menu.h mono.h mouse.h newmenu.h object.h palette.h piggy.h player.h screens.h segment.h settings.h sounds.h text.h timer.h types.h vecmat.h vfx.h weapon.h
$(OBJDIR)/slew.obj: slew.c aistruct.h digi.h error.h fix.h fvi.h game.h gameseg.h gr.h inferno.h joy.h joydefs.h kconfig.h key.h object.h physics.h piggy.h segment.h settings.h sounds.h types.h vecmat.h
$(OBJDIR)/songs.obj: songs.c cfile.h digi.h error.h fix.h mono.h settings.h songs.h types.h vecmat.h
$(OBJDIR)/soscodec.obj: soscodec.asm psmacros.inc types.inc
$(OBJDIR)/state.obj: state.c 3d.h aistruct.h args.h automap.h bm.h cfile.h cntrlcen.h digi.h error.h fix.h fuelcen.h game.h gamemine.h gameseg.h gameseq.h gauges.h gr.h hash.h inferno.h key.h mem.h mission.h mono.h morph.h multi.h network.h newdemo.h newmenu.h object.h paging.h pcx.h piggy.h player.h render.h segment.h settings.h sounds.h switch.h text.h textures.h titles.h types.h vecmat.h wall.h weapon.h
$(OBJDIR)/switch.obj: switch.c 3d.h aistruct.h digi.h editor.h endlevel.h error.h fix.h fuelcen.h game.h gameseg.h gameseq.h gauges.h gr.h inferno.h mission.h mono.h multi.h network.h newdemo.h object.h palette.h piggy.h player.h segment.h settings.h sounds.h switch.h texmap.h types.h ui.h vecmat.h wall.h weapon.h
$(OBJDIR)/terrain.obj: terrain.c 3d.h aistruct.h bm.h digi.h endlevel.h error.h fireball.h fix.h gameseg.h gr.h iff.h inferno.h mem.h mono.h object.h piggy.h segment.h settings.h sounds.h texmap.h textures.h types.h vecmat.h
$(OBJDIR)/texmerge.obj: texmerge.c aistruct.h bm.h digi.h error.h fix.h game.h gameseg.h gr.h inferno.h mono.h object.h piggy.h rle.h segment.h settings.h sounds.h textures.h types.h vecmat.h
$(OBJDIR)/text.obj: text.c args.h cfile.h compbit.h error.h inferno.h mem.h settings.h text.h types.h
$(OBJDIR)/titles.obj: titles.c 3d.h aistruct.h arcade.h bm.h cfile.h coindev.h compbit.h digi.h error.h fix.h game.h gamefont.h gameseg.h gameseq.h gr.h iff.h inferno.h joy.h key.h kmatrix.h mem.h mission.h mono.h multi.h newmenu.h object.h palette.h pcx.h piggy.h player.h polyobj.h robot.h screens.h segment.h settings.h songs.h sounds.h state.h text.h textures.h timer.h types.h vecmat.h vfx.h weapon.h
$(OBJDIR)/vclip.obj: vclip.c aistruct.h digi.h error.h fix.h game.h gameseg.h gr.h inferno.h object.h piggy.h segment.h settings.h sounds.h types.h vclip.h vecmat.h weapon.h
$(OBJDIR)/vfx.obj: vfx.c error.h fix.h gr.h mono.h settings.h types.h
$(OBJDIR)/victor.obj: victor.c args.h error.h fix.h key.h mono.h nocomlib.h settings.h text.h types.h victor.h
$(OBJDIR)/wall.obj: wall.c aistruct.h bm.h digi.h editor.h error.h fireball.h fix.h game.h gameseg.h gameseq.h gauges.h gr.h inferno.h mission.h mono.h multi.h newdemo.h object.h piggy.h player.h segment.h settings.h sounds.h switch.h text.h textures.h types.h ui.h vclip.h vecmat.h wall.h weapon.h
$(OBJDIR)/weapon.obj: weapon.c aistruct.h digi.h error.h fix.h game.h gameseg.h gameseq.h gauges.h gr.h inferno.h mission.h mono.h multi.h newdemo.h object.h piggy.h player.h powerup.h segment.h settings.h sounds.h text.h types.h vclip.h vecmat.h weapon.h

$(OBJDIR)/autosave.obj: autosave.c editor.h error.h fix.h gr.h inferno.h mem.h mono.h segment.h settings.h types.h ui.h vecmat.h
$(OBJDIR)/centers.obj: centers.c 3d.h ai.h aistruct.h bm.h centers.h digi.h editor.h ehostage.h eobject.h error.h eswitch.h fix.h fuelcen.h game.h gameseg.h gr.h hostage.h inferno.h kdefs.h key.h medrobot.h medwall.h mono.h object.h objpage.h piggy.h polyobj.h powerup.h robot.h screens.h segment.h settings.h sounds.h switch.h timer.h types.h ui.h vclip.h vecmat.h wall.h
$(OBJDIR)/curves.obj: curves.c editor.h fix.h gameseg.h gr.h inferno.h key.h mono.h segment.h settings.h types.h ui.h vecmat.h
$(OBJDIR)/eglobal.obj: eglobal.c editor.h fix.h gr.h inferno.h segment.h settings.h types.h ui.h vecmat.h
$(OBJDIR)/ehostage.obj: ehostage.c 3d.h ai.h aistruct.h bm.h centers.h digi.h editor.h eobject.h error.h eswitch.h fix.h fuelcen.h game.h gameseg.h gr.h hostage.h inferno.h kdefs.h key.h medrobot.h medwall.h mono.h object.h objpage.h piggy.h polyobj.h powerup.h robot.h screens.h segment.h settings.h sounds.h switch.h timer.h types.h ui.h vclip.h vecmat.h wall.h
$(OBJDIR)/einit.obj: einit.c editor.h fix.h gr.h inferno.h mono.h segment.h settings.h types.h ui.h vecmat.h
$(OBJDIR)/elight.obj: elight.c 3d.h aistruct.h bm.h digi.h editor.h error.h fix.h gameseg.h gr.h inferno.h kdefs.h mono.h object.h piggy.h segment.h seguvs.h settings.h sounds.h texmap.h textures.h types.h ui.h vecmat.h wall.h
$(OBJDIR)/eobject.obj: eobject.c 3d.h ai.h aistruct.h bm.h digi.h editor.h error.h fix.h fuelcen.h fvi.h game.h gameseg.h gr.h hostage.h inferno.h kdefs.h medrobot.h mono.h object.h objpage.h piggy.h player.h polyobj.h powerup.h robot.h segment.h settings.h sounds.h switch.h types.h ui.h vclip.h vecmat.h weapon.h
$(OBJDIR)/eswitch.obj: eswitch.c aistruct.h bm.h centers.h digi.h editor.h ehostage.h error.h eswitch.h fix.h fuelcen.h gameseg.h gr.h inferno.h key.h medrobot.h medwall.h mono.h object.h piggy.h screens.h segment.h settings.h sounds.h switch.h texmerge.h textures.h timer.h types.h ui.h vecmat.h wall.h
$(OBJDIR)/fixseg.obj: fixseg.c editor.h error.h fix.h gameseg.h gr.h inferno.h key.h mono.h segment.h settings.h types.h ui.h vecmat.h
$(OBJDIR)/func.obj: func.c func.h settings.h
$(OBJDIR)/group.obj: group.c aistruct.h bm.h cflib.h digi.h editor.h error.h fix.h fuelcen.h gamemine.h gameseg.h gr.h hash.h inferno.h medwall.h mono.h nocfile.h object.h piggy.h segment.h settings.h sounds.h switch.h textures.h types.h ui.h vecmat.h wall.h
$(OBJDIR)/info.obj: info.c ai.h aistruct.h bm.h digi.h editor.h error.h fix.h gameseg.h gr.h inferno.h mono.h object.h objpage.h piggy.h segment.h settings.h sounds.h switch.h texpage.h textures.h types.h ui.h vecmat.h wall.h
$(OBJDIR)/kbuild.obj: kbuild.c editor.h fix.h gamesave.h gameseg.h gr.h inferno.h mono.h segment.h settings.h types.h ui.h vecmat.h
$(OBJDIR)/kcurve.obj: kcurve.c editor.h fix.h gr.h inferno.h kdefs.h segment.h settings.h types.h ui.h vecmat.h
$(OBJDIR)/kfuncs.obj: kfuncs.c aistruct.h digi.h editor.h eobject.h error.h fix.h func.h gamesave.h gameseg.h gr.h inferno.h kdefs.h medwall.h mono.h object.h piggy.h segment.h settings.h slew.h sounds.h types.h ui.h vecmat.h wall.h
$(OBJDIR)/kgame.obj: kgame.c aistruct.h digi.h editor.h fix.h game.h gamesave.h gameseg.h gameseq.h gr.h inferno.h mission.h object.h piggy.h player.h segment.h settings.h sounds.h types.h ui.h vecmat.h weapon.h
$(OBJDIR)/khelp.obj: khelp.c editor.h fix.h gr.h inferno.h segment.h settings.h types.h ui.h vecmat.h
$(OBJDIR)/kmine.obj: kmine.c aistruct.h dcflib.h digi.h editor.h error.h fix.h game.h gameseg.h gameseq.h gr.h inferno.h info.h kdefs.h mission.h mono.h nocfile.h object.h piggy.h player.h segment.h settings.h sounds.h texpage.h types.h ui.h vecmat.h weapon.h
$(OBJDIR)/ksegmove.obj: ksegmove.c editor.h fix.h gr.h inferno.h segment.h settings.h types.h ui.h vecmat.h
$(OBJDIR)/ksegsel.obj: ksegsel.c editor.h fix.h gr.h inferno.h segment.h settings.h types.h ui.h vecmat.h
$(OBJDIR)/ksegsize.obj: ksegsize.c editor.h error.h fix.h gameseg.h gr.h inferno.h mono.h segment.h settings.h types.h ui.h vecmat.h
$(OBJDIR)/ktmap.obj: ktmap.c editor.h fix.h gr.h inferno.h kdefs.h mono.h segment.h settings.h types.h ui.h vecmat.h
$(OBJDIR)/kview.obj: kview.c editor.h fix.h gr.h inferno.h segment.h settings.h types.h ui.h vecmat.h
$(OBJDIR)/med.obj: med.c 3d.h ai.h aistruct.h bm.h centers.h cflib.h digi.h editor.h effects.h ehostage.h error.h eswitch.h fix.h fuelcen.h func.h game.h gamesave.h gameseg.h gameseq.h gr.h inferno.h info.h kdefs.h key.h kfuncs.h macro.h meddraw.h medmisc.h medrobot.h medsel.h medwall.h mem.h mission.h mono.h newmenu.h object.h objpage.h piggy.h player.h render.h screens.h segment.h settings.h slew.h sounds.h switch.h texmap.h texpage.h textures.h types.h ui.h vclip.h vecmat.h wall.h weapon.h
$(OBJDIR)/meddraw.obj: meddraw.c 3d.h aistruct.h bm.h cflib.h digi.h editor.h error.h fix.h fuelcen.h func.h game.h gameseg.h gr.h inferno.h kdefs.h key.h medlisp.h mem.h mono.h object.h piggy.h render.h screens.h segment.h segpoint.h settings.h sounds.h switch.h texmap.h textures.h types.h ui.h vecmat.h wall.h
$(OBJDIR)/medmisc.obj: medmisc.c 3d.h aistruct.h digi.h editor.h error.h fix.h func.h game.h gameseg.h gr.h inferno.h key.h meddraw.h mem.h mono.h object.h piggy.h render.h screens.h segment.h settings.h sounds.h texpage.h types.h ui.h vecmat.h
$(OBJDIR)/medrobot.obj: medrobot.c 3d.h ai.h aistruct.h bm.h centers.h digi.h editor.h ehostage.h eobject.h error.h eswitch.h fix.h fuelcen.h game.h gameseg.h gr.h hostage.h inferno.h kdefs.h key.h medwall.h mono.h object.h objpage.h piggy.h polyobj.h powerup.h robot.h screens.h segment.h settings.h sounds.h switch.h timer.h types.h ui.h vclip.h vecmat.h wall.h
$(OBJDIR)/medsel.obj: medsel.c aistruct.h digi.h editor.h error.h fix.h gameseg.h gr.h inferno.h key.h mem.h mono.h object.h piggy.h segment.h settings.h sounds.h types.h ui.h vecmat.h
$(OBJDIR)/medwall.obj: medwall.c aistruct.h bm.h centers.h digi.h editor.h ehostage.h error.h eswitch.h fix.h fuelcen.h gameseg.h gr.h inferno.h key.h medrobot.h medwall.h mono.h object.h piggy.h screens.h segment.h settings.h sounds.h switch.h texmerge.h textures.h timer.h types.h ui.h vecmat.h wall.h
$(OBJDIR)/mine.obj: mine.c aistruct.h bm.h dcflib.h digi.h editor.h error.h fix.h fuelcen.h gamemine.h gameseg.h gr.h inferno.h key.h medwall.h mono.h nocfile.h object.h piggy.h segment.h settings.h sounds.h switch.h texpage.h textures.h types.h ui.h vecmat.h wall.h
$(OBJDIR)/objpage.obj: objpage.c 3d.h aistruct.h bm.h digi.h editor.h error.h fix.h game.h gameseg.h gr.h hostage.h inferno.h mono.h object.h objpage.h piggy.h player.h polyobj.h powerup.h robot.h screens.h segment.h settings.h sounds.h texmap.h types.h ui.h vclip.h vecmat.h weapon.h
$(OBJDIR)/segment.obj: segment.c 3d.h aistruct.h demo.h digi.h editor.h error.h fix.h fuelcen.h game.h gameseg.h gameseq.h gr.h hostage.h inferno.h key.h medwall.h mission.h mono.h object.h piggy.h player.h render.h segment.h seguvs.h settings.h sounds.h switch.h types.h ui.h vclip.h vecmat.h wall.h weapon.h
$(OBJDIR)/seguvs.obj: seguvs.c aistruct.h bm.h digi.h editor.h effects.h error.h fix.h fvi.h gameseg.h gr.h inferno.h kdefs.h mono.h object.h piggy.h segment.h settings.h sounds.h types.h ui.h vclip.h vecmat.h wall.h
$(OBJDIR)/texpage.obj: texpage.c bm.h digi.h editor.h error.h fix.h gamesave.h gameseg.h gr.h inferno.h key.h mono.h piggy.h screens.h segment.h settings.h sounds.h texpage.h textures.h types.h ui.h vecmat.h
$(OBJDIR)/texture.obj: texture.c editor.h error.h fix.h gr.h inferno.h kdefs.h mono.h segment.h seguvs.h settings.h texture.c types.h ui.h vecmat.h
