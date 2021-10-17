/*
 *  wincon.h    Win32 console functions
 *
 * =========================================================================
 *
 *                          Open Watcom Project
 *
 * Copyright (c) 2004-2021 The Open Watcom Contributors. All Rights Reserved.
 *
 *    This file is automatically generated. Do not edit directly.
 *
 * =========================================================================
 */

#ifndef _WINCON_
#define _WINCON_

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file;
#endif

#include <wingdi.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Control key state flags */
#define RIGHT_ALT_PRESSED   0x00000001L
#define LEFT_ALT_PRESSED    0x00000002L
#define RIGHT_CTRL_PRESSED  0x00000004L
#define LEFT_CTRL_PRESSED   0x00000008L
#define SHIFT_PRESSED       0x00000010L
#define NUMLOCK_ON          0x00000020L
#define SCROLLLOCK_ON       0x00000040L
#define CAPSLOCK_ON         0x00000080L
#define ENHANCED_KEY        0x00000100L
#define NLS_DBCSCHAR        0x00010000L
#define NLS_ALPHANUMERIC    0x00000000L
#define NLS_KATAKANA        0x00020000L
#define NLS_HIRAGANA        0x00040000L
#define NLS_ROMAN           0x00400000L
#define NLS_IME_CONVERSION  0x00800000L
#define NLS_IME_DISABLE     0x20000000L

/* Mouse button state flags */
#define FROM_LEFT_1ST_BUTTON_PRESSED    0x00000001L
#define RIGHTMOST_BUTTON_PRESSED        0x00000002L
#define FROM_LEFT_2ND_BUTTON_PRESSED    0x00000004L
#define FROM_LEFT_3RD_BUTTON_PRESSED    0x00000008L
#define FROM_LEFT_4TH_BUTTON_PRESSED    0x00000010L

/* Mouse event flags */
#define MOUSE_MOVED         0x00000001L
#define DOUBLE_CLICK        0x00000002L
#define MOUSE_WHEELED       0x00000004L
#if (_WIN32_WINNT >= 0x0600)
    #define MOUSE_HWHEELED  0x00000008L
#endif

/* Console input event types */
#define KEY_EVENT                   0x00000001L
#define MOUSE_EVENT                 0x00000002L
#define WINDOW_BUFFER_SIZE_EVENT    0x00000004L
#define MENU_EVENT                  0x00000008L
#define FOCUS_EVENT                 0x00000010L

/* Console character attributes */
#define FOREGROUND_BLUE             0x00000001L
#define FOREGROUND_GREEN            0x00000002L
#define FOREGROUND_RED              0x00000004L
#define FOREGROUND_INTENSITY        0x00000008L
#define BACKGROUND_BLUE             0x00000010L
#define BACKGROUND_GREEN            0x00000020L
#define BACKGROUND_RED              0x00000040L
#define BACKGROUND_INTENSITY        0x00000080L
#define COMMON_LVB_LEADING_BYTE     0x00000100L
#define COMMON_LVB_TRAILING_BYTE    0x00000200L
#define COMMON_LVB_GRID_HORIZONTAL  0x00000400L
#define COMMON_LVB_GRID_LVERTICAL   0x00000800L
#define COMMON_LVB_GRID_RVERTICAL   0x00001000L
#define COMMON_LVB_REVERSE_VIDEO    0x00004000L
#define COMMON_LVB_UNDERSCORE       0x00008000L
#define COMMON_LVB_SBCSDBCS         0x00000300L

/* Console history flags */
#define HISTORY_NO_DUP_FLAG 0x00000001L

/* Console selection flags */
#if (_WIN32_WINNT >= 0x0500)
    #define CONSOLE_NO_SELECTION            0x00000000L
    #define CONSOLE_SELECTION_IN_PROGRESS   0x00000001L
    #define CONSOLE_SELECTION_NOT_EMPTY     0x00000002L
    #define CONSOLE_MOUSE_SELECTION         0x00000004L
    #define CONSOLE_MOUSE_DOWN              0x00000008L
#endif

/* Console control events */
#define CTRL_C_EVENT        0L
#define CTRL_BREAK_EVENT    1L
#define CTRL_CLOSE_EVENT    2L
#define CTRL_LOGOFF_EVENT   5L
#define CTRL_SHUTDOWN_EVENT 6L

/* Console input modes */
#define ENABLE_PROCESSED_INPUT  0x00000001L
#define ENABLE_LINE_INPUT       0x00000002L
#define ENABLE_ECHO_INPUT       0x00000004L
#define ENABLE_WINDOW_INPUT     0x00000008L
#define ENABLE_MOUSE_INPUT      0x00000010L
#define ENABLE_INSERT_MODE      0x00000020L
#define ENABLE_QUICK_EDIT_MODE  0x00000040L
#define ENABLE_EXTENDED_FLAGS   0x00000080L
#define ENABLE_AUTO_POSITION    0x00000100L

/* Console output modes */
#define ENABLE_PROCESSED_OUTPUT     0x00000001L
#define ENABLE_WRAP_AT_EOL_OUTPUT   0x00000002L

/* Console display modes */
#if (_WIN32_WINNT >= 0x0500)
    #define CONSOLE_FULLSCREEN          1L
    #define CONSOLE_FULLSCREEN_HARDWARE 2L
#endif

/* AttachConsole() special value */
#if (_WIN32_WINNT >= 0x0500)
    #define ATTACH_PARENT_PROCESS   0xFFFFFFFFL
#endif

/* CreateConsoleScreenBuffer() flags */
#define CONSOLE_TEXTMODE_BUFFER 0x00000001L

/* Special console handle values */
#define CONSOLE_REAL_OUTPUT_HANDLE  ((HANDLE)-2)
#define CONSOLE_REAL_INPUT_HANDLE   ((HANDLE)-3)

/* Console display mode flags */
#if (_WIN32_WINNT >= 0x0500)
    #define CONSOLE_FULLSCREEN_MODE 1L
    #define CONSOLE_WINDOWED_MODE   2L
#endif

/* Coordinate for use with the console */
typedef struct _COORD {
    SHORT   X;
    SHORT   Y;
} COORD;
typedef COORD   *PCOORD;

/* Rectangle for use with the console */
typedef struct _SMALL_RECT {
    SHORT   Left;
    SHORT   Top;
    SHORT   Right;
    SHORT   Bottom;
} SMALL_RECT;
typedef SMALL_RECT  *PSMALL_RECT;

/* Console key event record */
typedef struct _KEY_EVENT_RECORD {
    BOOL    bKeyDown;
    WORD    wRepeatCount;
    WORD    wVirtualKeyCode;
    WORD    wVirtualScanCode;
    union {
        WCHAR   UnicodeChar;
        CHAR    AsciiChar;
    } uChar;
    DWORD   dwControlKeyState;
} KEY_EVENT_RECORD;
typedef KEY_EVENT_RECORD    *PKEY_EVENT_RECORD;

/* Console mouse event record */
typedef struct _MOUSE_EVENT_RECORD {
    COORD   dwMousePosition;
    DWORD   dwButtonState;
    DWORD   dwControlKeyState;
    DWORD   dwEventFlags;
} MOUSE_EVENT_RECORD;
typedef MOUSE_EVENT_RECORD  *PMOUSE_EVENT_RECORD;

/* Console window resize event record */
typedef struct _WINDOW_BUFFER_SIZE_RECORD {
    COORD   dwSize;
} WINDOW_BUFFER_SIZE_RECORD;
typedef WINDOW_BUFFER_SIZE_RECORD   *PWINDOW_BUFFER_SIZE_RECORD;

/* Console menu event record */
typedef struct _MENU_EVENT_RECORD {
    UINT    dwCommandId;
} MENU_EVENT_RECORD;
typedef MENU_EVENT_RECORD   *PMENU_EVENT_RECORD;

/* Console focus event record */
typedef struct _FOCUS_EVENT_RECORD {
    BOOL    bSetFocus;
} FOCUS_EVENT_RECORD;
typedef FOCUS_EVENT_RECORD  *PFOCUS_EVENT_RECORD;

/* Console input record */
typedef struct _INPUT_RECORD {
    WORD    EventType;
    union {
        KEY_EVENT_RECORD            KeyEvent;
        MOUSE_EVENT_RECORD          MouseEvent;
        WINDOW_BUFFER_SIZE_RECORD   WindowBufferSizeEvent;
        MENU_EVENT_RECORD           MenuEvent;
        FOCUS_EVENT_RECORD          FocusEvent;
    } Event;
} INPUT_RECORD;
typedef INPUT_RECORD    *PINPUT_RECORD;

/* Console character information */
typedef struct _CHAR_INFO {
    union {
        WCHAR   UnicodeChar;
        CHAR    AsciiChar;
    } Char;
    WORD    Attributes;
} CHAR_INFO;
typedef CHAR_INFO   *PCHAR_INFO;

/* Console screen buffer information */
typedef struct _CONSOLE_SCREEN_BUFFER_INFO {
    COORD       dwSize;
    COORD       dwCursorPosition;
    WORD        wAttributes;
    SMALL_RECT  srWindow;
    COORD       dwMaximumWindowSize;
} CONSOLE_SCREEN_BUFFER_INFO;
typedef CONSOLE_SCREEN_BUFFER_INFO  *PCONSOLE_SCREEN_BUFFER_INFO;

/* Console screen buffer information (extended version) */
typedef struct _CONSOLE_SCREEN_BUFFER_INFOEX {
    ULONG       cbSize;
    COORD       dwSize;
    COORD       dwCursorPosition;
    WORD        wAttributes;
    SMALL_RECT  srWindow;
    COORD       dwMaximumWindowSize;
    WORD        wPopupAttributes;
    BOOL        bFullscreenSupported;
    COLORREF    ColorTable[16];
} CONSOLE_SCREEN_BUFFER_INFOEX;
typedef CONSOLE_SCREEN_BUFFER_INFOEX    *PCONSOLE_SCREEN_BUFFER_INFOEX;

/* Console cursor information */
typedef struct _CONSOLE_CURSOR_INFO {
    DWORD   dwSize;
    BOOL    bVisible;
} CONSOLE_CURSOR_INFO;
typedef CONSOLE_CURSOR_INFO *PCONSOLE_CURSOR_INFO;

/* Console font information */
typedef struct _CONSOLE_FONT_INFO {
    DWORD   nFont;
    COORD   dwFontSize;
} CONSOLE_FONT_INFO;
typedef CONSOLE_FONT_INFO   *PCONSOLE_FONT_INFO;

/* Console font information (extended version) */
typedef struct _CONSOLE_FONT_INFOEX {
    ULONG   cbSize;
    DWORD   nFont;
    COORD   dwFontSize;
    UINT    FontFamily;
    UINT    FontWeight;
    WCHAR   FaceName[LF_FACESIZE];
} CONSOLE_FONT_INFOEX;
typedef CONSOLE_FONT_INFOEX *PCONSOLE_FONT_INFOEX;

/* Console history information */
typedef struct _CONSOLE_HISTORY_INFO {
    UINT    cbSize;
    UINT    HistoryBufferSize;
    UINT    NumberOfHistoryBuffers;
    DWORD   dwFlags;
} CONSOLE_HISTORY_INFO;
typedef CONSOLE_HISTORY_INFO    *PCONSOLE_HISTORY_INFO;

/* Console selection information */
#if (_WIN32_WINNT >= 0x0500)
typedef struct _CONSOLE_SELECTION_INFO {
    DWORD       dwFlags;
    COORD       dwSelectionAnchor;
    SMALL_RECT  srSelection;
} CONSOLE_SELECTION_INFO;
typedef CONSOLE_SELECTION_INFO  *PCONSOLE_SELECTION_INFO;
#endif

/* Console control event handler callback */
typedef BOOL (WINAPI *PHANDLER_ROUTINE)( DWORD );

/* ReadConsole() control information */
typedef struct _CONSOLE_READCONSOLE_CONTROL {
    ULONG   nLength;
    ULONG   nInitialChars;
    ULONG   dwCtrlWakeupMask;
    ULONG   dwControlKeyState;
} CONSOLE_READCONSOLE_CONTROL;
typedef CONSOLE_READCONSOLE_CONTROL *PCONSOLE_READCONSOLE_CONTROL;

/* Functions in KERNEL32.DLL */
WINBASEAPI BOOL WINAPI      AllocConsole( VOID );
WINBASEAPI HANDLE WINAPI    CreateConsoleScreenBuffer( DWORD, DWORD, CONST SECURITY_ATTRIBUTES *, DWORD, LPVOID );
WINBASEAPI BOOL WINAPI      FillConsoleOutputAttribute( HANDLE, WORD, DWORD, COORD, LPDWORD );
WINBASEAPI BOOL WINAPI      FillConsoleOutputCharacterA( HANDLE, CHAR, DWORD, COORD, LPDWORD );
WINBASEAPI BOOL WINAPI      FillConsoleOutputCharacterW( HANDLE, WCHAR, DWORD, COORD, LPDWORD );
WINBASEAPI BOOL WINAPI      FlushConsoleInputBuffer( HANDLE );
WINBASEAPI BOOL WINAPI      FreeConsole( VOID );
WINBASEAPI BOOL WINAPI      GenerateConsoleCtrlEvent( DWORD, DWORD );
WINBASEAPI UINT WINAPI      GetConsoleCP( VOID );
WINBASEAPI BOOL WINAPI      GetConsoleCursorInfo( HANDLE, PCONSOLE_CURSOR_INFO );
WINBASEAPI BOOL WINAPI      GetConsoleMode( HANDLE, LPDWORD );
WINBASEAPI UINT WINAPI      GetConsoleOutputCP( VOID );
WINBASEAPI BOOL WINAPI      GetConsoleScreenBufferInfo( HANDLE, PCONSOLE_SCREEN_BUFFER_INFO );
WINBASEAPI BOOL WINAPI      GetConsoleScreenBufferInfoEx( HANDLE, PCONSOLE_SCREEN_BUFFER_INFOEX );
WINBASEAPI DWORD WINAPI     GetConsoleTitleA( LPSTR, DWORD );
WINBASEAPI DWORD WINAPI     GetConsoleTitleW( LPWSTR, DWORD );
WINBASEAPI COORD WINAPI     GetLargestConsoleWindowSize( HANDLE );
WINBASEAPI BOOL WINAPI      GetNumberOfConsoleInputEvents( HANDLE, LPDWORD );
WINBASEAPI BOOL WINAPI      GetNumberOfConsoleMouseButtons( LPDWORD );
WINBASEAPI BOOL WINAPI      PeekConsoleInputA( HANDLE, PINPUT_RECORD, DWORD, LPDWORD );
WINBASEAPI BOOL WINAPI      PeekConsoleInputW( HANDLE, PINPUT_RECORD, DWORD, LPDWORD );
WINBASEAPI BOOL WINAPI      ReadConsoleA( HANDLE, LPVOID, DWORD, LPDWORD, PCONSOLE_READCONSOLE_CONTROL );
WINBASEAPI BOOL WINAPI      ReadConsoleInputA( HANDLE, PINPUT_RECORD, DWORD, LPDWORD );
WINBASEAPI BOOL WINAPI      ReadConsoleInputW( HANDLE, PINPUT_RECORD, DWORD, LPDWORD );
WINBASEAPI BOOL WINAPI      ReadConsoleOutputA( HANDLE, PCHAR_INFO, COORD, COORD, PSMALL_RECT );
WINBASEAPI BOOL WINAPI      ReadConsoleOutputAttribute( HANDLE, LPWORD, DWORD, COORD, LPDWORD );
WINBASEAPI BOOL WINAPI      ReadConsoleOutputCharacterA( HANDLE, LPSTR, DWORD, COORD, LPDWORD );
WINBASEAPI BOOL WINAPI      ReadConsoleOutputCharacterW( HANDLE, LPWSTR, DWORD, COORD, LPDWORD );
WINBASEAPI BOOL WINAPI      ReadConsoleOutputW( HANDLE, PCHAR_INFO, COORD, COORD, PSMALL_RECT );
WINBASEAPI BOOL WINAPI      ReadConsoleW( HANDLE, LPVOID, DWORD, LPDWORD, PCONSOLE_READCONSOLE_CONTROL );
WINBASEAPI BOOL WINAPI      ScrollConsoleScreenBufferA( HANDLE, CONST SMALL_RECT *, CONST SMALL_RECT *, COORD, CONST CHAR_INFO * );
WINBASEAPI BOOL WINAPI      ScrollConsoleScreenBufferW( HANDLE, CONST SMALL_RECT *, CONST SMALL_RECT *, COORD, CONST CHAR_INFO * );
WINBASEAPI BOOL WINAPI      SetConsoleActiveScreenBuffer( HANDLE );
WINBASEAPI BOOL WINAPI      SetConsoleCP( UINT );
WINBASEAPI BOOL WINAPI      SetConsoleCtrlHandler( PHANDLER_ROUTINE, BOOL );
WINBASEAPI BOOL WINAPI      SetConsoleCursorInfo( HANDLE, CONST CONSOLE_CURSOR_INFO * );
WINBASEAPI BOOL WINAPI      SetConsoleCursorPosition( HANDLE, COORD );
WINBASEAPI BOOL WINAPI      SetConsoleMode( HANDLE, DWORD );
WINBASEAPI BOOL WINAPI      SetConsoleOutputCP( UINT );
WINBASEAPI BOOL WINAPI      SetConsoleScreenBufferInfoEx( HANDLE, PCONSOLE_SCREEN_BUFFER_INFOEX );
WINBASEAPI BOOL WINAPI      SetConsoleScreenBufferSize( HANDLE, COORD );
WINBASEAPI BOOL WINAPI      SetConsoleTextAttribute( HANDLE, WORD );
WINBASEAPI BOOL WINAPI      SetConsoleTitleA( LPCSTR );
WINBASEAPI BOOL WINAPI      SetConsoleTitleW( LPCWSTR );
WINBASEAPI BOOL WINAPI      SetConsoleWindowInfo( HANDLE, BOOL, CONST SMALL_RECT * );
WINBASEAPI BOOL WINAPI      WriteConsoleA( HANDLE, CONST VOID *, DWORD, LPDWORD, LPVOID );
WINBASEAPI BOOL WINAPI      WriteConsoleInputA( HANDLE, CONST INPUT_RECORD *, DWORD, LPDWORD );
WINBASEAPI BOOL WINAPI      WriteConsoleInputW( HANDLE, CONST INPUT_RECORD *, DWORD, LPDWORD );
WINBASEAPI BOOL WINAPI      WriteConsoleOutputA( HANDLE, CONST CHAR_INFO *, COORD, COORD, PSMALL_RECT );
WINBASEAPI BOOL WINAPI      WriteConsoleOutputAttribute( HANDLE, CONST WORD *, DWORD, COORD, LPDWORD );
WINBASEAPI BOOL WINAPI      WriteConsoleOutputCharacterA( HANDLE, LPCSTR, DWORD, COORD, LPDWORD );
WINBASEAPI BOOL WINAPI      WriteConsoleOutputCharacterW( HANDLE, LPCWSTR, DWORD, COORD, LPDWORD );
WINBASEAPI BOOL WINAPI      WriteConsoleOutputW( HANDLE, CONST CHAR_INFO *, COORD, COORD, PSMALL_RECT );
WINBASEAPI BOOL WINAPI      WriteConsoleW( HANDLE, CONST VOID *, DWORD, LPDWORD, LPVOID );
#if (_WIN32_WINNT >= 0x0500)
WINBASEAPI BOOL WINAPI      AttachConsole( DWORD );
WINBASEAPI BOOL WINAPI      GetConsoleDisplayMode( LPDWORD );
WINBASEAPI COORD WINAPI     GetConsoleFontSize( HANDLE, DWORD );
WINBASEAPI BOOL WINAPI      GetConsoleHistoryInfo( PCONSOLE_HISTORY_INFO );
WINBASEAPI BOOL WINAPI      GetConsoleSelectionInfo( PCONSOLE_SELECTION_INFO );
WINBASEAPI HWND WINAPI      GetConsoleWindow( VOID );
WINBASEAPI BOOL WINAPI      GetCurrentConsoleFont( HANDLE, BOOL, PCONSOLE_FONT_INFO );
WINBASEAPI BOOL WINAPI      GetCurrentConsoleFontEx( HANDLE, BOOL, PCONSOLE_FONT_INFOEX );
WINBASEAPI BOOL WINAPI      SetConsoleDisplayMode( HANDLE, DWORD, PCOORD );
WINBASEAPI BOOL WINAPI      SetConsoleHistoryInfo( PCONSOLE_HISTORY_INFO );
WINBASEAPI BOOL WINAPI      SetCurrentConsoleFontEx( HANDLE, BOOL, PCONSOLE_FONT_INFOEX );
#endif
#if (_WIN32_WINNT >= 0x0501)
WINBASEAPI BOOL WINAPI      AddConsoleAliasA( LPSTR, LPSTR, LPSTR );
WINBASEAPI BOOL WINAPI      AddConsoleAliasW( LPWSTR, LPWSTR, LPWSTR );
WINBASEAPI DWORD WINAPI     GetConsoleAliasA( LPSTR, LPSTR, DWORD, LPSTR );
WINBASEAPI DWORD WINAPI     GetConsoleAliasExesA( LPSTR, DWORD );
WINBASEAPI DWORD WINAPI     GetConsoleAliasExesLengthA( VOID );
WINBASEAPI DWORD WINAPI     GetConsoleAliasExesLengthW( VOID );
WINBASEAPI DWORD WINAPI     GetConsoleAliasExesW( LPWSTR, DWORD );
WINBASEAPI DWORD WINAPI     GetConsoleAliasW( LPWSTR, LPWSTR, DWORD, LPWSTR );
WINBASEAPI DWORD WINAPI     GetConsoleAliasesA( LPSTR, DWORD, LPSTR );
WINBASEAPI DWORD WINAPI     GetConsoleAliasesLengthA( LPSTR );
WINBASEAPI DWORD WINAPI     GetConsoleAliasesLengthW( LPWSTR );
WINBASEAPI DWORD WINAPI     GetConsoleAliasesW( LPWSTR, DWORD, LPWSTR );
WINBASEAPI DWORD WINAPI     GetConsoleProcessList( LPDWORD, DWORD );
#endif
#if (_WIN32_WINNT >= 0x0600)
WINBASEAPI DWORD WINAPI     GetConsoleOriginalTitleA( LPSTR, DWORD );
WINBASEAPI DWORD WINAPI     GetConsoleOriginalTitleW( LPWSTR, DWORD );
#endif

/* Map generic function names to the appropriate ANSI or Unicode version. */
#ifdef UNICODE
    #define FillConsoleOutputCharacter      FillConsoleOutputCharacterW
    #define GetConsoleTitle                 GetConsoleTitleW
    #define PeekConsoleInput                PeekConsoleInputW
    #define ReadConsole                     ReadConsoleW
    #define ReadConsoleInput                ReadConsoleInputW
    #define ReadConsoleOutput               ReadConsoleOutputW
    #define ReadConsoleOutputCharacter      ReadConsoleOutputCharacterW
    #define ScrollConsoleScreenBuffer       ScrollConsoleScreenBufferW
    #define SetConsoleTitle                 SetConsoleTitleW
    #define WriteConsole                    WriteConsoleW
    #define WriteConsoleInput               WriteConsoleInputW
    #define WriteConsoleOutput              WriteConsoleOutputW
    #define WriteConsoleOutputCharacter     WriteConsoleOutputCharacterW
    #if (_WIN32_WINNT >= 0x0501)
        #define AddConsoleAlias             AddConsoleAliasW
        #define GetConsoleAlias             GetConsoleAliasW
        #define GetConsoleAliasExes         GetConsoleAliasExesW
        #define GetConsoleAliasExesLength   GetConsoleAliasExesLengthW
        #define GetConsoleAliases           GetConsoleAliasesW
        #define GetConsoleAliasesLength     GetConsoleAliasesLengthW
    #endif
    #if (_WIN32_WINNT >= 0x0600)
        #define GetConsoleOriginalTitle     GetConsoleOriginalTitleW
    #endif
#else
    #define FillConsoleOutputCharacter      FillConsoleOutputCharacterA
    #define GetConsoleTitle                 GetConsoleTitleA
    #define PeekConsoleInput                PeekConsoleInputA
    #define ReadConsole                     ReadConsoleA
    #define ReadConsoleInput                ReadConsoleInputA
    #define ReadConsoleOutput               ReadConsoleOutputA
    #define ReadConsoleOutputCharacter      ReadConsoleOutputCharacterA
    #define ScrollConsoleScreenBuffer       ScrollConsoleScreenBufferA
    #define SetConsoleTitle                 SetConsoleTitleA
    #define WriteConsole                    WriteConsoleA
    #define WriteConsoleInput               WriteConsoleInputA
    #define WriteConsoleOutput              WriteConsoleOutputA
    #define WriteConsoleOutputCharacter     WriteConsoleOutputCharacterA
    #if (_WIN32_WINNT >= 0x0501)
        #define AddConsoleAlias             AddConsoleAliasA
        #define GetConsoleAlias             GetConsoleAliasA
        #define GetConsoleAliasExes         GetConsoleAliasExesA
        #define GetConsoleAliasExesLength   GetConsoleAliasExesLengthA
        #define GetConsoleAliases           GetConsoleAliasesA
        #define GetConsoleAliasesLength     GetConsoleAliasesLengthA
    #endif
    #if (_WIN32_WINNT >= 0x0600)
        #define GetConsoleOriginalTitle     GetConsoleOriginalTitleA
    #endif
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _WINCON_ */
