#
# Makefile for hack3df testbed
#

#Uncomment the following 3 lines if you want to build with only C code.
#set(NASM 1)
if(NASM)
add_compile_definitions(NASM)
endif()

# What libs to build
add_library(texmap)

# What objs in the TEXMAP lib
#target_sources(texmap PRIVATE ntmap.c tmapsky.c tmapv.c tmapflat.c tmap_per.asm tmap_p2.asm tmap_lin.asm tmap_ll.asm tmap_kl.asm tmap_ld.asm tmap_flt.asm tmap_sky.asm tmap_skv.asm tmap_fl1.asm tmapz.c tmap_z.asm tmapfade.c tmap_mul.asm)

target_sources(texmap PRIVATE ntmap.c tmapflat.c
	$<IF:$<BOOL:${NASM}>,
		scanline.c,
		tmap_per.asm tmap_lin.asm tmap_ll.asm tmap_flt.asm tmapfade.asm tmap_fl1.asm
	>)
