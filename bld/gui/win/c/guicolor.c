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
* Description:  GUI lib color handling.
*
****************************************************************************/


#if defined __WINDOWS__ && defined __GUI_IS_GUI__
#include <winuser.h>
#endif
#include "guiwind.h"	// in <OWROOT>\bld\gui\win\h\guiwind.h
#include <string.h>
#if defined(__WINDOWS__) && !defined(__WINDOWS_386__)
#include <commdlg.h>	// In <OWROOT>\bld\w16api\wini86\commdlg.h
#endif
#include "guicolor.h"	// in <OWROOT>\bld\gui\win\h\guicolor.h
#include "guiwnclr.h"	// in <OWROOT>\bld\gui\h\guiwnclr.h
#include "guixwind.h"	// in <OWROOT>\bld\gui\win\h\guixwind.h
#include "guilog.h"


void GUIDoSysColorChange ( gui_window * );

/***************************************************************/
// Variables used in guicolor.c and throughout this gui libary
// gui_colour 
//		Size: GUI_NUM_COLOURS
//			Type: last element of the enum gui_colour
//			Deined in:	
//		Type: WPI_COLOUR
//			Defined in:	gui\ui\gui.h
//			Defined as type: COLOR
//		Purpose: This contains a list of standard colour names and
//			RGB values as well as the RGB values for all Windows 
//			screen elements that can be obtained through GetSysColour
//			in the routine InitSystemRGB (see below)
// gui_colour_set 
//		Size: GUI_NUM_ATTRS
//		Defined in: gui\c\guiwnclr.c
//		Type: (fore RGB, back RGB)
//		Purpose: The foreground and packground colours of a particular 
//			display element.

// GUIColors contaus GUI_NUM_COLOURS elemets.  The colour names are
// defined in \ow2.0\bld\gui\h\gui.h.  Since RBG colour values are
// the same in all platforms, they only need to be defined once.
/******************************************************************/

WPI_COLOUR GUIColours[] = {

#ifdef __OS2_PM__
//      R G B	// Leave OS2 with colours for now
    0x00000000, // GUI_BLACK 0
    0x00000080, // GUI_BLUE 1
    0x00008000, // GUI_GREEN 2
    0x00008080, // GUI_CYAN 3
    0x00C00000, // GUI_RED 4
    0x00800080, // GUI_MAGENTA 5
    0x00808000, // GUI_BROWN 6
    0x00cccccc, // GUI_WHITE 7
    0x00808080, // GUI_GREY 8
    0x000000ff, // GUI_BR_BLUE 9
    0x0000ff00, // GUI_BR_GREEN 10
    0x0000ffff, // GUI_BR_CYAN 11
    0x00ff0000, // GUI_BR_RED 12
    0x00ff00ff, // GUI_BR_MAGENTA 13
    0x00ffff00, // GUI_BR_YELLOW 14
    0x00ffffff,  // GUI_BR_WHITE 15
// These are used in Windows but I'll put them in for compatibility
// All of the following values will be set in InitSystemRGB
    0x00808080, // GUIEX_3DDKSHADOW,
    0x00000000, // GUIEX_3DFACE,
    0x00000000, // GUIEX_3DHIGHLIGHT,
    0x00808080, // GUIEX_3DHILIGHT,
    0x00000000, // GUIEX_3DLIGHT,
    0x00808080, // GUIEX_3DSHADOW,
    0x00000000, // GUIEX_ACTIVEBORDER,
    0x00808080, // GUIEX_ACTIVECAPTION,
    0x00000000, // GUIEX_APPWORKSPACE,
    0x00808080, // GUIEX_BACKGROUND,
    0x00000000, // GUIEX_BTNFACE,
    0x00808080, // GUIEX_BTNHIGHLIGHT,
    0x00000000, // GUIEX_BTNHILIGHT,
    0x00808080, // GUIEX_BTNSHADOW,
    0x00000000, // GUIEX_BTNTEXT,
    0x00808080, // GUIEX_CAPTIONTEXT,
    0x00000000, // GUIEX_DESKTOP,
    0x00808080, // GUIEX_DLG_BACKGRND,
    0x00000000, // GUIEX_DLG_BKGRND,
    0x00808080, // GUIEX_DLG_TEXT,
    0x00000000, // GUIEX_FRAME_ACTIVE,
    0x00000000, // GUIEX_FRAME_INACTIVE,
    0x00808080, // GUIEX_GRADIENTACTIVECA
    0x00000000, // GUIEX_GRADIENTINACTIVE
    0x00000000, // GUIEX_GRAYTEXT,
    0x00808080, // GUIEX_HIGHLIGHT,
    0x00000000, // GUIEX_HIGHLIGHT_TEXT,
    0x00808080, // GUIEX_HIGHLIGHTTEXT,
    0x00000000, // GUIEX_HIGHLITE,
    0x00808080, // GUIEX_HIGHLITE_TEXT,
    0x00000000, // GUIEX_HIGHLITETEXT,
    0x00808080, // GUIEX_HOTLIGHT,
    0x00000000, // GUIEX_HOTLITE,
    0x00808080, // GUIEX_INACTIVEBORDER,
    0x00000000, // GUIEX_INACTIVECAPTION,
    0x00808080, // GUIEX_INACTIVECAPTIONT
    0x00000000, // GUIEX_INFO_BACKGROUND,
    0x00808080, // GUIEX_INFO_TEXT,
    0x00000000, // GUIEX_INFOBACKGROUND,
    0x00808080, // GUIEX_INFOBK,
    0x00000000, // GUIEX_INFOTEXT,
    0x00808080, // GUIEX_MENU,
    0x00808080, // GUIEX_MENU_INACTIVE_TE
    0x00000000, // GUIEX_MENU_TEXT,
    0x00808080, // GUIEX_MENU_TEXT_GRAYED
    0x00000000, // GUIEX_MENUBAR,
    0x00808080, // GUIEX_MENUHILIGHT,
    0x00000000, // GUIEX_MENUTEXT,
    0x00808080, // GUIEX_SCROLLBAR,
    0x00000000, // GUIEX_WINDOW,
    0x00808080, // GUIEX_WINDOWFRAME,
    0x00000000, // GUIEX_WINDOWTEXT,
    0x00808080, // GUIEX_WINDOW_TEXT,
    0x00000000, // GUIEX_WND_BKGRND,
    0x00808080  // GUIEX_WND_TEXT,
#else  // For Windows, include all GetSystemColor values that are available
//      B G R
    0x00000000, // GUI_BLACK 0
    0x00800000, // GUI_BLUE 1
    0x00008000, // GUI_GREEN 2
    0x00808000, // GUI_CYAN 3
    0x000000C0, // GUI_RED 4
    0x00800080, // GUI_MAGENTA 5
    0x00008080, // GUI_BROWN 6
    0x00c0c0c0, // GUI_WHITE 7
    0x00808080, // GUI_GREY 8
    0x00ff0000, // GUI_BR_BLUE 9
    0x0000ff00, // GUI_BR_GREEN 10
    0x00ffff00, // GUI_BR_CYAN 11
    0x000000ff, // GUI_BR_RED 12
    0x00ff00ff, // GUI_BR_MAGENTA 13
    0x0000ffff, // GUI_BR_YELLOW 14
	0x00ffffff, // GUI_BR_WHITE 15
// All of the following values will be set in InitSystemRGB
    0x00000000, // GUIEX_3DDKSHADOW,
    0x00808080, // GUIEX_3DFACE,
    0x00000000, // GUIEX_3DHIGHLIGHT,
    0x00000000, // GUIEX_3DHILIGHT,
    0x00808080, // GUIEX_3DLIGHT,
    0x00000000, // GUIEX_3DSHADOW,
    0x00808080, // GUIEX_ACTIVEBORDER,
    0x00000000, // GUIEX_ACTIVECAPTION,
    0x00808080, // GUIEX_APPWORKSPACE,
    0x00000000, // GUIEX_BACKGROUND,
    0x00808080, // GUIEX_BTNFACE,
    0x00000000, // GUIEX_BTNHIGHLIGHT,
    0x00808080, // GUIEX_BTNHILIGHT,
    0x00000000, // GUIEX_BTNSHADOW,
    0x00000000, // GUIEX_BTNTEXT,
    0x00808080, // GUIEX_CAPTIONTEXT,
    0x00000000, // GUIEX_DESKTOP,
    0x00808080, // GUIEX_DLG_BACKGRND,
    0x00000000, // GUIEX_DLG_BKGRND,
    0x00808080, // GUIEX_DLG_TEXT,
    0x00000000, // GUIEX_FRAME_ACTIVE,
    0x00000000, // GUIEX_FRAME_INACTIVE,
    0x00808080, // GUIEX_GRADIENTACTIVECAPTION,
    0x00000000, // GUIEX_GRADIENTINACTIVECAPTION,
    0x00000000, // GUIEX_GRAYTEXT,
    0x00808080, // GUIEX_HIGHLIGHT,
    0x00000000, // GUIEX_HIGHLIGHT_TEXT,
    0x00808080, // GUIEX_HIGHLIGHTTEXT,
    0x00000000, // GUIEX_HIGHLITE,
    0x00808080, // GUIEX_HIGHLITE_TEXT,
    0x00000000, // GUIEX_HIGHLITETEXT,
    0x00000000, // GUIEX_HOTLIGHT,
    0x00808080, // GUIEX_HOTLITE,
    0x00000000, // GUIEX_INACTIVEBORDER,
    0x00000000, // GUIEX_INACTIVECAPTION,
    0x00808080, // GUIEX_INACTIVECAPTIONTEXT,
    0x00000000, // GUIEX_INFO_BACKGROUND,
    0x00808080, // GUIEX_INFO_TEXT,
    0x00000000, // GUIEX_INFOBACKGROUND,
    0x00808080, // GUIEX_INFOBK,
    0x00000000, // GUIEX_INFOTEXT,
    0x00000000, // GUIEX_MENU,
    0x00808080, // GUIEX_MENU_INACTIVE_TEXT,
    0x00000000, // GUIEX_MENU_TEXT,
    0x00808080, // GUIEX_MENU_TEXT_GRAYED,
    0x00000000, // GUIEX_MENUBAR,
    0x00808080, // GUIEX_MENUHILIGHT,
    0x00000000, // GUIEX_MENUTEXT,
    0x00808080, // GUIEX_SCROLLBAR,
    0x00000000, // GUIEX_WINDOW,
    0x00808080, // GUIEX_WINDOWFRAME,
    0x00000000, // GUIEX_WINDOWTEXT,
    0x00808080, // GUIEX_WINDOW_TEXT,
    0x00000000, // GUIEX_WND_BKGRND,
    0x00808080  // GUIEX_WND_TEXT,
#endif             
};

void SetTextColorByScheme( gui_window *wnd, WPI_COLOUR fore, WPI_COLOUR back );
void InitRootWindowRGB ( gui_window *wnd );

#ifndef __OS2_PM__
void InitSystemRGB( void )
{
/*****************************************************
// From WINuSER.H, these are the values for each of the 
//	Code									Value
	COLOR_SCROLLBAR                     	0
	COLOR_BACKGROUND                   		1
	COLOR_ACTIVECAPTION                 	2
	COLOR_INACTIVECAPTION               	3
	COLOR_MENU                          	4
	COLOR_WINDOW                        	5
	COLOR_WINDOWFRAME                   	6
	COLOR_MENUTEXT                      	7
	COLOR_WINDOWTEXT                    	8
	COLOR_CAPTIONTEXT                   	9
	COLOR_ACTIVEBORDER                  	10
	COLOR_INACTIVEBORDER                	11
	COLOR_APPWORKSPACE                  	12
	COLOR_HIGHLIGHT                     	13
	COLOR_HIGHLIGHTTEXT                 	14
	COLOR_BTNFACE                       	15
	COLOR_BTNSHADOW                     	16
	COLOR_GRAYTEXT                      	17
	COLOR_BTNTEXT                       	18
	COLOR_INACTIVECAPTIONTEXT           	19
	COLOR_BTNHIGHLIGHT                  	20
#if (WINVER >= 0x0400)
    #define COLOR_3DDKSHADOW            	21
    #define COLOR_3DLIGHT               	22
    #define COLOR_INFOTEXT              	23
    #define COLOR_INFOBK                	24
#endif
#if (WINVER >= 0x0500)
    #define COLOR_HOTLIGHT                  26
    #define COLOR_GRADIENTACTIVECAPTION     27
    #define COLOR_GRRDIENTINACTIVECAPTION   28
#endif
//#if (WINVER >= 0x0501)
    #define COLOR_MENUHILIGHT               29
    #define COLOR_MENUBAR                   30
#endif
// The following are aliases for some of the ocdes
#if (WINVER >= 0x0400)
    #define COLOR_DESKTOP                   COLOR_BACKGROUND
    #define COLOR_3DFACE                    COLOR_BTNFACE
    #define COLOR_3DSHADOW                  COLOR_BTNSHADOW
    #define COLOR_3DHIGHLIGHT               COLOR_BTNHIGHLIGHT
    #define COLOR_3DHILIGHT                 COLOR_BTNHIGHLIGHT
    #define COLOR_BTNHILIGHT                COLOR_BTNHIGHLIGHT
#endif  // Of info from WINUSER.H
******************************************************************/
	GUIlog ("Entered %s %s(%d)\n", __func__, __FILE__, __LINE__ );
// These aren't available outside of Windows
#if (winver >= 0x0400)
	GUIColours[GUIEX_3DDKSHADOW]= 			GetSysColor( COLOR_3DDKSHADOW ); // 21
	GUIColours[GUIEX_3DFACE]= 				GetSysColor( COLOR_3DFACE ); // 15
	GUIColours[GUIEX_3DHIGHLIGHT]= 			GetSysColor( COLOR_3DHIGHLIGHT ); // 20
	GUIColours[GUIEX_3DHILIGHT]= 			GetSysColor( COLOR_3DHILIGHT ); //20
	GUIColours[GUIEX_3DLIGHT]= 				GetSysColor( COLOR_3DLIGHT ); // 22
	GUIColours[GUIEX_3DSHADOW]= 			GetSysColor( COLOR_3DSHADOW ); // 16
#endif
GUIColours[GUIEX_ACTIVEBORDER]= 			GetSysColor( COLOR_ACTIVEBORDER ); // 10
GUIColours[GUIEX_ACTIVECAPTION]=			GetSysColor( COLOR_ACTIVECAPTION ); // 2
GUIColours[GUIEX_APPWORKSPACE]= 			GetSysColor( COLOR_APPWORKSPACE ); // 12
GUIColours[GUIEX_BACKGROUND]= 				GetSysColor( COLOR_BACKGROUND ); // 1
GUIColours[GUIEX_BTNFACE]= 					GetSysColor( COLOR_BTNFACE ); // 15
GUIColours[GUIEX_BTNHIGHLIGHT]= 			GetSysColor( COLOR_BTNHIGHLIGHT ); // 20
#ifndef __WINDOWS__
// These aren't available to this OS
GUIColours[GUIEX_BTNHILIGHT]= 				GetSysColor( COLOR_BTNHILIGHT ); // 20
#endif
GUIColours[GUIEX_BTNSHADOW]= 				GetSysColor( COLOR_BTNSHADOW ); // 16
GUIColours[GUIEX_BTNTEXT]= 					GetSysColor( COLOR_BTNTEXT ); // 18
GUIColours[GUIEX_CAPTIONTEXT]= 				GetSysColor( COLOR_CAPTIONTEXT ); // 9
#ifndef __WINDOWS__
// These aren't available to this OS
GUIColours[GUIEX_DESKTOP]= 					GetSysColor( COLOR_DESKTOP ); // 1
#endif
GUIColours[GUIEX_DLG_BACKGRND]= 			GetSysColor( COLOR_BTNFACE ); // 15
GUIColours[GUIEX_DLG_BKGRND]= 				GetSysColor( COLOR_BTNFACE ); // 15
GUIColours[GUIEX_DLG_TEXT]= 				GetSysColor( COLOR_BTNTEXT ); // 18
GUIColours[GUIEX_FRAME_ACTIVE]= 			GetSysColor( COLOR_WINDOWFRAME ); // 6
GUIColours[GUIEX_FRAME_INACTIVE]= 			GetSysColor( COLOR_INACTIVEBORDER ); // 11
#if (WINVER >= 0x0500)
GUIColours[GUIEX_GRADIENTACTIVECAPTION]= 	GetSysColor( COLOR_GRADIENTACTIVECAPTION ); // 27
GUIColours[GUIEX_GRADIENTINACTIVECAPTION]= 	GetSysColor( COLOR_GRADIENTINACTIVECAPTION ); // 28
#endif
GUIColours[GUIEX_GRAYTEXT]= 				GetSysColor( COLOR_GRAYTEXT ); // 17
GUIColours[GUIEX_HIGHLIGHT]= 				GetSysColor( COLOR_HIGHLIGHT ); // 13
GUIColours[GUIEX_HIGHLIGHT_TEXT]= 			GetSysColor( COLOR_HIGHLIGHTTEXT );  // 14
GUIColours[GUIEX_HIGHLIGHTTEXT]= 			GetSysColor( COLOR_HIGHLIGHTTEXT ); // 14
GUIColours[GUIEX_HIGHLITE]= 				GetSysColor( COLOR_HIGHLIGHT ); // 13
GUIColours[GUIEX_HIGHLITE_TEXT]= 			GetSysColor( COLOR_HIGHLIGHTTEXT ); // 14
GUIColours[GUIEX_HIGHLITETEXT]= 			GetSysColor( COLOR_HIGHLIGHTTEXT ); // 14
#if (WINVER >= 0x0500)
GUIColours[GUIEX_HOTLITE]= 					GetSysColor( COLOR_HOTLIGHT ); // 26
GUIColours[GUIEX_HOTLIGHT]= 				GetSysColor( COLOR_HOTLIGHT ); // 26
#endif
GUIColours[GUIEX_INACTIVEBORDER]= 			GetSysColor( COLOR_INACTIVEBORDER ); // 11
GUIColours[GUIEX_INACTIVECAPTION]= 			GetSysColor( COLOR_INACTIVECAPTION ); // 3
GUIColours[GUIEX_INACTIVECAPTIONTEXT]= 		GetSysColor( COLOR_INACTIVECAPTIONTEXT ); // 19
#ifndef __WINDOWS__
// These aren't available to this OS
GUIColours[GUIEX_INFO_BACKGROUND]= 			GetSysColor( COLOR_INFOBK ); // 24
GUIColours[GUIEX_INFO_TEXT]= 				GetSysColor( COLOR_INFOTEXT ); // 23
GUIColours[GUIEX_INFOBACKGROUND]= 			GetSysColor( COLOR_INFOBK ); // 24
GUIColours[GUIEX_INFOBK]= 					GetSysColor( COLOR_INFOBK ); // 24
GUIColours[GUIEX_INFOTEXT]= 				GetSysColor( COLOR_INFOTEXT ); // 23
#endif
GUIColours[GUIEX_MENU]= 					GetSysColor( COLOR_MENU ); // 4
GUIColours[GUIEX_MENU_INACTIVE_TEXT]= 		GetSysColor( COLOR_GRAYTEXT ); // 17
GUIColours[GUIEX_MENU_TEXT]= 				GetSysColor( COLOR_MENUTEXT ); // 7
GUIColours[GUIEX_MENU_TEXT_GRAYED]= 		GetSysColor( COLOR_GRAYTEXT ); // 17
#if (WINVER >= 0x0501)
GUIColours[GUIEX_MENUBAR]= 					GetSysColor( COLOR_MENUBAR ); // 30
GUIColours[GUIEX_MENUHILIGHT]= 				GetSysColor( COLOR_MENUHILIGHT ); // 29
#endif
GUIColours[GUIEX_MENUTEXT]= 				GetSysColor( COLOR_MENUTEXT ); // 7
GUIColours[GUIEX_SCROLLBAR]= 				GetSysColor( COLOR_SCROLLBAR ); // 0
GUIColours[GUIEX_WINDOW]= 					GetSysColor( COLOR_WINDOW ); // 5
GUIColours[GUIEX_WINDOWFRAME]= 				GetSysColor( COLOR_WINDOWFRAME ); // 6
GUIColours[GUIEX_WINDOWTEXT]= 				GetSysColor( COLOR_WINDOWTEXT ); // 8
GUIColours[GUIEX_WINDOW_TEXT]= 				GetSysColor( COLOR_WINDOWTEXT ); // 8
GUIColours[GUIEX_WND_BKGRND]= 				GetSysColor( COLOR_WINDOW ); // 5
GUIColours[GUIEX_WND_TEXT]= 				GetSysColor( COLOR_WINDOWTEXT ); // 8
}
#endif

/*
	 What can CetSysColor get in Windows?
	-------- 3D elements ------
Text				Background			Purpose
					COLOR_3DDKSHADOW	Dark shadow for 3D display elements.
					COLOR_3DFACE		Face color for 3D display elements 
											and for dialog box backgrounds.
					COLOR_3DHIGHLIGHT	Highlight color for 3D display elements 
											(for edges facing the light source.)
					COLOR_3DHILIGHT		Highlight color for 3D display elements 
											(for edges facing the light source.)
					COLOR_3DLIGHT		Light color for 3D display elements 
											(for edges facing the light source.)
					COLOR_3DSHADOW		Shadow color 
											for 3D display elements (for edges 
											facing away from the light source).
					COLOR_BTNSHADOW		Shadow color for 3D display elements 
											(for edges facing away from the light source).
COLOR_BTNTEXT		COLOR_BTNFACE		Highlight color for 3D display elements 
											(for edges facing the light source.)
	------ Title bar gradient elements ------
Background								Purpose
COLOR_GRADIENTACTIVECAPTION				Right side color in the color gRadient of 
											an active window's title bar.   		
											Use SPI_GETGRADIENTCAPTIONS with the 
											SystemParametersInfo function to determine 
											whether the gradient effect is enabled.
											COLOR_ACTIVECAPTION specifies the left 
											side color.
COLOR_GRADIENTINACTIVECAPTION			Right side color in the color gradient of an 
											inactive window's title bar. 
											COLOR_INACTIVECAPTION specifies the left 
											side color.			
COLOR_GRADIENTINACTIVECAPTION			Right side color in the color gradient of an 
											inactive window's title bar
											COLOR_INACTIVECAPTION specifies the left 
											side color.
	------ Elements common to 2D and 3D objects ------
Text				Background			Purpose
					COLOR_ACTIVEBORDER	Active window border.
COLOR_CAPTIONTEXT	COLOR_ACTIVECAPTION	Active window title bar.
					COLOR_APPWORKSPACE	Background color of MDI applications.
					COLOR_BACKGROUND	Desktop
					COLOR_DESKTOP		Same as COLOR_BACKGROUND
					COLOR_BTNHILIGHT	Highlight color for 3D display elements 
											(for edges facing the light source.)
COLOR_GRAYTEXT							Grayed (disabled) text
COLOR_HIGHLIGHTTEXT	COLOR_HIGHLIGHT		Item(s) selected in a control.
COLOR_HOTLIGHT		COLOR_WINDOW		Color for a hyperlink or hot-tracked item. 
				COLOR_INACTIVEBORDER	Inactive window border.
COLOR_INACTIVECAPTIONTEXT
				COLOR_INACTIVECAPTION	Inactive window caption.  Specifies the 
											left side color in the color 
											gradient of an inactive window's 
											title bar if the gradient effect is 
											enabled.
COLOR_INFOTEXT		COLOR_INFOBK		Background color for tooltip controls.
COLOR_MENUTEXT		COLOR_MENU			Menu background.
					COLOR_MENUHILIGHT	The color used to highlight menu items 
											when the menu appears as a flat menu 
											(see SystemParametersInfo). The 
											highlighted menu item is outlined with 
											COLOR_HIGHLIGHT.  Windows 2000:  This 
											value is not supported.
					COLOR_MENUBAR		The background color for the menu bar when 
											menus appear as flat menus (see 
											SystemParametersInfo). However, 
											COLOR_MENU continues to specify the 
											background color of the menu popup.
					COLOR_SCROLLBAR		Scroll bar gray area.
COLOR_WINDOWTEXT	COLOR_WINDOW		Window background. 
or COLOR_HOTLITE
					COLOR_WINDOWFRAME	Window frame.

					Background			Purpose
*/

bool GUIAPI GUISetRGB( gui_colour colour, gui_rgb rgb )
{
    if( colour < GUI_NUM_COLOURS  ) {
        GUIColours[colour] = GETRGB( rgb );
        return( true );
    }
    return( false );
}

static void FillInRGB( WPI_COLOUR colour, gui_rgb *rgb )
{
    BYTE        r;
    BYTE        g;
    BYTE        b;

    r = GetRValue( colour );
    g = GetGValue( colour );
    b = GetBValue( colour );
    *rgb = GUIRGB( r, g, b );
}

bool GUIAPI GUIGetRGB( gui_colour colour, gui_rgb *rgb )
{
    if( ( colour < GUI_NUM_COLOURS ) && ( rgb != NULL ) ) {
        FillInRGB( GUIColours[colour], rgb );
        return( true );
    }
    return( false );
}

bool GUIAPI GUIGetWndColour( gui_window *wnd, gui_attr attr, gui_colour_set *colour_set )
{
    if( colour_set == NULL ) {
        return( false );
    }
    if( attr < wnd->num_attrs ) {
        colour_set->fore = WNDATTRFG( wnd, attr );
        colour_set->back = WNDATTRBG( wnd, attr );
        return( true );
    }
    return( false );
}

static void SetBKBrush( gui_window *wnd )
{
    static bool sys_rgb_initialized = false;

    if( !sys_rgb_initialized ) {
#ifndef __OS2_PM__
        InitSystemRGB();
		InitRootWindowRGB ( wnd );
#endif
        sys_rgb_initialized = true;
    }

    GUIGetRGB( WNDATTRBG( wnd, GUI_BACKGROUND ), &wnd->bk_rgb );
    wnd->bk_brush = _wpi_createsolidbrush(GUIGetBack( wnd, GUI_BACKGROUND ));
    GUIGetRGB( WNDATTRBG( wnd, GUI_BACKGROUND ), &wnd->bk_rgb );
}

static void ChangeBKBrush( gui_window *wnd )
{
    HBRUSH      prev;
    HBRUSH      curr;

    curr = wnd->bk_brush;
    prev = GUIFreeBKBrush( wnd );
    SetBKBrush( wnd );
#ifndef __OS2_PM__
    if( prev != curr ) {
        /* replce brush if it wasn't really ours */
        SET_HBRBACKGROUND( wnd->hwnd, prev );
    } else {
        SET_HBRBACKGROUND( wnd->hwnd, wnd->bk_brush );
    }
#endif
}

#if 0
void GUICheckBKBrush( gui_window *wnd )
{
    gui_rgb             rgb;
    gui_colour_set      set;

    GUIGetWndColour( wnd, GUI_BACKGROUND, &set );
    GUIGetRGB( set.back, &rgb );
    if( rgb != wnd->bk_rgb ) {
        ChangeBKBrush( wnd );
    }
}
#endif

bool GUIAPI GUISetWndColour( gui_window *wnd, gui_attr attr, gui_colour_set *colour_set )
{
    if( colour_set == NULL ) {
        return( false );
    }
    if( attr < wnd->num_attrs ) {
        WNDATTRFG( wnd, attr ) = colour_set->fore;
        WNDATTRBG( wnd, attr ) = colour_set->back;
        if( attr == GUI_BACKGROUND ) {
            ChangeBKBrush( wnd );
        }
        return( true );
    }
    return( false );
}

bool GUIAPI GUIGetRGBFromUser( gui_rgb init_rgb, gui_rgb *new_rgb )
{
#ifdef __OS2_PM__
    /* unused parameters */ (void)init_rgb; (void)new_rgb;

    return( false );
#else
    CHOOSECOLOR     choose;
    bool            ret;
 #if defined(__WINDOWS__)
    HINSTANCE       h;
    FARPROC         func;
  #ifdef __WINDOWS_386__
    HINDIR          hIndir;
    DWORD           guiColoursAlias;
  #endif
 #endif

    if( new_rgb == NULL ) {
        return( false );
    }
    memset( &choose, 0, sizeof( CHOOSECOLOR ) );
    choose.Flags = CC_PREVENTFULLOPEN;
    choose.hInstance = (HWND)GUIMainHInst;
    choose.Flags |= CC_RGBINIT;
    choose.rgbResult = GETRGB( init_rgb );
 #ifndef __WINDOWS_386__
    choose.lpCustColors = GUIColours;
 #endif
    choose.lStructSize = sizeof( CHOOSECOLOR );

 #if defined(__NT__)
    ret = ( ChooseColor( &choose ) != 0 );
 #else
    h = LoadLibrary( "COMMDLG.DLL" );
    if( (UINT)h < 32 ) {
        return( false );
    }
    func = GetProcAddress( h, "ChooseColor" );
    if( func == NULL ) {
        return( false );
    }
  #ifdef __WINDOWS_386__
    hIndir = GetIndirectFunctionHandle( func, INDIR_PTR, INDIR_ENDLIST );
    if( hIndir == NULL ) {
        FreeLibrary( h );
        return( false );
    }
    guiColoursAlias = AllocAlias16( (void *)GUIColours );
    choose.lpCustColors = (void *)guiColoursAlias;
    ret = (short)InvokeIndirectFunction( hIndir, &choose ) != 0;
    if( guiColoursAlias != 0 ) {
        FreeAlias16( guiColoursAlias );
    }
    FreeIndirectFunctionHandle( hIndir );
  #else
    ret = ((BOOL(WINAPI *)(LPCHOOSECOLOR))func)( &choose ) != 0;
  #endif
    FreeLibrary( h );
 #endif
    if( ret ) {
        FillInRGB( choose.rgbResult, new_rgb );
    }
    return( ret );
#endif
}

/*
 * GUIXSetColours -- record the colours selected by the application
 */

bool GUIXSetColours( gui_window *wnd, int num_attrs, gui_colour_set *colours )
{
    size_t          size;
    gui_colour_set  *attrs;

    if( colours != NULL ) {
        size = sizeof( gui_colour_set ) * num_attrs;
        attrs = (gui_colour_set *)GUIMemAlloc( size );
        if( attrs != NULL ) {
            wnd->attrs = attrs;
            wnd->num_attrs = num_attrs;
            memcpy( attrs, colours, size );
            SetBKBrush( wnd );
            return( true );
        }
    };
    return( false );
}

void GUIXGetWindowColours( gui_window *wnd, gui_colour_set *colours )
{
    memcpy( colours, wnd->attrs, sizeof( gui_colour_set ) * wnd->num_attrs );
}

HBRUSH GUIFreeBKBrush( gui_window * wnd )
{
    HBRUSH brush = NULLHANDLE;

    if( wnd->bk_brush != NULLHANDLE ) {
        /* make sure bk_brush is not the currently the background brush
         * and, therefore, a system resource */
#ifndef __OS2_PM__
        if( wnd->hwnd != NULLHANDLE ) {  /* NULL if create failed */
            brush = SET_HBRBACKGROUND( wnd->hwnd, NULL );
        }
#endif
        _wpi_deletebrush( wnd->bk_brush );
        wnd->bk_brush = NULLHANDLE;
    }
    return( brush );
}

void GUIAPI GUISetWindowColours( gui_window *wnd, int num_colours,
                          gui_colour_set *colours )
{
    GUIFreeColours( wnd );
    GUIFreeBKBrush( wnd );
    GUISetColours( wnd, num_colours, colours );
    GUIWndDirty( wnd );
}

WPI_COLOUR GUIGetFore( gui_window *wnd, gui_attr attr )
{
    return( GUIColours[WNDATTRFG( wnd, attr )] );
}

WPI_COLOUR GUIGetBack( gui_window *wnd, gui_attr attr )
{
    return( GUIColours[WNDATTRBG( wnd, attr )] );
}

void SetTextColorByScheme( gui_window *wnd, WPI_COLOUR fore, WPI_COLOUR back )
{
    _wpi_settextcolor( wnd->hdc, _wpi_getnearestcolor( wnd->hdc, fore ) );
    _wpi_setbackcolour( wnd->hdc, _wpi_getnearestcolor( wnd->hdc , back ) );
}

#ifndef __OS2_PM__
void GUIDoSysColorChange ( gui_window *wnd ) {
	InitSystemRGB (); 
	InitRootWindowRGB ( wnd );
	_wpi_invalidaterect( wnd->hwnd, NULL, TRUE );
	_wpi_sendmessage( wnd->hwnd, WM_PAINT, 0, 0 );
}

// The GUI colour controls only work on windows that are created by 
// the GUI library.  Most routines create thier own root windows.
// This routine finds those root windows and inserts the GUI 
// attribs and colour control on them.
void InitRootWindowRGB ( gui_window *wnd ) {
	HWND	this;
	gui_window	*thiswnd= wnd;			// Root window candidate
	BOOL		DCwas0= false;
	
	this= wnd->hwnd;
	if (!thiswnd->flags&IS_ROOT)
		this= thiswnd->root;

	if (this) {  // This is not a known root so look for the toot
		if (thiswnd->hdc==NULL) {
			thiswnd->hdc= GetDC (this);
			DCwas0= true;
		}
		SetTextColorByScheme( 	thiswnd, 
								GUIGetFore (thiswnd, GUIEX_MENU_TEXT),
								GUIGetBack (thiswnd, GUIEX_MENU));
		_wpi_invalidaterect( this, NULL, TRUE );
		_wpi_sendmessage( this, WM_PAINT, 0, 0 );
		if (DCwas0) {
			ReleaseDC (this, thiswnd->hdc);
			thiswnd->hdc= 0;
			DCwas0= false;
		}
	}
}
#endif
