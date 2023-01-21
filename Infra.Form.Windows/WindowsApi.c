#include "WindowsApi.h"




Bool Windows_ApiResultCheck(Bool cond, DWORD errorCode, Char* functionName)
{
    Bool b = (errorCode == 0);


    if (!(cond && b))
    {
        Char* apiFunctionName = &functionName[8];



        Windows_Error(apiFunctionName, errorCode);
    }



    return true;
}





#define Check(cond) Windows_ApiResultCheck(cond, errorCode, __FUNCTION__)






#define Start \
    DWORD errorCode = 0;\
    SetLastError(errorCode);



#define End \
    errorCode = GetLastError();





DWORD Windows_GetCurrentThreadId()
{
    Start;


    DWORD m = GetCurrentThreadId();


    End;
    
    
    Check(m != 0);


    DWORD ret = m;
    
    return ret;
}






HANDLE Windows_CreateThread(
        LPSECURITY_ATTRIBUTES lpThreadAttributes, 
        SIZE_T dwStackSize, 
        LPTHREAD_START_ROUTINE lpStartAddress, 
        LPVOID lpParameter, 
        DWORD dwCreationFlags, 
        LPDWORD lpThreadId
        )
{
    Start;


    HANDLE m = CreateThread(
        lpThreadAttributes, 
        dwStackSize, 
        lpStartAddress, 
        lpParameter, 
        dwCreationFlags, 
        lpThreadId
        );


    End;


    Check(m != null);


    HANDLE ret = m;

    return ret;
}






void Windows_Sleep(DWORD dwMilliseconds)
{
    Sleep(dwMilliseconds);
}






BOOL Windows_WaitOnAddress(volatile void *Address, PVOID CompareAddress, SIZE_T AddressSize, DWORD dwMilliseconds)
{
    Start;


    BOOL m = WaitOnAddress(Address, CompareAddress, AddressSize, dwMilliseconds);


    End;


    Check(m != 0);


    BOOL ret = m;

    return ret;
}



void Windows_WakeByAddressSingle(PVOID Address)
{
    WakeByAddressSingle(Address);
}





HANDLE Windows_CreateMutexW(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCWSTR lpName)
{
    Start;


    HANDLE m = CreateMutexW(lpMutexAttributes, bInitialOwner, lpName);


    End;


    Check(m != null);


    HANDLE ret = m;

    return ret;
}





BOOL Windows_ReleaseMutex(HANDLE hMutex)
{
    Start;


    BOOL m = ReleaseMutex(hMutex);


    End;


    Check(m != 0);


    BOOL ret = m;

    return ret;
}





DWORD Windows_WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds)
{
    Start;


    DWORD m = WaitForSingleObject(hHandle, dwMilliseconds);


    End;


    Check(true);


    DWORD ret = m;

    return ret;
}




void Windows_GetSystemTime(LPSYSTEMTIME lpSystemTime)
{
    GetSystemTime(lpSystemTime);
}





BOOL Windows_InvalidateRect(HWND hWnd, const RECT *lpRect, BOOL bErase)
{
    Start;


    BOOL m = InvalidateRect(hWnd, lpRect, bErase);


    End;


    Check(m != 0);
    

    BOOL ret = m;

    return ret;
}




int Windows_ShowCursor(BOOL bShow)
{
    Start;


    int m = ShowCursor(bShow);


    End;


    Check(true);


    int ret = m;

    return ret;
}






HDC Windows_GetDC(HWND hWnd)
{
    Start;


    HDC m = GetDC(hWnd);


    End;


    Check(m != null);


    HDC ret = m;

    return ret;
}




ATOM Windows_RegisterClassExW(const WNDCLASSEXW* wc)
{
    Start;


    ATOM m = RegisterClassExW(wc);


    End;


    Check(m != 0);


    ATOM ret = m;

    return ret;
}





HWND Windows_CreateWindowExW(
        DWORD dwExStyle, 
        LPCWSTR lpClassName, 
        LPCWSTR lpWindowName, 
        DWORD dwStyle, 
        int X, 
        int Y, 
        int nWidth, 
        int nHeight, 
        HWND hWndParent, 
        HMENU hMenu, 
        HINSTANCE hInstance, 
        LPVOID lpParam
        )
{
    Start;


    HWND m = CreateWindowExW(
        dwExStyle, 
        lpClassName, 
        lpWindowName, 
        dwStyle, 
        X, 
        Y, 
        nWidth, 
        nHeight, 
        hWndParent, 
        hMenu, 
        hInstance, 
        lpParam
        );


    End;


    Check(m != null);


    HWND ret = m;

    return ret;
}






LONG_PTR Windows_GetWindowLongPtrW(HWND hWnd, int nIndex)
{
    Start;


    LONG_PTR m = GetWindowLongPtrW(hWnd, nIndex);


    End;


    Check(m != 0);


    LONG_PTR ret = m;

    return ret;
}




LONG_PTR Windows_SetWindowLongPtrW(HWND hWnd, int nIndex, LONG_PTR dwNewLong)
{
    Start;


    LONG_PTR m = SetWindowLongPtrW(hWnd, nIndex, dwNewLong);


    End;


    Check(true);


    LONG_PTR ret = m;

    return ret;
}





BOOL Windows_SetWindowPos(HWND hWnd, HWND hWndInsertAfter, int X, int Y, int cx, int cy, UINT uFlags)
{
    Start;


    BOOL m = SetWindowPos(hWnd, hWndInsertAfter, X, Y, cx, cy, uFlags);


    End;


    Check(m != 0);


    BOOL ret = m;

    return ret;
}





int Windows_GetDeviceCaps(HDC hdc, int index)
{
    Start;


    int m = GetDeviceCaps(hdc, index);


    End;



    int ret = m;

    return ret;
}





BOOL Windows_SystemParametersInfoW(UINT uiAction, UINT uiParam, PVOID pvParam, UINT fWinIni)
{
    Start;


    BOOL m = SystemParametersInfoW(uiAction, uiParam, pvParam, fWinIni);


    End;


    Check(m != 0);


    BOOL ret = m;

    return ret;
}





BOOL Windows_GetWindowRect(HWND hWnd, LPRECT lpRect)
{
    Start;


    BOOL m = GetWindowRect(hWnd, lpRect);


    End;


    Check(m != 0);


    BOOL ret = m;

    return ret;
}





BOOL Windows_ShowWindow(HWND hWnd, int nCmdShow)
{
    Start;


    BOOL m = ShowWindow(hWnd, nCmdShow);


    End;


    Check(true);


    BOOL ret = m;

    return ret;
}





HBITMAP Windows_CreateDIBSection(HDC hdc, const BITMAPINFO *pbmi, UINT usage, void **ppvBits, HANDLE hSection, DWORD offset)
{
    Start;


    HBITMAP m = CreateDIBSection(hdc, pbmi, usage, ppvBits, hSection, offset);


    End;


    Bool na = (m != null);

    Bool nb = ((*ppvBits) != null);


    Check(na && nb);


    HBITMAP ret = m;

    return ret;
}





HDC Windows_CreateCompatibleDC(HDC hdc)
{
    Start;


    HDC m = CreateCompatibleDC(hdc);


    End;


    Check(m != null);


    HDC ret = m;

    return ret;
}






HGDIOBJ Windows_SelectObject(HDC hdc, HGDIOBJ h)
{
    Start;


    HGDIOBJ m = SelectObject(hdc, h);


    End;


    Check(m != null);


    HGDIOBJ ret = m;

    return ret;
}





HGDIOBJ Windows_GetStockObject(int i)
{
    Start;


    HGDIOBJ m = GetStockObject(i);


    End;



    Check(!(m == NULL));


    HGDIOBJ ret = m;

    return ret;
}





HDC Windows_BeginPaint(HWND hWnd, LPPAINTSTRUCT lpPaint)
{
    Start;


    HDC m = BeginPaint(hWnd, lpPaint);


    End;


    Check(m != null);


    HDC ret = m;

    return ret;
}




BOOL Windows_EndPaint(HWND hWnd, const PAINTSTRUCT *lpPaint)
{
    Start;


    BOOL m = EndPaint(hWnd, lpPaint);


    End;


    Check(true);


    BOOL ret = m;

    return ret;
}





BOOL Windows_GetUpdateRect(HWND hWnd, LPRECT lpRect, BOOL bErase)
{
    Start;


    BOOL m = GetUpdateRect(hWnd, lpRect, bErase);


    End;


    Check(true);


    BOOL ret = m;

    return ret;
}





BOOL Windows_BitBlt(HDC hdc, int x, int y, int cx, int cy, HDC hdcSrc, int x1, int y1, DWORD rop)
{
    Start;


    BOOL m = BitBlt(hdc, x, y, cx, cy, hdcSrc, x1, y1, rop);


    End;


    Check(m != 0);


    BOOL ret = m;

    return ret;
}





HANDLE Windows_LoadImageW(HINSTANCE hInst, LPCWSTR name, UINT type, int cx, int cy, UINT fuLoad)
{
    Start;


    HANDLE m = LoadImageW(hInst, name, type, cx, cy, fuLoad);


    End;


    Check(m != null);


    HANDLE ret = m;

    return ret;
}







BOOL Windows_GetMessageW(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax)
{
    Start;


    BOOL m = GetMessageW(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);


    End;


    Check(m != -1);


    BOOL ret = m;

    return ret;
}





LRESULT Windows_DispatchMessageW(const MSG *lpMsg)
{
    LRESULT m = DispatchMessageW(lpMsg);


    LRESULT ret = m;

    return ret;
}







void Windows_PostQuitMessage(int nExitCode)
{
    Start;


    PostQuitMessage(nExitCode);


    End;
}






LRESULT Windows_DefWindowProcW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    LRESULT m = DefWindowProcW(hWnd, Msg, wParam, lParam);


    LRESULT ret = m;

    return ret;
}






Bool Windows_Error(Char* functionName, Int32 errorCode)
{        
    Int n = errorCode;





    Int oa = CastInt("Error: Windows API Call ");




    Int ob = CastInt(functionName);




    Int oc = CastInt(" Fail, Code: ");





    Object format = Format_New();



    Format_Init(format);





    Int errorCodeLength = Format_HexInt32Length(format);




    Int errorCodeChars = New(errorCodeLength);




    Format_HexInt32(format, errorCodeChars, n);







    Int ka = String_ConstantLength(oa);


    Int kb = String_ConstantLength(ob);


    Int kc = String_ConstantLength(oc);


    Int kd = errorCodeLength;




    Int totalLength = ka + kb + kc + kd;




    Int stBuffer = New(totalLength);




    Object st = String_New();



    String_Init(st);




    String_SetLength(st, totalLength);



    String_SetData(st, stBuffer);




    Int length = 0;



    String_Copy(st, oa, length, ka);



    length = length + ka;



    String_Copy(st, ob, length, kb);



    length = length + kb;



    String_Copy(st, oc, length, kc);



    length = length + kc;



    String_Copy(st, errorCodeChars, length, kd);



    length = length + kd;





    Object console = Console_New();



    Console_Init(console);



    Console_Write(console, st);



    Console_Final(console);



    Console_Delete(console);






    String_Final(st);



    String_Delete(st);





    Delete(stBuffer);






    Delete(errorCodeChars);





    Format_Final(format);



    Format_Delete(format);



    



    Exit(1);




    return true;
}