@echo off

set testdata=..\..\TestData

:: set astyle=..\..\AStyle\build\cb-borland\bin\AStyle
:: set astyle=..\..\AStyle\build\cb-dmars\bin\AStyle
:: set astyle=..\..\AStyle\build\cb-mingw\bin\AStyle
:: set astyle=..\..\AStyle\build\vs2003\bin\AStyle
:: set astyle=..\..\AStyle\build\vs2005\bin\AStyle
set astyle=..\..\AStyle\build\vs2008\debug\AStyled

set excludes= --exclude=app_templates

:: set options= -vRQ
REM indent-brackets (B), add-brackets (j), break-blocks=all (F), align-pointer=type (k1)
set options= -CSKBNLwM50m10yejoOcFpPHUxEk3 -vRQ
REM indent-blocks (G), add-one-line-brackets (J), break-blocks (f), align-pointer=middle (k2)
:: set options= -CSKGNLwM50m10yeJoOcfpPHUxEk2 -vRQ


call  libCompile.bat  %astyle%
echo Formatting KDevelop %options%

%astyle%  %options%  %excludes%  "%testdata%\kdevelop\*.cpp"  "%testdata%\kdevelop\*.h"  > test.txt


echo -
pause
