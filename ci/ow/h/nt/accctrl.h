/*
 *  accctrl.h   Access control definitions
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

#ifndef __ACCESS_CONTROL__
#define __ACCESS_CONTROL__

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file;
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Access control primitive data types */
typedef ULONG   ACCESS_RIGHTS;
typedef ULONG   *PACCESS_RIGHTS;
typedef ULONG   INHERIT_FLAGS;
typedef ULONG   *PINHERIT_FLAGS;

/* Inheritance flags */
#define NO_INHERITANCE                      0x00000000L
#define SUB_OBJECTS_ONLY_INHERIT            0x00000001L
#define SUB_CONTAINERS_ONLY_INHERIT         0x00000002L
#define SUB_CONTAINERS_AND_OBJECTS_INHERIT  0x00000003L
#define INHERIT_NO_PROPAGATE                0x00000004L
#define INHERIT_ONLY                        0x00000008L
#define INHERITED_ACCESS_ENTRY              0x00000010L
#define INHERITED_PARENT                    0x10000000L
#define INHERITED_GRANDPARENT               0x20000000L

/* Default access control provider */
#define ACCCTRL_DEFAULT_PROVIDERA       "Windows NT Access Provider"
#define ACCCTRL_DEFAULT_PROVIDERW       L"Windows NT Access Provider"
#ifdef UNICODE
    #define ACCCTRL_DEFAULT_PROVIDER    ACCCTRL_DEFAULT_PROVIDERW
#else
    #define ACCCTRL_DEFAULT_PROVIDER    ACCCTRL_DEFAULT_PROVIDERA
#endif

/* Trustee access flags */
#define TRUSTEE_ACCESS_ALLOWED      0x00000001L
#define TRUSTEE_ACCESS_READ         0x00000002L
#define TRUSTEE_ACCESS_WRITE        0x00000004L
#define TRUSTEE_ACCESS_EXPLICIT     0x00000001L
#define TRUSTEE_ACCESS_READ_WRITE   (TRUSTEE_ACCESS_READ | TRUSTEE_ACCESS_WRITE)
#define TRUSTEE_ACCESS_ALL          0xFFFFFFFFL

/* Generic permission flags */
#define ACTRL_RESERVED          0x00000000L
#define ACTRL_PERM_1            0x00000001L
#define ACTRL_PERM_2            0x00000002L
#define ACTRL_PERM_3            0x00000004L
#define ACTRL_PERM_4            0x00000008L
#define ACTRL_PERM_5            0x00000010L
#define ACTRL_PERM_6            0x00000020L
#define ACTRL_PERM_7            0x00000040L
#define ACTRL_PERM_8            0x00000080L
#define ACTRL_PERM_9            0x00000100L
#define ACTRL_PERM_10           0x00000200L
#define ACTRL_PERM_11           0x00000400L
#define ACTRL_PERM_12           0x00000800L
#define ACTRL_PERM_13           0x00001000L
#define ACTRL_PERM_14           0x00002000L
#define ACTRL_PERM_15           0x00004000L
#define ACTRL_PERM_16           0x00008000L
#define ACTRL_PERM_17           0x00010000L
#define ACTRL_PERM_18           0x00020000L
#define ACTRL_PERM_19           0x00040000L
#define ACTRL_PERM_20           0x00080000L

/* Special permission flags */
#define ACTRL_ACCESS_ALLOWED    0x00000001L
#define ACTRL_ACCESS_DENIED     0x00000002L
#define ACTRL_AUDIT_SUCCESS     0x00000004L
#define ACTRL_AUDIT_FAILURE     0x00000008L

/* Property list flags */
#define ACTRL_ACCESS_PROTECTED  0x00000001L

/* Access rights */
#define ACTRL_SYSTEM_ACCESS         0x04000000L
#define ACTRL_DELETE                0x08000000L
#define ACTRL_READ_CONTROL          0x10000000L
#define ACTRL_CHANGE_ACCESS         0x20000000L
#define ACTRL_CHANGE_OWNER          0x40000000L
#define ACTRL_SYNCHRONIZE           0x80000000L
#define ACTRL_STD_RIGHTS_ALL        0xF8000000L
#define ACTRL_STD_RIGHT_REQUIRED    0x78000000L

/* Directory service permission flags */
#define ACTRL_DS_OPEN           ACTRL_RESERVED
#define ACTRL_DS_CREATE_CHILD   ACTRL_PERM_1
#define ACTRL_DS_DELETE_CHILD   ACTRL_PERM_2
#define ACTRL_DS_LIST           ACTRL_PERM_3
#define ACTRL_DS_SELF           ACTRL_PERM_4
#define ACTRL_DS_READ_PROP      ACTRL_PERM_5
#define ACTRL_DS_WRITE_PROP     ACTRL_PERM_6
#define ACTRL_DS_DELETE_TREE    ACTRL_PERM_7
#define ACTRL_DS_LIST_OBJECT    ACTRL_PERM_8
#define ACTRL_DS_CONTROL_ACCESS ACTRL_PERM_9

/* File permission flags */
#define ACTRL_FILE_READ         ACTRL_PERM_1
#define ACTRL_FILE_WRITE        ACTRL_PERM_2
#define ACTRL_FILE_APPEND       ACTRL_PERM_3
#define ACTRL_FILE_READ_PROP    ACTRL_PERM_4
#define ACTRL_FILE_WRITE_PROP   ACTRL_PERM_5
#define ACTRL_FILE_EXECUTE      ACTRL_PERM_6
#define ACTRL_FILE_READ_ATTRIB  ACTRL_PERM_8
#define ACTRL_FILE_WRITE_ATTRIB ACTRL_PERM_9
#define ACTRL_FILE_CREATE_PIPE  ACTRL_PERM_10

/* Directory permission flags */
#define ACTRL_DIR_LIST          ACTRL_PERM_1
#define ACTRL_DIR_CREATE_OBJECT ACTRL_PERM_2
#define ACTRL_DIR_CREATE_CHILD  ACTRL_PERM_3
#define ACTRL_DIR_TRAVERSE      ACTRL_PERM_6
#define ACTRL_DIR_DELETE_CHILD  ACTRL_PERM_7

/* Kernel permission flags */
#define ACTRL_KERNEL_TERMINATE      ACTRL_PERM_1
#define ACTRL_KERNEL_THREAD         ACTRL_PERM_2
#define ACTRL_KERNEL_VM             ACTRL_PERM_3
#define ACTRL_KERNEL_VM_READ        ACTRL_PERM_4
#define ACTRL_KERNEL_VM_WRITE       ACTRL_PERM_5
#define ACTRL_KERNEL_DUP_HANDLE     ACTRL_PERM_6
#define ACTRL_KERNEL_PROCESS        ACTRL_PERM_7
#define ACTRL_KERNEL_SET_INFO       ACTRL_PERM_8
#define ACTRL_KERNEL_GET_INFO       ACTRL_PERM_9
#define ACTRL_KERNEL_CONTROL        ACTRL_PERM_10
#define ACTRL_KERNEL_ALERT          ACTRL_PERM_11
#define ACTRL_KERNEL_GET_CONTEXT    ACTRL_PERM_12
#define ACTRL_KERNEL_SET_CONTEXT    ACTRL_PERM_13
#define ACTRL_KERNEL_TOKEN          ACTRL_PERM_14
#define ACTRL_KERNEL_IMPERSONATE    ACTRL_PERM_15
#define ACTRL_KERNEL_DIMPERSONATE   ACTRL_PERM_16

/* Printing permission flags */
#define ACTRL_PRINT_SADMIN  ACTRL_PERM_1
#define ACTRL_PRINT_SLIST   ACTRL_PERM_2
#define ACTRL_PRINT_PADMIN  ACTRL_PERM_3
#define ACTRL_PRINT_PUSE    ACTRL_PERM_4
#define ACTRL_PRINT_JADMIN  ACTRL_PERM_5

/* Service permission flags */
#define ACTRL_SVC_GET_INFO      ACTRL_PERM_1
#define ACTRL_SVC_SET_INFO      ACTRL_PERM_2
#define ACTRL_SVC_STATUS        ACTRL_PERM_3
#define ACTRL_SVC_LIST          ACTRL_PERM_4
#define ACTRL_SVC_START         ACTRL_PERM_5
#define ACTRL_SVC_STOP          ACTRL_PERM_6
#define ACTRL_SVC_PAUSE         ACTRL_PERM_7
#define ACTRL_SVC_INTERROGATE   ACTRL_PERM_8
#define ACTRL_SVC_UCONTROL      ACTRL_PERM_9

/* Registry permission flags */
#define ACTRL_REG_QUERY         ACTRL_PERM_1
#define ACTRL_REG_SET           ACTRL_PERM_2
#define ACTRL_REG_CREATE_CHILD  ACTRL_PERM_3
#define ACTRL_REG_LIST          ACTRL_PERM_4
#define ACTRL_REG_NOTIFY        ACTRL_PERM_5
#define ACTRL_REG_LINK          ACTRL_PERM_6

/* Windows permission flags */
#define ACTRL_WIN_CLIPBRD       ACTRL_PERM_1
#define ACTRL_WIN_GLOBAL_ATOMS  ACTRL_PERM_2
#define ACTRL_WIN_CREATE        ACTRL_PERM_3
#define ACTRL_WIN_LIST_DESK     ACTRL_PERM_4
#define ACTRL_WIN_LIST          ACTRL_PERM_5
#define ACTRL_WIN_READ_ATTRIBS  ACTRL_PERM_6
#define ACTRL_WIN_WRITE_ATTRIBS ACTRL_PERM_7
#define ACTRL_WIN_SCREEN        ACTRL_PERM_8
#define ACTRL_WIN_EXIT          ACTRL_PERM_9

/* Access control access options */
#define ACTRL_ACCESS_NO_OPTIONS                 0x00000000L
#define ACTRL_ACCESS_SUPPORTS_OBJECT_ENTRIES    0x00000001L

/* Tree security information options */
#if (NTDDI_VERSION >= 0x06000000)
    #define TREE_SEC_INFO_SET                   0x00000001L
    #define TREE_SEC_INFO_RESET                 0x00000002L
    #define TREE_SEC_INFO_RESET_KEEP_EXPLICIT   0x00000003L
#endif

/* Security object types */
typedef enum _SE_OBJECT_TYPE {
    SE_UNKNOWN_OBJECT_TYPE      = 0,
    SE_FILE_OBJECT              = 1,
    SE_SERVICE                  = 2,
    SE_PRINTER                  = 3,
    SE_REGISTRY_KEY             = 4,
    SE_LMSHARE                  = 5,
    SE_KERNEL_OBJECT            = 6,
    SE_WINDOW_OBJECT            = 7,
    SE_DS_OBJECT                = 8,
    SE_DS_OBJECT_ALL            = 9,
    SE_PROVIDER_DEFINED_OBJECT  = 10,
    SE_WMIGUID_OBJECT           = 11,
    SE_REGISTRY_WOW64_32KEY     = 12
} SE_OBJECT_TYPE;

/* Trustee types */
typedef enum _TRUSTEE_TYPE {
    TRUSTEE_IS_UNKNOWN          = 0,
    TRUSTEE_IS_USER             = 1,
    TRUSTEE_IS_GROUP            = 2,
    TRUSTEE_IS_DOMAIN           = 3,
    TRUSTEE_IS_ALIAS            = 4,
    TRUSTEE_IS_WELL_KNOWN_GROUP = 5,
    TRUSTEE_IS_DELETED          = 6,
    TRUSTEE_IS_INVALID          = 7,
    TRUSTEE_IS_COMPUTER         = 8
} TRUSTEE_TYPE;

/* Trustee forms */
typedef enum _TRUSTEE_FORM {
    TRUSTEE_IS_SID              = 0,
    TRUSTEE_IS_NAME             = 1,
    TRUSTEE_BAD_FORM            = 2,
    TRUSTEE_IS_OBJECTS_AND_SID  = 3,
    TRUSTEE_IS_OBJECTS_AND_NAME = 4
} TRUSTEE_FORM;

/* Multiple trustee operations */
typedef enum _MULTIPLE_TRUSTEE_OPERATION {
    NO_MULTIPLE_TRUSTEE     = 0,
    TRUSTEE_IS_IMPERSONATE  = 1
} MULTIPLE_TRUSTEE_OPERATION;

/* Objects and security identifier */
typedef struct _OBJECTS_AND_SID {
    DWORD   ObjectsPresent;
    GUID    ObjectTypeGuid;
    GUID    InheritedObjectTypeGuid;
    SID     *pSid;
} OBJECTS_AND_SID;
typedef OBJECTS_AND_SID *POBJECTS_AND_SID;

/* Objects and name */
typedef struct _OBJECTS_AND_NAME_A {
    DWORD           ObjectsPresent;
    SE_OBJECT_TYPE  ObjectType;
    LPSTR           ObjectTypeName;
    LPSTR           InheritedObjectTypeName;
    LPSTR           ptstrName;
} OBJECTS_AND_NAME_A;
typedef OBJECTS_AND_NAME_A  *POBJECTS_AND_NAME_A;
typedef struct _OBJECTS_AND_NAME_W {
    DWORD           ObjectsPresent;
    SE_OBJECT_TYPE  ObjectType;
    LPWSTR          ObjectTypeName;
    LPWSTR          InheritedObjectTypeName;
    LPWSTR          ptstrName;
} OBJECTS_AND_NAME_W;
typedef OBJECTS_AND_NAME_W  *POBJECTS_AND_NAME_W;
#ifdef UNICODE
typedef OBJECTS_AND_NAME_W  OBJECTS_AND_NAME;
typedef POBJECTS_AND_NAME_W POBJECTS_AND_NAME;
#else
typedef OBJECTS_AND_NAME_A  OBJECTS_AND_NAME;
typedef POBJECTS_AND_NAME_A POBJECTS_AND_NAME;
#endif

/* Trustee */
typedef struct _TRUSTEE_A {
    struct _TRUSTEE_A           *pMultipleTrustee;
    MULTIPLE_TRUSTEE_OPERATION  MultipleTrusteeOperation;
    TRUSTEE_FORM                TrusteeForm;
    TRUSTEE_TYPE                TrusteeType;
    LPSTR                       ptstrName;
} TRUSTEE_A;
typedef TRUSTEE_A   *PTRUSTEE_A;
typedef TRUSTEE_A   TRUSTEEA;
typedef TRUSTEE_A   *PTRUSTEEA;
typedef struct _TRUSTEE_W {
    struct _TRUSTEE_W           *pMultipleTrustee;
    MULTIPLE_TRUSTEE_OPERATION  MultipleTrusteeOperation;
    TRUSTEE_FORM                TrusteeForm;
    TRUSTEE_TYPE                TrusteeType;
    LPWSTR                      ptstrName;
} TRUSTEE_W;
typedef TRUSTEE_W   *PTRUSTEE_W;
typedef TRUSTEE_W   TRUSTEEW;
typedef TRUSTEE_W   *PTRUSTEEW;
#ifdef UNICODE
typedef TRUSTEE_W   TRUSTEE_;
typedef PTRUSTEE_W  PTRUSTEE_;
typedef TRUSTEEW    TRUSTEE;
typedef PTRUSTEEW   PTRUSTEE;
#else
typedef TRUSTEE_A   TRUSTEE_;
typedef PTRUSTEE_A  PTRUSTEE_;
typedef TRUSTEEA    TRUSTEE;
typedef PTRUSTEEA   PTRUSTEE;
#endif

/* Access modes */
typedef enum _ACCESS_MODE {
    NOT_USED_ACCESS     = 0,
    GRANT_ACCESS        = 1,
    SET_ACCESS          = 2,
    DENY_ACCESS         = 3,
    REVOKE_ACCESS       = 4,
    SET_AUDIT_SUCCESS   = 5,
    SET_AUDIT_FAILURE   = 6
} ACCESS_MODE;

/* Explicit access */
typedef struct _EXPLICIT_ACCESS_A {
    DWORD       grfAccessPermissions;
    ACCESS_MODE grfAccessMode;
    DWORD       grfInheritance;
    TRUSTEE_A   Trustee;
} EXPLICIT_ACCESS_A;
typedef EXPLICIT_ACCESS_A   *PEXPLICIT_ACCESS_A;
typedef EXPLICIT_ACCESS_A   EXPLICIT_ACCESSA;
typedef EXPLICIT_ACCESS_A   *PEXPLICIT_ACCESSA;
typedef struct _EXPLICIT_ACCESS_W {
    DWORD       grfAccessPermissions;
    ACCESS_MODE grfAccessMode;
    DWORD       grfInheritance;
    TRUSTEE_W   Trustee;
} EXPLICIT_ACCESS_W;
typedef EXPLICIT_ACCESS_W   *PEXPLICIT_ACCESS_W;
typedef EXPLICIT_ACCESS_W   EXPLICIT_ACCESSW;
typedef EXPLICIT_ACCESS_W   *PEXPLICIT_ACCESSW;
#ifdef UNICODE
typedef EXPLICIT_ACCESS_W   EXPLICIT_ACCESS_;
typedef PEXPLICIT_ACCESS_W  PEXPLICIT_ACCESS_;
typedef EXPLICIT_ACCESSW    EXPLICIT_ACCESS;
typedef PEXPLICIT_ACCESSW   PEXPLICIT_ACCESS;
#else
typedef EXPLICIT_ACCESS_A   EXPLICIT_ACCESS_;
typedef PEXPLICIT_ACCESS_A  PEXPLICIT_ACCESS_;
typedef EXPLICIT_ACCESSA    EXPLICIT_ACCESS;
typedef PEXPLICIT_ACCESSA   PEXPLICIT_ACCESS;
#endif

/* Access control access entry */
typedef struct _ACTRL_ACCESS_ENTRYA {
    TRUSTEE_A       Trustee;
    ULONG           fAccessFlags;
    ACCESS_RIGHTS   Access;
    ACCESS_RIGHTS   ProvSpecificAccess;
    INHERIT_FLAGS   Inheritance;
    LPSTR           lpInheritProperty;
} ACTRL_ACCESS_ENTRYA;
typedef ACTRL_ACCESS_ENTRYA     *PACTRL_ACCESS_ENTRYA;
typedef struct _ACTRL_ACCESS_ENTRYW {
    TRUSTEE_W       Trustee;
    ULONG           fAccessFlags;
    ACCESS_RIGHTS   Access;
    ACCESS_RIGHTS   ProvSpecificAccess;
    INHERIT_FLAGS   Inheritance;
    LPWSTR          lpInheritProperty;
} ACTRL_ACCESS_ENTRYW;
typedef ACTRL_ACCESS_ENTRYW     *PACTRL_ACCESS_ENTRYW;
#ifdef UNICODE
typedef ACTRL_ACCESS_ENTRYW     ACTRL_ACCESS_ENTRY;
typedef PACTRL_ACCESS_ENTRYW    PACTRL_ACCESS_ENTRY;
#else
typedef ACTRL_ACCESS_ENTRYA     ACTRL_ACCESS_ENTRY;
typedef PACTRL_ACCESS_ENTRYA    PACTRL_ACCESS_ENTRY;
#endif

/* Access control access entry list */
typedef struct _ACTRL_ACCESS_ENTRY_LISTA {
    ULONG               cEntries;
    ACTRL_ACCESS_ENTRYA *pAccessList;
} ACTRL_ACCESS_ENTRY_LISTA;
typedef ACTRL_ACCESS_ENTRY_LISTA    *PACTRL_ACCESS_ENTRY_LISTA;
typedef struct _ACTRL_ACCESS_ENTRY_LISTW {
    ULONG               cEntries;
    ACTRL_ACCESS_ENTRYW *pAccessList;
} ACTRL_ACCESS_ENTRY_LISTW;
typedef ACTRL_ACCESS_ENTRY_LISTW    *PACTRL_ACCESS_ENTRY_LISTW;
#ifdef UNICODE
typedef ACTRL_ACCESS_ENTRY_LISTW    ACTRL_ACCESS_ENTRY_LIST;
typedef PACTRL_ACCESS_ENTRY_LISTW   PACTRL_ACCESS_ENTRY_LIST;
#else
typedef ACTRL_ACCESS_ENTRY_LISTA    ACTRL_ACCESS_ENTRY_LIST;
typedef PACTRL_ACCESS_ENTRY_LISTA   PACTRL_ACCESS_ENTRY_LIST;
#endif

/* Access control property entry */
typedef struct _ACTRL_PROPERTY_ENTRYA {
    LPSTR                       lpProperty;
    PACTRL_ACCESS_ENTRY_LISTA   pAccessEntryList;
    ULONG                       fListFlags;
} ACTRL_PROPERTY_ENTRYA;
typedef ACTRL_PROPERTY_ENTRYA   *PACTRL_PROPERTY_ENTRYA;
typedef struct _ACTRL_PROPERTY_ENTRYW {
    LPWSTR                      lpProperty;
    PACTRL_ACCESS_ENTRY_LISTW   pAccessEntryList;
    ULONG                       fListFlags;
} ACTRL_PROPERTY_ENTRYW;
typedef ACTRL_PROPERTY_ENTRYW   *PACTRL_PROPERTY_ENTRYW;
#ifdef UNICODE
typedef ACTRL_PROPERTY_ENTRYW   ACTRL_PROPERTY_ENTRY;
typedef PACTRL_PROPERTY_ENTRYW  PACTRL_PROPERTY_ENTRY;
#else
typedef ACTRL_PROPERTY_ENTRYA   ACTRL_PROPERTY_ENTRY;
typedef PACTRL_PROPERTY_ENTRYA  PACTRL_PROPERTY_ENTRY;
#endif

/* Access control access/audit list */
typedef struct _ACTRL_ALISTA {
    ULONG                   cEntries;
    PACTRL_PROPERTY_ENTRYA  pPropertyAccessList;
} ACTRL_ACCESSA;
typedef ACTRL_ACCESSA   *PACTRL_ACCESSA;
typedef ACTRL_ACCESSA   ACTRL_AUDITA;
typedef ACTRL_ACCESSA   *PACTRL_AUDITA;
typedef struct _ACTRL_ALISTW {
    ULONG                   cEntries;
    PACTRL_PROPERTY_ENTRYW  pPropertyAccessList;
} ACTRL_ACCESSW;
typedef ACTRL_ACCESSW   *PACTRL_ACCESSW;
typedef ACTRL_ACCESSW   ACTRL_AUDITW;
typedef ACTRL_ACCESSW   *PACTRL_AUDITW;
#ifdef UNICODE
typedef ACTRL_ACCESSW   ACTRL_ACCESS;
typedef PACTRL_ACCESSW  PACTRL_ACCESS;
typedef ACTRL_AUDITW    ACTRL_AUDIT;
typedef PACTRL_AUDITW   PACTRL_AUDIT;
#else
typedef ACTRL_ACCESSA   ACTRL_ACCESS;
typedef PACTRL_ACCESSA  PACTRL_ACCESS;
typedef ACTRL_AUDITA    ACTRL_AUDIT;
typedef PACTRL_AUDITA   PACTRL_AUDIT;
#endif

/* Trustee access */
typedef struct _TRUSTEE_ACCESSA {
    LPSTR           lpProperty;
    ACCESS_RIGHTS   Access;
    ULONG           fAccessFlags;
    ULONG           fReturnedAccess;
} TRUSTEE_ACCESSA;
typedef TRUSTEE_ACCESSA     *PTRUSTEE_ACCESSA;
typedef struct _TRUSTEE_ACCESSW {
    LPWSTR          lpProperty;
    ACCESS_RIGHTS   Access;
    ULONG           fAccessFlags;
    ULONG           fReturnedAccess;
} TRUSTEE_ACCESSW;
typedef TRUSTEE_ACCESSW     *PTRUSTEE_ACCESSW;
#ifdef UNICODE
typedef TRUSTEE_ACCESSW     TRUSTEE_ACCESS;
typedef PTRUSTEE_ACCESSW    PTRUSTEE_ACCESS;
#else
typedef TRUSTEE_ACCESSA     TRUSTEE_ACCESS;
typedef PTRUSTEE_ACCESSA    PTRUSTEE_ACCESS;
#endif

/* Access control overlapped */
typedef struct _ACTRL_OVERLAPPED {
    union {
        PVOID   Provider;
        ULONG   Reserved1;
    };
    ULONG   Reserved2;
    HANDLE  hEvent;
} ACTRL_OVERLAPPED;
typedef ACTRL_OVERLAPPED    *PACTRL_OVERLAPPED;

/* Access control access information */
typedef struct _ACTRL_ACCESS_INFOA {
    ULONG   fAccessPermission;
    LPSTR   lpAccessPermissionName;
} ACTRL_ACCESS_INFOA;
typedef ACTRL_ACCESS_INFOA  *PACTRL_ACCESS_INFOA;
typedef struct _ACTRL_ACCESS_INFOW {
    ULONG   fAccessPermission;
    LPWSTR  lpAccessPermissionName;
} ACTRL_ACCESS_INFOW;
typedef ACTRL_ACCESS_INFOW  *PACTRL_ACCESS_INFOW;
#ifdef UNICODE
typedef ACTRL_ACCESS_INFOW  ACTRL_ACCESS_INFO;
typedef PACTRL_ACCESS_INFOW PACTRL_ACCESS_INFO;
#else
typedef ACTRL_ACCESS_INFOA  ACTRL_ACCESS_INFO;
typedef PACTRL_ACCESS_INFOA PACTRL_ACCESS_INFO;
#endif

/* Access control control information */
typedef struct _ACTRL_CONTROL_INFOA {
    LPSTR   lpControlId;
    LPSTR   lpControlName;
} ACTRL_CONTROL_INFOA;
typedef ACTRL_CONTROL_INFOA     *PACTRL_CONTROL_INFOA;
typedef struct _ACTRL_CONTROL_INFOW {
    LPWSTR  lpControlId;
    LPWSTR  lpControlName;
} ACTRL_CONTROL_INFOW;
typedef ACTRL_CONTROL_INFOW     *PACTRL_CONTROL_INFOW;
#ifdef UNICODE
typedef ACTRL_CONTROL_INFOW     ACTRL_CONTROL_INFO;
typedef PACTRL_CONTROL_INFOW    PACTRL_CONTROL_INFO;
#else
typedef ACTRL_CONTROL_INFOA     ACTRL_CONTROL_INFO;
typedef PACTRL_CONTROL_INFOA    PACTRL_CONTROL_INFO;
#endif

/* Progress invoke settings */
typedef enum _PROGRESS_INVOKE_SETTING {
    ProgressInvokeNever         = 1,
    ProgressInvokeEveryObject   = 2,
    ProgressInvokeOnError       = 3,
    ProgressCancelOperation     = 4,
#if (NTDDI_VERSION >= 0x06000000)
    ProgressRetryOperation      = 5,
    ProgressInvokePrePostError  = 6
#else
    ProgressRetryOperation      = 5
#endif
} PROG_INVOKE_SETTING;
typedef PROG_INVOKE_SETTING *PPROG_INVOKE_SETTING;

/* Object manager functions */
typedef struct _FN_OBJECT_MGR_FUNCTIONS {
    ULONG   PlaceHolder;
} FN_OBJECT_MGR_FUNCTS;
typedef FN_OBJECT_MGR_FUNCTS    *PFN_OBJECT_MGR_FUNCTS;

/* Inherited from */
typedef struct _INHERITED_FROMA {
    LONG    GenerationGap;
    LPSTR   AncestorName;
} INHERITED_FROMA;
typedef INHERITED_FROMA     *PINHERITED_FROMA;
typedef struct _INHERITED_FROMW {
    LONG    GenerationGap;
    LPWSTR  AncestorName;
} INHERITED_FROMW;
typedef INHERITED_FROMW     *PINHERITED_FROMW;
#ifdef UNICODE
typedef INHERITED_FROMW     INHERITED_FROM;
typedef PINHERITED_FROMW    PINHERITED_FROM;
#else
typedef INHERITED_FROMA     INHERITED_FROM;
typedef PINHERITED_FROMA    PINHERITED_FROM;
#endif

/* Alias */
#define AccFree LocalFree

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __ACCESS_CONTROL__ */
