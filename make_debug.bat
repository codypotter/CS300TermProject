@echo off

mkdir build
pushd build
cls
cl /Zi /EHsc /WX /RTC -I..\include ..\main.cpp ..\*.cpp ..\libs\*.lib msvcrt.lib shell32.lib user32.lib gdi32.lib
popd
