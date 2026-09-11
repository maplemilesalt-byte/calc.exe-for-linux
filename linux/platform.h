#ifndef CALC_LINUX_PLATFORM_H
#define CALC_LINUX_PLATFORM_H

/* Small compatibility layer for the experimental Linux port. */

#include <stddef.h>
#include <stdint.h>

typedef int BOOL;
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

typedef uint32_t COLORREF;
typedef int32_t LONG;
typedef uint32_t DWORD;
typedef uint32_t UINT;
typedef int INT;
typedef uint16_t WORD;
typedef uintptr_t ULONG_PTR;
typedef uintptr_t WPARAM;
typedef intptr_t LPARAM;
typedef intptr_t LRESULT;
typedef char TCHAR;
typedef char *LPTSTR;
typedef const char *LPCTSTR;
typedef void *HWND;
typedef void *HINSTANCE;
typedef void VOID;

#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef CALLBACK
#define CALLBACK
#endif
#ifndef NEAR
#define NEAR
#endif
#ifndef TEXT
#define TEXT(x) x
#endif

#endif /* CALC_LINUX_PLATFORM_H */
