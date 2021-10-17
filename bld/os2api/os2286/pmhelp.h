/*
 *  pmhelp.h    OS/2 Presentation Manager help manager include file
 *              for 16-bit development.
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

#ifndef PMHELP_H
#define PMHELP_H

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define HWND_PARENT (HWND)NULL

#define HM_RESOURCEID 0
#define HM_PANELNAME  1

#define HMPANELTYPE_NUMBER 0
#define HMPANELTYPE_NAME   1

#define CMIC_HIDE_PANEL_ID   0
#define CMIC_SHOW_PANEL_ID   1
#define CMIC_TOGGLE_PANEL_ID 2

#define HM_MSG_BASE 0x0220

#define HM_DISMISS_WINDOW        HM_MSG_BASE+0x0001
#define HM_DISPLAY_HELP          HM_MSG_BASE+0x0002
#define HM_EXT_HELP              HM_MSG_BASE+0x0003
#define HM_SET_ACTIVE_WINDOW     HM_MSG_BASE+0x0004
#define HM_LOAD_HELP_TABLE       HM_MSG_BASE+0x0005
#define HM_CREATE_HELP_TABLE     HM_MSG_BASE+0x0006
#define HM_SET_HELP_WINDOW_TITLE HM_MSG_BASE+0x0007
#define HM_SET_SHOW_PANEL_ID     HM_MSG_BASE+0x0008
#define HM_REPLACE_HELP_FOR_HELP HM_MSG_BASE+0x0009
#define HM_HELP_INDEX            HM_MSG_BASE+0x000a
#define HM_HELP_CONTENTS         HM_MSG_BASE+0x000b
#define HM_KEYS_HELP             HM_MSG_BASE+0x000c
#define HM_SET_HELP_LIBRARY_NAME HM_MSG_BASE+0x000d
#define HM_ERROR                 HM_MSG_BASE+0x000e
#define HM_HELPSUBITEM_NOT_FOUND HM_MSG_BASE+0x000f
#define HM_QUERY_KEYS_HELP       HM_MSG_BASE+0x0010
#define HM_TUTORIAL              HM_MSG_BASE+0x0011
#define HM_EXT_HELP_UNDEFINED    HM_MSG_BASE+0x0012
#define HM_ACTIONBAR_COMMAND     HM_MSG_BASE+0x0013
#define HM_INFORM                HM_MSG_BASE+0x0014

#define  HMERR_NO_FRAME_WND_IN_CHAIN     0x00001001L
#define  HMERR_INVALID_ASSOC_APP_WND     0x00001002L
#define  HMERR_INVALID_ASSOC_HELP_INST   0x00001003L
#define  HMERR_INVALID_DESTROY_HELP_INST 0x00001004L
#define  HMERR_NO_HELP_INST_IN_CHAIN     0x00001005L
#define  HMERR_INVALID_HELP_INSTANCE_HDL 0x00001006L
#define  HMERR_INVALID_QUERY_APP_WND     0x00001007L
#define  HMERR_HELP_INST_CALLED_INVALID  0x00001008L
#define  HMERR_HELPTABLE_UNDEFINE        0x00001009L
#define  HMERR_HELP_INSTANCE_UNDEFINE    0x0000100aL
#define  HMERR_HELPITEM_NOT_FOUND        0x0000100bL
#define  HMERR_INVALID_HELPSUBITEM_SIZE  0x0000100cL
#define  HMERR_HELPSUBITEM_NOT_FOUND     0x0000100dL
#define  HMERR_INDEX_NOT_FOUND           0x00002001L
#define  HMERR_CONTENT_NOT_FOUND         0x00002002L
#define  HMERR_OPEN_LIB_FILE             0x00002003L
#define  HMERR_READ_LIB_FILE             0x00002004L
#define  HMERR_CLOSE_LIB_FILE            0x00002005L
#define  HMERR_INVALID_LIB_FILE          0x00002006L
#define  HMERR_NO_MEMORY                 0x00002007L
#define  HMERR_ALLOCATE_SEGMENT          0x00002008L
#define  HMERR_FREE_MEMORY               0x00002009L
#define  HMERR_PANEL_NOT_FOUND           0x00002010L
#define  HMERR_DATABASE_NOT_OPEN         0x00002011L

typedef int HELPSUBTABLE;
typedef int FAR *PHELPSUBTABLE;

typedef struct _HELPTABLE {
    USHORT        idAppWindow;
    PHELPSUBTABLE phstHelpSubTable;
    USHORT        idExtPanel;
} HELPTABLE, FAR *PHELPTABLE;

typedef struct _HELPINIT {
    USHORT     cb;
    ULONG      ulReturnCode;
    PSZ        pszTutorialName;
    PHELPTABLE phtHelpTable;
    HMODULE    hmodHelpTableModule;
    HMODULE    hmodAccelActionBarModule;
    USHORT     idAccelTable;
    USHORT     idActionBar;
    PSZ        pszHelpWindowTitle;
    USHORT     usShowPanelId;
    PSZ        pszHelpLibraryName;
} HELPINIT, FAR *PHELPINIT;

BOOL APIENTRY  WinAssociateHelpInstance(HWND,HWND);
HWND APIENTRY  WinCreateHelpInstance(HAB,PHELPINIT);
BOOL APIENTRY  WinCreateHelpTable(HWND,PHELPTABLE);
BOOL APIENTRY  WinDestroyHelpInstance(HWND);
BOOL APIENTRY  WinLoadHelpTable(HWND,USHORT,HMODULE);
HWND APIENTRY  WinQueryHelpInstance(HWND);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
