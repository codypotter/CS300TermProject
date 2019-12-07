@echo off

cls
cl /EHsc /WX -Iinclude main.cpp *.cpp libs\*.cpp msvcrt.lib shell32.lib user32.lib gdi32.lib
del *.obj
del ChocAn.exe
ren main.exe ChocAn.exe