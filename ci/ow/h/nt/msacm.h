/*
 *  msacm.h     Audio Compression Manager (ACM) functions
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

#ifndef _INC_ACM
#define _INC_ACM

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file;
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* ACM calling convention */
#define ACMAPI  WINAPI

/* ACM handle data types */
DECLARE_HANDLE( HACMDRIVERID );
DECLARE_HANDLE( HACMDRIVER );
DECLARE_HANDLE( HACMSTREAM );
DECLARE_HANDLE( HACMOBJ );

/* Pointers to handles */
typedef HACMDRIVERID    *PHACMDRIVERID;
typedef HACMDRIVERID    *LPHACMDRIVERID;
typedef HACMDRIVER      *PHACMDRIVER;
typedef HACMDRIVER      *LPHACMDRIVER;
typedef HACMSTREAM      *PHACMSTREAM;
typedef HACMSTREAM      *LPHACMSTREAM;
typedef HACMOBJ         *PHACMOBJ;
typedef HACMOBJ         *LPHACMOBJ;

/* Mapper driver messages */
#define DRV_MAPPER_PREFERRED_INPUT_GET  (DRV_USER + 0)
#define DRV_MAPPER_PREFERRED_OUTPUT_GET (DRV_USER + 2)
#define DRVM_MAPPER                     0x2000
#define DRVM_MAPPER_STATUS              (DRVM_MAPPER + 0)
#define WIDM_MAPPER_STATUS              (DRVM_MAPPER_STATUS + 0)
#define WODM_MAPPER_STATUS              (DRVM_MAPPER_STATUS + 0)

/* Wave input mapper status values */
#define WAVEIN_MAPPER_STATUS_DEVICE 0
#define WAVEIN_MAPPER_STATUS_MAPPED 1
#define WAVEIN_MAPPER_STATUS_FORMAT 2

/* Wave output mapper status values */
#define WAVEOUT_MAPPER_STATUS_DEVICE    0
#define WAVEOUT_MAPPER_STATUS_MAPPED    1
#define WAVEOUT_MAPPER_STATUS_FORMAT    2

/* ACM error codes */
#define ACMERR_BASE         512
#define ACMERR_NOTPOSSIBLE  (ACMERR_BASE + 0)
#define ACMERR_BUSY         (ACMERR_BASE + 1)
#define ACMERR_UNPREPARED   (ACMERR_BASE + 2)
#define ACMERR_CANCELED     (ACMERR_BASE + 3)

/* ACM messages */
#define MM_ACM_OPEN         MM_STREAM_OPEN
#define MM_ACM_CLOSE        MM_STREAM_CLOSE
#define MM_ACM_DONE         MM_STREAM_DONE
#define MM_ACM_FORMATCHOOSE 0x8000
#define MM_ACM_FILTERCHOOSE 0x8000

/* acmMetrics() indices */
#define ACM_METRIC_COUNT_DRIVERS            1
#define ACM_METRIC_COUNT_CODECS             2
#define ACM_METRIC_COUNT_CONVERTERS         3
#define ACM_METRIC_COUNT_FILTERS            4
#define ACM_METRIC_COUNT_DISABLED           5
#define ACM_METRIC_COUNT_HARDWARE           6
#define ACM_METRIC_COUNT_LOCAL_DRIVERS      20
#define ACM_METRIC_COUNT_LOCAL_CODECS       21
#define ACM_METRIC_COUNT_LOCAL_CONVERTERS   22
#define ACM_METRIC_COUNT_LOCAL_FILTERS      23
#define ACM_METRIC_COUNT_LOCAL_DISABLED     24
#define ACM_METRIC_HARDWARE_WAVE_INPUT      30
#define ACM_METRIC_HARDWARE_WAVE_OUTPUT     31
#define ACM_METRIC_MAX_SIZE_FORMAT          50
#define ACM_METRIC_MAX_SIZE_FILTER          51
#define ACM_METRIC_DRIVER_SUPPORT           100
#define ACM_METRIC_DRIVER_PRIORITY          101

/* acmDriverEnum() flags */
#define ACM_DRIVERENUMF_NOLOCAL     0x40000000L
#define ACM_DRIVERENUMF_DISABLED    0x80000000L

/* acmDriverAdd() flags */
#define ACM_DRIVERADDF_NAME         0x00000001L
#define ACM_DRIVERADDF_FUNCTION     0x00000003L
#define ACM_DRIVERADDF_NOTIFYHWND   0x00000004L
#define ACM_DRIVERADDF_TYPEMASK     0x00000007L
#define ACM_DRIVERADDF_LOCAL        0x00000000L
#define ACM_DRIVERADDF_GLOBAL       0x00000008L

/* ACM driver messages */
#define ACMDM_USER          (DRV_USER + 0x0000)
#define ACMDM_RESERVED_LOW  (DRV_USER + 0x2000)
#define ACMDM_RESERVED_HIGH (DRV_USER + 0x2FFF)
#define ACMDM_BASE          ACMDM_RESERVED_LOW
#define ACMDM_DRIVER_ABOUT  (ACMDM_BASE + 11)

/* acmDriverPriority() flags */
#define ACM_DRIVERPRIORITYF_ENABLE      0x00000001L
#define ACM_DRIVERPRIORITYF_DISABLE     0x00000002L
#define ACM_DRIVERPRIORITYF_ABLEMASK    0x00000003L
#define ACM_DRIVERPRIORITYF_BEGIN       0x00010000L
#define ACM_DRIVERPRIORITYF_END         0x00020000L
#define ACM_DRIVERPRIORITYF_DEFERMASK   0x00030000L

/* acmDriverDetails() string lengths */
#define ACMDRIVERDETAILS_SHORTNAME_CHARS    32
#define ACMDRIVERDETAILS_LONGNAME_CHARS     128
#define ACMDRIVERDETAILS_COPYRIGHT_CHARS    80
#define ACMDRIVERDETAILS_LICENSING_CHARS    128
#define ACMDRIVERDETAILS_FEATURES_CHARS     512

/* acmDriverDetails() special values */
#define ACMDRIVERDETAILS_FCCTYPE_AUDIOCODEC mmioFOURCC( 'a', 'u', 'd', 'c' )
#define ACMDRIVERDETAILS_FCCCOMP_UNDEFINED  mmioFOURCC( '\0', '\0', '\0', '\0' )

/* acmDriverDetails() support flags */
#define ACMDRIVERDETAILS_SUPPORTF_CODEC     0x00000001L
#define ACMDRIVERDETAILS_SUPPORTF_CONVERTER 0x00000002L
#define ACMDRIVERDETAILS_SUPPORTF_FILTER    0x00000004L
#define ACMDRIVERDETAILS_SUPPORTF_HARDWARE  0x00000008L
#define ACMDRIVERDETAILS_SUPPORTF_ASYNC     0x00000010L
#define ACMDRIVERDETAILS_SUPPORTF_LOCAL     0x40000000L
#define ACMDRIVERDETAILS_SUPPORTF_DISABLED  0x80000000L

/* acmFormatTagDetails() string length */
#define ACMFORMATTAGDETAILS_FORMATTAG_CHARS 48

/* acmFormatTagDetails() flags */
#define ACM_FORMATTAGDETAILSF_INDEX         0x00000000L
#define ACM_FORMATTAGDETAILSF_FORMATTAG     0x00000001L
#define ACM_FORMATTAGDETAILSF_LARGESTSIZE   0x00000002L
#define ACM_FORMATTAGDETAILSF_QUERYMASK     0x0000000FL

/* acmFormatDetails() string length */
#define ACMFORMATDETAILS_FORMAT_CHARS   128

/* acmFormatDetails() flags */
#define ACM_FORMATDETAILSF_INDEX        0x00000000L
#define ACM_FORMATDETAILSF_FORMAT       0x00000001L
#define ACM_FORMATDETAILSF_QUERYMASK    0x0000000FL

/* acmFormatEnum() flags */
#define ACM_FORMATENUMF_WFORMATTAG      0x00010000L
#define ACM_FORMATENUMF_NCHANNELS       0x00020000L
#define ACM_FORMATENUMF_NSAMPLESPERSEC  0x00040000L
#define ACM_FORMATENUMF_WBITSPERSAMPLE  0x00080000L
#define ACM_FORMATENUMF_CONVERT         0x00100000L
#define ACM_FORMATENUMF_SUGGEST         0x00200000L
#define ACM_FORMATENUMF_HARDWARE        0x00400000L
#define ACM_FORMATENUMF_INPUT           0x00800000L
#define ACM_FORMATENUMF_OUTPUT          0x01000000L

/* acmFormatSuggest() flags */
#define ACM_FORMATSUGGESTF_WFORMATTAG       0x00010000L
#define ACM_FORMATSUGGESTF_NCHANNELS        0x00020000L
#define ACM_FORMATSUGGESTF_NSAMPLESPERSEC   0x00040000L
#define ACM_FORMATSUGGESTF_WBITSPERSAMPLE   0x00080000L
#define ACM_FORMATSUGGESTF_TYPEMASK         0x00FF0000L

/* ACM registered messages */
#define ACMHELPMSGSTRINGA           "acmchoose_help"
#define ACMHELPMSGSTRINGW           L"acmchoose_help"
#define ACMHELPMSGCONTEXTMENUA      "acmchoose_contextmenu"
#define ACMHELPMSGCONTEXTMENUW      L"acmchoose_contextmenu"
#define ACMHELPMSGCONTEXTHELPA      "acmchoose_contexthelp"
#define ACMHELPMSGCONTEXTHELPW      L"acmchoose_contexthelp"
#ifdef UNICODE
    #define ACMHELPMSGSTRING        ACMHELPMSGSTRINGW
    #define ACMHELPMSGCONTEXTMENU   ACMHELPMSGCONTEXTMENUW
    #define ACMHELPMSGCONTEXTHELP   ACMHELPMSGCONTEXTHELPW
#else
    #define ACMHELPMSGSTRING        ACMHELPMSGSTRINGA
    #define ACMHELPMSGCONTEXTMENU   ACMHELPMSGCONTEXTMENUA
    #define ACMHELPMSGCONTEXTHELP   ACMHELPMSGCONTEXTHELPA
#endif

/* MM_ACM_FORMATCHOOSE codes */
#define FORMATCHOOSE_MESSAGE            0
#define FORMATCHOOSE_FORMATTAG_VERIFY   (FORMATCHOOSE_MESSAGE + 0)
#define FORMATCHOOSE_FORMAT_VERIFY      (FORMATCHOOSE_MESSAGE + 1)
#define FORMATCHOOSE_CUSTOM_VERIFY      (FORMATCHOOSE_MESSAGE + 2)

/* acmFormatChoose() style flags */
#define ACMFORMATCHOOSE_STYLEF_SHOWHELP             0x00000004L
#define ACMFORMATCHOOSE_STYLEF_ENABLEHOOK           0x00000008L
#define ACMFORMATCHOOSE_STYLEF_ENABLETEMPLATE       0x00000010L
#define ACMFORMATCHOOSE_STYLEF_ENABLETEMPLATEHANDLE 0x00000020L
#define ACMFORMATCHOOSE_STYLEF_INITTOWFXSTRUCT      0x00000040L
#define ACMFORMATCHOOSE_STYLEF_CONTEXTHELP          0x00000080L

/* acmFilterTagDetails() string length */
#define ACMFILTERTAGDETAILS_FILTERTAG_CHARS 48

/* acmFilterTagDetails() flags */
#define ACM_FILTERTAGDETAILSF_INDEX         0x00000000L
#define ACM_FILTERTAGDETAILSF_FILTERTAG     0x00000001L
#define ACM_FILTERTAGDETAILSF_LARGESTSIZE   0x00000002L
#define ACM_FILTERTAGDETAILSF_QUERYMASK     0x0000000FL

/* acmFilterDetails() string length */
#define ACMFILTERDETAILS_FILTER_CHARS   128

/* acmFilterDetails() flags */
#define ACM_FILTERDETAILSF_INDEX        0x00000000L
#define ACM_FILTERDETAILSF_FILTER       0x00000001L
#define ACM_FILTERDETAILSF_QUERYMASK    0x0000000FL

/* acmFilterEnum() flags */
#define ACM_FILTERENUMF_DWFILTERTAG 0x00010000L

/* MM_ACM_FILTERCHOOSE codes */
#define FILTERCHOOSE_MESSAGE            0
#define FILTERCHOOSE_FILTERTAG_VERIFY   (FILTERCHOOSE_MESSAGE + 0)
#define FILTERCHOOSE_FILTER_VERIFY      (FILTERCHOOSE_MESSAGE + 1)
#define FILTERCHOOSE_CUSTOM_VERIFY      (FILTERCHOOSE_MESSAGE + 2)

/* acmFilterChoose() flags */
#define ACMFILTERCHOOSE_STYLEF_SHOWHELP             0x00000004L
#define ACMFILTERCHOOSE_STYLEF_ENABLEHOOK           0x00000008L
#define ACMFILTERCHOOSE_STYLEF_ENABLETEMPLATE       0x00000010L
#define ACMFILTERCHOOSE_STYLEF_ENABLETEMPLATEHANDLE 0x00000020L
#define ACMFILTERCHOOSE_STYLEF_INITTOFILTERSTRUCT   0x00000040L
#define ACMFILTERCHOOSE_STYLEF_CONTEXTHELP          0x00000080L

/* Size of driver reserved data */
#define _DRVRESERVED    10

/* ACM stream header status flags */
#define ACMSTREAMHEADER_STATUSF_DONE        0x00010000L
#define ACMSTREAMHEADER_STATUSF_PREPARED    0x00020000L
#define ACMSTREAMHEADER_STATUSF_INQUEUE     0x00100000L

/* acmStreamOpen() flags */
#define ACM_STREAMOPENF_QUERY       0x00000001L
#define ACM_STREAMOPENF_ASYNC       0x00000002L
#define ACM_STREAMOPENF_NONREALTIME 0x00000004L

/* acmStreamSize() flags */
#define ACM_STREAMSIZEF_SOURCE      0x00000000L
#define ACM_STREAMSIZEF_DESTINATION 0x00000001L
#define ACM_STREAMSIZEF_QUERYMASK   0x0000000FL

/* acmStreamConvert() flags */
#define ACM_STREAMCONVERTF_BLOCKALIGN   0x00000004L
#define ACM_STREAMCONVERTF_START        0x00000010L
#define ACM_STREAMCONVERTF_END          0x00000020L

/* ACM driver enumeration callback */
typedef BOOL (CALLBACK *ACMDRIVERENUMCB)( HACMDRIVERID, DWORD_PTR, DWORD );

/* ACM driver procedure */
typedef LRESULT (CALLBACK *ACMDRIVERPROC)( DWORD_PTR, HACMDRIVERID, UINT, LPARAM, LPARAM );
typedef ACMDRIVERPROC   *LPACMDRIVERPROC;

/* acmDriverDetails() parameters */
typedef struct tACMDRIVERDETAILSA {
    DWORD   cbStruct;
    FOURCC  fccType;
    FOURCC  fccComp;
    WORD    wMid;
    WORD    wPid;
    DWORD   vdwACM;
    DWORD   vdwDriver;
    DWORD   fdwSupport;
    DWORD   cFormatTags;
    DWORD   cFilterTags;
    HICON   hicon;
    char    szShortName[ACMDRIVERDETAILS_SHORTNAME_CHARS];
    char    szLongName[ACMDRIVERDETAILS_LONGNAME_CHARS];
    char    szCopyright[ACMDRIVERDETAILS_COPYRIGHT_CHARS];
    char    szLicensing[ACMDRIVERDETAILS_LICENSING_CHARS];
    char    szFeatures[ACMDRIVERDETAILS_FEATURES_CHARS];
} ACMDRIVERDETAILSA;
typedef ACMDRIVERDETAILSA   *PACMDRIVERDETAILSA;
typedef ACMDRIVERDETAILSA   *LPACMDRIVERDETAILSA;
typedef struct tACMDRIVERDETAILSW {
    DWORD   cbStruct;
    FOURCC  fccType;
    FOURCC  fccComp;
    WORD    wMid;
    WORD    wPid;
    DWORD   vdwACM;
    DWORD   vdwDriver;
    DWORD   fdwSupport;
    DWORD   cFormatTags;
    DWORD   cFilterTags;
    HICON   hicon;
    WCHAR   szShortName[ACMDRIVERDETAILS_SHORTNAME_CHARS];
    WCHAR   szLongName[ACMDRIVERDETAILS_LONGNAME_CHARS];
    WCHAR   szCopyright[ACMDRIVERDETAILS_COPYRIGHT_CHARS];
    WCHAR   szLicensing[ACMDRIVERDETAILS_LICENSING_CHARS];
    WCHAR   szFeatures[ACMDRIVERDETAILS_FEATURES_CHARS];
} ACMDRIVERDETAILSW;
typedef ACMDRIVERDETAILSW   *PACMDRIVERDETAILSW;
typedef ACMDRIVERDETAILSW   *LPACMDRIVERDETAILSW;
#ifdef UNICODE
typedef ACMDRIVERDETAILSW   ACMDRIVERDETAILS;
typedef PACMDRIVERDETAILSW  PACMDRIVERDETAILS;
typedef LPACMDRIVERDETAILSW LPACMDRIVERDETAILS;
#else
typedef ACMDRIVERDETAILSA   ACMDRIVERDETAILS;
typedef PACMDRIVERDETAILSA  PACMDRIVERDETAILS;
typedef LPACMDRIVERDETAILSA LPACMDRIVERDETAILS;
#endif

/* acmFormatTagDetails() parameters */
typedef struct tACMFORMATTAGDETAILSA {
    DWORD   cbStruct;
    DWORD   dwFormatTagIndex;
    DWORD   dwFormatTag;
    DWORD   cbFormatSize;
    DWORD   fdwSupport;
    DWORD   cStandardFormats;
    char    szFormatTag[ACMFORMATTAGDETAILS_FORMATTAG_CHARS];
} ACMFORMATTAGDETAILSA;
typedef ACMFORMATTAGDETAILSA    *PACMFORMATTAGDETAILSA;
typedef ACMFORMATTAGDETAILSA    *LPACMFORMATTAGDETAILSA;
typedef struct tACMFORMATTAGDETAILSW {
    DWORD   cbStruct;
    DWORD   dwFormatTagIndex;
    DWORD   dwFormatTag;
    DWORD   cbFormatSize;
    DWORD   fdwSupport;
    DWORD   cStandardFormats;
    WCHAR   szFormatTag[ACMFORMATTAGDETAILS_FORMATTAG_CHARS];
} ACMFORMATTAGDETAILSW;
typedef ACMFORMATTAGDETAILSW    *PACMFORMATTAGDETAILSW;
typedef ACMFORMATTAGDETAILSW    *LPACMFORMATTAGDETAILSW;
#ifdef UNICODE
typedef ACMFORMATTAGDETAILSW    ACMFORMATTAGDETAILS;
typedef PACMFORMATTAGDETAILSW   PACMFORMATTAGDETAILS;
typedef LPACMFORMATTAGDETAILSW  LPACMFORMATTAGDETAILS;
#else
typedef ACMFORMATTAGDETAILSA    ACMFORMATTAGDETAILS;
typedef PACMFORMATTAGDETAILSA   PACMFORMATTAGDETAILS;
typedef LPACMFORMATTAGDETAILSA  LPACMFORMATTAGDETAILS;
#endif

/* ACM format tag enumeration callback */
typedef BOOL (CALLBACK *ACMFORMATTAGENUMCBA)( HACMDRIVERID, LPACMFORMATTAGDETAILSA, DWORD_PTR, DWORD );
typedef BOOL (CALLBACK *ACMFORMATTAGENUMCBW)( HACMDRIVERID, LPACMFORMATTAGDETAILSW, DWORD_PTR, DWORD );
#ifdef UNICODE
    #define ACMFORMATTAGENUMCB  ACMFORMATTAGENUMCBW
#else
    #define ACMFORMATTAGENUMCB  ACMFORMATTAGENUMCBA
#endif

/* acmFormatDetails() parameters */
typedef struct tACMFORMATDETAILSA {
    DWORD           cbStruct;
    DWORD           dwFormatIndex;
    DWORD           dwFormatTag;
    DWORD           fdwSupport;
    LPWAVEFORMATEX  pwfx;
    DWORD           cbwfx;
    char            szFormat[ACMFORMATDETAILS_FORMAT_CHARS];
} ACMFORMATDETAILSA;
typedef ACMFORMATDETAILSA   *PACMFORMATDETAILSA;
typedef ACMFORMATDETAILSA   *LPACMFORMATDETAILSA;
typedef struct tACMFORMATDETAILSW {
    DWORD           cbStruct;
    DWORD           dwFormatIndex;
    DWORD           dwFormatTag;
    DWORD           fdwSupport;
    LPWAVEFORMATEX  pwfx;
    DWORD           cbwfx;
    WCHAR           szFormat[ACMFORMATDETAILS_FORMAT_CHARS];
} ACMFORMATDETAILSW;
typedef ACMFORMATDETAILSW   *PACMFORMATDETAILSW;
typedef ACMFORMATDETAILSW   *LPACMFORMATDETAILSW;
#ifdef UNICODE
typedef ACMFORMATDETAILSW   ACMFORMATDETAILS;
typedef PACMFORMATDETAILSW  PACMFORMATDETAILS;
typedef LPACMFORMATDETAILSW LPACMFORMATDETAILS;
#else
typedef ACMFORMATDETAILSA   ACMFORMATDETAILS;
typedef PACMFORMATDETAILSA  PACMFORMATDETAILS;
typedef LPACMFORMATDETAILSA LPACMFORMATDETAILS;
#endif

/* ACM format enumeration callback */
typedef BOOL (CALLBACK *ACMFORMATENUMCBA)( HACMDRIVERID, LPACMFORMATDETAILSA, DWORD_PTR, DWORD );
typedef BOOL (CALLBACK *ACMFORMATENUMCBW)( HACMDRIVERID, LPACMFORMATDETAILSW, DWORD_PTR, DWORD );
#ifdef UNICODE
    #define ACMFORMATENUMCB ACMFORMATENUMCBW
#else
    #define ACMFORMATENUMCB ACMFORMATENUMCBA
#endif

/* acmFormatChoose() hook procedure */
typedef UINT (CALLBACK *ACMFORMATCHOOSEHOOKPROCA)( HWND, UINT, WPARAM, LPARAM );
typedef UINT (CALLBACK *ACMFORMATCHOOSEHOOKPROCW)( HWND, UINT, WPARAM, LPARAM );
#ifdef UNICODE
    #define ACMFORMATCHOOSEHOOKPROC ACMFORMATCHOOSEHOOKPROCW
#else
    #define ACMFORMATCHOOSEHOOKPROC ACMFORMATCHOOSEHOOKPROCA
#endif

/* acmFormatChoose() parameters */
typedef struct tACMFORMATCHOOSEA {
    DWORD                       cbStruct;
    DWORD                       fdwStyle;
    HWND                        hwndOwner;
    LPWAVEFORMATEX              pwfx;
    DWORD                       cbwfx;
    LPCSTR                      pszTitle;
    char                        szFormatTag[ACMFORMATTAGDETAILS_FORMATTAG_CHARS];
    char                        szFormat[ACMFORMATDETAILS_FORMAT_CHARS];
    LPSTR                       pszName;
    DWORD                       cchName;
    DWORD                       fdwEnum;
    LPWAVEFORMATEX              pwfxEnum;
    HINSTANCE                   hInstance;
    LPCSTR                      pszTemplateName;
    LPARAM                      lCustData;
    ACMFORMATCHOOSEHOOKPROCA    pfnHook;
} ACMFORMATCHOOSEA;
typedef ACMFORMATCHOOSEA    *PACMFORMATCHOOSEA;
typedef ACMFORMATCHOOSEA    *LPACMFORMATCHOOSEA;
typedef struct tACMFORMATCHOOSEW {
    DWORD                       cbStruct;
    DWORD                       fdwStyle;
    HWND                        hwndOwner;
    LPWAVEFORMATEX              pwfx;
    DWORD                       cbwfx;
    LPCWSTR                     pszTitle;
    WCHAR                       szFormatTag[ACMFORMATTAGDETAILS_FORMATTAG_CHARS];
    WCHAR                       szFormat[ACMFORMATDETAILS_FORMAT_CHARS];
    LPWSTR                      pszName;
    DWORD                       cchName;
    DWORD                       fdwEnum;
    LPWAVEFORMATEX              pwfxEnum;
    HINSTANCE                   hInstance;
    LPCWSTR                     pszTemplateName;
    LPARAM                      lCustData;
    ACMFORMATCHOOSEHOOKPROCW    pfnHook;
} ACMFORMATCHOOSEW;
typedef ACMFORMATCHOOSEW    *PACMFORMATCHOOSEW;
typedef ACMFORMATCHOOSEW    *LPACMFORMATCHOOSEW;
#ifdef UNICODE
typedef ACMFORMATCHOOSEW    ACMFORMATCHOOSE;
typedef PACMFORMATCHOOSEW   PACMFORMATCHOOSE;
typedef LPACMFORMATCHOOSEW  LPACMFORMATCHOOSE;
#else
typedef ACMFORMATCHOOSEA    ACMFORMATCHOOSE;
typedef PACMFORMATCHOOSEA   PACMFORMATCHOOSE;
typedef LPACMFORMATCHOOSEA  LPACMFORMATCHOOSE;
#endif

/* acmFilterTagDetails() parameters */
typedef struct tACMFILTERTAGDETAILSA {
    DWORD   cbStruct;
    DWORD   dwFilterTagIndex;
    DWORD   dwFilterTag;
    DWORD   cbFilterSize;
    DWORD   fdwSupport;
    DWORD   cStandardFilters;
    char    szFilterTag[ACMFILTERTAGDETAILS_FILTERTAG_CHARS];
} ACMFILTERTAGDETAILSA;
typedef ACMFILTERTAGDETAILSA    *PACMFILTERTAGDETAILSA;
typedef ACMFILTERTAGDETAILSA    *LPACMFILTERTAGDETAILSA;
typedef struct tACMFILTERTAGDETAILSW {
    DWORD   cbStruct;
    DWORD   dwFilterTagIndex;
    DWORD   dwFilterTag;
    DWORD   cbFilterSize;
    DWORD   fdwSupport;
    DWORD   cStandardFilters;
    WCHAR   szFilterTag[ACMFILTERTAGDETAILS_FILTERTAG_CHARS];
} ACMFILTERTAGDETAILSW;
typedef ACMFILTERTAGDETAILSW    *PACMFILTERTAGDETAILSW;
typedef ACMFILTERTAGDETAILSW    *LPACMFILTERTAGDETAILSW;
#ifdef UNICODE
typedef ACMFILTERTAGDETAILSW    ACMFILTERTAGDETAILS;
typedef PACMFILTERTAGDETAILSW   PACMFILTERTAGDETAILS;
typedef LPACMFILTERTAGDETAILSW  LPACMFILTERTAGDETAILS;
#else
typedef ACMFILTERTAGDETAILSA    ACMFILTERTAGDETAILS;
typedef PACMFILTERTAGDETAILSA   PACMFILTERTAGDETAILS;
typedef LPACMFILTERTAGDETAILSA  LPACMFILTERTAGDETAILS;
#endif

/* ACM filter tag enumeration callback */
typedef BOOL (CALLBACK *ACMFILTERTAGENUMCBA)( HACMDRIVERID, LPACMFILTERTAGDETAILSA, DWORD_PTR, DWORD );
typedef BOOL (CALLBACK *ACMFILTERTAGENUMCBW)( HACMDRIVERID, LPACMFILTERTAGDETAILSW, DWORD_PTR, DWORD );
#ifdef UNICODE
    #define ACMFILTERTAGENUMCB  ACMFILTERTAGENUMCBW
#else
    #define ACMFILTERTAGENUMCB  ACMFILTERTAGENUMCBA
#endif

/* acmFilterDetails() parameters */
typedef struct tACMFILTERDETAILSA {
    DWORD           cbStruct;
    DWORD           dwFilterIndex;
    DWORD           dwFilterTag;
    DWORD           fdwSupport;
    LPWAVEFILTER    pwfltr;
    DWORD           cbwfltr;
    char            szFilter[ACMFILTERDETAILS_FILTER_CHARS];
} ACMFILTERDETAILSA;
typedef ACMFILTERDETAILSA   *PACMFILTERDETAILSA;
typedef ACMFILTERDETAILSA   *LPACMFILTERDETAILSA;
typedef struct tACMFILTERDETAILSW {
    DWORD           cbStruct;
    DWORD           dwFilterIndex;
    DWORD           dwFilterTag;
    DWORD           fdwSupport;
    LPWAVEFILTER    pwfltr;
    DWORD           cbwfltr;
    WCHAR           szFilter[ACMFILTERDETAILS_FILTER_CHARS];
} ACMFILTERDETAILSW;
typedef ACMFILTERDETAILSW   *PACMFILTERDETAILSW;
typedef ACMFILTERDETAILSW   *LPACMFILTERDETAILSW;
#ifdef UNICODE
typedef ACMFILTERDETAILSW   ACMFILTERDETAILS;
typedef PACMFILTERDETAILSW  PACMFILTERDETAILS;
typedef LPACMFILTERDETAILSW LPACMFILTERDETAILS;
#else
typedef ACMFILTERDETAILSA   ACMFILTERDETAILS;
typedef PACMFILTERDETAILSA  PACMFILTERDETAILS;
typedef LPACMFILTERDETAILSA LPACMFILTERDETAILS;
#endif

/* ACM filter enumeration callback */
typedef BOOL (CALLBACK *ACMFILTERENUMCBA)( HACMDRIVERID, LPACMFILTERDETAILSA, DWORD_PTR, DWORD );
typedef BOOL (CALLBACK *ACMFILTERENUMCBW)( HACMDRIVERID, LPACMFILTERDETAILSW, DWORD_PTR, DWORD );
#ifdef UNICODE
    #define ACMFILTERENUMCB ACMFILTERENUMCBW
#else
    #define ACMFILTERENUMCB ACMFILTERENUMCBA
#endif

/* acmFilterChoose() callback procedure */
typedef UINT (CALLBACK *ACMFILTERCHOOSEHOOKPROCA)( HWND, UINT, WPARAM, LPARAM );
typedef UINT (CALLBACK *ACMFILTERCHOOSEHOOKPROCW)( HWND, UINT, WPARAM, LPARAM );
#ifdef UNICODE
    #define ACMFILTERCHOOSEHOOKPROC ACMFILTERCHOOSEHOOKPROCW
#else
    #define ACMFILTERCHOOSEHOOKPROC ACMFILTERCHOOSEHOOKPROCA
#endif

/* acmFilterChoose() parameters */
typedef struct tACMFILTERCHOOSEA {
    DWORD                       cbStruct;
    DWORD                       fdwStyle;
    HWND                        hwndOwner;
    LPWAVEFILTER                pwfltr;
    DWORD                       cbwfltr;
    LPCSTR                      pszTitle;
    char                        szFilterTag[ACMFILTERTAGDETAILS_FILTERTAG_CHARS];
    char                        szFilter[ACMFILTERDETAILS_FILTER_CHARS];
    LPSTR                       pszName;
    DWORD                       cchName;
    DWORD                       fdwEnum;
    LPWAVEFILTER                pwfltrEnum;
    HINSTANCE                   hInstance;
    LPCSTR                      pszTemplateName;
    LPARAM                      lCustData;
    ACMFILTERCHOOSEHOOKPROCA    pfnHook;
} ACMFILTERCHOOSEA;
typedef ACMFILTERCHOOSEA    *PACMFILTERCHOOSEA;
typedef ACMFILTERCHOOSEA    *LPACMFILTERCHOOSEA;
typedef struct tACMFILTERCHOOSEW {
    DWORD                       cbStruct;
    DWORD                       fdwStyle;
    HWND                        hwndOwner;
    LPWAVEFILTER                pwfltr;
    DWORD                       cbwfltr;
    LPCWSTR                     pszTitle;
    WCHAR                       szFilterTag[ACMFILTERTAGDETAILS_FILTERTAG_CHARS];
    WCHAR                       szFilter[ACMFILTERDETAILS_FILTER_CHARS];
    LPWSTR                      pszName;
    DWORD                       cchName;
    DWORD                       fdwEnum;
    LPWAVEFILTER                pwfltrEnum;
    HINSTANCE                   hInstance;
    LPCWSTR                     pszTemplateName;
    LPARAM                      lCustData;
    ACMFILTERCHOOSEHOOKPROCW    pfnHook;
} ACMFILTERCHOOSEW;
typedef ACMFILTERCHOOSEW    *PACMFILTERCHOOSEW;
typedef ACMFILTERCHOOSEW    *LPACMFILTERCHOOSEW;
#ifdef UNICODE
typedef ACMFILTERCHOOSEW    ACMFILTERCHOOSE;
typedef PACMFILTERCHOOSEW   PACMFILTERCHOOSE;
typedef LPACMFILTERCHOOSEW  LPACMFILTERCHOOSE;
#else
typedef ACMFILTERCHOOSEA    ACMFILTERCHOOSE;
typedef PACMFILTERCHOOSEA   PACMFILTERCHOOSE;
typedef LPACMFILTERCHOOSEA  LPACMFILTERCHOOSE;
#endif

/* ACM stream header */
typedef struct tACMSTREAMHEADER {
    DWORD       cbStruct;
    DWORD       fdwStatus;
    DWORD_PTR   dwUser;
    LPBYTE      pbSrc;
    DWORD       cbSrcLength;
    DWORD       cbSrcLengthUsed;
    DWORD_PTR   dwSrcUser;
    LPBYTE      pbDst;
    DWORD       cbDstLength;
    DWORD       cbDstLengthUsed;
    DWORD_PTR   dwDstUser;
    DWORD       dwReservedDriver[_DRVRESERVED];
} ACMSTREAMHEADER;
typedef ACMSTREAMHEADER *PACMSTREAMHEADER;
typedef ACMSTREAMHEADER *LPACMSTREAMHEADER;

/* Functions in MSACM32.DLL */
MMRESULT ACMAPI acmDriverAddA( LPHACMDRIVERID, HINSTANCE, LPARAM, DWORD, DWORD );
MMRESULT ACMAPI acmDriverAddW( LPHACMDRIVERID, HINSTANCE, LPARAM, DWORD, DWORD );
MMRESULT ACMAPI acmDriverClose( HACMDRIVER, DWORD );
MMRESULT ACMAPI acmDriverDetailsA( HACMDRIVERID, LPACMDRIVERDETAILSA, DWORD );
MMRESULT ACMAPI acmDriverDetailsW( HACMDRIVERID, LPACMDRIVERDETAILSW, DWORD );
MMRESULT ACMAPI acmDriverEnum( ACMDRIVERENUMCB, DWORD_PTR, DWORD );
MMRESULT ACMAPI acmDriverID( HACMOBJ, LPHACMDRIVERID, DWORD );
LRESULT ACMAPI  acmDriverMessage( HACMDRIVER, UINT, LPARAM, LPARAM );
MMRESULT ACMAPI acmDriverOpen( LPHACMDRIVER, HACMDRIVERID, DWORD );
MMRESULT ACMAPI acmDriverPriority( HACMDRIVERID, DWORD, DWORD );
MMRESULT ACMAPI acmDriverRemove( HACMDRIVERID, DWORD );
MMRESULT ACMAPI acmFilterChooseA( LPACMFILTERCHOOSEA );
MMRESULT ACMAPI acmFilterChooseW( LPACMFILTERCHOOSEW );
MMRESULT ACMAPI acmFilterDetailsA( HACMDRIVER, LPACMFILTERDETAILSA, DWORD );
MMRESULT ACMAPI acmFilterDetailsW( HACMDRIVER, LPACMFILTERDETAILSW, DWORD );
MMRESULT ACMAPI acmFilterEnumA( HACMDRIVER, LPACMFILTERDETAILSA, ACMFILTERENUMCBA, DWORD_PTR, DWORD );
MMRESULT ACMAPI acmFilterEnumW( HACMDRIVER, LPACMFILTERDETAILSW, ACMFILTERENUMCBW, DWORD_PTR, DWORD );
MMRESULT ACMAPI acmFilterTagDetailsA( HACMDRIVER, LPACMFILTERTAGDETAILSA, DWORD );
MMRESULT ACMAPI acmFilterTagDetailsW( HACMDRIVER, LPACMFILTERTAGDETAILSW, DWORD );
MMRESULT ACMAPI acmFilterTagEnumA( HACMDRIVER, LPACMFILTERTAGDETAILSA, ACMFILTERTAGENUMCBA, DWORD_PTR, DWORD );
MMRESULT ACMAPI acmFilterTagEnumW( HACMDRIVER, LPACMFILTERTAGDETAILSW, ACMFILTERTAGENUMCBW, DWORD_PTR, DWORD );
MMRESULT ACMAPI acmFormatChooseA( LPACMFORMATCHOOSEA );
MMRESULT ACMAPI acmFormatChooseW( LPACMFORMATCHOOSEW );
MMRESULT ACMAPI acmFormatDetailsA( HACMDRIVER, LPACMFORMATDETAILSA, DWORD );
MMRESULT ACMAPI acmFormatDetailsW( HACMDRIVER, LPACMFORMATDETAILSW, DWORD );
MMRESULT ACMAPI acmFormatEnumA( HACMDRIVER, LPACMFORMATDETAILSA, ACMFORMATENUMCBA, DWORD_PTR, DWORD );
MMRESULT ACMAPI acmFormatEnumW( HACMDRIVER, LPACMFORMATDETAILSW, ACMFORMATENUMCBW, DWORD_PTR, DWORD );
MMRESULT ACMAPI acmFormatSuggest( HACMDRIVER, LPWAVEFORMATEX, LPWAVEFORMATEX, DWORD, DWORD );
MMRESULT ACMAPI acmFormatTagDetailsA( HACMDRIVER, LPACMFORMATTAGDETAILSA, DWORD );
MMRESULT ACMAPI acmFormatTagDetailsW( HACMDRIVER, LPACMFORMATTAGDETAILSW, DWORD );
MMRESULT ACMAPI acmFormatTagEnumA( HACMDRIVER, LPACMFORMATTAGDETAILSA, ACMFORMATTAGENUMCBA, DWORD_PTR, DWORD );
MMRESULT ACMAPI acmFormatTagEnumW( HACMDRIVER, LPACMFORMATTAGDETAILSW, ACMFORMATTAGENUMCBW, DWORD_PTR, DWORD );
DWORD ACMAPI    acmGetVersion( void );
MMRESULT ACMAPI acmMetrics( HACMOBJ, UINT, LPVOID );
MMRESULT ACMAPI acmStreamClose( HACMSTREAM, DWORD );
MMRESULT ACMAPI acmStreamConvert( HACMSTREAM, LPACMSTREAMHEADER, DWORD );
MMRESULT ACMAPI acmStreamMessage( HACMSTREAM, UINT, LPARAM, LPARAM );
MMRESULT ACMAPI acmStreamOpen( LPHACMSTREAM, HACMDRIVER, LPWAVEFORMATEX, LPWAVEFORMATEX, LPWAVEFILTER, DWORD_PTR, DWORD_PTR, DWORD );
MMRESULT ACMAPI acmStreamPrepareHeader( HACMSTREAM, LPACMSTREAMHEADER, DWORD );
MMRESULT ACMAPI acmStreamReset( HACMSTREAM, DWORD );
MMRESULT ACMAPI acmStreamSize( HACMSTREAM, DWORD, LPDWORD, DWORD );
MMRESULT ACMAPI acmStreamUnprepareHeader( HACMSTREAM, LPACMSTREAMHEADER, DWORD );

/* Map generic function names to the appropriate ANSI or Unicode version. */
#ifdef UNICODE
    #define acmDriverAdd        acmDriverAddW
    #define acmDriverDetails    acmDriverDetailsW
    #define acmFilterChoose     acmFilterChooseW
    #define acmFilterDetails    acmFilterDetailsW
    #define acmFilterEnum       acmFilterEnumW
    #define acmFilterTagDetails acmFilterTagDetailsW
    #define acmFilterTagEnum    acmFilterTagEnumW
    #define acmFormatChoose     acmFormatChooseW
    #define acmFormatDetails    acmFormatDetailsW
    #define acmFormatEnum       acmFormatEnumW
    #define acmFormatTagDetails acmFormatTagDetailsW
    #define acmFormatTagEnum    acmFormatTagEnumW
#else
    #define acmDriverAdd        acmDriverAddA
    #define acmDriverDetails    acmDriverDetailsA
    #define acmFilterChoose     acmFilterChooseA
    #define acmFilterDetails    acmFilterDetailsA
    #define acmFilterEnum       acmFilterEnumA
    #define acmFilterTagDetails acmFilterTagDetailsA
    #define acmFilterTagEnum    acmFilterTagEnumA
    #define acmFormatChoose     acmFormatChooseA
    #define acmFormatDetails    acmFormatDetailsA
    #define acmFormatEnum       acmFormatEnumA
    #define acmFormatTagDetails acmFormatTagDetailsA
    #define acmFormatTagEnum    acmFormatTagEnumA
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _INC_ACM */
