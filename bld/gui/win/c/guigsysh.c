/****************************************************************************
*
*                            Open Watcom Project
*
* Copyright (c) 2018-2021 The Open Watcom Contributors. All Rights Reserved.
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
* Description:  Get system handle of the Window
*
****************************************************************************/


#include "guiwind.h"
#include "guixutil.h"
#include "guigsysh.h"
#include "guixwind.h"
#include "guilog.h"


/*
 * GUIGetSysHandle -- This routine returns a handle to ?
 */

HWND GUIGetSysHandle( gui_window *wnd )
{
    GUIlog_entering_HWND_function ();

    return( GUIGetTopParentHWND( wnd->hwnd ) );
}

#if 0
/*
 * GUIGetHInst -- ?
 */

WPI_INST GUIGetHInst( void )
{
    GUIlog_entering_WPI_INST_function ();

    return( GUIMainHInst );
}
#endif  // of #if 0

#ifdef __OS2__
/*
 * GUIGetHAB -- ?
 */

HAB GUIGetHAB( void )
{
    GUIlog_entering_HAB_function ();

    return( GUIMainHInst.hab );
}
#endif  // of #ifdef __OS2__
