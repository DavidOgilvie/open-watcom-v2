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
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "guicolor.h"
#include "guimenus.h"
#include "guiscale.h"
#include "guixutil.h"
#include "guiscrol.h"
#include "guixwind.h"
#include "guiwnclr.h"
#include "guimapky.h"
#include "guicontr.h"
#include "guihook.h"
#include "guixhook.h"
#include "guipaint.h"
#include "guizlist.h"
#include "guirdlg.h"
#include "guilog.h"


#define ERROR_STYLE MB_OK | MB_ICONEXCLAMATION

/*
 * MaxChild -- ?
 */

static void MaxChild( gui_window *wnd, void *param )
{
    GUIlog_entering_void_function ();

    param = param;
    if( _wpi_iszoomed( wnd->hwnd_frame ) ) {
        GUISetRedraw( wnd, false );
        GUIRestoreWindow( wnd );
        GUIMaximizeWindow( wnd );
        GUISetRedraw( wnd, true );
        GUIShowWindowNA( wnd );
    }
}

/*
 * GUIMaximizeZoomedChildren -- ?
 */

void GUIMaximizeZoomedChildren( gui_window *wnd )
{
    GUIlog_entering_void_function ();

    GUIEnumChildWindows( wnd, &MaxChild, NULL );
}

/*
 * GUIIsOpen -- This routine returns true if the given window is open
 */

bool GUIIsOpen( gui_window *wnd )
{
    GUIlog_entering_bool_function ();

    if( _wpi_iswindow( GUIMainHInst, wnd->hwnd ) ) {
        return( true );
    }
    return( false );
}

/*
 * GUIIsParentADialog -- This routine returns true if ?
 */

bool GUIIsParentADialog( gui_window *wnd )
{
    GUIlog_entering_bool_function ();

    while( (wnd = GUIGetParentWindow( wnd )) != NULL ) {
        if( GUI_IS_DIALOG( wnd ) ) {
            return( true );
        }
    }
    return( false );
}

/*
 * GUIIsRectInUpdateRect -- This routine returns true if ?
 */

bool GUIIsRectInUpdateRect( gui_window *wnd, WPI_RECT *wpi_rect )
{
    WPI_RECT    update_wpi_rect;
    WPI_RECT    intersect_wpi_rect;

    GUIlog_entering_bool_function ();

    if( !wnd || !wnd->ps || !wpi_rect ) {
        return( true );
    }

#ifdef __OS2_PM__
    update_wpi_rect = *(wnd->ps);
#else  // of #ifdef __OS2_PM__
    _wpi_getpaintrect( wnd->ps, &update_wpi_rect );
#endif  // of #else for #ifdef __OS2_PM__
    _wpi_intersectrect( GUIMainHInst, &intersect_wpi_rect, &update_wpi_rect, wpi_rect );

    if( _wpi_isrectempty( GUIMainHInst, &intersect_wpi_rect ) ) {
        return( false );
    }

    return( true );
}

/*
 * GUICalcLocation -- ?
 */

void GUICalcLocation( const gui_rect *rect, guix_coord *scr_pos, guix_coord *scr_size, HWND parent )
{
    WPI_RECT    wpi_rect;
    WPI_RECTDIM left, top, right, bottom;

    GUIlog_entering_void_function ();

    if( parent == NULLHANDLE ) {
        parent = HWND_DESKTOP;
    }
    scr_size->x = GUIScaleToScreenH( rect->width );
    scr_size->y = GUIScaleToScreenV( rect->height );
    if( parent == HWND_DESKTOP ) {
        scr_pos->x = GUIScaleToScreenX( rect->x );
        scr_pos->y = GUIScaleToScreenY( rect->y );
    } else {
        _wpi_getclientrect( parent, &wpi_rect );
        _wpi_getrectvalues( wpi_rect, &left, &top, &right, &bottom );
        scr_pos->x = GUIScaleToScreenH( rect->x ) + left;
        scr_pos->y = GUIScaleToScreenV( rect->y ) + top;
    }

    scr_pos->y = _wpi_cvtc_y_size_plus1( parent, scr_pos->y, scr_size->y );
}

/*
 * GUISetupStruct -- This routine returns true if it can set up the
 *                   gui_window structure according to the given
 *                   create_info information.
 */

bool GUISetupStruct( gui_window *wnd, gui_create_info *dlg_info, guix_coord *scr_pos,
                        guix_coord *scr_size, HWND parent, HMENU *hmenu )
{
    GUIlog_entering_bool_function ();

    GUICalcLocation( &dlg_info->rect, scr_pos, scr_size, parent );
    if( wnd != NULL ) {
        if( !GUI_IS_DIALOG( wnd ) ) {
            wnd->style = dlg_info->style;
            wnd->scroll_style = dlg_info->scroll_style;
        }
        if( !GUISetColours( wnd, dlg_info->colours.num_items, dlg_info->colours.colour ) ) {
            return( false );
        }
    }

    if( ( ( parent == HWND_DESKTOP ) || (dlg_info->style & GUI_POPUP) ) && ( hmenu != NULL ) ) {
        if( dlg_info->resource_menu != NULL ) {
            *hmenu = _wpi_loadmenu( GUIResHInst, dlg_info->resource_menu );
        } else {
            return( GUICreateMenus( wnd, &dlg_info->menus, hmenu ) );
        }
    }

    return( true );
}

/*
 * GUIError -- display a formatted error message
 */

void GUIError( const char *_str, ... )
{
    char        str[256]= "\0";
    HWND        focus;
    int         ret;
    va_list     arglist;

    va_start (arglist, _str);

    ret = vsprintf (str, _str, arglist);

    focus = _wpi_getfocus();
    if( focus != NULLHANDLE ) {
        _wpi_messagebox( focus, str, NULL, ERROR_STYLE );
    }
    va_end (arglist);
}

/*
 * GUIErrorSA -- display a formatted error message when the GUI is not yet
 *               initialized.  In DOS, this would have been equivalent to
 *               using a printf
 */

void GUIErrorSA( const char *_str, ... )
{
    char        str[256]= "\0";
    HWND        focus= 0L;
    int         ret;
    va_list     arglist;

    va_start (arglist, _str);

    ret = vsprintf (str, _str, arglist);

    _wpi_messagebox( focus, str, NULL, ERROR_STYLE );
    va_end (arglist);
}

/*
 * GUIFindWindowFromHWND -- ?
 */

gui_window *GUIFindWindowFromHWND( HWND hwnd )
{
    gui_window *curr;

    GUIlog_entering_gui_window_function ();

    for( curr = GUIGetFront(); curr != NULL; curr = GUIGetNextWindow( curr ) ) {
        if( ( curr->hwnd == hwnd ) || ( curr->hwnd_frame == hwnd ) ||
            ( curr->root == hwnd ) || ( curr->root_frame == hwnd ) ) {
            return( curr );
        }
    }

    return( NULL );
}

/*
 * GUIIsGUIChild -- This routine returns true if ?
 */

bool GUIIsGUIChild( HWND hwnd )
{
    gui_window  *root;

    GUIlog_entering_bool_function ();

    root = GUIGetRootWindow();
    if( root ) {
        hwnd = GUIGetTopParentHWND( hwnd );
        if( root->root_frame == hwnd ) {
            return( true );
        }
    }

    return( false );
}

/*
 * GUISetRedraw -- This routine returns true if it can set the redraw
 *                 flag for a given window
 */

bool GUIAPI GUISetRedraw( gui_window *wnd, bool redraw )
{
    GUIlog_entering_bool_function ();

    _wpi_setredraw( wnd->hwnd, ( redraw ) ? TRUE : FALSE );
    return( true );
}

/*
 * GUIBringNewToFront -- This routine returns true if it can bring the
 *                       next window in the z-order to the front.  Do not
 *                       bring forward the given window or a decendent
 *                       of that window.
 */

bool GUIBringNewToFront( gui_window *prev )
{
    gui_window *curr;

    GUIlog_entering_bool_function ();

    for( curr = GUIGetFront(); curr != NULL; curr = GUIGetNextWindow( curr ) ) {
        if( ( curr != prev ) && !_wpi_ischild( prev->hwnd, curr->hwnd ) && (curr->flags & DOING_DESTROY) == 0 ) {
            GUIBringToFront( curr );
            return( true );
        }
    }
    return( false );
}

/*
 * GUIXGetRootWindow -- ?
 */

gui_window *GUIXGetRootWindow( void )
{
    gui_window *curr;

    GUIlog_entering_gui_window_function ();

    for( curr = GUIGetFront(); curr != NULL; curr = GUIGetNextWindow( curr ) ) {
        if( curr->flags & IS_ROOT ) {
            return( curr );
        }
    }

    return( NULL );
}

/*
 * GUIFindFirstChild -- ?
 */

gui_window *GUIFindFirstChild( gui_window *parent_wnd )
{
    gui_window *wnd;

    GUIlog_entering_gui_window_function ();

    for( wnd = GUIGetFront(); wnd != NULL; wnd = GUIGetNextWindow( wnd ) ) {
        if( wnd->parent == parent_wnd && (wnd->flags & UTILITY_BIT) == 0 ) {
            return( wnd );
        }
    }

    return( NULL );
}

/*
 * GUIFindFirstPopupWithNoParent -- ?
 */

static gui_window *GUIFindFirstPopupWithNoParent( void )
{
    gui_window *wnd;

    GUIlog_entering_gui_window_function ();

    for( wnd = GUIGetFront(); wnd != NULL; wnd = GUIGetNextWindow( wnd ) ) {
        if( (wnd->style & GUI_POPUP) && ( wnd->parent == NULL ) ) {
            return( wnd );
        }
    }

    return( NULL );
}

/*
 * GUIMarkChildrenWithFlag -- ?
 */

static void GUIMarkChildrenWithFlag( gui_window *parent_wnd, gui_flags flag )
{
    gui_window *wnd;

    GUIlog_entering_void_function ();

    for( wnd = GUIGetFront(); wnd != NULL; wnd = GUIGetNextWindow( wnd ) ) {
        if( wnd->parent == parent_wnd ) {
            wnd->flags |= flag;
        }
    }
}

/*
 * GUIDestroyAllChildren -- ?
 */

void GUIDestroyAllChildren( gui_window *parent_wnd )
{
    gui_window  *wnd;

    GUIlog_entering_void_function ();

    GUIMarkChildrenWithFlag( parent_wnd, DOING_DESTROY );
    while( (wnd = GUIFindFirstChild( parent_wnd )) != NULL ) {
        wnd->flags |= UTILITY_BIT;
        GUIDestroyWnd( wnd );
    }
}

/*
 * GUIDestroyAllPopupsWithNoParent -- ?
 */

void GUIDestroyAllPopupsWithNoParent( void )
{
    gui_window  *wnd;

    GUIlog_entering_void_function ();

    while( (wnd = GUIFindFirstPopupWithNoParent()) != NULL ) {
        GUIDestroyWnd( wnd );
    }
}


/*
 * GUIFreeWindowMemory -- free the memory of the given window
 */

void GUIFreeWindowMemory( gui_window *wnd, bool from_parent, bool dialog )
{
    gui_window  *root;
    HWND        capture;

    GUIlog_entering_void_function ();

    from_parent = from_parent;
    if( ( wnd->hwnd != NULLHANDLE ) && ( GUICurrWnd == wnd ) ) {
        capture = _wpi_getcapture();
        if( capture == wnd->hwnd ) {
            _wpi_releasecapture();
        }
    }
    if( wnd->font != NULL ) {
        _wpi_deletefont( wnd->font );
        wnd->font = NULLHANDLE;
    }
    if( wnd->icon != NULLHANDLE ) {
        _wpi_destroyicon( wnd->icon );
    }
    GUIFreeColours( wnd );
    GUIFreeBKBrush( wnd );
    GUIControlDeleteAll( wnd );
    GUICloseToolBar( wnd );
    GUIFreeHint( wnd );
    _wpi_setwindowlongptr( wnd->hwnd, GUI_EXTRA_WORD * EXTRA_SIZE, 0 );
    if( wnd->root != NULLHANDLE ) {
        _wpi_setwindowlongptr( wnd->root, GUI_EXTRA_WORD * EXTRA_SIZE, 0 );
    }
    if( !dialog ) {
        GUIMDIDelete( wnd );
        if( GUICurrWnd == wnd ) {
            GUICurrWnd = NULL;
        }
        GUIFreePopupList( wnd );
    }
    GUIDeleteFromList( wnd );
    /* If the window being deleted was the current window, choose a new
     * window to bring to front.  Don't do this if the window that's being
     * destroyed is being destroyed because it's parent is being destroyed
     * (ie never got WM_CLOSE so DOING_CLOSE isn't set).
     */
    if( !dialog && (wnd->flags & DOING_CLOSE) && ( GUICurrWnd == NULL ) && !GUIIsParentADialog( wnd ) ) {
        // if the root window has received a WM_DESTROY then just run away
        root = GUIGetRootWindow();
        if( root && (root->flags & DOING_DESTROY) == 0 ) {
            GUIBringNewToFront( wnd );
        }
    }
    if( wnd->hdc != NULLHANDLE ) {
        _wpi_releasepres( wnd->hwnd, wnd->hdc );
        wnd->hdc = NULLHANDLE;
    }
#ifdef __OS2_PM__
    GUIFreeWndPaintHandles( wnd, true );
    if( wnd->root_pinfo.normal_pres != NULLHANDLE ) {
        _wpi_deleteos2normpres( wnd->root_pinfo.normal_pres );
        wnd->root_pinfo.normal_pres = NULLHANDLE;
    }
    if( wnd->hwnd_pinfo.normal_pres != NULLHANDLE ) {
        _wpi_deleteos2normpres( wnd->hwnd_pinfo.normal_pres );
        wnd->hwnd_pinfo.normal_pres = NULLHANDLE;
    }
#endif  // of #ifdef __OS2_PM__
    GUIMemFree( wnd );
}

/*
 * GUIScrollOn -- This routine returns true if ?
 */

bool GUIScrollOn( gui_window *wnd, int bar )
{
    GUIlog_entering_bool_function ();

    if( ( bar == SB_VERT ) && GUI_VSCROLL_ON( wnd ) ) {
        return( true );
    }
    if( ( bar == SB_HORZ ) && GUI_HSCROLL_ON( wnd ) ) {
        return( true );
    }
    return( false );
}

/*
 * GUISetRowCol -- ?
 */

void GUISetRowCol( gui_window *wnd, const guix_coord *scr_size )
{
    guix_ord    size_x;
    guix_ord    size_y;

    GUIlog_entering_void_function ();

    if( scr_size == NULL ) {
        size_x = _wpi_getwidthrect( wnd->hwnd_client_rect );
        size_y = _wpi_getheightrect( wnd->hwnd_client_rect );
    } else {
        size_x = scr_size->x;
        size_y = scr_size->y;
    }
    wnd->num_cols = GUIToTextX( size_x, wnd );
    wnd->num_rows = GUIToTextY( size_y, wnd );
}

/*
 * GUIInvalidateResize -- invalidate the bottom portion of the window that
 *                        may now contain a line of text
 */

void GUIInvalidateResize( gui_window *wnd )
{
    WPI_RECT    wpi_rect;
    WPI_RECTDIM left, top, right, bottom;

    GUIlog_entering_void_function ();

    if( (wnd->flags & NEEDS_RESIZE_REDRAW) && ( wnd->old_rows != wnd->num_rows ) ) {
        _wpi_getrectvalues( wnd->hwnd_client_rect, &left, &top, &right, &bottom );
        GUIGetMetrics( wnd );
        if( wnd->old_rows < wnd->num_rows ) {
            /* window grew */
            top = wnd->old_rows * AVGYCHAR( GUItm );
        } else {
            /* window shrunk */
            top = wnd->num_rows * AVGYCHAR( GUItm );
        }
        _wpi_setrectvalues( &wpi_rect, left, top, right, bottom );
        _wpi_invalidaterect( wnd->hwnd, &wpi_rect, TRUE );
        wnd->flags &= ~NEEDS_RESIZE_REDRAW;
    }
    wnd->old_rows = wnd->num_rows;
}

/*
 * GUISendMessage -- ?
 */

WPI_MRESULT GUISendMessage( HWND hwnd, WPI_MSG msg, WPI_PARAM1 wparam, WPI_PARAM2 lparam )
{
    GUIlog_entering_WPI_MRESULT_function ();

    if( hwnd != NULLHANDLE ) {
        return( _wpi_sendmessage( hwnd, msg, wparam, lparam ) );
    } else {
        return( 0L );
    }
}

/*
 * GUISendDlgItemMessage -- ?
 */

WPI_MRESULT GUISendDlgItemMessage( HWND parent, gui_ctl_id id, WPI_MSG msg, WPI_PARAM1 wparam, WPI_PARAM2 lparam )
{
    HWND hwnd;

    GUIlog_entering_WPI_MRESULT_function ();

    hwnd = _wpi_getdlgitem( parent, id );
    if( hwnd != NULLHANDLE ) {
        return( _wpi_sendmessage( hwnd, msg, wparam, lparam ) );
    } else {
        return( 0L );
    }
}

/*
 * GUIMakeRelative -- ?
 */

void GUIMakeRelative( gui_window *wnd, WPI_POINT *wpi_point, gui_point *point )
{
    WPI_RECT    wpi_rect;
    WPI_RECTDIM left, top, right, bottom;
    gui_ord     scr_x;
    gui_ord     scr_y;

    GUIlog_entering_void_function ();

    wpi_rect = wnd->hwnd_client_rect;
    _wpi_mapwindowpoints( wnd->hwnd, HWND_DESKTOP, (WPI_LPPOINT)&wpi_rect, 2 );
    _wpi_getrectvalues( wpi_rect, &left, &top, &right, &bottom );
    scr_x = wpi_point->x - left;
    scr_y = wpi_point->y - top;
    if( GUI_DO_HSCROLL( wnd ) || GUI_DO_VSCROLL( wnd ) ) {
        if( GUI_DO_HSCROLL( wnd ) ) {
            scr_x += GUIGetScrollPos( wnd, SB_HORZ );
        }
        if( GUI_DO_VSCROLL( wnd ) ) {
            scr_y += GUIGetScrollPos( wnd, SB_VERT );
        }
    }
    point->x = GUIScreenToScaleH( scr_x );
    point->y = GUIScreenToScaleV( scr_y );
}

/*
 * GUIGetScrollHWND -- This routine returns the handle to a window if ?
 */

HWND GUIGetScrollHWND( gui_window *wnd )
{
    GUIlog_entering_HWND_function ();

    if( wnd == NULL ) {
        return( NULLHANDLE );
    }
    if( wnd->root != NULLHANDLE ) {
        return( wnd->root );
    }
    return( wnd->hwnd );
}

/*
 * ChangeScrollPos -- This routine returns true if ?
 */

static bool ChangeScrollPos( gui_window *wnd, int bar, guix_ord new )
{
    GUIlog_entering_bool_function ();

    if( bar == SB_HORZ ) {
        if( wnd->hpos == new )
            return( false );
        wnd->hpos = new;
    } else {
        if( wnd->vpos == new )
            return( false );
        wnd->vpos = new;
    }
    return( true );
}

/*
 * GUISetScrollPos -- ?
 */

void GUISetScrollPos( gui_window *wnd, int bar, guix_ord new, bool redraw )
{
    GUIlog_entering_void_function ();

    if( ChangeScrollPos( wnd, bar, new ) ) {
        _wpi_setscrollpos( GUIGetParentFrameHWND( wnd ), bar, new, ( redraw ) ? TRUE : FALSE );
    }
}

/*
 * GUIGetScrollPos -- ?
 */

guix_ord GUIGetScrollPos( gui_window *wnd, int bar )
{
    GUIlog_entering_guix_ord_function ();

    if( bar == SB_HORZ ) {
        return( wnd->hpos );
    } else {
        return( wnd->vpos );
    }
}

/*
 * ChangeScrollRange -- This routine returns true if ?
 */

static bool ChangeScrollRange( gui_window *wnd, int bar, guix_ord new )
{
    GUIlog_entering_bool_function ();

    if( bar == SB_HORZ ) {
        if( wnd->hrange == new )
            return( false );
        wnd->hpos = new;
    } else {
        if( wnd->vrange == new )
            return( false );
        wnd->vpos = new;
    }
    return( true );
}

/*
 * GUISetScrollRange -- ?
 */

void GUISetScrollRange( gui_window *wnd, int bar, int min, int max, bool redraw )
{
    GUIlog_entering_void_function ();

    if( ChangeScrollRange( wnd, bar, max - min ) ) {
        _wpi_setscrollrange( GUIGetParentFrameHWND( wnd ), bar, min, max, ( redraw ) ? TRUE : FALSE );
        if( bar == SB_HORZ ) {
            GUIRedrawScroll( wnd, SB_HORZ, redraw );
        } else {
            GUIRedrawScroll( wnd, SB_VERT, redraw );
        }
    }
}

/*
 * GUIGetScrollRange -- ?
 */

guix_ord GUIGetScrollRange( gui_window *wnd, int bar )
{
    GUIlog_entering_guix_ord_function ();

    if( bar == SB_HORZ ) {
        return( wnd->hrange );
    } else {
        return( wnd->vrange );
    }
}

/*
 * GUISetRangePos -- ?
 */

void GUISetRangePos( gui_window *wnd, int bar )
{
    guix_ord    range;
    guix_ord    pos;

    GUIlog_entering_void_function ();

    range = GUIGetScrollRange( wnd, bar );
    pos = GUIGetScrollPos( wnd, bar );
    _wpi_setscrollrange( GUIGetParentFrameHWND( wnd ), bar, 0, range, FALSE );
    _wpi_setscrollpos( GUIGetParentFrameHWND( wnd ), bar, pos, TRUE );
}

/*
 * GUIRedrawScroll -- ?
 */

void GUIRedrawScroll( gui_window *wnd, int bar, bool redraw_now )
{
    WPI_RECT    wpi_rect;
    WPI_RECT    client_wpi_rect;
    HWND        hwnd;
    WPI_RECTDIM left, top, right, bottom;
    WPI_RECTDIM clleft, cltop, clright, clbottom;

    GUIlog_entering_void_function ();

    hwnd = GUIGetParentFrameHWND( wnd );
    _wpi_getwindowrect( hwnd, &wpi_rect );
    _wpi_getclientrect( hwnd, &client_wpi_rect );
    _wpi_mapwindowpoints( HWND_DESKTOP, hwnd, (WPI_LPPOINT)&wpi_rect, 2 );
    _wpi_getrectvalues( wpi_rect, &left, &top, &right, &bottom );
    _wpi_getrectvalues( client_wpi_rect, &clleft, &cltop, &clright, &clbottom );
    if( bar == SB_HORZ ) {
        top = clbottom;
    } else {
        left = clright;
    }
    _wpi_setrectvalues( &wpi_rect, left, top, right, bottom );
    GUIInvalidatePaintHandles( wnd );
    _wpi_invalidaterect( hwnd, &wpi_rect, TRUE );
    if( redraw_now && (wnd->flags & NEEDS_RESIZE_REDRAW) == 0 ) {
        _wpi_updatewindow( hwnd );
    }
}

/*
 * GUIGetParentHWND -- This routine returns a handle to a window if ?
 */

HWND GUIGetParentHWND( gui_window *wnd )
{
    GUIlog_entering_HWND_function ();

    if( wnd == NULL ) {
        return( NULLHANDLE );
    }
    if( wnd->root != NULLHANDLE ) {
        return( wnd->root );
    }
    return( wnd->hwnd );
}

/*
 * GUIGetParentFrameHWND -- This routine returns a handle to a window if ?
 */

HWND GUIGetParentFrameHWND( gui_window *wnd )
{
    GUIlog_entering_HWND_function ();

    if( wnd == NULL ) {
        return( NULLHANDLE );
    }
    if( wnd->root_frame != NULLHANDLE ) {
        return( wnd->root_frame );
    }
    return( wnd->hwnd_frame );
}

/*
 * GUIGetTopParentHWND -- This routine returns a handle to a window if ?
 */

HWND GUIGetTopParentHWND( HWND hwnd )
{
    HWND curr_hwnd;
    HWND parent;

    GUIlog_entering_HWND_function ();

    curr_hwnd = hwnd;
    for( ;; ) {
        parent = _wpi_getparent( curr_hwnd );
        if( parent == HWND_DESKTOP )
            break;
        curr_hwnd = parent;
    }
    return( curr_hwnd );
}

/*
 * GUIGetTopGUIWindow -- ?
 */

gui_window *GUIGetTopGUIWindow( HWND hwnd )
{
    GUIlog_entering_gui_window_function ();

    hwnd = hwnd;
    return( GUIGetRootWindow() );
}

/*
 * GUIGetWindow -- get the gui_window associated with the hwnd
 */

gui_window *GUIGetWindow( HWND hwnd )
{
    gui_window  *wnd;

    GUIlog_entering_gui_window_function ();

    if( ( hwnd != NULLHANDLE ) && ( hwnd != HWND_DESKTOP ) ) {
        wnd = (gui_window *)_wpi_getwindowlongptr( hwnd, GUI_EXTRA_WORD * EXTRA_SIZE );
        return( wnd );
    }

    return( NULL );
}

/*
 * GUIGetParentWindow -- ?
 */

gui_window * GUIAPI GUIGetParentWindow( gui_window *wnd )
{
    GUIlog_entering_gui_window_function ();

    if( wnd != NULL ) {
        return( wnd->parent );
    } else {
        return( NULL );
    }
}

/*
 * GUIParentHasFlags -- This routine returns true if ?
 */

bool GUIParentHasFlags( gui_window *wnd, gui_flags flags )
{
    GUIlog_entering_bool_function ();

    for( ; wnd != NULL; wnd = GUIGetParentWindow( wnd ) ) {
        if( wnd->flags & flags ) {
            return( true );
        }
    }

    return( false );
}

/*
 * GUIGetFirstSibling -- ?
 */

gui_window * GUIAPI GUIGetFirstSibling( gui_window *wnd )
{
    gui_window  *parent_wnd;

    GUIlog_entering_gui_window_function ();

    if( wnd == NULL ) {
        return( NULL );
    }

    parent_wnd = wnd->parent;
    if( ( parent_wnd == NULL ) || GUI_IS_DIALOG( parent_wnd ) ) {
        return( NULL );
    }

    return( GUIFindFirstChild( parent_wnd ) );
}

/*
 * GUIGetSystemFont -- ?
 */

WPI_FONT GUIGetSystemFont( void )
{
    WPI_FONT    font;

#ifdef __OS2_PM__
    WPI_FONT    ret;

    GUIlog_entering_WPI_FONT_function ();

    font = NULL;
    ret = _wpi_getsystemfont();
    if( ret ) {
        font = (WPI_FONT)GUIMemAlloc( sizeof( *font ) );
        if( font ) {
            *font = *ret;
        }
    }
#else  // of #ifdef __OS2_PM__
    GUIlog_entering_void_function ();

    font = _wpi_getsystemfont();
#endif  // of #else for #ifdef __OS2_PM__

    return( font );
}
