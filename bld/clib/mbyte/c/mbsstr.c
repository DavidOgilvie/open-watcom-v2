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


#include "variety.h"
#include <mbstring.h>
#include "farfunc.h"



/****
***** Find the first occurrence of 'substring' in 'string'.  If 'substring'
***** has zero length, return 'string'.  Equivalent to strstr().
****/

_WCRTLINK unsigned char _FFAR *_NEARFAR(_mbsstr,_fmbsstr)( const unsigned char _FFAR *string, const unsigned char _FFAR *substring )
{
    size_t              length;

//    if( !__IsDBCS )  return( strstr( string, substring ) );

    length = _NEARFAR(_mbslen,_fmbslen)( substring ); /* substring length */

    for( ; !_NEARFAR(_mbterm,_fmbterm)(string); string=_NEARFAR(_mbsinc,_fmbsinc)(string) ) {
        if( _NEARFAR(_mbsncmp,_fmbsncmp)(string,substring,length) == 0 )
            return( (unsigned char _FFAR*) string );
    }

    return( NULL );
}
