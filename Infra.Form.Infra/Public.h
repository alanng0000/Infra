#pragma once




#include <Infra/Public.h>




#ifdef Infra_Form_Infra_Module
#define Infra_Form_Infra_Api ExportApi
#else
#define Infra_Form_Infra_Api ImportApi
#endif





InfraObjectApi(Infra_Form_Infra, Rect)




Infra_Form_Infra_Api
Object Rect_GetPos(Object o);




Infra_Form_Infra_Api
Bool Rect_SetPos(Object o, Object value);




Infra_Form_Infra_Api
Object Rect_GetSize(Object o);




Infra_Form_Infra_Api
Bool Rect_SetSize(Object o, Object value);







InfraObjectApi(Infra_Form_Infra, Pos)





Infra_Form_Infra_Api
Int Pos_GetLeft(Object o);




Infra_Form_Infra_Api
Bool Pos_SetLeft(Object o, Int value);




Infra_Form_Infra_Api
Int Pos_GetUp(Object o);




Infra_Form_Infra_Api
Bool Pos_SetUp(Object o, Int value);





InfraObjectApi(Infra_Form_Infra, Size)





Infra_Form_Infra_Api
Int Size_GetWidth(Object o);




Infra_Form_Infra_Api
Bool Size_SetWidth(Object o, Int value);




Infra_Form_Infra_Api
Int Size_GetHeight(Object o);




Infra_Form_Infra_Api
Bool Size_SetHeight(Object o, Int value);





InfraObjectApi(Infra_Form_Infra, Data)




Infra_Form_Infra_Api
Int Data_GetSize(Object o);




Infra_Form_Infra_Api
Bool Data_SetSize(Object o, Int value);




Infra_Form_Infra_Api
Int Data_GetValue(Object o);




Infra_Form_Infra_Api
Bool Data_SetValue(Object o, Int value);