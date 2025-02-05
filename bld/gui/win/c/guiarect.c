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
#include "guiscale.h"
#include "guilog.h"

/*
 * GUIGetAbsRect --
 */

void GUIAPI GUIGetAbsRect( gui_window *wnd, gui_rect *rect )
{
    HWND        hwnd;
    WPI_RECT    wpi_rect;
    WPI_RECTDIM left, top, right, bottom;
    guix_rect   scr_rect;

    GUIlog_entering_void_function ();

    hwnd = GUIGetParentFrameHWND( wnd );
    _wpi_getwindowrect( hwnd, &wpi_rect );
    _wpi_getwrectvalues( wpi_rect, &left, &top, &right, &bottom );
    scr_rect.s_width = _wpi_getwidthrect( wpi_rect );
    scr_rect.s_height = _wpi_getheightrect( wpi_rect );
    scr_rect.s_x = left;
    scr_rect.s_y = _wpi_cvtc_y_plus1( HWND_DESKTOP, top );
    GUIScreenToScaleRect( &scr_rect, rect );
}
