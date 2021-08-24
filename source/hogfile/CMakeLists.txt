#
# Master makefile for Miner source
#
# Makes all the executable by visiting subdirs and making there
#

add_executable(hogfile)

target_sources(hogfile PRIVATE hogfile.c )
