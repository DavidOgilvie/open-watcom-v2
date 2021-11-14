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
#if !defined(__OS2_PM__) && !defined(__WINDOWS_386__)
	#include <commdlg.h>
#endif  // of #if !defined(__OS2_PM__) && !defined(__WINDOWS_386__)
#include "guifont.h"
#include "fontstr.h"
#include "guiutil.h"
#include "guixutil.h"
#include "guiscrol.h"
#include "guilog.h"


#define MAX_STR 256


/*
 * SetFont -- ?
 */

#ifndef __OS2_PM__
static void SetFont( gui_window *wnd, HFONT font )
{
	GUIlog_entering_function ();
    wnd->font = font;
    GUISetRowCol( wnd, NULL );
    GUISetScroll( wnd );
    GUIEVENT( wnd, GUI_FONT_CHANGED, NULL );
}

/*
 * GUIChooseFont -- This routine returns true if ?
 */

static bool GUIChooseFont( HFONT font, LOGFONT *lf, HWND hwnd )
{
	GUIlog_entering_function ();
 #ifdef __OS2_PM__
    hwnd = hwnd;
    lf = lf;
    font = font;
    return( false );
 #else  // of #ifdef __OS2_PM__
    CHOOSEFONT  cf;
    bool        ret;
  #if defined(__WINDOWS__)
    HINSTANCE   h;
    FARPROC     func;
   #ifdef __WINDOWS_386__
    HINDIR      hIndir;
    DWORD       lfAlias;
   #endif  // of #ifdef __WINDOWS_386__
  #endif  // of #if defined(__WINDOWS__)

    memset( &cf, 0, sizeof( CHOOSEFONT ) );

    cf.Flags = CF_SCREENFONTS;
    if( font != NULL ) {
        GetObject( font, sizeof( LOGFONT ), (LPSTR) lf );
        cf.Flags |= CF_INITTOLOGFONTSTRUCT;
    }

  #ifndef __WINDOWS_386__
    cf.lpLogFont = lf;
  #endif  // of #ifndef __WINDOWS_386__
    cf.lStructSize = sizeof( CHOOSEFONT );
    cf.hwndOwner = hwnd;

  #if defined(__NT__)
    ret = ChooseFont( &cf ) != 0;
  #else  // of #if defined(__NT__)
    h = LoadLibrary( "COMMDLG.DLL" );
    if( (UINT)h < 32 ) {
        return( false );
    }
    func = GetProcAddress( h, "ChooseFont" );
    if( func == NULL ) {
        return( false );
    }
   #ifdef __WINDOWS_386__
    hIndir = GetIndirectFunctionHandle( func, INDIR_PTR, INDIR_ENDLIST );
    if( hIndir == NULL ) {
        FreeLibrary( h );
        return( false );
    }
    lfAlias = AllocAlias16( (void *)lf );
    cf.lpLogFont = (LOGFONT *)lfAlias;
    ret = (short)InvokeIndirectFunction( hIndir, &cf ) != 0;
    if( lfAlias != 0 ) {
        FreeAlias16( lfAlias );
    }
    FreeIndirectFunctionHandle( hIndir );
   #else  // of #ifdef __WINDOWS_386__
    ret = ((BOOL(WINAPI *)(LPCHOOSEFONT))func)( &cf ) != 0;
   #endif  // of #else for #ifdef __WINDOWS_386__
    FreeLibrary( h );
  #endif  // of #else for #if defined(__NT__)
    return( ret );
 #endif  // of #else for #ifdef __OS2_PM__
}
#endif  // of #ifndef __OS2_PM__

/*
 * GUIChangeFont -- This routine returns true if ?
 */

bool GUIAPI GUIChangeFont( gui_window *wnd )
{
#ifndef __OS2_PM__
    LOGFONT     lf;
    HFONT       font;

	GUIlog_entering_function ();
    if( !GUIChooseFont( wnd->font, &lf, wnd->hwnd ) ) {
        return( false );
    }
    font = CreateFontIndirect( &lf );
    if( font == NULL ) {
        return( false );
    }
    DeleteObject( wnd->font );
    SetFont( wnd, font );
    GUIWndDirty( wnd );
    return( true );
#else  // of #ifndef __OS2_PM__
	GUIlog_entering_function ();
    wnd = wnd;
    return( false );
#endif  // of #else for #ifndef __OS2_PM__
}

/*
 * GetFontInfo -- This routine returns a character string containing ?
 */

#ifndef __OS2_PM__
static char *GetFontInfo( LOGFONT *lf )
{
    char                buff[MAX_STR];

	GUIlog_entering_function ();
    GetFontFormatString( lf, buff );
    return( GUIStrDup( buff, NULL ) );
}
#endif  // of #ifndef __OS2_PM__

/*
 * GUIGetFontInfo -- This routine returns a character string containing ?
 */

char * GUIAPI GUIGetFontInfo( gui_window *wnd )
{
#ifndef __OS2_PM__
    LOGFONT             lf;

	GUIlog_entering_function ();
    if( GetObject( wnd->font, sizeof( LOGFONT ), (LPSTR) &lf ) == 0 ) {
        return( NULL );
    }
    return( GetFontInfo( &lf ) );
#else  // of #ifndef __OS2_PM__
	GUIlog_entering_function ();
    wnd = wnd;
    return( NULL );
#endif  // of #else for #ifndef __OS2_PM__
}

/*
 * GUIGetFontFromUser -- This routine returns true if it can create font
 *                       dialog to get font info from use, initializing with
 *                       font info given
 */

char * GUIAPI GUIGetFontFromUser( char *fontinfo )
{
#ifndef __OS2_PM__
    LOGFONT     lf;
    HFONT       font;

	GUIlog_entering_function ();
    font = NULLHANDLE;
    if( fontinfo != NULL ) {
        GetLogFontFromString( &lf, fontinfo );
        font = CreateFontIndirect( &lf );
        fontinfo = NULL;
    }
    if( GUIChooseFont( font, &lf, NULLHANDLE ) ) {
        fontinfo = GetFontInfo( &lf );
    }
    if( font != NULL ) {
        DeleteObject( font );
    }
    return( fontinfo );
#else  // of #ifndef __OS2_PM__
	GUIlog_entering_function ();
    fontinfo = fontinfo;
    return( NULL );
#endif  // of #else for #ifndef __OS2_PM__
}

/*
 * GUISetFontInfo -- This routine returns true if ?
 */

bool GUIAPI GUISetFontInfo( gui_window *wnd, char *fontinfo )
{
#ifndef __OS2_PM__
    HFONT       font;
    LOGFONT     lf;

	GUIlog_entering_function ();
    if( fontinfo == NULL ) {
        return( false );
    }
    GetLogFontFromString( &lf, fontinfo );
    font = CreateFontIndirect( &lf );
    if( font == NULL ) {
        return( false );
    }
    if( wnd->font != NULL ) {
        DeleteObject( wnd->font );
    }
    SetFont( wnd, font );
    return( true );
#else  // of #ifndef __OS2_PM__
	GUIlog_entering_function ();
    wnd = wnd;
    fontinfo = fontinfo;
    return( false );
#endif  // of #else for #ifndef __OS2_PM__
}

/*
 * GUIFontsSupported -- This routine returns true if ?
 */

bool GUIAPI GUIFontsSupported( void )
{
	GUIlog_entering_function ();
#ifndef __OS2_PM__
    return( true );
#else  // of #ifndef __OS2_PM__
    return( false );
#endif  // of #else for #ifndef __OS2_PM__
}

/*
 * GUISetSystemFont -- This routine returns true if ?
 */

bool GUIAPI GUISetSystemFont( gui_window *wnd, bool fixed )
{
#ifndef __OS2_PM__
    HFONT               font;
 #ifdef __NT__
    NONCLIENTMETRICS    ncm;
 #endif  // of #ifdef __NT__

	GUIlog_entering_function ();
    if( fixed ) {
        font = GetStockObject( SYSTEM_FIXED_FONT );
    } else {
 #ifdef __NT__
        ncm.cbSize = sizeof( NONCLIENTMETRICS );
        SystemParametersInfo( SPI_GETNONCLIENTMETRICS, sizeof( NONCLIENTMETRICS ),
                              &ncm, 0 );
        font = CreateFontIndirect( &ncm.lfMessageFont );
 #else  // of #ifdef __NT__
        font = GetStockObject( SYSTEM_FONT );
 #endif  // of #else for #ifdef __NT__
    }
    if( wnd->font != NULL ) {
        DeleteObject( wnd->font );
    }
    SetFont( wnd, font );
    return( true );
#else  // of #ifndef __OS2_PM__
    wnd = wnd;
    fixed = fixed;
    return( false );
#endif  // of #else for #ifndef __OS2_PM__
}
