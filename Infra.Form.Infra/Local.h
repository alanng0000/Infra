#pragma once



#include "Public.h"





#define ClassNew(c) Object c##_New()\
{\
    Int size = sizeof(c);\
\
\
    Int o = New(size);\
\
\
    Object ret = o;\
\
\
    return ret;\
}\
\
\
Bool c##_Delete(Object o)\
{\
    Int k = o;\
\
\
    Delete(k);\
\
\
    return true;\
}\
