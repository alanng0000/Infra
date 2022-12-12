@echo off

CALL %*
goto :eof



:CreateModule
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



CALL :CreateFold "%OutFoldPath%\%Module%"



cl *.c /D %DefineModuleName%_Module /Fo%OutFoldPath%\%Module%\ /Fe: %OutFoldPath%\%BinaryName% /I %OutFoldPath% /W3 /O2 /link %Imports% %DllFlag%



copy Public.h %OutFoldPath%\%Module%\Public.h >nul



cd ..


ENDLOCAL & SET _result=
goto :eof





:CreateFold
SETLOCAL
SET CreateFoldPath=%~1


if not exist "%CreateFoldPath%" mkdir "%CreateFoldPath%"


ENDLOCAL & SET _result=
goto :eof