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
* Description:  Description of the code module. This should describe the
*               purpose of the code in this module.
*
****************************************************************************
 *      GUIDEBUG.C  Update History
 *
 *      Version  Date          Updated by        Comments
 *      -------  ------------  ----------------  ----------------------------
 *      0.00     May 15, 2000  David Ogilvie     Original version
 *      0.10     Aug 18, 2021  David Ogilvie     Revamped for OW GUI
 *      0.20     Aug 20, 2021  David Ogilvie     Added full justification
 *      0.30     Nov 12, 2021  David Ogilvie     Added various macros and
 *                                                  switcher routines
 *      0.40     Nov 16, 2021  David Ogilvie     Changed classes method
 *
 *      GUILOG calls and macros.  Note: ^ denotes "still needs implimenting"
 ***************************************************************************
 *  set_logging_mode(mode) Start/stop logging (mode= 1/0)
 *^ GUIlog_set_logging_mode_from_ini() Start/stop logging using settings contained
 *                                  in "guilog.ini" file located on the
 *                                  desktop
 *  GUIlog_set_filename(name)     Set filename for log file
 *  GUIlog_set_envvar (envname)   Sets environment variable to use, such as
 *                                  OWROOT preceeding filename
 *  GUIlog_set_crash_mode(mode)   Sets crash-resistant mode on or off with
 *                                  "mode" (1/0)
 *  GUIlog_set_justify_mode (value) Turns justification on or off.  If on, log
 *                                  file includes __FILE__, __ROUTINE__ and
 *                                  __LINE__ for each call to GUIlog, right
 *                                  justified and showing only the items that
 *                                  changed from the previous call.
 *  GUIlog_set_justify_width(int) Number of columns to use for right
 *                                  justification of log file output
 *  GUIlog_open_logfile()         Initializes log file for logging.
 *  GUIlog_close_logfile()        Shuts down logging
 *  GUIlog (format, ...)          Logging routine for tracing code.  Use
 *      (macro to GUIlog_)          similarly to how you would use printf
 *  GUIlog_entering_function()    Use at the start of every routine to log
 *      (macro to GUIlog_)          entry into that routine
 *^ GUIlog_win_msg ()             Use to display window messages inn a winproc
 *      (macro to GUIlog_)          callback routine
 *      (macro)                     log into about WM_???? messages
 *^ GUIlog_justify_mode_on()      Turn justification on
 *^ GUIlog_justify_mode_off()     Turn justification off
 *^ GUIlog_crash_mode_on()        Sets crash-resistant mode on
 *^ GUIlog_crash_mode_off()       Sets crash-resistant mode off
 *  GUIlog_logging_on ();
 *  GUIlog_logging_off ();
 *^ GUIlog_enterubg_on()          Turn display of entering messages on
 *^ GUIlog_entering_off()         Turn display of entering messages off
 *^ GUIlog_win_msg_on()       Turn window messaging info on
 *^ GUIlog_win_msg_off()      Turn window messaging info off
 */

#include    <stdlib.h>
#include    <string.h>
#include    <stdio.h>
#include    <stdarg.h>
#include    <io.h>
#include    <errno.h>
#include    <time.h>
#include    "guiwind.h"
#include    "guixutil.h"
#define     _GUILOG_H_
#include    "guilog.h"

static  int GUIlog_open_logfile (void);     // Opens log file (gui.log in root air)

static  FILE    *fpDPTR= NULL;              // File pointer to filename
static  char    DEBUGFILE[128]= "gui.log";  // Default filename
static  char    FULLDEBUGFILE[128]= "\0";   // <EMVVAR>+filename
static  char    ENVVARNAME[128]= "zzzz";    // Sets environment variable to use
static  char   *oldFILE= NULL;
static  char   *oldFUNC= NULL;
static  int     oldLINE= 0;
static  int     DONEDEBUGFILE= 0;           // Becomes true once <owroot> is added
static  int     DEBUG= 0;                   // Logging turned off by default
static  int     DOSLOWDUMP= 0;              // Crash-proof logging turned off
static  int     LOGWIDTH= 76;               // Width of log if justified
static  int     JUSTIFY= 1;                 // Put routine and line number on right
static unsigned long ACTIVE_CLASSES= 0;

// Set various loggin parameters on or off
int GUIlog_set_logging_mode (int mode)               { DEBUG= mode;      return (1); }
int GUIlog_logging_on       (void)                   { DEBUG= 1;         return (1); }
int GUIlog_logging_off      (void)                   { DEBUG= 0;         return (1); }
int GUIlog_set_crash_mode   (int mode)               { DOSLOWDUMP= mode; return (1); }
int GUIlog_crash_mode_on    (void)                   { DOSLOWDUMP= 1;    return (1); }
int GUIlog_crash_mode_off   (void)                   { DOSLOWDUMP= 0;    return (1); }
int GUIlog_set_justify_mode (int value)              { JUSTIFY= value;   return (1); }
int GUIlog_justify_mode_on  (void)                   { JUSTIFY= 1;       return (1); }
int GUIlog_justify_mode_off (void)                   { JUSTIFY= 0;       return (1); }
int GUIlog_set_justify_width(int width)              { LOGWIDTH= width;  return (1); }
// Turn logging classes on or off
int GUIlog_functions_on (void)                       { ACTIVE_CLASSES|= L_EF;        return (1); }
int GUIlog_functions_off (void)                      { ACTIVE_CLASSES&= (L_1^L_EF);  return (1); }
int GUIlog_callbacks_on (void)                       { ACTIVE_CLASSES|= L_EC;        return (1); }
int GUIlog_callbacks_off (void)                      { ACTIVE_CLASSES&= (L_1^L_EC);  return (1); }
int GUIlog_win_clr_on (void)                         { ACTIVE_CLASSES|= L_WC;        return (1); }
int GUIlog_win_clr_off (void)                        { ACTIVE_CLASSES&= (L_1^L_WC);  return (1); }
int GUIlog_strings_on (void)                         { ACTIVE_CLASSES|= L_ST;        return (1); }
int GUIlog_strings_off (void)                        { ACTIVE_CLASSES&= (L_1^L_ST);  return (1); }
int GUIlog_win_msg_on (void)                         { ACTIVE_CLASSES|= L_WM;        return (1); }
int GUIlog_win_msg_off (void)                        { ACTIVE_CLASSES&= (L_1^L_WM);  return (1); }
int GUIlog_mouse_on (void)                           { ACTIVE_CLASSES|= L_MO;        return (1); }
int GUIlog_mouse_off (void)                          { ACTIVE_CLASSES&= (L_1^L_MO);  return (1); }
int GUIlog_keyboard_on (void)                        { ACTIVE_CLASSES|= L_KB;        return (1); }
int GUIlog_keyboard_off (void)                       { ACTIVE_CLASSES&= (L_1^L_KB);  return (1); }
int GUIlog_scrolling_on (void)                       { ACTIVE_CLASSES|= L_SC;        return (1); }
int GUIlog_scrolling_off (void)                      { ACTIVE_CLASSES&= (L_1^L_SC);  return (1); }

// Various function entry log lines printing
void GUIlog_entering_bool_function()                 { GUIlog(L_EF,       "Function %s, returns bool",__FUNCTION__); }
void GUIlog_entering_bool_strings_function ()        { GUIlog(L_EF+L_ST,  "Function %s, returns bool",__FUNCTION__); }
void GUIlog_entering_callback ()                     { GUIlog(L_EF+L_EC,  "Callback %s, no return value (void)",__FUNCTION__); }
void GUIlog_entering_charptr_function()              { GUIlog(L_EF,       "Function %s, returns char*",__FUNCTION__); }
void GUIlog_entering_control_item_function()         { GUIlog(L_EF,       "Function %s, returns control_item",__FUNCTION__); }
void GUIlog_entering_function ()                     { GUIlog(L_EF,       "Function %s, no return value (void)",__FUNCTION__); }
void GUIlog_entering_guix_ord_function()             { GUIlog(L_EF,       "Function %s, returns guix_ord",__FUNCTION__); }
void GUIlog_entering_gui_control_class_function()    { GUIlog(L_EF,       "Function %s, returns gui_control_class",__FUNCTION__); }
void GUIlog_entering_gui_control_styles_function()   { GUIlog(L_EF,       "Function %s, returns gui_control_styles",__FUNCTION__); }
void GUIlog_entering_gui_help_instance_function()    { GUIlog(L_EF,       "Function %s, returns gui_help_instance",__FUNCTION__); }
void GUIlog_entering_gui_message_return_function()   { GUIlog(L_EF,       "Function %s, returns gui_message_return",__FUNCTION__); }
void GUIlog_entering_gui_ord_function()              { GUIlog(L_EF,       "Function %s, returns gui_ord",__FUNCTION__); }
void GUIlog_entering_gui_scroll_styles_function()    { GUIlog(L_EF,       "Function %s, returns gui_scroll_styles",__FUNCTION__); }
void GUIlog_entering_gui_text_ord_function()         { GUIlog(L_EF,       "Function %s, returns gui_text_ord",__FUNCTION__); }
void GUIlog_entering_gui_window_function()           { GUIlog(L_EF,       "Function %s, returns gui_window",__FUNCTION__); }
void GUIlog_entering_HAB_function()                  { GUIlog(L_EF,       "Function %s, returns HAB",__FUNCTION__); }
void GUIlog_entering_HBRUSH_function()               { GUIlog(L_EF,       "Function %s, returns HBRUSH",__FUNCTION__); }
void GUIlog_entering_HMENU_function()                { GUIlog(L_EF,       "Function %s, returns HMENU",__FUNCTION__); }
void GUIlog_entering_HWND_function()                 { GUIlog(L_EF,       "Function %s, returns HWND",__FUNCTION__); }
void GUIlog_entering_int_function()                  { GUIlog(L_EF,       "Function %s, returns int",__FUNCTION__); }
void GUIlog_entering_LONG_function()                 { GUIlog(L_EF,       "Function %s, returns LONG",__FUNCTION__); }
void GUIlog_entering_LRESULT_function()              { GUIlog(L_EF,       "Function %s, returns LRESULT",__FUNCTION__); }
void GUIlog_entering_mcursor_function ()             { GUIlog(L_EF,       "Function %s, no return value (void)",__FUNCTION__); }
void GUIlog_entering_mcursor_handle_function()       { GUIlog(L_EF,       "Function %s, returns mcursor_handle",__FUNCTION__); }
void GUIlog_entering_mouse_function()                { GUIlog(L_EF+L_MO,  "Function %s",__FUNCTION__); }
void GUIlog_entering_size_t_function()               { GUIlog(L_EF,       "Function %s, returns size_t",__FUNCTION__); }
void GUIlog_entering_strings()                       { GUIlog(L_ST,       " STR Nothing set up yet"); }
void GUIlog_entering_unsigned_function()             { GUIlog(L_EF,       "Function %s, returns unsigned int",__FUNCTION__); }
void GUIlog_entering_UINTptr_callback ()             { GUIlog(L_EC,       "Callback %s, returns unsigned integer*",__FUNCTION__); }
void GUIlog_entering_void_function()                 { GUIlog(L_EF,       "Function %s",__FUNCTION__); }
void GUIlog_entering_wndproc_function()              { GUIlog(L_EF,       "Function %s, returns wndproc",__FUNCTION__); }
void GUIlog_entering_WPI_COLOUR_function()           { GUIlog(L_EF,       "Function %s, returns WPI_COLOUR",__FUNCTION__); }
void GUIlog_entering_WPI_DLGRESULT_callback()        { GUIlog(L_EF+L_EC,  "Callback %s, returns WPI_DLGRESULT",__FUNCTION__); }
void GUIlog_entering_WPI_FONT_function()             { GUIlog(L_EF,       "Function %s, returns WPI_FONT",__FUNCTION__); }
void GUIlog_entering_WPI_INST_function()             { GUIlog(L_EF,       "Function %s, returns WPI_INST",__FUNCTION__); }
void GUIlog_entering_WPI_MRESULT_callback()          { GUIlog(L_EF+L_EC,  "Callback %s, returns WPI_MRESULT",__FUNCTION__); }
void GUIlog_entering_WPI_MRESULT_function()          { GUIlog(L_EF,       "Function %s, returns WPI_MRESULT",__FUNCTION__); }
void GUIlog_entering_WPI_WNDPROC_function ()         { GUIlog(L_EF,       "Function %s, returns WPI_WNDPROC",__FUNCTION__); }

void GUIlog_win_msg_ (HWND hwnd,WPI_MSG msg,WINDOW_MSG _msg,WPI_PARAM1  wparam,WPI_PARAM2 lparam) {
    GUIlog(L_WM,       " MSG hwnd 0x%08x, msg %s(0x%04X %d),w=0x%08X,l=0x%08X",hwnd,e2s_(__dummy__,_msg),msg,msg,wparam,lparam);
}

/*
 * GUIset_log_envvar -- This routine sets the environment variable
 *                      name that is prepended to the log file name.
 */

int GUIlog_set_envvar (char *envname)
{
    strcpy(ENVVARNAME, envname);
/* Notes on using this feature
 * 1)   This is a global environment variable, not an environment variable that\
 *      has been set when using mysetvars batch/command file
 * 2)   This envirnment variable may be case sensitive
 * 3)   If you are going to use this feature, use it before opening
 *      the log file using GUIopen_log.
 * 4)   A "/" is inserted between the environment variable and the file name
 * 5)   If no environment name is provided "" is assumed.
 * 6)   If no environment variable is provided and the filename is a simple
 *      filename such as "gui.log", the file will be placed on the desktop */
    return (1);
}


/*
 * GUIset_log_filename -- This routine sets the debug file name
 */

int GUIlog_set_filename(char *name)
{
    if (fpDPTR) { // Log file was already open with another name
        fclose (fpDPTR);
        fpDPTR= NULL;
    }
    strcpy(DEBUGFILE, name);    // Store new filename
    DONEDEBUGFILE= 0;           // Set to 0 so that filename gets opened again
    return (1);
}

/*
 * GUIlog_print_timestamp -- This routine prints the date and time the
 *                           log file was started at the beginning of
 *                           the log file
 */

int GUIlog_print_timestamp ()
{
    time_t  current_time;
    char    *current_time_string;

    if (!fpDPTR&&DEBUG) GUIlog_open_logfile ();

    current_time= time ( NULL );
    current_time_string= ctime (&current_time);
    fprintf (fpDPTR,
        "Started \"%s\" on %s=============================================\n",
        FULLDEBUGFILE, current_time_string );
    if (DOSLOWDUMP) {
        fflush (fpDPTR);
    }
    return (1);
}

/*
 * GUIlog_print_guilog_settings_ -- This routine prints the location that
 *                                 the settings are created, then lists
 *                                 the settings information
 */

int GUIlog_print_guilog_settings_ (char *FUNC, char *FILE, int LINE)
{
    char    STS_FMT[]= "Logging %-12s is %s\n";

    if (!fpDPTR) return (0);
    fprintf (fpDPTR, "Logfile initiated from file %s, routine %s, line %d\n",
        FILE, FUNC, LINE );

// Show status of various categories
    fprintf (fpDPTR, STS_FMT, "crash_mode"   , (DOSLOWDUMP)?"on":"off" );
    fprintf (fpDPTR, STS_FMT, "justify_mode" , (JUSTIFY   )?"on":"off" );
    if (JUSTIFY) fprintf (fpDPTR, "Justify width is %d\n", LOGWIDTH );

    fprintf (fpDPTR, STS_FMT, "functions"    , (ACTIVE_CLASSES&L_EF)?"on":"off" );
    fprintf (fpDPTR, STS_FMT, "callbacks"    , (ACTIVE_CLASSES&L_EC)?"on":"off" );
    fprintf (fpDPTR, STS_FMT, "win_msg"      , (ACTIVE_CLASSES&L_WM)?"on":"off" );
    fprintf (fpDPTR, STS_FMT, "win_colour"   , (ACTIVE_CLASSES&L_WC)?"on":"off" );
    fprintf (fpDPTR, STS_FMT, "mouse"        , (ACTIVE_CLASSES&L_MO)?"on":"off" );
    fprintf (fpDPTR, STS_FMT, "keyboard"     , (ACTIVE_CLASSES&L_KB)?"on":"off" );
    fprintf (fpDPTR, STS_FMT, "scrolling"    , (ACTIVE_CLASSES&L_SC)?"on":"off" );
    fprintf (fpDPTR, STS_FMT, "strings"      , (ACTIVE_CLASSES&L_ST)?"on":"off" );

    fprintf (fpDPTR, "=============================================\n");

    if (DOSLOWDUMP) {
        fflush (fpDPTR);
    }
    return (1);
}

/*
 * GUIlog_open_logfile -- This routine opens the debug file
 */

static int GUIlog_open_logfile(void)
{

    if (!DONEDEBUGFILE) {
        char *envstr;
        envstr= getenv (ENVVARNAME);
        if (envstr != NULL)
        sprintf (FULLDEBUGFILE, "%s\\%s", envstr, DEBUGFILE);
        else
        strcpy (FULLDEBUGFILE, DEBUGFILE);
        DONEDEBUGFILE= 1;
    }
    errno= 0; // Before call to fopen
    if (DEBUG) fpDPTR= fopen( FULLDEBUGFILE, "w" );
    if (!fpDPTR) {
        GUIErrorSA ("Error %d opening log file ""%s"".\n%s.",
        errno, FULLDEBUGFILE, strerror ( errno ) );
        exit (1);
    }
    return (1);
}

/*
 * GUIclose_log-- This routine closes the debug file
 */

int GUIlog_close_logfile(void)
{
    if (DEBUG) fclose(fpDPTR);
    return (1);
}

/*
 * GUIlog_set_justify_mode -- This routine sets whether right justify mode is on or off.
 *               If it is set to on, the calling routine must supply
 *               __FUNCTION__ and __LINE__ as the last 2 parameters
 *               of the call.  At some point I will try to find out how to
 *               find the file and line number of the calling routine.
 *               This will likely be in the Code > Callers menu item.
 *               Until then, this will have to do. Note that turning this
 *               on and off can have parts of the log file with
 *               justification, but part of the log that deals with a long
 *               string of events within a small portion of the same file
 *               can have justification (Saves on file size and time.)
 */


/*
 * GUIlog -- This routine writes a record to the debug file, ensuring
 *           that it is written to the disk.
 *
 *           Added a THIS_CLASS parameter so that the user can select
 *           multiple classes for a call to GUIlog.  The user can say,
 *           for example:
 *
 *           GUIlog (LOG_ER+LOG_EC+LOG_WM, "This is what will be written.")
 *
 *           if this call is a routine entry point, but is also a
 *           callback entry point and also is useful for logging mouse
 *           processing issues.
 */

int GUIlog_ (char *FUNC, char *FILE, int LINE, unsigned long THIS_CLASS, char *format, ...)
{
    int         ret, length, len1, len2;
    char        _format[128]= "\0";
    char        _format2[128]= "\0", *pos;
    char        _format3[32]= "\0";
    char        *blanks= "  ";

    if (!DEBUG) return (0);

    if (!(ACTIVE_CLASSES&THIS_CLASS))   return (0);

    if (strlen (format) != 0)
    {
        va_list arglist;

        if (!fpDPTR) GUIlog_open_logfile ();

        va_start (arglist, format);

        if (!JUSTIFY) {
            ret= vfprintf (fpDPTR, format, arglist);
            ret= fprintf  (fpDPTR, "\n");
        }
        else {

            ret= vsprintf (_format, format, arglist);
            len1= strlen (_format);
            // Extension:
            // search backwards for the last blank, so that
            // we just have the file name, not the relative pathname

            if (oldFILE != FILE) {
                sprintf (_format2, "%s %s:%d", FILE, FUNC, LINE);
                oldFILE= FILE;
            }
            else if (oldFUNC != FUNC) {
                sprintf (_format2, "%s:%d", FUNC, LINE);
                oldFUNC= FUNC;
            }
            else {
                sprintf (_format2, ":%d", LINE);
                oldLINE= LINE;
            }
            pos= strrchr (_format2, '\\');
            if (pos != NULL) pos++;
//              _format2= *(_format2)+pos+1;

            if (pos == NULL)  len2= strlen (_format2);
            else            len2= strlen (pos);

            length= LOGWIDTH-len1-len2;

            // ret should return total # of characterss printed, hopefully
            // the same value as LOGWIDTH.  This may not work if this is
            // not compiled as C99.
            sprintf (_format3, "%%s %%%ds %%s\n", length);
            if (pos == NULL)  ret= fprintf(fpDPTR, _format3, _format, blanks, _format2);
            else            ret= fprintf(fpDPTR, _format3, _format, blanks, pos);
        }
        va_end (arglist);
        if (ret < 0)  // We have an error and cannot continue
        {
            GUIError ("GuiLog failed with error %d\n%s", ret, strerror (ret) );
        }
    }
    if (DOSLOWDUMP) {
        fflush (fpDPTR);
    }
    return (1);

/* Example of how to use the GUIlog facility
#include        "GUIlog.h"
    ...
In main routine do...
    GUIset_log_filename("\\DEVEL\\mdiedit\\gui.log");  // Open debug file if logging enabled
    GUIset_log_mode( 1 );           // 1 to turn on standard tracing, usually 1
    GUIset_crash_mode(0);           // 1 to turn on crash-resistant log file writing (slow!), usually 0
    GUIopen_debug( );               // open the debug file to start loggin
...
    GUIlog ("This will be written to the log file from routine %s\n",
        __FUNCTION__);
...
    GUIset_log_mode(0);        // 1 to turn on crash-resistant log file writing (slow!), usually 0
...
    GUIclose_log ();    // Close everything down when closing program

Here's how I would like the log file to look:

Started Aug 20 2021 16:42:27 in GUIopen_log in guilog.c(64)
Entered GUIXMain                                                  guixwind.c(272)
Entered GUIInitDialog                                              guixdlg.c(810)
Entered GUIInitDialogFuncDlgProc                                            (756)
MSG WM_WINDOWCREATE(48) GUIInitDialogFuncDlgProc                            (757)
Entered GUIInitDialogFuncDlgProc                                            (756)
MSG 272(272) GUIInitDialogFuncDlgProc                                       (757)
Entered GUIInitDialogFuncDlgProc                                            (756)
MSG 70(70) GUIInitDialogFuncDlgProc                                         (757)
Entered GUIInitDialogFuncDlgProc                                            (756)
MSG 295(295) GUIInitDialogFuncDlgProc                                       (757)
Entered GUIInitDialogFuncDlgProc                                            (756)
MSG 144(144) GUIInitDialogFuncDlgProc                                       (757)
Entered GUIInitDialogFuncDlgProc                                            (756)
MSG 2(2) GUIInitDialogFuncDlgProc                                           (757)
Entered GUIInitDialogFuncDlgProc                                            (756)
MSG 130(130) GUIInitDialogFuncDlgProc                                       (757)
Entered InitSystemRGB                                             guicolor.c(283)
Entered GUIGetCtrlWnd                                             guicontr.c(100)
Entered GUIGetCtrlWnd                                                       (100)
Entered GUIGetCtrlWnd                                                       (100)
Entered GUIGetClientRect                                      ..\c\guicrect.c(45)
...                                                                            */
}

/*
 * e2s_ -- In this routine, I will try to get at the name of an
 *         arglist value by examining the info available in the
 *         argument list, which hopefully will supply the type of
 *         the enum and a pointer to its list values.  I note that
 *         this is done in the debugger, so hopefully I can reverse
 *         engineer the process here.
 */

char *e2s_ (int dummy, ...) { // Actually only 1 parameter, but need to get at list
    va_list     arglist;
    char        *pos;
    int         i= 0;

    va_start (arglist, dummy);
    pos= va_arg (arglist, char *);
    va_end (arglist);
    for (i=0; i<20; i++) {
        pos--;
    }
    return (__NaS__);
}
