/****************************Module*Header***********************************\
* Module Name: UNIFUNC.C
*
* Module Descripton: Number to string conversion routines for Unicode
****************************************************************************/
#ifndef CALC_LINUX
#include <windows.h>
#endif
#include "scicalc.h"

#define CCH_DWORD   15

TCHAR *UToDecT( UINT value, TCHAR *sz) {
    TCHAR szTmp[CCH_DWORD];
    LPTSTR psz = szTmp;
    LPTSTR pszOut;

    do {
        *psz++ = TEXT('0') + (value % 10);
        value = value / 10;
    } while( value != 0 );

    for( psz--, pszOut = sz; psz >= szTmp; psz-- )
        *pszOut++ = *psz;

    *pszOut = TEXT('\0');
    return sz;
}

#ifdef UNICODE
#   if 0
double MyAtof( const WCHAR *string ) {
    char szAnsi[MAX_PATH];
    WideCharToMultiByte( CP_ACP, WC_COMPOSITECHECK, string, -1, szAnsi, sizeof(szAnsi), NULL, NULL );
    return atof( szAnsi );
}

WCHAR *MyGcvt( double value, int digits, WCHAR *buffer ) {
    char szAnsi[MAX_PATH];
    _gcvt( value, digits, szAnsi);
    MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, szAnsi, -1, buffer, MAX_PATH);
    return buffer;
}
#   endif
#endif
