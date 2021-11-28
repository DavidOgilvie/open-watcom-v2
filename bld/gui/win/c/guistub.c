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
#include "guilog.h"


/*
 * GUISetBetweenTitles -- ?
 */

void GUIAPI GUISetBetweenTitles( int between_titles )
{
    GUIlog_entering_void_function ();

    (void)between_titles;
}

/*
 * GUIGetCursorPos -- This routine returns true if ?
 */

bool GUIAPI GUIGetCursorPos( gui_window *wnd, gui_point *point )
{
    GUIlog_entering_bool_function ();

    (void)wnd;
    (void)point;
    return( false );
}

/*
 * GUISetCursorPos -- This routine returns true if ?
 */

bool GUIAPI GUISetCursorPos( gui_window *wnd, const gui_point *point )
{
    GUIlog_entering_bool_function ();

    (void)wnd;
    (void)point;
    return( false );
}

/*
 * GUIGetCursorType -- This routine returns true if ?
 */

bool GUIAPI GUIGetCursorType( gui_window *wnd, gui_cursor_type *cursor )
{
    GUIlog_entering_bool_function ();

    (void)wnd;
    (void)cursor;
    return( false );
}

/*
 * GUISetCursorType -- This routine returns true if ?
 */

bool GUIAPI GUISetCursorType( gui_window *wnd, gui_cursor_type cursor )
{
    GUIlog_entering_bool_function ();

    (void)wnd;
    (void)cursor;
    return( false );
}

/*
 * GUISetBackgroundChar -- This routine returns true if ?
 */

bool GUIAPI GUISetBackgroundChar( gui_window *wnd, char background )
{
    GUIlog_entering_bool_function ();

    (void)wnd;
    (void)background;
    return( false );
}

/*
 * GUIGMouseOn -- ?
 */

void GUIAPI GUIGMouseOn( void )
{
    GUIlog_entering_void_function ();
}

/*
 * GUIGMouseOff -- ?
 */

void GUIAPI GUIGMouseOff( void )
{
    GUIlog_entering_void_function ();
}

/*
 * GUISetBackgroundColour -- ?
 */

void GUIAPI GUISetBackgroundColour( gui_colour_set *colour )
{
    GUIlog_entering_void_function ();

    (void)colour;
}

/*
 * GUISetDialogColours -- ?
 */

void GUIAPI GUISetDialogColours( gui_colour_set *colours )
{
    GUIlog_entering_void_function ();

    (void)colours;
}

/*
 * GUIGetDialogColours -- ?
 */

void GUIAPI GUIGetDialogColours( gui_colour_set *colours )
{
    GUIlog_entering_void_function ();

    (void)colours;
}

/*
 * GUISetCharacter -- ?
 */

void GUIAPI GUISetCharacter( gui_draw_char draw_char, int new )
{
    GUIlog_entering_void_function ();

    (void)draw_char;
    (void)new;
}

/*
 * GUIGetCharacter -- This routine returns an integer value representing ?
 */

int GUIAPI GUIGetCharacter( gui_draw_char draw_char )
{
    GUIlog_entering_int_function ();

    (void)draw_char;
    return( ' ');
}
