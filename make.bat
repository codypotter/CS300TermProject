@echo off

mkdir build
pushd build
cls
cl /EHsc /WX -I..\include ..\main.cpp ..\*.cpp ..\libs\*.lib msvcrt.lib shell32.lib user32.lib gdi32.lib
popd
