@echo off
REM create the web documentation branch from the current trunk
REM the old files will be removed if necessary

REM do NOT use backslashes in the file:/// statement
REM do NOT use %USERPROFILE% becaue of the backslashes
set repos=https://astyle.svn.sourceforge.net/svnroot/astyle
set svndir=%repos%/branches

REM do NOT use backslashes in the file:/// statement

echo -
echo --------------------------
echo deleting old AStyleWeb/doc
echo --------------------------
svn delete 	"%svndir%/AStyleWeb/doc"  -m "Delete directory." 
if errorlevel 1 (
REM must create AStyleWeb if it doesn't exist
echo -
echo --------------------------
echo creating AStyleWeb
echo --------------------------
svn  mkdir  "%svndir%/AStyleWeb"   -m "Create directory."
)

echo -
echo --------------------------
echo copying AStyleWeb/doc
echo --------------------------
svn  copy  "%repos%/trunk/AStyle/doc"  "%svndir%/AStyleWeb/doc"  -m "Copy AStyle files."


echo -
echo -
echo * * * * *  end of create branch  * * * * *
pause
