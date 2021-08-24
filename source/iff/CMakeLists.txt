#
# Makefile for IFF library
#

# What libs to build
add_library(iff)

# What objs in the iff lib
target_sources(iff PRIVATE iff.c)
