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
* Description:  WHEN YOU FIGURE OUT WHAT THIS FILE DOES, PLEASE
*               DESCRIBE IT HERE!
*
****************************************************************************/


#include "guiwind.h"
#include "guixutil.h"
#include "guihook.h"
#include "guilog.h"


/*
 * GUISetWindowText - set the title text of a window
 */

bool GUIAPI GUISetWindowText( gui_window *wnd, const char *data )
{
    GUIlog_entering_bool_function ();

#if defined( __OS2__ ) && defined( _M_I86 )
     _wpi_setwindowtext( GUIGetParentFrameHWND( wnd ), (char *)data );
#else  // of #if defined( __OS2__ ) && defined( _M_I86 )
     _wpi_setwindowtext( GUIGetParentFrameHWND( wnd ), data );
#endif  // of #else for #if defined( __OS2__ ) && defined( _M_I86 )
     GUIChangeMDITitle( wnd );
     return( true );
}

/*
 * GUIGetWindowText -- get the window text
 */

size_t GUIAPI GUIGetWindowText( gui_window *wnd, char *buff, size_t buff_len )
{
    GUIlog_entering_size_t_function ();

    return( _wpi_getwindowtext( GUIGetParentFrameHWND( wnd ), buff, buff_len ) );
}

/*
 * GUIGetWindowTextLength -- ?
 */

size_t GUIAPI GUIGetWindowTextLength( gui_window *wnd )
{
    GUIlog_entering_size_t_function ();

    return( _wpi_getwindowtextlength( GUIGetParentFrameHWND( wnd ) ) );
}
