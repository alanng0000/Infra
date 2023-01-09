#include "Main.h"




Object DrawRect;



Byte ColorComp;








Int CharArray(Int a, Int index)
{
    return a + index;
}





Bool ConsoleWrite(Object string)
{
    Object console = Console_New();



    Console_Init(console);



    Console_Write(console, string);



    Console_Final(console);


    
    Console_Delete(console);



    return true;
}





Bool SetFormatArg(Object format, Int arg, Int index, Int type, Int value)
{
    Object o;


    o = Format_Arg(format, arg);





    FormatArg_SetIndex(o, index);



    FormatArg_SetType(o, type);



    FormatArg_SetValue(o, value);




    return true;
}




Bool ControlHandleConsoleWriteKeyValue(Int controlKey, Int controlValue)
{
    Object format;



    format = Format_New();



    Format_Init(format);





    Int o = CastInt(", \n");



    Int baseLength = String_ConstantLength(o);




    Object base;
    


    base = String_New();



    String_Init(base);




    String_SetLength(base, baseLength);


    String_SetData(base, o);







    Object result = String_New();



    String_Init(result);





    Int arg = 0;


    Int index = 0;


    Int type = 0;


    Int value = 0;



    Int argCount = 2;




    Format_SetBase(format, base);




    Format_SetArgCount(format, argCount);




    Format_Open(format);







    arg = 0;


    index = 0;


    type = 1;


    value = controlKey;




    SetFormatArg(format, arg, index, type, value);






    arg = 1;


    index = 2;


    type = 1;

    
    value = controlValue;




    SetFormatArg(format, arg, index, type, value);







    Int resultLength = Format_Length(format);




    Int resultBuffer = New(resultLength);




    String_SetLength(result, resultLength);



    String_SetData(result, resultBuffer);




    Format_SetString(format, result);






    Format_Result(format);





    Format_Close(format);








    Object console;
    
    

    console = Console_New();



    Console_Init(console);



    Console_Write(console, result);



    Console_Final(console);



    Console_Delete(console);








    Delete(resultBuffer);





    String_Final(result);



    String_Delete(result);






    String_Final(base);



    String_Delete(base);





    Format_Final(format);



    Format_Delete(format);




    return true;
}





Bool ControlHandle(Object frame, Int key, Int value)
{
    ControlHandleConsoleWriteKeyValue(key, value);




    if (key == 0x20)
    {
        if (value == 1)
        {
            Frame_Close(frame);


            return true;
        }
    }




    if (value == 0)
    {
        return true;
    }




    // Int l = 100;


    // Int t = 100;



    // Int w = 100;


    // Int h = 100;



    // Object drawPos = Rect_GetPos(DrawRect);

    // Object drawSize = Rect_GetSize(DrawRect);


    // Pos_SetLeft(drawPos, l);

    // Pos_SetUp(drawPos, t);


    // Size_SetWidth(drawSize, w);

    // Size_SetHeight(drawSize, h);





    // Object size = Frame_GetSize(frame);



    // Int width = Size_GetWidth(size);



    // Int height = Size_GetHeight(size);




    // Int32 ot = ColorComp;



    // Int32 color = ot << 16;




    // Int32* pixels = Frame_LockPixels(frame, DrawRect);




    // Int index = 0;



    // Int row = 0;


    // Int col = 0;




    // Int r = 0;

    // Int c = 0;


    // r = 0;


    // while (r < h)
    // {
    //     c = 0;


    //     while (c < w)
    //     {
    //         row = r + t;


    //         col = c + l;



    //         index = row * width + col;


    //         pixels[index] = color;




    //         c++;
    //     }


    //     r++;
    // }





    // Frame_UnlockPixels(frame);




    ColorComp++;



    return true;
}



Bool FrameExecute()
{
    DrawRect = Rect_New();


    Rect_Init(DrawRect);




    Object pos = Pos_New();


    Pos_Init(pos);




    Object size = Size_New();


    Size_Init(size);




    Rect_SetPos(DrawRect, pos);



    Rect_SetSize(DrawRect, size);





    Int os = CastInt("Infra Demo Frame");



    Int osLength = String_ConstantLength(os);




    Object windowTitle = String_New();



    String_Init(windowTitle);




    String_SetLength(windowTitle, osLength);



    String_SetData(windowTitle, os);






    Object frame = Frame_New();
    
    
    
    Frame_SetTitle(frame, windowTitle);



    Frame_Init(frame);



    Frame_SetControlHandle(frame, &ControlHandle);




    Frame_SetVisible(frame, true);




    Frame_Execute(frame);




    Frame_Final(frame);



    Frame_Delete(frame);
    




    String_Final(windowTitle);



    String_Delete(windowTitle);




    return true;
}




Int ListValuesLength(Object list)
{
    Object format = Format_New();


    Format_Init(format);




    Int length = 0;




    Object iter = ListIter_New();



    ListIter_Init(iter);





    List_Iter(list, iter);





    while (ListIter_Next(iter))
    {
        Object value = ListIter_Value(iter);



        Int n = (Int)value;



        Int k = Format_IntLength(format, n);



        length = length + k;
    }





    ListIter_Final(iter);



    ListIter_Delete(iter);




    Format_Final(format);


    Format_Delete(format);




    Int ret = length;



    return ret;
}





Bool ConsoleWriteList(Object list)
{
    Int count = List_GetCount(list);





    Int ta = CastInt("List: Count: ");



    Int tb = CastInt(", ");
    
    
    
    Int tc = CastInt("Values: ");



    Int td = CastInt("[");


    
    Int te = CastInt("]");



    Int newLine = CastInt("\n");





    Object format = Format_New();



    Format_Init(format);





    Int taLength = String_ConstantLength(ta);



    Int tbLength = String_ConstantLength(tb);



    Int tcLength = String_ConstantLength(tc);



    Int tdLength = String_ConstantLength(td);



    Int teLength = String_ConstantLength(te);



    Int newLineLength = String_ConstantLength(newLine);



    Int countLength = Format_IntLength(format, count);
    


    Int valuesLength = ListValuesLength(list);





    Int valuesSeparaterLength = 0;



    Bool b = (count < 1);



    if (!b)
    {
        valuesSeparaterLength = (count - 1) * tbLength;
    }







    Int totalLength = taLength + countLength + tbLength + tcLength + tdLength + valuesLength + valuesSeparaterLength + teLength + newLineLength;






    Int wholeStringChars = New(totalLength);




    Object string = String_New();



    String_Init(string);



    String_SetLength(string, totalLength);



    String_SetData(string, wholeStringChars);





    Int length = 0;




    String_Copy(string, ta, length, taLength);



    length = length + taLength;



    
    Int countChars = CharArray(wholeStringChars, length);



    Format_Int(format, countChars, count, countLength);



    length = length + countLength;



    String_Copy(string, tb, length, tbLength);



    length = length + tbLength;



    String_Copy(string, tc, length, tcLength);



    length = length + tcLength;



    String_Copy(string, td, length, tdLength);



    length = length + tdLength;





    Int i = 0;    



    Object iter = ListIter_New();



    ListIter_Init(iter);



    List_Iter(list, iter);



    while (ListIter_Next(iter))
    {
        Object value = ListIter_Value(iter);



        Int n = value;



        Int nLength = Format_IntLength(format, n);




        Bool b = (i < 1);


        if (!b)
        {
            String_Copy(string, tb, length, tbLength);



            length = length + tbLength;
        }




        Int p = CharArray(wholeStringChars, length);




        Format_Int(format, p, n, nLength);




        length = length + nLength;




        i = i + 1;
    }





    ListIter_Final(iter);



    ListIter_Delete(iter);







    String_Copy(string, te, length, teLength);



    length = length + teLength;




    String_Copy(string, newLine, length, newLineLength);



    length = length + newLineLength;
    






    ConsoleWrite(string);




    String_Final(string);



    String_Delete(string);





    Delete(wholeStringChars);





    Format_Final(format);



    Format_Delete(format);





    return true;
}





Object ListAddInt(Object list, Int n)
{
    Object value = n;



    Object key = List_Add(list, value);



    Object ret = key;


    return ret;
}





Bool ListExecute()
{
    Object list = List_New();



    List_Init(list);




    ConsoleWriteList(list);




    Int a = 1;



    Object aKey = ListAddInt(list, a);




    ConsoleWriteList(list);




    Int b = 1000;



    Object bKey = ListAddInt(list, b);




    Int c = 46;



    Object cKey = ListAddInt(list, c);




    Int d = 62;



    Object dKey = ListAddInt(list, d);




    ConsoleWriteList(list);




    List_Remove(list, bKey);




    ConsoleWriteList(list);




    List_Remove(list, cKey);




    ConsoleWriteList(list);




    Int e = 79;


    Object value = (Object)e;



    Object eKey = List_Insert(list, dKey, value);
    




    ConsoleWriteList(list);




    List_Remove(list, dKey);




    ConsoleWriteList(list);




    List_Remove(list, aKey);




    ConsoleWriteList(list);




    List_Remove(list, eKey);




    ConsoleWriteList(list);





    List_Final(list);



    List_Delete(list);



    return true;
}







Bool TimeExecute()
{
    Object time = Time_New();




    Time_Init(time);





    Time_Current(time);





    Object date = Date_New();



    Date_Init(date);




    Time_Date(time, date);





    Int year = Date_GetYear(date);



    Int month = Date_GetMonth(date);


    
    Int day = Date_GetDay(date);


    
    Int hour = Date_GetHour(date);



    Int min = Date_GetMin(date);



    Int sec = Date_GetSec(date);



    Int millisec = Date_GetMillisec(date);





    Object format = Format_New();



    Format_Init(format);





    Int t = CastInt("Time Now:");



    Int space = CastInt(" ");




    Int hyphen = CastInt("-");




    Int colon = CastInt(":");



    Int newLine = CastInt("\n");




    Int tLength = String_ConstantLength(t);



    Int spaceLength = String_ConstantLength(space);



    Int hyphenLength = String_ConstantLength(hyphen);



    Int colonLength = String_ConstantLength(colon);



    Int newLineLength = String_ConstantLength(newLine);



    Int yearLength = Format_IntLength(format, year);



    Int monthLength = Format_IntLength(format, month);



    Int dayLength = Format_IntLength(format, day);



    Int hourLength = Format_IntLength(format, hour);



    Int minLength = Format_IntLength(format, min);



    Int secLength = Format_IntLength(format, sec);



    Int millisecLength = Format_IntLength(format, millisec);




    Int totalLength = tLength + spaceLength + 
        yearLength + hyphenLength + monthLength + hyphenLength + dayLength + spaceLength +
        hourLength + colonLength + minLength + colonLength + secLength + spaceLength +
        millisecLength + newLineLength;





    Int wholeStringChars = New(totalLength);




    Object string = String_New();



    String_Init(string);



    String_SetLength(string, totalLength);



    String_SetData(string, wholeStringChars);




    Int p = 0;




    Int length = 0;




    String_Copy(string, t, length, tLength);



    length = length + tLength;



    String_Copy(string, space, length, spaceLength);



    length = length + spaceLength;



    p = CharArray(wholeStringChars, length);


    Format_Int(format, p, year, yearLength);



    length = length + yearLength;



    String_Copy(string, hyphen, length, hyphenLength);



    length = length + hyphenLength;



    p = CharArray(wholeStringChars, length);


    Format_Int(format, p, month, monthLength);



    length = length + monthLength;



    String_Copy(string, hyphen, length, hyphenLength);



    length = length + hyphenLength;



    p = CharArray(wholeStringChars, length);


    Format_Int(format, p, day, dayLength);



    length = length + dayLength;



    String_Copy(string, space, length, spaceLength);



    length = length + spaceLength;



    p = CharArray(wholeStringChars, length);


    Format_Int(format, p, hour, hourLength);



    length = length + hourLength;



    String_Copy(string, colon, length, colonLength);



    length = length + colonLength;



    p = CharArray(wholeStringChars, length);


    Format_Int(format, p, min, minLength);



    length = length + minLength;



    String_Copy(string, colon, length, colonLength);



    length = length + colonLength;



    p = CharArray(wholeStringChars, length);


    Format_Int(format, p, sec, secLength);


    
    length = length + secLength;



    String_Copy(string, space, length, spaceLength);



    length = length + spaceLength;



    p = CharArray(wholeStringChars, length);


    Format_Int(format, p, millisec, millisecLength);



    length = length + millisecLength;



    String_Copy(string, newLine, length, newLineLength);



    length = length + newLineLength;






    ConsoleWrite(string);






    String_Final(string);



    String_Delete(string);






    Delete(wholeStringChars);






    Format_Final(format);



    Format_Delete(format);





    Date_Final(date);



    Date_Delete(date);






    Time_Final(time);



    Time_Delete(time);




    return true;
}





Bool StorageStatusExecute(Object storage)
{
    Storage_Status(storage);




    Object name = Storage_GetName(storage);







    Int h = CastInt("Storage ");



    Int hLength = String_ConstantLength(h);






    Int f = String_GetData(name);



    Int fLength = String_GetLength(name) - 1;






    Int newLine = CastInt("\n");



    Int newLineLength = String_ConstantLength(newLine);





    

    Int demoFileSize = Storage_GetSize(storage);





    Object format = Format_New();



    Format_Init(format);





    Int e = CastInt(" Size: ");



    Int t = demoFileSize;



    Int eLength = String_ConstantLength(e);



    Int tLength = Format_IntLength(format, t);




    Int totalLength = hLength + fLength + eLength + tLength + newLineLength;






    Int wholeStringChars = New(totalLength);





    Int length = 0;



    Object string = null;




    string = String_New();



    String_Init(string);



    String_SetLength(string, totalLength);



    String_SetData(string, wholeStringChars);




    Int p = 0;


    length = 0;



    String_Copy(string, h, length, hLength);



    length = length + hLength;



    String_Copy(string, f, length, fLength);



    length = length + fLength;



    String_Copy(string, e, length, eLength);



    length = length + eLength;



    p = CharArray(wholeStringChars, length);


    Format_Int(format, p, t, tLength);



    length = length + tLength;



    String_Copy(string, newLine, length, newLineLength);



    length = length + newLineLength;


    


    ConsoleWrite(string);





    String_Final(string);



    String_Delete(string);





    Delete(wholeStringChars);





    Format_Final(format);




    Format_Delete(format);
    






    Bool demoFileFold = Storage_GetFold(storage);





    e = CastInt(" Is Fold: ");



    Int m = CastInt("false");


    if (demoFileFold)
    {
        m = CastInt("true");
    }




    eLength = String_ConstantLength(e);



    Int mLength = String_ConstantLength(m);



    totalLength = hLength + fLength + eLength + mLength + newLineLength;




    wholeStringChars = New(totalLength);




    string = String_New();



    String_Init(string);



    String_SetLength(string, totalLength);



    String_SetData(string, wholeStringChars);




    length = 0;



    String_Copy(string, h, length, hLength);



    length = length + hLength;



    String_Copy(string, f, length, fLength);



    length = length + fLength;



    String_Copy(string, e, length, eLength);



    length = length + eLength;



    String_Copy(string, m, length, mLength);



    length = length + mLength;



    String_Copy(string, newLine, length, newLineLength);



    length = length + newLineLength;


    


    ConsoleWrite(string);




    String_Final(string);



    String_Delete(string);




    Delete(wholeStringChars);



    return true;
}






Bool StorageStringSet(Object string, Int charArray)
{
    Int k = String_ConstantLength(charArray);



    Int length = k + 1;



    String_SetLength(string, length);


    String_SetData(string, charArray);



    return true;
}






Bool ConsoleWriteCharArray(Int s)
{
    Int length = String_ConstantLength(s);



    Object string = String_New();



    String_Init(string);



    String_SetLength(string, length);



    String_SetData(string, s);




    ConsoleWrite(string);




    String_Final(string);



    String_Delete(string);



    return true;
}






Bool StorageExecute()
{
    Int ca = CastInt("demo.txt");





    Object name = String_New();



    String_Init(name);





    StorageStringSet(name, ca);





    Object storage = Storage_New();




    Storage_Init(storage);





    Storage_SetName(storage, name);






    Storage_SetMode(storage, 0);





    Storage_Open(storage);




    Int size = 11;




    Int o = New(size);



    Int buffer = o;




    Object data;


    data = Data_New();



    Data_Init(data);



    Data_SetSize(data, size);


    Data_SetValue(data, buffer);





    Storage_Read(storage, data);





    Int h = CastInt("Storage Read Text: ");



    Int t = buffer;



    Int newLine = CastInt("\n");




    Int hLength = String_ConstantLength(h);



    Int tLength = size;



    Int newLineLength = String_ConstantLength(newLine);




    Int totalLength = hLength + tLength + newLineLength;




    Int wholeStringChars = New(totalLength);




    Object string = String_New();



    String_Init(string);



    String_SetLength(string, totalLength);



    String_SetData(string, wholeStringChars);




    Int length = 0;



    String_Copy(string, h, length, hLength);



    length = length + hLength;



    String_Copy(string, t, length, tLength);



    length = length + tLength;



    String_Copy(string, newLine, length, newLineLength);



    length = length + newLineLength;


    


    ConsoleWrite(string);





    String_Final(string);



    String_Delete(string);





    Delete(wholeStringChars);







    Delete(o);





    Storage_Close(storage);












    StorageStatusExecute(storage);









    Storage_SetMode(storage, 1);




    Storage_Open(storage);




    Int os = CastInt("DEMOSTORAGE FGHJ");



    length = String_ConstantLength(os);




    size = length;



    buffer = os;




    Data_SetSize(data, size);



    Data_SetValue(data, buffer);




    Storage_Write(storage, data);




    Storage_Close(storage);






    Data_Final(data);


    Data_Delete(data);






    ConsoleWriteCharArray(CastInt("Offset Read\n"));






    size = 4;




    o = New(size);



    buffer = o;





    data = Data_New();



    Data_Init(data);



    Data_SetSize(data, size);


    Data_SetValue(data, buffer);





    Storage_SetMode(storage, 0);




    Storage_Open(storage);




    Storage_Offset(storage, 1, 12);




    Storage_Read(storage, data);





    h = CastInt("Storage Offset Read Text: ");



    t = buffer;



    newLine = CastInt("\n");




    hLength = String_ConstantLength(h);



    tLength = size;



    newLineLength = String_ConstantLength(newLine);




    totalLength = hLength + tLength + newLineLength;




    wholeStringChars = New(totalLength);




    string = String_New();



    String_Init(string);



    String_SetLength(string, totalLength);



    String_SetData(string, wholeStringChars);




    length = 0;



    String_Copy(string, h, length, hLength);



    length = length + hLength;



    String_Copy(string, t, length, tLength);



    length = length + tLength;



    String_Copy(string, newLine, length, newLineLength);



    length = length + newLineLength;


    


    ConsoleWrite(string);





    String_Final(string);



    String_Delete(string);





    Delete(wholeStringChars);







    Data_Final(data);


    Data_Delete(data);




    Delete(o);









    Storage_Close(storage);











    ca = CastInt("newfile.txt");


    StorageStringSet(name, ca);




    Storage_CreateFile(storage);





    StorageStatusExecute(storage);





    ca = CastInt("newfile2.txt");


    StorageStringSet(name, ca);




    Storage_DeleteFile(storage);







    ca = CastInt("newfold");


    StorageStringSet(name, ca);



    Storage_CreateFold(storage);





    StorageStatusExecute(storage);






    ca = CastInt("newfold2");


    StorageStringSet(name, ca);



    Storage_DeleteFold(storage);







    Storage_Final(storage);




    Storage_Delete(storage);





    String_Final(name);



    String_Delete(name);





    return true;
}





Bool DemoExecute()
{
    Int t = CastInt("DEMODEMODEMO\n");



    Int length = String_ConstantLength(t);




    Object s = String_New();



    String_Init(s);



    String_SetLength(s, length);



    String_SetData(s, t);







    Object h = String_New();



    String_Init(h);



    String_SetLength(h, length);



    String_SetData(h, t);








    ConsoleWrite(s);









    Bool equal = String_Equal(s, h);



    if (equal)
    {
        Int j = CastInt("Strings are equal\n");



        Int jLength = String_ConstantLength(j);




        Object jString = String_New();



        String_Init(jString);



        String_SetLength(jString, jLength);



        String_SetData(jString, j);




        ConsoleWrite(jString);




        String_Final(jString);



        String_Delete(jString);
    }




    String_Final(h);



    String_Delete(h);





    String_Final(s);



    String_Delete(s);




    return true;
}







Bool DemoCLeftExecute()
{
    Int s = CastInt("Left Execute\n");




    ConsoleWriteCharArray(s);



    return true;
}




Bool DemoCRightExecute()
{
    Int s = CastInt("Right Execute\n");




    ConsoleWriteCharArray(s);



    return true;
}





Bool DemoCExecute()
{
    ConsoleWriteCharArray(CastInt("Bitwise Or Operator Start\n"));



    Bool ba = (DemoCLeftExecute() | DemoCRightExecute());



    ConsoleWriteCharArray(CastInt("Bitwise Or Operator End\n"));





    ConsoleWriteCharArray(CastInt("Bitwise And Operator Start\n"));



    Bool bb = (DemoCLeftExecute() & DemoCRightExecute());



    ConsoleWriteCharArray(CastInt("Bitwise And Operator End\n"));






    ConsoleWriteCharArray(CastInt("Add Operator Start\n"));



    Int u = (DemoCLeftExecute() + DemoCRightExecute());



    ConsoleWriteCharArray(CastInt("Add Operator End\n"));





    ConsoleWriteCharArray(CastInt("Sub Operator Start\n"));



    u = (DemoCLeftExecute() - DemoCRightExecute());



    ConsoleWriteCharArray(CastInt("Sub Operator End\n"));




    return true;
}








Bool ExecuteFormat()
{
    Object format;



    format = Format_New();



    Format_Init(format);





    Int o = CastInt("DEMO World NOW  NOW ");



    Int baseLength = String_ConstantLength(o);




    Object base;
    


    base = String_New();



    String_Init(base);




    String_SetLength(base, baseLength);


    String_SetData(base, o);






    o = CastInt("Clase ");



    Int helloLength = String_ConstantLength(o);




    Object hello;



    hello = String_New();



    String_Init(hello);




    String_SetLength(hello, helloLength);


    String_SetData(hello, o);






    Object result = String_New();



    String_Init(result);





    Int arg = 0;


    Int index = 0;


    Int type = 0;


    Int value = 0;



    Int argCount = 4;




    Format_SetBase(format, base);




    Format_SetArgCount(format, argCount);




    Format_Open(format);







    arg = 0;


    index = 5;


    type = 2;


    value = hello;




    SetFormatArg(format, arg, index, type, value);






    arg = 1;


    index = 15;


    type = 0;

    
    value = (Int)true;




    SetFormatArg(format, arg, index, type, value);








    arg = 2;


    index = 15;


    type = 0;

    
    value = (Int)false;




    SetFormatArg(format, arg, index, type, value);








    arg = 3;


    index = 20;


    type = 1;

    
    value = 2022;




    SetFormatArg(format, arg, index, type, value);

    






    Int resultLength = Format_Length(format);




    Int resultBuffer = New(resultLength);




    String_SetLength(result, resultLength);



    String_SetData(result, resultBuffer);




    Format_SetString(format, result);






    Format_Result(format);





    Format_Close(format);








    Object console;
    
    

    console = Console_New();



    Console_Init(console);



    Console_Write(console, result);



    Console_Final(console);



    Console_Delete(console);








    Delete(resultBuffer);





    String_Final(result);



    String_Delete(result);







    String_Final(hello);



    String_Delete(hello);






    String_Final(base);



    String_Delete(base);





    Format_Final(format);



    Format_Delete(format);




    return true;
}






Bool SpeedDemoExecute()
{
    Object start;


    start = Time_New();


    Time_Init(start);





    Object end;


    end = Time_New();


    Time_Init(end);








    Int count;


    count = DemoCount();





    Int i;

    i = 0;




    Time_Current(start);




    while (i < count)
    {
        //HelloSpeed();


        i = i + 1;
    }




    Time_Current(end);




    Int a;

    a = i * 1 - 2;



    TakeA(a);





    Int startTick;


    startTick = Time_GetTick(start);




    Int endTick;


    endTick = Time_GetTick(end);






    Int tickEllapsed;


    tickEllapsed = endTick - startTick;







    Object format;



    format = Format_New();



    Format_Init(format);






    Int o = CastInt(" ms");



    Int baseLength = String_ConstantLength(o);




    Object base;
    


    base = String_New();



    String_Init(base);




    String_SetLength(base, baseLength);


    String_SetData(base, o);









    Object result = String_New();



    String_Init(result);





    Int arg = 0;


    Int index = 0;


    Int type = 0;


    Int value = 0;



    Int argCount = 1;




    Format_SetBase(format, base);




    Format_SetArgCount(format, argCount);




    Format_Open(format);








    arg = 0;


    index = 0;


    type = 1;

    
    value = tickEllapsed;




    SetFormatArg(format, arg, index, type, value);

    






    Int resultLength = Format_Length(format);




    Int resultBuffer = New(resultLength);




    String_SetLength(result, resultLength);



    String_SetData(result, resultBuffer);






    Format_SetString(format, result);






    Format_Result(format);





    Format_Close(format);








    Object console;
    
    

    console = Console_New();



    Console_Init(console);



    Console_Write(console, result);



    Console_Final(console);



    Console_Delete(console);








    Delete(resultBuffer);





    String_Final(result);



    String_Delete(result);










    String_Final(base);



    String_Delete(base);





    Format_Final(format);



    Format_Delete(format);




    return true;
}





Bool FontExecute()
{
    Int u;

    u = CastInt("Cascadia Mono");



    Int length;

    length = String_ConstantLength(u);




    Int font;

    font = Font_Create(length, u, 20, 700, true, false);




    Int o;

    o = CastInt("Font Create Call Done\n");



    ConsoleWriteCharArray(o);



    return true;
}






int main(int argc, char* argv[])
{
    Infra_Form_Init();






    ExecuteFormat();





    DemoExecute();





    ListExecute();





    TimeExecute();





    StorageExecute();





    FrameExecute();





    FontExecute();




    // DemoCExecute();
    





    //SpeedDemoExecute();







    Infra_Form_Final();




    return 0;
}