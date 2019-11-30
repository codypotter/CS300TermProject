@echo off

mkdir build
pushd build
cls
cl /EHsc ..\main.cpp ..\..\*.cpp -I..\..\include ..\..\libs\*.cpp
popd
