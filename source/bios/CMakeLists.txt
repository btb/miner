#
# Makefile for bios functions
#

# What libs to make
add_library(io)

# What test programs to make
# add_executable(demo)
# add_executable(testj)
# add_executable(testk)
# add_executable(testm)
# add_executable(testms)

# What object files for the lib
target_sources(io PRIVATE key.c joy.asm mouse.c timer.asm mono.c joyc.c dpmi.c ipx.c)

# What object files and libs for the test programs
# target_sources(demo PRIVATE demo.c)
# target_link_libraries(demo io)
