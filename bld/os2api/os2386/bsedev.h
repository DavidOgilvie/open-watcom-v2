/*
 *  bsedev.mh   OS/2 Base device support include file for 32-bit development.
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

#ifndef __BSEDEV__
#define __BSEDEV__

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define BSEDEV_INCLUDED

#define IOCTL_ASYNC           0x0001
#define IOCTL_SCR_AND_PTRDRAW 0x0003
#define IOCTL_KEYBOARD        0x0004
#define IOCTL_PRINTER         0x0005
#define IOCTL_LIGHTPEN        0x0006
#define IOCTL_POINTINGDEVICE  0x0007
#define IOCTL_DISK            0x0008
#define IOCTL_PHYSICALDISK    0x0009
#define IOCTL_MONITOR         0x000a
#define IOCTL_GENERAL         0x000b
#define IOCTL_POWER           0x000c
#define IOCTL_OEMHLP          0x0080
#define IOCTL_TESTCFG_SYS     0x0080
#define IOCTL_CDROMDISK       0x0080
#define IOCTL_CDROMAUDIO      0x0081
#define IOCTL_TOUCH_DEVDEP    0x0081
#define IOCTL_TOUCH_DEVINDEP  0x0081

#define ASYNC_SETBAUDRATE          0x0041
#define ASYNC_SETLINECTRL          0x0042
#define ASYNC_EXTSETBAUDRATE       0x0043
#define ASYNC_TRANSMITIMM          0x0044
#define ASYNC_SETBREAKOFF          0x0045
#define ASYNC_SETMODEMCTRL         0x0046
#define ASYNC_SETBREAKON           0x004B
#define ASYNC_STOPTRANSMIT         0x0047
#define ASYNC_STARTTRANSMIT        0x0048
#define ASYNC_SETDCBINFO           0x0053
#define ASYNC_SETENHANCEDMODEPARMS 0x0054
#define ASYNC_GETBAUDRATE          0x0061
#define ASYNC_GETLINECTRL          0x0062
#define ASYNC_EXTGETBAUDRATE       0x0063
#define ASYNC_GETCOMMSTATUS        0x0064
#define ASYNC_GETLINESTATUS        0x0065
#define ASYNC_GETMODEMOUTPUT       0x0066
#define ASYNC_GETMODEMINPUT        0x0067
#define ASYNC_GETINQUECOUNT        0x0068
#define ASYNC_GETOUTQUECOUNT       0x0069
#define ASYNC_GETCOMMERROR         0x006d
#define ASYNC_GETCOMMEVENT         0x0072
#define ASYNC_GETDCBINFO           0x0073
#define ASYNC_GETENHANCEDMODEPARMS 0x0074

#define SCR_ALLOCLDT          0x0070
#define SCR_DEALLOCLDT        0x0071
#define PTR_GETPTRDRAWADDRESS 0x0072
#define VID_INITCALLVECTOR    0x0073
#define SCR_ABIOSPASSTHRU     0x0074
#define SCR_ALLOCLDTOFF       0x0075
#define SCR_ALLOCLDTBGVAL     0x0076
#define SCR_ALLOCVIDEOBUFFER  0x007e
#define SCR_GETROMFONTADDR    0x007f

#define KBD_SETTRANSTABLE           0x0050
#define KBD_SETINPUTMODE            0x0051
#define KBD_SETINTERIMFLAG          0x0052
#define KBD_SETSHIFTSTATE           0x0053
#define KBD_SETTYPAMATICRATE        0x0054
#define KBD_SETFGNDSCREENGRP        0x0055
#define KBD_SETSESMGRHOTKEY         0x0056
#define KBD_SETFOCUS                0x0057
#define KBD_SETKCB                  0x0058
#define KBD_SETREADNOTIFICATION     0x0059
#define KBD_ALTERKBDLED             0x005a
#define KBD_SETNLS                  0x005c
#define KBD_CREATE                  0x005d
#define KBD_DESTROY                 0x005e
#define KBD_GETINPUTMODE            0x0071
#define KBD_GETINTERIMFLAG          0x0072
#define KBD_GETSHIFTSTATE           0x0073
#define KBD_READCHAR                0x0074
#define KBD_PEEKCHAR                0x0075
#define KBD_GETSESMGRHOTKEY         0x0076
#define KBD_GETKEYBDTYPE            0x0077
#define KBD_GETCODEPAGEID           0x0078
#define KBD_XLATESCAN               0x0079
#define KBD_QUERYKBDHARDWAREID      0x007a
#define KBD_QUERYKBDCODEPAGESUPPORT 0x007b

#define PRT_QUERYJOBHANDLE    0x0021
#define PRT_SETFRAMECTL       0x0042
#define PRT_SETINFINITERETRY  0x0044
#define PRT_INITPRINTER       0x0046
#define PRT_ACTIVATEFONT      0x0048
#define PRT_SETPRINTJOBTITLE  0x004d
#define PRT_SETIRQTIMEOUT     0x004e
#define PRT_SETCOMMMODE       0x0052
#define PRT_SETDATAXFERMODE   0x0053
#define PRT_GETFRAMECTL       0x0062
#define PRT_GETINFINITERETRY  0x0064
#define PRT_GETPRINTERSTATUS  0x0066
#define PRT_QUERYACTIVEFONT   0x0069
#define PRT_VERIFYFONT        0x006a
#define PRT_QUERYIRQTIMEOUT   0x006e
#define PRT_QUERYCOMMMODE     0x0072
#define PRT_QUERYDATAXFERMODE 0x0073
#define PRT_QUERDEVICEID      0x0074

#define MOU_ALLOWPTRDRAW            0x0050
#define MOU_UPDATEDISPLAYMODE       0x0051
#define MOU_SCREENSWITCH            0x0052
#define MOU_SETSCALEFACTORS         0x0053
#define MOU_SETEVENTMASK            0x0054
#define MOU_SETHOTKEYBUTTON         0x0055
#define MOU_REASSIGNTHRESHOLDVALUES 0x0055
#define MOU_SETPTRSHAPE             0x0056
#define MOU_DRAWPTR                 0x0057
#define MOU_UNMARKCOLLISIONAREA     0x0057
#define MOU_REMOVEPTR               0x0058
#define MOU_MARKCOLLISIONAREA       0x0058
#define MOU_SETPTRPOS               0x0059
#define MOU_SETPROTDRAWADDRESS      0x005a
#define MOU_SETREALDRAWADDRESS      0x005b
#define MOU_SETMOUSTATUS            0x005c
#define MOU_DISPLAYMODECHANGE       0x005d
#define MOU_GETBUTTONCOUNT          0x0060
#define MOU_GETMICKEYCOUNT          0x0061
#define MOU_GETMOUSTATUS            0x0062
#define MOU_READEVENTQUE            0x0063
#define MOU_GETQUESTATUS            0x0064
#define MOU_GETEVENTMASK            0x0065
#define MOU_GETSCALEFACTORS         0x0066
#define MOU_GETPTRPOS               0x0067
#define MOU_GETPTRSHAPE             0x0068
#define MOU_GETHOTKEYBUTTON         0x0069
#define MOU_QUERYTHRESHOLDVALUES    0x0069
#define MOU_VER                     0x006a
#define MOU_QUERYPOINTERID          0x006b

#define DSK_LOCKDRIVE        0x0000
#define DSK_UNLOCKDRIVE      0x0001
#define DSK_REDETERMINEMEDIA 0x0002
#define DSK_SETLOGICALMAP    0x0003
#define DSK_BEGINFORMAT      0x0004
#define DSK_BLOCKREMOVABLE   0x0020
#define DSK_GETLOGICALMAP    0x0021
#define DSK_UNLOCKEJECTMEDIA 0x0040
#define DSK_SETDEVICEPARAMS  0x0043
#define DSK_WRITETRACK       0x0044
#define DSK_FORMATVERIFY     0x0045
#define DSK_DISKETTECONTROL  0x005d
#define DSK_QUERYMEDIASENSE  0x0060
#define DSK_GETDEVICEPARAMS  0x0063
#define DSK_READTRACK        0x0064
#define DSK_VERIFYTRACK      0x0065
#define DSK_GETLOCKSTATUS    0x0066

#define PDSK_LOCKPHYSDRIVE       0x0000
#define PDSK_UNLOCKPHYSDRIVE     0x0001
#define PDSK_WRITEPHYSTRACK      0x0044
#define PDSK_GETPHYSDEVICEPARAMS 0x0063
#define PDSK_READPHYSTRACK       0x0064
#define PDSK_VERIFYPHYSTRACK     0x0065

#define MON_REGISTERMONITOR 0x0040

#define DEV_FLUSHINPUT      0x0001
#define DEV_FLUSHOUTPUT     0x0002
#define DEV_SYSTEMNOTIFYPDD 0x0041
#define DEV_QUERYMONSUPPORT 0x0060

#define POWER_SENDPOWEREVENT   0x0040
#define POWER_SETPOWEREVENTRES 0x0041
#define POWER_GETPOWERSTATUS   0x0060
#define POWER_GETPOWEREVENT    0x0061
#define POWER_GETPOWERINFO     0x0062

#define OEMHLP_GETOEMADAPTIONINFO 0x0000
#define OEMHLP_GETMACHINEINFO     0x0001
#define OEMHLP_GETDISPLAYCOMBCODE 0x0002
#define OEMHLP_GETVIDEOFONTS      0x0003
#define OEMHLP_READEISACONFIGINFO 0x0004
#define OEMHLP_GETROMBIOSINFO     0x0005
#define OEMHLP_GETMISCVIDEOINFO   0x0006
#define OEMHLP_GETVIDEOADAPTER    0x0007
#define OEMHLP_GETSVGAINFO        0x0008
#define OEMHLP_GETMEMINFO         0x0009
#define OEMHLP_GETDMQSINFO        0x000a
#define OEMHLP_PCI                0x000b
#define OEMHLP_QUERYDISKINFO      0x000e

#define TESTCFG_SYS_GETBIOSADAPTER  0x0040
#define TESTCFG_SYS_ISSUEINIOINSTR  0x0041
#define TESTCFG_SYS_ISSUEOUTIOINSTR 0x0042
#define TESTCFG_SYS_GETBUSARCH      0x0060
#define TESTCFG_SYS_GETALLPOSIDS    0x0061
#define TESTCFG_SYS_GETALLEISAIDS   0x0062

#define CDROMDISK_RESETDRIVE     0x0040
#define CDROMDISK_EJECTDISK      0x0044
#define CDROMDISK_LOCKUNLOCKDOOR 0x0046
#define CDROMDISK_SEEK           0x0050
#define CDROMDISK_DEVICESTATUS   0x0060
#define CDROMDISK_GETDRIVER      0x0061
#define CDROMDISK_GETSECTORSIZE  0x0063
#define CDROMDISK_GETHEADLOC     0x0070
#define CDROMDISK_READLONG       0x0072
#define CDROMDISK_GETVOLUMESIZE  0x0078
#define CDROMDISK_GETUPC         0x0079

#define CDROMAUDIO_SETCHANNELCTRL 0x0040
#define CDROMAUDIO_PLAYAUDIO      0x0050
#define CDROMAUDIO_STOPAUDIO      0x0051
#define CDROMAUDIO_RESUMEAUDIO    0x0052
#define CDROMAUDIO_GETCHANNEL     0x0060
#define CDROMAUDIO_GETAUDIODISK   0x0061
#define CDROMAUDIO_GETAUDIOTRACK  0x0062
#define CDROMAUDIO_GETSUBCHANNELQ 0x0063
#define CDROMAUDIO_GETAUDIOSTATUS 0x0065

#define TOUCH_DEVDEP_SETCALIBCONST     0x0052
#define TOUCH_DEVDEP_READDATA          0x0053
#define TOUCH_DEVDEP_SETDATAMODE       0x0054
#define TOUCH_DEVDEP_SETCLICKLOCK      0x0055
#define TOUCH_DEVDEP_SETTOUCHTHRESHOLD 0x0056
#define TOUCH_DEVDEP_SETEMULXY         0x0057
#define TOUCH_DEVDEP_SETDATAREPORTRATE 0x0058
#define TOUCH_DEVDEP_SETLOWPASSFILTER  0x0059
#define TOUCH_DEVDEP_WRITEMEMLOC       0x005a
#define TOUCH_DEVDEP_GETCALIBCONST     0x0060
#define TOUCH_DEVDEP_GETDATAMODE       0x0061
#define TOUCH_DEVDEP_GETCLICKLOCK      0x0062
#define TOUCH_DEVDEP_GETTOUCHTHRESHOLD 0x0063
#define TOUCH_DEVDEP_GETEMULXY         0x0064
#define TOUCH_DEVDEP_GETDATAREPORTRATE 0x0065
#define TOUCH_DEVDEP_GETLOWPASSFILTER  0x0066
#define TOUCH_DEVDEP_READMEMLOC        0x0067

#define TOUCH_DEVINDEP_SETCOORDSYS       0x0050
#define TOUCH_DEVINDEP_SETSELECTMECH     0x0052
#define TOUCH_DEVINDEP_SETEVENTMASK      0x0053
#define TOUCH_DEVINDEP_SETQUEUESIZE      0x0054
#define TOUCH_DEVINDEP_SETEMULSTATE      0x0055
#define TOUCH_DEVINDEP_GETCOORDSYS       0x0060
#define TOUCH_DEVINDEP_GETSELECTMECH     0x0062
#define TOUCH_DEVINDEP_GETEVENTMASK      0x0063
#define TOUCH_DEVINDEP_GETQUEUESIZE      0x0064
#define TOUCH_DEVINDEP_GETEMULSTATE      0x0065
#define TOUCH_DEVINDEP_GETREADEVENTQUEUE 0x0066

#define RX_QUE_OVERRUN      0x0001
#define RX_HARDWARE_OVERRUN 0x0002
#define PARITY_ERROR        0x0004
#define FRAMING_ERROR       0x0008

#define CHAR_RECEIVED  0x0001
#define LAST_CHAR_SENT 0x0004
#define CTS_CHANGED    0x0008
#define DSR_CHANGED    0x0010
#define DCD_CHANGED    0x0020
#define BREAK_DETECTED 0x0040
#define ERROR_OCCURRED 0x0080
#define RI_DETECTED    0x0100

#define TX_WAITING_FOR_CTS        0x0001
#define TX_WAITING_FOR_DSR        0x0002
#define TX_WAITING_FOR_DCD        0x0004
#define TX_WAITING_FOR_XON        0x0008
#define TX_WAITING_TO_SEND_XON    0x0010
#define TX_WAITING_WHILE_BREAK_ON 0x0020
#define TX_WAITING_TO_SEND_IMM    0x0040
#define RX_WAITING_FOR_DSR        0x0080

#define WRITE_REQUEST_QUEUED   0x0001
#define DATA_IN_TX_QUE         0x0002
#define HARDWARE_TRANSMITTING  0x0004
#define CHAR_READY_TO_SEND_IMM 0x0008
#define WAITING_TO_SEND_XON    0x0010
#define WAITING_TO_SEND_XOFF   0x0020

#define CTS_ON 0x10
#define DSR_ON 0x20
#define RI_ON  0x40
#define DCD_ON 0x80

#define DTR_ON 1
#define RTS_ON 2

#define DTR_OFF 0xFE
#define RTS_OFF 0xFD

#define MODE_DTR_CONTROL     0x01
#define MODE_DTR_HANDSHAKE   0x02
#define MODE_CTS_HANDSHAKE   0x08
#define MODE_DSR_HANDSHAKE   0x10
#define MODE_DCD_HANDSHAKE   0x20
#define MODE_DSR_SENSITIVITY 0x40

#define MODE_AUTO_TRANSMIT   0x01
#define MODE_AUTO_RECEIVE    0x02
#define MODE_ERROR_CHAR      0x04
#define MODE_NULL_STRIPPING  0x08
#define MODE_BREAK_CHAR      0x10
#define MODE_RTS_CONTROL     0x40
#define MODE_RTS_HANDSHAKE   0x80
#define MODE_TRANSMIT_TOGGLE 0xC0

#define MODE_NO_WRITE_TIMEOUT    0x01
#define MODE_READ_TIMEOUT        0x02
#define MODE_WAIT_READ_TIMEOUT   0x04
#define MODE_NOWAIT_READ_TIMEOUT 0x06

#define BUILD_BPB_FROM_MEDIUM  0
#define REPLACE_BPB_FOR_DEVICE 1
#define REPLACE_BPB_FOR_MEDIUM 2

#define GET_BPB_FROM_DEVICE 0
#define GET_BPB_FROM_MEDIUM 1

#define ASCII_MODE  0x00
#define BINARY_MODE 0x80

#define CONVERSION_REQUEST 0x20
#define INTERIM_CHAR       0x80

#define HOTKEY_MAX_COUNT     0
#define HOTKEY_CURRENT_COUNT 1

#define KBD_DATA_RECEIVED 0x0001
#define KBD_DATA_BINARY   0x8000

#define KBD_READ_WAIT   0x0000
#define KBD_READ_NOWAIT 0x8000

#define SHIFT_REPORT_MODE 1

#ifndef INCL_MOU
  #define MOUSE_MOTION               0x0001
  #define MOUSE_MOTION_WITH_BN1_DOWN 0x0002
  #define MOUSE_BN1_DOWN             0x0004
  #define MOUSE_MOTION_WITH_BN2_DOWN 0x0008
  #define MOUSE_BN2_DOWN             0x0010
  #define MOUSE_MOTION_WITH_BN3_DOWN 0x0020
  #define MOUSE_BN3_DOWN             0x0040

  #define MHK_BUTTON1 1
  #define MHK_BUTTON2 2
  #define MHK_BUTTON3 4

  #define MOU_NOWAIT 0
  #define MOU_WAIT   1
#endif

#define MHK_NO_HOTKEY 0

#define MOUSE_QUEUEBUSY        0x0001
#define MOUSE_BLOCKREAD        0x0002
#define MOUSE_FLUSH            0x0004
#define MOUSE_UNSUPPORTED_MODE 0x0008
#define MOUSE_DISABLED         0x0100
#define MOUSE_MICKEYS          0x0200

#define PRINTER_TIMEOUT      0x0001
#define PRINTER_IO_ERROR     0x0008
#define PRINTER_SELECTED     0x0010
#define PRINTER_OUT_OF_PAPER 0x0020
#define PRINTER_ACKNOWLEDGED 0x0040
#define PRINTER_NOT_BUSY     0x0080

#define READ_BANK    0
#define WRITE_BANK   1
#define MODE_TEXT    0
#define MODE_PLANAR  1
#define MODE_LINEAR  2

#define RIGHTSHIFT    0x0001
#define LEFTSHIFT     0x0002
#define CONTROL       0x0004
#define ALT           0x0008
#define SCROLLLOCK_ON 0x0010
#define NUMLOCK_ON    0x0020
#define CAPSLOCK_ON   0x0040
#define INSERT_ON     0x0080
#define LEFTCONTROL   0x0100
#define LEFTALT       0x0200
#define RIGHTCONTROL  0x0400
#define RIGHTALT      0x0800
#define SCROLLLOCK    0x1000
#define NUMLOCK       0x2000
#define CAPSLOCK      0x4000
#define SYSREQ        0x8000

#define DEVTYPE_48TPI   0
#define DEVTYPE_96TPI   1
#define DEVTYPE_35      2
#define DEVTYPE_8SD     3
#define DEVTYPE_8DD     4
#define DEVTYPE_FIXED   5
#define DEVTYPE_TAPE    6
#define DEVTYPE_UNKNOWN 7

#define SCREENDD_GETCURRENTBANK        0x00
#define SCREENDD_SETCURRENTBANK        0x01
#define SCREENDD_SVGA_ID               0x08
#define SCREENDD_SVGA_OEM              0x09
#define SCREENDD_UPDATEMEMORY          0x0A
#define SCREENDD_GETLINEARACCESS       0x0B
#define SCREENDD_GETGLOBALACCESS       0x0C
#define SCREENDD_FREEGLOBALACCESS      0x0D
#define SCREENDD_REGISTER_RING0_CALLER 0x0E
#define SCREENDD_WAIT_ON_RING0_CALLER  0x0F
#define SCREENDD_SVGA_APM              0x10
#define SCREENDD_GET_CS_ALIAS          0x11

#define APM_RESUME   1
#define APM_SUSPEND  2
#define APM_DISABLED 4

#define SCREENDD_CATEGORY 0x80
#define SCREENDD_NAME     "SCREEN$"

#define GETLINEAR_FLAG_MAPPHYSICAL 0x00000010
#define GETLINEAR_FLAG_MAPPROCESS  0x00000020
#define GETLINEAR_FLAG_MAPSHARED   0x00000400
#define GETLINEAR_FLAG_MAPVERIFY   0x40000000
#define GETLINEAR_FLAG_MAPATTACH   0x80000000

#define EGA_BIT    4
#define VGA_BIT    8
#define EGAVGA_BIT (EGA_BIT+VGA_BIT)

typedef struct _DCBINFO {
    USHORT usWriteTimeout;
    USHORT usReadTimeout;
    BYTE   fbCtlHndShake;
    BYTE   fbFlowReplace;
    BYTE   fbTimeout;
    BYTE   bErrorReplacementChar;
    BYTE   bBreakReplacementChar;
    BYTE   bXONChar;
    BYTE   bXOFFChar;
} DCBINFO, *PDCBINFO;

typedef _Packed struct _TRACKLAYOUT {
    BYTE   bCommand;
    USHORT usHead;
    USHORT usCylinder;
    USHORT usFirstSector;
    USHORT cSectors;
    struct {
        USHORT usSectorNumber;
        USHORT usSectorSize;
    } TrackTable[1];
} TRACKLAYOUT, *PTRACKLAYOUT;

typedef _Packed struct _BIOSPARAMETERBLOCK {
    USHORT usBytesPerSector;
    BYTE   bSectorsPerCluster;
    USHORT usReservedSectors;
    BYTE   cFATs;
    USHORT cRootEntries;
    USHORT cSectors;
    BYTE   bMedia;
    USHORT usSectorsPerFAT;
    USHORT usSectorsPerTrack;
    USHORT cHeads;
    ULONG  cHiddenSectors;
    ULONG  cLargeSectors;
    BYTE   abReserved[6];
    USHORT cCylinders;
    BYTE   bDeviceType;
    USHORT fsDeviceAttr;
} BIOSPARAMETERBLOCK, *PBIOSPARAMETERBLOCK;

typedef struct _SCREENGROUP {
    USHORT idScreenGrp;
    USHORT fTerminate;
} SCREENGROUP, *PSCREENGROUP;

typedef struct _FRAME {
    BYTE bCharsPerLine;
    BYTE bLinesPerInch;
} FRAME, *PFRAME;

typedef struct _KBDTYPE {
    USHORT usType;
    USHORT reserved1;
    USHORT reserved2;
} KBDTYPE, *PKBDTYPE;

typedef struct _LINECONTROL {
    BYTE bDataBits;
    BYTE bParity;
    BYTE bStopBits;
    BYTE fTransBreak;
} LINECONTROL, *PLINECONTROL;

typedef struct _MODEMSTATUS {
    BYTE fbModemOn;
    BYTE fbModemOff;
} MODEMSTATUS, *PMODEMSTATUS;

/* NOINC */
#pragma pack( __push, 1 )
/* INC */

typedef _Packed struct _TRACKFORMAT {
    BYTE bCommand;
    USHORT usHead;
    USHORT usCylinder;
    USHORT usReserved;
    USHORT cSectors;
    struct {
        BYTE bCylinder;
        BYTE bHead;
        BYTE idSector;
        BYTE bBytesSector;
    } FormatTable[1];
} TRACKFORMAT, *PTRACKFORMAT;

typedef struct _RXQUEUE {
    USHORT cch;
    USHORT cb;
} RXQUEUE, *PRXQUEUE;

typedef struct _DEVICEPARAMETERBLOCK {
    USHORT reserved1;
    USHORT cCylinders;
    USHORT cHeads;
    USHORT cSectorsPerTrack;
    USHORT reserved2;
    USHORT reserved3;
    USHORT reserved4;
    USHORT reserved5;
} DEVICEPARAMETERBLOCK, *PDEVICEPARAMETERBLOCK;

typedef _Packed struct _PTRDRAWFUNCTION {
    USHORT usReturnCode;
    PFN    pfnDraw;
    PCH    pchDataSeg;
} PTRDRAWFUNCTION, *PPTRDRAWFUNCTION;

typedef struct _PTRDRAWADDRESS {
    USHORT reserved;
    PTRDRAWFUNCTION ptrdfnc;
} PTRDRAWADDRESS, *PPTRDRAWADDRESS;

typedef struct _SHIFTSTATE {
    USHORT fsState;
    BYTE   fNLS;
} SHIFTSTATE, *PSHIFTSTATE;

typedef struct _HOTKEY {
    USHORT fsHotKey;
    UCHAR  uchScancodeMake;
    UCHAR  uchScancodeBreak;
    USHORT idHotKey;
} HOTKEY, *PHOTKEY;

typedef struct _MONITORPOSITION {
    USHORT fPosition;
    USHORT index;
    ULONG  pbInBuf;
    USHORT offOutBuf;
} MONITORPOSITION, *PMONITORPOSITION;

typedef struct _RATEDELAY {
    USHORT usDelay;
    USHORT usRate;
} RATEDELAY, *PRATEDELAY;

typedef struct _CODEPAGEINFO {
    PBYTE  pbTransTable;
    USHORT idCodePage;
    USHORT idTable;
} CODEPAGEINFO, *PCODEPAGEINFO;

typedef struct _CPID {
    USHORT idCodePage;
    USHORT Reserved;
} CPID, *PCPID;

typedef struct _LDTADDRINFO {
    PULONG pulPhysAddr;
    USHORT cb;
} LDTADDRINFO, *PLDTADDRINFO;

typedef struct _PTRDRAWDATA {
    USHORT cb;
    USHORT usConfig;
    USHORT usFlag;
} PTRDRAWDATA, *PPTRDRAWDATA;

typedef struct _GETLINIOCTLDATA {
    ULONG PacketLength;
    ULONG PhysicalAddress;
    ULONG ApertureSize;
    PBYTE LinearAddress;
    ULONG LinearFlags;
} GETLINIOCTLDATA, *PGETLINIOCTLDATA;

typedef struct _BANKINFO {
    ULONG  ulBankLength;
    USHORT usBank;
    USHORT usVideoModeType;
    USHORT usReadWriteMode;
} BANKINFO;

typedef struct _GLOBALIOCTLDATA {
    ULONG ProcessAddress;
    ULONG AddressLength;
    ULONG GlobalAddress;
} GLOBALIOCTLDATA;

typedef struct _OEMSVGAINFO {
    USHORT AdapterType;
    USHORT ChipType;
    ULONG  Memory;
    ULONG  aulPCIRangeSize [6];
    BYTE   abPCIConfiguration [256];
} OEMSVGAINFO;

typedef struct _OEMINFO {
    ULONG  OEMLength;
    USHORT Manufacturer;
    ULONG  ManufacturerData;
    USHORT ManufacturerModel;
} OEMINFO;

typedef struct _GETGLOBALPACKET {
    ULONG   GlobalPktLength;
    GLOBALIOCTLDATA GlobalPktData[1];
} GETGLOBALPACKET;

typedef _Packed struct _OEMHLPDISKINFO {
    USHORT ODI_Reserved;
    USHORT ODI_Flags;
    ULONG  ODI_Cylinders;
    ULONG  ODI_Heads;
    ULONG  ODI_SectorsPerTrack;
    ULONG  ODI_PhysSectors_low;
    ULONG  ODI_PhysSectors_high;
    USHORT ODI_SectorSize;
    ULONG  ODI_Reserved2;
    USHORT ODI_IOPort;
    USHORT ODI_ControlPort;
    UCHAR  ODI_HeadRegisterUN;
    UCHAR  ODI_Reserved3;
    UCHAR  ODI_IRQ;
    UCHAR  ODI_RWMult_BlkCnt;
    UCHAR  ODI_DMAInfo;
    UCHAR  ODI_PIOInfo;
    USHORT ODI_HWFlags;
    USHORT ODI_Reserved4;
    UCHAR  ODI_Revision;
    UCHAR  ODI_Reserved5;
} OEMHLPDISKINFO;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
