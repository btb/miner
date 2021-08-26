#
# Makefile for xcolor
#

# What programs to make
add_executable(xcolor)

# What source files and libs for the programs
target_sources(xcolor PRIVATE xcolor.c )
target_link_libraries(xcolor gr misc mem iff ui io cflib cfile)
target_link_options(xcolor PRIVATE option stack=150k)
