#
# Makefile for compress library
#

# What libs to make
add_library(cflib)

# What object files for the lib
target_sources(cflib PRIVATE lzw.c bitio.c library.c)
#cf.c

# What test programs to make
add_executable(pslib)
# add_executable(cftest)
# add_executable(cftest2)

# What object files and libs for the test programs
target_sources(pslib PRIVATE pslib.c)
target_link_libraries(pslib cflib misc mem io)

# target_sources(cftest PRIVATE cftest.c)
# target_link_libraries(cftest cflib.lib misc.lib mem.lib io.lib)

# target_sources(cftest2 PRIVATE cftest2.c)
# target_link_libraries(cftest2 cflib.lib misc.lib mem.lib io.lib)
