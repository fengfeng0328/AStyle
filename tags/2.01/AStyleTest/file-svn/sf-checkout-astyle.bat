@echo off
REM checkout the files to a working copy

REM do NOT use backslashes in the file:/// statement
REM do NOT use %USERPROFILE% becaue of the backslashes
set repos=https://astyle.svn.sourceforge.net/svnroot/astyle
set svndir=%repos%/trunk
set projdir=%USERPROFILE%\Projects


if exist  "%projdir%/AStyle" (
echo -
echo AStyle already checked out
pause
exit 100
)

REM do NOT use backslashes in the file:/// statement
echo -
echo --------------------------
echo checkout AStyle
echo --------------------------
svn  checkout  "%svndir%/AStyle"  "%projdir%/AStyle"


echo -
echo -
echo * * * * *  end of checkout * * * * *
pause
