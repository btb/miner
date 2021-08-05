@echo off

rem where are tools installed
set _DJGPP=M:\DJGPP
set _MASM=M:\MASM611
set _WATCOM=M:\WATCOM

rem where is source code
set MINER=M:/MINER

rem make options
set SHOW_REASONS=1
set SHOW_FLAGS=1


rem Set up DJGPP
set DJGPP=%_DJGPP%\DJGPP.ENV
set PATH=%_DJGPP%\BIN;%PATH%

rem Set up MASM
SET PATH=%_MASM%\BIN;%_MASM%\BINR;%PATH%
SET INCLUDE=%_MASM%\INCLUDE;%INCLUDE%
SET TMP=C:\WINDOWS\TEMP

rem Set up Watcom
path %_WATCOM%\bin;%_WATCOM%\binb;%PATH%
set INCLUDE=%_WATCOM%\h;%INCLUDE%
set WATCOM=%_WATCOM%\.

rem Clear temporary vars
set _DJGPP=
set _MASM=
set _WATCOM=
