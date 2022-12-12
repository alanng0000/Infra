#include "Rect.h"



ClassNew(Rect)




Bool Rect_Init(Object this)
{
    return true;
}




Bool Rect_Final(Object this)
{
    return true;
}





Object Rect_GetPos(Object this)
{
    Rect* m = CastPointer(this);


    return m->Pos;
}





Bool Rect_SetPos(Object this, Object value)
{
    Rect* m = CastPointer(this);



    m->Pos = value;



    return true;
}





Object Rect_GetSize(Object this)
{
    Rect* m = CastPointer(this);


    return m->Size;
}





Bool Rect_SetSize(Object this, Object value)
{
    Rect* m = CastPointer(this);



    m->Size = value;



    return true;
}