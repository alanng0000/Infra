#include "Frame.h"




InfraClassNew(Frame)





Object Frame_GetTitle(Object this)
{
    Frame* m = CastPointer(this);



    return m->Title;
}




Bool Frame_SetTitle(Object this, Object value)
{
    Frame* m = CastPointer(this);



    m->Title = value;



    return true;
}




Bool Frame_Init(Object this)
{
    Frame* m = CastPointer(this);



    Object size = Size_New();



    Size_Init(size);



    m->Size = size;





    Frame_InitWindow(this);





    return true;
}




Bool Frame_Final(Object this)
{
    Frame* m = CastPointer(this);



    Size_Final(m->Size);


    Size_Delete(m->Size);





    Delete(CastInt(m->WindowTitle));





    return true;
}







Bool Frame_InitWindow(Object this)
{
    Frame* m;

    m = CastPointer(this);



    Frame_InitWindowTitle(this);




    HINSTANCE hInstance = m->HInstance;


    WCHAR* className  = L"Machine Window Class";


    WNDCLASSEXW wc = { 0 };

    wc.cbSize = sizeof(WNDCLASSEXW);


    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = className;
    wc.hbrBackground  = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wc.hCursor = NULL;


    Windows_RegisterClassExW(&wc);
    


    WCHAR* title = m->WindowTitle;


    HWND hwnd = Windows_CreateWindowExW(
        0,
        className,
        title,
        WS_MAXIMIZE,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        null,
        null,
        hInstance,
        null
        );




    m->Hwnd = hwnd;



    m->Hdc = Windows_GetDC(m->Hwnd);




    LONG_PTR o;
    
    o = (LONG_PTR)m;



    Windows_SetWindowLongPtrW(m->Hwnd, GWLP_USERDATA, o);



    Frame_InitWindowStyle(this);


    Frame_InitWindowSize(this);



    Windows_ShowCursor(FALSE);



    return true;
}




Bool Frame_InitWindowTitle(Object this)
{
    Frame* m;

    m = CastPointer(this);



    Object title;
    
    title = m->Title;



    Int titleLength = String_GetLength(title);



    Int charCount = titleLength + 1;



    Int size = charCount * sizeof(WCHAR);



    Int p;

    p = New(size);



    WCHAR* u = CastPointer(p);



    Frame_CopyString(u, title);



    m->WindowTitle = u;



    return true;
}





Bool Frame_InitWindowStyle(Object this)
{
    Frame* m;

    m = CastPointer(this);



    HWND hwnd = m->Hwnd;


    LONG_PTR d = Windows_GetWindowLongPtrW(hwnd, GWL_STYLE);


    d = Frame_UnsetBit(d, WS_BORDER);

    d = Frame_UnsetBit(d, WS_CAPTION);

    d = Frame_UnsetBit(d, WS_SYSMENU);

    d = Frame_UnsetBit(d, WS_THICKFRAME);

    d = Frame_UnsetBit(d, WS_MINIMIZEBOX);

    d = Frame_UnsetBit(d, WS_MAXIMIZEBOX);

    d = Frame_UnsetBit(d, WS_CLIPSIBLINGS);


    Windows_SetWindowLongPtrW(hwnd, GWL_STYLE, d);


    Windows_SetWindowLongPtrW(hwnd, GWL_EXSTYLE, 0);


    return true;
}




Bool Frame_InitWindowSize(Object this)
{
    Frame* m;

    m = CastPointer(this);




    int w = Windows_GetDeviceCaps(m->Hdc, HORZRES);



    int h = Windows_GetDeviceCaps(m->Hdc, VERTRES);




    HWND hwnd;
    
    hwnd = m->Hwnd;


    Windows_SetWindowPos(hwnd, HWND_TOP, 0, 0, w, h, SWP_NOZORDER);



    RECT rect = { 0 };

    Windows_GetWindowRect(hwnd, &rect);



    Int left = rect.left;


    Int right = rect.right;


    Int up = rect.top;


    Int down = rect.bottom;



    Int width = right - left;


    Int height = down - up;



    Object size;
    
    size = m->Size;



    Size_SetWidth(size, width);


    Size_SetHeight(size, height);


    return true;
}





LONG_PTR Frame_UnsetBit(LONG_PTR value, Int32 bit)
{
    LONG_PTR d = value;


    Int o = bit;


    Int m = ~ o;


    d = d & m;


    LONG_PTR ret = d;

    return ret;
}







Bool Frame_CopyString(WCHAR* result, Object string)
{
    Int count = String_GetLength(string);



    Int w = 0;



    WCHAR o = L'\0';



    Int i = 0;


    while (i < count)
    {
        w = String_Char(string, i);


        o = (WCHAR)w;


        result[i] = o;



        i++;
    }



    result[count] = L'\0';



    return true;
}





Bool Frame_GetVisible(Object this)
{
    Frame* m;
    
    m = CastPointer(this);


    return m->Visible;
}





Bool Frame_SetVisible(Object this, Bool value)
{
    Frame* m;
    
    m = CastPointer(this);



    int o = SW_HIDE;


    if (value)
    {
        o = SW_SHOW;
    }



    Windows_ShowWindow(m->Hwnd, o);



    m->Visible = value;



    return true;
}




Object Frame_GetSize(Object this)
{
    Frame* m = CastPointer(this);



    return m->Size;
}






Bool Frame_Update(Object this)
{
    Frame* m;

    m = CastPointer(this);



    HWND hwnd;
    
    hwnd = m->Hwnd;




    Windows_InvalidateRect(hwnd, NULL, FALSE);



    return true;
}






Int Frame_GetHandle(Object this)
{
    Frame* m;
    
    m = CastPointer(this);



    HDC u;

    u = m->Hdc;



    Int o;

    o = CastInt(u);


    return o;
}






Frame_ControlHandle_Method Frame_GetControlHandleMethod(Object this)
{
    Frame* m;
    
    m = CastPointer(this);



    return m->ControlHandle;
}




Int Frame_GetControlHandle(Object this)
{
    Frame_ControlHandle_Method method;

    method = Frame_GetControlHandleMethod(this);


    Int o;

    o = CastInt(method);


    return o;
}





Bool Frame_SetControlHandle(Object this, Int value)
{
    Frame* m;
    
    m = CastPointer(this);



    Frame_ControlHandle_Method method;

    method = CastPointer(value);



    m->ControlHandle = method;


    return true;
}






Frame_DrawHandle_Method Frame_GetDrawHandleMethod(Object this)
{
    Frame* m;
    
    m = CastPointer(this);



    return m->DrawHandle;
}






Int Frame_GetDrawHandle(Object this)
{
    Frame_DrawHandle_Method method;

    method = Frame_GetDrawHandleMethod(this);


    Int o;

    o = CastInt(method);


    return o;
}





Bool Frame_SetDrawHandle(Object this, Int value)
{
    Frame* m;
    
    m = CastPointer(this);



    Frame_DrawHandle_Method method;

    method = CastPointer(value);



    m->DrawHandle = method;


    return true;
}






Object Frame_GetDrawHandleArg(Object this)
{
    Frame* m;
    
    m = CastPointer(this);


    return m->DrawHandleArg;
}





Bool Frame_SetDrawHandleArg(Object this, Object value)
{
    Frame* m;
    
    m = CastPointer(this);


    m->DrawHandleArg = value;


    return true;
}






Object Frame_GetFrame(Int hwnd)
{
    HWND u;

    u = CastPointer(hwnd);




    LONG_PTR o;
    
    o = Windows_GetWindowLongPtrW(u, GWLP_USERDATA);




    Object frame;
    
    frame = (Object)o;



    Object ret;
    
    ret = frame;


    return ret;
}






Bool Frame_Close(Object this)
{
    Windows_PostQuitMessage(0);


    return true;
}





Bool Frame_Execute(Object this)
{
    MSG msg = { 0 };



    while (Windows_GetMessageW(&msg, null, 0, 0))
    {
        Windows_DispatchMessageW(&msg);
    }




    return true;
}






Bool Frame_EventHandle(Int hwnd, Int32 uMsg, Int wParam, Int lParam)
{
    Bool handled = false;


    switch (uMsg)
    {
        case WM_PAINT:
        {
            HWND o = (HWND)hwnd;



            Object frame;
            
            frame = Frame_GetFrame(hwnd);



            PAINTSTRUCT ot = { 0 };



            HDC hdc = Windows_BeginPaint(o, &ot);





            Object arg;

            arg = Frame_GetDrawHandleArg(frame);




            Frame_DrawHandle_Method method;

            method = Frame_GetDrawHandleMethod(frame);



            if (!(method == null))
            {
                method(arg);
            }



            Windows_EndPaint(o, &ot);
        }
        handled = true;
        break;


        case WM_KEYDOWN:
        {
            Byte key;
            
            key = (Byte)wParam;


            
            Object frame;
            

            frame = Frame_GetFrame(hwnd);



            Frame_ControlHandle_Method method;

            method = Frame_GetControlHandleMethod(frame);



            if (!(method == null))
            {
                method(frame, key, true);
            }
        }
        handled = true;
        break;


        case WM_KEYUP:
        {
            Byte key;
            
            key = (Byte)wParam;



            Object frame;
            

            frame = Frame_GetFrame(hwnd);



            Frame_ControlHandle_Method method;

            method = Frame_GetControlHandleMethod(frame);



            if (!(method == null))
            {
                method(frame, key, false);
            }
        }
        handled = true;
        break;


        case WM_DESTROY:
        {
            Windows_PostQuitMessage(0);
        }
        handled = true;
        break;


        default:
        break;
    }


    Bool ret = handled;

    return ret;
}






LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    Int d = (Int)hwnd;



    Bool handled = Frame_EventHandle(d, uMsg, wParam, lParam);



    LRESULT ret = 0;



    if (handled)
    {
        ret = 0;
    }
    else
    {
        ret = Windows_DefWindowProcW(hwnd, uMsg, wParam, lParam);
    }

    

    return ret;
}