#
# Makefile for DESCENT execuable
#

LIBDIR = c:\dev\d1src\main
#

CCFLAGS = /dNETWORK /dRELEASE /dNDEBUG
CCFLAGS = $(CFLAGS) /I..\misc /I..\includes /I..\2d /I..\bios /I..\div /I..\mem /I..\vecmat /I..\fix /I..\3d /I..\texmap /I..\ui /I..\pslib


DESCENT_LIBS =	3d.lib gr.lib fix.lib io.lib iff.lib vecmat.lib \
        	 	cfile.lib \
        	 	mem.lib \
        	 	ui.lib \
				div0.lib misc.lib texmap.lib editor.lib

#		sosdigi.lib #sosmidi.lib \
		#iglasses.lib gclfr32.lib loadpats.lib
		#lzw.lib sosdwxcr.lib sosmwxcr.lib 

DESCENT_OBJS = inferno.obj game.obj gauges.obj mglobal.obj \
			 scores.obj object.obj laser.obj physics.obj bm.obj \
 			 menu.obj gamesave.obj switch.obj effects.obj texmerge.obj polyobj.obj \
			 gamemine.obj fireball.obj ai.obj aipath.obj hostage.obj \
			 powerup.obj fuelcen.obj digi.obj render.obj hash.obj piggy.obj args.obj \
			 gameseg.obj wall.obj collide.obj lighting.obj \
			 robot.obj morph.obj vclip.obj weapon.obj fvi.obj newdemo.obj titles.obj \
			 vfx.obj gameseq.obj controls.obj automap.obj text.obj \
			 network.obj newmenu.obj netmisc.obj victor.obj\
			 gamefont.obj joydefs.obj hud.obj playsave.obj \
			 endlevel.obj terrain.obj kconfig.obj modem.obj  \
			 multi.obj cntrlcen.obj credits.obj config.obj soscodec.obj kmatrix.obj	\
			 paging.obj mission.obj iglasses.obj songs.obj bmread.obj state.obj multibot.obj nocomlib.obj slew.obj dumpmine.obj 
#demo.obj garage.obj radar.obj coindev.obj serial.obj vfxread.obj victor.obj


# Files to link for Descent

DESCENTR.EXE: 	$(DESCENT_OBJS)
	wcl386 /fe=descentr.exe /l=dos4g /k50000 $(DESCENT_OBJS) $(DESCENT_LIBS)

ai.obj:	 ai.c ai.h
aipath.obj: aipath.c
arcade.obj: arcade.c 
args.obj: args.c args.h
automap.obj: automap.c 
	
autosave.obj: autosave.c 
	
bm.obj:	 bm.c 
bmread.obj: bmread.c 
	
centers.obj: centers.c 
	
cntrlcen.obj: cntrlcen.c 
cockpit.obj: cockpit.asm
#cockpit.inc psmacros.inc types.inc

coindev.obj: coindev.c coindev.h 
collide.obj: collide.c collide.h
config.obj: config.c 
controls.obj: controls.c 
credits.obj: credits.c 
curves.obj: curves.c 
demo.obj: demo.c 
digi.obj: digi.c 
dumpmine.obj: dumpmine.c 
effects.obj: effects.c 
eglobal.obj: eglobal.c 
ehostage.obj: ehostage.c 
einit.obj: einit.c 
elight.obj: elight.c 
endlevel.obj: endlevel.c 
eobject.obj: eobject.c 
eswitch.obj: eswitch.c 
fireball.obj: fireball.c 
fixseg.obj: fixseg.c 
flyby.obj: flyby.c 
fuelcen.obj: fuelcen.c 
func.obj: func.c 
fvi.obj: fvi.c 
game.obj: game.c 
gamefont.obj: gamefont.c
gamemine.obj: gamemine.c 
gamesave.obj: gamesave.c 
gameseg.obj: gameseg.c 
gameseq.obj: gameseq.c
garage.obj: garage.c 
gauges.obj: gauges.c
group.obj: group.c
hash.obj: hash.c
hostage.obj: hostage.c
hud.obj: hud.c
iglasses.obj: iglasses.c
inferno.obj: inferno.c
info.obj: info.c
int3hand.obj: psmacros.inc types.inc
ipx_esr.obj: psmacros.inc types.inc
joydefs.obj: joydefs.c
kbuild.obj: 
kconfig.obj: 
kcurve.obj: 
kfuncs.obj: 
kgame.obj: 
khelp.obj: 
kmatrix.obj: 
kmine.obj:
ksegmove.obj:
ksegsize.obj:
ktmap.obj:
kview.obj:
laser.obj:
lighting.obj:
macro.obj: 
mcockpit.obj: 
med.obj: 
meddraw.obj: 
medmisc.obj: 
medrobot.obj: 
medsel.obj: 
medwall.obj: 
menu.obj: 
mglobal.obj: 
mine.obj: 
mission.obj: 
modem.obj: 
morph.obj: 
multi.obj: 
multibot.obj:
netmisc.obj: 
netware.obj: 
network.obj: 
newdemo.obj: 
newdemo1.obj:
newmenu.obj: 
object.obj: 
objfly.obj: 
objpage.obj: 
ourcom.obj: 
paging.obj: 
photos.obj: 
physics.obj:
piggy.obj: 
playsave.obj: 
polyobj.obj: 
powerup.obj: 
radar.obj: 
render.obj: 
robot.obj: 
scores.obj: 
segment.obj: 
seguvs.obj: 
serial.obj: 
ship.obj: 
slew.obj: 
songs.obj: 
soscodec.obj: soscodec.asm
state.obj: 
switch.obj:
tempgame.obj: 
terrain.obj: 
test1.obj:
testgaug.obj:
texmerge.obj:
texpage.obj: 
text.obj: 
texture.obj: 
titles.obj: 
vclip.obj: 
vfx.obj: 
#vfxread.obj: 
#	wcc386 $(CCFLAGS) vfxread.c
victor.obj: 
wall.obj: 
weapon.obj: 
nocomlib.obj: nocomlib.c

