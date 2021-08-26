#
# Makefile for IFF library
#

# What libs to build
add_library(iff)

# What objs in the iff lib
target_sources(iff PRIVATE iff.c)

# What test programs to make
# add_executable(ifftest)
# add_executable(ifftestv)

# What source files and libs for the test programs
# target_sources(ifftest PRIVATE ifftest.c)
# target_link_libraries(ifftest iff gr mem bm misc cflib cfile)

# target_sources(ifftestv PRIVATE ifftestv.c)
# target_link_libraries(ifftestv iff vesa cflib cfile)
