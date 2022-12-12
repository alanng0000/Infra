#include "Storage.h"



ClassNew(Storage)





Bool Storage_Init(Object this)
{
    Storage* m = CastPointer(this);



    Int size = sizeof(StorageStat);



    void* o = CastPointer(New(size));



    StorageStat* p = o;



    m->Status = p;
    


    return true;
}




Bool Storage_Final(Object this)
{
    Storage* m = CastPointer(this);



    Delete(CastInt(m->Status));



    return true;
}




Object Storage_GetName(Object this)
{
    Storage* m = CastPointer(this);


    return m->Name;
}




Bool Storage_SetName(Object this, Object value)
{
    Storage* m = CastPointer(this);


    m->Name = value;


    return true;
}





Int Storage_GetMode(Object this)
{
    Storage* m = CastPointer(this);


    return m->Mode;
}





Bool Storage_SetMode(Object this, Int value)
{
    Storage* m = CastPointer(this);


    m->Mode = value;


    return true;
}




#define StorageOpenModeCount 6




char* Storage_FOpenModes[StorageOpenModeCount] = 
{   
    "r",

    "w",

    "a",


    "r+",

    "w+",

    "a+"
};




Bool Storage_CreateFile(Object this)
{
    Int mode = Storage_GetMode(this);




    Storage_SetMode(this, 2);




    Bool ba = Storage_Open(this);


    if (!ba)
    {
        return false;
    }




    Bool bb = Storage_Close(this);


    if (!bb)
    {
        return false;
    }




    Storage_SetMode(this, mode);




    return true;
}




Bool Storage_DeleteFile(Object this)
{
    Storage* m = CastPointer(this);



    char* name = (char*)String_GetData(m->Name);



    int u = remove(name);



    Bool b = (u == 0);



    if (!b)
    {
        return false;
    }



    return true;
}




Bool Storage_CreateFold(Object this)
{
    Storage* m = CastPointer(this);



    char* name = (char*)String_GetData(m->Name);



    int u = _mkdir(name);



    Bool b = (u == 0);



    if (!b)
    {
        return false;
    }



    return true;
}




Bool Storage_DeleteFold(Object this)
{
    Storage* m = CastPointer(this);



    char* name = (char*)String_GetData(m->Name);



    int u = _rmdir(name);



    Bool b = (u == 0);



    if (!b)
    {
        return false;
    }



    return true;
}





Bool Storage_Status(Object this)
{
    Storage* m = CastPointer(this);



    char* name = (char*)String_GetData(m->Name);



    StorageStat* status = m->Status;



    int u = _stat64(name, status);



    Bool b = (u == 0);


    if (!b)
    {
        return false;
    }



    return true;
}





Bool Storage_GetFold(Object this)
{
    Storage* m = CastPointer(this);



    StorageStat* status = m->Status;



    unsigned short t = status->st_mode;



    unsigned short f = t & _S_IFDIR;



    Int k = f;



    Bool b = (k == 0);



    Bool bb = !b;



    Bool ret = bb;


    return ret;
}





Int Storage_GetSize(Object this)
{
    Storage* m = CastPointer(this);



    StorageStat* status = m->Status;



    __int64 t = status->st_size;



    if (t < 0)
    {
        return 0;
    }



    Int h = t;



    Int ret = h;



    return ret;
}






Bool Storage_Open(Object this)
{
    Storage* m = CastPointer(this);



    char* name = (char*)String_GetData(m->Name);



    Int mode = m->Mode;




    Bool ba = (mode < StorageOpenModeCount);



    if (!ba)
    {
        return false;
    }




    FILE* file = NULL;
    



    char* uMode = Storage_FOpenModes[mode];

    


    errno_t u = fopen_s(&file, name, uMode);





    Bool b = (u == 0 && file != NULL);




    if (!b)
    {
        return false;
    }




    m->File = file;



    return true;
}





Bool Storage_Close(Object this)
{
    Storage* m = CastPointer(this);




    FILE* file = m->File;




    int u = fclose(file);




    Bool b = (u == 0);



    if (!b)
    {
        return false;
    }




    m->File = NULL;
    



    return true;
}





Bool Storage_Flush(Object this)
{
    Storage* m = CastPointer(this);




    FILE* file = m->File;




    int u = fflush(file);




    Bool b = (u == 0);



    if (!b)
    {
        return false;
    }




    return true;
}





Bool Storage_Read(Object this, Object data)
{
    Storage* m = CastPointer(this);




    FILE* file = m->File;




    Int o = Data_GetValue(data);



    void* buffer = CastPointer(o);



    Int size = Data_GetSize(data);



    size_t u = fread(buffer, 1, size, file);



    Bool b = (u == size);



    if (!b)
    {
        return false;
    }



    return true;
}





Bool Storage_Write(Object this, Object data)
{
    Storage* m = CastPointer(this);




    FILE* file = m->File;



    Int o = Data_GetValue(data);



    void* buffer = CastPointer(o);



    Int size = Data_GetSize(data);
    


    size_t u = fwrite(buffer, 1, size, file);



    Bool b = (u == size);



    if (!b)
    {
        return false;
    }




    Storage_Flush(this);





    return true;
}





#define StorageSeekOriginCount 3



int Storage_FSeekOrigins[StorageSeekOriginCount] = { SEEK_CUR, SEEK_SET, SEEK_END };





Bool Storage_Offset(Object this, Int origin, Int offset)
{
    Storage* m = CastPointer(this);





    Bool ba = (origin < StorageSeekOriginCount);



    if (!ba)
    {
        return false;
    }




    __int64 uW = offset;

    

    if (uW < 0)
    {
        return false;
    }





    FILE* file = m->File;





    int uOrigin = Storage_FSeekOrigins[origin];




    __int64 uOffset = uW;





    int u = _fseeki64(file, uOffset, uOrigin);




    Bool b = (u == 0);



    if (!b)
    {
        return false;
    }



    return true;
}