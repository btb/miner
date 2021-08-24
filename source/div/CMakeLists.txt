#
# Makefile for bios functions
#

# What libs to make
add_library(div0)
set_target_properties(div0 PROPERTIES LINKER_LANGUAGE C)

# What test programs to make
# add_executable(testd)

# What object files for the lib
target_sources(div0 PRIVATE div0.asm)

# What object files and libs for the test programs
# target_sources(testd PRIVATE testd.c testda.asm)
# target_link_libraries(testd div0)
