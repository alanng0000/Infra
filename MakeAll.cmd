@echo off



SET MethodFilePath=MakeMethod.cmd



SET OutFoldName=Out



SET OutFold=..\..\..\%OutFoldName%




SET Module=Infra


CALL %MethodFilePath% :MakeModule "%Module%" "%Module%"




SET Module=Infra.Form.Infra


CALL %MethodFilePath% :MakeModule "%Module%" "%Module%" "%OutFold%\Infra.lib"




CALL :CreateForm



SET Module=Infra.Form.Windows


CALL %MethodFilePath% :MakeModule "%Module%" "%Module%" "%OutFold%\Infra.lib %OutFold%\Infra.Form.Infra.lib Kernel32.lib User32.lib Gdi32.lib Synchronization.lib"





CALL :CopyHeader





SET Module=Infra.Exe


CALL %MethodFilePath% :MakeModule "%Module%" "%Module%" "%OutFold%\Infra.lib %OutFold%\Infra.Form.Infra.lib %OutFold%\Infra.Form.Windows.lib" "" exe






goto :eof








:CreateForm
SETLOCAL


SET FormFoldName=Infra.Form


SET FormOutFoldPath=%OutFold%\%FormFoldName%


cd %FormFoldName%


CALL "..\%MethodFilePath%" :CreateFold "%FormOutFoldPath%"


copy "Public.h" "%FormOutFoldPath%\Public.h" >nul


cd ..



ENDLOCAL & SET _result=
goto :eof







:CopyHeader
SETLOCAL



copy "Infra.h" "..\..\%OutFoldName%\Infra.h" >nul



ENDLOCAL & SET _result=
goto :eof