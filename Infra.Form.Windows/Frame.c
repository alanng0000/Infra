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




    Object lockRect = Rect_New();


    Rect_Init(lockRect);



    Object lockRectPos = Pos_New();


    Pos_Init(lockRectPos);



    Object lockRectSize = Size_New();


    Size_Init(lockRectSize);





    Rect_SetPos(lockRect, lockRectPos);



    Rect_SetSize(lockRect, lockRectSize);




    m->LockRect = lockRect;





    Frame_InitWindow(m);



    Frame_InitBitmap(m);



    return true;
}




Bool Frame_Final(Object this)
{
    Frame* m = CastPointer(this);



    Size_Final(m->Size);


    Size_Delete(m->Size);





    Delete(CastInt(m->WindowTitle));




    Object lockRect = m->LockRect;


    Object lockPos = Rect_GetPos(lockRect);


    Object lockSize = Rect_GetSize(lockRect);



    Pos_Final(lockPos);


    Pos_Delete(lockPos);



    Size_Final(lockSize);

    
    Size_Delete(lockSize);



    Rect_Final(lockRect);


    Rect_Delete(lockRect);



    return true;
}







Bool Frame_InitWindow(Frame* this)
{
    Frame_InitWindowTitle(this);




    HINSTANCE hInstance = this->HInstance;


    WCHAR* className  = L"Machine Window Class";


    WNDCLASSEXW wc = { 0 };

    wc.cbSize = sizeof(WNDCLASSEXW);


    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = className;
    wc.hCursor = NULL;


    Windows_RegisterClassExW(&wc);
    


    WCHAR* title = this->WindowTitle;


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




    this->Hwnd = hwnd;



    this->Hdc = Windows_GetDC(this->Hwnd);




    LONG_PTR o = (LONG_PTR)this;


    Windows_SetWindowLongPtrW(this->Hwnd, GWLP_USERDATA, o);



    Frame_InitWindowStyle(this);


    Frame_InitWindowSize(this);



    Windows_ShowCursor(FALSE);



    return true;
}




Bool Frame_InitWindowTitle(Frame* this)
{
    Object title = this->Title;



    Int titleLength = String_GetLength(title);



    Int charCount = titleLength + 1;



    Int size = charCount * sizeof(WCHAR);



    WCHAR* u = CastPointer(New(size));



    Frame_CopyString(u, title);



    this->WindowTitle = u;



    return true;
}





Bool Frame_InitWindowStyle(Frame* this)
{
    HWND hwnd = this->Hwnd;


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




Bool Frame_InitWindowSize(Frame* this)
{
    int w = Windows_GetDeviceCaps(this->Hdc, HORZRES);



    int h = Windows_GetDeviceCaps(this->Hdc, VERTRES);




    HWND hwnd = this->Hwnd;


    Windows_SetWindowPos(hwnd, HWND_TOP, 0, 0, w, h, SWP_NOZORDER);



    RECT rect = { 0 };

    Windows_GetWindowRect(hwnd, &rect);



    Int left = rect.left;


    Int right = rect.right;


    Int up = rect.top;


    Int down = rect.bottom;



    Int width = right - left;


    Int height = down - up;



    Object size = this->Size;



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





Bool Frame_InitBitmap(Frame* this)
{
    Object size = this->Size;


    Int width = Size_GetWidth(size);


    Int height = Size_GetHeight(size);




    int u = 0;



    u = (int)width;


    LONG w = u;



    u = (int)height;


    LONG h = u;



    BITMAPINFO bitmapInfo = { 0 };

    
    BITMAPINFOHEADER bmiHeader = { 0 };

    bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    
    bmiHeader.biWidth = w;
    
    bmiHeader.biHeight = - h;
    
    bmiHeader.biPlanes = 1;
    
    bmiHeader.biBitCount = 32;

    bmiHeader.biCompression = BI_RGB;

    bmiHeader.biSizeImage = 0;

    bmiHeader.biXPelsPerMeter = 0;

    bmiHeader.biYPelsPerMeter = 0;

    bmiHeader.biClrUsed = 0;

    bmiHeader.biClrImportant = 0;


    bitmapInfo.bmiHeader = bmiHeader;


    RGBQUAD d = { 0 };
    
    d.rgbRed = 0;

    d.rgbGreen = 0;
    
    d.rgbBlue = 0;
    
    d.rgbReserved = 0;


    bitmapInfo.bmiColors[0] = d;



    void* pixelsDataBuffer = null;


    HBITMAP hBitmap = Windows_CreateDIBSection(null, &bitmapInfo, DIB_RGB_COLORS, &pixelsDataBuffer, null, 0);




    Int32* pixelsData = (Int32*)pixelsDataBuffer;



    this->HBitmap = hBitmap;


    this->Pixels = pixelsData;



    Frame_InitBitmapBuffer(this);




    HDC srcDc = Windows_CreateCompatibleDC(this->Hdc);


    this->SrcDc = srcDc;
    

    Windows_SelectObject(this->SrcDc, this->HBitmap);


    return true;
}




Bool Frame_InitBitmapBuffer(Frame* this)
{
    Int32 color = 0x000000ff;


    Object size = this->Size;



    Int32 width = (Int32)Size_GetWidth(size);


    Int32 height = (Int32)Size_GetHeight(size);


    Int32* pixels = this->Pixels;



    Int32 i = 0;

    Int32 j = 0;

    Int32 u = 0;


    i = 0;

    while (i < height)
    {
        j = 0;

        while (j < width)
        {
            u = i * width + j;

            pixels[u] = color;


            j++;
        }

        i++;
    }


    return true;
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
    Frame* m = CastPointer(this);


    return m->Visible;
}





Bool Frame_SetVisible(Object this, Bool value)
{
    Frame* m = CastPointer(this);



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






Bool Frame_SetControlHandle(Object this, Frame_ControlHandle_Method value)
{
    Frame* m = CastPointer(this);



    m->ControlHandle = value;


    return true;
}






Frame* Frame_GetFrame(HWND hwnd)
{
    LONG_PTR o = Windows_GetWindowLongPtrW(hwnd, GWLP_USERDATA);


    Frame* p = (Frame*)o;


    Frame* ret = p;


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



            Frame* frame = Frame_GetFrame(o);



            PAINTSTRUCT ot = { 0 };



            HDC hdc = Windows_BeginPaint(o, &ot);





            Windows_EndPaint(o, &ot);
        }
        handled = true;
        break;


        case WM_KEYDOWN:
        {
            Byte key = (Byte)wParam;


            HWND o = (HWND)hwnd;


            Frame* frame = Frame_GetFrame(o);



            Object h = (Object)frame;



            frame->ControlHandle(h, key, true);
        }
        handled = true;
        break;


        case WM_KEYUP:
        {
            Byte key = (Byte)wParam;


            HWND o = (HWND)hwnd;


            Frame* frame = Frame_GetFrame(o);



            Object h = (Object)frame;



            frame->ControlHandle(h, key, false);
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