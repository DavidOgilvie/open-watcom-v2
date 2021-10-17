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
* Description:  Defines basic color scheme for each window component.
*
****************************************************************************/


#include "guiwind.h"	// In <OWROOT>\bld\gui\win\h\guiwind.h
#include <string.h>
#include "guiwnclr.h"	// In <OWROOT>\bld\gui\win\h\guiwnclr.h
#include "guicolor.h"	// In <OWROOT>\bld\gui\win\h\guicolor.h


static gui_colour_set Default[GUI_NUM_ATTRS] =
{
#if defined (__NT__) && defined( GUI_IS_GUI )
    //  fore/text           		backgr. 			Window class
    { GUIEX_MENUTEXT,         	GUIEX_MENU	     	}, // GUI_MENU_PLAIN
    { GUIEX_MENUTEXT,           GUIEX_MENU      	}, // GUI_MENU_STANDOUT
    { GUIEX_MENU_INACTIVE_TEXT, GUIEX_MENU    		}, // GUI_MENU_GRAYED
    { GUIEX_MENUTEXT,  			GUIEX_MENUHILIGHT 	}, // GUI_MENU_ACTIVE    (selected in list)
    { GUIEX_MENUTEXT,  			GUIEX_MENUHILIGHT 	}, // GUI_MENU_ACTIVE_STANDOUT
    { GUIEX_BTNTEXT,       		GUIEX_APPWORKSPACE	}, // GUI_BACKGROUND
    { GUIEX_MENUTEXT,       	GUIEX_WINDOWFRAME 	}, // GUI_MENU_FRAME
    { GUIEX_CAPTIONTEXT,       	GUIEX_ACTIVECAPTION	}, // GUI_TITLE_INACTIVE
    { GUIEX_CAPTIONTEXT,		GUIEX_ACTIVEBORDER	}, // GUI_FRAME_ACTIVE,
    { GUIEX_INACTIVECAPTIONTEXT,GUIEX_INACTIVEBORDER}, // GUI_FRAME_INACTIVE
    { GUIEX_CAPTIONTEXT,       	GUIEX_ACTIVECAPTION }, // GUI_ICON
    { GUIEX_MENU_INACTIVE_TEXT, GUIEX_MENU    		}, // GUI_MENU_GRAYED_ACTIVE
    { GUIEX_INACTIVECAPTIONTEXT,GUIEX_INACTIVEBORDER}, // GUI_FRAME_RESIZE
    { GUIEX_BTNTEXT,       		GUIEX_BTNFACE	  	}  // GUI_CONTROL_BACKGROUND
/* The following values were the orginal values
    { GUI_BR_GREEN,         	GUI_BR_BLUE       	}, // GUI_MENU_PLAIN
    { GUI_BLUE,             	GUI_BR_GREEN      	}, // GUI_MENU_STANDOUT
    { GUI_GREY,             	GUI_BR_BLUE       	}, // GUI_MENU_GRAYED
    { GUI_WHITE,  				GUI_GREY	      	}, // GUI_MENU_ACTIVE    (selected in list)
    { GUI_BR_BLUE,          	GUI_BR_GREEN      	}, // GUI_MENU_ACTIVE_STANDOUT
    { GUI_BLACK,       			GUI_WHITE 		  	}, // GUI_BACKGROUND
    { GUI_BLUE,             	GUI_GREY          	}, // GUI_MENU_FRAME
    { GUI_GREY,             	GUI_WHITE         	}, // GUI_TITLE_INACTIVE
    { GUI_BLUE,             	GUI_GREY          	}, // GUI_FRAME_ACTIVE,
    { GUI_BLACK,            	GUI_GREY          	}, // GUI_FRAME_INACTIVE
    { GUI_BLUE,             	GUI_GREY          	}, // GUI_ICON
    { GUI_BLUE,             	GUI_GREY          	}, // GUI_MENU_GRAYED_ACTIVE
    { GUI_BLACK,            	GUI_WHITE         	}, // GUI_FRAME_RESIZE
    { GUI_BLACK,       			GUI_GREY		  	} // GUI_CONTROL_BACKGROUND
*/
#else
    /*  fore/text           backgr. */
    { GUI_WHITE,            	GUI_BLUE          }, // GUI_MENU_PLAIN
    { GUI_BR_WHITE,         	GUI_BLUE          }, // GUI_MENU_STANDOUT
    { GUI_GREY,             	GUI_BLUE          }, // GUI_MENU_GRAYED
    { GUI_WHITE,            	GUI_BLACK         }, // GUI_MENU_ACTIVE
    { GUI_BR_WHITE,         	GUI_BLACK         }, // GUI_MENU_ACTIVE_STANDOUT
    { GUI_BLUE,             	GUI_WHITE         }, // GUI_BACKGROUND
    { GUI_BR_YELLOW,        	GUI_BLUE          }, // GUI_MENU_FRAME
    { GUI_GREY,             	GUI_WHITE         }, // GUI_TITLE_INACTIVE
    { GUI_BLUE,             	GUI_CYAN          }, // GUI_FRAME_ACTIVE
    { GUI_GREY,             	GUI_WHITE         }, // GUI_FRAME_INACTIVE
    { GUI_BR_WHITE,         	GUI_RED           }, // GUI_ICON
    { GUI_GREY,             	GUI_BLACK         }, // GUI_MENU_GRAYED_ACTIVE
    { GUI_GREY,             	GUI_CYAN          }, // GUI_FRAME_RESIZE
    { GUI_BLUE,             	GUI_WHITE         }  // GUI_CONTROL_BACKGROUND
#endif
};

bool GUISetColours( gui_window *wnd, int num_attrs, gui_colour_set *colours )
{
    if( num_attrs < GUI_NUM_ATTRS ) {
        num_attrs = GUI_NUM_ATTRS;
        colours = Default;
    }
    return( GUIXSetColours( wnd, num_attrs, colours ) );
}

void GUIFreeColours( gui_window *wnd )
{
    GUIMemFree( wnd->attrs );
    wnd->num_attrs = 0;
    wnd->attrs = NULL;
}

int GUIAPI GUIGetNumWindowColours( gui_window *wnd )
{
    return( wnd->num_attrs );
}

gui_colour_set * GUIAPI GUIGetWindowColours( gui_window *wnd )
{
    gui_colour_set *colours;

    colours = GUIMemAlloc( wnd->num_attrs * sizeof( gui_colour_set ) );
    if( colours != NULL ) {
        GUIXGetWindowColours( wnd, colours );
    }
    return( colours );
}
