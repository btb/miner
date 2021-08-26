#
# Makefile for hack3df testbed
#

# What libs to build
add_library(texmap)

# What objs in the TEXMAP lib
target_sources(texmap PRIVATE ntmap.c tmapflat.c
	$<IF:$<BOOL:${NO_ASSEMBLY}>,
		scanline.c
	,
		tmap_per.asm tmap_lin.asm tmap_ll.asm tmap_flt.asm tmapfade.asm
		tmap_fl1.asm
	>
)
