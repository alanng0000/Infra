#pragma once




#include "Local.h"






typedef struct
{
    Int Index;


    Int Type;


    Int Value;

} FormatArg;






typedef struct
{
    Object Base;


    Int ArgCount;


    FormatArg* Args;


    Bool Open;


    Object String;

    
} Format;






Int Format_DigitCount(Int n);




Bool Format_HexIntByteCount(Char* result, Int n, Int byteCount);



Char Format_HexDigit(Int k);




Int Format_ArgLength(Format* this, Int arg);






typedef Int (*Format_ArgLengthMethod)(Format* this, Int value);




Int Format_BoolArgLength(Format* this, Int value);


Int Format_IntArgLength(Format* this, Int value);


Int Format_StringArgLength(Format* this, Int value);





Bool Format_ResultIndexArgs(Format* this, Int index, Int* argP, Char* result, Int* resultIndexP);






typedef Bool (*Format_ArgResultMethod)(Format* this, Int value, Int dest, Int* lengthP);





Bool Format_BoolArgResult(Format* this, Int value, Int dest, Int* lengthP);



Bool Format_IntArgResult(Format* this, Int value, Int dest, Int* lengthP);



Bool Format_StringArgResult(Format* this, Int value, Int dest, Int* lengthP);