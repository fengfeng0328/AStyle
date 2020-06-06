@REM formats the astyle source code
@echo off

set progdir=C:\Program Files\AStyle
set options=--options=..\..\AStyle\file\astyle.ini

echo Formatting AStyle
echo.

"%progdir%\AStyle"  %options%  -Q  ..\..\AStyle\src\*.cpp
echo.
"%progdir%\AStyle"  %options%  -Q  ..\..\AStyle\src\*.h
echo.

echo.
pause
