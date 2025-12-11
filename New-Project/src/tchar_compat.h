/* tchar.h Compatibility Stub for Linux */
#ifndef _TCHAR_COMPAT_H_
#define _TCHAR_COMPAT_H_

#ifdef _WIN32
    #include <tchar.h>
#else
    /* Simple stub - tchar tidak banyak digunakan di project ini */
    #include <string>
    typedef char _TCHAR;
    #define _T(x) x
    #define _tcslen strlen
    #define _tcscpy strcpy
#endif

#endif
