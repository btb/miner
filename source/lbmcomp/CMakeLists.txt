#
# Makefile for lbmcomp
#

# What programs to make
add_executable(lbmcomp)

# What source files and libs for the programs
target_sources(lbmcomp PRIVATE lbmcomp.c)

target_link_libraries(lbmcomp gr misc mem iff readfile ui io func cflib cfile)
target_link_options(lbmcomp PRIVATE option stack=150k)
