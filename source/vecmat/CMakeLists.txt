#
# Makefile for vector/matrix library
#

# What libs to build
add_library(vecmat)
set_target_properties(vecmat PROPERTIES LINKER_LANGUAGE C)

# What objs in the lib
target_sources(vecmat PRIVATE vecmat.asm)

# What test programs to make
# add_executable(vectest)

# What object files and libs for the test programs
# target_sources(vectest PRIVATE vectest.c)
# target_link_libraries(vectest vecmat io fix)
