#include "String.h"



ClassNew(String)






Bool String_Init(Object this)
{
    return true;
}




Bool String_Final(Object this)
{
    return true;
}





Int String_GetLength(Object this)
{
    String* m = CastPointer(this);


    return m->Length;
}



Bool String_SetLength(Object this, Int value)
{
    String* m = CastPointer(this);


    m->Length = value;


    return true;
}





Int String_GetData(Object this)
{
    String* m = CastPointer(this);



    return (Int)m->Data;
}




Bool String_SetData(Object this, Int value)
{
    String* m = CastPointer(this);



    m->Data = (Char*)value;


    return true;
}





Int String_Char(Object this, Int index)
{
    String* m = CastPointer(this);



    return m->Data[index];
}




Bool String_Equal(Object this, Object other)
{
    String* m = CastPointer(this);



    String* d = CastPointer(other);




    Bool ba = (m->Length == d->Length);



    if (!ba)
    {
        return false;
    }




    Char* mf = m->Data;



    Char* df = d->Data;




    Int count = m->Length;


    Int i = 0;


    while (i < count)
    {
        if (mf[i] != df[i])
        {
            return false;
        }


        i++;
    }




    return true;
}






Int String_ConstantLength(Int o)
{
    Char* p = (Char*)o;
    


    Int k = 0;



    while ((*p) != '\0')
    {
        k++;


        ++p;
    }


    return k;
}






Bool String_Copy(Object this, Int data, Int index, Int length)
{
    String* m = CastPointer(this);




    Int count = length;



    Int i = 0;




    Int j = 0;




    Char* resultData = m->Data;



    Char* sourceData = (Char*)data;




    while (i < count)
    {
        j = index + i;



        resultData[j] = sourceData[i];



        i++;
    }


    return true;
}