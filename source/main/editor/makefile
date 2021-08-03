#
# $Source: f:/miner/source/main/rcs/makefile $
# $Revision: 2.11 $
# $Author: john $
# $Date: 1995/05/26 16:16:13 $
#
# Makefile for DESCENT execuable
#

LIBDIR = ..\main
#

CCFLAGS = /dNETWORK /dRELEASE /dNDEBUG
EDITOR_OBJS = med.obj einit.obj eglobal.obj mine.obj curves.obj kcurve.obj \
	khelp.obj ksegsel.obj kbuild.obj kview.obj kmine.obj seguvs.obj ksegsize.obj \
	ksegmove.obj ktmap.obj kfuncs.obj autosave.obj group.obj texture.obj \
	fixseg.obj eobject.obj elight.obj texpage.obj objpage.obj medmisc.obj \
	medsel.obj kgame.obj info.obj medwall.obj eswitch.obj medrobot.obj meddraw.obj \
	segment.obj ehostage.obj centers.obj func.obj

EDITOR: $(EDITOR_OBJS)
	wlib editor.lib $(EDITOR_OBJS)
	copy *.lib ..
	
# Editor data files to check out with source
#EDITOR_DATA = segmove.pad segsize.pad texture.pad object.pad curve.pad \
#	      group.pad objmov.pad lighting.pad test.pad med.mnu global.key

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
ksegsel.obj:
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
soscodec.obj: psmacros.inc types.inc
state.obj: 
switch.obj:
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
