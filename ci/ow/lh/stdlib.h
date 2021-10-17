/***************************************************************************
 * FILE: stdlib.h/cstdlib (Standard Library functions)
 *
 * =========================================================================
 *
 *                          Open Watcom Project
 *
 *    Copyright (c) 2002-2021 Open Watcom Contributors. All Rights Reserved.
 *    Portions Copyright (c) 1983-2002 Sybase, Inc. All Rights Reserved.
 *
 *    This file is automatically generated. Do not edit directly.
 *
 * =========================================================================
 *
 * Description: This header is part of the C/C++ standard library. It
 *              declares several types, macros, and functions of general
 *              utility.
 ***************************************************************************/
#ifndef _STDLIB_H_INCLUDED
#define _STDLIB_H_INCLUDED

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file;
#endif

#ifdef __cplusplus

#define _INCLUDED_FROM_STDLIB_H
#include <cstdlib>
#undef  _INCLUDED_FROM_STDLIB_H

// C99 types in stdlib.h.
using std::div_t;
using std::ldiv_t;
#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#define _SIZE_T_DEFINED_
using std::size_t;
#endif

// C99 functions in stdlib.h
using std::abort;
using std::abs;
using std::atexit;
using std::atof;
using std::atoi;
using std::atol;
using std::atoll;
using std::bsearch;
using std::calloc;
using std::div;
using std::exit;
using std::free;
using std::getenv;
using std::labs;
using std::ldiv;
using std::malloc;
using std::mblen;
using std::mbstowcs;
using std::mbtowc;
using std::wcstombs;
using std::wctomb;
using std::qsort;
using std::rand;
using std::realloc;
using std::srand;
using std::strtod;
using std::strtol;
using std::strtoll;
using std::strtoul;
using std::strtoull;
using std::system;

#if defined(_LINUX_SOURCE) || !defined(NO_EXT_KEYS) /* extensions enabled */
using std::wcstol;
using std::wcstoll;
using std::wcstod;
using std::wcstoul;
using std::wcstoull;
#endif /* extensions enabled */

#else /* __cplusplus not defined */

#ifndef _COMDEF_H_INCLUDED
 #include <_comdef.h>
#endif

#pragma pack( __push, 8 )

 #ifndef _WCHAR_T_DEFINED
 #define _WCHAR_T_DEFINED
  #define _WCHAR_T_DEFINED_
  typedef unsigned short wchar_t;
 #endif

 #ifndef _SIZE_T_DEFINED
 #define _SIZE_T_DEFINED
  #define _SIZE_T_DEFINED_
  typedef unsigned size_t;
  typedef size_t   _w_size_t;
 #endif

#if defined(__STDC_WANT_LIB_EXT1__) && __STDC_WANT_LIB_EXT1__ == 1

#ifndef _ERRNO_T_DEFINED
 #define _ERRNO_T_DEFINED
 typedef int errno_t;
#endif

#ifndef _RSIZE_T_DEFINED
#define _RSIZE_T_DEFINED
 typedef size_t rsize_t;
#endif

typedef void (*constraint_handler_t)( const char * __restrict __msg, void * __restrict __ptr, errno_t __error );

#endif /* Safer C Library */

#ifndef NULL
 #ifdef __cplusplus
  #if !defined(_M_I86) || defined(__SMALL__) || defined(__MEDIUM__)
   #define NULL 0
  #else
   #define NULL 0L
  #endif 
 #else
  #define NULL ((void *)0)
 #endif
#endif

#ifndef MB_CUR_MAX
 #define MB_CUR_MAX     6
#endif
#ifndef MB_LEN_MAX
 #define MB_LEN_MAX     6
#endif

#ifndef _MAX_PATH
 #define _MAX_PATH    256 /* maximum length of path name     */
#endif

#define RAND_MAX        32767U
#define EXIT_SUCCESS    0
#define EXIT_FAILURE    1

typedef struct  {
    int     quot;
    int     rem;
} div_t;

typedef struct  {
    long    quot;
    long    rem;
} ldiv_t;

typedef struct  {
    long long   quot;
    long long   rem;
} lldiv_t;

_WCRTLINK extern void    abort( void );

_WCIRTLINK extern int    abs( int __j );
#if defined(_M_IX86) && 0
#pragma aux abs     parm nomemory modify nomemory;
#endif
_WRTLFCONV extern int    atexit( void ( *__func )( void ) );
_WMRTLINK extern double  atof( const char *__nptr );
_WCRTLINK extern int     atoi( const char *__nptr );
_WCRTLINK extern long int atol( const char *__nptr );
_WCRTLINK extern long long int atoll( const char *__nptr );
_WCRTLINK extern void    *bsearch( const void *__key, const void *__base,
                                  size_t __nmemb, size_t __size,
                                  int (*__compar)(const void *__pkey, const void *__pbase) );
_WCRTLINK extern void    *calloc( size_t __n, size_t __size );
_WCIRTLINK extern div_t  div( int __numer, int __denom );
_WCRTLINK extern void    exit( int __status );
_WCRTLINK extern void    _Exit( int __status );
_WCRTLINK extern void    free( void *__ptr );
_WCRTLINK extern char    *getenv( const char *__name );

_WCIRTLINK extern long int labs( long int __j );
#if defined(_M_IX86) && 0
#pragma aux labs    parm nomemory modify nomemory;
#endif

#if defined(_M_I86)
_WCRTLINK
#else
_WCIRTLINK
#endif
          extern ldiv_t  ldiv( long int __numer, long int __denom );
_WCRTLINK extern long long int llabs( long long int __j );
_WCRTLINK extern lldiv_t lldiv( long long int __numer, long long int __denom );
_WCRTLINK extern void    *malloc( size_t __size );
_WCRTLINK extern int     mblen( const char *__s, size_t __n );
_WCRTLINK extern size_t  mbstowcs( wchar_t *__pwcs, const char *__s, size_t __n );
_WCRTLINK extern int     mbtowc( wchar_t *__pwc, const char *__s, size_t __n );
_WCRTLINK extern size_t  wcstombs( char *__s, const wchar_t *__pwcs, size_t __n );
_WCRTLINK extern int     wctomb( char *__s, wchar_t __wchar );
_WCRTLINK extern void    qsort( void *__base, size_t __nmemb, size_t __size,
                                int (*__compar)( const void *, const void * ) );
_WCRTLINK extern int     rand( void );
_WCRTLINK extern void    *realloc( void *__ptr, size_t __size );
_WCRTLINK extern void    srand( unsigned int __seed );
_WMRTLINK extern double  strtod( const char *__nptr, char **__endptr );
_WMRTLINK extern float   strtof( const char *__nptr, char **__endptr );
_WMRTLINK extern long double strtold( const char *__nptr, char **__endptr );
_WCRTLINK extern long int strtol( const char *__nptr, char **__endptr, int __base );
_WCRTLINK extern long long int strtoll( const char *__nptr, char **__endptr, int __base );
_WCRTLINK extern unsigned long strtoul( const char *__nptr, char **__endptr, int __base );
_WCRTLINK extern unsigned long long int strtoull( const char *__nptr, char **__endptr, int __base );
_WCRTLINK extern int     system( const char *__string );

#if defined(__INLINE_FUNCTIONS__)
#pragma intrinsic(abs,div,labs)
#if !defined(_M_I86)
 #pragma intrinsic(ldiv)
#endif
#endif

#define atof(p)  strtod(p,(char **)NULL)

#if defined(_POSIX_SOURCE) || defined(_LINUX_SOURCE) || !defined(NO_EXT_KEYS) /* extensions enabled */
_WCRTLINK void           _exit( int __status );
#endif /* extensions enabled */

#if defined(_LINUX_SOURCE) || !defined(NO_EXT_KEYS) /* extensions enabled */

_WCRTLINK extern void    break_on( void );
_WCRTLINK extern void    break_off( void );

_WMRTLINK extern char    *ecvt( double __val, int __ndig, int *__dec, int *__sign );
_WMRTLINK extern char    *_ecvt( double __val, int __ndig, int *__dec, int *__sign );
_WMRTLINK extern char    *fcvt( double __val, int __ndig, int *__dec, int *__sign );
_WMRTLINK extern char    *_fcvt( double __val, int __ndig, int *__dec, int *__sign );
_WCRTLINK extern char    *_fullpath( char *__buf, const char *__path, _w_size_t __size );
_WMRTLINK extern char    *gcvt( double __val, int __ndig, char *__buf );
_WMRTLINK extern char    *_gcvt( double __val, int __ndig, char *__buf );
_WCRTLINK extern char    *itoa( int __value, char *__buf, int __radix );
_WCRTLINK extern char    *_itoa( int __value, char *__buf, int __radix );
#if defined(_M_I86)
_WCRTLINK
#else
_WCIRTLINK
#endif
    extern unsigned long _lrotl( unsigned long __value, unsigned int __shift );
#if defined(_M_I86)
_WCRTLINK
#else
_WCIRTLINK
#endif
    extern unsigned long _lrotr( unsigned long __value, unsigned int __shift );
_WCRTLINK extern char    *ltoa( long int __value, char *__buf, int __radix );
_WCRTLINK extern char    *lltoa( long long int __value, char *__buf, int __radix );
_WCRTLINK extern char    *_ltoa( long int __value, char *__buf, int __radix );
_WCRTLINK extern char    *_lltoa( long long int __value, char *__buf, int __radix );
_WCRTLINK extern void    _makepath( char *__path, const char *__drive,
                                    const char *__dir, const char *__fname, const char *__ext );
_WCRTLINK extern int     mkstemp( char *__template );
_WCIRTLINK extern unsigned int _rotl( unsigned int __value, unsigned int __shift );
_WCIRTLINK extern unsigned int _rotr( unsigned int __value, unsigned int __shift );

_WMRTLINK extern wchar_t  *_wecvt( double __val, int __ndig, int *__dec, int *__sign );
_WMRTLINK extern wchar_t  *_wfcvt( double __val, int __ndig, int *__dec, int *__sign );
_WMRTLINK extern wchar_t  *_wgcvt( double __val, int __ndig, wchar_t *__buf );
_WCRTLINK extern int      _wtoi( const wchar_t * );
_WCRTLINK extern long int _wtol( const wchar_t * );
_WCRTLINK extern long long int _wtoll( const wchar_t * );
_WCRTLINK extern wchar_t  *_itow( int, wchar_t *, int );
_WCRTLINK extern wchar_t  *_ltow( long int, wchar_t *, int );
_WCRTLINK extern wchar_t  *_lltow( long long int, wchar_t *, int );
_WCRTLINK extern wchar_t  *_utow( unsigned int, wchar_t *, int );
_WCRTLINK extern wchar_t  *_ultow( unsigned long int, wchar_t *, int );
_WCRTLINK extern wchar_t  *_ulltow( unsigned long long int, wchar_t *, int );
_WMRTLINK extern double   _wtof( const wchar_t * );
_WMRTLINK extern double   _watof( const wchar_t * );
_WCRTLINK extern long int wcstol( const wchar_t *, wchar_t **, int );
_WCRTLINK extern long long int wcstoll( const wchar_t *, wchar_t **, int );
_WMRTLINK extern double  wcstod( const wchar_t *, wchar_t ** );
_WCRTLINK extern unsigned long int wcstoul( const wchar_t *, wchar_t **, int );
_WCRTLINK extern unsigned long long int wcstoull( const wchar_t *, wchar_t **, int );
_WCRTLINK extern wchar_t  *_atouni( wchar_t *, const char * );
_WCRTLINK extern wchar_t  *_wfullpath( wchar_t *, const wchar_t *, _w_size_t );
_WCRTLINK extern void     _wmakepath( wchar_t *__path, const wchar_t *__drive,
                                      const wchar_t *__dir,
                                      const wchar_t *__fname,
                                      const wchar_t *__ext );
_WCRTLINK extern int      _wcsicmp( const wchar_t *, const wchar_t * );
_WCRTLINK extern wchar_t  *_wcsdup( const wchar_t * );
_WCRTLINK extern int      _wcsnicmp( const wchar_t *, const wchar_t *, _w_size_t );
_WCRTLINK extern wchar_t  *_wcslwr( wchar_t * );
_WCRTLINK extern wchar_t  *_wcsupr( wchar_t * );
_WCRTLINK extern wchar_t  *_wcsrev( wchar_t * );
_WCRTLINK extern wchar_t  *_wcsset( wchar_t *, wchar_t );
_WCRTLINK extern wchar_t  *_wcsnset( wchar_t *, int, _w_size_t );
_WCRTLINK extern wchar_t  *_wgetenv( const wchar_t *__name );
_WCRTLINK extern int      _wsetenv( const wchar_t *__name,
                                      const wchar_t *__newvalue,
                                      int __overwrite );
_WCRTLINK extern int      _wputenv( const wchar_t *__env_string );

_WCRTLINK extern int     setenv( const char *__name, const char *__newvalue, int __overwrite );
_WCRTLINK extern void    unsetenv( const char *name );

_WCRTLINK extern int     putenv( const char *__string );
_WCRTLINK extern int     _putenv( const char *__string );
_WCRTLINK extern void    _searchenv( const char *__name, const char *__env_var, char *__buf );
_WCRTLINK extern void    _splitpath2( const char *__inp, char *__outp,
                                      char **__drive, char **__dir,
                                      char **__fn, char **__ext );
_WCRTLINK extern void    _splitpath( const char *__path, char *__drive,
                                     char *__dir, char *__fname, char *__ext );
_WCRTLINK extern void    swab( char *__src, char *__dest, int __num );
_WCRTLINK extern char    *ultoa( unsigned long int __value, char *__buf, int __radix );
_WCRTLINK extern char    *ulltoa( unsigned long long int __value, char *__buf, int __radix );
_WCRTLINK extern char    *_ultoa( unsigned long int __value, char *__buf, int __radix );
_WCRTLINK extern char    *_ulltoa( unsigned long long int __value, char *__buf, int __radix );
_WCRTLINK extern char    *utoa( unsigned int __value, char *__buf, int __radix );
_WCRTLINK extern char    *_utoa( unsigned int __value, char *__buf, int __radix );

_WCRTLINK extern char    *_i64toa( __int64 __value, char *__buf, int __radix );
_WCRTLINK extern char    *_ui64toa( unsigned __int64 __value, char *__buf, int __radix );
_WCRTLINK extern __int64 _atoi64( const char *__nptr );
_WCRTLINK extern __int64 _strtoi64( const char *__nptr, char **__endptr, int __base );
_WCRTLINK extern unsigned __int64 _strtoui64( const char *__nptr, char **__endptr, int __base );

#if defined(__INLINE_FUNCTIONS__)
 #pragma intrinsic(_rotl,_rotr)
 #if !defined(_M_I86)
  #pragma intrinsic(_lrotl,_lrotr)
 #endif
#endif

#if defined(__STDC_WANT_LIB_EXT1__) && __STDC_WANT_LIB_EXT1__ == 1

_WCRTLINK extern constraint_handler_t set_constraint_handler_s( constraint_handler_t __handler );
_WCRTLINK extern void abort_handler_s( const char * __restrict __msg, void * __restrict __ptr, errno_t __error );
_WCRTLINK extern void ignore_handler_s( const char * __restrict __msg, void * __restrict __ptr, errno_t __error );

_WCRTLINK extern errno_t getenv_s( size_t * __restrict __len, char * __restrict __value, rsize_t __maxsize, const char * __restrict __name );

_WCRTLINK extern void    *bsearch_s( const void *__key, const void *__base, rsize_t __nmemb, rsize_t __size,
                                     int (*__compar)(const void *__x, const void *__y, void *__context), void *__context);
_WCRTLINK extern errno_t qsort_s( void *__base, rsize_t __nmemb, rsize_t __size,
                                  int (*__compar)(const void *__x, const void *__y, void *__context), void *__context);

_WCRTLINK extern errno_t wctomb_s( int * __restrict __status, char * __restrict __s, rsize_t __smax, wchar_t __wc );
_WCRTLINK extern errno_t mbstowcs_s( size_t * __restrict __retval, wchar_t * __restrict __dst, rsize_t __dstmax, const char * __restrict __src, rsize_t __len );
_WCRTLINK extern errno_t wcstombs_s( size_t * __restrict __retval, char * __restrict __dst, rsize_t __dstmax, const wchar_t * __restrict __src, rsize_t __len );

#endif /* Safer C Library */

/* min and max macros */
#if !defined(__max)
#define __max(a,b)  (((a) > (b)) ? (a) : (b))
#endif
#if !defined(max)
#define max(a,b)  (((a) > (b)) ? (a) : (b))
#endif
#if !defined(__min)
#define __min(a,b)  (((a) < (b)) ? (a) : (b))
#endif
#if !defined(min)
#define min(a,b)  (((a) < (b)) ? (a) : (b))
#endif

/*
 * The following sizes are the maximum sizes of buffers used by the _fullpath()
 * _makepath() and _splitpath() functions.  They include space for the '\0'
 * terminator.
 */
#define _MAX_DRIVE      48      /*  maximum length of node name w/ '\0' */
#define _MAX_NODE    _MAX_DRIVE /*  maximum length of node name w/ '\0' */
#define _MAX_DIR        256     /*  maximum length of subdirectory      */
#define _MAX_FNAME      48      /*  maximum length of a file name       */
#define _MAX_EXT        48      /*  maximum length of a file extension  */

#define _MAX_PATH2 (_MAX_PATH+3) /* maximum size of output buffer
                                    for _splitpath2() */

_WCRTLINK char             ***__get_environ_ptr( void );
_WCRTLINK char _WCI86FAR   **__get_pgmptr_ptr( void );
#if defined(__FUNCTION_DATA_ACCESS)
 #define environ   (*__get_environ_ptr())
 #define _pgmptr   (*__get_pgmptr_ptr())
#endif
_WCRTDATA extern char  **_WCNEAR environ;   /* pointer to environment table */
_WCRTDATA extern char _WCI86FAR *_pgmptr;   /* pointer to executable name */

 _WCRTDATA extern wchar_t  **_WCNEAR _wenviron; /* pointer to wide environment */
 _WCRTDATA extern wchar_t _WCI86FAR *_wpgmptr;  /* pointer to wide executable name */

#ifndef _ERRNO_DEFINED
#define _ERRNO_DEFINED
 #ifndef errno
  _WCRTLINK extern int *__get_errno_ptr( void );
  #define errno (*__get_errno_ptr())
 #else
  _WCRTDATA extern int errno;
 #endif
#endif

_WCRTLINK unsigned      *__get_amblksiz_ptr( void );
_WCRTLINK unsigned char *__get_osmajor_ptr( void );
_WCRTLINK unsigned char *__get_osminor_ptr( void );
#if defined(__FUNCTION_DATA_ACCESS)
 #define _amblksiz      (*__get_amblksiz_ptr())
 #define _osmajor       (*__get_osmajor_ptr())
 #define _osminor       (*__get_osminor_ptr())
#elif defined(__SW_BR) || defined(_RTDLL)
 #define _amblksiz      _amblksiz_br
 #define _osmajor       _osmajor_br
 #define _osminor       _osminor_br
#endif
_WCRTDATA extern unsigned _WCNEAR       _amblksiz;   /*  mallocs done in multiples of    */
_WCRTDATA extern unsigned char _WCNEAR  _osmajor;    /*  O/S major version # */
_WCRTDATA extern unsigned char _WCNEAR  _osminor;    /*  O/S minor version # */

extern  int       __argc;       /* number of cmd line args */
extern  char    **__argv;       /* vector of cmd line args */

#ifndef alloca
 _WCRTLINK extern void  *alloca(_w_size_t __size);
 _WCRTLINK extern void  *_alloca(_w_size_t __size);
 _WCRTLINK extern unsigned stackavail( void );
 #ifdef _M_IX86
  extern void  *__doalloca(_w_size_t __size);
  #pragma aux stackavail __modify __nomemory;

  #define __ALLOCA_ALIGN( s )   (((s)+(sizeof(int)-1))&~(sizeof(int)-1))
  #define __alloca( s )         __doalloca(__ALLOCA_ALIGN(s))

   #define alloca( s )  ((__ALLOCA_ALIGN(s)<stackavail())?__alloca(s):NULL)
   #define _alloca( s ) ((__ALLOCA_ALIGN(s)<stackavail())?__alloca(s):NULL)

  #if defined(__386__)
   #pragma aux __doalloca = \
            "sub esp,eax"   \
            __parm __nomemory [__eax] __value [__esp] __modify __exact __nomemory [__esp];
  #elif defined(__SMALL__) || defined(__MEDIUM__) /* small data models */
   #pragma aux __doalloca = \
            "sub sp,ax"     \
            __parm __nomemory [__ax] __value [__sp] __modify __exact __nomemory [__sp];
  #else                                           /* large data models */
   #pragma aux __doalloca = \
            "sub sp,ax"     \
            "mov ax,sp"     \
            "mov dx,ss"     \
            __parm __nomemory [__ax] __value [__dx __ax] __modify __exact __nomemory [__dx __ax __sp];
  #endif
 #else
  extern void *__builtin_alloca(_w_size_t __size);
  #pragma intrinsic(__builtin_alloca);

  #define __alloca( s ) (__builtin_alloca(s))

  #define alloca( s )   ((s<stackavail())?__alloca(s):NULL)
  #define _alloca( s )  ((s<stackavail())?__alloca(s):NULL)
 #endif
#endif

_WCRTLINK extern int          brk( void *endds );
_WCRTLINK extern void _WCNEAR *sbrk( int incr );

typedef void (*onexit_t)( void );
_WCRTLINK extern onexit_t     onexit( onexit_t __func );

#endif /* extensions enabled */

#pragma pack( __pop )

#endif /* __cplusplus not defined */

#endif

