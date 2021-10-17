/*
 *  dive.h      OS/2 Direct Interface to Video Extensions include file.
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

#ifndef __DIVE_H__
#define __DIVE_H__

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_DIVE_INSTANCES 64

#define FOURCC ULONG
#define HDIVE ULONG

#define DIVE_SUCCESS 0x00000000
#define DIVE_ERR_INVALID_INSTANCE 0x00001000
#define DIVE_ERR_SOURCE_FORMAT 0x00001001
#define DIVE_ERR_DESTINATION_FORMAT 0x00001002
#define DIVE_ERR_BLITTER_NOT_SETUP 0x00001003
#define DIVE_ERR_INSUFFICIENT_LENGTH 0x00001004
#define DIVE_ERR_TOO_MANY_INSTANCES 0x00001005
#define DIVE_ERR_NO_DIRECT_ACCESS 0x00001006
#define DIVE_ERR_NOT_BANK_SWITCHED 0x00001007
#define DIVE_ERR_INVALID_BANK_NUMBER 0x00001008
#define DIVE_ERR_FB_NOT_ACQUIRED 0x00001009
#define DIVE_ERR_FB_ALREADY_ACQUIRED 0x0000100a
#define DIVE_ERR_ACQUIRE_FAILED 0x0000100b
#define DIVE_ERR_BANK_SWITCH_FAILED 0x0000100c
#define DIVE_ERR_DEACQUIRE_FAILED 0x0000100d
#define DIVE_ERR_INVALID_PALETTE 0x0000100e
#define DIVE_ERR_INVALID_DESTINATION_RECTL 0x0000100f
#define DIVE_ERR_INVALID_BUFFER_NUMBER 0x00001010
#define DIVE_ERR_SSMDD_NOT_INSTALLED 0x00001011
#define DIVE_ERR_BUFFER_ALREADY_ACCESSED 0x00001012
#define DIVE_ERR_BUFFER_NOT_ACCESSED 0x00001013
#define DIVE_ERR_TOO_MANY_BUFFERS 0x00001014
#define DIVE_ERR_ALLOCATION_ERROR 0x00001015
#define DIVE_ERR_INVALID_LINESIZE 0x00001016
#define DIVE_ERR_FATAL_EXCEPTION 0x00001017
#define DIVE_ERR_INVALID_CONVERSION 0x00001018
#define DIVE_ERR_VSD_ERROR 0x00001019
#define DIVE_ERR_COLOR_SUPPORT 0x0000101a
#define DIVE_ERR_OUT_OF_RANGE 0x0000101b
#define DIVE_WARN_NO_SIZE 0x00001100
#define DIVE_BUFFER_SCREEN 0x00000000
#define DIVE_BUFFER_GRAPHICS_PLANE 0x00000001
#define DIVE_BUFFER_ALTERNATE_PLANE 0x00000002
#define DIVE_FULLY_VISIBLE 0xffffffff

#define DIVE_PALETTE_PHYSICAL (PBYTE)0x00000000
#define DIVE_PALETTE_DEFAULT (PBYTE)0xffffffff

typedef struct _DIVE_CAPS {
    ULONG  ulStructLen;
    ULONG  ulPlaneCount;
    BOOL   fScreenDirect;
    BOOL   fBankSwitched;
    ULONG  ulDepth;
    ULONG  ulHorizontalResolution;
    ULONG  ulVerticalResolution;
    ULONG  ulScanLineBytes;
    FOURCC fccColorEncoding;
    ULONG  ulApertureSize;
    ULONG  ulInputFormats;
    ULONG  ulOutputFormats;
    ULONG  ulFormatLength;
    PVOID  pFormatData;
} DIVE_CAPS, *PDIVE_CAPS;

typedef struct _SETUP_BLITTER {
    ULONG  ulStructLen;
    ULONG  fInvert;
    FOURCC fccSrcColorFormat;
    ULONG  ulSrcWidth;
    ULONG  ulSrcHeight;
    ULONG  ulSrcPosX;
    ULONG  ulSrcPosY;
    ULONG  ulDitherType;
    FOURCC fccDstColorFormat;
    ULONG  ulDstWidth;
    ULONG  ulDstHeight;
    LONG   lDstPosX;
    LONG   lDstPosY;
    LONG   lScreenPosX;
    LONG   lScreenPosY;
    ULONG  ulNumDstRects;
    PRECTL pVisDstRects;
} SETUP_BLITTER, *PSETUP_BLITTER;

ULONG APIENTRY DiveAcquireFrameBuffer(HDIVE,PRECTL);
ULONG APIENTRY DiveAllocImageBuffer(HDIVE,PULONG,FOURCC,ULONG,ULONG,ULONG,PBYTE);
ULONG APIENTRY DiveBeginImageBufferAccess(HDIVE,ULONG,PBYTE *,PULONG,PULONG);
ULONG APIENTRY DiveBlitImage(HDIVE,ULONG,ULONG);
ULONG APIENTRY DiveCalcFrameBufferAddress(HDIVE,PRECTL,PBYTE *,PULONG,PULONG);
ULONG APIENTRY DiveClose(HDIVE);
ULONG APIENTRY DiveDeacquireFrameBuffer(HDIVE);
ULONG APIENTRY DiveEndImageBufferAccess(HDIVE,ULONG);
ULONG APIENTRY DiveFreeImageBuffer(HDIVE,ULONG);
ULONG APIENTRY DiveOpen(HDIVE *,BOOL,PVOID);
ULONG APIENTRY DiveQueryCaps(PDIVE_CAPS,ULONG);
ULONG APIENTRY DiveSetDestinationPalette(HDIVE,ULONG,ULONG,PBYTE);
ULONG APIENTRY DiveSetSourcePalette(HDIVE,ULONG,ULONG,PBYTE);
ULONG APIENTRY DiveSetupBlitter(HDIVE,PSETUP_BLITTER);
ULONG APIENTRY DiveSwitchBank(HDIVE,ULONG);

#ifdef INCL_MM_OS2

#define DIVE_TBM_NONE 0
#define DIVE_TBM_EXCLUDE_SOURCE_VALUE 1
#define DIVE_TBM_EXCLUDE_SOURCE_RGB_RANGE 2
#define DIVE_TBM_INCLUDE_SOURCE_RGB_RANGE 3
#define DIVE_TBM_EXCLUDE_SOURCE_YUV_RANGE 4
#define DIVE_TBM_INCLUDE_SOURCE_YUV_RANGE 5

ULONG APIENTRY DiveBlitImageLines(HDIVE,ULONG,ULONG,PBYTE);
ULONG APIENTRY DiveSetTransparentBlitMode(HDIVE,ULONG,ULONG,ULONG);

#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
