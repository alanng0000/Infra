#include "Size.h"



ClassNew(Size)




Bool Size_Init(Object this)
{
    return true;
}




Bool Size_Final(Object this)
{
    return true;
}




Int Size_GetWidth(Object this)
{
    Size* m = CastPointer(this);


    return m->Width;
}





Bool Size_SetWidth(Object this, Int value)
{
    Size* m = CastPointer(this);



    m->Width = value;



    return true;
}





Int Size_GetHeight(Object this)
{
    Size* m = CastPointer(this);


    return m->Height;
}





Bool Size_SetHeight(Object this, Int value)
{
    Size* m = CastPointer(this);



    m->Height = value;



    return true;
}