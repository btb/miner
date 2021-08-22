#
# Master makefile for Miner source
#
# Makes all the executable by visiting subdirs and making there
#

# CC = wcc386
# CCENV = wcc386
# CFLAGS_STACK = /s	#default is stack checking off
# CFLAGS = /zq /zld /w3 /on /oa $(INCPATH,</I\=) $(CFLAGS_DEBUG) $(CFLAGS_OPT) $(GLOBAL_CFLAGS) $(CFLAGS_STACK) $(CFLAGS_MONO)
# zq operate quietly (see "zq" on page 31)
# zld suppress generation of file dependency information in object file (see "zld" on page 37)
# w<number> set warning level number (default is w1) (see "w<number>" on page 28)
# on This option allows the compiler to replace floating-point divisions with multiplications by the reciprocal
# oa Alias checking is relaxed.

if(WATCOM)
   add_compile_options($<$<COMPILE_LANGUAGE:C>:-fi=settings.h>)
   add_compile_options($<$<COMPILE_LANGUAGE:C>:-zp1>)
   set(CMAKE_SYSTEM_NAME DOS)
endif()

# Set up personal settings
set(USE_SOS ON)
set(NEWDEMO ON)
option(BUILD_EDITOR "" OFF)
if(BUILD_EDITOR)
   set(EDITOR ON)
endif()
option(NMONO "is monochrome debugging turned off?" ON)
option(SHAREWARE "is this the smaller shareware?" OFF)
option(ARCADE "is the Arcade/AWD code in?" OFF)
option(DEMO_ONLY "Game is playable" OFF)
option(REQUIRE_CD "Copy protect?" OFF)
option(USE_CD "Use a CD if available?" OFF)
option(ROCKWELL_CODE "Rockwell psuedo shareware" OFF)
option(MARK_ON "are marks on?" OFF)
if(MARK_ON)
   set(_MARK_ON ON)
endif()
set(PASSWORD CACHE STRING "is a password required?")
option(DEST_SAT "Build for Destination Saturn?" OFF)
option(COMPACT_SEGS "" OFF)
option(NO_MULTIPLAYER "Take out multiplayer code" OFF)
if(NOT NO_MULTIPLAYER)
   set(NETWORK ON)
endif()
option(PIGGY_NO_PAGING "Don't use paging from pig file" OFF)
if(NOT PIGGY_NO_PAGING)
   SET(PIGGY_USE_PAGING ON)
endif()
option(NO_ASSEMBLY "Build with only C code" OFF)
if(NO_ASSEMBLY)
   SET(NASM ON)
endif()

#other vestiges
#STORE_DEMO
#OPTIMIZE_ON
#SIMULEYES

# Check various settings for conflicts
if(ARCADE AND NEWDEMO)
message(FATAL_ERROR "ARCADE option requires that NEWDEMO also be set.")
endif()
if(DEMO_ONLY AND NEWDEMO)
message(FATAL_ERROR "DEMO_ONLY defined, but NEWDEMO not.")
endif()

add_compile_definitions(
   $<$<OR:$<CONFIG:Release>,$<CONFIG:RelWithDebInfo>>:RELEASE>
   $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>>:NDEBUG>
)
configure_file(main/vers_id.h.in main/vers_id.h)
configure_file(main/settings.h.in main/settings.h)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/main)

# The only thing to make is the subdirs
set(SUBSYSTEMS misc includes fix cfile 2d bios iff div mem vecmat 3d texmap)
#sosdigi sosmidi
if(BUILD_EDITOR)
list(APPEND SUBSYSTEMS pslib ui)
endif()

include_directories(${SUBSYSTEMS})
foreach(SUBSYSTEM ${SUBSYSTEMS})
add_subdirectory(${SUBSYSTEM})
endforeach()

add_subdirectory(main)
