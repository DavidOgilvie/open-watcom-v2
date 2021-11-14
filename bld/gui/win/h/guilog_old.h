/*
  DEBUG.H  Update History

Version  Date          Updated by        Comments
-------  ------------  ----------------  ----------------
0.00     May 15, 2000  D. Ogilvie        Original version
*/

// Window messages enum

typedef enum {
 _WM_NULL=0x0000,                         // 0x0000
 _WM_CREATE,                              // 0x0001
 _WM_DESTROY,                             // 0x0002
 _WM_MOVE,                                // 0x0003
 _WM_SIZE=0x0005,                         // 0x0005
 _WM_ACTIVATE,                            // 0x0006
 _WM_SETFOCUS,                            // 0x0007
 _WM_KILLFOCUS,                           // 0x0008
 _WM_ENABLE=0x000A,                       // 0x000A
 _WM_SETREDRAW,                           // 0x000B
 _WM_SETTEXT,                             // 0x000C
 _WM_GETTEXT,                             // 0x000D
 _WM_GETTEXTLENGTH,                       // 0x000E
 _WM_PAINT,                               // 0x000F
 _WM_CLOSE,                               // 0x0010
 _WM_QUERYENDSESSION,                     // 0x0011
 _WM_QUIT,                                // 0x0012
 _WM_QUERYOPEN,                           // 0x0013
 _WM_ERASEBKGND,                          // 0x0014
 _WM_SYSCOLORCHANGE,                      // 0x0015
 _WM_ENDSESSION,                          // 0x0016
 _WM_SHOWWINDOW=0x0018,                   // 0x0018
 _WM_WININICHANGE=0x001A,                 // 0x001A
#if (WINVER >= 0x0400)
 _WM_SETTINGCHANGE=0x001A,                // 0x001A
#endif
 _WM_DEVMODECHANGE=0x001B,                // 0x001B
 _WM_ACTIVATEAPP,                         // 0x001C
 _WM_FONTCHANGE,                          // 0x001D
 _WM_TIMECHANGE,                          // 0x001E
 _WM_CANCELMODE,                          // 0x001F
 _WM_SETCURSOR,                           // 0x0020
 _WM_MOUSEACTIVATE,                       // 0x0021
 _WM_CHILDACTIVATE,                       // 0x0022
 _WM_QUEUESYNC,                           // 0x0023
 _WM_GETMINMAXINFO,                       // 0x0024
 _WM_PAINTICON=0x0026,                    // 0x0026
 _WM_ICONERASEBKGND,                      // 0x0027
 _WM_NEXTDLGCTL,                          // 0x0028
 _WM_SPOOLERSTATUS=0x002A,                // 0x002A
 _WM_DRAWITEM,                            // 0x002B
 _WM_MEASUREITEM,                         // 0x002C
 _WM_DELETEITEM,                          // 0x002D
 _WM_VKEYTOITEM,                          // 0x002E
 _WM_CHARTOITEM,                          // 0x002F
 _WM_SETFONT,                             // 0x0030
 _WM_GETFONT,                             // 0x0031
 _WM_SETHOTKEY,                           // 0x0032
 _WM_GETHOTKEY,                           // 0x0033
 _WM_QUERYDRAGICON=0x0037,                // 0x0037
 _WM_COMPAREITEM=0x0039,                  // 0x0039
#if (WINVER >= 0x0500)
 _WM_GETOBJECT=0x003D,                    // 0x003D
#endif
 _WM_COMPACTING=0x0041,                   // 0x0041
 _WM_COMMNOTIFY=0x0044,                   // 0x0044
 _WM_WINDOWPOSCHANGING=0x0046,            // 0x0046
 _WM_WINDOWPOSCHANGED,                    // 0x0047
 _WM_POWER,                                // 0x0048
 _WM_COPYDATA=0x004A,                     // 0x004A
 _WM_CANCELJOURNAL,                        // 0x004B
#if (WINVER >= 0x0400)
 _WM_NOTIFY=0x004E,                       // 0x004E
 _WM_INPUTLANGCHANGEREQUEST=0x0050,       // 0x0050
 _WM_INPUTLANGCHANGE,                     // 0x0051
 _WM_TCARD,                               // 0x0052
 _WM_HELP,                                // 0x0053
 _WM_USERCHANGED,                         // 0x0054
 _WM_NOTIFYFORMAT,                        // 0x0055
 _WM_CONTEXTMENU=0x007B,                  // 0x007B
 _WM_STYLECHANGING,                       // 0x007C
 _WM_STYLECHANGED,                        // 0x007D
 _WM_DISPLAYCHANGE,                       // 0x007E
 _WM_GETICON,                             // 0x007F
 _WM_SETICON,                             // 0x0080
#endif
 _WM_NCCREATE=0x0081,                     // 0x0081
 _WM_NCDESTROY,                           // 0x0082
 _WM_NCCALCSIZE,                          // 0x0083
 _WM_NCHITTEST,                           // 0x0084
 _WM_NCPAINT,                             // 0x0085
 _WM_NCACTIVATE,                          // 0x0086
 _WM_GETDLGCODE,                          // 0x0087
 _WM_SYNCPAINT,                           // 0x0088
 _WM_NCMOUSEMOVE=0x00A0,                  // 0x00A0
 _WM_NCLBUTTONDOWN,                       // 0x00A1
 _WM_NCLBUTTONUP,                         // 0x00A2
 _WM_NCLBUTTONDBLCLK,                     // 0x00A3
 _WM_NCRBUTTONDOWN,                       // 0x00A4
 _WM_NCRBUTTONUP,                         // 0x00A5
 _WM_NCRBUTTONDBLCLK,                     // 0x00A6
 _WM_NCMBUTTONDOWN,                       // 0x00A7
 _WM_NCMBUTTONUP,                         // 0x00A8
 _WM_NCMBUTTONDBLCLK,                     // 0x00A9
#if (_WIN32_WINNT >= 0x0500)
 _WM_NCXBUTTONDOWN=0x00AB,                // 0x00AB
 _WM_NCXBUTTONUP,                         // 0x00AC
 _WM_NCXBUTTONDBLCLK,                     // 0x00AD
#endif
#if (_WIN32_WINNT >= 0x0501)
 _WM_INPUT_DEVICE_CHANGE0x00FE,           // 0x00FE
 _WM_INPUT,                               // 0x00FF
#endif
 _WM_KEYFIRST=0x0100,                     // 0x0100
 _WM_KEYDOWN=0x0100,                      // 0x0100
 _WM_KEYUP,                               // 0x0101
 _WM_CHAR,                                // 0x0102
 _WM_DEADCHAR,                            // 0x0103
 _WM_SYSKEYDOWN,                          // 0x0104
 _WM_SYSKEYUP,                            // 0x0105
 _WM_SYSCHAR,                             // 0x0106
 _WM_SYSDEADCHAR,                         // 0x0107
#if (_WIN32_WINNT >= 0x0501)
 _WM_UNICHAR=0x0109,                      // 0x0109
 _WM_KEYLAST=0x0109,                      // 0x0109
#else
 _WM_KEYLAST=0x0108,                      // 0x0108
#endif
#if (WINVER >= 0x0400)
 _WM_IME_STARTCOMPOSITION=0x010D,         // 0x010D
 _WM_IME_ENDCOMPOSITION,                  // 0x010E
 _WM_IME_COMPOSITION,                     // 0x010F
 _WM_IME_KEYLAST=0x010F,                  // 0x010F
#endif
 _WM_INITDIALOG=0x0110,                   // 0x0110
 _WM_COMMAND,                             // 0x0111
 _WM_SYSCOMMAND,                          // 0x0112
 _WM_TIMER,                               // 0x0113
 _WM_HSCROLL,                             // 0x0114
 _WM_VSCROLL,                             // 0x0115
 _WM_INITMENU,                            // 0x0116
 _WM_INITMENUPOPUP,                       // 0x0117
#if (WINVER >= 0x0601)
 _WM_GESTURE=0x0119,                      // 0x0119
 _WM_GESTUREINPUT,                        // 0x011A
#endif
 _WM_MENUSELECT=0x011F,                   // 0x011F
 _WM_MENUCHAR,                            // 0x0120
 _WM_ENTERIDLE,                           // 0x0121
#if (WINVER >= 0x0500)
 _WM_MENURBUTTONUP,                       // 0x0122
 _WM_MENUDRAG,                            // 0x0123
 _WM_MENUGETOBJECT,                       // 0x0124
 _WM_UNINITMENUPOPUP,                     // 0x0125
 _WM_MENUCOMMAND,                         // 0x0126
#endif
#if (_WIN32_WINNT >= 0x0500)
 _WM_CHANGEUISTATE=0x0127,                // 0x0127
 _WM_UPDATEUISTATE,                       // 0x0128
 _WM_QUERYUISTATE,                        // 0x0129
#endif
 _WM_CTLCOLORMSGBOX=0x0132,               // 0x0132
 _WM_CTLCOLOREDIT,                        // 0x0133
 _WM_CTLCOLORLISTBOX,                     // 0x0134
 _WM_CTLCOLORBTN,                         // 0x0135
 _WM_CTLCOLORDLG,                         // 0x0136
 _WM_CTLCOLORSCROLLBAR,                   // 0x0137
 _WM_CTLCOLORSTATIC,                      // 0x0138
 _MN_GETHMENU=0x01E1,                     // 0x01E1
 _WM_MOUSEFIRST=0x0200,                   // 0x0200
 _WM_MOUSEMOVE=0x0200,                    // 0x0200
 _WM_LBUTTONDOWN,                         // 0x0201
 _WM_LBUTTONUP,                           // 0x0202
 _WM_LBUTTONDBLCLK,                       // 0x0203
 _WM_RBUTTONDOWN,                         // 0x0204
 _WM_RBUTTONUP,                           // 0x0205
 _WM_RBUTTONDBLCLK,                       // 0x0206
 _WM_MBUTTONDOWN,                         // 0x0207
 _WM_MBUTTONUP,                           // 0x0208
 _WM_MBUTTONDBLCLK,                       // 0x0209
#if (_WIN32_WINNT >= 0x0400) || (_WIN32_WINDOWS > 0x0400)
 _WM_MOUSEWHEEL,                          // 0x020A
#endif
#if (_WIN32_WINNT >= 0x0500)
 _WM_XBUTTONDOWN=0x020B,                  // 0x020B
 _WM_XBUTTONUP,                           // 0x020C
 _WM_XBUTTONDBLCLK,                       // 0x020D
#endif
#if (_WIN32_WINNT >= 0x0600)
 _WM_MOUSEHWHEEL=0x020E,                  // 0x020E
 _WM_MOUSELAST=0x020E,                    // 0x020E
#elif (_WIN32_WINNT >= 0x0500)
 _WM_MOUSELAST=0x020D,                    // 0x020D
#elif (_WIN32_WINNT >= 0x0400) || (_WIN32_WINDOWS > 0x0400)
 _WM_MOUSELAST=0x020A,                    // 0x020A
#else
 _WM_MOUSELAST=0x0209,                    // 0x0209
#endif
 _WM_PARENTNOTIFY=0x0210,                 // 0x0210
 _WM_ENTERMENULOOP,                       // 0x0211
 _WM_EXITMENULOOP,                        // 0x0212
#if (WINVER >= 0x0400)
 _WM_NEXTMENU,                            // 0x0213
 _WM_SIZING,                              // 0x0214
 _WM_CAPTURECHANGED,                      // 0x0215
 _WM_MOVING,                              // 0x0216
 _WM_POWERBROADCAST=0x0218,               // 0x0218
 _WM_DEVICECHANGE,                        // 0x0219
#endif
 _WM_MDICREATE=0x0220,                    // 0x0220
 _WM_MDIDESTROY,                          // 0x0221
 _WM_MDIACTIVATE,                         // 0x0222
 _WM_MDIRESTORE,                          // 0x0223
 _WM_MDINEXT,                             // 0x0224
 _WM_MDIMAXIMIZE,                         // 0x0225
 _WM_MDITILE,                             // 0x0226
 _WM_MDICASCADE,                          // 0x0227
 _WM_MDIICONARRANGE,                      // 0x0228
 _WM_MDIGETACTIVE,                        // 0x0229
 _WM_MDISETMENU=0x0230,                   // 0x0230
 _WM_ENTERSIZEMOVE,                       // 0x0231
 _WM_EXITSIZEMOVE,                        // 0x0232
 _WM_DROPFILES,                           // 0x0233
 _WM_MDIREFRESHMENU,                      // 0x0234
#if (WINVER >= 0x0601)
 _WM_TOUCH=0x0240,                        // 0x0240
#endif
#if (WINVER >= 0x0400)
 _WM_IME_SETCONTEXT=0x0281,               // 0x0281
 _WM_IME_NOTIFY,                          // 0x0282
 _WM_IME_CONTROL,                         // 0x0283
 _WM_IME_COMPOSITIONFULL,                 // 0x0284
 _WM_IME_SELECT,                          // 0x0285
 _WM_IME_CHAR,                            // 0x0286
#endif
#if (WINVER >= 0x0500)
 _WM_IME_REQUEST=0x0288,                  // 0x0288
#endif
#if (WINVER >= 0x0400)
 _WM_IME_KEYDOWN=0x0290,                  // 0x0290
 _WM_IME_KEYUP,                           // 0x0291
#endif
#if (WINVER >= 0x0500)
 _WM_NCMOUSEHOVER=0x02A0,                 // 0x02A0
#endif
#if (_WIN32_WINNT >= 0x0400) || (WINVER >= 0x0500)
 _WM_MOUSEHOVER=0x02A1,                   // 0x02A1
#endif
#if (WINVER >= 0x0500)
 _WM_NCMOUSELEAVE=0x02A2,                 // 0x02A2
#endif
#if (_WIN32_WINNT >= 0x0400) || (WINVER >= 0x0500)
 _WM_MOUSELEAVE=0x02A3,                   // 0x02A3
#endif
#if (_WIN32_WINNT >= 0x0501)
 _WM_WTSSESSION_CHANGE=0x02B1,            // 0x02B1
 _WM_TABLET_FIRST=0x02C0,                 // 0x02C0
 _WM_TABLET_LAST=0x02DF,                  // 0x02DF
#endif
 _WM_CUT=0x0300,                          // 0x0300
 _WM_COPY,                                // 0x0301
 _WM_PASTE,                               // 0x0302
 _WM_CLEAR,                               // 0x0303
 _WM_UNDO,                                // 0x0304
 _WM_RENDERFORMAT,                        // 0x0305
 _WM_RENDERALLFORMATS,                    // 0x0306
 _WM_DESTROYCLIPBOARD,                    // 0x0307
 _WM_DRAWCLIPBOARD,                       // 0x0308
 _WM_PAINTCLIPBOARD,                      // 0x0309
 _WM_VSCROLLCLIPBOARD,                    // 0x030A
 _WM_SIZECLIPBOARD,                       // 0x030B
 _WM_ASKCBFORMATNAME,                     // 0x030C
 _WM_CHANGECBCHAIN,                       // 0x030D
 _WM_HSCROLLCLIPBOARD,                    // 0x030E
 _WM_QUERYNEWPALETTE,                     // 0x030F
 _WM_PALETTEISCHANGING,                   // 0x0310
 _WM_PALETTECHANGED,                      // 0x0311
 _WM_HOTKEY,                              // 0x0312
#if (WINVER >= 0x0400)
 _WM_PRINT=0x0317,                        // 0x0317
 _WM_PRINTCLIENT,                         // 0x0318
#endif
#if (_WIN32_WINNT >= 0x0500)
 _WM_APPCOMMAND=0x0319                    // 0x0319
#endif
#if (_WIN32_WINNT >= 0x0501)
 _WM_THEMECHANGED=0x031A,                 // 0x031A
#endif
#if (_WIN32_WINNT >= 0x0501)
 _WM_CLIPBOARDUPDATE=0x031D,              // 0x031D
#endif
#if (_WIN32_WINNT >= 0x0600)
 _WM_DWMCOMPOSITIONCHANGED=0x031E,        // 0x031E
 _WM_DWMNCRENDERINGCHANGED,               // 0x031F
 _WM_DWMCOLORIZATIONCOLORCHANGED,         // 0x0320
 _WM_DWMWINDOWMAXIMIZEDCHANGED,           // 0x0321
#endif
#if (_WIN32_WINNT >= 0x0601)
 _WM_DWMSENDICONICTHUMBNAIL=0x0323,       // 0x0323
 _WM_DWMSENDICONICLIVEPREVIEWBITMAP=0x0326,// 0x0326
#endif
#if (WINVER >= 0x0600)
 _WM_GETTITLEBARINFOEX=0x033F,            // 0x033F
#endif
#if (WINVER >= 0x0400)
 _WM_HANDHELDFIRST=0x0358,                // 0x0358
 _WM_HANDHELDLAST=0x035F,                 // 0x035F
 _WM_AFXFIRST,                            // 0x0360
 _WM_AFXLAST=0x037F,                      // 0x037F
#endif
 _WM_PENWINFIRST=0x0380,                  // 0x0380
 _WM_PENWINLAST=0x038F,                   // 0x038F
 _WM_USER=0x0400,                         // 0x0400
#if (WINVER >= 0x0400)
 _WM_APP=0x8000,                          // 0x8000
#endif
 _WM_DUMMY
} WINDOW_MSG;

/*
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

