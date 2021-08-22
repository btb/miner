export _WATCOM=/usr/local/opt/open-watcom-v2
# where is source code
export MINER=~/MinerProj/miner

# set toolchain
export COMPILER=WATCOM
export ASSEMBLER=JWASM
export INSTALL="install -C -v"

# make options
export SHOW_REASONS=1
export SHOW_FLAGS=1

# debug
# export CFLAGS_DEBUG="-wx -we"
# export AFLAGS_DEBUG="-W4 -WX"

# print full path in errors
export GLOBAL_CFLAGS="-ef"

# Set up Watcom
export PATH=$_WATCOM/osx64:$PATH
export INCLUDE=$_WATCOM/h:$INCLUDE
export WATCOM=$_WATCOM/.

# Clear temporary vars
unset _WATCOM
