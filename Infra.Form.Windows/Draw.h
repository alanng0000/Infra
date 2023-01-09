#pragma once



#include "WindowsLocal.h"



#include "Local.h"




typedef struct
{
    HDC Hdc;

    Object Size;
}
Draw;





Bool Draw_SetSize(Object this, Object value);