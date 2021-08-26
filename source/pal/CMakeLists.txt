#
# Makefile for pal functions
#

# What test programs to make
add_executable(testp)

# What object files and libs for the test programs
target_sources(testp PRIVATE testp.c iff.c iff15bpp.c)
target_link_libraries(testp io gr ui misc mem bm iff readfile)
