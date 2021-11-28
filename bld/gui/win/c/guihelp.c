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
#include <mbstring.h>
#include "guixwind.h"
#ifndef __OS2_PM__
    #include "wwinhelp.h"
#endif  // of #ifndef __OS2_PM__
#include "guilog.h"


#ifdef __OS2_PM__

/*
 * gui_help_instance -- ?
 */

static gui_help_instance InitHelp( HWND hwnd, WPI_INST inst, const char *title, const char *help_lib )
{
    HWND        hwndHelpInstance;
    HELPINIT    help;

    GUIlog_entering_gui_help_instance_function ();

    help.cb = sizeof( HELPINIT );
    help.pszTutorialName = NULL;
    help.phtHelpTable = NULL;
    help.hmodHelpTableModule = 0;
    help.hmodAccelActionBarModule = 0;
    help.idAccelTable = 0;
    help.idActionBar = 0;
    help.pszHelpWindowTitle = (PSZ)title;
 #ifdef _M_I86
    help.usShowPanelId = CMIC_HIDE_PANEL_ID;
 #else  // of #ifdef _M_I86
    help.fShowPanelId = CMIC_HIDE_PANEL_ID;
 #endif  // of #else for #ifdef _M_I86
    help.pszHelpLibraryName = (PSZ)help_lib;
    hwndHelpInstance = WinCreateHelpInstance( inst.hab, &help );
    if( hwndHelpInstance != NULLHANDLE ) {
        if( !WinAssociateHelpInstance( hwndHelpInstance, hwnd ) ) {
            WinDestroyHelpInstance( hwndHelpInstance );
            hwndHelpInstance = NULLHANDLE;
        }
    }
    return( (gui_help_instance)hwndHelpInstance );
}

/*
 * FiniHelp -- ?
 */

static void FiniHelp( gui_help_instance inst, HWND hwnd, const char *file )
{
    GUIlog_entering_void_function ();

    hwnd=hwnd;
    file=file;
    if( (HWND)inst != NULLHANDLE ) {
        WinAssociateHelpInstance( (HWND)inst, NULLHANDLE );
        WinDestroyHelpInstance( (HWND)inst );
    }
}

/*
 * DisplayContents -- This routine returns true if ?
 */

static bool DisplayContents( gui_help_instance inst, HWND hwnd, const char *file )
{
    GUIlog_entering_bool_function ();

    hwnd=hwnd;
    file=file;
    return( !WinSendMsg( (HWND)inst, HM_HELP_CONTENTS, NULL, NULL ) );
}

/*
 * DisplayHelpOnHelp -- This routine returns true if ?
 */

static bool DisplayHelpOnHelp( gui_help_instance inst, HWND hwnd, const char *file )
{
    GUIlog_entering_bool_function ();

    hwnd=hwnd;
    file=file;
    return( !WinSendMsg( (HWND)inst, HM_DISPLAY_HELP, NULL, NULL ) );
}

/*
 * DisplayHelpSearch -- This routine returns true if ?
 */
 
static bool DisplayHelpSearch( gui_help_instance inst, HWND hwnd, const char *file, const char *topic )
{
    GUIlog_entering_bool_function ();
    hwnd=hwnd;
    file=file;
    topic=topic;
    return( !WinSendMsg( (HWND)inst, HM_HELP_INDEX, NULL, NULL ) );
}

/*
 * DisplayHelpKey -- This routine returns true if ?
 */

static bool DisplayHelpKey( gui_help_instance inst, HWND hwnd, const char *file, const char *topic )
{
    GUIlog_entering_bool_function ();

    hwnd=hwnd;
    file=file;
    return( !WinSendMsg( (HWND)inst, HM_DISPLAY_HELP, MPFROMLONG( (LONG)&topic ), MPFROMSHORT( HM_PANELNAME ) ) );
}

/*
 * DisplayHelpContext -- This routine returns true if ?
 */

static bool DisplayHelpContext( gui_help_instance inst, HWND hwnd, const char *file, const char *topic )
{
    GUIlog_entering_bool_function ();

    hwnd=hwnd;
    file=file;
    return( !WinSendMsg( (HWND)inst, HM_DISPLAY_HELP, MPFROM2SHORT( (SHORT)topic, 0 ), MPFROMSHORT( HM_RESOURCEID ) ) );
}
#else  // of #ifdef __OS2_PM__

/*
 * InitHelp -- ?
 */

static gui_help_instance InitHelp( HWND hwnd, WPI_INST inst, const char *title, const char *help_file )
{
    GUIlog_entering_gui_help_instance_function ();

    hwnd = hwnd;
    inst = inst;
    title = title;
    help_file = help_file;
    return( (gui_help_instance)true );
}

/*
 * FiniHelp -- ?
 */

static void FiniHelp( gui_help_instance inst, HWND hwnd, const char *file )
{
    GUIlog_entering_void_function ();

    inst=inst;
    WWinHelp( hwnd, file, (UINT)HELP_QUIT, 0 );
}

/*
 * DisplayContents -- This routine returns true if ?
 */

static bool DisplayContents( gui_help_instance inst, HWND hwnd, const char *file )
{
    GUIlog_entering_bool_function ();

    inst=inst;
    return( WWinHelp( hwnd, file, (UINT)HELP_CONTENTS, 0 ) );
}

/*
 * DisplayHelpOnHelp -- This routine returns true if ?
 */

static bool DisplayHelpOnHelp( gui_help_instance inst, HWND hwnd, const char *file )
{
    GUIlog_entering_bool_function ();

    inst=inst;
    return( WWinHelp( hwnd, file, (UINT)HELP_HELPONHELP, 0 ) );
}

/*
 * DisplayHelpSearch -- This routine returns true if ?
 */

static bool DisplayHelpSearch( gui_help_instance inst, HWND hwnd, const char *file, const char *topic )
{
    GUIlog_entering_bool_function ();

    inst=inst;
    if( topic == NULL ) {
        topic = "";
    }
    return( WWinHelp( hwnd, file, (UINT)HELP_PARTIALKEY, (HELP_DATA)(LPCSTR)topic ) );
}

/*
 * DisplayHelpContext -- This routine returns true if ?
 */

static bool DisplayHelpContext( gui_help_instance inst, HWND hwnd, const char *file, const char *topic )
{
    GUIlog_entering_bool_function ();

    inst=inst;
    return( WWinHelp( hwnd, file, (UINT)HELP_CONTEXT, (HELP_DATA)(LPCSTR)topic ) );
}

/*
 * DisplayHelpKey -- This routine returns true if ?
 */

static bool DisplayHelpKey( gui_help_instance inst, HWND hwnd, const char *file, const char *topic )
{
    GUIlog_entering_bool_function ();

    inst=inst;
    return( WWinHelp( hwnd, file, (UINT)HELP_KEY, (HELP_DATA)(LPCSTR)topic ) );
}

 #if defined( __NT__ )

/*
 * DisplayContentsHH -- This routine returns true if ?
 */

static bool DisplayContentsHH( gui_help_instance inst, HWND hwnd, const char *file )
{
    GUIlog_entering_bool_function ();

    inst = inst;
    return( WHtmlHelp( hwnd, file, (UINT)HELP_CONTENTS, 0 ) );
}

/*
 * DisplayHelpSearchHH -- This routine returns true if ?
 */

static bool DisplayHelpSearchHH( gui_help_instance inst, HWND hwnd, const char *file, const char *topic )
{
    GUIlog_entering_bool_function ();

    inst = inst;
    if( topic == NULL ) {
        topic = "";
    }
    return( WHtmlHelp( hwnd, file, (UINT)HELP_PARTIALKEY, (HELP_DATA)(LPCSTR)topic ) );
}

/*
 * DisplayHelpContextHH -- This routine returns true if ?
 */

static bool DisplayHelpContextHH( gui_help_instance inst, HWND hwnd, const char *file, const char *topic )
{
    GUIlog_entering_bool_function ();

    inst=inst;
    return( WHtmlHelp( hwnd, file, (UINT)HELP_CONTEXT, (HELP_DATA)(LPCSTR)topic ) );
}

/*
 * DisplayHelpKeyHH -- This routine returns true if ?
 */

static bool DisplayHelpKeyHH( gui_help_instance inst, HWND hwnd, const char *file, const char *topic )
{
    GUIlog_entering_bool_function ();

    inst = inst;
    return( WHtmlHelp( hwnd, file, (UINT)HELP_KEY, (HELP_DATA)(LPCSTR)topic ) );
}
 #endif  // of #if defined( __NT__ )
#endif  // of #else for #ifdef __OS2_PM__

/*
 * GUIHelpInit -- ?
 */

gui_help_instance GUIAPI GUIHelpInit( gui_window *wnd, const char *file, const char *title )
{
    GUIlog_entering_gui_help_instance_function ();

    return( InitHelp( wnd->hwnd, GUIMainHInst, title, file ) );
}


/*
 * GUIHelpFini -- ?
 */

void GUIAPI GUIHelpFini( gui_help_instance inst, gui_window *wnd, const char *file )
{
    GUIlog_entering_void_function ();

    FiniHelp( inst, wnd->hwnd, file );
}

/*
 * GUIShowHelp -- This routine returns true if ?
 */

bool GUIAPI GUIShowHelp( gui_help_instance inst, gui_window *wnd, gui_help_actions act,
                  const char *file, const char *topic )
{
    bool        ret;

    GUIlog_entering_bool_function ();

    ret = false;

    switch( act ) {
    case GUI_HELP_CONTENTS:
        ret = DisplayContents( inst, wnd->hwnd, file );
        break;
    case GUI_HELP_ON_HELP:
        ret = DisplayHelpOnHelp( inst, wnd->hwnd, file );
        break;
    case GUI_HELP_SEARCH:
        ret = DisplayHelpSearch( inst, wnd->hwnd, file, topic );
        break;
    case GUI_HELP_CONTEXT:
        ret = DisplayHelpContext( inst, wnd->hwnd, file, topic );
        break;
    case GUI_HELP_KEY:
        ret = DisplayHelpKey( inst, wnd->hwnd, file, topic );
        break;
    }

    return( ret );
}

/*
 * GUIShowHtmlHelp -- This routine returns true if ?
 */

bool GUIAPI GUIShowHtmlHelp( gui_help_instance inst, gui_window *wnd, gui_help_actions act, const char *file, const char *topic )
{
    bool        ret;

#ifndef __NT__
    /* unused parameters */ (void)inst; (void)wnd; (void)act; (void)file; (void)topic;
#endif  // of #ifndef __NT__

    GUIlog_entering_bool_function ();

    ret = false;

#ifdef __OS2_PM__
#elif defined( __NT__ )
    switch( act ) {
    case GUI_HELP_CONTENTS:
        ret = DisplayContentsHH( inst, wnd->hwnd, file );
        break;
    case GUI_HELP_SEARCH:
        ret = DisplayHelpSearchHH( inst, wnd->hwnd, file, topic );
        break;
    case GUI_HELP_CONTEXT:
        ret = DisplayHelpContextHH( inst, wnd->hwnd, file, topic );
        break;
    case GUI_HELP_KEY:
        ret = DisplayHelpKeyHH( inst, wnd->hwnd, file, topic );
        break;
    }
#endif  // of #elif defined( __NT__ )
    return( ret );
}

/*
 * GUIDisplayHelp -- This routine returns true if ?
 */

bool GUIAPI GUIDisplayHelp( gui_window *wnd, const char *file, const char *topic )
{
    GUIlog_entering_bool_function ();

#ifdef __OS2_PM__
    wnd = wnd;
    file = file;
    topic = topic;
    return( false );
#else  // of #ifdef __OS2_PM__
    if( topic == NULL ) {
        return( WWinHelp( wnd->hwnd, file, (UINT)HELP_INDEX, 0 ) );
    } else {
        return( WWinHelp( wnd->hwnd, file, (UINT)HELP_KEY, (HELP_DATA)(LPCSTR)topic ) );
    }
#endif  // of #else for #ifdef __OS2_PM__
}

/*
 * GUIDisplayHelpWin4 -- This routine returns true if ?
 */

bool GUIAPI GUIDisplayHelpWin4( gui_window *wnd, const char *file, const char *topic )
{
    GUIlog_entering_bool_function ();

#ifdef __OS2_PM__
    wnd = wnd;
    file = file;
    topic = topic;
    return( false );
#else  // of #ifdef __OS2_PM__
    if( topic == NULL ) {
  #if defined( __NT__ )
    #if !defined( _WIN64 )
        DWORD   version;

        version = GetVersion();
        version = 100 * LOBYTE(LOWORD(version)) + HIBYTE(LOWORD(version));
        if( version < 351 ) {
            return( WWinHelp( wnd->hwnd, file, (UINT)HELP_INDEX, 0 ) );
        }
    #endif  // of #if !defined( _WIN64 )
        // NT 3.51 or higher
        return( WWinHelp( wnd->hwnd, file, (UINT)HELP_FINDER, 0 ) );
  #else  // of #if defined( __NT__ )
        return( WWinHelp( wnd->hwnd, file, (UINT)HELP_INDEX, 0 ) );
  #endif  // of #else for #if defined( __NT__ )
    } else {
        return( WWinHelp( wnd->hwnd, file, (UINT)HELP_KEY, (HELP_DATA)(LPCSTR)topic ) );
    }
#endif  // of #else for #ifdef __OS2_PM__
}

/*
 * GUIDisplayHelpId -- This routine returns true if ?
 */

bool GUIAPI GUIDisplayHelpId( gui_window *wnd, const char *file, gui_hlp_id id )
{
    GUIlog_entering_bool_function ();

#ifdef __OS2_PM__
    wnd = wnd;
    file = file;
    id = id;
    return( false );
#else  // of #ifdef __OS2_PM__
    return( WWinHelp( wnd->hwnd, file, (UINT)HELP_CONTEXT, (HELP_DATA)id ) );
#endif  // of #else for #ifdef __OS2_PM__
}
