#pragma once




#include "WindowsLocal.h"



#include <Infra/Public.h>




Bool Windows_ApiResultCheck(Bool cond, DWORD errorCode, Char* functionName);




Bool Windows_Error(Char* functionName, Int32 errorCode);