#
# Makefile for misc libaray
#

# What libs to build
add_library(misc)

# What objs in the lib
target_sources(misc PRIVATE byteswap.c error.c
   $<$<BOOL:${BUILD_EDITOR}>:parsarg.c>
)
if(NOT CMAKE_SYSTEM_NAME STREQUAL "DOS")
   target_sources(misc PRIVATE fileutil.c misc.c strutil.c)
endif()

# What test programs to make
# add_executable(errtest)
# add_executable(parstest)

# What object files and libs for the test programs
# target_sources(parstest PRIVATE parstest.c)
# target_link_libraries(parstest misc)

# target_sources(errtest PRIVATE errtest.c)
# target_link_libraries(errtest misc)
