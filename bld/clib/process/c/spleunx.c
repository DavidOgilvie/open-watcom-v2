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
* Description:  Implementation of spawnle() for UNIX.
*
****************************************************************************/


#include "variety.h"
#include <ctype.h>
#include <sys/types.h>
#include <stddef.h>
#include <stdarg.h>
#include <process.h>
#include "_process.h"
#include "_environ.h"


_WCRTLINK int (spawnle)( int mode, const char *path, const char *arg, ... )
{
    va_list         args1;
    ENVP_TYPE_ARR   env;

    va_start( args1, path );
    while( ARGS_NEXT_VA( args1 ) != NULL )
        ;
    env = ENVP_ARRAY_VA( args1 );
    va_end( args1 );

    return( spawnve( mode, path, &arg, env ) );
}
