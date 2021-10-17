/*
 *  winber.h    Win32 Basic Encoding Rules (BER) functions
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

#ifndef _WINBER_DEFINED_
#define _WINBER_DEFINED_

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file;
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Macro to specify BER functions */
#define WINBERAPI   DECLSPEC_IMPORT

/* BER calling convention */
#define BERAPI  __cdecl

/* BER primitive data types */
typedef unsigned int    ber_tag_t;
typedef int             ber_int_t;
typedef unsigned int    ber_uint_t;
typedef unsigned int    ber_len_t;
typedef int             ber_slen_t;

/* BER special values */
#define LBER_ERROR      0xFFFFFFFFL
#define LBER_DEFAULT    0xFFFFFFFFL

/* Functions in WLDAP32.DLL */
WINBERAPI BerElement * BERAPI   ber_alloc_t( INT );
WINBERAPI BERVAL * BERAPI       ber_bvdup( BERVAL * );
WINBERAPI VOID BERAPI           ber_bvecfree( PBERVAL * );
WINBERAPI VOID BERAPI           ber_bvfree( BERVAL * );
WINBERAPI ULONG BERAPI          ber_first_element( BerElement *, ULONG *, CHAR ** );
WINBERAPI INT BERAPI            ber_flatten( BerElement *, PBERVAL * );
WINBERAPI VOID BERAPI           ber_free( BerElement *, INT );
WINBERAPI BerElement * BERAPI   ber_init( BERVAL * );
WINBERAPI ULONG BERAPI          ber_next_element( BerElement *, ULONG *, CHAR * );
WINBERAPI ULONG BERAPI          ber_peek_tag( BerElement *, ULONG * );
WINBERAPI INT BERAPI            ber_printf( BerElement *, PCHAR, ... );
WINBERAPI ULONG BERAPI          ber_scanf( BerElement *, PCHAR, ... );
WINBERAPI ULONG BERAPI          ber_skip_tag( BerElement *, ULONG * );

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _WINBER_DEFINED_ */
