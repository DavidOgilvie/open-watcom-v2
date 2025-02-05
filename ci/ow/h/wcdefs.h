//
//  wcdefs.h   Definitions for the WATCOM Container Classes
//
// =========================================================================
//
//                          Open Watcom Project
//
//    Copyright (c) 2002-2021 Open Watcom Contributors. All Rights Reserved.
//    Portions Copyright (c) 1983-2002 Sybase, Inc. All Rights Reserved.
//
//    This file is automatically generated. Do not edit directly.
//
// =========================================================================
//
#ifndef _WCDEFS_H_INCLUDED
#define _WCDEFS_H_INCLUDED

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file;
#endif

#ifndef __cplusplus
 #error This header file requires C++
#endif

#ifndef _COMDEF_H_INCLUDED
 #include <_comdef.h>
#endif

#ifndef _EXCEPT_H_INCLUDED
 #include <except.h>
#endif

typedef int             WCbool;

#ifndef TRUE
 #define TRUE           ((WCbool)1)
 #define FALSE          ((WCbool)0)
#endif

#ifdef __cplusplus
 #ifndef _STDSIZE_T_DEFINED
 #define _STDSIZE_T_DEFINED
  namespace std {
    typedef unsigned size_t;
  }
  typedef std::size_t _w_size_t;
 #endif
 #ifndef _SIZE_T_DEFINED
 #define _SIZE_T_DEFINED
  #define _SIZE_T_DEFINED_
  using std::size_t;
 #endif
#else  /* __cplusplus not defined */
 #ifndef _SIZE_T_DEFINED
 #define _SIZE_T_DEFINED
  #define _SIZE_T_DEFINED_
  typedef unsigned size_t;
  typedef size_t   _w_size_t;
 #endif
#endif /* __cplusplus not defined */

#endif
