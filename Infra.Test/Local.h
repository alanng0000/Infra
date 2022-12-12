#pragma once



#include "Public.h"






#define ClassNew(c) Object c##_New()\
{\
    Int size = sizeof(c);\
\
\
    Object o = New(size);\
\
\
    Object ret = o;\
\
\
    return ret;\
}\




Object TestStorage_New();




Bool TestStorage_Init(Object this);



Bool TestStorage_Final(Object this);




Object TestStorage_GetName(Object this);




Bool TestStorage_Execute(Object this);