@echo off

:: set progdir=%astyledir%\build\cb-borland\bin\AStyled
:: set progdir=%astyledir%\build\cb-dmars\bin\AStyled
:: set progdir=%astyledir%\build\cb-mingw\bin\AStyled
:: set progdir=%astyledir%\build\vs2003\bin\AStyled
:: set progdir=%astyledir%\build\vs2005\bin\AStyled
set astyle=..\..\AStyle\build\vs2010\debug\AStyled


:: call  libCompile.bat  %astyle%
%astyle%  -h


echo -
pause
