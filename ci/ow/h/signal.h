/***************************************************************************
 * FILE: signal.h/csignal (Signal definitions)
 *
 * =========================================================================
 *
 *                          Open Watcom Project
 *
 *    Copyright (c) 2002-2021 Open Watcom Contributors. All Rights Reserved.
 *    Portions Copyright (c) 1983-2002 Sybase, Inc. All Rights Reserved.
 *
 *    This file is automatically generated. Do not edit directly.
 *
 * =========================================================================
 *
 * Description: This header is part of the C/C++ standard library. It
 *              declares facilities for handling signals in programs.
 ***************************************************************************/
#ifndef _SIGNAL_H_INCLUDED
#define _SIGNAL_H_INCLUDED

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file;
#endif

#ifdef __cplusplus

#include <csignal>

// C99 types in signal.h.
using std::sig_atomic_t;

// C99 functions in signal.h.
using std::signal;
using std::raise;

#else /* __cplusplus not defined */

#ifndef _COMDEF_H_INCLUDED
 #include <_comdef.h>
#endif

typedef int sig_atomic_t;

typedef void (*__sig_func)( int );

#define SIG_IGN         ((__sig_func) 1)
#define SIG_DFL         ((__sig_func) 2)
#define SIG_ERR         ((__sig_func) 3)

#define SIGABRT 1
#define SIGFPE  2
#define SIGILL  3
#define SIGINT  4
#define SIGSEGV 5
#define SIGTERM 6
#define SIGBREAK 7
/* following are OS/2 1.x process flag A,B and C */
#define SIGUSR1 8
#define SIGUSR2 9
#define SIGUSR3 10
/* following are for OS/2 2.x only */
#define SIGIDIVZ 11
#define SIGIOVFL 12

#define _SIGMAX     12
#define _SIGMIN     1

_WCRTLINK extern int  raise( int __sig );
_WCRTLINK extern void (*signal( int __sig, void (*__func)(int) ) )(int);

#endif /* __cplusplus not defined */

#endif
