/*
 *  vidcap.h    Video capture interfaces
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

#include <rpc.h>
#include <rpcndr.h>
#ifndef COM_NO_WINDOWS_H
    #include <windows.h>
    #include <ole2.h>
#endif

#ifndef __vidcap_h__
#define __vidcap_h__

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file;
#endif

#include <unknwn.h>
#include <strmif.h>
#include <ks.h>

#ifdef __cplusplus
extern "C" {
#endif

/* IKsTopologyInfo interface */
#undef INTERFACE
#define INTERFACE   IKsTopologyInfo
DECLARE_INTERFACE_( IKsTopologyInfo, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IKsTopologyInfo methods */
    STDMETHOD( get_NumCategories )( THIS_ DWORD * ) PURE;
    STDMETHOD( get_Category )( THIS_ DWORD, GUID * ) PURE;
    STDMETHOD( get_NumConnections )( THIS_ DWORD * ) PURE;
    STDMETHOD( get_ConnectionInfo )( THIS_ DWORD, KSTOPOLOGY_CONNECTION * ) PURE;
    STDMETHOD( get_NodeName )( THIS_ DWORD, WCHAR *, DWORD, DWORD * ) PURE;
    STDMETHOD( get_NumNodes )( THIS_ DWORD * ) PURE;
    STDMETHOD( get_NodeType )( THIS_ DWORD, GUID * ) PURE;
    STDMETHOD( CreateNodeInstance )( THIS_ DWORD, REFIID, void ** ) PURE;
};

/* ISelector interface */
#undef INTERFACE
#define INTERFACE   ISelector
DECLARE_INTERFACE_( ISelector, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* ISelector methods */
    STDMETHOD( get_NumSources )( THIS_ DWORD * ) PURE;
    STDMETHOD( get_SourceNodeId )( THIS_ DWORD * ) PURE;
    STDMETHOD( put_SourceNodeId )( THIS_ DWORD ) PURE;
};

/* ICameraControl interface */
#undef INTERFACE
#define INTERFACE   ICameraControl
DECLARE_INTERFACE_( ICameraControl, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* ICameraControl methods */
    STDMETHOD( get_Exposure )( THIS_ long *, long * ) PURE;
    STDMETHOD( put_Exposure )( THIS_ long, long ) PURE;
    STDMETHOD( getRange_Exposure )( THIS_ long *, long *, long *, long *, long * ) PURE;
    STDMETHOD( get_Focus )( THIS_ long *, long * ) PURE;
    STDMETHOD( put_Focus )( THIS_ long, long ) PURE;
    STDMETHOD( getRange_Focus )( THIS_ long *, long *, long *, long *, long * ) PURE;
    STDMETHOD( get_Iris )( THIS_ long *, long * ) PURE;
    STDMETHOD( put_Iris )( THIS_ long, long ) PURE;
    STDMETHOD( getRange_Iris )( THIS_ long *, long *, long *, long *, long * ) PURE;
    STDMETHOD( get_Zoom )( THIS_ long *, long * ) PURE;
    STDMETHOD( put_Zoom )( THIS_ long, long ) PURE;
    STDMETHOD( getRange_Zoom )( THIS_ long *, long *, long *, long *, long * ) PURE;
    STDMETHOD( get_FocalLengths )( THIS_ long *, long *, long * ) PURE;
    STDMETHOD( get_Pan )( THIS_ long *, long * ) PURE;
    STDMETHOD( put_Pan )( THIS_ long, long ) PURE;
    STDMETHOD( getRange_Pan )( THIS_ long *, long *, long *, long *, long * ) PURE;
    STDMETHOD( get_Tilt )( THIS_ long *, long * ) PURE;
    STDMETHOD( put_Tilt )( THIS_ long, long ) PURE;
    STDMETHOD( getRange_Tilt )( THIS_ long *, long *, long *, long *, long * ) PURE;
    STDMETHOD( get_PanTilt )( THIS_ long *, long *, long * ) PURE;
    STDMETHOD( put_PanTilt )( THIS_ long, long, long ) PURE;
    STDMETHOD( get_Roll )( THIS_ long *, long * ) PURE;
    STDMETHOD( put_Roll )( THIS_ long, long ) PURE;
    STDMETHOD( getRange_Roll )( THIS_ long *, long *, long *, long *, long * ) PURE;
    STDMETHOD( get_ExposureRelative )( THIS_ long *, long * ) PURE;
    STDMETHOD( put_ExposureRelative )( THIS_ long, long ) PURE;
    STDMETHOD( getRange_ExposureRelative )( THIS_ long *, long *, long *, long *, long * ) PURE;
    STDMETHOD( get_FocusRelative )( THIS_ long *, long * ) PURE;
    STDMETHOD( put_FocusRelative )( THIS_ long, long ) PURE;
    STDMETHOD( getRange_FocusRelative )( THIS_ long *, long *, long *, long *, long * ) PURE;
    STDMETHOD( get_IrisRelative )( THIS_ long *, long * ) PURE;
    STDMETHOD( put_IrisRelative )( THIS_ long, long ) PURE;
    STDMETHOD( getRange_IrisRelative )( THIS_ long *, long *, long *, long *, long * ) PURE;
    STDMETHOD( get_ZoomRelative )( THIS_ long *, long * ) PURE;
    STDMETHOD( put_ZoomRelative )( THIS_ long, long ) PURE;
    STDMETHOD( getRange_ZoomRelative )( THIS_ long *, long *, long *, long *, long * ) PURE;
    STDMETHOD( get_PanRelative )( THIS_ long *, long * ) PURE;
    STDMETHOD( put_PanRelative )( THIS_ long, long ) PURE;
    STDMETHOD( get_TiltRelative )( THIS_ long *, long * ) PURE;
    STDMETHOD( put_TiltRelative )( THIS_ long, long ) PURE;
    STDMETHOD( getRange_TiltRelative )( THIS_ long *, long *, long *, long *, long * ) PURE;
    STDMETHOD( get_PanTiltRelative )( THIS_ long *, long *, long * ) PURE;
    STDMETHOD( put_PanTiltRelative )( THIS_ long, long, long ) PURE;
    STDMETHOD( getRange_PanRelative )( THIS_ long *, long *, long *, long *, long * ) PURE;
    STDMETHOD( get_RollRelative )( THIS_ long *, long * ) PURE;
    STDMETHOD( put_RollRelative )( THIS_ long, long ) PURE;
    STDMETHOD( getRange_RollRelative )( THIS_ long *, long *, long *, long *, long * ) PURE;
    STDMETHOD( get_ScanMode )( THIS_ long *, long * ) PURE;
    STDMETHOD( put_ScanMode )( THIS_ long, long ) PURE;
    STDMETHOD( get_PrivacyMode )( THIS_ long *, long * ) PURE;
    STDMETHOD( put_PrivacyMode )( THIS_ long, long ) PURE;
};

/* IVideoProcAmp interface */
#undef INTERFACE
#define INTERFACE   IVideoProcAmp
DECLARE_INTERFACE_( IVideoProcAmp, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IVideoProcAmp methods */
    STDMETHOD( get_BacklightCompensation )( THIS_ long *, long * ) PURE;
    STDMETHOD( put_BacklightCompensation )( THIS_ long, long ) PURE;
    STDMETHOD( getRange_BacklightCompensation )( THIS_ long *, long *, long *, long *, long * ) PURE;
    STDMETHOD( get_Brightness )( THIS_ long *, long * ) PURE;
    STDMETHOD( put_Brightness )( THIS_ long, long ) PURE;
    STDMETHOD( getRange_Brightness )( THIS_ long *, long *, long *, long *, long * ) PURE;
    STDMETHOD( get_ColorEnable )( THIS_ long *, long * ) PURE;
    STDMETHOD( put_ColorEnable )( THIS_ long, long ) PURE;
    STDMETHOD( getRange_ColorEnable )( THIS_ long *, long *, long *, long *, long * ) PURE;
    STDMETHOD( get_Contrast )( THIS_ long *, long * ) PURE;
    STDMETHOD( put_Contrast )( THIS_ long, long ) PURE;
    STDMETHOD( getRange_Contrast )( THIS_ long *, long *, long *, long *, long * ) PURE;
    STDMETHOD( get_Gamma )( THIS_ long *, long * ) PURE;
    STDMETHOD( put_Gamma )( THIS_ long, long ) PURE;
    STDMETHOD( getRange_Gamma )( THIS_ long *, long *, long *, long *, long * ) PURE;
    STDMETHOD( get_Saturation )( THIS_ long *, long * ) PURE;
    STDMETHOD( put_Saturation )( THIS_ long, long ) PURE;
    STDMETHOD( getRange_Saturation )( THIS_ long *, long *, long *, long *, long * ) PURE;
    STDMETHOD( get_Sharpness )( THIS_ long *, long * ) PURE;
    STDMETHOD( put_Sharpness )( THIS_ long, long ) PURE;
    STDMETHOD( getRange_Sharpness )( THIS_ long *, long *, long *, long *, long * ) PURE;
    STDMETHOD( get_WhiteBalance )( THIS_ long *, long * ) PURE;
    STDMETHOD( put_WhiteBalance )( THIS_ long, long ) PURE;
    STDMETHOD( getRange_WhiteBalance )( THIS_ long *, long *, long *, long *, long * ) PURE;
    STDMETHOD( get_Gain )( THIS_ long *, long * ) PURE;
    STDMETHOD( put_Gain )( THIS_ long, long ) PURE;
    STDMETHOD( getRange_Gain )( THIS_ long *, long *, long *, long *, long * ) PURE;
    STDMETHOD( get_Hue )( THIS_ long *, long * ) PURE;
    STDMETHOD( put_Hue )( THIS_ long, long ) PURE;
    STDMETHOD( getRange_Hue )( THIS_ long *, long *, long *, long *, long * ) PURE;
    STDMETHOD( get_DigitalMultiplier )( THIS_ long *, long * ) PURE;
    STDMETHOD( put_DigitalMultiplier )( THIS_ long, long ) PURE;
    STDMETHOD( getRange_DigitalMultiplier )( THIS_ long *, long *, long *, long *, long * ) PURE;
    STDMETHOD( get_PowerlineFrequency )( THIS_ long *, long * ) PURE;
    STDMETHOD( put_PowerlineFrequency )( THIS_ long, long ) PURE;
    STDMETHOD( getRange_PowerlineFrequency )( THIS_ long *, long *, long *, long *, long * ) PURE;
    STDMETHOD( get_WhiteBalanceComponent )( THIS_ long *, long *, long * ) PURE;
    STDMETHOD( put_WhiteBalanceComponent )( THIS_ long, long, long ) PURE;
    STDMETHOD( getRange_WhiteBalanceComponent )( THIS_ long *, long *, long *, long *, long * ) PURE;
};

/* IKsNodeControl interface */
#undef INTERFACE
#define INTERFACE   IKsNodeControl
DECLARE_INTERFACE_( IKsNodeControl, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IKsNodeControl methods */
    STDMETHOD( put_NodeId )( THIS_ DWORD ) PURE;
    STDMETHOD( put_KsControl )( THIS_ PVOID ) PURE;
};

/* C object macros */
#if (!defined( __cplusplus ) || defined( CINTERFACE )) && defined( COBJMACROS )
    #define IKsTopologyInfo_QueryInterface( x, p1, p2 ) \
        (x)->lpVtbl->QueryInterface( x, p1, p2 )
    #define IKsTopologyInfo_AddRef( x ) \
        (x)->lpVtbl->AddRef( x )
    #define IKsTopologyInfo_Release( x ) \
        (x)->lpVtbl->Release( x )
    #define IKsTopologyInfo_get_NumCategories( x, p ) \
        (x)->lpVtbl->get_NumCategories( x, p )
    #define IKsTopologyInfo_get_Category( x, p1, p2 ) \
        (x)->lpVtbl->get_Category( x, p1, p2 )
    #define IKsTopologyInfo_get_NumConnections( x, p ) \
        (x)->lpVtbl->get_NumConnections( x, p )
    #define IKsTopologyInfo_get_ConnectionInfo( x, p1, p2 ) \
        (x)->lpVtbl->get_ConnectionInfo( x, p1, p2 )
    #define IKsTopologyInfo_get_NodeName( x, p1, p2, p3, p4 ) \
        (x)->lpVtbl->get_NodeName( x, p1, p2, p3, p4 )
    #define IKsTopologyInfo_get_NumNodes( x, p ) \
        (x)->lpVtbl->get_NumNodes( x, p )
    #define IKsTopologyInfo_get_NodeType( x, p1, p2 ) \
        (x)->lpVtbl->get_NodeType( x, p1, p2 )
    #define IKsTopologyInfo_CreateNodeInstance( x, p1, p2, p3 ) \
        (x)->lpVtbl->CreateNodeInstance( x, p1, p2, p3 )
    #define ISelector_QueryInterface( x, p1, p2 ) \
        (x)->lpVtbl->QueryInterface( x, p1, p2 )
    #define ISelector_AddRef( x ) \
        (x)->lpVtbl->AddRef( x )
    #define ISelector_Release( x ) \
        (x)->lpVtbl->Release( x )
    #define ISelector_get_NumSources( x, p ) \
        (x)->lpVtbl->get_NumSources( x, p )
    #define ISelector_get_SourceNodeId( x, p ) \
        (x)->lpVtbl->get_SourceNodeId( x, p )
    #define ISelector_put_SourceNodeId( x, p ) \
        (x)->lpVtbl->put_SourceNodeId( x, p )
    #define ICameraControl_QueryInterface( x, p1, p2 ) \
        (x)->lpVtbl->QueryInterface( x, p1, p2 )
    #define ICameraControl_AddRef( x ) \
        (x)->lpVtbl->AddRef( x )
    #define ICameraControl_Release( x ) \
        (x)->lpVtbl->Release( x )
    #define ICameraControl_get_Exposure( x, p1, p2 ) \
        (x)->lpVtbl->get_Exposure( x, p1, p2 )
    #define ICameraControl_put_Exposure( x, p1, p2 ) \
        (x)->lpVtbl->put_Exposure( x, p1, p2 )
    #define ICameraControl_getRange_Exposure( x, p1, p2, p3, p4, p5 ) \
        (x)->lpVtbl->getRange_Exposure( x, p1, p2, p3, p4, p5 )
    #define ICameraControl_get_Focus( x, p1, p2 ) \
        (x)->lpVtbl->get_Focus( x, p1, p2 )
    #define ICameraControl_put_Focus( x, p1, p2 ) \
        (x)->lpVtbl->put_Focus( x, p1, p2 )
    #define ICameraControl_getRange_Focus( x, p1, p2, p3, p4, p5 ) \
        (x)->lpVtbl->getRange_Focus( x, p1, p2, p3, p4, p5 )
    #define ICameraControl_get_Iris( x, p1, p2 ) \
        (x)->lpVtbl->get_Iris( x, p1, p2 )
    #define ICameraControl_put_Iris( x, p1, p2 ) \
        (x)->lpVtbl->put_Iris( x, p1, p2 )
    #define ICameraControl_getRange_Iris( x, p1, p2, p3, p4, p5 ) \
        (x)->lpVtbl->getRange_Iris( x, p1, p2, p3, p4, p5 )
    #define ICameraControl_get_Zoom( x, p1, p2 ) \
        (x)->lpVtbl->get_Zoom( x, p1, p2 )
    #define ICameraControl_put_Zoom( x, p1, p2 ) \
        (x)->lpVtbl->put_Zoom( x, p1, p2 )
    #define ICameraControl_getRange_Zoom( x, p1, p2, p3, p4, p5 ) \
        (x)->lpVtbl->getRange_Zoom( x, p1, p2, p3, p4, p5 )
    #define ICameraControl_get_FocalLengths( x, p1, p2, p3 ) \
        (x)->lpVtbl->get_FocalLengths( x, p1, p2, p3 )
    #define ICameraControl_get_Pan( x, p1, p2 ) \
        (x)->lpVtbl->get_Pan( x, p1, p2 )
    #define ICameraControl_put_Pan( x, p1, p2 ) \
        (x)->lpVtbl->put_Pan( x, p1, p2 )
    #define ICameraControl_getRange_Pan( x, p1, p2, p3, p4, p5 ) \
        (x)->lpVtbl->getRange_Pan( x, p1, p2, p3, p4, p5 )
    #define ICameraControl_get_Tilt( x, p1, p2 ) \
        (x)->lpVtbl->get_Tilt( x, p1, p2 )
    #define ICameraControl_put_Tilt( x, p1, p2 ) \
        (x)->lpVtbl->put_Tilt( x, p1, p2 )
    #define ICameraControl_getRange_Tilt( x, p1, p2, p3, p4, p5 ) \
        (x)->lpVtbl->getRange_Tilt( x, p1, p2, p3, p4, p5 )
    #define ICameraControl_get_PanTilt( x, p1, p2, p3 ) \
        (x)->lpVtbl->get_PanTilt( x, p1, p2, p3 )
    #define ICameraControl_put_PanTilt( x, p1, p2, p3 ) \
        (x)->lpVtbl->put_PanTilt( x, p1, p2, p3 )
    #define ICameraControl_get_Roll( x, p1, p2 ) \
        (x)->lpVtbl->get_Roll( x, p1, p2 )
    #define ICameraControl_put_Roll( x, p1, p2 ) \
        (x)->lpVtbl->put_Roll( x, p1, p2 )
    #define ICameraControl_getRange_Roll( x, p1, p2, p3, p4, p5 ) \
        (x)->lpVtbl->getRange_Roll( x, p1, p2, p3, p4, p5 )
    #define ICameraControl_get_ExposureRelative( x, p1, p2 ) \
        (x)->lpVtbl->get_ExposureRelative( x, p1, p2 )
    #define ICameraControl_put_ExposureRelative( x, p1, p2 ) \
        (x)->lpVtbl->put_ExposureRelative( x, p1, p2 )
    #define ICameraControl_getRange_ExposureRelative( x, p1, p2, p3, p4, p5 ) \
        (x)->lpVtbl->getRange_ExposureRelative( x, p1, p2, p3, p4, p5 )
    #define ICameraControl_get_FocusRelative( x, p1, p2 ) \
        (x)->lpVtbl->get_FocusRelative( x, p1, p2 )
    #define ICameraControl_put_FocusRelative( x, p1, p2 ) \
        (x)->lpVtbl->put_FocusRelative( x, p1, p2 )
    #define ICameraControl_getRange_FocusRelative( x, p1, p2, p3, p4, p5 ) \
        (x)->lpVtbl->getRange_FocusRelative( x, p1, p2, p3, p4, p5 )
    #define ICameraControl_get_IrisRelative( x, p1, p2 ) \
        (x)->lpVtbl->get_IrisRelative( x, p1, p2 )
    #define ICameraControl_put_IrisRelative( x, p1, p2 ) \
        (x)->lpVtbl->put_IrisRelative( x, p1, p2 )
    #define ICameraControl_getRange_IrisRelative( x, p1, p2, p3, p4, p5 ) \
        (x)->lpVtbl->getRange_IrisRelative( x, p1, p2, p3, p4, p5 )
    #define ICameraControl_get_ZoomRelative( x, p1, p2 ) \
        (x)->lpVtbl->get_ZoomRelative( x, p1, p2 )
    #define ICameraControl_put_ZoomRelative( x, p1, p2 ) \
        (x)->lpVtbl->put_ZoomRelative( x, p1, p2 )
    #define ICameraControl_getRange_ZoomRelative( x, p1, p2, p3, p4, p5 ) \
        (x)->lpVtbl->getRange_ZoomRelative( x, p1, p2, p3, p4, p5 )
    #define ICameraControl_get_PanRelative( x, p1, p2 ) \
        (x)->lpVtbl->get_PanRelative( x, p1, p2 )
    #define ICameraControl_put_PanRelative( x, p1, p2 ) \
        (x)->lpVtbl->put_PanRelative( x, p1, p2 )
    #define ICameraControl_get_TiltRelative( x, p1, p2 ) \
        (x)->lpVtbl->get_TiltRelative( x, p1, p2 )
    #define ICameraControl_put_TiltRelative( x, p1, p2 ) \
        (x)->lpVtbl->put_TiltRelative( x, p1, p2 )
    #define ICameraControl_getRange_TiltRelative( x, p1, p2, p3, p4, p5 ) \
        (x)->lpVtbl->getRange_TiltRelative( x, p1, p2, p3, p4, p5 )
    #define ICameraControl_get_PanTiltRelative( x, p1, p2, p3 ) \
        (x)->lpVtbl->get_PanTiltRelative( x, p1, p2, p3 )
    #define ICameraControl_put_PanTiltRelative( x, p1, p2, p3 ) \
        (x)->lpVtbl->put_PanTiltRelative( x, p1, p2, p3 )
    #define ICameraControl_getRange_PanRelative( x, p1, p2, p3, p4, p5 ) \
        (x)->lpVtbl->getRange_PanRelative( x, p1, p2, p3, p4, p5 )
    #define ICameraControl_get_RollRelative( x, p1, p2 ) \
        (x)->lpVtbl->get_RollRelative( x, p1, p2 )
    #define ICameraControl_put_RollRelative( x, p1, p2 ) \
        (x)->lpVtbl->put_RollRelative( x, p1, p2 )
    #define ICameraControl_getRange_RollRelative( x, p1, p2, p3, p4, p5 ) \
        (x)->lpVtbl->getRange_RollRelative( x, p1, p2, p3, p4, p5 )
    #define ICameraControl_get_ScanMode( x, p1, p2 ) \
        (x)->lpVtbl->get_ScanMode( x, p1, p2 )
    #define ICameraControl_put_ScanMode( x, p1, p2 ) \
        (x)->lpVtbl->put_ScanMode( x, p1, p2 )
    #define ICameraControl_get_PrivacyMode( x, p1, p2 ) \
        (x)->lpVtbl->get_PrivacyMode( x, p1, p2 )
    #define ICameraControl_put_PrivacyMode( x, p1, p2 ) \
        (x)->lpVtbl->put_PrivacyMode( x, p1, p2 )
    #define IVideoProcAmp_QueryInterface( x, p1, p2 ) \
        (x)->lpVtbl->QueryInterface( x, p1, p2 )
    #define IVideoProcAmp_AddRef( x ) \
        (x)->lpVtbl->AddRef( x )
    #define IVideoProcAmp_Release( x ) \
        (x)->lpVtbl->Release( x )
    #define IVideoProcAmp_get_BacklightCompensation( x, p1, p2 ) \
        (x)->lpVtbl->get_BacklightCompensation( x, p1, p2 )
    #define IVideoProcAmp_put_BacklightCompensation( x, p1, p2 ) \
        (x)->lpVtbl->put_BacklightCompensation( x, p1, p2 )
    #define IVideoProcAmp_getRange_BacklightCompensation( x, p1, p2, p3, p4, p5 ) \
        (x)->lpVtbl->getRange_BacklightCompensation( x, p1, p2, p3, p4, p5 )
    #define IVideoProcAmp_get_Brightness( x, p1, p2 ) \
        (x)->lpVtbl->get_Brightness( x, p1, p2 )
    #define IVideoProcAmp_put_Brightness( x, p1, p2 ) \
        (x)->lpVtbl->put_Brightness( x, p1, p2 )
    #define IVideoProcAmp_getRange_Brightness( x, p1, p2, p3, p4, p5 ) \
        (x)->lpVtbl->getRange_Brightness( x, p1, p2, p3, p4, p5 )
    #define IVideoProcAmp_get_ColorEnable( x, p1, p2 ) \
        (x)->lpVtbl->get_ColorEnable( x, p1, p2 )
    #define IVideoProcAmp_put_ColorEnable( x, p1, p2 ) \
        (x)->lpVtbl->put_ColorEnable( x, p1, p2 )
    #define IVideoProcAmp_getRange_ColorEnable( x, p1, p2, p3, p4, p5 ) \
        (x)->lpVtbl->getRange_ColorEnable( x, p1, p2, p3, p4, p5 )
    #define IVideoProcAmp_get_Contrast( x, p1, p2 ) \
        (x)->lpVtbl->get_Contrast( x, p1, p2 )
    #define IVideoProcAmp_put_Contrast( x, p1, p2 ) \
        (x)->lpVtbl->put_Contrast( x, p1, p2 )
    #define IVideoProcAmp_getRange_Contrast( x, p1, p2, p3, p4, p5 ) \
        (x)->lpVtbl->getRange_Contrast( x, p1, p2, p3, p4, p5 )
    #define IVideoProcAmp_get_Gamma( x, p1, p2 ) \
        (x)->lpVtbl->get_Gamma( x, p1, p2 )
    #define IVideoProcAmp_put_Gamma( x, p1, p2 ) \
        (x)->lpVtbl->put_Gamma( x, p1, p2 )
    #define IVideoProcAmp_getRange_Gamma( x, p1, p2, p3, p4, p5 ) \
        (x)->lpVtbl->getRange_Gamma( x, p1, p2, p3, p4, p5 )
    #define IVideoProcAmp_get_Saturation( x, p1, p2 ) \
        (x)->lpVtbl->get_Saturation( x, p1, p2 )
    #define IVideoProcAmp_put_Saturation( x, p1, p2 ) \
        (x)->lpVtbl->put_Saturation( x, p1, p2 )
    #define IVideoProcAmp_getRange_Saturation( x, p1, p2, p3, p4, p5 ) \
        (x)->lpVtbl->getRange_Saturation( x, p1, p2, p3, p4, p5 )
    #define IVideoProcAmp_get_Sharpness( x, p1, p2 ) \
        (x)->lpVtbl->get_Sharpness( x, p1, p2 )
    #define IVideoProcAmp_put_Sharpness( x, p1, p2 ) \
        (x)->lpVtbl->put_Sharpness( x, p1, p2 )
    #define IVideoProcAmp_getRange_Sharpness( x, p1, p2, p3, p4, p5 ) \
        (x)->lpVtbl->getRange_Sharpness( x, p1, p2, p3, p4, p5 )
    #define IVideoProcAmp_get_WhiteBalance( x, p1, p2 ) \
        (x)->lpVtbl->get_WhiteBalance( x, p1, p2 )
    #define IVideoProcAmp_put_WhiteBalance( x, p1, p2 ) \
        (x)->lpVtbl->put_WhiteBalance( x, p1, p2 )
    #define IVideoProcAmp_getRange_WhiteBalance( x, p1, p2, p3, p4, p5 ) \
        (x)->lpVtbl->getRange_WhiteBalance( x, p1, p2, p3, p4, p5 )
    #define IVideoProcAmp_get_Gain( x, p1, p2 ) \
        (x)->lpVtbl->get_Gain( x, p1, p2 )
    #define IVideoProcAmp_put_Gain( x, p1, p2 ) \
        (x)->lpVtbl->put_Gain( x, p1, p2 )
    #define IVideoProcAmp_getRange_Gain( x, p1, p2, p3, p4, p5 ) \
        (x)->lpVtbl->getRange_Gain( x, p1, p2, p3, p4, p5 )
    #define IVideoProcAmp_get_Hue( x, p1, p2 ) \
        (x)->lpVtbl->get_Hue( x, p1, p2 )
    #define IVideoProcAmp_put_Hue( x, p1, p2 ) \
        (x)->lpVtbl->put_Hue( x, p1, p2 )
    #define IVideoProcAmp_getRange_Hue( x, p1, p2, p3, p4, p5 ) \
        (x)->lpVtbl->getRange_Hue( x, p1, p2, p3, p4, p5 )
    #define IVideoProcAmp_get_DigitalMultiplier( x, p1, p2 ) \
        (x)->lpVtbl->get_DigitalMultiplier( x, p1, p2 )
    #define IVideoProcAmp_put_DigitalMultiplier( x, p1, p2 ) \
        (x)->lpVtbl->put_DigitalMultiplier( x, p1, p2 )
    #define IVideoProcAmp_getRange_DigitalMultiplier( x, p1, p2, p3, p4, p5 ) \
        (x)->lpVtbl->getRange_DigitalMultiplier( x, p1, p2, p3, p4, p5 )
    #define IVideoProcAmp_get_PowerlineFrequency( x, p1, p2 ) \
        (x)->lpVtbl->get_PowerlineFrequency( x, p1, p2 )
    #define IVideoProcAmp_put_PowerlineFrequency( x, p1, p2 ) \
        (x)->lpVtbl->put_PowerlineFrequency( x, p1, p2 )
    #define IVideoProcAmp_getRange_PowerlineFrequency( x, p1, p2, p3, p4, p5 ) \
        (x)->lpVtbl->getRange_PowerlineFrequency( x, p1, p2, p3, p4, p5 )
    #define IVideoProcAmp_get_WhiteBalanceComponent( x, p1, p2, p3 ) \
        (x)->lpVtbl->get_WhiteBalanceComponent( x, p1, p2, p3 )
    #define IVideoProcAmp_put_WhiteBalanceComponent( x, p1, p2, p3 ) \
        (x)->lpVtbl->put_WhiteBalanceComponent( x, p1, p2, p3 )
    #define IVideoProcAmp_getRange_WhiteBalanceComponent( x, p1, p2, p3, p4, p5 ) \
        (x)->lpVtbl->getRange_WhiteBalanceComponent( x, p1, p2, p3, p4, p5 )
    #define IKsNodeControl_QueryInterface( x, p1, p2 ) \
        (x)->lpVtbl->QueryInterface( x, p1, p2 )
    #define IKsNodeControl_AddRef( x ) \
        (x)->lpVtbl->AddRef( x )
    #define IKsNodeControl_Release( x ) \
        (x)->lpVtbl->Release( x )
    #define IKsNodeControl_put_NodeId( x, p ) \
        (x)->lpVtbl->put_NodeId( x, p )
    #define IKsNodeControl_put_KsControl( x, p ) \
        (x)->lpVtbl->put_KsControl( x, p )
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __vidcap_h__ */
