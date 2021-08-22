#
# Makefile for fixed-point library
#

# What libs to make
add_library(fix)
set_target_properties(fix PROPERTIES LINKER_LANGUAGE C)

# What object files for the lib
target_sources(fix PRIVATE
   $<IF:$<BOOL:${NO_ASSEMBLY}>,
      fixc.c tables.c
   ,
      fix.asm
   >)
