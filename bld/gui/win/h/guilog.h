/*
  DEBUG.H  Update History

Version  Date          Updated by        Comments
-------  ------------  ----------------  ----------------
0.00     May 15, 2000  D. Ogilvie        Original version

  Prototypes
*/
#ifndef GUILOG 
	#define DOEXTERN extern
#else
	#define DOEXTERN
#endif

DOEXTERN int	GUIset_log_filename (char *);	// Set log file name
DOEXTERN int	GUIset_log_envvar (char *);		// Set log file environment name
DOEXTERN int	GUIopen_log (void);				// Opens log file (gui.log in root air)
DOEXTERN int	GUIset_log_mode (int);			// Turns logging on or off
DOEXTERN int	GUIset_crash_mode (int);		// Crash-proof looging on or off
DOEXTERN int	GUIlog (char *format, ...);		// Write to the log file
DOEXTERN int	GUIclose_log (void);			// Close log file
DOEXTERN int	GUIlog_width (int width);		// Close log file
DOEXTERN int	GUIjustify (int value);			// Close log file
DOEXTERN char  *strmsgenum (char *, ...);			// This has 1 paramerter, the enum
												// but we need the dummy parameter for 
												// va_list to work
