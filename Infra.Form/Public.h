#pragma once



#include <Infra/Public.h>





#ifdef Infra_Form_Module
#define Infra_Form_Api __declspec(dllexport)
#else
#define Infra_Form_Api __declspec(dllimport)
#endif




InfraObjectApi(Infra_Form, Frame)





Infra_Form_Api
Object Frame_GetTitle(Object o);




Infra_Form_Api
Bool Frame_SetTitle(Object o, Object value);






Infra_Form_Api
Bool Frame_GetVisible(Object o);





Infra_Form_Api
Bool Frame_SetVisible(Object o, Bool value);







typedef Bool (*Frame_ControlHandle_Method)(Object frame, Int key, Int value);





typedef Bool (*Frame_DrawHandle_Method)(Object frame, Int handle, Object arg);





Infra_Form_Api
Int Frame_GetControlHandle(Object o);




Infra_Form_Api
Bool Frame_SetControlHandle(Object o, Int value);






Infra_Form_Api
Int Frame_GetDrawHandle(Object o);




Infra_Form_Api
Bool Frame_SetDrawHandle(Object o, Int value);





Infra_Form_Api
Object Frame_GetDrawHandleArg(Object o);




Infra_Form_Api
Bool Frame_SetDrawHandleArg(Object o, Object value);






Infra_Form_Api
Object Frame_GetSize(Object o);






Infra_Form_Api
Bool Frame_Execute(Object o);





Infra_Form_Api
Bool Frame_Close(Object o);






Infra_Form_Api
Bool Frame_Update(Object o);







InfraObjectApi(Infra_Form, Time)





Infra_Form_Api
Int Time_GetTick(Object o);




Infra_Form_Api
Bool Time_SetTick(Object o, Int value);




Infra_Form_Api
Bool Time_Current(Object o);




Infra_Form_Api
Bool Time_AddTime(Object o, Object time);




Infra_Form_Api
Bool Time_SubTime(Object o, Object time);




Infra_Form_Api
Bool Time_Date(Object o, Object date);





InfraObjectApi(Infra_Form, Interval)





Infra_Form_Api
Int Interval_GetTime(Object o);



Infra_Form_Api
Bool Interval_SetTime(Object o, Int value);





Infra_Form_Api
Object Interval_GetArg(Object o);




Infra_Form_Api
Bool Interval_SetArg(Object o, Object value);





typedef Bool (*Interval_ElapsedHandle_Method)(Object interval, Object arg);





Infra_Form_Api
Bool Internal_SetElapsedHandle(Object o, Interval_ElapsedHandle_Method value);




Infra_Form_Api
Bool Interval_Execute(Object o);




Infra_Form_Api
Bool Interval_Stop(Object o);




Infra_Form_Api
Bool Interval_Reset(Object o);






InfraObjectApi(Infra_Form, Date)






Infra_Form_Api
Int Date_GetYear(Object o);



Infra_Form_Api
Bool Date_SetYear(Object o, Int value);




Infra_Form_Api
Int Date_GetMonth(Object o);



Infra_Form_Api
Bool Date_SetMonth(Object o, Int value);




Infra_Form_Api
Int Date_GetDay(Object o);



Infra_Form_Api
Bool Date_SetDay(Object o, Int value);




Infra_Form_Api
Int Date_GetHour(Object o);



Infra_Form_Api
Bool Date_SetHour(Object o, Int value);




Infra_Form_Api
Int Date_GetMin(Object o);



Infra_Form_Api
Bool Date_SetMin(Object o, Int value);




Infra_Form_Api
Int Date_GetSec(Object o);



Infra_Form_Api
Bool Date_SetSec(Object o, Int value);




Infra_Form_Api
Int Date_GetMillisec(Object o);




Infra_Form_Api
Bool Date_SetMillisec(Object o, Int value);




Infra_Form_Api
Bool Date_Time(Object o, Object time);






InfraObjectApi(Infra_Form, Storage)






Infra_Form_Api
Object Storage_GetName(Object o);




Infra_Form_Api
Bool Storage_SetName(Object o, Object value);




Infra_Form_Api
Int Storage_GetMode(Object o);




Infra_Form_Api
Bool Storage_SetMode(Object o, Int value);




Infra_Form_Api
Bool Storage_CreateFile(Object o);




Infra_Form_Api
Bool Storage_DeleteFile(Object o);




Infra_Form_Api
Bool Storage_CreateFold(Object o);




Infra_Form_Api
Bool Storage_DeleteFold(Object o);




Infra_Form_Api
Bool Storage_Status(Object o);




Infra_Form_Api
Bool Storage_GetFold(Object o);




Infra_Form_Api
Int Storage_GetSize(Object o);




Infra_Form_Api
Bool Storage_Open(Object o);




Infra_Form_Api
Bool Storage_Close(Object o);





Infra_Form_Api
Int Storage_Read(Object o, Object data);




Infra_Form_Api
Int Storage_Write(Object o, Object data);




Infra_Form_Api
Bool Storage_Offset(Object o, Int offset, Int origin);






Infra_Form_Api
Bool Infra_Form_Init();




Infra_Form_Api
Bool Infra_Form_Final();