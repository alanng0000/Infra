#include "TestStorage.h"



ClassNew(TestStorage)




Bool TestStorage_Init(Object this)
{
    TestStorage* m = this;



    Char* p = "Storage";




    Int length;


    length = String_ConstantLength(p);




    Object name;


    name = String_New();


    String_SetLength(name, length);


    String_SetData(name, p);


    String_Init(name);


    m->Name = name;


    return true;
}




Bool TestStorage_Final(Object this)
{
    TestStorage* m = this;


    Object name;


    name = m->Name;


    String_Final(name);


    Delete(name);


    return true;
}




Object TestStorage_GetName(Object this)
{
    TestStorage* m = this;


    return m->Name;
}





Bool TestStorage_Execute(Object this)
{
    TestStorage* m = this;



    Object fileName;
    
    
    fileName = String_New();



    String_Init(fileName);




    TestStorage_StorageStringSet(fileName, "test1.txt");






    Object storage;



    storage = Storage_New();



    Storage_Init(storage);



    Storage_SetName(storage, fileName);



    Storage_SetMode(storage, 0);




    Storage_Open(storage);




    Int size = 7;



    Object o = New(size);




    Byte* data = (Byte*)o;



    Storage_Read(storage, data, size);



    Bool isEqual;

    isEqual = TestStorage_DataEqual(data, "ABCD 11", size);
    


    
    Char* trueString;


    trueString = "Data Read Correct\n";



    Char* falseString;


    falseString = "Data Read Incorrect\n";





    Char* resultString;


    resultString = falseString;



    if (isEqual)
    {
        resultString = trueString;
    }



    Int length;


    length = String_ConstantLength(resultString);




    Object s;


    s = String_New();



    String_Init(s);



    String_SetLength(s, length);


    String_SetData(s, resultString);




    Object console;


    console = Console_New();



    Console_Init(console);



    Console_OutWrite(console, s);



    Console_Final(console);




    Delete(console);




    String_Final(s);



    Delete(s);

    




    Delete(o);




    Storage_Close(storage);





    Storage_Final(storage);




    Delete(storage);






    String_Final(fileName);



    Delete(fileName);





    return true;
}





Bool TestStorage_DataEqual(Byte* left, Byte* right, Int size)
{
    Byte oa;

    oa = 0;



    Byte ob;

    ob = 0;



    Int count;

    count = size;



    Int i;

    i = 0;


    while (i < count)
    {
        oa = left[i];


        ob = right[i];



        if (!(oa == ob))
        {
            return false;
        }


        i = i + 1;
    }



    return true;
}






Bool TestStorage_StorageStringSet(Object string, char* charArray)
{
    Int k = String_ConstantLength(charArray);



    Int length = k + 1;



    String_SetLength(string, length);


    String_SetData(string, charArray);



    return true;
}