//      GUIDEBUG.C  Update History
//
//      Copyright 2001, David Ogilvie, Ogilvie Consulting, All rights reserved
//
//      Description:
//
//      Version  Date          Updated by        Comments
//      -------  ------------  ----------------  ----------------------------
//      0.00     May 15, 2000  David Ogilvie     Original version
//		0.10	 Aug 18, 2021  David Ogilvie	 Revamped for OW GUI
//		0.20	 Aug 20, 2021  David Ogilvie	 Added right justification

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <io.h>
#include <errno.h>
#include "guiwind.h"
//#include "guicolor.h"
//#include "guimenus.h"
//#include "guiscale.h"
#include "guixutil.h"
#include "guilog.h"

static  FILE    *fpDPTR= NULL;					// File pointer to filename
static  char    DEBUGFILE[128]= "gui.log"; 		// Default filename
static  char    FULLDEBUGFILE[128]; 			// <EMVVAR>+filename
static  char    ENVVARNAME[128]= "zzzz"; 		// Sets environment variable to use
static	int		DONEDEBUGFILE= 0;				// Becomes true once <owroot> is added
static  int     DEBUG= 0;						// Logging turned off by default
static  int     DOSLOWDUMP= 0;					// Crash-proof logging turned off
static	int		LOGWIDTH= 78;					// Width of log if justified
static	int		JUSTIFY= 1;						// Put routine and line number on right
	
/* -----------------------------------------------------------------------
*   This routine sets the environment variable name that is prepended to
*	the log file name.                                                  */

int GUIset_log_envvar (char *envname)
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
	
/* -----------------------------------------------------------------------
*   This routine sets the debug mode
*	0= off, don't write to log file
*	1= on, write to log file                                            */

int GUIset_log_mode(int mode)
{
    DEBUG= mode;
	return (1);
}

/* -----------------------------------------------------------------------
*    This routine sets the debug crash mode (very slow)
*	 Log file is flushed to disk after each call                        */

int GUIset_crash_mode(int mode)
{
    DOSLOWDUMP= mode;
	return (1);
}

/* -----------------------------------------------------------------------
*   This routine sets the debug file name                               */

int GUIset_log_filename(char *name)
{
	if (fpDPTR) { // Log file was already open with another name
		fclose (fpDPTR);
		fpDPTR= NULL;
	}
    strcpy(DEBUGFILE, name);	// Store new filename
	DONEDEBUGFILE= 0;			// Set to 0 so that filename gets opened again
	return (1);
}

/* -----------------------------------------------------------------------
*   This routine opens the debug file                                   */
	
int GUIopen_log(void)
{
	if (!DONEDEBUGFILE) {
		char *envstr;
		envstr= getenv (ENVVARNAME);
		if (envstr!=NULL)
		sprintf (FULLDEBUGFILE, "%s\\%s", envstr, DEBUGFILE);
		else
		sprintf (FULLDEBUGFILE, "%s", DEBUGFILE);
		DONEDEBUGFILE= 1;
	}
	errno= 0; // Before call to fopen
    if (DEBUG) fpDPTR= fopen( FULLDEBUGFILE, "w" );
	if (fpDPTR) {
		GUIlog ("Started %s %s in ""%s"" in %s(%d)\n",
			__DATE__, __TIME__, __FUNCTION__, __FILE__, __LINE__ );
	} else {
		GUIErrorSA ("Error %d opening log file ""%s"".\n%s.", 
		errno, FULLDEBUGFILE, strerror ( errno ) );
		exit (1);
	}
	return (1);
}

/* -----------------------------------------------------------------------
*   This routine closes the debug file                                  */
	
int GUIclose_log(void)
{
    if (DEBUG) fclose(fpDPTR);
	return (1);
}

/* -----------------------------------------------------------------------
*   This routine sets the width of the log file, if right justified     */
	
int GUIlog_width (int width)
{
    LOGWIDTH= width;
	return (1);
}

/* -----------------------------------------------------------------------
*   This routine sets whether right justify mode is on or off. If it is set
*	to on, the calling routine must supply __FUNCTION__ and __LINE__ as the
*	last 2 parameters of the call.  At some point I will try to find out 
*	how to find the file and line number of the calling routine.  This will 
*	likely be in the Code > Callers menu item.  Until then, this will have 
*	to do. Note that turning this on and off can have parts of the log file
*	with justification, but part of the log that deals with a long string 
*   of events within a small portion of the same file can have justification
*	disabled.  (Saves on file size and time.)                           */

int GUIjustify (int value)
{
    JUSTIFY= value;
	return (1);
}

/* -----------------------------------------------------------------------
*   This routine writes a record to the debug file, ensuring that it is
*   written to the disk.                                               */

int GUIlog (char *format, ...)
{
    int ret;

    if (!DEBUG) return (0);
    if (strlen (format) != 0)
    {
        va_list arglist;
        va_start (arglist, format);
		if (!fpDPTR) GUIopen_log ();
		if (!JUSTIFY)
			ret = vfprintf (fpDPTR, format, arglist);
		else {
			/* If justification is turned on, then there should be 
			some stuff on the left, then a blank, then the module
			path and the line number.  If I search from the end of
			the string to the first blank, change that blank to abort
			null character, then I'll have two strings, one with the
			left side and the other with the right side.  I can then 
			search backwards on the right side to see if there is a 
			backslash that might be just to the left of the relative
			path.  I can then move the pointer of the right side 
			string right one character to get the beginning of the 
			module name.  For example
			    Entered module HELP ..\..\dohelp.c(46)\n
			                       ^     ^
			             last blank     last backslash
			If I put /0 at the blank and put the start of the second 
			line right by one character, I get the two stringss:
			"   Entered module HELP" and "dohelp.c(46)\n"
			I can then esily calculate the number of blanks needed to
			pad the line.  I can then do a sprintf of the two string
			and the padding count as follows
			sprintf (strfmt, "%s\%%d%s", str1, count str2)
			If you need 20 blanks, the string would become
			"   Entered module HELP%20sdohelp.c(46)\n"
			and you can print it with fprintf with
			fprintf (fpDPTR, string, " ");
			The blank will be padded to 20 characters			*/
			 
/*
			char	_format[128]= "\0";
			ret = vsprintf (_format, format, arglist);
			int len1= stelen (_format);
			// search backwards for the last blank, so that 
			// we just have the file name, not the relative pathname
			int loc = strrchr (_format, " ");
			*_format+loc= "\0";
			// get the length of the second part of the string from
			// the character after the last /.
			lnt length= LOG_WIDTH-(loc-loc2);
			// Calculate the number of spaces we need to pad the line 
			// so that the right end if justified at the correct column
			int i= *loc-*_format;
			// Create the formatting string for the fprintf call.
			char fmtstr[]= _format//i//_format2;
			// now call fprintf with the correct string
			ret= fprintf (fpDPTR, fmtstr, _format, " ", _format2);
			
*/
		}
        if (ret < 0)
        {
            GUIError ("GuiLog failed with error %d\n%s", ret, strerror (ret) );
        }        
		va_end (arglist);
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

/* -----------------------------------------------------------------------
 * In this routine, I will try to get at the name of an arglist value
 * by examining the info available in the argument list, which hopefully
 * will supply the type of the enum and a pointer to its list values.
 * I note that this is done in the debugger, so hopefully I can reverse
 * engineer the process here.                                          */
 
char *strmsgenum (char *dummy, ...) { // Actually only 1 parameter, but need to get at list
	va_list		arglist;
	char 		*msg;
	
	va_start (arglist, dummy);
	msg= (char *)va_arg ( arglist, WINDOW_MSG );
	va_end (arglist);
	return (*msg);
}
