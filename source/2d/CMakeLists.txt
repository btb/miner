#
# Makefile for bios functions
#

# What libs to make
add_library(gr)

# What programs to make
add_executable(fdraw)

# What test programs to make
add_executable(testg)
add_executable(vesatest)

# What object files for the lib
target_sources(gr PRIVATE
	linear.asm vesa.asm modex.asm canvas.c bitmap.c gr.c font.c
	bitblt.c scanline.c pixel.c poly.c disc.c rect.c box.c
	gpixel.c palette.c line.c lbitblt.asm
	scale.c scalea.asm circle.c ibitblt.c rle.c pcx.c)

# What source files and libs for the programs
target_sources(fdraw PRIVATE fdraw.c)
target_link_libraries(fdraw io gr misc cfile fix mem)

# What object files and libs for the test programs
target_sources(testg PRIVATE testg.c tmapbits.c)
target_link_libraries(testg io gr misc mem iff cfile fix)

target_sources(vesatest PRIVATE vesatest.c)
target_link_libraries(vesatest io gr misc mem cfile fix)
