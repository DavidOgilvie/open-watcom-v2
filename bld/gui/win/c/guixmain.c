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
* Description:  Mainline for applications using GUI library.
*
****************************************************************************/


#include "guiwind.h"
#include "guixmain.h"
#include <stdlib.h>
#ifdef __WATCOMC__
    #include "clibint.h"
#else  // of #ifdef __WATCOMC__
    #include "clibext.h"
#endif  // of #else for #ifdef __WATCOMC__
#include "guilog.h"


// This makes sure that the main routine is actially linked in
bool    GUIMainTouched = false;

#if defined( __OS2_PM__ )

/*
 * main -- main entry point for PM
 */

int main( SHORT sArgc, CHAR *ppArgv[] )
{
    GUIlog_entering_int_function ();

    return( GUIXMain( sArgc, ppArgv ) );
}

#else  // of #if defined( __OS2_PM__ )

/*
 * WinMain -- main windows message loop
 */

int PASCAL WinMain( HINSTANCE inst, HINSTANCE hPrevInstance, LPSTR lpCmdLine,
                    int nShowCmd )
{
    GUIlog_entering_int_function ();

 #if !defined( __WATCOMC__ ) && defined( __NT__ )
    _argc = __argc;
    _argv = __argv;
 #endif  // of #if !defined( __WATCOMC__ ) && defined( __NT__ )
    return( GUIXMain( _argc, _argv, inst, hPrevInstance, lpCmdLine, nShowCmd ) );
}
#endif  // of #else for #if defined( __OS2_PM__ )
