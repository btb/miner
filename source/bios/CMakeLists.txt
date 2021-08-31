#
# Makefile for bios functions
#

# What libs to make
add_library(io)

# What test programs to make
add_executable(demo)
add_executable(testj)
add_executable(testk)
add_executable(testm)
add_executable(testmem)
add_executable(testms)
add_executable(testt)

# What object files for the lib
target_sources(io PRIVATE
	key.c joy.asm mouse.c timer.asm mono.c joyc.c dpmi.c ipx.c findfile.c)

# What object files and libs for the test programs
target_sources(demo PRIVATE demo.c)
target_link_libraries(demo io)

target_sources(testj PRIVATE testj.c)
target_link_libraries(testj io fix)

target_sources(testk PRIVATE testk.c)
target_link_libraries(testk io)

target_sources(testm PRIVATE testm.c)
target_link_libraries(testm io fix)

target_sources(testmem PRIVATE testmem.c)
target_link_libraries(testmem io)

target_sources(testms PRIVATE testms.c)
target_link_libraries(testms io)

target_sources(testt PRIVATE testt.c)
target_link_libraries(testt io)

