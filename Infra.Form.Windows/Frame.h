#pragma once




#include "WindowsLocal.h"




#include "Local.h"







typedef struct
{
    Object Size;



    Bool Visible;




    Frame_ControlHandle_Method ControlHandle;



    Object Title;



    WCHAR* WindowTitle;



    HWND Hwnd;



    HINSTANCE HInstance;




    HDC Hdc;




}
Frame;







Bool Frame_InitWindow(Object this);



Bool Frame_InitWindowTitle(Object this);



Bool Frame_InitWindowStyle(Object this);



Bool Frame_InitWindowSize(Object this);




LONG_PTR Frame_UnsetBit(LONG_PTR value, Int32 bit);




Object Frame_GetFrame(Int hwnd);




Bool Frame_CopyString(WCHAR* result, Object string);





Frame_ControlHandle_Method Frame_GetControlHandleMethod(Object this);





Bool Frame_EventHandle(Int hwnd, Int32 uMsg, Int wParam, Int lParam);





LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);