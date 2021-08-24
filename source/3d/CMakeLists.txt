#
# Makefile for 3d library
#

# What libs to build
add_library(3d)
set_target_properties(3d PROPERTIES LINKER_LANGUAGE C)

# What objs in the lib
target_sources(3d PRIVATE globvars.asm setup.asm matrix.asm points.asm draw.asm clipper.asm horizon.asm instance.asm rod.asm interp.asm)
