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
* Description:  Floating-point modulo routine.
*
****************************************************************************/


#include "variety.h"
#include "mathlib.h"
#include "ifprag.h"
#include <math.h>
#include "_matherr.h"

/*  The fmod function computes the floating-point remainder of x/y.
    It returns x if y is 0, otherwise it returns the value f that has
    the same sign as x, such that x == i*y + f for some integer i,
    where the magnitude of f is less than the magnitude of y.
*/


_WMRTLINK float _IF_fmod( float x, float y )
/******************************************/
{
    return( _IF_dfmod( x, y ) );
}

_WMRTLINK double (fmod)( double x, double y )
/*******************************************/
{
    return( _IF_dfmod( x, y ) );
}

_WMRTLINK double _IF_dfmod( double x, double y )
/**********************************************/
{
    int     quot;
    double  rem;
    
    if(__math_errhandling_flag != 0 && 
       (isinf(x) || y == 0))
    {
        __reporterror(DOMAIN, __func__, x, y, NAN);
        return NAN;
    }   

    __fprem( x, y, &quot, &rem );
    return( rem );
}
