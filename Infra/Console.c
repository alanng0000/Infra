#include <stdio.h>

#include "Console.h"



InfraClassNew(Console)




Bool Console_Init(Object this)
{
    return true;
}




Bool Console_Final(Object this)
{
    return true;
}





Bool Console_Write(Object this, Object text)
{
    Console* m = CastPointer(this);



    Int o = (Int)stdout;



    Console_WriteFile(m, text, o);



    return true;
}






Bool Console_WriteFile(Console* this, Object text, Int o)
{
    Int data = String_GetData(text);


    Int length = String_GetLength(text);



    Char* d = (Char*)data;




    FILE* stream = (FILE*)o;



    fwrite(d, sizeof(Char), length, stream);



    fflush(stream);
    



    return true;
}