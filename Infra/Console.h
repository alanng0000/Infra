#pragma once



#include "Local.h"



typedef struct
{
    Bool A;

} Console;



Bool Console_WriteFile(Console* this, Object text, Int o);