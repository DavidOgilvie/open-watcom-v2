/*
 *  windef.h    Win32 basic data types
 *
 * =========================================================================
 *
 *                          Open Watcom Project
 *
 * Copyright (c) 2004-2021 The Open Watcom Contributors. All Rights Reserved.
 *
 *    This file is automatically generated. Do not edit directly.
 *
 * =========================================================================
 */
 
#ifndef _WINDEF_
#define _WINDEF_

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file;
#endif

#include <_w32ials.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Define the STRICT macro for strict type checking. */
#ifndef NO_STRICT
    #ifndef STRICT
        #define STRICT  1
    #endif
#endif

/* Define default Windows version number. */
#ifndef WINVER
    #define WINVER  0x0400
#endif

/* Override default compiler behavior for these keywords. */
#define far
#define near
#define pascal  __stdcall

/* Calling conventions */
#undef pascal
#undef _pascal
#undef __pascal
#define pascal      __stdcall
#define _pascal     __stdcall
#define __pascal    __stdcall
#ifndef CDECL
    #define CDECL   __cdecl
#endif
#define CALLBACK    __stdcall
#define WINAPI      __stdcall
#define WINAPIV     __cdecl
#define APIENTRY    WINAPI
#define APIPRIVATE  __stdcall
#define PASCAL      __stdcall

/* Variable attributes */
#define FAR
#define NEAR
#define CONST const

/* Parameter attributes */
#define IN
#define OUT
#define OPTIONAL

/* Primitive data types */
typedef unsigned long   ULONG;
typedef ULONG           *PULONG;
typedef unsigned short  USHORT;
typedef USHORT          *PUSHORT;
typedef unsigned char   UCHAR;
typedef UCHAR           *PUCHAR;
typedef char            *PSZ;
typedef unsigned long   DWORD;
typedef int             BOOL;
typedef unsigned char   BYTE;
typedef unsigned short  WORD;
typedef float           FLOAT;
typedef FLOAT           *PFLOAT;
typedef BOOL            *PBOOL;
typedef BOOL            *LPBOOL;
typedef BYTE            *PBYTE;
typedef BYTE            *LPBYTE;
typedef int             *PINT;
typedef int             *LPINT;
typedef WORD            *PWORD;
typedef WORD            *LPWORD;
typedef long            *LPLONG;
typedef DWORD           *PDWORD;
typedef DWORD           *LPDWORD;
typedef void            *LPVOID;
typedef CONST void      *LPCVOID;
typedef int             INT;
typedef unsigned int    UINT;
typedef unsigned int    *PUINT;
typedef WORD            ATOM;
typedef DWORD           COLORREF;
typedef DWORD           *LPCOLORREF;

/* Function pointer data types */
typedef int (WINAPI *FARPROC)();
typedef int (WINAPI *NEARPROC)();
typedef int (WINAPI *PROC)();

#ifndef NT_INCLUDED
    #include <winnt.h>
#endif

/* Message parameters data types */
typedef UINT_PTR    WPARAM;
typedef LONG_PTR    LPARAM;
typedef LONG_PTR    LRESULT;

/* Handle data types */
DECLARE_HANDLE( HACCEL );
DECLARE_HANDLE( HBITMAP );
DECLARE_HANDLE( HBRUSH );
DECLARE_HANDLE( HDC );
DECLARE_HANDLE( HDESK );
DECLARE_HANDLE( HENHMETAFILE );
DECLARE_HANDLE( HFONT );
DECLARE_HANDLE( HGLRC );
DECLARE_HANDLE( HHOOK );
DECLARE_HANDLE( HICON );
DECLARE_HANDLE( HINSTANCE );
DECLARE_HANDLE( HKEY );
DECLARE_HANDLE( HKL );
DECLARE_HANDLE( HMENU );
DECLARE_HANDLE( HMETAFILE );
DECLARE_HANDLE( HPALETTE );
DECLARE_HANDLE( HPEN );
DECLARE_HANDLE( HRGN );
DECLARE_HANDLE( HRSRC );
DECLARE_HANDLE( HSPRITE );
DECLARE_HANDLE( HSTR );
DECLARE_HANDLE( HTASK );
DECLARE_HANDLE( HWINSTA );
DECLARE_HANDLE( HWND );
#if (WINVER >= 0x0400)
DECLARE_HANDLE( HCOLORSPACE );
DECLARE_HANDLE( HWINEVENTHOOK );
#endif
#if (WINVER >= 0x0500)
DECLARE_HANDLE( HMONITOR );
DECLARE_HANDLE( HUMPD );
#endif

/* Special handle data types */
typedef HANDLE NEAR *SPHANDLE;
typedef HANDLE FAR  *LPHANDLE;
typedef HANDLE      HGLOBAL;
typedef HANDLE      HLOCAL;
typedef HANDLE      GLOBALHANDLE;
typedef HANDLE      LOCALHANDLE;
typedef void        *HGDIOBJ;
typedef HKEY        *PHKEY;
typedef int         HFILE;
typedef HINSTANCE   HMODULE;
typedef HICON       HCURSOR;

/* Basic constants */
#define MAX_PATH        260
#ifndef NULL
    #ifdef __cplusplus
        #define NULL    0
    #else
        #define NULL    ((void *)0)
    #endif
#endif
#ifndef FALSE
    #define FALSE       0
#endif
#ifndef TRUE
    #define TRUE        1
#endif
#define HFILE_ERROR     0xFFFFFFFF

/* Rectangle */
typedef struct tagRECT {
    LONG    left;
    LONG    top;
    LONG    right;
    LONG    bottom;
} RECT;
typedef RECT            *PRECT;
typedef RECT NEAR       *NPRECT;
typedef RECT FAR        *LPRECT;
typedef const RECT FAR  *LPCRECT;

/* Rectangle (long version) */
typedef struct _RECTL {
    LONG    left;
    LONG    top;
    LONG    right;
    LONG    bottom;
} RECTL;
typedef RECTL           *PRECTL;
typedef RECTL           *LPRECTL;
typedef const RECTL FAR *LPCRECTL;

/* Point */
typedef struct tagPOINT {
    LONG    x;
    LONG    y;
} POINT;
typedef POINT       *PPOINT;
typedef POINT NEAR  *NPPOINT;
typedef POINT FAR   *LPPOINT;

/* Point (long version) */
typedef struct _POINTL {
    LONG    x;
    LONG    y;
} POINTL;
typedef POINTL  *PPOINTL;

/* Size */
typedef struct tagSIZE {
    LONG    cx;
    LONG    cy;
} SIZE;
typedef SIZE    *PSIZE;
typedef SIZE    *LPSIZE;
typedef SIZE    SIZEL;
typedef SIZE    *PSIZEL;
typedef SIZE    *LPSIZEL;

/* Point (short version) */
typedef struct tagPOINTS {
    SHORT   x;
    SHORT   y;
} POINTS;
typedef POINTS  *PPOINTS;
typedef POINTS  *LPPOINTS;

/* File time */
#define _FILETIME_
typedef struct _FILETIME {
    DWORD   dwLowDateTime;
    DWORD   dwHighDateTime;
} FILETIME;
typedef FILETIME    *PFILETIME;
typedef FILETIME    *LPFILETIME;

/* Minimum and maximum macros */
#ifndef NOMINMAX
    #ifndef min
        #define min( p1, p2 )   (((p1) < (p2)) ? (p1) : (p2))
    #endif
    #ifndef max
        #define max( p1, p2 )   (((p1) > (p2)) ? (p1) : (p2))
    #endif
#endif

/* Macros for manipulating words and longs */
#define MAKEWORD( p1, p2 ) \
    ((WORD)((BYTE)(DWORD_PTR)(p1) & 0xFF) | ((WORD)((BYTE)(DWORD_PTR)(p2) & 0xFF) << 8))
#define MAKELONG( p1, p2 ) \
    ((LONG)((WORD)(DWORD_PTR)(p1) & 0xFFFF) |  \
    ((LONG)((WORD)(DWORD_PTR)(p2) & 0xFFFF) << 16))
#define LOWORD( x )         ((WORD)((DWORD_PTR)(x) & 0xFFFF))
#define HIWORD( x )         ((WORD)((DWORD_PTR)(x) >> 16))
#define LOBYTE( x )         ((BYTE)((DWORD_PTR)(x) & 0xFF))
#define HIBYTE( x )         ((BYTE)((DWORD_PTR)(x) >> 8))

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _WINDEF_ */
