#include "Memory.h"






InfraClassNew(Memory)






Bool Memory_Init(Object this)
{
    return true;
}




Bool Memory_Final(Object this)
{
    return true;
}




Int Memory_GetData(Object this)
{
    Memory* m = CastPointer(this);


    return (Int)m->Data;
}




Bool Memory_SetData(Object this, Int value)
{
    Memory* m = CastPointer(this);


    m->Data = (Byte*)value;


    return true;
}





Int Memory_GetByte(Object this, Int index)
{
    Memory* m = CastPointer(this);



    return m->Data[index];
}




Bool Memory_SetByte(Object this, Int index, Int value)
{
    Memory* m = CastPointer(this);



    m->Data[index] = (Byte)value;



    return true;
}






Int Memory_GetInt(Object this, Int index)
{
    Memory* m = CastPointer(this);



    Int* p = (Int*)(m->Data);



    return p[index];
}






Bool Memory_SetInt(Object this, Int index, Int value)
{
    Memory* m = CastPointer(this);




    Int* p = (Int*)(m->Data);




    p[index] = value;



    return true;
}





Int Memory_Alloc(Object this, Int size)
{
    return New(size);
}




Bool Memory_Free(Object this, Int o)
{
    return Delete(o);
}





Bool Memory_Copy(Object this, Int dest, Int source, Int count)
{
    return Copy(dest, source, count);
}








Int Memory_M_K;





Int New(Int size)
{
    if (size == 0)
    {
        void* d = &Memory_M_K;


        return (Int)d;
    }
    



    void* p = calloc(1, size);


    return (Int)p;
}




Bool Delete(Int o)
{
    Object k = o;



    if (k == null)
    {
        return true;
    }
    



    Int f = CastInt(&Memory_M_K);


    if (k == f)
    {
        return true;
    }




    void* p = CastPointer(k);



    free(p);



    return true;
}






Int CastInt(void* o)
{
    return (Int)o;
}



void* CastPointer(Int o)
{
    return (void*)o;
}





Bool Copy(Int dest, Int source, Int count)
{
    void* pa = (void*)dest;


    void* pb = (void*)source;


    size_t n = count;



    memcpy(pa, pb, n);



    return true;
}


