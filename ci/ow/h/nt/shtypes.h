/*
 *  shtypes.h   Shell data types
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

#include <rpc.h>
#include <rpcndr.h>

#ifndef __shtypes_h__
#define __shtypes_h__

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file;
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Perceived flag data type */
#if (_WIN32_IE >= 0x0603)
typedef DWORD   PERCEIVEDFLAG;
#endif

/* Known folder identifier data type */
typedef GUID    KNOWNFOLDERID;
#ifdef __cplusplus
    #define REFKNOWNFOLDERID    const KNOWNFOLDERID &
#else
    #define REFKNOWNFOLDERID    const KNOWNFOLDERID * const
#endif

/* Known folder redirection flags data type */
typedef DWORD   KF_REDIRECT_FLAGS;

/* Folder type identifier data type */
typedef GUID    FOLDERTYPEID;
#ifdef __cplusplus
    #define REFFOLDERTYPEID const FOLDERTYPEID &
#else
    #define REFFOLDERTYPEID const FOLDERTYPEID * const
#endif

/* Task owner identifier data type */
typedef GUID    TASKOWNERID;
#ifdef __cplusplus
    #define REFTASKOWNERID  const TASKOWNERID &
#else
    #define REFTASKOWNERID  const TASKOWNERID * const
#endif

/* Shell column state flags data type */
typedef DWORD   SHCOLSTATEF;

/* Shell column identifier data type */
typedef PROPERTYKEY         SHCOLUMNID;
typedef const SHCOLUMNID    *LPCSHCOLUMNID;

/* Perceived flags */
#if (_WIN32_IE >= 0x0603)
    #define PERCEIVEDFLAG_UNDEFINED     0x0000
    #define PERCEIVEDFLAG_SOFTCODED     0x0001
    #define PERCEIVEDFLAG_HARDCODED     0x0002
    #define PERCEIVEDFLAG_NATIVESUPPORT 0x0004
    #define PERCEIVEDFLAG_GDIPLUS       0x0010
    #define PERCEIVEDFLAG_WMSDK         0x0020
    #define PERCEIVEDFLAG_ZIPFOLDER     0x0040
#endif

/* Shell item identifier */
#include <pshpack1.h>
typedef struct _SHITEMID {
    USHORT  cb;
    BYTE    abID[1];
} SHITEMID;
typedef SHITEMID        *LPSHITEMID;
typedef const SHITEMID  *LPCSHITEMID;
#include <poppack.h>

/* Item identifier list */
#include <pshpack1.h>
typedef struct _ITEMIDLIST {
    SHITEMID    mkid;
} ITEMIDLIST;
typedef ITEMIDLIST                  *LPITEMIDLIST;
typedef ITEMIDLIST                  *LPCITEMIDLIST;
typedef ITEMIDLIST                  ITEMIDLIST_RELATIVE;
typedef ITEMIDLIST                  ITEMID_CHILD;
typedef ITEMIDLIST                  ITEMIDLIST_ABSOLUTE;
typedef ITEMIDLIST_ABSOLUTE         *PIDLIST_ABSOLUTE;
typedef const ITEMIDLIST_ABSOLUTE   *PCIDLIST_ABSOLUTE;
typedef const ITEMIDLIST_ABSOLUTE   *PCUIDLIST_ABSOLUTE;
typedef ITEMIDLIST_RELATIVE         *PIDLIST_RELATIVE;
typedef ITEMIDLIST_RELATIVE         *PUIDLIST_RELATIVE;
typedef const ITEMIDLIST_RELATIVE   *PCIDLIST_RELATIVE;
typedef const ITEMIDLIST_RELATIVE   *PCUIDLIST_RELATIVE;
typedef ITEMID_CHILD                *PITEMID_CHILD;
typedef const ITEMID_CHILD          *PCITEMID_CHILD;
typedef ITEMID_CHILD                *PUITEMID_CHILD;
typedef const ITEMID_CHILD          *PCUITEMID_CHILD;
typedef PCUITEMID_CHILD const       *PCUITEMID_CHILD_ARRAY;
typedef PCUIDLIST_RELATIVE const    *PCUIDLIST_RELATIVE_ARRAY;
typedef PCIDLIST_ABSOLUTE const     *PCIDLIST_ABSOLUTE_ARRAY;
typedef PCUIDLIST_ABSOLUTE const    *PCUIDLIST_ABSOLUTE_ARRAY;
#include <poppack.h>

/* String return types */
typedef enum tagSTRRET_TYPE {
    STRRET_WSTR     = 0x0000,
    STRRET_OFFSET   = 0x0001,
    STRRET_CSTR     = 0x0002
} STRRET_TYPE;

/* String return */
#include <pshpack8.h>
typedef struct _STRRET {
    UINT    uType;
    union {
        LPWSTR  pOleStr;
        UINT    uOffset;
        char    cStr[MAX_PATH];
    } DUMMYUNIONNAME;
} STRRET;
typedef STRRET  *LPSTRRET;
#include <poppack.h>

/* Shell details */
#include <pshpack1.h>
typedef struct _SHELLDETAILS {
    int     fmt;
    int     cxChar;
    STRRET  str;
} SHELLDETAILS;
typedef SHELLDETAILS    *LPSHELLDETAILS;
#include <poppack.h>

/* Perceived types */
#if (_WIN32_IE >= 0x0603)
typedef enum tagPERCEIVED {
    PERCEIVED_TYPE_FIRST        = -3,
    PERCEIVED_TYPE_CUSTOM       = -3,
    PERCEIVED_TYPE_UNSPECIFIED  = -2,
    PERCEIVED_TYPE_FOLDER       = -1,
    PERCEIVED_TYPE_UNKNOWN      = 0,
    PERCEIVED_TYPE_TEXT         = 1,
    PERCEIVED_TYPE_IMAGE        = 2,
    PERCEIVED_TYPE_AUDIO        = 3,
    PERCEIVED_TYPE_VIDEO        = 4,
    PERCEIVED_TYPE_COMPRESSED   = 5,
    PERCEIVED_TYPE_DOCUMENT     = 6,
    PERCEIVED_TYPE_SYSTEM       = 7,
    PERCEIVED_TYPE_APPLICATION  = 8,
    PERCEIVED_TYPE_GAMEMEDIA    = 9,
    PERCEIVED_TYPE_CONTACTS     = 10,
    PERCEIVED_TYPE_LAST         = 10
} PERCEIVED;
#endif

/* Common dialog filter specifier */
#if (NTDDI_VERSION >= 0x06000000)
typedef struct _COMDLG_FILTERSPEC {
    LPCWSTR pszName;
    LPCWSTR pszSpec;
} COMDLG_FILTERSPEC;
#endif

/* Machine identifier */
#if (NTDDI_VERSION >= 0x06000000)
typedef struct tagMACHINE_ID {
    char    szName[16];
} MACHINE_ID;
#endif

/* Domain relative object identifier */
#if (NTDDI_VERSION >= 0x06000000)
typedef struct tagDOMAIN_RELATIVE_OBJECTID {
    GUID    guidVolume;
    GUID    guidObject;
} DOMAIN_RELATIVE_OBJECTID;
#endif

/* Shell column states */
typedef enum tagSHCOLSTATE {
    SHCOLSTATE_DEFAULT              = 0x00000000,
    SHCOLSTATE_TYPE_STR             = 0x00000001,
    SHCOLSTATE_TYPE_INT             = 0x00000002,
    SHCOLSTATE_TYPE_DATE            = 0x00000003,
    SHCOLSTATE_TYPEMASK             = 0x0000000F,
    SHCOLSTATE_ONBYDEFAULT          = 0x00000010,
    SHCOLSTATE_SLOW                 = 0x00000020,
    SHCOLSTATE_EXTENDED             = 0x00000040,
    SHCOLSTATE_SECONDARYUI          = 0x00000080,
    SHCOLSTATE_HIDDEN               = 0x00000100,
    SHCOLSTATE_PREFER_VARCMP        = 0x00000200,
    SHCOLSTATE_PREFER_FMTCMP        = 0x00000400,
    SHCOLSTATE_NOSORTBYFOLDERNESS   = 0x00000800,
    SHCOLSTATE_FIXED_WIDTH          = 0x00001000,
    SHCOLSTATE_NODPISCALE           = 0x00002000,
    SHCOLSTATE_FIXED_RATIO          = 0x00004000,
    SHCOLSTATE_DISPLAYMASK          = 0x0000F000,
    SHCOLSTATE_VIEWONLY             = 0x00010000,
    SHCOLSTATE_BATCHREAD            = 0x00020000,
    SHCOLSTATE_NO_GROUPBY           = 0x00040000
} SHCOLSTATE;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __shtypes_h__ */
