#pragma once



#include <Infra.h>




#ifdef Infra_Test_Module
#define Infra_Test_Api __declspec(dllexport)
#else
#define Infra_Test_Api __declspec(dllimport)
#endif




Infra_Test_Api
Object Test_New();



Infra_Test_Api
Bool Test_Init(Object this);



Infra_Test_Api
Bool Test_Final(Object this);




Infra_Test_Api
Bool Test_Execute(Object this);