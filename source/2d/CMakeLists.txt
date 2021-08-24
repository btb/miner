#
# Makefile for bios functions
#

# What libs to make
add_library(gr)

# What test programs to make
# add_executable(testg)
# add_executable(vesatest)

# What object files for the lib
target_sources(gr PRIVATE linear.asm vesa.asm modex.asm canvas.c bitmap.c gr.c font.c bitblt.c scanline.c pixel.c poly.c disc.c rect.c box.c gpixel.c palette.c line.c lbitblt.asm scale.c scalea.asm circle.c ibitblt.c rle.c pcx.c)
# target_sources(gr PRIVATE effects.c roller.c)

# What object files and libs for the test programs
# target_sources(testg PRIVATE testg.c tmapbits.c)
# target_link_libraries(testg io gr misc mem iff cfile)

# target_sources(vesatest vesatest.c)
# target_link_libraries(io gr misc mem cflib)
