@echo off
set arg1=%1
rem echo build file: %arg1%\build.txt
set /p var= <%arg1%\build.txt
set /a var= %var%+1
echo %var% >%arg1%\build.txt
rem echo #define BUILD %var% >build.h
rem echo %var%
