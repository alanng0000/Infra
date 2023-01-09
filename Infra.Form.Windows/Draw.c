#include "Draw.h"




InfraClassNew(Draw)





Bool Draw_Init(Object this)
{
    Object size;



    size = Size_New();



    Size_Init(size);



    Draw_SetSize(this, size);



    return true;
}




Bool Draw_Final(Object this)
{
    Object size;


    size = Draw_GetSize(this);



    Size_Final(size);


    Size_Delete(size);



    return true;
}






Object Draw_GetSize(Object this)
{
    Draw* m;

    m = CastPointer(this);


    return m->Size;
}




Bool Draw_SetSize(Object this, Object value)
{
    Draw* m;

    m = CastPointer(this);



    m->Size = value;



    return true;
}






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






Bool Draw_SelectFont(Object this, Int font)
{
    Draw* m;

    m = CastPointer(this);


    
    HDC u;

    u = m->Hdc;
    



    HGDIOBJ uu;

    uu = (HGDIOBJ)font;




    Windows_SelectObject(u, uu);



    return true;
}