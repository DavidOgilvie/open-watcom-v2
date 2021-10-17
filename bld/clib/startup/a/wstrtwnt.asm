;*****************************************************************************
;*
;*                            Open Watcom Project
;*
;* Copyright (c) 2002-2021 The Open Watcom Contributors. All Rights Reserved.
;*    Portions Copyright (c) 1983-2002 Sybase, Inc. All Rights Reserved.
;*
;*  ========================================================================
;*
;*    This file contains Original Code and/or Modifications of Original
;*    Code as defined in and that are subject to the Sybase Open Watcom
;*    Public License version 1.0 (the 'License'). You may not use this file
;*    except in compliance with the License. BY USING THIS FILE YOU AGREE TO
;*    ALL TERMS AND CONDITIONS OF THE LICENSE. A copy of the License is
;*    provided with the Original Code and Modifications, and is also
;*    available at www.sybase.com/developer/opensource.
;*
;*    The Original Code and all software distributed under the License are
;*    distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
;*    EXPRESS OR IMPLIED, AND SYBASE AND ALL CONTRIBUTORS HEREBY DISCLAIM
;*    ALL SUCH WARRANTIES, INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF
;*    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR
;*    NON-INFRINGEMENT. Please see the License for the specific language
;*    governing rights and limitations under the License.
;*
;*  ========================================================================
;*
;* Description:  Win32 windowed startup code.
;*
;*****************************************************************************


;       This must be assembled using one of the following commands:
;               wasm cstrtwwt -bt=NT -ms -3r
;               wasm cstrtwwt -bt=NT -ms -3s
;
        name    cstrtwwt
.386p
        assume  nothing

        extrn   __WinMain       : near
        extrn   ___begtext      : near

_TEXT   segment use32 word public 'CODE'

        public  _wstart_
        public  _wstart2_
        public  WinMainCRTStartup

        assume  cs:_TEXT

_wstart_ proc near
_wstart2_ proc near
WinMainCRTStartup proc near
        jmp     __WinMain
WinMainCRTStartup endp
_wstart2_ endp
_wstart_ endp

        dd      ___begtext      ; reference module with segment definitions

;
; copyright message
;
include msgcpyrt.inc

_TEXT   ends

        end     _wstart_
