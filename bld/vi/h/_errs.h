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
* Description:  vi editor return codes definition with messages (vi_rc >= 0)
*
****************************************************************************/


pick( ERR_NO_ERR,                       "", = 0 )
pick( ERR_NO_MEMORY,                    "Out of memory", )
pick( ERR_FILE_NOT_FOUND,               "File not found", )
pick( ERR_READ,                         "File read error", )
pick( ERR_SWAP_FILE_OPEN,               "Swap file open error", )
pick( ERR_NO_SUCH_DRIVE,                "No such drive", )
pick( ERR_DIRECTORY_OP_FAILED,          "Directory operation failed", )
pick( ERR_WIND_INVALID,                 "Invalid window", )
pick( ERR_WIND_NO_MORE_WINDOWS,         "No more windows", )
pick( ERR_WIND_NO_SUCH_LINE,            "No such line in window", )
pick( ERR_NO_SUCH_LINE,                 "No such line", )
pick( ERR_NO_MORE_LINES,                "No more lines", )
pick( ERR_NO_SUCH_COLUMN,               "No such column", )
pick( ERR_SWAP_FILE_READ,               "Swap file read error", )
pick( ERR_SWAP_FILE_WRITE,              "Swap file write error", )
pick( ERR_INVALID_COMMAND,              "Invalid command", )
pick( ERR_REPEAT_STRING_TOO_LONG,       "Repeat string too long", )
pick( ERR_ALREADY_IN_DOT_MODE,          "Already in dot mode", )
pick( ERR_CANNOT_DELETE_CHAR,           "Cannot delete character", )
pick( ERR_NO_MORE_UNDOS,                "No more undos", )
pick( ERR_FILE_EXISTS,                  "File with same name already exists", )
pick( ERR_FILE_OPEN,                    "File open error", )
pick( ERR_FILE_CLOSE,                   "File close error", )
pick( ERR_FILE_WRITE,                   "File write error", )
pick( ERR_NOT_THAT_MANY_WORDS,          "Not that many words", )
pick( ERR_INVALID_LINE_RANGE,           "Invalid line range", )
pick( ERR_NO_FILE_SPECIFIED,            "No file specified", )
pick( ERR_INVALID_SET_COMMAND,          "Invalid set command", )
pick( ERR_INVALID_VALUE,                "Cannot insert the character value 0.", )
pick( ERR_CHAR_NOT_FOUND,               "Character '%c' not found", )
pick( ERR_FIND_END_OF_FILE,             "End of file reached", )
pick( ERR_FIND_NOT_FOUND,               "String '%s' not found", )
pick( ERR_NO_PREVIOUS_SEARCH_STRING,    "No previous search string", )
pick( ERR_LINE_FULL,                    "Not enough room in line", )
pick( ERR_CANNOT_OPEN_LINENUM_WIND,     "Cannot open line number window", )
pick( ERR_INVALID_DELETE_CMD,           "Invalid delete command", )
pick( ERR_INVALID_YANK_CMD,             "Invalid yank command", )
pick( ERR_NO_CHAR_TO_REPLACE,           "No character to replace", )
pick( ERR_NOTHING_TO_MATCH,             "Nothing to match", )
pick( ERR_MATCH_NOT_FOUND,              "Matching '%s' not found", )
pick( ERR_FIND_TOP_OF_FILE,             "Top of file reached", )
pick( ERR_INVALID_SUBS_CMD,             "Invalid substitute command", )
pick( ERR_INVALID_MARK_RANGE,           "Invalid mark - use 'a'-'z'", )
pick( ERR_MARK_NOT_SET,                 "Mark '%c' not set", )
pick( ERR_MARK_NOW_INVALID,             "Mark '%c' no longer valid", )
pick( ERR_INVALID_KEY,                  "Invalid key", )
pick( ERR_INVALID_CHANGE_CMD,           "Invalid change command", )
pick( ERR_INVALID_SAVEBUF,              "Invalid copy buffer '%c' - use '1'-'9' or 'a'-'z'", )
pick( ERR_EMPTY_SAVEBUF,                "Empty copy buffer", )
pick( ERR_WIND_NO_SUCH_COLUMN,          "No such column in window", )
pick( ERR_RE_NULL_ARGUMENT,             "Internal error: Regular expression NULL argument", )
pick( ERR_RE_TOO_MANY_ROUND_BRACKETS,   "Too many ()", )
pick( ERR_RE_UNMATCHED_ROUND_BRACKETS,  "Unmatched ()", )
pick( ERR_RE_MEMORY_CORRUPTION,         "Internal err: Regexp memory corruption", )
pick( ERR_RE_CORRUPTED_POINTER,         "Internal err: Regexp corrupted pointer", )
pick( ERR_RE_INTERNAL_FOULUP,           "Internal err: Regexp foulup", )
pick( ERR_RE_EMPTY_OPERAND,             "*+ operand could be empty", )
pick( ERR_RE_NESTED_OPERAND,            "nested *?+", )
pick( ERR_RE_INVALID_SB_RANGE,          "invalid [] range", )
pick( ERR_RE_UNMATCHED_SQUARE_BRACKET,  "Unmatched []", )
pick( ERR_RE_OPERAND_FOLLOWS_NOTHING,   "?+* follows nothing", )
pick( ERR_RE_TRAILING_SLASH,            "Trailing \\", )
pick( ERR_INVALID_FIND_CMD,             "Invalid find command", )
pick( ERR_FIND_PAST_TERM_LINE,          "Past terminating line", )
pick( ERR_SWAP_FILE_FULL,               "Swap file full", )
pick( ERR_SRC_INVALID_ASSIGN,           "Invalid ASSIGN", )
pick( ERR_SRC_INVALID_IF,               "Invalid conditional expression", )
pick( ERR_SRC_NO_ERROR_DATA,            "File 'error.dat' not found", )
pick( ERR_SRC_INVALID_GOTO,             "Invalid GOTO", )
pick( ERR_SRC_LABEL_NOT_FOUND,          "Label not found", )
pick( ERR_SCRIPT_ALREADY_RESIDENT,      "Script already loaded", )
pick( ERR_SRC_INVALID_LABEL,            "Invalid LABEL", )
pick( ERR_INVALID_ADDRESS,              "Invalid line address", )
pick( ERR_SRC_INVALID_OPEN,             "Invalid FOPEN", )
pick( ERR_SRC_INVALID_READ,             "Invalid FREAD", )
pick( ERR_SRC_INVALID_WRITE,            "Invalid FWRITE", )
pick( ERR_SRC_FILE_NOT_OPEN,            "File not FOPEN", )
pick( ERR_SRC_INVALID_CLOSE,            "Invalid FCLOSE", )
pick( ERR_INPUT_KEYMAP_RUNNING,         "Input key map already running", )
pick( ERR_NO_EXTENDED_MEMORY,           "Out of extended memory", )
pick( ERR_FILE_SEEK,                    "File seek error", )
pick( ERR_RE_INVALID_CASETOGGLE,        "Case toggle has nothing following", )
pick( ERR_INVALID_DATA_FILE,            "Invalid data in file '%s' at line %d", )
pick( ERR_NO_XMS_MEMORY,                "Out of XMS memory", )
pick( ERR_NO_WORD_TO_FIND,              "No word found", )
pick( ERR_TAG_NOT_FOUND,                "Tag '%s' not found", )
pick( ERR_READ_ONLY_FILE,               "File is read only", )
pick( ERR_INVALID_TAG_FOUND,            "Invalid tag found", )
pick( ERR_NO_STRING,                    "No string specified", )
pick( ERR_INVALID_CASE_CMD,             "Invalid case command", )
pick( ERR_INVALID_RANGE,                "Invalid range given", )
pick( ERR_INTERNAL_NULL_PTR,            "Internal err: Null pointer found", )
pick( ERR_INVALID_SHIFT_CMD,            "Invalid shift command", )
pick( ERR_SRC_INVALID_INPUT,            "Invalid INPUT", )
pick( ERR_INVALID_GLOBAL_CMD,           "Invalid global command", )
pick( ERR_NO_EMS_MEMORY,                "Out of EMS memory", )
pick( ERR_INVALID_UNDO,                 "Internal err: Invalid undo record found - undo stacks purged", )
pick( ERR_SRC_INVALID_EXPR,             "Invalid EXPR", )
pick( ERR_INVALID_MAP,                  "Invalid map command", )
pick( ERR_TWO_MARKS_ON_LINE,            "Already two marks on this line", )
pick( ERR_READ_ONLY_FILE_MODIFIED,      "Warning: file is read only", )
pick( ERR_TTY_FILE,                     "File is a tty", )
pick( ERR_FILE_VIEW_ONLY,               "File is view only", )
pick( ERR_FILE_MODIFIED,                "File modified - save before exit", )
pick( ERR_NO_STACK,                     "Insufficient stack for allocation", )
pick( ERR_INVALID_ALIAS,                "Invalid alias command", )
pick( ERR_TOO_MANY_MATCH_STRINGS,       "Too many match items", )
pick( ERR_INVALID_MATCH,                "Invalid match command", )
pick( ERR_INVALID_SETCOLOR,             "Invalid setcolor command", )
pick( ERR_INVALID_WINDOW_SETUP,         "Invalid window data", )
pick( ERR_NO_FILE_NAME,                 "File has no name", )
pick( ERR_INVALID_ABBREV,               "Invalid abbreviation", )
pick( ERR_NO_SUCH_ALIAS,                "No such alias", )
pick( ERR_NO_SUCH_ABBREV,               "No such abbreviation", )
pick( ERR_INVALID_IN_EX_MODE,           "Not valid while in ex mode", )
pick( ERR_ONLY_VALID_IN_EX_MODE,        "Only valid in ex mode", )
pick( ERR_SAVEBUF_TOO_BIG,              "Copy buffer too big", )
pick( ERR_INVALID_REDRAW,               "Invalid redraw", )
pick( ERR_INVALID_HIDE_CMD,             "Invalid hide command", )
pick( ERR_EXPECTING_COLON,              "Expecting :", )
pick( ERR_INVALID_MENU,                 "Invalid menu", )
pick( ERR_NO_SELECTION,                 "No selection", )
pick( ERR_OPEN_UNDO,                    "Internal err: Open undo", )
pick( ERR_NO_PREVIOUS_COMMAND,          "No previous 'f','t','T' or 'F' command", )
pick( ERR_FILE_STACK_EMPTY,             "Empty file stack", )
pick( ERR_INVALID_FONT,                 "Invalid or incomplete font specification", )
pick( ERR_INVALID_DDE,                  "Invalid DDE command", )
pick( ERR_DDE_FAILED,                   "DDE command failed", )
pick( ERR_SRC_INVALID_NEXTWORD,         "Invalid NEXTWORD command", )
pick( ERR_NO_REGION,                    "No previous selection", )
pick( ERR_INVALID_OP,                   "Invalid operation", )
pick( ERR_CLIPBOARD,                    "Error accessing clipboard", )
pick( ERR_CLIPBOARD_EMPTY,              "Clipboard is empty", )
pick( ERR_NO_FILE,                      "No file being edited", )
pick( ERR_PROMPT_TOO_LONG,              "Input prompt too long for window", )
pick( ERR_EXIT_ABORTED,                 "Exit Aborted", )
pick( ERR_INVALID_LOCATE,               "Invalid Location", )
pick( ERR_NO_MORE_REDOS,                "No more redos", )
pick( ERR_SAVE_CANCELED,                "Save Canceled", )
pick( ERR_SPECIFIC_FILE_NOT_FOUND,      "File '%s' not found", )
pick( ERR_INTERNAL_FCBSIZE,             "Internal err: FCB size corruption", )
pick( ERR_BAD_TERMINAL,                 "Failed to initialize terminal", )
