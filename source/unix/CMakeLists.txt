#
# Makefile for unix functions
#

# What libs to make
add_library(unix)

# What object files for the lib
target_sources(unix PRIVATE mono.c)
