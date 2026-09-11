#ifndef SCICALC_H
#define SCICALC_H

#define CALC_COMPILE

#ifdef CALC_LINUX
#include "linux/platform.h"
#include <stdint.h>
#include <stddef.h>
#include "scimath.h"
#include "resource.h"
#include "wassert.h"

typedef int32_t LONG;
typedef uint32_t DWORD;
typedef uint32_t UINT;
typedef int32_t INT;
typedef uintptr_t ULONG_PTR;
typedef uintptr_t WPARAM;
typedef intptr_t LPARAM;
typedef intptr_t LRESULT;
typedef void *HINSTANCE;
typedef void *HWND;
typedef char TCHAR;
typedef char *LPTSTR;
typedef const char *LPCTSTR;
typedef unsigned short WORD;
typedef int BOOL;
#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif
#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef WINAPI
#define WINAPI
#endif
#ifndef CALLBACK
#define CALLBACK
#endif
#ifndef VOID
#define VOID void
#endif
#ifndef NEAR
#define NEAR
#endif
#ifndef TEXT
#define TEXT(x) x
#endif
#else
#define NOGDICAPMASKS
#define NOSYSMETRICS
#define NODRAWFRAME
#define NOKEYSTATES
#define OEMRESOURCE
#define NOATOM
#define NOMETAFILE
#define NOOPENFILE
#define NOSOUND
#define NOWH
#define NOCOMM
#define NOKANJI
#include <windows.h>
#include <windowsx.h>
#include "scimath.h"
#include "resource.h"
#include "wassert.h"
#include <htmlhelp.h>
#endif

#define CSTRMAX 256
#ifdef DEBUG
#define CCHSTRINGSMAX 3
#else
#define CCHSTRINGSMAX 1024
#endif

#define CMS_CALC_TIMEOUT (10 * 1000)
#define CMS_MAX_TIMEOUT (40 * 1000)
#define xwParam(x,y) ((wParam >=x) && (wParam <=y))
#define RSHF 7

#define SCERR_DIVIDEZERO 0
#define SCERR_DOMAIN 1
#define SCERR_UNDEFINED 2
#define SCERR_POS_INFINITY 3
#define SCERR_NEG_INFINITY 4
#define SCERR_ABORTED 5
#define F_INTMATH() (nRadix != 10)

#ifndef CALC_LINUX
LRESULT APIENTRY CalcWndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR APIENTRY StatBoxProc(HWND, UINT, WPARAM, LPARAM);
VOID APIENTRY DisplayError(INT);
VOID APIENTRY EnableToggles(BOOL bEnable);
VOID APIENTRY InitSciCalc(BOOL);
VOID APIENTRY MenuFunctions(DWORD);
VOID APIENTRY SciCalcFunctions(PHNUMOBJ phnoNum, DWORD wOp);
VOID APIENTRY SetStat(BOOL);
VOID APIENTRY StatFunctions(WPARAM);
VOID DisplayNum(VOID);
void DoOperation(INT nOperation, HNUMOBJ *phnoNum, HNUMOBJ hnoX);
VOID NEAR ProcessCommands(WPARAM);
VOID NEAR SetBox(int, BOOL);
VOID NEAR SetRadix(DWORD);
LONG NEAR StatAlloc(WORD, DWORD);
VOID NEAR StatError(VOID);
void SwitchModes(DWORD wRadix, int nDecMode, int nHexMode);
BOOL SetWaitCursor(BOOL fOn);
BOOL SetDisplayText(HWND, LPCTSTR);
COLORREF GetKeyColor(int iID);
ULONG_PTR GetHelpID(int iID);
#endif

void RecalcNumObjConstants(void);
void KillTimeCalc(void);
void TimeCalc(BOOL fStart);

#define INDEXFROMID(x) ((x)-IDC_FIRSTCONTROL)

extern HWND g_hwndDlg;
extern HINSTANCE hInst;
extern ANGLE_TYPE nDecMode;
extern long nRadix;
extern long nPrecision;
extern long dwWordBitWidth;
extern BOOL bInv;
extern BOOL bHyp;
extern int nCalc;
extern int nHexMode;
extern HNUMOBJ g_ahnoChopNumbers[];
extern BOOL bFarEast;

#endif /* SCICALC_H */
