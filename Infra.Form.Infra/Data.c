#include "Data.h"




InfraClassNew(Data)





Bool Data_Init(Object this)
{
    return true;
}




Bool Data_Final(Object this)
{
    return true;
}





Int Data_GetSize(Object this)
{
    Data* m = CastPointer(this);


    return m->Size;
}





Bool Data_SetSize(Object this, Int value)
{
    Data* m = CastPointer(this);



    m->Size = value;



    return true;
}





Int Data_GetValue(Object this)
{
    Data* m = CastPointer(this);


    return (Int)m->Value;
}





Bool Data_SetValue(Object this, Int value)
{
    Data* m = CastPointer(this);



    m->Value = (Byte*)value;



    return true;
}