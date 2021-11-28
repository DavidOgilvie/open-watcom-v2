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
#include <string.h>
#include "guimenus.h"
#include "guixwind.h"
#include "guixutil.h"
#include "guifloat.h"
#include "guifont.h"
#include "guistr.h"
#include "guixhook.h"
#include "guihook.h"
#include "guimdi.h"
#include "guilog.h"


#define MAX_STR 256

static gui_menu_struct GUIHint[] = {
    { NULL, GUI_CHANGE_FONT, GUI_STYLE_MENU_ENABLED, NULL },
    { NULL, GUI_FIX_TOOLBAR, GUI_STYLE_MENU_ENABLED, NULL }
};

static gui_menu_items menu_GUIHint = GUI_MENU_ARRAY( GUIHint );

/*
 * GUIInitGUIMenuHint -- ?
 */

void GUIInitGUIMenuHint( void )
{
    GUIlog_entering_void_function ();

    GUIHint[GUI_MENU_IDX( GUI_CHANGE_FONT )].label = LIT( Change_XFont_ );
    GUIHint[GUI_MENU_IDX( GUI_CHANGE_FONT )].hinttext = LIT( Change_Font_for_this_window  );
    GUIHint[GUI_MENU_IDX( GUI_FIX_TOOLBAR )].label = LIT( XFix_Tool_Bar );
    GUIHint[GUI_MENU_IDX( GUI_FIX_TOOLBAR )].hinttext = LIT( Make_Tool_Bar_Fixed );
}

/*
 * GUIAppendSystemMenuItem -- ?
 */

void GUIAppendSystemMenuItem( HMENU hsysmenu, int menu_idx )
{
    GUIlog_entering_void_function ();

    if( hsysmenu != NULLHANDLE ) {
        if( _wpi_appendmenu( hsysmenu, MF_SEPARATOR, 0, 0, NULLHANDLE, NULL ) ) {
            _wpi_appendmenu( hsysmenu, MF_STRING, MF_ENABLED, GUIHint[menu_idx].id, NULLHANDLE, GUIHint[menu_idx].label );
        }
    }
}

/*
 * GetMenuFlags -- This routine returns true if ?
 */

static bool GetMenuFlags( HMENU hmenu, gui_ctl_id id_position, bool by_position,
                          unsigned *menu_flags, unsigned *attr_flags )
{
    WPI_MENUSTATE       mstate;

    GUIlog_entering_bool_function ();

    if( hmenu != NULLHANDLE ) {
        _wpi_getmenustate( hmenu, id_position, &mstate, ( by_position ) ? TRUE : FALSE );
        _wpi_getmenuflagsfromstate( &mstate, menu_flags, attr_flags );
        return( true );
    }

    return( false );
}

/*
 * GetParentMenuPos -- This routine returns true if ?
 */

static bool GetParentMenuPos( HMENU hmenu, HMENU hpopup, HMENU *hparent, int *position )
{
    int         num_items;
    int         i;
    HMENU       hsubmenu;

    GUIlog_entering_bool_function ();

    num_items = _wpi_getmenuitemcount( hmenu );
    for( i = 0; i < num_items; i++ ) {
        hsubmenu = _wpi_getsubmenu( hmenu, i );
        if( hsubmenu != NULLHANDLE ) {
            if( hsubmenu == hpopup ) {
                if( hparent != NULL ) {
                    *hparent = hmenu;
                }
                if( position != NULL ) {
                    *position = i;
                }
                return( true );
            } else {
                if( GetParentMenuPos( hsubmenu, hpopup, hparent, position ) ) {
                    return( true );
                }
            }
        }
    }
    return( false );
}

/*
 * GetPopupHMENU -- This routine returns a handle to a menu if ?
 */

static HMENU GetPopupHMENU( gui_window *wnd, HMENU hmenu, gui_ctl_id id,
                            HMENU *hparent, int *position, hint_type type )
{
    popup_info  *info;

    GUIlog_entering_HMENU_function ();

    if( hparent != NULL ) {
        *hparent = NULLHANDLE;
    }
    if( position != NULL ) {
        *position = 0;
    }
    for( info = wnd->popup; info != NULL; info = info->next ) {
        if( ( info->id == id ) && ( info->type == type ) ) {
            if( ( hparent != NULL ) || ( position != NULL ) ) {
                GetParentMenuPos( hmenu, info->hpopup, hparent, position );
                if( hparent != NULL && *hparent == NULLHANDLE ) {
                    return( NULLHANDLE );
                }
            }
            return( info->hpopup );
        }
    }
    return( NULLHANDLE );
}

#if 0
/*
 * GetStateForMenu -- ?
 */

void GetStateForMenu( gui_window *wnd, gui_ctl_id id, WPI_MENUSTATE *mstate )
{
    HMENU           hmenu, hpopup, hparent;
    int             position;

    GUIlog_entering_void_function ();

    hmenu = GUIGetHMENU( wnd );
    if( hmenu == NULLHANDLE ) {
        return;
    }

    hpopup = GetPopupHMENU( wnd, hmenu, id, &hparent, &position, MENU_HINT );

    if( hpopup != NULLHANDLE ) {
        _wpi_getmenustate( hparent, position, mstate, TRUE );
    } else {
        _wpi_getmenustate( hmenu, id, mstate, FALSE );
    }
}

/*
 * GUIIsMenuItemChecked -- This routine returns true if ?
 */

bool GUIIsMenuItemChecked( gui_window *wnd, gui_ctl_id id )
{
    WPI_MENUSTATE       mstate;

    GUIlog_entering_bool_function ();

    GetStateForMenu( wnd, id, &mstate );

    return( _wpi_ismenucheckedfromstate( &mstate ) );
}

/*
 * GUIIsMenuItemEnabled -- This routine returns true if ?
 */

bool GUIIsMenuItemEnabled( gui_window *wnd, gui_ctl_id id )
{
    WPI_MENUSTATE       mstate;

    GUIlog_entering_bool_function ();

    GetStateForMenu( wnd, id, &mstate );

    return( _wpi_ismenuenabledfromstate( &mstate ) );
}
#endif  // of #if 0

/*
 * GUISetMenu -- ?
 */

void GUISetMenu( gui_window *wnd, HMENU hmenu )
{
    HWND        frame;
    WPI_RECT    wpi_rect;
    guix_coord  scr_size;
    int         height;
#ifndef __OS2_PM__
    HMENU       hmenu2;
#endif  // of #ifndef __OS2_PM__

    GUIlog_entering_void_function ();

#ifndef __OS2_PM__
    hmenu2 = GUIGetHMENU( wnd );
#endif  // of #ifndef __OS2_PM__
    frame = GUIGetParentFrameHWND( wnd );
    _wpi_getclientrect( frame, &wpi_rect );
    height = _wpi_getheightrect( wpi_rect );
    _wpi_setmenu( frame, hmenu );
    _wpi_getclientrect( frame, &wpi_rect );
    scr_size.y = _wpi_getheightrect( wpi_rect );
    if( height != scr_size.y ) {
        scr_size.x = _wpi_getwidthrect( wpi_rect );
        GUIDoResize( wnd, GUIGetParentHWND( wnd ), &scr_size );
    }
#ifndef __OS2_PM__
    if( hmenu2 != NULLHANDLE ) {
        _wpi_destroymenu( hmenu2 );
    }
#endif  // of #ifndef __OS2_PM__
}

/*
 * GetPopupId -- This routine returns true if ?
 */

static bool GetPopupId( gui_window *wnd, HMENU hmenu, gui_ctl_id *id )
{
    popup_info  *info;

    GUIlog_entering_bool_function ();

    for( info = wnd->popup; info != NULL; info = info->next ) {
        if( info->hpopup == hmenu ) {
            *id = info->id;
            return( true );
        }
    }
    return( false );
}

/*
 * InsertPopup -- This routine returns true if ?
 */

static bool InsertPopup( gui_window *wnd, gui_ctl_id id, HMENU hpopup, hint_type type )
{
    popup_info  *info;
    HMENU       hmenu;

    GUIlog_entering_bool_function ();

    hmenu = GetPopupHMENU( wnd, GUIGetHMENU( wnd ), id, NULL, NULL, type );
    if( hmenu != hpopup ) {
        info = (popup_info *)GUIMemAlloc( sizeof( popup_info ) );
        if( info == NULL )
            return( false );
        info->next = wnd->popup;
        wnd->popup = info;
        info->id = id;
        info->hpopup = hpopup;
        info->type = type;
    }
    return( true );
}

/*
 * DeletePopup -- ?
 */

static void DeletePopup( gui_window *wnd, gui_ctl_id id )
{
    popup_info  *curr;
    popup_info  *prev;

    GUIlog_entering_void_function ();

    prev = NULL;
    for( curr = wnd->popup; curr != NULL; prev = curr, curr=curr->next ) {
        if( ( curr->id == id ) && ( curr->type == MENU_HINT ) ) {
            if( prev != NULL ) {
                prev->next = curr->next;
            } else {
                wnd->popup = curr->next;
            }
            GUIMemFree( curr );
            break;
        }
    }
}

/*
 * GUIDeleteFloatingPopups -- ?
 */

void GUIDeleteFloatingPopups( gui_window *wnd )
{
    popup_info  *curr;
    popup_info  *prev;
    popup_info  *tmp;

    GUIlog_entering_void_function ();

    prev = NULL;
    for( curr = wnd->popup; curr != NULL; ) {
        if( curr->type == FLOAT_HINT ) {
            if( prev != NULL ) {
                prev->next = curr->next;
            } else {
                wnd->popup = curr->next;
            }
            tmp = curr->next;
            GUIMemFree( curr );
            curr = tmp;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

/*
 * GUIFreePopupList -- ?
 */

void GUIFreePopupList( gui_window *wnd )
{
    popup_info  *curr;
    popup_info  *next;

    GUIlog_entering_void_function ();

    for( curr = wnd->popup; curr != NULL; curr = next ) {
        next = curr->next;
        GUIMemFree( curr );
    }
    wnd->popup = NULLHANDLE;
}

/*
 * GUISetGUIHint -- ?
 */

void GUISetGUIHint( gui_window *wnd )
{
    GUIlog_entering_void_function ();

    GUIInitHint( wnd, &menu_GUIHint, GUI_HINT );
}

HMENU   GUIHFloatingPopup = NULLHANDLE;

/*
 * GUIGetHMENU -- return the HMENU that the user can change
 */

HMENU GUIGetHMENU( gui_window *wnd )
{
    HMENU hmenu;

    GUIlog_entering_HMENU_function ();

    if( wnd->root_frame == NULLHANDLE ) { /* child window */
        if( wnd->hwnd_frame == NULLHANDLE )
            return( NULLHANDLE );
        hmenu = _wpi_getsystemmenu( wnd->hwnd_frame );
    } else {
        hmenu = _wpi_getmenu( wnd->root_frame );
    }
    return( hmenu );
}

/*
 * GUIDrawMenuBar -- ?
 */

static void GUIDrawMenuBar( gui_window *wnd )
{
    GUIlog_entering_void_function ();

    if( wnd->root_frame != NULLHANDLE ) {
        if( _wpi_getmenu( wnd->root_frame ) != NULLHANDLE ) {
            _wpi_drawmenubar( wnd->root_frame );
        }
    } else {
        if( wnd->style & GUI_POPUP ) {
            if( _wpi_getmenu( wnd->hwnd_frame ) != NULLHANDLE ) {
                _wpi_drawmenubar( wnd->hwnd_frame );
            }
        }
    }
}

/*
 * GUIGetMenuPopupCount -- This routine returns an integer value
 *                         representing ?
 */

int GUIAPI GUIGetMenuPopupCount( gui_window *wnd, gui_ctl_id id )
{
    HMENU       hmenu;
    HMENU       hpopup;
    int         num_items;

    GUIlog_entering_int_function ();

    hmenu = GUIGetHMENU( wnd );
    if( hmenu == NULLHANDLE ) {
        return( 0 );
    }

    hpopup = GetPopupHMENU( wnd, hmenu, id, NULL, NULL, MENU_HINT );

    if( hpopup != NULLHANDLE ) {
        num_items = _wpi_getmenuitemcount( hpopup );
    } else {
        num_items = -1;
    }

    return( num_items );
}

/*
 * GetOrMakeHMENU -- This routine returns a handle to a menu if ?
 */

static HMENU GetOrMakeHMENU( gui_window *wnd, bool floating, bool *made_root )
{
    HMENU       hmenu;

    GUIlog_entering_HMENU_function ();

    if( made_root ) {
        *made_root = false;
    }
    if( floating ) {
        if( GUIHFloatingPopup == NULLHANDLE ) {
            GUIHFloatingPopup = _wpi_createpopupmenu();
        }
        hmenu = GUIHFloatingPopup;
    } else {
        hmenu = GUIGetHMENU( wnd );
        if( hmenu == NULLHANDLE ) {
            if( wnd->root_frame != NULLHANDLE ) {
                hmenu = _wpi_createmenu();
                if( hmenu != NULLHANDLE ) {
                    //GUISetMenu( wnd, hmenu );
                    if( made_root ) {
                        *made_root = true;
                    }
                }
            }
        }
    }
    return( hmenu );
}

/*
 * GUIDeleteMenuItem -- delete the given menu item
 */

bool GUIAPI GUIDeleteMenuItem( gui_window *wnd, gui_ctl_id id, bool floating )
{
    HMENU       hmenu, hpopup, hparent;
    int         position;
    hint_type   type;

    GUIlog_entering_bool_function ();

    if( floating ) {
        type = FLOAT_HINT;
    } else {
        type = MENU_HINT;
    }
    hmenu = GetOrMakeHMENU( wnd, floating, NULL );
    if( hmenu == NULLHANDLE ) {
        return( false );
    }

    hpopup = GetPopupHMENU( wnd, hmenu, id, &hparent, &position, type );

    if( hpopup != NULLHANDLE ) {
        _wpi_deletemenu( hparent, position, TRUE );
    } else {
        _wpi_deletemenu( hmenu, id, FALSE );
    }

    GUIDeleteHintText( wnd, id, MENU_HINT );
    DeletePopup( wnd, id );
    GUIMDIDeleteMenuItem( id );

    if( hmenu == hparent ) {
        GUIDrawMenuBar( wnd );
    }

    return( true );
}

/*
 * CheckItem -- ?
 */

static void CheckItem( HMENU hmenu, gui_ctl_id id, bool check )
{
    GUIlog_entering_void_function ();

    _wpi_checkmenuitem( hmenu, id, ( check ) ? TRUE : FALSE, FALSE );
}

/*
 * CheckPopup -- ?
 */

static void CheckPopup( HMENU hmenu, int position, bool check )
{
    GUIlog_entering_void_function ();

    _wpi_checkmenuitem( hmenu, position, ( check ) ? TRUE : FALSE, TRUE );
}

/*
 * GUICheckMenuItem -- This routine returns true if  the routine can
 *                     check or uncheck a menu item
 */

bool GUIAPI GUICheckMenuItem( gui_window *wnd, gui_ctl_id id, bool check, bool floating )
{
    HMENU       hmenu, hpopup, hparent;
    int         position;
    hint_type   type;

    GUIlog_entering_bool_function ();

    if( floating ) {
        type = FLOAT_HINT;
    } else {
        type = MENU_HINT;
    }
    hmenu = GetOrMakeHMENU( wnd, floating, NULL );
    if( hmenu == NULLHANDLE ) {
        return( false );
    }

    hpopup = GetPopupHMENU( wnd, hmenu, id, &hparent, &position, MENU_HINT );

    if( hpopup != NULLHANDLE ) {
        CheckPopup( hparent, position, check );
    } else {
        CheckItem( hmenu, id, check );
    }

    if( hmenu == hparent ) {
        GUIDrawMenuBar( wnd );
    }

    return( true );
}

/*
 * EnableItem -- ?
 */

static void EnableItem( HMENU hmenu, gui_ctl_id id, bool enable )
{
    GUIlog_entering_void_function ();

    _wpi_enablemenuitem( hmenu, id, ( enable ) ? TRUE : FALSE, FALSE );
}

/*
 * EnablePopup -- ?
 */

static void EnablePopup( HMENU hmenu, int position, bool enable )
{
    GUIlog_entering_void_function ();

    _wpi_enablemenuitem( hmenu, position, ( enable ) ? TRUE : FALSE, TRUE );
}

/*
 * GUIEnableSystemMenuItem -- This routine returns true if it can enable
 *                            or disable a system menu item.  Used by GUI
 *                            library only
 */

bool GUIEnableSystemMenuItem( gui_window *wnd, gui_ctl_id id, bool enable )
{
    HMENU       hsysmenu;

    GUIlog_entering_bool_function ();

    hsysmenu = _wpi_getsystemmenu( GUIGetParentFrameHWND( wnd ) );
    if( hsysmenu != NULLHANDLE ) {
        EnableItem( hsysmenu, id, enable );
    }
    return( true );
}

/*
 * GUIEnableMenuItem -- This routine returns true if it can enable or
 *                      disable a menu item
 */

bool GUIAPI GUIEnableMenuItem( gui_window *wnd, gui_ctl_id id, bool enable, bool floating )
{
    HMENU       hmenu, hpopup, hparent;
    int         position;
    hint_type   type;

    GUIlog_entering_bool_function ();

    if( floating ) {
        type = FLOAT_HINT;
    } else {
        type = MENU_HINT;
    }
    hmenu = GetOrMakeHMENU( wnd, floating, NULL );
    if( hmenu == NULLHANDLE ) {
        return( false );
    }

    hpopup = GetPopupHMENU( wnd, hmenu, id, &hparent, &position, MENU_HINT );

    if( hpopup != NULLHANDLE ) {
        EnablePopup( hparent, position, enable );
    } else {
        EnableItem( hmenu, id, enable );
    }

    if( hmenu == hparent ) {
        GUIDrawMenuBar( wnd );
    }

    return( true );
}

/*
 * GUISetMenuText -- This routine returns true if it can change the
 *                   text of a menu item
 */

bool GUIAPI GUISetMenuText( gui_window *wnd, gui_ctl_id id, const char *text, bool floating )
{
    HMENU       hmenu, hpopup, hparent;
    int         position;
    hint_type   type;
    bool        ret;

    GUIlog_entering_bool_function ();

    if( floating ) {
        type = FLOAT_HINT;
    } else {
        type = MENU_HINT;
    }
    hmenu = GetOrMakeHMENU( wnd, floating, NULL );
    if( hmenu == NULLHANDLE ) {
        return( false );
    }

    hpopup = GetPopupHMENU( wnd, hmenu, id, &hparent, &position, MENU_HINT );

    if ( hpopup != NULLHANDLE ) {
        ret = ( _wpi_setmenutext( hparent, position, text, TRUE ) != 0 );
    } else {
        ret = ( _wpi_setmenutext( hmenu, id, text, FALSE ) != 0 );
    }

    if( hmenu == hparent ) {
        GUIDrawMenuBar( wnd );
    }

    return( ret );
}

/*
 * GUICreateMenuFlags -- take gui_menu_styles information and return Windows
 *                       menu style
 */

void GUICreateMenuFlags( gui_menu_styles style, unsigned *menu_flags, unsigned *attr_flags )
{
    GUIlog_entering_void_function ();

    *menu_flags = 0;
    *attr_flags = 0;
    if( style == GUI_STYLE_MENU_ENABLED ) {
        *attr_flags |= MF_ENABLED;
    }
    if( style & GUI_STYLE_MENU_CHECKED ) {
        *attr_flags |= MF_CHECKED;
    }
    if( style & GUI_STYLE_MENU_GRAYED ) {
        *attr_flags |= MF_GRAYED;
    }
    if( style & GUI_STYLE_MENU_SEPARATOR ) {
        *menu_flags |= MF_SEPARATOR;
    }
}

/*
 * GUICreateSubMenu -- This routine returns a handle to a menu when ?
 */

HMENU GUICreateSubMenu( gui_window *wnd, const gui_menu_items *menus, hint_type type )
{
    HMENU       hmenu;
    int         i;
    HMENU       hsubmenu;
    unsigned    menu_flags;
    unsigned    attr_flags;

    GUIlog_entering_HMENU_function ();

    hmenu = _wpi_createpopupmenu();
    if( hmenu == NULLHANDLE ) {
        return( NULLHANDLE );
    }
    for( i = 0; i < menus->num_items; i++ ) {
        GUICreateMenuFlags( menus->menu[i].style, &menu_flags, &attr_flags );
        if( menus->menu[i].child.num_items > 0 ) {
            hsubmenu = GUICreateSubMenu( wnd, &menus->menu[i].child, type );
            _wpi_appendmenu( hmenu, MF_POPUP | menu_flags, attr_flags, menus->menu[i].id, hsubmenu, menus->menu[i].label );
            InsertPopup( wnd, menus->menu[i].id, hsubmenu, type );
        } else {
            _wpi_appendmenu( hmenu, menu_flags, attr_flags, menus->menu[i].id, NULLHANDLE, menus->menu[i].label );
        }
    }
    return( hmenu );
}

/*
 * AppendMenus -- This routine returns true if it can append menu items
 *                to a HMENU
 */

static bool AppendMenus( gui_window *wnd, HMENU hmenu, const gui_menu_items *menus )
{
    int                 i;
    HMENU               hchildmenu;

    GUIlog_entering_bool_function ();

    for( i = 0; i < menus->num_items; i++ ) {
        hchildmenu = GUICreateSubMenu( wnd, &menus->menu[i].child, MENU_HINT );
        if( hchildmenu != NULLHANDLE ) {
            _wpi_appendmenu( hmenu, MF_STRING | MF_POPUP, MF_ENABLED, menus->menu[i].id, hchildmenu, menus->menu[i].label );
            InsertPopup( wnd, menus->menu[i].id, hchildmenu, MENU_HINT );
        }
    }
    return( true );
}

/*
 * GUICreateMenus -- This routine returns true if it can create a menu
 *                   resourse
 */

bool GUICreateMenus( gui_window *wnd, const gui_menu_items *menus, HMENU *hmenu )
{
    GUIlog_entering_bool_function ();

    if( hmenu == NULL ) {
        return( false );
    }
    *hmenu = NULLHANDLE;
    if( menus->num_items == 0 ) {
        return( true );
    }
    *hmenu = _wpi_createmenu();
    if( *hmenu == NULLHANDLE ) {
        return( false );
    }
    return( AppendMenus( wnd, *hmenu, menus ) );
}

/*
 * GUIAddToSystemMenu -- This routine returns true if it can add menus
 *                       items to the system menus.  Used to give menu
 *                       items to child windows
 */

bool GUIAddToSystemMenu( gui_window *wnd, HWND hwnd, const gui_menu_items *menus, gui_create_styles style )
{
    HMENU           hsysmenu;
    int             num_items;

    GUIlog_entering_bool_function ();

    if( (style & GUI_SYSTEM_MENU) == 0 ) {
        return( true );
    }
    hsysmenu = _wpi_getsystemmenu( hwnd );
    if( hsysmenu == NULLHANDLE ) {
        return( false );
    }
    if( GUIMDI && ( _wpi_getparent( hwnd ) != NULLHANDLE ) ) {
        num_items = _wpi_getmenuitemcount( hsysmenu );
#ifndef __OS2_PM__
        ModifyMenu( hsysmenu, num_items - 1, MF_STRING | MF_BYPOSITION | MF_GRAYED,
                    SC_NEXTWINDOW, LIT( NexXt ) ); // add \tCtrl+F6" );
        ModifyMenu( hsysmenu, num_items - 3, MF_STRING | MF_BYPOSITION | MF_ENABLED,
                    SC_CLOSE, LIT( XClose ) ); // add \tctrl+f4" );
#endif  // of #ifndef __OS2_PM__
    }
    if( (style & GUI_CLOSEABLE) == 0 ) {
        _wpi_enablemenuitem( hsysmenu, SC_CLOSE, FALSE, FALSE );
    }
    if( style & GUI_CHANGEABLE_FONT ) {
        GUIAppendSystemMenuItem( hsysmenu, GUI_MENU_IDX( GUI_CHANGE_FONT ) );
    }
    if( menus->num_items > 0 ) {
        if( _wpi_appendmenu( hsysmenu, MF_SEPARATOR, 0, 0, NULLHANDLE, NULL ) ) {
            return( AppendMenus( wnd, hsysmenu, menus ) );
        }
    }
    return( true );
}

/*
 * DisplayMenuHintText -- display hint text for a menu item
 */

static void DisplayMenuHintText( gui_window *wnd, WPI_PARAM1 wparam, WPI_PARAM2 lparam, hint_type type )
{
    gui_window          *top_wnd;
    gui_menu_styles     style;
    gui_ctl_id          id;
    HMENU               hpopup;
    int                 menu_closed;
    int                 is_separator;
    int                 is_popup;
    int                 is_hilite;
    int                 is_enabled;
    int                 is_sysmenu;
#ifndef __OS2_PM__
    WORD                flags;
#else  // of #ifndef __OS2_PM__
    WPI_MENUSTATE       mstate;
    HMENU               hmenu;
#endif  // of #else for #ifndef __OS2_PM__

    GUIlog_entering_void_function ();

    lparam = lparam;
    id = GET_WM_MENUSELECT_ITEM( wparam, lparam );
    menu_closed = _wpi_is_close_menuselect( wparam, lparam );

#ifndef __OS2_PM__
    flags = GET_WM_MENUSELECT_FLAGS( wparam, lparam );
    is_sysmenu = ( flags & MF_SYSMENU );
    is_separator = ( flags & MF_SEPARATOR );
    is_hilite = ( flags & MF_HILITE );
    is_popup = ( flags & MF_POPUP );
    is_enabled = ( ( flags & MF_GRAYED ) || ( flags & MF_DISABLED ) );
    hpopup = NULLHANDLE;
    if( is_popup ) {
        hpopup = (HMENU)GET_WM_MENUSELECT_ITEM( wparam, lparam );
    }
#else  // of #ifndef __OS2_PM__
    hmenu = (HMENU)lparam;
    if( !menu_closed &&
        WinSendMsg( hmenu, MM_QUERYITEM, MPFROM2SHORT(id, true), MPFROMP(&mstate) ) ) {
        is_sysmenu = ( (mstate.afStyle & MF_SYSMENU) != 0 );
        is_separator = false;
        is_popup = ( (mstate.afStyle & MF_POPUP) != 0 );
        is_hilite = ( (mstate.afAttribute & MF_HILITE) != 0 );
        is_enabled = ( (mstate.afAttribute & MF_DISABLED) != 0 );
        hpopup = NULLHANDLE;
        if( is_popup ) {
            hpopup = mstate.hwndSubMenu;
        }
    } else {
        menu_closed = true;
    }
#endif  // of #else for #ifndef __OS2_PM__

    if( !( menu_closed || is_separator || is_hilite ) ) {
        return;
    }

    top_wnd = GUIGetTopGUIWindow( wnd->hwnd );
    if( top_wnd == NULL ) {
        return;
    }


    if( menu_closed ) {
        style = GUI_STYLE_MENU_IGNORE; /* will display blank */
    } else {
        if( is_separator ) {
            style = GUI_STYLE_MENU_SEPARATOR; /* will display blank */
        } else {
            /* must be MF_HILITE */
            if( is_enabled ) {
                style = GUI_STYLE_MENU_GRAYED;
            } else {
                style = GUI_STYLE_MENU_ENABLED;
            }
            if( is_sysmenu ) {
                if( id > GUI_LAST_MENU_ID ) {
                    /* menu item added by GUI */
                    type = GUI_HINT;
                }
            }
            if( is_popup ) {
                if( !GetPopupId( wnd, hpopup, &id ) ) {
                    style = GUI_STYLE_MENU_IGNORE; /* will display blank */
                }
            }
        }
    }

    GUIDisplayHintText( top_wnd, wnd, id, type, style );
}

/*
 * GUIProcessMenuSelect -- ?
 */

WPI_MRESULT GUIProcessMenuSelect( gui_window *wnd, HWND hwnd, WPI_MSG msg,
                                  WPI_PARAM1 wparam, WPI_PARAM2 lparam )
{
    hint_type   type;

    GUIlog_entering_WPI_MRESULT_function ();

    if( GUIHFloatingPopup != NULLHANDLE ) {
        type = FLOAT_HINT;
#ifndef __OS2_PM__
        ShowOwnedPopups( hwnd, true );
#endif  // of #ifndef __OS2_PM__
        GUIPopupMenuSelect( wparam, lparam );
    } else {
        type = MENU_HINT;
    }
    DisplayMenuHintText( wnd, wparam, lparam, type );
    return( _wpi_defwindowproc( hwnd, msg, wparam, lparam ) );
}

/*
 * GUIProcessInitMenuPopup -- ?
 */

WPI_MRESULT GUIProcessInitMenuPopup ( gui_window *wnd, HWND hwnd, WPI_MSG msg,
                                      WPI_PARAM1 wparam, WPI_PARAM2 lparam )
{
    gui_ctl_id  id;
    HMENU       hmenu;

    GUIlog_entering_WPI_MRESULT_function ();

    hmenu = GET_WM_INITMENU_MENU( wparam, lparam );
    if( GetPopupId( wnd, hmenu, &id ) ) {
        GUIEVENT( wnd, GUI_INITMENUPOPUP, &id );
    }
    return( _wpi_defwindowproc( hwnd, msg, wparam, lparam ) );
}

/*
 * AddMenu -- This routine returns true if ?
 */

static bool AddMenu( HMENU hmenu, gui_window *wnd, const gui_menu_struct *menu,
                     bool insert, gui_ctl_id id_position, bool by_position,
                     hint_type type )
{
    unsigned        menu_flags;
    unsigned        attr_flags;
    gui_ctl_id      newitem;
    HMENU           hsubmenu;
    gui_menu_items  menus;

    GUIlog_entering_bool_function ();

    hsubmenu = NULLHANDLE;
    newitem = menu->id;
    if( hmenu == NULLHANDLE ) {
        return( false );
    }
    if( menu->child.num_items == 0 ) {
        GUICreateMenuFlags( menu->style, &menu_flags, &attr_flags );
    } else {
        hsubmenu = GUICreateSubMenu( wnd, &menu->child, type );
        if( hsubmenu == NULLHANDLE ) {
            return( false );
        } else {
            GUICreateMenuFlags( menu->style, &menu_flags, &attr_flags );
            menu_flags |= MF_POPUP;
            InsertPopup( wnd, newitem, hsubmenu, type );
        }
    }
    if( insert ) {
        if( by_position ) {
            if( ( (int)id_position != -1 ) && GUIMDIUpdatedMenu() ) {
                id_position++;
            }
        }
        _wpi_insertmenu( hmenu, id_position, menu_flags, attr_flags,
                         newitem, hsubmenu, menu->label, ( by_position ) ? TRUE : FALSE );
    } else {
        _wpi_appendmenu( hmenu, menu_flags, attr_flags,
                         newitem, hsubmenu, menu->label );
    }
    GUIAppendHintText( wnd, menu, type );
    menus.num_items = 1;
    menus.menu = (gui_menu_struct *)menu;
    GUIMDIResetMenus( wnd, wnd->parent, &menus );
    if( ( type != FLOAT_HINT ) && ( hmenu == GUIGetHMENU( wnd ) ) ) {
        GUIDrawMenuBar( wnd );
    }
    return( true );
}

/*
 * GUIInsertMenuByIdx -- This routine returns true if ?
 */

bool GUIAPI GUIInsertMenuByIdx( gui_window *wnd, int position, const gui_menu_struct *menu, bool floating )
{
    HMENU       hmenu;
    hint_type   type;
    bool        made_root;
    bool        ret;

    GUIlog_entering_bool_function ();

    if( floating ) {
        type = FLOAT_HINT;
    } else {
        type = MENU_HINT;
    }
    hmenu = GetOrMakeHMENU( wnd, floating, &made_root );
    ret = AddMenu( hmenu, wnd, menu, true, position, true, type );
    if( ret && made_root ) {
        GUISetMenu( wnd, hmenu );
    }
    return( ret );
}

/*
 * GUIInsertMenuByID -- This routine returns true if ?
 */

bool GUIAPI GUIInsertMenuByID( gui_window *wnd, gui_ctl_id id, const gui_menu_struct *menu )
{
    WPI_MENUSTATE   mstate;
    HMENU           hmenu;
    int             position;
    HMENU           hparent;
    bool            made_root;
    bool            ret;

    GUIlog_entering_bool_function ();

    ret = false;
    hmenu = GetOrMakeHMENU( wnd, false, &made_root );
    if( !_wpi_getmenustate( hmenu, id, &mstate, FALSE ) ) {
        if( GetPopupHMENU( wnd, hmenu, id, &hparent, &position, MENU_HINT ) != NULLHANDLE ) {
            ret = AddMenu( hparent, wnd, menu, true, position, true, MENU_HINT );
        }
    } else {
        ret = AddMenu( hmenu, wnd, menu, true, id, false, MENU_HINT );
    }
    if( ret && made_root ) {
        GUISetMenu( wnd, hmenu );
    }
    return( ret );
}

/*
 * GUIAppendMenu -- This routine returns true if ?
 */

bool GUIAPI GUIAppendMenu( gui_window *wnd, const gui_menu_struct *menu, bool floating )
{
    HMENU       hmenu;
    hint_type   type;
    bool        ret;
    bool        made_root;

    GUIlog_entering_bool_function ();

    if( floating ) {
        type = FLOAT_HINT;
    } else {
        type = MENU_HINT;
    }
    hmenu = GetOrMakeHMENU( wnd, floating, &made_root );
    ret = AddMenu( hmenu, wnd, menu, false, 0, false, type );
    if( ret && made_root ) {
        GUISetMenu( wnd, hmenu );
    }
    return( ret );
}

/*
 * GUIAppendMenuByIdx -- This routine returns true if ?
 */

bool GUIAPI GUIAppendMenuByIdx( gui_window *wnd, int position, const gui_menu_struct *menu )
{
    HMENU       hmenu;
    HMENU       hsubmenu;
    bool        made_root;
    bool        ret;

    GUIlog_entering_bool_function ();

    hmenu = GetOrMakeHMENU( wnd, false, &made_root );
    if( hmenu == NULLHANDLE ) {
        return( false );
    }
    if( ( position != -1 ) && GUIMDIUpdatedMenu() ) {
        position++;
    }
    hsubmenu = _wpi_getsubmenu( hmenu, position );
    ret = AddMenu( hsubmenu, wnd, menu, false, 0, false, MENU_HINT );
    if( ret && made_root ) {
        GUISetMenu( wnd, hmenu );
    }
    return( ret );
}

/*
 * ChangeMenuToPopup -- This routine returns true if ?
 */

static HMENU ChangeMenuToPopup ( gui_window *wnd, HMENU hmenu, gui_ctl_id id, hint_type type )
{
    HMENU               hpopup;
    char                name[MAX_STR];
    unsigned            menu_flags;
    unsigned            attr_flags;

    GUIlog_entering_HMENU_function ();

    hpopup = _wpi_createpopupmenu();
    if( hpopup != NULLHANDLE ) {
        _wpi_getmenutext( hmenu, id, name, MAX_STR - 1, FALSE );
        GetMenuFlags( hmenu, id, false, &menu_flags, &attr_flags );
        _wpi_modifymenu( hmenu, id, menu_flags | MF_POPUP, attr_flags, id, hpopup, name, FALSE );
        GUIDrawMenuBar( wnd );
        InsertPopup( wnd, id, hpopup, type );
    }

    return( hpopup );
}

/*
 * AddPopup -- This routine returns true if ?
 */

static bool AddPopup( gui_window *wnd, gui_ctl_id id, const gui_menu_struct *menu,
                      bool insert, int position, bool floating )
{
    HMENU               hmenu;
    HMENU               hpopup;
    hint_type           type;

    GUIlog_entering_bool_function ();

    hmenu = GetOrMakeHMENU( wnd, floating, NULL );
    if( hmenu == NULLHANDLE ) {
        return( false );
    }

    if( floating ) {
        type = FLOAT_HINT;
    } else {
        type = MENU_HINT;
    }

    hpopup = GetPopupHMENU( wnd, hmenu, id, NULL, NULL, type );
    if( hpopup == NULLHANDLE ) {
        hpopup = ChangeMenuToPopup ( wnd, hmenu, id, type );
    }

    return( AddMenu( hpopup, wnd, menu, insert, position, true, type ) );
}

/*
 * GUIInsertMenuToPopup -- This routine returns true if ?
 */

bool GUIAPI GUIInsertMenuToPopup( gui_window *wnd, gui_ctl_id id, int position,
                                const gui_menu_struct *menu, bool floating )
{
    GUIlog_entering_bool_function ();

    return( AddPopup( wnd, id, menu, true, position, floating ) );
}

/*
 * GUIAppendMenuToPopup -- This routine returns true if ?
 */

bool GUIAPI GUIAppendMenuToPopup( gui_window *wnd, gui_ctl_id id,
                                const gui_menu_struct *menu, bool floating )
{
    GUIlog_entering_bool_function ();

    return( AddPopup( wnd, id, menu, false, 0, floating ) );
}
