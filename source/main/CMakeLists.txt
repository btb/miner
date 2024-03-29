#
# Makefile for DESCENT execuable
#

if(USE_SOS)
	set(SOS_DIR ${PROJECT_SOURCE_DIR}/extlib/sos)
	include_directories(${SOS_DIR})
	add_library(sosdigi STATIC IMPORTED GLOBAL)
	set_target_properties(sosdigi PROPERTIES
		IMPORTED_LOCATION ${SOS_DIR}/sosdigi.lib)
	add_library(sosmidi STATIC IMPORTED GLOBAL)
	set_target_properties(sosmidi PROPERTIES
		IMPORTED_LOCATION ${SOS_DIR}/sosmidi.lib)
endif()

if(USE_COMMLIB)
	set(COMMLIB_DIR ${PROJECT_SOURCE_DIR}/extlib/greenlf)
	include_directories(${COMMLIB_DIR})
	add_library(gclfr32 STATIC IMPORTED GLOBAL)
	set_target_properties(gclfr32 PROPERTIES
		IMPORTED_LOCATION ${COMMLIB_DIR}/gclfr32.lib)
endif()

add_executable(descent)
target_link_libraries(descent 3d gr fix io iff vecmat cfile misc texmap
	$<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:mem>)
if(NOT NO_ASSEMBLY)
	target_link_libraries(descent div0)
endif()
if(USE_SOS)
	target_link_libraries(descent sosdigi sosmidi)
endif()
if(USE_COMMLIB)
	target_link_libraries(descent gclfr32)
endif()
if(BUILD_EDITOR)
	add_subdirectory(editor)
	target_link_libraries(descent ui editor)
endif()
		#iglasses.lib gclfr32.lib loadpats.lib
		#lzw.lib sosdwxcr.lib sosmwxcr.lib 
include_directories(../pslib ../ui) # should really only be needed for editor

set(DESCENT_SRCS inferno.c game.c gauges.c mglobal.c
	scores.c object.c laser.c physics.c bm.c
	menu.c gamesave.c switch.c effects.c texmerge.c polyobj.c
	gamemine.c fireball.c ai.c aipath.c hostage.c
	powerup.c fuelcen.c render.c hash.c piggy.c args.c
	gameseg.c wall.c collide.c lighting.c
	robot.c morph.c vclip.c weapon.c fvi.c newdemo.c titles.c
	vfx.c gameseq.c controls.c automap.c text.c
	network.c newmenu.c netmisc.c victor.c
	gamefont.c joydefs.c hud.c playsave.c
	endlevel.c terrain.c kconfig.c modem.c
	multi.c cntrlcen.c credits.c config.c kmatrix.c
	paging.c mission.c iglasses.c songs.c bmread.c state.c multibot.c
	$<$<NOT:$<OR:$<CONFIG:Release>,$<CONFIG:RelWithDebInfo>>>:slew.c>
	$<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:dumpmine.c>)
if(ARCADE)
	list(APPEND DESCENT_SRCS arcade.c)
endif()
if(USE_SOS)
	list(APPEND DESCENT_SRCS digi.c)
else()
	list(APPEND DESCENT_SRCS no_digi.c)
endif()
if(NOT USE_COMMLIB)
	list(APPEND DESCENT_SRCS nocomlib.c)
endif()
#demo.c garage.c radar.c coindev.c serial.c vfxread.c victor.c
target_sources(descent PRIVATE ${DESCENT_SRCS})

# The linker used at the time would have been case-insensitive.
# There are some symbol references in Descent that have mismatched case.
# Not so many that they can't be fixed, but some of them are tricky to see
# exactly what was meant in the original code.
target_link_options(descent PRIVATE option nocaseexact)

install(TARGETS descent RUNTIME DESTINATION .)

# Files to link for Descent

# DESCENTR.EXE: 	$(DESCENT_OBJS)
# 	wcl386 /fe=descentr.exe /l=dos4g /k50000 $(DESCENT_OBJS) $(DESCENT_LIBS)
