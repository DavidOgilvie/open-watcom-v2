/*
 *  bse.h       OS/2 Base System include file for 32-bit development.
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

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifdef INCL_BASE
    #define INCL_DOS
    #define INCL_SUB
    #define INCL_DOSERRORS
#endif

#include <bsedos.h>
#include <bsesub.h>
#include <bseerr.h>

#ifdef INCL_DOSDEVIOCTL
    #include <bsedev.h>
#endif

#ifdef INCL_ORDINALS
    #include <bseord.h>
#endif
