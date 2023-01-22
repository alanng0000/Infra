@echo off

CALL %*
goto :eof



:MakeModule
SETLOCAL
SET Module=%~1
SET Fold=%~2
SET Imports=%~3
SET Cpp=%~4
SET Exe=%~5


SET DefineModuleName=%Module:.=_%


SET OutFoldPath=..\..\..\Out



SET DllFlag=/dll

SET BinaryName=%Module%.dll


SET Ext=c




IF "%Cpp%" == "" GOTO EndCppSet

SET Ext=cpp

:EndCppSet



IF "%Exe%" == "" GOTO EndExeSet

SET DllFlag=

SET BinaryName=%Module%.dll.exe


:EndExeSet




cd "%Fold%"



CALL :CreateFold "%OutFoldPath%\%Module%"



cl *.%Ext% /D %DefineModuleName%_Module /Fo%OutFoldPath%\%Module%\ /Fe: %OutFoldPath%\%BinaryName% /I %OutFoldPath% /W3 /O2 /link %Imports% %DllFlag%



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