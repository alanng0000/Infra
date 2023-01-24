#pragma once





#define ExportApi __declspec(dllexport)


#define ImportApi __declspec(dllimport)




#ifdef Infra_Module
#define Infra_Api ExportApi
#else
#define Infra_Api ImportApi
#endif






typedef unsigned char Byte;




typedef unsigned long long Bool;




typedef unsigned long long Int;





typedef unsigned char Char;




typedef unsigned long long Object;




typedef unsigned int Int32;





typedef long long SInt;







#define true (1)



#define false (0)





#ifndef null

#define null (0)

#else

#error null is defined by another include

#endif






#define Constant_IntByteCount (sizeof(Int))



#define Constants_Int32ByteCount (sizeof(Int32))



#define Constants_ByteHexDigitCount (2)



#define Constants_HexDigitBitCount (4)







#define InfraObjectApi(m, c) m##_Api \
Object c##_New();\
\
m##_Api \
Bool c##_Delete(Object o);\
\
m##_Api \
Bool c##_Init(Object o);\
\
m##_Api \
Bool c##_Final(Object o);\






#define ObjectApi(m, c) m##_Api \
Object m##_##c##_New();\
\
m##_Api \
Bool m##_##c##_Delete(Object o);\
\
m##_Api \
Bool m##_##c##_Init(Object o);\
\
m##_Api \
Bool m##_##c##_Final(Object o);\






#define InfraClassNew(c) Object c##_New()\
{\
    Int size = sizeof(c);\
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
Bool c##_Delete(Object o)\
{\
    Int k = o;\
\
\
    Delete(k);\
\
\
    return true;\
}\





#define ClassNew(m, c) Object m##_##c##_New()\
{\
    Int size = sizeof(c);\
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
Bool m##_##c##_Delete(Object o)\
{\
    Int k = o;\
\
\
    Delete(k);\
\
\
    return true;\
}\






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





InfraObjectApi(Infra, String)






Infra_Api
Int String_GetLength(Object o);




Infra_Api
Bool String_SetLength(Object o, Int value);





Infra_Api
Int String_GetData(Object o);




Infra_Api
Bool String_SetData(Object o, Int value);





Infra_Api
Int String_Char(Object o, Int index);




Infra_Api
Bool String_Equal(Object o, Object other);





Infra_Api
Int String_ConstantLength(Int o);





Infra_Api
Bool String_Copy(Object o, Int data, Int index, Int length);





InfraObjectApi(Infra, List)





Infra_Api
Int List_GetCount(Object o);




Infra_Api
Object List_Add(Object o, Object item);




Infra_Api
Object List_Insert(Object o, Object key, Object item);




Infra_Api
Bool List_Remove(Object o, Object key);




Infra_Api
Bool List_Contain(Object o, Object key);





Infra_Api
Bool List_Clear(Object o);





Infra_Api
Object List_Get(Object o, Object key);




Infra_Api
Bool List_Set(Object o, Object key, Object value);




Infra_Api
Bool List_Iter(Object o, Object iter);





InfraObjectApi(Infra, ListIter)





Infra_Api
Bool ListIter_Next(Object o);




Infra_Api
Object ListIter_Value(Object o);






InfraObjectApi(Infra, Console)





Infra_Api
Bool Console_Write(Object o, Object text);





InfraObjectApi(Infra, Format)





Infra_Api
Int Format_IntLength(Object o, Int n);




Infra_Api
Bool Format_Int(Object o, Int result, Int n, Int length);





Infra_Api
Int Format_HexIntLength(Object o);




Infra_Api
Bool Format_HexInt(Object o, Int result, Int n);





Infra_Api
Int Format_HexInt32Length(Object o);





Infra_Api
Bool Format_HexInt32(Object o, Int result, Int n);





Infra_Api
Char Format_HexDigit(Int k);







Infra_Api
Object Format_GetBase(Object o);




Infra_Api
Bool Format_SetBase(Object o, Object value);





Infra_Api
Int Format_GetArgCount(Object o);




Infra_Api
Bool Format_SetArgCount(Object o, Int value);





Infra_Api
Bool Format_Open(Object o);





Infra_Api
Bool Format_Close(Object o);






Infra_Api
Object Format_Arg(Object o, Int arg);






Infra_Api
Int Format_Length(Object o);






Infra_Api
Object Format_GetString(Object o);





Infra_Api
Bool Format_SetString(Object o, Object value);






Infra_Api
Bool Format_Result(Object o);





InfraObjectApi(Infra, FormatArg)





Infra_Api
Int FormatArg_GetIndex(Object o);





Infra_Api
Bool FormatArg_SetIndex(Object o, Int value);





Infra_Api
Int FormatArg_GetType(Object o);




Infra_Api
Bool FormatArg_SetType(Object o, Int value);




Infra_Api
Int FormatArg_GetValue(Object o);




Infra_Api
Bool FormatArg_SetValue(Object o, Int value);







InfraObjectApi(Infra, Memory)





Infra_Api
Int Memory_GetData(Object o);




Infra_Api
Bool Memory_SetData(Object o, Int value);





Infra_Api
Int Memory_GetByte(Object o, Int index);




Infra_Api
Bool Memory_SetByte(Object o, Int index, Int value);





Infra_Api
Int Memory_GetInt(Object o, Int index);




Infra_Api
Bool Memory_SetInt(Object o, Int index, Int value);




Infra_Api
Int Memory_Alloc(Object o, Int size);




Infra_Api
Bool Memory_Free(Object o, Int address);




Infra_Api
Bool Memory_Copy(Object o, Int dest, Int source, Int count);