#
# Makefile for compress library
#

# What libs to make
add_library(cflib)

# What object files for the lib
target_sources(cflib PRIVATE lzw.c bitio.c library.c)

# What programs to make
add_executable(pslib)

# What object files and libs for the test programs
target_sources(pslib PRIVATE pslib.c)
target_link_libraries(pslib cflib misc mem io)
