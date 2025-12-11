/* Windows.h Compatibility Wrapper for Linux */
#ifndef _WINDOWS_COMPAT_H_
#define _WINDOWS_COMPAT_H_

#ifdef _WIN32
    #include <windows.h>
#else
    /* Dummy types untuk kompatibilitas Linux */
    typedef void* HANDLE;
    typedef unsigned long DWORD;
    typedef int BOOL;
    typedef void* HINSTANCE;
    typedef char* LPSTR;
    typedef unsigned int UINT;
    typedef int WPARAM;
    typedef int LPARAM;
    typedef int HWND;
    typedef int LRESULT;
    typedef int WNDPROC;
    typedef int WNDCLASS;
    typedef void* HMODULE;

    #define TRUE 1
    #define FALSE 0
    #define GetLogicalDrives() 0
    #define GetModuleHandleA(x) NULL
    #define GetModuleHandle(x) NULL
    #define CreateWindow(...) NULL
    #define UnregisterClass(...) 
    #define WS_POPUP 0
    
    /* Stub untuk ImGui Win32 */
    #define IMGUI_IMPL_API
    inline LRESULT ImGui_ImplWin32_WndProcHandler(HWND window, UINT message, WPARAM wideParameter, LPARAM longParameter) { return 0; }
#endif

#endif
