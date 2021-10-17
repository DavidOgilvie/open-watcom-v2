/*
 *  sys/stat.h  Equates and prototype for fstat, stat functions
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
 */
#ifndef _STAT_H_INCLUDED
#define _STAT_H_INCLUDED

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file;
#endif

#ifndef _COMDEF_H_INCLUDED
 #include <_comdef.h>
#endif

#ifndef __TYPES_H_INCLUDED
 #include <sys/types.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack( __push, 4 )

/* Versions of the `struct stat' data structure.  */
#define _STAT_VER_LINUX_OLD 1
#define _STAT_VER_KERNEL    1
#define _STAT_VER_SVR4      2
#define _STAT_VER_LINUX     3
#define _STAT_VER           _STAT_VER_LINUX /* The one defined below.  */

#ifndef _ARCH_DIR
 #if defined(__386__)
  #define _ARCH_DIR i386
 #elif defined(__MIPS__)
  #define _ARCH_DIR mips
 #else
  #error unknown platform
  #define _ARCH_DIR
 #endif
 #define _ARCH_INCLUDE(hdr) <arch/ ## _ARCH_DIR ## / ## hdr ## >
#endif /* !_ARCH_DIR */

#include _ARCH_INCLUDE(sys/stat.h)

/* Tell code we have these members.  */
#define _STATBUF_ST_BLKSIZE
#define _STATBUF_ST_RDEV

/* Encoding of the file mode */

#define _S_IFMT     0xF000              /*  Type of file                    */
#define _S_IFIFO    0x1000              /*  FIFO                            */
#define _S_IFCHR    0x2000              /*  Character special               */
#define _S_IFDIR    0x4000              /*  Directory                       */
#define _S_IFNAM    0x5000              /*  Special named file              */
#define _S_IFBLK    0x6000              /*  Block special                   */
#define _S_IFREG    0x8000              /*  Regular                         */
#define _S_IFLNK    0xA000              /*  Symbolic link                   */
#define _S_IFSOCK   0xC000              /*  Socket                          */

#define S_ISFIFO(m) (((m)&_S_IFMT)==_S_IFIFO) /* Test for FIFO.             */
#define S_ISCHR(m)  (((m)&_S_IFMT)==_S_IFCHR) /* Test for char special file.*/
#define S_ISDIR(m)  (((m)&_S_IFMT)==_S_IFDIR) /* Test for directory file.   */
#define S_ISBLK(m)  (((m)&_S_IFMT)==_S_IFBLK) /* Test for block specl file. */
#define S_ISREG(m)  (((m)&_S_IFMT)==_S_IFREG) /* Test for regular file.     */

#if defined(_POSIX_SOURCE) || !defined(NO_EXT_KEYS) /* extensions enabled */

#define S_ISLNK(m)  (((m)&_S_IFMT)==_S_IFLNK) /* Test for symbolic link.    */
#define S_ISNAM(m)  (((m)&_S_IFMT)==_S_IFNAM) /* Test for special named file*/
#define S_ISSOCK(m) (((m)&_S_IFMT)==_S_IFSOCK)/* Test for socket.           */

/*
 *  Common filetype macros
 */
#define S_IFMT      _S_IFMT             /*  Type of file                    */
#define S_IFIFO     _S_IFIFO            /*  FIFO                            */
#define S_IFCHR     _S_IFCHR            /*  Character special               */
#define S_IFDIR     _S_IFDIR            /*  Directory                       */
#define S_IFNAM     _S_IFNAM            /*  Special named file              */
#define S_IFBLK     _S_IFBLK            /*  Block special                   */
#define S_IFREG     _S_IFREG            /*  Regular                         */
#define S_IFLNK     _S_IFLNK            /*  Symbolic link                   */
#define S_IFSOCK    _S_IFSOCK           /*  Socket                          */

#endif /* extensions enabled */

#define S_ISUID     004000              /* set user id on execution         */
#define S_ISGID     002000              /* set group id on execution        */
#define S_ISVTX     001000              /* sticky bit (does nothing yet)    */
#define S_ENFMT     002000              /* enforcement mode locking         */

/*
 *  Owner permissions
 */
#define S_IRWXU     000700              /*  Read, write, execute/search     */
#define S_IRUSR     000400              /*  Read permission                 */
#define S_IWUSR     000200              /*  Write permission                */
#define S_IXUSR     000100              /*  Execute/search permission       */
#define S_IREAD     S_IRUSR             /*  Read permission                 */
#define S_IWRITE    S_IWUSR             /*  Write permission                */
#define S_IEXEC     S_IXUSR             /*  Execute/search permission       */

/*
 *  Group permissions
 */
#define S_IRWXG     000070              /*  Read, write, execute/search     */
#define S_IRGRP     000040              /*  Read permission                 */
#define S_IWGRP     000020              /*  Write permission                */
#define S_IXGRP     000010              /*  Execute/search permission       */

/*
 *  Other permissions
 */
#define S_IRWXO     000007              /*  Read, write, execute/search     */
#define S_IROTH     000004              /*  Read permission                 */
#define S_IWOTH     000002              /*  Write permission                */
#define S_IXOTH     000001              /*  Execute/search permission       */

/*
 *  POSIX 1003.1 Prototypes.
 */
_WCRTLINK extern int     chmod( const char *__path, mode_t __mode );
_WCRTLINK extern int     stat( const char *__path, struct stat *__buf );
_WCRTLINK extern int     lstat( const char *__path, struct stat *__buf );
_WCRTLINK extern int     fchmod( int __fildes, mode_t __mode );
_WCRTLINK extern int     fstat( int __fildes, struct stat *__buf );
_WCRTLINK extern int     mkdir( const char *__path, mode_t __mode );
_WCRTLINK extern int     mkfifo( const char *__path, mode_t __mode );
_WCRTLINK extern int     mknod( const char *__path, mode_t __mode, int __dev );
_WCRTLINK extern mode_t  umask( mode_t __cmask );
_WCRTLINK extern int     fstat64( int __fildes, struct stat64 * __buf );
_WCRTLINK extern int     lstat64( const char *filename, struct stat64 * __buf );
_WCRTLINK extern int     stat64( const char *filename, struct stat64 * __buf );

#pragma pack( __pop )

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
