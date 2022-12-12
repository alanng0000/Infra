#include "Format.h"





ClassNew(Format)




ClassNew(FormatArg)






Bool Format_Init(Object this)
{
    return true;
}




Bool Format_Final(Object this)
{
    return true;
}





Object Format_GetBase(Object this)
{
    Format* m = CastPointer(this);



    return m->Base;
}




Bool Format_SetBase(Object this, Object value)
{
    Format* m = CastPointer(this);



    m->Base = value;


    return true;
}





Int Format_GetArgCount(Object this)
{
    Format* m = CastPointer(this);



    return m->ArgCount;
}




Bool Format_SetArgCount(Object this, Int value)
{
    Format* m = CastPointer(this);




    if (m->Open)
    {
        return true;
    }




    m->ArgCount = value;


    return true;
}





Bool Format_Open(Object this)
{
    Format* m = CastPointer(this);



    Int size;


    size = m->ArgCount * sizeof(FormatArg);




    Int o;

    o = New(size);




    m->Args = (FormatArg*)o;




    m->Open = true;




    return true;
}





Bool Format_Close(Object this)
{
    Format* m = CastPointer(this);



    Int o;

    o = (Int)m->Args;



    Delete(o);



    m->Args = null;



    m->ArgCount = 0;



    m->Open = false;



    return true;
}





Object Format_Arg(Object this, Int arg)
{
    Format* m = CastPointer(this);



    FormatArg* p = &(m->Args[arg]);



    Object o = CastInt(p);



    Object ret = o;


    return ret;
}






Bool FormatArg_Init(Object this)
{
    return true;
}




Bool FormatArg_Final(Object this)
{
    return true;
}





Int FormatArg_GetIndex(Object this)
{
    FormatArg* m = CastPointer(this);



    return m->Index;
}





Bool FormatArg_SetIndex(Object this, Int value)
{
    FormatArg* m = CastPointer(this);


    m->Index = value;


    return true;
}






Int FormatArg_GetType(Object this)
{
    FormatArg* m = CastPointer(this);



    return m->Type;
}





Bool FormatArg_SetType(Object this, Int value)
{
    FormatArg* m = CastPointer(this);


    m->Type = value;


    return true;
}






Int FormatArg_GetValue(Object this)
{
    FormatArg* m = CastPointer(this);



    return m->Value;
}





Bool FormatArg_SetValue(Object this, Int value)
{
    FormatArg* m = CastPointer(this);


    m->Value = value;


    return true;
}










Object Format_GetString(Object this)
{
    Format* m = CastPointer(this);


    return m->String;
}




Bool Format_SetString(Object this, Object value)
{
    Format* m = CastPointer(this);



    m->String = value;


    return true;
}






Int Format_Length(Object this)
{
    Format* m = CastPointer(this);




    Object base;

    base = m->Base;



    Int baseLength;

    baseLength = String_GetLength(base);




    Int length;

    length = baseLength;




    Int arg = 0;



    Int k = 0;




    Int count;

    count = m->ArgCount;



    Int i;

    i = 0;


    while (i < count)
    {
        arg = i;



        k = Format_ArgLength(m, arg);



        length = length + k;



        i = i + 1;
    }



    Int ret = length;


    return ret;
}





Int Format_ArgLength(Format* this, Int arg)
{
    FormatArg* p;
    
    
    p = &(this->Args[arg]);




    Int type;

    type = p->Type;
    
    


    Int value;

    value = p->Value;





    Format_ArgLengthMethod u = null;




    if (type == 0)
    {
        u = Format_BoolArgLength;
    }


    if (type == 1)
    {
        u = Format_IntArgLength;
    }

    
    if (type == 2)
    {
        u = Format_StringArgLength;
    }
    


    Int length;

    
    length = u(this, value);




    Int ret = length;

    
    return ret;
}





Int Format_BoolArgLength(Format* this, Int value)
{
    Bool b = (Bool)value;



    Int length = 5;


    if (b)
    {
        length = 4;
    }



    Int ret = length;


    return ret;
}





Int Format_IntArgLength(Format* this, Int value)
{
    Int length = Format_IntLength(CastInt(this), value);


    Int ret = length;


    return ret;
}






Int Format_StringArgLength(Format* this, Int value)
{
    Object o = value;



    Int length = String_GetLength(o);



    Int ret = length;


    return ret;
}





Bool Format_Result(Object this)
{
    Format* m = CastPointer(this);




    Object base;

    base = m->Base;



    Int baseLength;

    baseLength = String_GetLength(base);



    Int o;

    o = String_GetData(base);



    Char* baseChars;


    baseChars = (Char*)o;




    Int argCount;

    argCount = m->ArgCount;




    FormatArg* args;

    args = m->Args;





    Object string;

    string = m->String;




    o = String_GetData(string);





    Char* result;


    result = (Char*)o;




    Int resultIndex;

    resultIndex = 0;




    Int arg;

    arg = 0;



    Int i;

    i = 0;


    while (i < baseLength)
    {
        Format_ResultIndexArgs(m, i, &arg, result, &resultIndex);




        result[resultIndex] = baseChars[i];



        resultIndex = resultIndex + 1;



        i = i + 1;
    }



    Format_ResultIndexArgs(m, baseLength, &arg, result, &resultIndex);




    return true;
}





Bool Format_ResultIndexArgs(Format* this, Int index, Int* argP, Char* result, Int* resultIndexP)
{
    Int argCount = this->ArgCount;



    FormatArg* args = this->Args;



    Int arg = *argP;



    Int resultIndex = *resultIndexP;




    FormatArg* t = null;





    Bool f;

    f = false;


    while ((!f) & (arg < argCount))
    {
        t = &(args[arg]);




        Int k;

        k = t->Index;



        Bool ba;

        ba = (index == k);


        if (ba)
        {
            Int type;

            type = t->Type;


            Int value;

            value = t->Value;



            Int h;

            h = (Int)result;



            Int dest;

            dest = h + resultIndex;



            Int length = 0;




            Format_ArgResultMethod u = null;


            if (type == 0)
            {
                u = Format_BoolArgResult;
            }



            if (type == 1)
            {
                u = Format_IntArgResult;
            }


            if (type == 2)
            {
                u = Format_StringArgResult;
            }




            u(this, value, dest, &length);




            resultIndex = resultIndex + length;


            arg = arg + 1;
        }


        if (!ba)
        {
            f = true;
        }
    }




    *argP = arg;



    *resultIndexP = resultIndex;




    return true;
}




Bool Format_BoolArgResult(Format* this, Int value, Int dest, Int* lengthP)
{
    Bool b;

    b = (Bool)value;



    Int sLength;

    Int sData;




    if (b)
    {
        sLength = 4;

        sData = CastInt("true");
    }



    if (!b)
    {
        sLength = 5;

        sData = CastInt("false");
    }



    Copy(dest, sData, sLength);




    *lengthP = sLength;



    return true;
}





Bool Format_IntArgResult(Format* this, Int value, Int dest, Int* lengthP)
{
    Int length;

    length = Format_IntLength(CastInt(this), value);




    Format_Int(CastInt(this), dest, value, length);




    *lengthP = length;



    return true;
}





Bool Format_StringArgResult(Format* this, Int value, Int dest, Int* lengthP)
{
    Object o = value;



    Int length = String_GetLength(o);



    Int data = String_GetData(o);




    Copy(dest, data, length);




    *lengthP = length;



    return true;
}











Int Format_IntLength(Object this, Int n)
{
    return Format_DigitCount(n);
}




Bool Format_Int(Object this, Int result, Int n, Int length)
{
    Int digitCount = length;






    Char* buffer = (Char*)result;




    if (n == 0)
    {
        buffer[0] = '0';



        return true;
    }






    Int k = n;




    Int j = 0;




    Byte digit = 0;



    Int o = 0;



    Char c = 0;



    Int index = 0;



    Int count = digitCount;



    Int i = 0;



    while (i < count)
    {
        j = k / 10;




        o = k - j * 10;




        digit = (Byte)o;




        index = count - 1 - i;





        c = digit + '0';




        buffer[index] = c;




        k = j;




        i++;
    }




    return true;
}





Int Format_DigitCount(Int n)
{
    Int digitCount = 0;





    Int k = n;





    while (k > 0)
    {
        k = k / 10;



        digitCount = digitCount + 1;
    }





    if (digitCount == 0)
    {
        digitCount = 1;
    }



    Int ret = digitCount;



    return ret;
}






Int Format_HexIntLength(Object this)
{
    return Constants_IntByteCount * Constants_ByteHexDigitCount;
}





Bool Format_HexInt(Object this, Int result, Int n)
{
    Char* p = (Char*)result;




    Int k = n;


    Int byteCount = Constants_IntByteCount;



    Bool t = Format_HexIntByteCount(p, k, byteCount);



    Bool ret = t;


    return ret;
}





Int Format_HexInt32Length(Object this)
{
    return Constants_Int32ByteCount * Constants_ByteHexDigitCount;
}





Bool Format_HexInt32(Object this, Int result, Int n)
{
    Char* p = (Char*)result;




    Int k = n;



    Int byteCount = Constants_Int32ByteCount;




    Bool t = Format_HexIntByteCount(p, k, byteCount);




    Bool ret = t;


    return ret;
}






Bool Format_HexIntByteCount(Char* result, Int n, Int byteCount)
{
    Int count = byteCount * Constants_ByteHexDigitCount;





    Char* buffer = result;




    Char c = 0;




    Int shiftCount = 0;




    Int k = 0;




    Int index = 0;




    Int i = 0;




    while (i < count)
    {
        shiftCount = i * 4;





        k = n >> shiftCount;




        k = k & 0xf;



        
        index = count - 1 - i;




        c = Format_HexDigit(k);
        




        buffer[index] = c;





        i = i + 1;
    }




    return true;
}





Char Format_HexDigit(Int k)
{
    Char c;




    Byte u;



    u = (Byte)k;



    if (u < 10)
    {
        c = '0' + u;
    }
    else
    {
        Byte n = u - 10;



        c = 'a' + n;
    }




    return c;
}