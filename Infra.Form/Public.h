#pragma once



#include <Infra/Public.h>





#ifdef Infra_Form_Module
#define Infra_Form_Api __declspec(dllexport)
#else
#define Infra_Form_Api __declspec(dllimport)
#endif





Infra_Form_Api
Object Frame_New();




Infra_Form_Api
Bool Frame_Delete(Object o);




Infra_Form_Api
Object Frame_GetTitle(Object this);




Infra_Form_Api
Bool Frame_SetTitle(Object this, Object value);




Infra_Form_Api
Bool Frame_Init(Object this);




Infra_Form_Api
Bool Frame_Final(Object this);





Infra_Form_Api
Bool Frame_GetVisible(Object this);





Infra_Form_Api
Bool Frame_SetVisible(Object this, Bool value);







typedef Bool (*Frame_ControlHandle_Method)(Object frame, Int key, Int value);





Infra_Form_Api
Bool Frame_SetControlHandle(Object this, Frame_ControlHandle_Method value);





Infra_Form_Api
Object Frame_GetSize(Object this);





Infra_Form_Api
Int32* Frame_LockPixels(Object this, Object rect);





Infra_Form_Api
Bool Frame_UnlockPixels(Object this);





Infra_Form_Api
Bool Frame_Execute(Object this);





Infra_Form_Api
Bool Frame_Close(Object this);






Infra_Form_Api
Object Time_New();





Infra_Form_Api
Bool Time_Delete(Object o);




Infra_Form_Api
Bool Time_Init(Object this);




Infra_Form_Api
Bool Time_Final(Object this);




Infra_Form_Api
Int Time_GetTick(Object this);




Infra_Form_Api
Bool Time_SetTick(Object this, Int value);




Infra_Form_Api
Bool Time_Current(Object this);




Infra_Form_Api
Bool Time_AddTime(Object this, Object time);




Infra_Form_Api
Bool Time_SubTime(Object this, Object time);




Infra_Form_Api
Bool Time_Date(Object this, Object date);





Infra_Form_Api
Object Interval_New();



Infra_Form_Api
Bool Interval_Delete(Object o);



Infra_Form_Api
Bool Interval_Init(Object this);




Infra_Form_Api
Int Interval_GetTime(Object this);



Infra_Form_Api
Bool Interval_SetTime(Object this, Int value);





Infra_Form_Api
Object Interval_GetArg(Object this);




Infra_Form_Api
Bool Interval_SetArg(Object this, Object value);





typedef Bool (*Interval_ElapsedHandle_Method)(Object interval, Object arg);





Infra_Form_Api
Bool Internal_SetElapsedHandle(Object this, Interval_ElapsedHandle_Method value);




Infra_Form_Api
Bool Interval_Execute(Object this);




Infra_Form_Api
Bool Interval_Stop(Object this);




Infra_Form_Api
Bool Interval_Reset(Object this);





Infra_Form_Api
Object Date_New();




Infra_Form_Api
Bool Date_Delete(Object o);




Infra_Form_Api
Bool Date_Init(Object this);




Infra_Form_Api
Bool Date_Final(Object this);




Infra_Form_Api
Int Date_GetYear(Object this);



Infra_Form_Api
Bool Date_SetYear(Object this, Int value);




Infra_Form_Api
Int Date_GetMonth(Object this);



Infra_Form_Api
Bool Date_SetMonth(Object this, Int value);




Infra_Form_Api
Int Date_GetDay(Object this);



Infra_Form_Api
Bool Date_SetDay(Object this, Int value);




Infra_Form_Api
Int Date_GetHour(Object this);



Infra_Form_Api
Bool Date_SetHour(Object this, Int value);




Infra_Form_Api
Int Date_GetMinute(Object this);



Infra_Form_Api
Bool Date_SetMinute(Object this, Int value);




Infra_Form_Api
Int Date_GetSecond(Object this);



Infra_Form_Api
Bool Date_SetSecond(Object this, Int value);




Infra_Form_Api
Int Date_GetMillisecond(Object this);




Infra_Form_Api
Bool Date_SetMillisecond(Object this, Int value);




Infra_Form_Api
Bool Date_Time(Object this, Object time);





Infra_Form_Api
Object Storage_New();




Infra_Form_Api
Bool Storage_Delete(Object o);




Infra_Form_Api
Bool Storage_Init(Object this);




Infra_Form_Api
Bool Storage_Final(Object this);





Infra_Form_Api
Object Storage_GetName(Object this);




Infra_Form_Api
Bool Storage_SetName(Object this, Object value);




Infra_Form_Api
Int Storage_GetMode(Object this);




Infra_Form_Api
Bool Storage_SetMode(Object this, Int value);




Infra_Form_Api
Bool Storage_CreateFile(Object this);




Infra_Form_Api
Bool Storage_DeleteFile(Object this);




Infra_Form_Api
Bool Storage_CreateFold(Object this);




Infra_Form_Api
Bool Storage_DeleteFold(Object this);




Infra_Form_Api
Bool Storage_Status(Object this);




Infra_Form_Api
Bool Storage_GetFold(Object this);




Infra_Form_Api
Int Storage_GetSize(Object this);




Infra_Form_Api
Bool Storage_Open(Object this);




Infra_Form_Api
Bool Storage_Close(Object this);





Infra_Form_Api
Bool Storage_Read(Object this, Object data);




Infra_Form_Api
Bool Storage_Write(Object this, Object data);




Infra_Form_Api
Bool Storage_Offset(Object this, Int offset, Int origin);






Infra_Form_Api
Bool Infra_Form_Init();




Infra_Form_Api
Bool Infra_Form_Final();