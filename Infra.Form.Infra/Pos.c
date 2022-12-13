#include "Pos.h"



InfraClassNew(Pos)




Bool Pos_Init(Object this)
{
    return true;
}




Bool Pos_Final(Object this)
{
    return true;
}




Int Pos_GetLeft(Object this)
{
    Pos* m = CastPointer(this);


    return m->Left;
}





Bool Pos_SetLeft(Object this, Int value)
{
    Pos* m = CastPointer(this);



    m->Left = value;



    return true;
}





Int Pos_GetUp(Object this)
{
    Pos* m = CastPointer(this);


    return m->Up;
}





Bool Pos_SetUp(Object this, Int value)
{
    Pos* m = CastPointer(this);



    m->Up = value;



    return true;
}