#
# Master makefile for Miner source
#
# Makes all the executable by visiting subdirs and making there
#

# What libs to make
add_library(cfile)

# What test programs to make
add_executable(t)

# What object files for the lib
target_sources(cfile PRIVATE cfile.c)

# What object files and libs for the test programs
target_sources(t PRIVATE t.c)
