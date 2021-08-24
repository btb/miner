#
# Master makefile for Miner source
#
# Makes all the executable by visiting subdirs and making there
#

add_executable(lbmcomp)

target_sources(lbmcomp PRIVATE lbmcomp.c)

target_link_libraries(lbmcomp gr misc mem iff readfile ui io func cflib cfile)
target_link_options(lbmcomp PRIVATE option stack=150k)
