@echo off



SET MethodsFilePath=MakeMethods.cmd




SET OutFold=..\..\Out




SET Module=Infra


CALL %MethodsFilePath% :MakeModule "%Module%" "%Module%"




SET Module=Infra.Form.Infra


CALL %MethodsFilePath% :MakeModule "%Module%" "%Module%" "%OutFold%\Infra.lib"




CALL :MakeForm



SET Module=Infra.Form.Windows


CALL %MethodsFilePath% :MakeModule "%Module%" "%Module%" "%OutFold%\Infra.lib %OutFold%\Infra.Form.Infra.lib Kernel32.lib User32.lib Gdi32.lib Synchronization.lib"




SET Module=Infra.Exe


CALL %MethodsFilePath% :MakeModule "%Module%" "%Module%" "%OutFold%\Infra.lib %OutFold%\Infra.Form.Infra.lib %OutFold%\Infra.Form.Windows.lib" exe






REM SET Module=Infra.Test


REM CALL %MethodsFilePath% :MakeModule "%Module%" "%Module%" "%OutFold%\Infra.lib %OutFold%\Infra.Form.Infra.lib %OutFold%\Infra.Form.Windows.lib"





REM SET Module=Infra.Test.Exe


REM CALL %MethodsFilePath% :MakeModule "%Module%" "%Module%" "%OutFold%\Infra.Test.lib %OutFold%\Infra.lib %OutFold%\Infra.Form.Infra.lib %OutFold%\Infra.Form.Windows.lib" exe





goto :eof








:MakeForm
SETLOCAL


SET FormFoldName=Infra.Form


SET FormOutFoldPath=%OutFold%\%FormFoldName%


cd %FormFoldName%


CALL "..\%MethodsFilePath%" :MakeFold "%FormOutFoldPath%"


copy "Public.h" "%FormOutFoldPath%\Public.h" >nul


cd ..



ENDLOCAL & SET _result=
goto :eof