@echo off



SET MethodsFilePath=CreateMethods.cmd




SET OutFold=..\..\Out




SET Module=Infra


CALL %MethodsFilePath% :CreateModule "%Module%" "%Module%"




SET Module=Infra.Form.Infra


CALL %MethodsFilePath% :CreateModule "%Module%" "%Module%" "%OutFold%\Infra.lib"




CALL :CreateForm



SET Module=Infra.Form.Windows


CALL %MethodsFilePath% :CreateModule "%Module%" "%Module%" "%OutFold%\Infra.lib %OutFold%\Infra.Form.Infra.lib Kernel32.lib User32.lib Gdi32.lib Synchronization.lib"




SET Module=Infra.Exe


CALL %MethodsFilePath% :CreateModule "%Module%" "%Module%" "%OutFold%\Infra.lib %OutFold%\Infra.Form.Infra.lib %OutFold%\Infra.Form.Windows.lib" exe







goto :eof








:CreateForm
SETLOCAL


SET FormFoldName=Infra.Form


SET FormOutFoldPath=%OutFold%\%FormFoldName%


cd %FormFoldName%


CALL "..\%MethodsFilePath%" :CreateFold "%FormOutFoldPath%"


copy "Public.h" "%FormOutFoldPath%\Public.h" >nul


cd ..



ENDLOCAL & SET _result=
goto :eof