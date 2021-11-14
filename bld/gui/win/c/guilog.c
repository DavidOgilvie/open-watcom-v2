/*      GUIDEBUG.C  Update History
 *
 *      Copyright 2001, David Ogilvie, Ogilvie Consulting, All rights reserved
 *
 *      Description:
 *
 *      Version  Date          Updated by        Comments
 *      -------  ------------  ----------------  ----------------------------
 *      0.00     May 15, 2000  David Ogilvie     Original version
 *		0.10	 Aug 18, 2021  David Ogilvie	 Revamped for OW GUI
 *		0.20	 Aug 20, 2021  David Ogilvie	 Added full justification
 *		0.30	 Nov 12, 2021  David Ogilvie	 Added various macros and 
 *													switcher routines
 *
 *		GUILOG calls and macros.  Note: ^ denotes "still needs implimenting"
 ***************************************************************************
 * 	GUIlog_set_logging_mode(mode) Start/stop logging (mode= 1/0)
 *^ GUIlog_set_logging_mode_from_ini() Start/stop logging using settings contained 
 *									in "guilog.ini" file located on the 
 *									desktop
 * 	GUIlog_set_filename(name)	  Set filename for log file
 * 	GUIlog_set_envvar (envname)	  Sets environment variable to use, such as 
 *									OWROOT preceeding filename
 * 	GUIlog_set_crash_mode(mode)	  Sets crash-resistant mode on or off with 
 *									"mode" (1/0)
 * 	GUIlog_set_justify_mode
 *						(value)	  Turns justification on or off.  If on, log
 *									file includes __FILE__, __ROUTINE__ and
 *									__LINE__ for each call to GUIlog, right 
 *									justified and showing only the items that
 *									changed from the previous call.
 * 	GUIlog_set_justify_width(int) Number of columns to use for right 
 *									justification of log file output
 * 	GUIlog_open_logfile()		  Initializes log file for logging.
 * 	GUIlog_close_logfile()		  Shuts down logging
 * 	GUIlog (format, ...)		  Logging routine for tracing code.  Use 
 *		(macro to GUIlog2)			similarly to how you would use printf
 * 	GUIlog_entering_function()	  Use at the start of every routine to log
 *		(macro to GUIlog2)			entry into that routine
 *^	GUIlog_win_msg ();()	  		  Use to display window messages inn a winproc
 *		(macro to GUIlog2)			callback routine
 *		(macro)						log into about WM_???? messages
 *^ GUIlog_justify_mode_on()	 Turn justification on
 *^ GUIlog_justify_mode_off()	 Turn justification off
 *^ GUIlog_crash_mode_on()		  Sets crash-resistant mode on
 *^ GUIlog_crash_mode_off()		  Sets crash-resistant mode off
 *  GUIlog_logging_on ();
 *  GUIlog_logging_off ();
 *^	GUIlog_enterubg_on()		  Turn display of entering messages on
 *^	GUIlog_entering_off()		  Turn display of entering messages off
 *^	GUIlog_win_msg ();_on()		  	Turn window messaging info on
 *^	GUIlog_win_msg ();_off()		  Turn window messaging info off
 */
 
#include 	<stdlib.h>
#include 	<string.h>
#include 	<stdio.h>
#include 	<stdarg.h>
#include 	<io.h>
#include 	<errno.h>
#include 	<time.h>
#include 	"guiwind.h"
//#include 	"guicolor.h"
//#include 	"guimenus.h"
//#include 	"guiscale.h"
#include 	"guixutil.h"
#define _GUILOG_H_
#include 	"guilog.h"

static  int GUIlog_open_logfile (void);			// Opens log file (gui.log in root air)

static  FILE    *fpDPTR= NULL;				// File pointer to filename
static  char    DEBUGFILE[128]= "gui.log"; 	// Default filename
static  char    FULLDEBUGFILE[128]= "\0"; 	// <EMVVAR>+filename
static  char    ENVVARNAME[128]= "zzzz"; 	// Sets environment variable to use
static	int		DONEDEBUGFILE= 0;			// Becomes true once <owroot> is added
static  int     DEBUG= 0;					// Logging turned off by default
static  int     DOSLOWDUMP= 0;				// Crash-proof logging turned off
static	int		LOGWIDTH= 76;				// Width of log if justified
static	int		JUSTIFY= 1;					// Put routine and line number on right
static	int		ENTERING= 1;				// Log lines for entering routines
static	int		CALLBACKS= 1;				// Log lines for entering windprocs
static	int		STRINGS= 1;					// Log lines for string loading
static	int		WIN_MSG= 1;					// Log lines that show window messages
static  char   *oldFILE= NULL;
static  char   *oldFUNC= NULL;
static  int		oldLINE= 0;

/*
 * GUIset_log_envvar -- This routine sets the environment variable
 *                      name that is prepended to the log file name.
 */

int GUIlog_set_envvar (char *envname)
{
    strcpy(ENVVARNAME, envname);
/* Notes on using this feature
 * 1) 	This is a global environment variable, not an environment variable that\
 *		has been set when using mysetvars batch/command file
 * 2)	This envirnment variable may be case sensitive
 * 3)	If you are going to use this feature, use it before opening
 *		the log file using GUIopen_log.
 * 4)	A "/" is inserted between the environment variable and the file name
 * 5)	If no environment name is provided "" is assumed.
 * 6)	If no environment variable is provided and the filename is a simple
 *		filename such as "gui.log", the file will be placed on the desktop */
	return (1);
}

/*
 * Set various loggin parameters on or off
 */
 
int GUIlog_set_logging_mode	(int mode) 	{ DEBUG= mode; 		return (1); }
int GUIlog_logging_on		(void) 		{ DEBUG= 1; 		return (1); }
int GUIlog_logging_off		(void) 		{ DEBUG= 0; 		return (1); }
int GUIlog_set_crash_mode	(int mode)	{ DOSLOWDUMP= mode;	return (1); }
int GUIlog_crash_mode_on	(void)		{ DOSLOWDUMP= 1;	return (1); }
int GUIlog_crash_mode_off	(void)		{ DOSLOWDUMP= 0;	return (1); }
int GUIlog_set_justify_mode (int value) { JUSTIFY= value;	return (1); }
int GUIlog_justify_mode_on	(void) 		{ JUSTIFY= 1;		return (1); }
int GUIlog_justify_mode_off (void) 		{ JUSTIFY= 0;		return (1); }
int GUIlog_set_justify_width(int width) { LOGWIDTH= width;	return (1); }

/*
 * Turn logging classes on or off
 */

int GUIlog_functions_on		(void)		{ ENTERING= 1;		return (1); }
int GUIlog_functions_off	(void)		{ ENTERING= 0;		return (1); }
int GUIlog_callbacks_on		(void)		{ CALLBACKS= 1;		return (1); }
int GUIlog_callbacks_off	(void)		{ CALLBACKS= 0;		return (1); }
int GUIlog_strings_on		(void)		{ STRINGS= 1;		return (1); }
int GUIlog_strings_off		(void)		{ STRINGS= 0;		return (1); }
int GUIlog_win_msg_on		(void) 		{ WIN_MSG= 1; 		return (1); }
int GUIlog_win_msg_off		(void)		{ WIN_MSG= 0;		return (1); }

/*
 * GUIset_log_filename -- This routine sets the debug file name
 */

int GUIlog_set_filename(char *name)
{
	if (fpDPTR) { // Log file was already open with another name
		fclose (fpDPTR);
		fpDPTR= NULL;
	}
    strcpy(DEBUGFILE, name);	// Store new filename
	DONEDEBUGFILE= 0;			// Set to 0 so that filename gets opened again
	return (1);
}

/*
 * GUIlog_open_logfile -- This routine opens the debug file
 */

static int GUIlog_open_logfile(void)
{
	time_t	current_time;
	char 	*current_time_string;

	if (!DONEDEBUGFILE) {
		char *envstr;
		envstr= getenv (ENVVARNAME);
		if (envstr!=NULL)
		sprintf (FULLDEBUGFILE, "%s\\%s", envstr, DEBUGFILE);
		else
		strcpy (FULLDEBUGFILE, DEBUGFILE);
		DONEDEBUGFILE= 1;
	}
	errno= 0; // Before call to fopen
    if (DEBUG) fpDPTR= fopen( FULLDEBUGFILE, "w" );
	if (fpDPTR) {
		current_time= time ( NULL );
		current_time_string= ctime (&current_time);
		fprintf (fpDPTR,
			"Started \"%s\" on %s=============================================\n",
			FULLDEBUGFILE, current_time_string );
		if (DOSLOWDUMP) {
			fflush (fpDPTR);
		}
	} else {
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
 */

int GUIlog2 (char *FUNC, char *FILE, int LINE, char *format, ...)
{
	int 		ret, length, len1, len2;
	char		_format[128]= "\0";
	char		_format2[128]= "\0", *pos;
	char		_format3[32]= "\0";
	char		*blanks= "  ";
	
    if (!DEBUG) return (0);
	if (!ENTERING&&(ENTERING_FORMAT==format)) return (0);
	if (!CALLBACKS&&(CALLBACK_FORMAT==format)) return (0);
	if (!STRINGS&&(STRINGS_FORMAT==format)) return (0);
	if (!WIN_MSG&&(WIN_MSG_FORMAT==format)) return (0);
    if (strlen (format) != 0)
    {
        va_list arglist;

		if (!fpDPTR) GUIlog_open_logfile ();

		va_start (arglist, format);

		if (!JUSTIFY) {
			ret = vfprintf (fpDPTR, format, arglist);
			ret = fprintf  (fpDPTR, "\n");
		}
		else {

			ret = vsprintf (_format, format, arglist);
			len1= strlen (_format);
			// Extension:
			// search backwards for the last blank, so that
			// we just have the file name, not the relative pathname

			if (oldFILE!=FILE) {
				sprintf (_format2, "%s %s:%d", FILE, FUNC, LINE);
				oldFILE= FILE; 
			}
			else if (oldFUNC!=FUNC) {
				sprintf (_format2, "%s:%d", FUNC, LINE);
				oldFUNC= FUNC;
			}
			else {
				sprintf (_format2, ":%d", LINE);
				oldLINE= LINE;
			}
			pos= strrchr (_format2, '\\');
			if (pos!=NULL) pos++;
//				_format2= *(_format2)+pos+1;
			
			if (pos==NULL) 	len2= strlen (_format2);
			else			len2= strlen (pos);
			
			length= LOGWIDTH-len1-len2;

			// ret should return total # of characterss printed, hopefully
			// the same value as LOGWIDTH.  This may not work if this is
			// not compiled as C99.
			sprintf (_format3, "%%s %%%ds %%s\n", length);
			if (pos==NULL) 	ret= fprintf(fpDPTR, _format3, _format, blanks, _format2);
			else			ret= fprintf(fpDPTR, _format3, _format, blanks, pos);
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
    GUIset_log_mode( 1 );          	// 1 to turn on standard tracing, usually 1
    GUIset_crash_mode(0);        	// 1 to turn on crash-resistant log file writing (slow!), usually 0
    GUIopen_debug( );              	// open the debug file to start loggin
...
	GUIlog ("This will be written to the log file from routine %s\n",
		__FUNCTION__);
...
    GUIset_log_mode(0);        // 1 to turn on crash-resistant log file writing (slow!), usually 0
...
	GUIclose_log ();	// Close everything down when closing program

Here's how I would like the log file to look:

Started Aug 20 2021 16:42:27 in GUIopen_log in ..\c\guilog.c(64)
Entered GUIXMain 											      guixwind.c(272)
Entered GUIInitDialog 										       guixdlg.c(810)
Entered GUIInitDialogFuncDlgProc 							                (756)
MSG WM_WINDOWCREATE(48) GUIInitDialogFuncDlgProc 							(757)
Entered GUIInitDialogFuncDlgProc 							 		 	    (756)
MSG 272(272) GUIInitDialogFuncDlgProc 						 		 	    (757)
Entered GUIInitDialogFuncDlgProc 							 		 		(756)
MSG 70(70) GUIInitDialogFuncDlgProc 						 				(757)
Entered GUIInitDialogFuncDlgProc 							 				(756)
MSG 295(295) GUIInitDialogFuncDlgProc 						 				(757)
Entered GUIInitDialogFuncDlgProc 							 				(756)
MSG 144(144) GUIInitDialogFuncDlgProc 						 				(757)
Entered GUIInitDialogFuncDlgProc 							 				(756)
MSG 2(2) GUIInitDialogFuncDlgProc 							 				(757)
Entered GUIInitDialogFuncDlgProc 							 				(756)
MSG 130(130) GUIInitDialogFuncDlgProc 						 				(757)
Entered InitSystemRGB 											  guicolor.c(283)
Entered GUIGetCtrlWnd 											  guicontr.c(100)
Entered GUIGetCtrlWnd 										                (100)
Entered GUIGetCtrlWnd 										                (100)
Entered GUIGetClientRect 									  ..\c\guicrect.c(45)
...																			   */
}

/*
 * strmsgenum -- In this routine, I will try to get at the name of an
 *               arglist value by examining the info available in the
 *               argument list, which hopefully will supply the type of
 *               the enum and a pointer to its list values.  I note that
 *               this is done in the debugger, so hopefully I can reverse
 *               engineer the process here.
 */

char *strmsgenum (char *dummy, ...) { // Actually only 1 parameter, but need to get at list
	va_list		arglist;
	char 		*msg;

	va_start (arglist, dummy);
	msg= (char *)va_arg ( arglist, WINDOW_MSG );
	va_end (arglist);
	return ("This is a test");
}
