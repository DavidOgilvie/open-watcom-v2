/*
 *  amstream.h  ActiveMovie streaming interfaces
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

#ifndef __amstream_h__
#define __amstream_h__

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file;
#endif

#include <strmif.h>
#include <ddraw.h>
#include <mmsystem.h>
#include <mmstream.h>
#include <ddstream.h>
#include <austream.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
typedef interface IMediaStreamFilter    IMediaStreamFilter;
typedef interface IAMMediaTypeSample    IAMMediaTypeSample;

/* ActiveMovie multimedia stream flags */
enum {
    AMMSF_NOGRAPHTHREAD         = 0x00000001,
    AMMSF_ADDDEFAULTRENDERER    = 0x00000001,
    AMMSF_CREATEPEER            = 0x00000002,
    AMMSF_STOPIFNOSAMPLES       = 0x00000004,
    AMMSF_NOSTALL               = 0x00000008,
    AMMSF_RENDERTYPEMASK        = 0x00000003,
    AMMSF_RENDERTOEXISTING      = 0x00000000,
    AMMSF_RENDERALLSTREAMS      = 0x00000001,
    AMMSF_NORENDER              = 0x00000002,
    AMMSF_NOCLOCK               = 0x00000004,
    AMMSF_RUN                   = 0x00000008
};

/* Output states */
typedef enum {
    Disabled    = 0,
    ReadData    = 1,
    RenderData  = 2
} OUTPUT_STATE;

/* GUIDs */
EXTERN_C const IID      IID_IAMMultiMediaStream;
EXTERN_C const IID      IID_IAMMediaStream;
EXTERN_C const IID      IID_IMediaStreamFilter;
EXTERN_C const IID      IID_IDirectDrawMediaSampleAllocator;
EXTERN_C const IID      IID_IDirectDrawMediaSample;
EXTERN_C const IID      IID_IAMMediaTypeStream;
EXTERN_C const IID      IID_IAMMediaTypeSample;
EXTERN_C const CLSID    CLSID_AMMultiMediaStream;
EXTERN_C const CLSID    CLSID_AMDirectDrawStream;
EXTERN_C const CLSID    CLSID_AMAudioStream;
EXTERN_C const CLSID    CLSID_AMAudioData;
EXTERN_C const CLSID    CLSID_AMMediaTypeStream;

/* IAMMultiMediaStream interface */
#undef INTERFACE
#define INTERFACE   IAMMultiMediaStream
DECLARE_INTERFACE_( IAMMultiMediaStream, IMultiMediaStream ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IMultiMediaStream interface */
    STDMETHOD( GetInformation )( THIS_ DWORD *, STREAM_TYPE * ) PURE;
    STDMETHOD( GetMediaStream )( THIS_ REFMSPID, IMediaStream ** ) PURE;
    STDMETHOD( EnumMediaStream )( THIS_ long, IMediaStream ** ) PURE;
    STDMETHOD( GetState )( THIS_ STREAM_STATE * ) PURE;
    STDMETHOD( SetState )( THIS_ STREAM_STATE ) PURE;
    STDMETHOD( GetTime )( THIS_ STREAM_TIME * ) PURE;
    STDMETHOD( GetDuration )( THIS_ STREAM_TIME * ) PURE;
    STDMETHOD( Seek )( THIS_ STREAM_TIME ) PURE;
    STDMETHOD( GetEndOfStreamEventHandle )( THIS_ HANDLE * ) PURE;

    /* IAMMultiMediaStream interface */
    STDMETHOD( Initialize )( THIS_ STREAM_TYPE, DWORD, IGraphBuilder * ) PURE;
    STDMETHOD( GetFilterGraph )( THIS_ IGraphBuilder ** ) PURE;
    STDMETHOD( GetFilter )( THIS_ IMediaStreamFilter ** ) PURE;
    STDMETHOD( AddMediaStream )( THIS_ IUnknown *, const MSPID *, DWORD, IMediaStream ** ) PURE;
    STDMETHOD( OpenFile )( THIS_ LPCWSTR, DWORD ) PURE;
    STDMETHOD( OpenMoniker )( THIS_ IBindCtx *, IMoniker *, DWORD ) PURE;
    STDMETHOD( Render )( THIS_ DWORD ) PURE;
};

/* IAMMediaStream interface */
#undef INTERFACE
#define INTERFACE   IAMMediaStream
DECLARE_INTERFACE_( IAMMediaStream, IMediaStream ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IMediaStream methods */
    STDMETHOD( GetMultiMediaStream )( THIS_ IMultiMediaStream ** ) PURE;
    STDMETHOD( GetInformation )( THIS_ MSPID *, STREAM_TYPE * ) PURE;
    STDMETHOD( SetSameFormat )( THIS_ IMediaStream *, DWORD ) PURE;
    STDMETHOD( AllocateSample )( THIS_ DWORD, IStreamSample ** ) PURE;
    STDMETHOD( CreateSharedSample )( THIS_ IStreamSample *, DWORD, IStreamSample ** ) PURE;
    STDMETHOD( SendEndOfStream )( THIS_ DWORD ) PURE;

    /* IAMMediaStream methods */
    STDMETHOD( Initialize )( THIS_ IUnknown *, DWORD, REFMSPID, const STREAM_TYPE ) PURE;
    STDMETHOD( SetState )( THIS_ FILTER_STATE ) PURE;
    STDMETHOD( JoinAMMultiMediaStream )( THIS_ IAMMultiMediaStream * ) PURE;
    STDMETHOD( JoinFilter )( THIS_ IMediaStreamFilter * ) PURE;
    STDMETHOD( JoinFilterGraph )( THIS_ IFilterGraph * ) PURE;
};

/* IMediaStreamFilter interface */
#undef INTERFACE
#define INTERFACE   IMediaStreamFilter
DECLARE_INTERFACE_( IMediaStreamFilter, IBaseFilter ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;
    
    /* IPersist methods */
    STDMETHOD( GetClassID )( THIS_ CLSID * ) PURE;

    /* IMediaFilter methods */
    STDMETHOD( Stop )( THIS ) PURE;
    STDMETHOD( Pause )( THIS ) PURE;
    STDMETHOD( Run )( THIS_ REFERENCE_TIME ) PURE;
    STDMETHOD( GetState )( THIS_ DWORD, FILTER_STATE * ) PURE;
    STDMETHOD( SetSyncSource )( THIS_ IReferenceClock * ) PURE;
    STDMETHOD( GetSyncSource )( THIS_ IReferenceClock ** ) PURE;

    /* IBaseFilter methods */
    STDMETHOD( EnumPins )( THIS_ IEnumPins ** ) PURE;
    STDMETHOD( FindPin )( THIS_ LPCWSTR, IPin ** ) PURE;
    STDMETHOD( QueryFilterInfo )( THIS_ FILTER_INFO * ) PURE;
    STDMETHOD( JoinFilterGraph )( THIS_ IFilterGraph *, LPCWSTR ) PURE;
    STDMETHOD( QueryVendorInfo )( THIS_ LPWSTR * ) PURE;

    /* IMediaStreamFilter methods */
    STDMETHOD( AddMediaStream )( THIS_ IAMMediaStream * ) PURE;
    STDMETHOD( GetMediaStream )( THIS_ REFMSPID, IMediaStream ** ) PURE;
    STDMETHOD( EnumMediaStreams )( THIS_ long, IMediaStream ** ) PURE;
    STDMETHOD( SupportSeeking )( THIS_ BOOL ) PURE;
    STDMETHOD( ReferenceTimeToStreamTime )( THIS_ REFERENCE_TIME * ) PURE;
    STDMETHOD( GetCurrentStreamTime )( THIS_ REFERENCE_TIME * ) PURE;
    STDMETHOD( WaitUntil )( THIS_ REFERENCE_TIME ) PURE;
    STDMETHOD( Flush )( THIS_ BOOL ) PURE;
    STDMETHOD( EndOfStream )( THIS ) PURE;
};

/* IDirectDrawMediaSampleAllocator interface */
#undef INTERFACE
#define INTERFACE   IDirectDrawMediaSampleAllocator
DECLARE_INTERFACE_( IDirectDrawMediaSampleAllocator, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IDirectDrawMediaSampleAllocator methods */
    STDMETHOD( GetDirectDraw )( THIS_ IDirectDraw ** ) PURE;
};

/* IDirectDrawMediaSample interface */
#undef INTERFACE
#define INTERFACE   IDirectDrawMediaSample
DECLARE_INTERFACE_( IDirectDrawMediaSample, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IDirectDrawMediaSample methods */
    STDMETHOD( GetSurfaceAndReleaseLock )( THIS_ IDirectDrawSurface *, RECT * ) PURE;
    STDMETHOD( LockMediaSamplePointer )( THIS ) PURE;
};

/* IAMMediaTypeStream interface */
#undef INTERFACE
#define INTERFACE   IAMMediaTypeStream
DECLARE_INTERFACE_( IAMMediaTypeStream, IMediaStream ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IMediaStream methods */
    STDMETHOD( GetMultiMediaStream )( THIS_ IMultiMediaStream ** ) PURE;
    STDMETHOD( GetInformation )( THIS_ MSPID *, STREAM_TYPE * ) PURE;
    STDMETHOD( SetSameFormat )( THIS_ IMediaStream *, DWORD ) PURE;
    STDMETHOD( AllocateSample )( THIS_ DWORD, IStreamSample ** ) PURE;
    STDMETHOD( CreateSharedSample )( THIS_ IStreamSample *, DWORD, IStreamSample ** ) PURE;
    STDMETHOD( SendEndOfStream )( THIS_ DWORD ) PURE;

    /* IAMMediaTypeStream methods */
    STDMETHOD( GetFormat )( THIS_ AM_MEDIA_TYPE *, DWORD ) PURE;
    STDMETHOD( SetFormat )( THIS_ AM_MEDIA_TYPE *, DWORD ) PURE;
    STDMETHOD( CreateSample )( THIS_ long, BYTE *, DWORD, IUnknown *, IAMMediaTypeSample ** ) PURE;
    STDMETHOD( GetStreamAllocatorRequirements )( THIS_ ALLOCATOR_PROPERTIES * ) PURE;
    STDMETHOD( SetStreamAllocatorRequirements )( THIS_ ALLOCATOR_PROPERTIES * ) PURE;
};

/* IAMMediaTypeSample interface */
#undef INTERFACE
#define INTERFACE   IAMMediaTypeSample
DECLARE_INTERFACE_( IAMMediaTypeSample, IStreamSample ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IStreamSample methods */
    STDMETHOD( GetMediaStream )( THIS_ IMediaStream ** ) PURE;
    STDMETHOD( GetSampleTimes )( THIS_ STREAM_TIME *, STREAM_TIME *, STREAM_TIME * ) PURE;
    STDMETHOD( SetSampleTimes )( THIS_ const STREAM_TIME *, const STREAM_TIME * ) PURE;
    STDMETHOD( Update )( THIS_ DWORD, HANDLE, PAPCFUNC, DWORD_PTR ) PURE;
    STDMETHOD( CompletionStatus )( DWORD, DWORD ) PURE;

    /* IAMMediaTypeSample methods */
    STDMETHOD( SetPointer )( THIS_ BYTE *, long ) PURE;
    STDMETHOD( GetPointer )( THIS_ BYTE ** ) PURE;
    STDMETHOD( GetSize )( THIS ) PURE;
    STDMETHOD( GetTime )( THIS_ REFERENCE_TIME *, REFERENCE_TIME * ) PURE;
    STDMETHOD( SetTime )( THIS_ REFERENCE_TIME *, REFERENCE_TIME * ) PURE;
    STDMETHOD( IsSyncPoint )( THIS ) PURE;
    STDMETHOD( SetSyncPoint )( THIS_ BOOL ) PURE;
    STDMETHOD( IsPreroll )( THIS ) PURE;
    STDMETHOD( SetPreroll )( THIS_ BOOL ) PURE;
    STDMETHOD_( long, GetActualDataLength )( THIS ) PURE;
    STDMETHOD( SetActualDataLength )( THIS_ long ) PURE;
    STDMETHOD( GetMediaType )( THIS_ AM_MEDIA_TYPE ** ) PURE;
    STDMETHOD( SetMediaType )( THIS_ AM_MEDIA_TYPE * ) PURE;
    STDMETHOD( IsDiscontinuity )( THIS ) PURE;
    STDMETHOD( SetDiscontinuity )( THIS_ BOOL ) PURE;
    STDMETHOD( GetMediaTime )( THIS_ LONGLONG *, LONGLONG * ) PURE;
    STDMETHOD( SetMediaTime )( THIS_ LONGLONG *, LONGLONG * ) PURE;
};

/* C object macros */
#if (!defined( __cplusplus ) || defined( CINTERFACE )) && defined( COBJMACROS )
    #define IAMMultiMediaStream_QueryInterface( x, p1, p2 ) \
        (x)->lpVtbl->QueryInterface( x, p1, p2 )
    #define IAMMultiMediaStream_AddRef( x ) \
        (x)->lpVtbl->AddRef( x )
    #define IAMMultiMediaStream_Release( x ) \
        (x)->lpVtbl->Release( x )
    #define IAMMultiMediaStream_GetInformation( x, p1, p2 ) \
        (x)->lpVtbl->GetInformation( x, p1, p2 )
    #define IAMMultiMediaStream_GetMediaStream( x, p1, p2 ) \
        (x)->lpVtbl->GetMediaStream( x, p1, p2 )
    #define IAMMultiMediaStream_EnumMediaStream( x, p1, p2 ) \
        (x)->lpVtbl->EnumMediaStream( x, p1, p2 )
    #define IAMMultiMediaStream_GetState( x, p ) \
        (x)->lpVtbl->GetState( x, p )
    #define IAMMultiMediaStream_SetState( x, p ) \
        (x)->lpVtbl->SetState( x, p )
    #define IAMMultiMediaStream_GetTime( x, p ) \
        (x)->lpVtbl->GetTime( x, p )
    #define IAMMultiMediaStream_GetDuration( x, p ) \
        (x)->lpVtbl->GetDuration( x, p )
    #define IAMMultiMediaStream_Seek( x, p ) \
        (x)->lpVtbl->Seek( x, p )
    #define IAMMultiMediaStream_GetEndOfStreamEventHandle( x, p ) \
        (x)->lpVtbl->GetEndOfStreamEventHandle( x, p )
    #define IAMMultiMediaStream_Initialize( x, p1, p2, p3 ) \
        (x)->lpVtbl->Initialize( x, p1, p2, p3 )
    #define IAMMultiMediaStream_GetFilterGraph( x, p ) \
        (x)->lpVtbl->GetFilterGraph( x, p )
    #define IAMMultiMediaStream_GetFilter( x, p ) \
        (x)->lpVtbl->GetFilter( x, p )
    #define IAMMultiMediaStream_AddMediaStream( x, p1, p2, p3, p4 ) \
        (x)->lpVtbl->AddMediaStream( x, p1, p2, p3, p4 )
    #define IAMMultiMediaStream_OpenFile( x, p1, p2 ) \
        (x)->lpVtbl->OpenFile( x, p1, p2 )
    #define IAMMultiMediaStream_OpenMoniker( x, p1, p2, p3 ) \
        (x)->lpVtbl->OpenMoniker( x, p1, p2, p3 )
    #define IAMMultiMediaStream_Render( x, p ) \
        (x)->lpVtbl->Render( x, p )
    #define IAMMediaStream_QueryInterface( x, p1, p2 ) \
        (x)->lpVtbl->QueryInterface( x, p1, p2 )
    #define IAMMediaStream_AddRef( x ) \
        (x)->lpVtbl->AddRef( x )
    #define IAMMediaStream_Release( x ) \
        (x)->lpVtbl->Release( x )
    #define IAMMediaStream_GetMultiMediaStream( x, p ) \
        (x)->lpVtbl->GetMultiMediaStream( x, p )
    #define IAMMediaStream_GetInformation( x, p1, p2 ) \
        (x)->lpVtbl->GetInformation( x, p1, p2 )
    #define IAMMediaStream_SetSameFormat( x, p1, p2 ) \
        (x)->lpVtbl->SetSameFormat( x, p1, p2 )
    #define IAMMediaStream_AllocateSample( x, p1, p2 ) \
        (x)->lpVtbl->AllocateSample( x, p1, p2 )
    #define IAMMediaStream_CreateSharedSample( x, p1, p2, p3 ) \
        (x)->lpVtbl->CreateSharedSample( x, p1, p2, p3 )
    #define IAMMediaStream_SendEndOfStream( x, p ) \
        (x)->lpVtbl->SendEndOfStream( x, p )
    #define IAMMediaStream_Initialize( x, p1, p2, p3, p4 ) \
        (x)->lpVtbl->Initialize( x, p1, p2, p3, p4 )
    #define IAMMediaStream_SetState( x, p ) \
        (x)->lpVtbl->SetState( x, p )
    #define IAMMediaStream_JoinAMMultiMediaStream( x, p ) \
        (x)->lpVtbl->JoinAMMultiMediaStream( x, p )
    #define IAMMediaStream_JoinFilter( x, p ) \
        (x)->lpVtbl->JoinFilter( x, p )
    #define IAMMediaStream_JoinFilterGraph( x, p ) \
        (x)->lpVtbl->JoinFilterGraph( x, p )
    #define IMediaStreamFilter_QueryInterface( x, p1, p2 ) \
        (x)->lpVtbl->QueryInterface( x, p1, p2 )
    #define IMediaStreamFilter_AddRef( x ) \
        (x)->lpVtbl->AddRef( x )
    #define IMediaStreamFilter_Release( x ) \
        (x)->lpVtbl->Release( x )
    #define IMediaStreamFilter_GetClassID( x, p ) \
        (x)->lpVtbl->GetClassID( x, p )
    #define IMediaStreamFilter_Stop( x ) \
        (x)->lpVtbl->Stop( x )
    #define IMediaStreamFilter_Pause( x ) \
        (x)->lpVtbl->Pause( x )
    #define IMediaStreamFilter_Run( x, p ) \
        (x)->lpVtbl->Run( x, p )
    #define IMediaStreamFilter_GetState( x, p1, p2 ) \
        (x)->lpVtbl->GetState( x, p1, p2 )
    #define IMediaStreamFilter_SetSyncSource( x, p ) \
        (x)->lpVtbl->SetSyncSource( x, p )
    #define IMediaStreamFilter_GetSyncSource( x, p ) \
        (x)->lpVtbl->GetSyncSource( x, p )
    #define IMediaStreamFilter_EnumPins( x, p ) \
        (x)->lpVtbl->EnumPins( x, p )
    #define IMediaStreamFilter_FindPin( x, p1, p2 ) \
        (x)->lpVtbl->FindPin( x, p1, p2 )
    #define IMediaStreamFilter_QueryFilterInfo( x, p ) \
        (x)->lpVtbl->QueryFilterInfo( x, p )
    #define IMediaStreamFilter_JoinFilterGraph( x, p1, p2 ) \
        (x)->lpVtbl->JoinFilterGraph( x, p1, p2 )
    #define IMediaStreamFilter_QueryVendorInfo( x, p ) \
        (x)->lpVtbl->QueryVendorInfo( x, p )
    #define IMediaStreamFilter_AddMediaStream( x, p ) \
        (x)->lpVtbl->AddMediaStream( x, p )
    #define IMediaStreamFilter_GetMediaStream( x, p1, p2 ) \
        (x)->lpVtbl->GetMediaStream( x, p1, p2 )
    #define IMediaStreamFilter_EnumMediaStreams( x, p1, p2 ) \
        (x)->lpVtbl->EnumMediaStreams( x, p1, p2 )
    #define IMediaStreamFilter_SupportSeeking( x, p ) \
        (x)->lpVtbl->SupportSeeking( x, p )
    #define IMediaStreamFilter_ReferenceTimeToStreamTime( x, p ) \
        (x)->lpVtbl->ReferenceTimeToStreamTime( x, p )
    #define IMediaStreamFilter_GetCurrentStreamTime( x, p ) \
        (x)->lpVtbl->GetCurrentStreamTime( x, p )
    #define IMediaStreamFilter_WaitUntil( x, p ) \
        (x)->lpVtbl->WaitUntil( x, p )
    #define IMediaStreamFilter_Flush( x, p ) \
        (x)->lpVtbl->Flush( x, p )
    #define IMediaStreamFilter_EndOfStream( x ) \
        (x)->lpVtbl->EndOfStream( x )
    #define IDirectDrawMediaSampleAllocator_QueryInterface( x, p1, p2 ) \
        (x)->lpVtbl->QueryInterface( x, p1, p2 )
    #define IDirectDrawMediaSampleAllocator_AddRef( x ) \
        (x)->lpVtbl->AddRef( x )
    #define IDirectDrawMediaSampleAllocator_Release( x ) \
        (x)->lpVtbl->Release( x )
    #define IDirectDrawMediaSampleAllocator_GetDirectDraw( x, p ) \
        (x)->lpVtbl->GetDirectDraw( x, p )
    #define IDirectDrawMediaSample_QueryInterface( x, p1, p2 ) \
        (x)->lpVtbl->QueryInterface( x, p1, p2 )
    #define IDirectDrawMediaSample_AddRef( x ) \
        (x)->lpVtbl->AddRef( x )
    #define IDirectDrawMediaSample_Release( x ) \
        (x)->lpVtbl->Release( x )
    #define IDirectDrawMediaSample_GetSurfaceAndReleaseLock( x, p1, p2 ) \
        (x)->lpVtbl->GetSurfaceAndReleaseLock( x, p1, p2 )
    #define IDirectDrawMediaSample_LockMediaSamplePointer( x ) \
        (x)->lpVtbl->LockMediaSamplePointer( x )
    #define IAMMediaTypeStream_QueryInterface( x, p1, p2 ) \
        (x)->lpVtbl->QueryInterface( x, p1, p2 )
    #define IAMMediaTypeStream_AddRef( x ) \
        (x)->lpVtbl->AddRef( x )
    #define IAMMediaTypeStream_Release( x ) \
        (x)->lpVtbl->Release( x )
    #define IAMMediaTypeStream_GetMultiMediaStream( x, p ) \
        (x)->lpVtbl->GetMultiMediaStream( x, p )
    #define IAMMediaTypeStream_GetInformation( x, p1, p2 ) \
        (x)->lpVtbl->GetInformation( x, p1, p2 )
    #define IAMMediaTypeStream_SetSameFormat( x, p1, p2 ) \
        (x)->lpVtbl->SetSameFormat( x, p1, p2 )
    #define IAMMediaTypeStream_AllocateSample( x, p1, p2 ) \
        (x)->lpVtbl->AllocateSample( x, p1, p2 )
    #define IAMMediaTypeStream_CreateSharedSample( x, p1, p2, p3 ) \
        (x)->lpVtbl->CreateSharedSample( x, p1, p2, p3 )
    #define IAMMediaTypeStream_SendEndOfStream( x, p ) \
        (x)->lpVtbl->SendEndOfStream( x, p )
    #define IAMMediaTypeStream_GetFormat( x, p1, p2 ) \
        (x)->lpVtbl->GetFormat( x, p1, p2 )
    #define IAMMediaTypeStream_SetFormat( x, p1, p2 ) \
        (x)->lpVtbl->SetFormat( x, p1, p2 )
    #define IAMMediaTypeStream_CreateSample( x, p1, p2, p3, p4, p5 ) \
        (x)->lpVtbl->CreateSample( x, p1, p2, p3, p4, p5 )
    #define IAMMediaTypeStream_GetStreamAllocatorRequirements( x, p ) \
        (x)->lpVtbl->GetStreamAllocatorRequirements( x, p )
    #define IAMMediaTypeStream_SetStreamAllocatorRequirements( x, p ) \
        (x)->lpVtbl->SetStreamAllocatorRequirements( x, p )
    #define IAMMediaTypeSample_QueryInterface( x, p1, p2 ) \
        (x)->lpVtbl->QueryInterface( x, p1, p2 )
    #define IAMMediaTypeSample_AddRef( x ) \
        (x)->lpVtbl->AddRef( x )
    #define IAMMediaTypeSample_Release( x ) \
        (x)->lpVtbl->Release( x )
    #define IAMMediaTypeSample_GetMediaStream( x, p ) \
        (x)->lpVtbl->GetMediaStream( x, p )
    #define IAMMediaTypeSample_GetSampleTimes( x, p1, p2, p3 ) \
        (x)->lpVtbl->GetSampleTimes( x, p1, p2, p3 )
    #define IAMMediaTypeSample_SetSampleTimes( x, p1, p2 ) \
        (x)->lpVtbl->SetSampleTimes( x, p1, p2 ) \
    #define IAMMediaTypeSample_Update( x, p1, p2, p3, p4 ) \
        (x)->lpVtbl->Update( x, p1, p2, p3, p4 )
    #define IAMMediaTypeSample_CompletionStatus( x, p1, p2 ) \
        (x)->lpVtbl->CompletionStatus( x, p1, p2 )
    #define IAMMediaTypeSample_SetPointer( x, p1, p2 ) \
        (x)->lpVtbl->SetPointer( x, p1, p2 )
    #define IAMMediaTypeSample_GetPointer( x, p ) \
        (x)->lpVtbl->GetPointer( x, p )
    #define IAMMediaTypeSample_GetSize( x ) \
        (x)->lpVtbl->GetSize( x )
    #define IAMMediaTypeSample_GetTime( x, p1, p2 ) \
        (x)->lpVtbl->GetTime( x, p1, p2 )
    #define IAMMediaTypeSample_SetTime( x, p1, p2 ) \
        (x)->lpVtbl->SetTime( x, p1, p2 )
    #define IAMMediaTypeSample_IsSyncPoint( x ) \
        (x)->lpVtbl->IsSyncPoint( x )
    #define IAMMediaTypeSample_SetSyncPoint( x, p ) \
        (x)->lpVtbl->SetSyncPoint( x, p )
    #define IAMMediaTypeSample_IsPreroll( x ) \
        (x)->lpVtbl->IsPreroll( x )
    #define IAMMediaTypeSample_SetPreroll( x, p ) \
        (x)->lpVtbl->SetPreroll( x, p )
    #define IAMMediaTypeSample_GetActualDataLength( x ) \
        (x)->lpVtbl->GetActualDataLength( x )
    #define IAMMediaTypeSample_SetActualDataLength( x, p ) \
        (x)->lpVtbl->SetActualDataLength( x, p )
    #define IAMMediaTypeSample_GetMediaType( x, p ) \
        (x)->lpVtbl->GetMediaType( x, p )
    #define IAMMediaTypeSample_SetMediaType( x, p ) \
        (x)->lpVtbl->SetMediaType( x, p )
    #define IAMMediaTypeSample_IsDiscontinuity( x ) \
        (x)->lpVtbl->IsDiscontinuity( x )
    #define IAMMediaTypeSample_SetDiscontinuity( x, p ) \
        (x)->lpVtbl->SetDiscontinuity( x, p )
    #define IAMMediaTypeSample_GetMediaTime( x, p1, p2 ) \
        (x)->lpVtbl->GetMediaTime( x, p1, p2 )
    #define IAMMediaTypeSample_SetMediaTime( x, p1, p2 ) \
        (x)->lpVtbl->SetMediaTime( x, p1, p2 )
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __amstream_h__ */
