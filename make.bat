PATH=C:\mingw64\bin;C:\SDL2-2.24.0\x86_64-w64-mingw32\bin;C:\Users\icebe\AppData\Local\Programs\Python\Python310\
REM gcc -std=c99 -Wall -Wpedantic 2.1.c -IC:\SDL2-2.24.0\x86_64-w64-mingw32\include\SDL2 -LC:\SDL2-2.24.0\x86_64-w64-mingw32\lib -w -lmingw32 -lSDL2main -lSDL2
REM gcc -std=c99 -Wall -Wpedantic 2.2.c -IC:\lua-5.4.4\src C:\lua-5.4.4\src\liblua.a
REM gcc -std=c99 -Wall -Wpedantic pract2.10.c -shared -o libcode.dll
REM python pract2.10.py
REM gcc -std=c99 -Wall -Wpedantic port.c
REM a.exe
gcc -std=c99 -Wall -Wpedantic port.c
a.exe