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
* Description:  WHEN YOU FIGURE OUT WHAT THIS FILE DOES, PLEASE
*               DESCRIBE IT HERE!
*
****************************************************************************/


#include "guiwind.h"
#include "guixutil.h"
#include "guixhook.h"
#include "guilog.h"


static  bool    (*ProcessMsg)(gui_window *, HWND, WPI_MSG, WPI_PARAM1, WPI_PARAM2, WPI_MRESULT *) = NULL;
static  bool    (*IsMaximized)( gui_window * )          = NULL;
static  bool    (*UpdatedMenu)( void )                  = NULL;
static  bool    (*NewWindow)( HWND )                    = NULL;
static  void    (*MDIMaximize)(bool, gui_window *)      = NULL;
static  bool    (*IsMDIChildWindow)(gui_window *)       = NULL;
static  void    (*SetMDIRestoredSize)(HWND, const WPI_RECT *) = NULL;

/*
 * GUISetMDIProcessMessage -- ?
 */

void GUISetMDIProcessMessage( bool (*func)(gui_window *, HWND, WPI_MSG, WPI_PARAM1,
                              WPI_PARAM2, WPI_MRESULT *) )
{
    GUIlog_entering_void_function ();

    ProcessMsg = func;
}

/*
 * GUIMDIProcessMessage -- This routine returns true if ?
 */

bool GUIMDIProcessMessage( gui_window *wnd, HWND hwnd, WPI_MSG msg,
                           WPI_PARAM1 wparam, WPI_PARAM2 lparam, WPI_MRESULT *ret )
{
    GUIlog_entering_bool_function ();

    if( ProcessMsg != NULL ) {
        return( (*ProcessMsg)( wnd, hwnd, msg, wparam, lparam, ret ) );
    }
    return( false );
}

/*
 * GUIMDIMaximized -- This routine returns true if ?
 */

bool GUIMDIMaximized( gui_window *wnd )
{
    GUIlog_entering_bool_function ();

    if( IsMaximized != NULL ) {
        return( (*IsMaximized)( wnd ) );
    }
    return( _wpi_iszoomed( GUIGetParentFrameHWND( wnd ) ) != 0 );
}

/*
 * GUISetMDIMaximized -- ?
 */

void GUISetMDIMaximized( bool (*func)( gui_window * ) )
{
    GUIlog_entering_void_function ();

    IsMaximized = func;
}

bool GUIMDIUpdatedMenu( void )
{
    GUIlog_entering_bool_function ();

    if( UpdatedMenu != NULL ) {
        return( (*UpdatedMenu)() );
    }
    return( false );
}

/*
 * GUISetMDIUpdatedMenu -- ?
 */

void GUISetMDIUpdatedMenu( bool (*func)( void ) )
{
    GUIlog_entering_void_function ();

    UpdatedMenu = func;
}

/*
 * GUISetIsMDIChildWindow -- ?
 */

void GUISetIsMDIChildWindow( bool (*func)( gui_window *) )
{
    GUIlog_entering_void_function ();

    IsMDIChildWindow = func;
}

/*
 * GUIIsMDIChildWindow -- This routine returns true if ?
 */

bool GUIIsMDIChildWindow( gui_window *wnd )
{
    GUIlog_entering_bool_function ();

    if( IsMDIChildWindow != NULL ) {
        return( (*IsMDIChildWindow)(wnd) );
    }
    return( false );
}

/*
 * GUISetMDINewWindow -- ?
 */

void GUISetMDINewWindow( bool (*func)(HWND) )
{
    GUIlog_entering_void_function ();

    NewWindow = func;
}

/*
 * GUIMDINewWindow -- This routine returns true if ?
 */

bool GUIMDINewWindow( HWND hwnd )
{
    GUIlog_entering_bool_function ();

    if( NewWindow != NULL ) {
        return( (*NewWindow)( hwnd ) );
    } else {
        return( false );
    }
}

/*
 * GUISetMDIMaximize -- ?
 */

void GUISetMDIMaximize( void (*func)(bool, gui_window *) )
{
    GUIlog_entering_void_function ();

    MDIMaximize = func;
}

void GUIMDIMaximize( bool max, gui_window *wnd )
{
    GUIlog_entering_void_function ();

    if( MDIMaximize != NULL ) {
        (*MDIMaximize)( max, wnd );
    }
}

/*
 * GUISetSetMDIRestoredSize -- ?
 */

void GUISetSetMDIRestoredSize( void (*func)(HWND, const WPI_RECT *) )
{
    GUIlog_entering_void_function ();

    SetMDIRestoredSize = func;
}

/*
 * GUISetMDIRestoredSize -- ?
 */

void GUISetMDIRestoredSize( HWND hwnd, const WPI_RECT *wpi_rect )
{
    GUIlog_entering_void_function ();

    if( SetMDIRestoredSize != NULL ) {
        (*SetMDIRestoredSize)( hwnd, wpi_rect );
    }
}
