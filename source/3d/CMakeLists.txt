#
# Makefile for 3d library
#

# What libs to build
add_library(3d)
set_target_properties(3d PROPERTIES LINKER_LANGUAGE C)

# What objs in the lib
target_sources(3d PRIVATE $<IF:$<BOOL:${NO_ASSEMBLY}>,
	globvarc.c setupc.c matrixc.c pointsc.c drawc.c clipperc.c
	horizonc.c instancc.c rodc.c interpc.c
,
	globvars.asm setup.asm matrix.asm points.asm draw.asm clipper.asm
	horizon.asm instance.asm rod.asm interp.asm
>)
