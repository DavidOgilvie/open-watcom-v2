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
#include "guiextnm.h"
#include "guixwind.h"
#include "guirdlg.h"
#include "guilog.h"


static  bool        GUIMsgInitFlag = false;
static  bool        external = false;


/*
 * GUIIsLoadStrInitialized -- This routine returns true if ?
 */

bool GUIAPI GUIIsLoadStrInitialized( void )
{
	GUIlog_entering_strings ();
    return( GUIMsgInitFlag );
}

/*
 * GUILoadStrInit -- This routine returns true if ?
 */

bool GUIAPI GUILoadStrInit( const char * fname )
{
#ifndef __OS2_PM__
    WPI_INST    library;
#endif  // of #ifndef __OS2_PM__
    char        *resource_file_name;

	GUIlog_entering_strings ();
    fname = fname;
    if( !GUIMsgInitFlag ) {
        resource_file_name = GUIGetResFileName();
        external = ( resource_file_name != NULL );
#ifndef __OS2_PM__
        if( external ) {
            // if an external resource DLL is specified, then load it
            library = _wpi_loadlibrary( GUIMainHInst, resource_file_name );
            if( library != NULL ) {
                memcpy( &GUIResHInst, &library, sizeof( WPI_INST ) ) ;
            } else {
                return( false );
            }
        }
#endif  // of #ifndef __OS2_PM__
        GUIMsgInitFlag = true;
        return( true );
    } else {
        return( false );
    }
}

/*
 * GUILoadStrFini -- This routine returns true if ?
 */

bool GUIAPI GUILoadStrFini( void )
{
 	GUIlog_entering_strings ();
   if( GUIMsgInitFlag ) {
#ifndef __OS2_PM__
        if( external ) {
            _wpi_freelibrary( GUIMainHInst, GUIResHInst );
        }
#endif  // of #ifndef __OS2_PM__
        GUIMsgInitFlag = false;
    }

    return( true );
}

/*
 * GUILoadString -- This routine returns true if ?
 */

bool GUIAPI GUILoadString( gui_res_id id, char *buffer, int buffer_length )
{
	GUIlog_entering_strings ();
    if( buffer != NULL && buffer_length > 0 ) {
        if( _wpi_loadstring( GUIResHInst, id, (LPSTR)buffer, buffer_length ) > 0 ) {
            return( true );
        }
        buffer[0] = '\0';
    }
    return( false );
}
