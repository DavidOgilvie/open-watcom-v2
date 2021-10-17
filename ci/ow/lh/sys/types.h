/*
 *  sys/types.h Defined system types
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
 */
#ifndef __TYPES_H_INCLUDED
#define __TYPES_H_INCLUDED

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file;
#endif

#ifndef _COMDEF_H_INCLUDED
 #include <_comdef.h>
#endif

#ifndef _LIMITS_H_INCLUDED
 #include <limits.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
 #ifndef _STDTIME_T_DEFINED
 #define _STDTIME_T_DEFINED
  namespace std {
    typedef signed long time_t;
  }
 #endif
 #ifndef _TIME_T_DEFINED
 #define _TIME_T_DEFINED
  #define _TIME_T_DEFINED_
  using std::time_t;
 #endif
#else  /* __cplusplus not defined */
 #ifndef _TIME_T_DEFINED
 #define _TIME_T_DEFINED
  #define _TIME_T_DEFINED_
  typedef signed long time_t;
 #endif
#endif /* __cplusplus not defined */

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

#ifndef _SSIZE_T_DEFINED_
#define _SSIZE_T_DEFINED_
 typedef signed ssize_t;
#endif

/*          char | short | int | long | long long                        */
/* 16 bit : 8      16      16    32     64     All 16 bit targets.       */
/* 32 bit : 8      16      32    32     64     386, AXP, PPC, MIPS       */
/* 64 bit : 8      16      32    64     64     No targets implemented.   */

/* Exact-width types. */
#ifndef _EXACT_WIDTH_INTS
#define _EXACT_WIDTH_INTS
typedef signed char         int8_t;
typedef unsigned char       uint8_t;
typedef short               int16_t;
typedef unsigned short      uint16_t;
#ifdef _M_I86
 typedef long               int32_t;
 typedef unsigned long      uint32_t;
#else
 typedef int                int32_t;
 typedef unsigned int       uint32_t;
#endif
typedef long long           int64_t;
typedef unsigned long long  uint64_t;
#endif /* _EXACT_WIDTH_INTS */

#ifndef _ARCH_DIR
 #if defined(__386__)
  #define _ARCH_DIR i386
 #elif defined(__MIPS__)
  #define _ARCH_DIR mips
 #else
  #error unknown platform
  #define _ARCH_DIR
 #endif
 #define _ARCH_INCLUDE(hdr) <arch/ ## _ARCH_DIR ## / ## hdr ## >
#endif /* !_ARCH_DIR */

/* Define POSIX 1003.1 types */
#include _ARCH_INCLUDE(sys/types.h)

typedef unsigned char   u_char;
typedef unsigned short  u_short;
typedef unsigned int    u_int;
typedef unsigned long   u_long;
typedef unsigned __int64 u_quad_t;
typedef __int64         quad_t;
typedef quad_t *        qaddr_t;
typedef int             key_t;
typedef long            blksize_t;
typedef long            blkcnt_t;
typedef quad_t          loff_t;


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
