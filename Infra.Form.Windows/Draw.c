#include "Draw.h"




InfraClassNew(Draw)







Int Draw_GetHandle(Object this)
{
    Draw* m;

    m = CastPointer(this);



    Int o;

    o = CastInt(m->Hdc);


    return o;
}





Bool Draw_SetHandle(Object this, Int value)
{
    Draw* m;

    m = CastPointer(this);



    HDC o;

    o = (HDC)value;



    m->Hdc = o;



    return true;
}