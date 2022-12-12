#pragma once





#ifndef UNICODE
#define UNICODE
#endif



#define OEMRESOURCE



#include <windows.h>





DWORD Windows_GetCurrentThreadId();


HANDLE Windows_CreateThread(
    LPSECURITY_ATTRIBUTES lpThreadAttributes, 
    SIZE_T dwStackSize, 
    LPTHREAD_START_ROUTINE lpStartAddress, 
    LPVOID lpParameter, 
    DWORD dwCreationFlags, 
    LPDWORD lpThreadId
    );


void Windows_Sleep(DWORD dwMilliseconds);


BOOL Windows_WaitOnAddress(volatile void *Address, PVOID CompareAddress, SIZE_T AddressSize, DWORD dwMilliseconds);


void Windows_WakeByAddressSingle(PVOID Address);


HANDLE Windows_CreateMutexW(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCWSTR lpName);


BOOL Windows_ReleaseMutex(HANDLE hMutex);


DWORD Windows_WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds);


void Windows_GetSystemTime(LPSYSTEMTIME lpSystemTime);


BOOL Windows_InvalidateRect(HWND hWnd, const RECT *lpRect, BOOL bErase);


int Windows_ShowCursor(BOOL bShow);


HDC Windows_GetDC(HWND hWnd);


ATOM Windows_RegisterClassExW(const WNDCLASSEXW * wc);


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
    );


LONG_PTR Windows_GetWindowLongPtrW(HWND hWnd, int nIndex);


LONG_PTR Windows_SetWindowLongPtrW(HWND hWnd, int nIndex, LONG_PTR dwNewLong);


BOOL Windows_SetWindowPos(HWND hWnd, HWND hWndInsertAfter, int X, int Y, int cx, int cy, UINT uFlags);


BOOL Windows_SystemParametersInfoW(UINT uiAction, UINT uiParam, PVOID pvParam, UINT fWinIni);


BOOL Windows_GetWindowRect(HWND hWnd, LPRECT lpRect);


BOOL Windows_ShowWindow(HWND hWnd, int nCmdShow);


HBITMAP Windows_CreateDIBSection(HDC hdc, const BITMAPINFO *pbmi, UINT usage, void **ppvBits, HANDLE hSection, DWORD offset);


HDC Windows_CreateCompatibleDC(HDC hdc);


HGDIOBJ Windows_SelectObject(HDC hdc, HGDIOBJ h);


HDC Windows_BeginPaint(HWND hWnd, LPPAINTSTRUCT lpPaint);


BOOL Windows_EndPaint(HWND hWnd, const PAINTSTRUCT *lpPaint);


BOOL Windows_GetUpdateRect(HWND hWnd, LPRECT lpRect, BOOL bErase);


BOOL Windows_BitBlt(HDC hdc, int x, int y, int cx, int cy, HDC hdcSrc, int x1, int y1, DWORD rop);


HANDLE Windows_LoadImageW(HINSTANCE hInst, LPCWSTR name, UINT type, int cx, int cy, UINT fuLoad);


BOOL Windows_GetMessageW(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax);


LRESULT Windows_DispatchMessageW(const MSG *lpMsg);


void Windows_PostQuitMessage(int nExitCode);


LRESULT Windows_DefWindowProcW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);