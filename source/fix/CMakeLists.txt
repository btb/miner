#
# Makefile for fixed-point library
#

# What libs to make
add_library(fix)
set_target_properties(fix PROPERTIES LINKER_LANGUAGE C)

# What test programs to make
add_executable(fixtest)

# What object files for the lib
target_sources(fix PRIVATE
	$<IF:$<BOOL:${NO_ASSEMBLY}>,fixc.c tables.c,fix.asm>)

# What source files and libs for the test programs
target_sources(fixtest PRIVATE fixtest.c)
target_link_libraries(fixtest fix)
if(CMAKE_SYSTEM_NAME STREQUAL "DOS")
	target_link_libraries(fixtest io)
else()
	target_link_libraries(fixtest SDL2::SDL2)
endif()
