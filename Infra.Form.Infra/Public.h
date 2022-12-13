#pragma once




#include <Infra/Public.h>




#ifdef Infra_Form_Infra_Module
#define Infra_Form_Infra_Api __declspec(dllexport)
#else
#define Infra_Form_Infra_Api __declspec(dllimport)
#endif





InfraObjectApi(Infra_Form_Infra, Rect)




Infra_Form_Infra_Api
Object Rect_GetPos(Object this);




Infra_Form_Infra_Api
Bool Rect_SetPos(Object this, Object value);




Infra_Form_Infra_Api
Object Rect_GetSize(Object this);




Infra_Form_Infra_Api
Bool Rect_SetSize(Object this, Object value);







InfraObjectApi(Infra_Form_Infra, Pos)





Infra_Form_Infra_Api
Int Pos_GetLeft(Object this);




Infra_Form_Infra_Api
Bool Pos_SetLeft(Object this, Int value);




Infra_Form_Infra_Api
Int Pos_GetUp(Object this);




Infra_Form_Infra_Api
Bool Pos_SetUp(Object this, Int value);





InfraObjectApi(Infra_Form_Infra, Size)





Infra_Form_Infra_Api
Int Size_GetWidth(Object this);




Infra_Form_Infra_Api
Bool Size_SetWidth(Object this, Int value);




Infra_Form_Infra_Api
Int Size_GetHeight(Object this);




Infra_Form_Infra_Api
Bool Size_SetHeight(Object this, Int value);





InfraObjectApi(Infra_Form_Infra, Data)




Infra_Form_Infra_Api
Int Data_GetSize(Object this);




Infra_Form_Infra_Api
Bool Data_SetSize(Object this, Int value);




Infra_Form_Infra_Api
Int Data_GetValue(Object this);




Infra_Form_Infra_Api
Bool Data_SetValue(Object this, Int value);