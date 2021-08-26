#
# Makefile for memory debugging
#

# What libs to make
add_library(mem)

# What source files for the lib
target_sources(mem PRIVATE mem.c)
