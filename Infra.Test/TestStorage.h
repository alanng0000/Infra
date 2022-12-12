#pragma once



#include "Local.h"



typedef struct
{
    Object Name;

} TestStorage;




Bool TestStorage_StorageStringSet(Object string, char* charArray);




Bool TestStorage_DataEqual(Byte* left, Byte* right, Int size);