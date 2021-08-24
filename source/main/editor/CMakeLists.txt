#
# Makefile for DESCENT execuable
#

include_directories(..)

add_library(editor)
target_sources(editor PRIVATE med.c einit.c eglobal.c mine.c curves.c kcurve.c khelp.c ksegsel.c kbuild.c kview.c kmine.c seguvs.c ksegsize.c ksegmove.c ktmap.c kfuncs.c autosave.c group.c texture.c fixseg.c eobject.c elight.c texpage.c objpage.c medmisc.c medsel.c kgame.c info.c medwall.c eswitch.c medrobot.c meddraw.c segment.c ehostage.c centers.c func.c)
	
# Editor data files to check out with source
#EDITOR_DATA = segmove.pad segsize.pad texture.pad object.pad curve.pad group.pad objmov.pad lighting.pad test.pad med.mnu global.key
