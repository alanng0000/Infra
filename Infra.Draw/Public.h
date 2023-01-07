#pragma once




#include <Infra/Public.h>




#ifdef Infra_Draw_Module
#define Infra_Draw_Api __declspec(dllexport)
#else
#define Infra_Draw_Api __declspec(dllimport)
#endif





InfraObjectApi(Infra_Draw, Draw)




Infra_Draw_Api
Object Draw_Color(Object this, Int color, Object rect);
