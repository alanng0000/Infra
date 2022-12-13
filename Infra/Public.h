#pragma once




#ifdef Infra_Module
#define Infra_Api __declspec(dllexport)
#else
#define Infra_Api __declspec(dllimport)
#endif






typedef unsigned char Byte;




typedef unsigned long long Bool;




typedef unsigned long long Int;





typedef unsigned char Char;




typedef unsigned long long Object;




typedef unsigned int Int32;





#define true (1)



#define false (0)





#ifndef null

#define null (0)

#else

#error null is defined by another include

#endif






#define Constants_IntByteCount (sizeof(Int))



#define Constants_Int32ByteCount (sizeof(Int32))



#define Constants_ByteHexDigitCount (2)






#define ObjectApi(api, class) api\
Object class##_New();\
\
api\
Bool class##_Delete(Object o);\
\
api\
Bool class##_Init(Object this);\
\
api\
Bool class##_Final(Object this);\
\





#define ClassNew(class) Object class##_New()\
{\
    Int size = sizeof(class);\
\
\
    Int o = New(size);\
\
\
    Object ret = o;\
\
\
    return ret;\
}\
\
\
Bool class##_Delete(Object o)\
{\
    Int k = o;\
\
\
    Delete(k);\
\
\
    return true;\
}\
\







Infra_Api
Int New(Int size);





Infra_Api
Bool Delete(Int o);






Infra_Api
Int CastInt(void* o);




Infra_Api
void* CastPointer(Int o);






Infra_Api
Bool Copy(Int dest, Int source, Int count);





Infra_Api
Bool Exit(Int code);






Infra_Api
Object String_New();





Infra_Api
Bool String_Delete(Object o);





Infra_Api
Bool String_Init(Object this);





Infra_Api
Bool String_Final(Object this);





Infra_Api
Int String_GetLength(Object this);




Infra_Api
Bool String_SetLength(Object this, Int value);





Infra_Api
Int String_GetData(Object this);




Infra_Api
Bool String_SetData(Object this, Int value);





Infra_Api
Int String_Char(Object this, Int index);




Infra_Api
Bool String_Equal(Object this, Object other);





Infra_Api
Int String_ConstantLength(Int o);





Infra_Api
Bool String_Copy(Object this, Int data, Int index, Int length);





Infra_Api
Object List_New();




Infra_Api
Bool List_Delete(Object o);




Infra_Api
Bool List_Init(Object this);




Infra_Api
Bool List_Final(Object this);




Infra_Api
Int List_GetCount(Object this);




Infra_Api
Object List_Add(Object this, Object item);




Infra_Api
Object List_Insert(Object this, Object key, Object item);




Infra_Api
Bool List_Remove(Object this, Object key);




Infra_Api
Bool List_Contain(Object this, Object key);





Infra_Api
Bool List_Clear(Object this);





Infra_Api
Object List_Get(Object this, Object key);




Infra_Api
Bool List_Set(Object this, Object key, Object value);




Infra_Api
Bool List_Iter(Object this, Object iter);





Infra_Api
Object ListIter_New();




Infra_Api
Bool ListIter_Delete(Object o);




Infra_Api
Bool ListIter_Init(Object this);




Infra_Api
Bool ListIter_Final(Object this);




Infra_Api
Bool ListIter_Next(Object this);




Infra_Api
Object ListIter_Value(Object this);





Infra_Api
Object Console_New();




Infra_Api
Bool Console_Delete(Object o);




Infra_Api
Bool Console_Init(Object this);




Infra_Api
Bool Console_Final(Object this);




Infra_Api
Bool Console_Write(Object this, Object text);





Infra_Api
Object Format_New();




Infra_Api
Bool Format_Delete(Object o);




Infra_Api
Bool Format_Init(Object this);





Infra_Api
Bool Format_Final(Object this);





Infra_Api
Int Format_IntLength(Object this, Int n);




Infra_Api
Bool Format_Int(Object this, Int result, Int n, Int length);





Infra_Api
Int Format_HexIntLength(Object this);




Infra_Api
Bool Format_HexInt(Object this, Int result, Int n);





Infra_Api
Int Format_HexInt32Length(Object this);





Infra_Api
Bool Format_HexInt32(Object this, Int result, Int n);





Infra_Api
Object Format_GetBase(Object this);




Infra_Api
Bool Format_SetBase(Object this, Object value);





Infra_Api
Int Format_GetArgCount(Object this);




Infra_Api
Bool Format_SetArgCount(Object this, Int value);





Infra_Api
Bool Format_Open(Object this);





Infra_Api
Bool Format_Close(Object this);






Infra_Api
Object Format_Arg(Object this, Int arg);






Infra_Api
Int Format_Length(Object this);






Infra_Api
Object Format_GetString(Object this);





Infra_Api
Bool Format_SetString(Object this, Object value);






Infra_Api
Bool Format_Result(Object this);







Infra_Api
Object FormatArg_New();





Infra_Api
Bool FormatArg_Delete(Object o);







Infra_Api
Bool FormatArg_Init(Object this);





Infra_Api
Bool FormatArg_Final(Object this);






Infra_Api
Int FormatArg_GetIndex(Object this);





Infra_Api
Bool FormatArg_SetIndex(Object this, Int value);





Infra_Api
Int FormatArg_GetType(Object this);




Infra_Api
Bool FormatArg_SetType(Object this, Int value);




Infra_Api
Int FormatArg_GetValue(Object this);




Infra_Api
Bool FormatArg_SetValue(Object this, Int value);









Infra_Api
Object Memory_New();




Infra_Api
Bool Memory_Delete(Object o);




Infra_Api
Bool Memory_Init(Object this);




Infra_Api
Bool Memory_Final(Object this);





Infra_Api
Int Memory_GetData(Object this);




Infra_Api
Bool Memory_SetData(Object this, Int value);





Infra_Api
Int Memory_GetByte(Object this, Int index);




Infra_Api
Bool Memory_SetByte(Object this, Int index, Int value);





Infra_Api
Int Memory_GetInt(Object this, Int index);




Infra_Api
Bool Memory_SetInt(Object this, Int index, Int value);




Infra_Api
Int Memory_Alloc(Object this, Int size);




Infra_Api
Bool Memory_Free(Object this, Int o);




Infra_Api
Bool Memory_Copy(Object this, Int dest, Int source, Int count);