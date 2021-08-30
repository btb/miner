#
# Makefile for vga functions
#

# What libs to make
add_library(vga)

# What source files for the lib
target_sources(vga PRIVATE
	vga.c palette.c vesa.asm modex.asm)
