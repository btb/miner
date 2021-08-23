#
# Makefile for misc libaray
#

# What libs to build
add_library(misc)

# What objs in the lib
target_sources(misc PRIVATE byteswap.c error.c
   $<$<BOOL:${BUILD_EDITOR}>:parsarg.c>
)

# What test programs to make
# add_executable(errtest)
# add_executable(parstest)

# What object files and libs for the test programs
# target_sources(parstest PRIVATE parstest.c)
# target_link_libraries(parstest misc)

# target_sources(errtest PRIVATE errtest.c)
# target_link_libraries(errtest misc)
