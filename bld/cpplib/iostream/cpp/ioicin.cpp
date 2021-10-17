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
* Description:
*
****************************************************************************/

#ifdef __SW_FH
#include "iost.h"
#else
#include "variety.h"
#include <unistd.h>
#include <iostream>
#include <stdiobuf.h>
#endif
#include "clibsupp.h"


#pragma initialize 21;

// This struct is just a place holder to control the initialization and
// finalization of cin
struct cin_initfini {
  cin_initfini();
};


// This is the definition of the predefined stream buffer:
static stdiobuf  cin_strmbuf( __get_std_stream( STDIN_FILENO ) );

// This is the definition of the predefined stream:
namespace std {
  istream _HUGEDATA cin( &cin_strmbuf );
}

// This will force the extra initialization and finalization
static cin_initfini __standard_io_instance_cin;

cin_initfini::cin_initfini() {
  // Tie the streams together, for automatic flushing:
  std::cin.tie( &std::cout );

  // Ensure the correct flag settings.
  std::cin.setf( ios::skipws );
}

