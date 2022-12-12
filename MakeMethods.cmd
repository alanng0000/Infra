@echo off

CALL %*
goto :eof



:MakeModule
SETLOCAL
SET Module=%~1
SET Fold=%~2
SET Imports=%~3
SET Exe=%~4


SET DefineModuleName=%Module:.=_%


SET OutFoldPath=..\..\Out



SET DllFlag=/dll

SET BinaryName=%Module%.dll



IF "%Exe%" == "" GOTO EndExeSet

SET DllFlag=

SET BinaryName=%Module%.dll.exe


:EndExeSet




cd "%Fold%"



CALL :MakeFold "%OutFoldPath%\%Module%"



cl *.c /D %DefineModuleName%_Module /Fo%OutFoldPath%\%Module%\ /Fe: %OutFoldPath%\%BinaryName% /I %OutFoldPath% /W3 /O2 /link %Imports% %DllFlag%



copy Public.h %OutFoldPath%\%Module%\Public.h >nul



cd ..


ENDLOCAL & SET _result=
goto :eof





:MakeFold
SETLOCAL
SET MakeFoldPath=%~1


if not exist "%MakeFoldPath%" mkdir "%MakeFoldPath%"


ENDLOCAL & SET _result=
goto :eof