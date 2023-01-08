#include "Font.h"





Int Font_Create(Int nameLength, Int name, Int size, Int weight, Bool italic, Bool underline)
{
    HFONT u;
    
    
    u = Windows_CreateFontA(size, 0, 0, 0, int cWeight, DWORD bItalic, DWORD bUnderline, DWORD bStrikeOut, DWORD iCharSet, DWORD iOutPrecision, DWORD iClipPrecision, DWORD iQuality, DWORD iPitchAndFamily, LPCSTR pszFaceName);





    return 0;
}