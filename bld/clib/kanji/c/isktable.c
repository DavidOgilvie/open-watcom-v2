/****************************************************************************
*
*                            Open Watcom Project
*
* Copyright (c) 2002-2021 The Open Watcom Contributors. All Rights Reserved.
*    Portions Copyright (c) 1983-2002 Sybase, Inc. All Rights Reserved.
*
*  ========================================================================
*
*    This file contains Original Code and/or Modifications of Original
*    Code as defined in and that are subject to the Sybase Open Watcom
*    Public License version 1.0 (the 'License'). You may not use this file
*    except in compliance with the License. BY USING THIS FILE YOU AGREE TO
*    ALL TERMS AND CONDITIONS OF THE LICENSE. A copy of the License is
*    provided with the Original Code and Modifications, and is also
*    available at www.sybase.com/developer/opensource.
*
*    The Original Code and all software distributed under the License are
*    distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
*    EXPRESS OR IMPLIED, AND SYBASE AND ALL CONTRIBUTORS HEREBY DISCLAIM
*    ALL SUCH WARRANTIES, INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF
*    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR
*    NON-INFRINGEMENT. Please see the License for the specific language
*    governing rights and limitations under the License.
*
*  ========================================================================
*
* Description:  Kanji character detction table.
*
****************************************************************************/


#include "variety.h"
#include <jctype.h>

_WCRTDATA const char _HUGEDATA  _IsKTable[257] = {

#define ___0__ 0
#define ___K__ _K
#define ___KP_ _KP
#define ___J1_ _J1
#define ___J2_ _J2

/* -1,EOF */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 00,NUL */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 01,SOH */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 02,STX */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 03,ETX */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 04,EOT */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 05,ENQ */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 06,NAK */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 07,BEL */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 08,BS  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 09,TAB */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 0A,LF  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 0B,VT  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 0C,FF  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 0D,CR  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 0E,SI  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 0F,SO  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 10,    */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 11,    */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 12,    */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 13,    */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 14,    */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 15,    */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 16,    */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 17,    */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 18,    */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 19,    */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 1A,    */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 1B,    */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 1C,    */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 1D,    */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 1E,    */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 1F,    */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 20,    */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 21, !  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 22, "  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 23, #  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 24, $  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 25, %  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 26, &  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 27, '  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 28, (  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 29, )  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 2A, *  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 2B, +  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 2C, ,  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 2D, -  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 2E, .  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 2F, /  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 30, 0  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 31, 1  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 32, 2  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 33, 3  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 34, 4  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 35, 5  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 36, 6  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 37, 7  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 38, 8  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 39, 9  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 3A, :  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 3B, ;  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 3C, <  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 3D, =  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 3E, >  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 3F, ?  */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 40, @  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 41, A  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 42, B  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 43, C  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 44, D  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 45, E  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 46, F  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 47, G  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 48, H  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 49, I  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 4A, J  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 4B, K  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 4C, L  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 4D, M  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 4E, N  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 4F, O  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 50, P  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 51, Q  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 52, R  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 53, S  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 54, T  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 55, U  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 56, V  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 57, W  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 58, X  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 59, Y  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 5A, Z  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 5B, [  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 5C, \  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 5D, ]  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 5E, ^  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 5F, _  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 60, `  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 61, a  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 62, b  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 63, c  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 64, d  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 65, e  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 66, f  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 67, g  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 68, h  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 69, i  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 6A, j  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 6B, k  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 6C, l  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 6D, m  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 6E, n  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 6F, o  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 70, p  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 71, q  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 72, r  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 73, s  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 74, t  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 75, u  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 76, v  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 77, w  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 78, x  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 79, y  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 7A, z  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 7B, {  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 7C, |  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 7D, }  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 7E, ~  */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 7F,DEL */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* 80,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* 81,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 82,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 83,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 84,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 85,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 86,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 87,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 88,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 89,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 8A,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 8B,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 8C,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 8D,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 8E,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 8F,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 90,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 91,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 92,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 93,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 94,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 95,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 96,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 97,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 98,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 99,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 9A,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 9B,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 9C,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 9D,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 9E,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* 9F,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* A0,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___0__,
/* A1,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___KP_|___0__,
/* A2,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___KP_|___0__,
/* A3,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___KP_|___0__,
/* A4,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___KP_|___0__,
/* A5,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___KP_|___0__,
/* A6,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* A7,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* A8,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* A9,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* AA,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* AB,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* AC,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* AD,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* AE,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* AF,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* B0,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* B1,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* B2,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* B3,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* B4,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* B5,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* B6,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* B7,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* B8,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* B9,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* BA,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* BB,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* BC,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* BD,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* BE,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* BF,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* C0,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* C1,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* C2,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* C3,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* C4,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* C5,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* C6,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* C7,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* C8,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* C9,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* CA,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* CB,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* CC,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* CD,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* CE,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* CF,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* D0,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* D1,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* D2,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* D3,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* D4,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* D5,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* D6,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* D7,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* D8,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* D9,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* DA,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* DB,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* DC,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* DD,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* DE,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* DF,    */  ___0__|___0__|___0__|___0__|___J2_|___0__|___0__|___K__,
/* E0,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* E1,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* E2,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* E3,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* E4,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* E5,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* E6,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* E7,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* E8,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* E9,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* EA,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* EB,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* EC,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* ED,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* EE,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* EF,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* F0,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* F1,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* F2,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* F3,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* F4,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* F5,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* F6,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* F7,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* F8,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* F9,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* FA,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* FB,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* FC,    */  ___0__|___0__|___0__|___0__|___J2_|___J1_|___0__|___0__,
/* FD,    */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* FE,    */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__,
/* FF,    */  ___0__|___0__|___0__|___0__|___0__|___0__|___0__|___0__  };
