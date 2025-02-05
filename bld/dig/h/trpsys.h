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
* Description:  TRAP file loader global function/variable OS specific declaration
*
****************************************************************************/


/*
 * Trap interface function/pointer macros
 */
#define TRAP_EXTFUNC(n)         trap_ ## n
#define TRAP_EXTFUNC_PTR(n)     ptr_ ## n
#define TRAP_EXTFUNC_TYPE(n)    type_ ## n
#define TRAPENTRY_FUNC(n)       TRAPENTRY Trap ## n

#if defined( __OS2__ )

extern bool     IsTrapFilePumpingMessageQueue( void );

#elif defined( __DOS__ )
  #if !defined( _M_I86 )

extern char     DPMICheck;
extern void     SaveOrigVectors( void );
extern void     RestoreOrigVectors( void );

  #endif
#elif defined( __WINDOWS__ )

extern bool     TrapHardModeRequired;

#endif

#define pick(n,r,p,ar,ap)   extern ar TRAP_EXTFUNC( n ) ## ap;
#include "_trpextf.h"
#undef pick

#define pick(n,r,p,ar,ap)   extern r TRAPENTRY_FUNC( n ) ## p;
#include "_trpextf.h"
#undef pick
