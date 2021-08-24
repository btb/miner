call m:\owatcom2\owsetenv.bat
call m:\masm611\binr\new-vars.bat
cmake -S . -B build -G "Watcom WMake"
