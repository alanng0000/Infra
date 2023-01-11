#pragma once




#include "WindowsLocal.h"




#include "Local.h"




#include <Infra.Form.Infra/Public.h>




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




} Frame;





Bool Frame_CopyString(WCHAR* result, Object string);





Bool Frame_InitWindow(Frame* this);



Bool Frame_InitWindowTitle(Frame* this);



Bool Frame_InitWindowStyle(Frame* this);



Bool Frame_InitWindowSize(Frame* this);




LONG_PTR Frame_UnsetBit(LONG_PTR value, Int32 bit);






Frame* Frame_GetFrame(HWND hwnd);







Bool Frame_TransferBlock(Frame* frame, Int left, Int up, Int width, Int height);




Bool Frame_EventHandle(Int hwnd, Int32 uMsg, Int wParam, Int lParam);





LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);