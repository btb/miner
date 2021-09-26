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
	canvas.c bitmap.c gr.c font.c
	bitblt.c scanline.c pixel.c poly.c disc.c rect.c box.c
	gpixel.c line.c
	scale.c circle.c ibitblt.c rle.c pcx.c)
if(NOT NO_ASSEMBLY)
	target_sources(gr PRIVATE linear.asm lbitblt.asm scalea.asm)
endif()

# What source files and libs for the programs
target_sources(fdraw PRIVATE fdraw.c)
target_link_libraries(fdraw gr misc cfile fix mem)

# What object files and libs for the test programs
target_sources(testg PRIVATE testg.c tmapbits.c)
target_link_libraries(testg gr misc mem iff cfile fix)

target_sources(vesatest PRIVATE vesatest.c)
target_link_libraries(vesatest gr misc mem cfile fix)

if(CMAKE_SYSTEM_NAME STREQUAL "DOS")
	target_link_libraries(fdraw io vga)
	target_link_libraries(testg io vga)
	target_link_libraries(vesatest io vga)
else()
	target_link_libraries(fdraw sdl unix)
	target_link_libraries(testg sdl unix)
	target_link_libraries(vesatest sdl unix)
endif()
