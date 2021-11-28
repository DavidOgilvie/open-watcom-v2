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
 * Version  Date          Updated by        Comments
 * -------  ------------  --------------  ----------------
 * 0.00     May 15, 2000   D. Ogilvie      Original version
 * 0.10     Aug 26, 2021   D. Ogilvie      Added window messages enum
 * 0.20     Nov 15, 2021   D. Ogilvie      Added class formats, prototypes and macros
 */

// Window messages enum

typedef enum {                              //  Hex   Dec
 _WM_NULL                         = 0x0000, // 0x0000 0
 _WM_CREATE,                                // 0x0001 1
 _WM_DESTROY,                               // 0x0002 2
 _WM_MOVE,                                  // 0x0003 3
 _WM_SIZE                         = 0x0005, // 0x0005 5
 _WM_ACTIVATE,                              // 0x0006 6
 _WM_SETFOCUS,                              // 0x0007 7
 _WM_KILLFOCUS,                             // 0x0008 8
 _WM_ENABLE                       = 0x000A, // 0x000A 10
 _WM_SETREDRAW,                             // 0x000B 11
 _WM_SETTEXT,                               // 0x000C 12
 _WM_GETTEXT,                               // 0x000D 13
 _WM_GETTEXTLENGTH,                         // 0x000E 14
 _WM_PAINT,                                 // 0x000F 15
 _WM_CLOSE,                                 // 0x0010 16
 _WM_QUERYENDSESSION,                       // 0x0011 17
 _WM_QUIT,                                  // 0x0012 18
 _WM_QUERYOPEN,                             // 0x0013 19
 _WM_ERASEBKGND,                            // 0x0014 20
 _WM_SYSCOLORCHANGE,                        // 0x0015 21
 _WM_ENDSESSION,                            // 0x0016 22
 _WM_SHOWWINDOW                   = 0x0018, // 0x0018 24
 _WM_WININICHANGE                 = 0x001A, // 0x001A 26
#if (WINVER >= 0x0400)
 _WM_SETTINGCHANGE                = 0x001A, // 0x001A 26
#endif  // of #if (WINVER >= 0x0400)
 _WM_DEVMODECHANGE                = 0x001B, // 0x001B 27
 _WM_ACTIVATEAPP,                           // 0x001C 28
 _WM_FONTCHANGE,                            // 0x001D 29
 _WM_TIMECHANGE,                            // 0x001E 30
 _WM_CANCELMODE,                            // 0x001F 31
 _WM_SETCURSOR,                             // 0x0020 32
 _WM_MOUSEACTIVATE,                         // 0x0021 33
 _WM_CHILDACTIVATE,                         // 0x0022 34
 _WM_QUEUESYNC,                             // 0x0023 35
 _WM_GETMINMAXINFO,                         // 0x0024 36
 _WM_PAINTICON                    = 0x0026, // 0x0026 38
 _WM_NEXTDLGCTL,                            // 0x0028 40
 _WM_ICONERASEBKGND,                        // 0x0027 39
 _WM_SPOOLERSTATUS                = 0x002A, // 0x002A 42
 _WM_MEASUREITEM,                           // 0x002C 44
 _WM_DRAWITEM,                              // 0x002B 43
 _WM_DELETEITEM,                            // 0x002D 45
 _WM_VKEYTOITEM,                            // 0x002E 46
 _WM_CHARTOITEM,                            // 0x002F 47
 _WM_SETFONT,                               // 0x0030 48
 _WM_GETFONT,                               // 0x0031 49
 _WM_SETHOTKEY,                             // 0x0032 50
 _WM_GETHOTKEY,                             // 0x0033 51
 _WM_QUERYDRAGICON                = 0x0037, // 0x0037 55
 _WM_COMPAREITEM                  = 0x0039, // 0x0039 57
#if (WINVER >= 0x0500)
 _WM_GETOBJECT                    = 0x003D, // 0x003D 61
#endif  // of #if (WINVER >= 0x0500)
 _WM_COMPACTING                   = 0x0041, // 0x0041 65
 _WM_COMMNOTIFY                   = 0x0044, // 0x0044 68
 _WM_WINDOWPOSCHANGING            = 0x0046, // 0x0046 70
 _WM_WINDOWPOSCHANGED,                      // 0x0047 71
 _WM_POWER,                                 // 0x0048 72
 _WM_COPYDATA                     = 0x004A, // 0x004A 74
 _WM_CANCELJOURNAL,                         // 0x004B 75
#if (WINVER >= 0x0400)
 _WM_NOTIFY                       = 0x004E, // 0x004E 78
 _WM_INPUTLANGCHANGEREQUEST       = 0x0050, // 0x0050 80
 _WM_INPUTLANGCHANGE,                       // 0x0051 81
 _WM_TCARD,                                 // 0x0052 82
 _WM_HELP,                                  // 0x0053 83
 _WM_USERCHANGED,                           // 0x0054 84
 _WM_NOTIFYFORMAT,                          // 0x0055 85
 _WM_CONTEXTMENU                  = 0x007B, // 0x007B 123
 _WM_STYLECHANGING,                         // 0x007C 124
 _WM_STYLECHANGED,                          // 0x007D 125
 _WM_DISPLAYCHANGE,                         // 0x007E 126
 _WM_GETICON,                               // 0x007F 127
 _WM_SETICON,                               // 0x0080 128
#endif  // of #if (WINVER >= 0x0400)
 _WM_NCCREATE                     = 0x0081, // 0x0081 129
 _WM_NCDESTROY,                             // 0x0082 130
 _WM_NCCALCSIZE,                            // 0x0083 131
 _WM_NCHITTEST,                             // 0x0084 132
 _WM_NCPAINT,                               // 0x0085 133
 _WM_NCACTIVATE,                            // 0x0086 134
 _WM_GETDLGCODE,                            // 0x0087 135
 _WM_SYNCPAINT,                             // 0x0088 136
                                            // 0x0090 144
 _WM_NCMOUSEMOVE                  = 0x00A0, // 0x00A0 160
 _WM_NCLBUTTONDOWN,                         // 0x00A1 161
 _WM_NCLBUTTONUP,                           // 0x00A2 162
 _WM_NCLBUTTONDBLCLK,                       // 0x00A3 163
 _WM_NCRBUTTONDOWN,                         // 0x00A4 164
 _WM_NCRBUTTONUP,                           // 0x00A5 165
 _WM_NCRBUTTONDBLCLK,                       // 0x00A6 166
 _WM_NCMBUTTONDOWN,                         // 0x00A7 167
 _WM_NCMBUTTONUP,                           // 0x00A8 168
 _WM_NCMBUTTONDBLCLK,                       // 0x00A9 169
#if (_WIN32_WINNT >= 0x0500)
 _WM_NCXBUTTONDOWN                = 0x00AB, // 0x00AB 171
 _WM_NCXBUTTONUP,                           // 0x00AC 172
 _WM_NCXBUTTONDBLCLK,                       // 0x00AD 173
#endif  // of #if (_WIN32_WINNT >= 0x0500)
#if (_WIN32_WINNT >= 0x0501)
 _WM_INPUT_DEVICE_CHANGE0x00FE,             // 0x00FE 255
 _WM_INPUT,                                 // 0x00FF 255
#endif  // of #if (_WIN32_WINNT >= 0x0501)
 _WM_KEYFIRST                     = 0x0100, // 0x0100 256
 _WM_KEYDOWN                      = 0x0100, // 0x0100 256
 _WM_KEYUP,                                 // 0x0101 257
 _WM_CHAR,                                  // 0x0102 258
 _WM_DEADCHAR,                              // 0x0103 259
 _WM_SYSKEYDOWN,                            // 0x0104 260
 _WM_SYSKEYUP,                              // 0x0105 261
 _WM_SYSCHAR,                               // 0x0106 262
 _WM_SYSDEADCHAR,                           // 0x0107 263
#if (_WIN32_WINNT >= 0x0501)
 _WM_UNICHAR                      = 0x0109, // 0x0109 265
 _WM_KEYLAST                      = 0x0109, // 0x0109 265
#else  // of #if (_WIN32_WINNT >= 0x0501)
 _WM_KEYLAST                      = 0x0108, // 0x0108 264
#endif  // of #else for #if (_WIN32_WINNT >= 0x0501)
#if (WINVER >= 0x0400)
 _WM_IME_STARTCOMPOSITION         = 0x010D, // 0x010D 269
 _WM_IME_ENDCOMPOSITION,                    // 0x010E 270
 _WM_IME_COMPOSITION,                       // 0x010F 271
 _WM_IME_KEYLAST                  = 0x010F, // 0x010F 271
#endif  // of #if (WINVER >= 0x0400)
 _WM_INITDIALOG                   = 0x0110, // 0x0110 272
 _WM_COMMAND,                               // 0x0111 273
 _WM_SYSCOMMAND,                            // 0x0112 274
 _WM_TIMER,                                 // 0x0113 275
 _WM_HSCROLL,                               // 0x0114 276
 _WM_VSCROLL,                               // 0x0115 277
 _WM_INITMENU,                              // 0x0116 278
 _WM_INITMENUPOPUP,                         // 0x0117 279
#if (WINVER >= 0x0601)
 _WM_GESTURE                      = 0x0119, // 0x0119 281
 _WM_GESTUREINPUT,                          // 0x011A 282
#endif  // of #if (WINVER >= 0x0601)
 _WM_MENUSELECT                   = 0x011F, // 0x011F 287
 _WM_MENUCHAR,                              // 0x0120 288
 _WM_ENTERIDLE,                             // 0x0121 289
#if (WINVER >= 0x0500)
 _WM_MENURBUTTONUP,                         // 0x0122 290
 _WM_MENUDRAG,                              // 0x0123 291
 _WM_MENUGETOBJECT,                         // 0x0124 292
 _WM_UNINITMENUPOPUP,                       // 0x0125 293
 _WM_MENUCOMMAND,                           // 0x0126 294
#endif  // of #if (WINVER >= 0x0500)
#if (_WIN32_WINNT >= 0x0500)
 _WM_CHANGEUISTATE                = 0x0127, // 0x0127 295
 _WM_UPDATEUISTATE,                         // 0x0128 296
 _WM_QUERYUISTATE,                          // 0x0129 297
#endif  // of #if (_WIN32_WINNT >= 0x0500)
 _WM_CTLCOLORMSGBOX               = 0x0132, // 0x0132 306
 _WM_CTLCOLOREDIT,                          // 0x0133 307
 _WM_CTLCOLORLISTBOX,                       // 0x0134 308
 _WM_CTLCOLORBTN,                           // 0x0135 309
 _WM_CTLCOLORDLG,                           // 0x0136 310
 _WM_CTLCOLORSCROLLBAR,                     // 0x0137 311
 _WM_CTLCOLORSTATIC,                        // 0x0138 312
 _MN_GETHMENU                     = 0x01E1, // 0x01E1 313
 _WM_MOUSEFIRST                   = 0x0200, // 0x0200 512
 _WM_MOUSEMOVE                    = 0x0200, // 0x0200 512
 _WM_LBUTTONDOWN,                           // 0x0201 513
 _WM_LBUTTONUP,                             // 0x0202 514
 _WM_LBUTTONDBLCLK,                         // 0x0203 515
 _WM_RBUTTONDOWN,                           // 0x0204 516
 _WM_RBUTTONUP,                             // 0x0205 517
 _WM_RBUTTONDBLCLK,                         // 0x0206 518
 _WM_MBUTTONDOWN,                           // 0x0207 219
 _WM_MBUTTONUP,                             // 0x0208 220
 _WM_MBUTTONDBLCLK,                         // 0x0209 221
#if (_WIN32_WINNT >= 0x0400) || (_WIN32_WINDOWS > 0x0400)
 _WM_MOUSEWHEEL,                            // 0x020A 222
#endif  // of #if (_WIN32_WINNT >= 0x0400) || (_WIN32_WINDOWS > 0x0400)
#if (_WIN32_WINNT >= 0x0500)
 _WM_XBUTTONDOWN                  = 0x020B, // 0x020B 223
 _WM_XBUTTONUP,                             // 0x020C 224
 _WM_XBUTTONDBLCLK,                         // 0x020D 225
#endif  // of #if (_WIN32_WINNT >= 0x0500)
#if (_WIN32_WINNT >= 0x0600)
 _WM_MOUSEHWHEEL                  = 0x020E, // 0x020E 226
 _WM_MOUSELAST                    = 0x020E, // 0x020E 227
 #elif (_WIN32_WINNT >= 0x0500)
 _WM_MOUSELAST                    = 0x020D, // 0x020D 225
 #elif (_WIN32_WINNT >= 0x0400) || (_WIN32_WINDOWS > 0x0400)
 _WM_MOUSELAST                    = 0x020A, // 0x020A 222
#else  // of #if (_WIN32_WINNT >= 0x0600)
 _WM_MOUSELAST                    = 0x0209, // 0x0209 527
#endif  // of #else for #if (_WIN32_WINNT >= 0x0600)
 _WM_PARENTNOTIFY                 = 0x0210, // 0x0210 528
 _WM_ENTERMENULOOP,                         // 0x0211 529
 _WM_EXITMENULOOP,                          // 0x0212 530
#if (WINVER >= 0x0400)
 _WM_NEXTMENU,                              // 0x0213 531
 _WM_SIZING,                                // 0x0214 532
 _WM_CAPTURECHANGED,                        // 0x0215 533
 _WM_MOVING,                                // 0x0216 534
 _WM_POWERBROADCAST               = 0x0218, // 0x0218 536
 _WM_DEVICECHANGE,                          // 0x0219 537
#endif  // of #if (WINVER >= 0x0400)
 _WM_MDICREATE                    = 0x0220, // 0x0220 544
 _WM_MDIDESTROY,                            // 0x0221 545
 _WM_MDIACTIVATE,                           // 0x0222 546
 _WM_MDIRESTORE,                            // 0x0223 547
 _WM_MDINEXT,                               // 0x0224 548
 _WM_MDIMAXIMIZE,                           // 0x0225 549
 _WM_MDITILE,                               // 0x0226 550
 _WM_MDICASCADE,                            // 0x0227 551
 _WM_MDIICONARRANGE,                        // 0x0228 552
 _WM_MDIGETACTIVE,                          // 0x0229 553
 _WM_MDISETMENU                   = 0x0230, // 0x0230 560
 _WM_ENTERSIZEMOVE,                         // 0x0231 561
 _WM_EXITSIZEMOVE,                          // 0x0232 562
 _WM_DROPFILES,                             // 0x0233 563
 _WM_MDIREFRESHMENU,                        // 0x0234 564
#if (WINVER >= 0x0601)
 _WM_TOUCH                        = 0x0240, // 0x0240 576
#endif  // of #if (WINVER >= 0x0601)
#if (WINVER >= 0x0400)
 _WM_IME_SETCONTEXT               = 0x0281, // 0x0281 641
 _WM_IME_NOTIFY,                            // 0x0282 642
 _WM_IME_CONTROL,                           // 0x0283 643
 _WM_IME_COMPOSITIONFULL,                   // 0x0284 644
 _WM_IME_SELECT,                            // 0x0285 645
 _WM_IME_CHAR,                              // 0x0286 646
#endif  // #if (WINVER >= 0x0400)
#if (WINVER >= 0x0500)
 _WM_IME_REQUEST                  = 0x0288, // 0x0288 648
#endif  // of #if (WINVER >= 0x0500)
#if (WINVER >= 0x0400)
 _WM_IME_KEYDOWN                  = 0x0290, // 0x0290 656
 _WM_IME_KEYUP,                             // 0x0291 657
#endif  // #if (WINVER >= 0x0400)
#if (WINVER >= 0x0500)
 _WM_NCMOUSEHOVER                 = 0x02A0, // 0x02A0 672
#endif  // of #if (WINVER >= 0x0500)
#if (_WIN32_WINNT >= 0x0400) || (WINVER >= 0x0500)
 _WM_MOUSEHOVER                   = 0x02A1, // 0x02A1 673
#endif  // of #if (_WIN32_WINNT >= 0x0400) || (WINVER >= 0x0500)
#if (WINVER >= 0x0500)
 _WM_NCMOUSELEAVE                 = 0x02A2, // 0x02A2 674
#endif  // of #if (WINVER >= 0x0500)
#if (_WIN32_WINNT >= 0x0400) || (WINVER >= 0x0500)
 _WM_MOUSELEAVE                   = 0x02A3, // 0x02A3 673
#endif  // of #if (_WIN32_WINNT >= 0x0400) || (WINVER >= 0x0500)
#if (_WIN32_WINNT >= 0x0501)
 _WM_WTSSESSION_CHANGE            = 0x02B1, // 0x02B1 689
 _WM_TABLET_FIRST                 = 0x02C0, // 0x02C0 706
 _WM_TABLET_LAST                  = 0x02DF, // 0x02DF 721
#endif  // of #if (_WIN32_WINNT >= 0x0501)
 _WM_CUT                          = 0x0300, // 0x0300 768
 _WM_COPY,                                  // 0x0301 769
 _WM_PASTE,                                 // 0x0302 770
 _WM_CLEAR,                                 // 0x0303 771
 _WM_UNDO,                                  // 0x0304 772
 _WM_RENDERFORMAT,                          // 0x0305 773
 _WM_RENDERALLFORMATS,                      // 0x0306 774
 _WM_DESTROYCLIPBOARD,                      // 0x0307 775
 _WM_DRAWCLIPBOARD,                         // 0x0308 776
 _WM_PAINTCLIPBOARD,                        // 0x0309 777
 _WM_VSCROLLCLIPBOARD,                      // 0x030A 778
 _WM_SIZECLIPBOARD,                         // 0x030B 779
 _WM_ASKCBFORMATNAME,                       // 0x030C 780
 _WM_CHANGECBCHAIN,                         // 0x030D 781
 _WM_HSCROLLCLIPBOARD,                      // 0x030E 782
 _WM_QUERYNEWPALETTE,                       // 0x030F 783
 _WM_PALETTEISCHANGING,                     // 0x0310 784
 _WM_PALETTECHANGED,                        // 0x0311 785
 _WM_HOTKEY,                                // 0x0312 786
#if (WINVER >= 0x0400)
 _WM_PRINT                        = 0x0317, // 0x0317 791
 _WM_PRINTCLIENT,                           // 0x0318 792
#endif  // of #if (WINVER >= 0x0400)
#if (_WIN32_WINNT >= 0x0500)
 _WM_APPCOMMAND                   = 0x0319, // 0x0319 793
#endif  // of #if (_WIN32_WINNT >= 0x0500)
#if (_WIN32_WINNT >= 0x0501)
 _WM_THEMECHANGED                 = 0x031A, // 0x031A 794
#endif  // of #if (_WIN32_WINNT >= 0x0501)
#if (_WIN32_WINNT >= 0x0501)
 _WM_CLIPBOARDUPDATE              = 0x031D, // 0x031D 797
#endif  // of #if (_WIN32_WINNT >= 0x0501)
#if (_WIN32_WINNT >= 0x0600)
 _WM_DWMCOMPOSITIONCHANGED        = 0x031E, // 0x031E 798
 _WM_DWMNCRENDERINGCHANGED,                 // 0x031F 799
 _WM_DWMCOLORIZATIONCOLORCHANGED,           // 0x0320 800
 _WM_DWMWINDOWMAXIMIZEDCHANGED,             // 0x0321 801
#endif  // of #if (_WIN32_WINNT >= 0x0600)
#if (_WIN32_WINNT >= 0x0601)
 _WM_DWMSENDICONICTHUMBNAIL       = 0x0323, // 0x0323 803
                                            // 0x0324 804
                                            // 0x0325 805
 _WM_DWMSENDICONICLIVEPREVIEWBITMAP=0x0326, // 0x0326 806
#endif  // of #if (_WIN32_WINNT >= 0x0601)
#if (WINVER >= 0x0600)
 _WM_GETTITLEBARINFOEX            = 0x033F, // 0x033F 851
#endif  // of #if (WINVER >= 0x0600)
#if (WINVER >= 0x0400)
 _WM_HANDHELDFIRST                = 0x0358, // 0x0358 856
 _WM_HANDHELDLAST                 = 0x035F, // 0x035F 863
 _WM_AFXFIRST,                              // 0x0360 864
 _WM_AFXLAST                      = 0x037F, // 0x037F 895
#endif  // of #if (WINVER >= 0x0400)
 _WM_PENWINFIRST                  = 0x0380, // 0x0380 896
 _WM_PENWINLAST                   = 0x038F, // 0x038F 911
                                            // 0x03e0 992
 _WM_USER                         = 0x0400, // 0x0400 1024
                                            // 0x0401 1024
#if (WINVER >= 0x0400)
                                            // 0x043c 1084
 _WM_APP                          = 0x8000, // 0x8000 32768
#endif  // of #if (WINVER >= 0x0400)
 _WM_DUMMY
} WINDOW_MSG;

// Logging class switches
#define log_all         0xFFFFFFFFUL    // log all claases
#define L_1             0xFFFFFFFFUL    // log all claases (short form)
#define log_none        0x00000000UL    // log no classes
#define L_0             0x00000000UL    // log no classes (short form)
#define log_function    0x00000001UL    // log function alls
#define L_EF            0x00000001UL    // log function alls (short form)
#define log_callback    0x00000002UL    // log callback function calls
#define L_EC            0x00000002UL    // log callback function calls (short cut)
#define log_win_msg     0x00000004UL    // log window messages
#define L_WM            0x00000004UL    // log window messages (short form)
#define log_scrolling   0x00000008UL    // log scrolling info
#define L_SC            0x00000008UL    // log scrolling info (short form)
#define log_mouse       0x00000010UL    // log mouse info
#define L_MO            0x00000010UL    // log mouse info (short form)
#define log_keyboard    0x00000020UL    // log keyboard and text info
#define L_KB            0x00000020UL    // log keyboard and text info (short form)
#define log_strings     0x00000040UL    // log strings info
#define L_ST            0x00000040UL    // log strings info (short form)
#define log_win_clr     0x00000080UL    // log colour info
#define L_WC            0x00000080UL    // log colour info (short form)
#define log_menu        0x00000100UL    // log menu info
#define l_mu            0x00000100UL    // log menu info (short form)
#define log_toolbar     0x00000200UL    // log toolbar info
#define l_tb            0x00000200UL    // log toolbar info (short form)
#define log_help        0x00000400UL    // log help info
#define l_hp            0x00000400UL    // log help info (short form)
#define log_focus       0x00000800UL    // log focus events
#define l_fo            0x00000800UL    // log focus events (short form)
#define log_font        0x00001000UL    // log font events
#define l_fn            0x00002000UL    // log font events (short form)
// Extra classes to be set up as needed
#define log_class15     0x00004000UL    //
#define log_class16     0x00008000UL    //
#define log_class17     0x00010000UL    //
#define log_class18     0x00020000UL    //
#define log_class19     0x00040000UL    //
#define log_class20     0x00080000UL    //
#define log_class21     0x00100000UL    //
#define log_class22     0x00200000UL    //
#define log_class23     0x00400000UL    //
#define log_class24     0x00800000UL    //
#define log_class25     0x01000000UL    //
#define log_class26     0x02000000UL    //
#define log_class27     0x08000000UL    //
#define log_class28     0x10000000UL    //
#define log_class29     0x20000000UL    //
#define log_class30     0x40000000UL    //
#define log_class31     0x80000000UL    //

// Helper routines
#ifdef _GUILOG_H_
    int __dummy__= 0;
    char __NaS__[]= "NaS";  // for use in e2s_ function
#else
    extern int __dummy__;
#endif
char *e2s_ (int __dummy__, ...);// Hopefully an enum value to string routine
                                // Nees to be defined here for macros to work

extern int GUIlog_set_logging_mode (int);         // Turns logging on or off
extern int GUIlog_set_logging_mode_from_ini ();   // Settings from guilog.ini on desktop
extern int GUIlog_set_filename (char *);          // Set log file name
extern int GUIlog_set_envvar (char *);            // Set log file environment name
extern int GUIlog_set_crash_mode (int);           // Crash-proof looging on or off
extern int GUIlog_set_justify_mode (int value);   // Set justification mode on/off
extern int GUIlog_set_justify_width (int width);  // Set justification width
extern int GUIlog_close_logfile (void);           // Close log file
// Loggin settings on/off
extern int GUIlog_justify_mode_on();              // Set justification mode on
extern int GUIlog_justify_mode_off();             // Set justification mode off
extern int GUIlog_crash_mode_on ();               // Crash-proof looging on
extern int GUIlog_crash_mode_off ();              // Crash-proof looging off
extern int GUIlog_logging_on();                   // Turns logging off temporarily
extern int GUIlog_logging_off();                  // Turns logging on after being paused
// Logging classes on/off
extern int GUIlog_functions_on ();                // Turn routine entering messages on
extern int GUIlog_functions_off ();               // Turn routine entering messages off
extern int GUIlog_callbacks_on ();                // Turn entering windprocs notices on
extern int GUIlog_callbacks_off ();               // Turn entering windprocs messages notices off
extern int GUIlog_strings_on ();                  // Turn entering strings notices on
extern int GUIlog_strings_off ();                 // Turn entering strings messages notices off
extern int GUIlog_win_clr_on ();                  // Turn window messages notices on
extern int GUIlog_win_clr_off ();                 // Turn window messages notices off
extern int GUIlog_win_msg_on ();                  // Turn window messages notices on
extern int GUIlog_win_msg_off ();                 // Turn window messages notices off
extern int GUIlog_mouse_on ();                    // Turn mouse events on
extern int GUIlog_mouse_off ();                   // Turn mouse events off
extern int GUIlog_keyboard_on ();                 // Turn keyboard events on
extern int GUIlog_keyboard_off ();                // Turn keyboard events off
extern int GUIlog_scrolling_on ();                // Turn scrolling eventson
extern int GUIlog_scrolling_off ();               // Turn scrolling events off
// Routines to print header info in log file
extern int GUIlog_print_timestamp ();             // Print timestamp in log file
extern int GUIlog_print_guilog_settings_ (char *FUNC, char *FILE, int LINE);

// Workhorse routine thaht makes this all possible
int GUIlog (unsigned long classes, char *format, ...); // Write to the log file
                                                       // uses macro guilog_


// Workhorse routine thaht makes this all possible
int GUIlog_ (char *FUNC, char *FILE, int LINE,
             unsigned long classes, char *format, ...);// Write to the log file
                                                       // string conversion routine

// The following defines functions that display the entry points into functions,
// set thier classes and show what type they return
extern void GUIlog_entering_bool_function();
extern void GUIlog_entering_bool_strings_function ();
extern void GUIlog_entering_callback ();
extern void GUIlog_entering_charptr_function();
extern void GUIlog_entering_control_item_function();
extern void GUIlog_entering_function ();
extern void GUIlog_entering_guix_ord_function();
extern void GUIlog_entering_gui_control_class_function();
extern void GUIlog_entering_gui_control_styles_function();
extern void GUIlog_entering_gui_help_instance_function();
extern void GUIlog_entering_gui_message_return_function();
extern void GUIlog_entering_gui_ord_function();
extern void GUIlog_entering_gui_scroll_styles_function();
extern void GUIlog_entering_gui_text_ord_function();
extern void GUIlog_entering_gui_window_function();
extern void GUIlog_entering_HAB_function();
extern void GUIlog_entering_HBRUSH_function();
extern void GUIlog_entering_HMENU_function();
extern void GUIlog_entering_HWND_function();
extern void GUIlog_entering_int_function();
extern void GUIlog_entering_UINTptr_callback ();
extern void GUIlog_entering_LONG_function();
extern void GUIlog_entering_LRESULT_function();
extern void GUIlog_entering_mcursor_function ();
extern void GUIlog_entering_mcursor_handle_function();
extern void GUIlog_entering_mouse_function();
extern void GUIlog_entering_size_t_function();
extern void GUIlog_entering_strings();
extern void GUIlog_entering_unsigned_function();
extern void GUIlog_entering_void_function();
extern void GUIlog_entering_wndproc_function();
extern void GUIlog_entering_WPI_COLOUR_function();
extern void GUIlog_entering_WPI_DLGRESULT_callback();
extern void GUIlog_entering_WPI_FONT_function();
extern void GUIlog_entering_WPI_INST_function();
extern void GUIlog_entering_WPI_MRESULT_callback();
extern void GUIlog_entering_WPI_MRESULT_function();
extern void GUIlog_entering_WPI_WNDPROC_function ();
extern void GUIlog_win_msg_ (HWND hwnd, WPI_MSG msg, WINDOW_MSG _msg, WPI_PARAM1 wparam, WPI_PARAM2 lparam );

// Macros
// General-purpose loggin function
// #define GUIlog(classes,format,...) (GUIlog_(__func__,__FILE__,__LINE__,classes,format,__VA_ARGS__))
#define GUIlog(classes,...) (GUIlog_(__func__,__FILE__,__LINE__,classes,__VA_ARGS__))
// Prints settings at beginning of log file
#define GUIlog_print_guilog_settings() GUIlog_print_guilog_settings_(__func__,__FILE__,__LINE__)
// Potential enum to string function (umder development)
#define e2s(...)                       (e2s_(int,__VA_ARGS__))
#define GUIlog_win_msg() (GUIlog_win_msg_ (hwnd, msg, _msg, wparam, lparam))
