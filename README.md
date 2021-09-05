# miner

## what is this?
It's a silly project to revive a "canonical" version of Descent from the original source.
The original D1 source readme states that it was built with Watcom 9.5 and MASM 6.11.
Getting a system set up with those tools isn't easy in this day and age, but once you do, it will build with no changes to the source at all.
All of the changes subsequently made should fully preserve the Watcom/DOS build and any other "original" builds I can reproduce.

### Tasks

Minor changes to undo the last-minute hacks done by Kevin Bentley specifically for the OG source release.
- [x] Sound support via SOS
- [x] Serial support via Greenleaf CommLib
- [ ] IPX networking
- [x] Debugging functions

Changes/Code merges to Reproduce other builds
- [ ] D1 for Macintosh (What toolchain?)
- [ ] Shareware / OEM
- [ ] D2

Use "modern" toolchains (still targeting DOS)
- [x] GNU Make
- [x] CMake
- [x] Open Watcom
- [x] Open Watcom v2
- [x] JWasm

Port to modern systems with native compilers
- [ ] SDL
- [ ] GCC
- [ ] Clang
