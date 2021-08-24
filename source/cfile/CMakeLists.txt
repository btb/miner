#
# Master makefile for Miner source
#
# Makes all the executable by visiting subdirs and making there
#

add_library(cfile)

target_sources(cfile PRIVATE cfile.c)
