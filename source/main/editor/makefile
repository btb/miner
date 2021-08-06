#
# $Source: f:/miner/source/main/rcs/makefile $
# $Revision: 2.11 $
# $Author: john $
# $Date: 1995/05/26 16:16:13 $
#
# Makefile for DESCENT execuable
#

LIBDIR = ../main
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

ai.obj: ai.c	 ai.c ai.h
aipath.obj: aipath.c aipath.c
arcade.obj: arcade.c arcade.c 
args.obj: args.c args.c args.h
automap.obj: automap.c automap.c 
	
autosave.obj: autosave.c autosave.c 
	
bm.obj: bm.c	 bm.c 
bmread.obj: bmread.c bmread.c 
	
centers.obj: centers.c centers.c 
	
cntrlcen.obj: cntrlcen.c cntrlcen.c 
cockpit.obj: cockpit.c cockpit.asm
#cockpit.inc psmacros.inc types.inc

coindev.obj: coindev.c coindev.c coindev.h 
collide.obj: collide.c collide.c collide.h
config.obj: config.c config.c 
controls.obj: controls.c controls.c 
credits.obj: credits.c credits.c 
curves.obj: curves.c curves.c 
demo.obj: demo.c demo.c 
digi.obj: digi.c digi.c 
dumpmine.obj: dumpmine.c dumpmine.c 
effects.obj: effects.c effects.c 
eglobal.obj: eglobal.c eglobal.c 
ehostage.obj: ehostage.c ehostage.c 
einit.obj: einit.c einit.c 
elight.obj: elight.c elight.c 
endlevel.obj: endlevel.c endlevel.c 
eobject.obj: eobject.c eobject.c 
eswitch.obj: eswitch.c eswitch.c 
fireball.obj: fireball.c fireball.c 
fixseg.obj: fixseg.c fixseg.c 
flyby.obj: flyby.c flyby.c 
fuelcen.obj: fuelcen.c fuelcen.c 
func.obj: func.c func.c 
fvi.obj: fvi.c fvi.c 
game.obj: game.c game.c 
gamefont.obj: gamefont.c gamefont.c
gamemine.obj: gamemine.c gamemine.c 
gamesave.obj: gamesave.c gamesave.c 
gameseg.obj: gameseg.c gameseg.c 
gameseq.obj: gameseq.c gameseq.c
garage.obj: garage.c garage.c 
gauges.obj: gauges.c gauges.c
group.obj: group.c group.c
hash.obj: hash.c hash.c
hostage.obj: hostage.c hostage.c
hud.obj: hud.c hud.c
iglasses.obj: iglasses.c iglasses.c
inferno.obj: inferno.c inferno.c
info.obj: info.c info.c
int3hand.obj: int3hand.c psmacros.inc types.inc
ipx_esr.obj: ipx_esr.c psmacros.inc types.inc
joydefs.obj: joydefs.c joydefs.c
kbuild.obj: kbuild.c 
kconfig.obj: kconfig.c 
kcurve.obj: kcurve.c 
kfuncs.obj: kfuncs.c 
kgame.obj: kgame.c 
khelp.obj: khelp.c 
kmatrix.obj: kmatrix.c 
kmine.obj: kmine.c
ksegmove.obj: ksegmove.c
ksegsel.obj: ksegsel.c
ksegsize.obj: ksegsize.c
ktmap.obj: ktmap.c
kview.obj: kview.c
laser.obj: laser.c
lighting.obj: lighting.c
macro.obj: macro.c 
mcockpit.obj: mcockpit.c 
med.obj: med.c 
meddraw.obj: meddraw.c 
medmisc.obj: medmisc.c 
medrobot.obj: medrobot.c 
medsel.obj: medsel.c 
medwall.obj: medwall.c 
menu.obj: menu.c 
mglobal.obj: mglobal.c 
mine.obj: mine.c 
mission.obj: mission.c 
modem.obj: modem.c 
morph.obj: morph.c 
multi.obj: multi.c 
multibot.obj: multibot.c
netmisc.obj: netmisc.c 
netware.obj: netware.c 
network.obj: network.c 
newdemo.obj: newdemo.c 
newdemo1.obj: newdemo1.c
newmenu.obj: newmenu.c 
object.obj: object.c 
objfly.obj: objfly.c 
objpage.obj: objpage.c 
ourcom.obj: ourcom.c 
paging.obj: paging.c 
photos.obj: photos.c 
physics.obj: physics.c
piggy.obj: piggy.c 
playsave.obj: playsave.c 
polyobj.obj: polyobj.c 
powerup.obj: powerup.c 
radar.obj: radar.c 
render.obj: render.c 
robot.obj: robot.c 
scores.obj: scores.c 
segment.obj: segment.c 
seguvs.obj: seguvs.c 
serial.obj: serial.c 
ship.obj: ship.c 
slew.obj: slew.c 
songs.obj: songs.c 
soscodec.obj: soscodec.c psmacros.inc types.inc
state.obj: state.c 
switch.obj: switch.c
terrain.obj: terrain.c 
test1.obj: test1.c
testgaug.obj: testgaug.c
texmerge.obj: texmerge.c
texpage.obj: texpage.c 
text.obj: text.c 
texture.obj: texture.c 
titles.obj: titles.c 
vclip.obj: vclip.c 
vfx.obj: vfx.c 
#vfxread.obj: #vfxread.c 
#	wcc386 $(CCFLAGS) vfxread.c
victor.obj: victor.c 
wall.obj: wall.c 
weapon.obj: weapon.c 
nocomlib.obj: nocomlib.c nocomlib.c
