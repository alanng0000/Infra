#include "Font.h"





Int Font_Create(Int nameLength, Int name, Int size, Int weight, Bool italic, Bool underline)
{
    DWORD ui;

    ui = FALSE;


    if (italic)
    {
        ui = TRUE;
    }



    DWORD uu;

    uu = FALSE;


    if (underline)
    {
        uu = TRUE;
    }






    Int k;


    k = nameLength + 1;



    Int p;


    p = New(k);



    Copy(p, name, nameLength);





    LPCSTR faceName;

    faceName = p;





    HFONT u;
    
    
    u = Windows_CreateFontA(size, 0, 0, 0, weight, ui, uu, 
        FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, 
        CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_DONTCARE, faceName);





    Delete(p);




    Int o;

    o = u;



    Int ret;

    ret = o;


    return ret;
}