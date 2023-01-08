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




    HFONT u;
    
    
    u = Windows_CreateFontA(size, 0, 0, 0, weight, ui, uu, 
        FALSE, ANSI_CHARSET, DWORD iOutPrecision, DWORD iClipPrecision, 
        DWORD iQuality, DWORD iPitchAndFamily, LPCSTR pszFaceName);





    return 0;
}