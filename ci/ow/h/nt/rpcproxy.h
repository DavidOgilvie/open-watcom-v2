/*
 *  rpcproxy.h  RPC proxy definitions
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

#ifndef __RPCPROXY_H__
#define __RPCPROXY_H__

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file;
#endif

#include <basetsd.h>
#include <guiddef.h>
#include <rpc.h>
#include <rpcndr.h>
#include <string.h>
#include <memory.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Pointers to structures */
typedef struct tagCInterfaceStubVtbl    *PCInterfaceStubVtblList;
typedef struct tagCInterfaceProxyVtbl   *PCInterfaceProxyVtblList;

/* Interface name data type */
typedef const char  *PCInterfaceName;

/* Stub forwarding function */
#define STUB_FORWARDING_FUNCTION    NdrStubForwardingFunction

/* IID lookup return callback */
typedef int (__stdcall IIDLookupRtn)( const IID *, int * );
typedef IIDLookupRtn    *PIIDLookup;

/* Proxy file information */
typedef struct tagProxyFileInfo {
    const PCInterfaceProxyVtblList  *pProxyVtblList;
    const PCInterfaceStubVtblList   *pStubVtblList;
    const PCInterfaceName           *pNamesArray;
    const IID                       **pDelegatedIIDs;
    const PIIDLookup                pIIDLookupRtn;
    unsigned short                  TableSize;
    unsigned short                  TableVersion;
    const IID                       **pAsyncIIDLookup;
    LONG_PTR                        Filler2;
    LONG_PTR                        Filler3;
    LONG_PTR                        Filler4;
} ProxyFileInfo;
typedef ProxyFileInfo   ExtendedProxyFileInfo;

/* C interface proxy header */
typedef struct tagCInterfaceProxyHeader {
#ifdef USE_STUBLESS_PROXY
    const void  *pStublessProxyInfo;
#endif
    const IID   *piid;
} CInterfaceProxyHeader;

/* Macro to declare a C interface proxy virtual table */
#define CINTERFACE_PROXY_VTABLE( x ) \
    struct { \
        CInterfaceProxyHeader   header; \
        void                    *Vtbl[x]; \
    }

/* C interface proxy virtual table */
typedef struct tagCInterfaceProxyVtbl {
    CInterfaceProxyHeader   header;
    void                    *vtbl[1];
} CInterfaceProxyVtbl;

/* RPC stub function */
typedef void (RPC_ENTRY *PRPC_STUB_FUNCTION)( IRpcStubBuffer *, IRpcChannelBuffer *, PRPC_MESSAGE, DWORD * );

/* C interface stub header */
typedef struct tagCInterfaceStubHeader {
    const IID                   *piid;
    const MIDL_SERVER_INFO      *pServerInfo;
    unsigned long               DispatchTableCount;
    const PRPC_STUB_FUNCTION    *pDispatchTable;
} CInterfaceStubHeader;

/* C interface stub virtual table */
typedef struct tagCInterfaceStubVtbl {
    CInterfaceStubHeader    header;
    IRpcStubBufferVtbl      Vtbl;
} CInterfaceStubVtbl;

/* C standard stub buffer */
typedef struct tagCStdStubBuffer {
    const struct IRpcStubBufferVtbl         *lpVtbl;
    long                                    RefCount;
    struct IUnknown                         *pvServerObject;
    const struct ICallFactoryVtbl           *pCallFactoryVtbl;
    const IID                               *pAsyncIID;
    struct IPSFactoryBuffer                 *pPSFactory;
    const struct IReleaseMarshalBuffersVtbl *pRMBVtbl;
} CStdStubBuffer;

/* C standard proxy/stub factory buffer */
typedef struct tagCStdPSFactoryBuffer {
    const IPSFactoryBufferVtbl  *lpVtbl;
    long                        RefCount;
    const ProxyFileInfo         **pProxyFileList;
    long                        Filler1;
} CStdPSFactoryBuffer;

/* Proxy/stub macros */
#define IID_GENERIC_CHECK_IID( p1, p2, p3 ) \
    memcmp( p2, p1##_ProxyVtblList[p3]->header.piid, 16 )
#define IID_BS_LOOKUP_SETUP \
    int result; \
    int low = -1;
#define IID_BS_LOOKUP_INITIAL_TEST( p1, p2, p3 ) \
    result = p1##_CHECK_IID( p3 ); \
    if( result > 0 ) { \
        low = p2 - p3; \
    } else if( !result ) { \
        low = p3; \
        goto found_label; \
    }
#define IID_BS_LOOKUP_NEXT_TEST( p1, p2 ) \
    result = p1##_CHECK_IID( low + p2 ); \
    if( result >= 0 ) { \
        low = low + p2; \
        if( !result ) { \
            goto found_label; \
        } \
    }
#define IID_BS_LOOKUP_RETURN_RESULT( p1, p2, p3 ) \
    low++; \
    if( low >= p2 ) { \
        goto not_found_label; \
    } \
    result = p1##_CHECK_IID( low ); \
    if( result ) { \
        goto not_found_label; \
    }; \
found_label: \
    (p3) = low; \
    return 1; \
not_found_label: \
    return 0;

/* Proxy/stub entry point names */
#ifndef ENTRY_PREFIX
    #ifndef DllMain
        #define DISABLE_THREAD_LIBRARY_CALLS( x ) \
            DisableThreadLibraryCalls( x )
    #endif
    #define ENTRY_PREFIX
    #define DLLREGISTERSERVER_ENTRY     DllRegisterServer
    #define DLLUNREGISTERSERVER_ENTRY   DllUnregisterServer
    #define DLLMAIN_ENTRY               DllMain
    #define DLLGETCLASSOBJECT_ENTRY     DllGetClassObject
    #define DLLCANUNLOADNOW_ENTRY       DllCanUnloadNow
#else
    #define __rpc_macro_expand( p1, p2 )    p1##p2
    #define __rpc_macro_expand2( p1, p2 )   p1##p2
    #define DLLREGISTERSERVER_ENTRY \
        __rpc_macro_expand( ENTRY_PREFIX, DllRegisterServer )
    #define DLLUNREGISTERSERVER_ENTRY \
        __rpc_macro_expand( ENTRY_PREFIX, DllUnregisterServer )
    #define DLLMAIN_ENTRY \
        __rpc_macro_expand( ENTRY_PREFIX, DllMain )
    #define DLLGETCLASSOBJECT_ENTRY \
        __rpc_macro_expand( ENTRY_PREFIX, DllGetClassObject )
    #define DLLCANUNLOADNOW_ENTRY \
        __rpc_macro_expand( ENTRY_PREFIX, DllCanUnloadNow )
#endif
#ifndef DISABLE_THREAD_LIBRARY_CALLS
    #define DISABLE_THREAD_LIBRARY_CALLS( x )
#endif

/* Functions in RPCRT4.DLL */
RPCRTAPI HRESULT RPC_ENTRY  NdrDllCanUnloadNow( CStdPSFactoryBuffer * );
RPCRTAPI HRESULT RPC_ENTRY  NdrDllGetClassObject( REFCLSID, REFIID, void **, const ProxyFileInfo **, const CLSID *, CStdPSFactoryBuffer * );
RPCRTAPI HRESULT RPC_ENTRY  NdrDllRegisterProxy( HMODULE, const ProxyFileInfo **, const CLSID * );
RPCRTAPI HRESULT RPC_ENTRY  NdrDllUnregisterProxy( HMODULE, const ProxyFileInfo **, const CLSID * );
RPCRTAPI HRESULT RPC_ENTRY  NdrProxyErrorHandler( DWORD );
RPCRTAPI void RPC_ENTRY     NdrProxyFreeBuffer( void *, MIDL_STUB_MESSAGE * );
RPCRTAPI void RPC_ENTRY     NdrProxyGetBuffer( void *, PMIDL_STUB_MESSAGE );
RPCRTAPI void RPC_ENTRY     NdrProxyInitialize( void *, PRPC_MESSAGE, PMIDL_STUB_MESSAGE, PMIDL_STUB_DESC, unsigned int );
RPCRTAPI void RPC_ENTRY     NdrProxySendReceive( void *, MIDL_STUB_MESSAGE * );
RPCRTAPI HRESULT RPC_ENTRY  NdrStubErrorHandler( DWORD );
RPCRTAPI void RPC_ENTRY     NdrStubForwardingFunction( IRpcStubBuffer *, IRpcChannelBuffer *, PRPC_MESSAGE, DWORD * );
RPCRTAPI void RPC_ENTRY     NdrStubGetBuffer( IRpcStubBuffer *, IRpcChannelBuffer *, PMIDL_STUB_MESSAGE );
RPCRTAPI void RPC_ENTRY     NdrStubInitialize( PRPC_MESSAGE, PMIDL_STUB_MESSAGE, PMIDL_STUB_DESC, IRpcChannelBuffer * );
RPCRTAPI void RPC_ENTRY     NdrStubInitializePartial( PRPC_MESSAGE, PMIDL_STUB_MESSAGE, PMIDL_STUB_DESC, IRpcChannelBuffer *, unsigned long );

/* Method implementation functions in RPCRT4.DLL */
ULONG STDMETHODCALLTYPE     CStdStubBuffer_AddRef( IRpcStubBuffer * );
HRESULT STDMETHODCALLTYPE   CStdStubBuffer_Connect( IRpcStubBuffer *, IUnknown * );
ULONG STDMETHODCALLTYPE     CStdStubBuffer_CountRefs( IRpcStubBuffer * );
HRESULT STDMETHODCALLTYPE   CStdStubBuffer_DebugServerQueryInterface( IRpcStubBuffer *, void ** );
void STDMETHODCALLTYPE      CStdStubBuffer_DebugServerRelease( IRpcStubBuffer *, void * );
void STDMETHODCALLTYPE      CStdStubBuffer_Disconnect( IRpcStubBuffer * );
HRESULT STDMETHODCALLTYPE   CStdStubBuffer_Invoke( IRpcStubBuffer *, RPCOLEMESSAGE *, IRpcChannelBuffer * );
IRpcStubBuffer * STDMETHODCALLTYPE  CStdStubBuffer_IsIIDSupported( IRpcStubBuffer *, REFIID );
HRESULT STDMETHODCALLTYPE   CStdStubBuffer_QueryInterface( IRpcStubBuffer *, REFIID, void ** );
ULONG STDMETHODCALLTYPE     CStdStubBuffer_Release( IRpcStubBuffer * );
ULONG STDMETHODCALLTYPE     NdrCStdStubBuffer2_Release( IRpcStubBuffer *, IPSFactoryBuffer * );
ULONG STDMETHODCALLTYPE     NdrCStdStubBuffer_Release( IRpcStubBuffer *, IPSFactoryBuffer * );

/* Macros to specify proxy/stub DLL method implementation functions */
#define CStdStubBuffer_METHODS \
    CStdStubBuffer_QueryInterface, \
    CStdStubBuffer_AddRef, \
    CStdStubBuffer_Release, \
    CStdStubBuffer_Connect, \
    CStdStubBuffer_Disconnect, \
    CStdStubBuffer_Invoke, \
    CStdStubBuffer_IsIIDSupported, \
    CStdStubBuffer_CountRefs, \
    CStdStubBuffer_DebugServerQueryInterface, \
    CStdStubBuffer_DebugServerRelease
#define CStdAsyncStubBuffer_METHODS             0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define CStdAsyncStubBuffer_DELEGATING_METHODS  0, 0, 0, 0, 0, 0, 0, 0, 0, 0

/* Macro to define routines in proxy/stub DLL */
#define REGISTER_PROXY_DLL_ROUTINES( p1, p2 ) \
    HINSTANCE hProxyDll = 0; \
    BOOL WINAPI DLLMAIN_ENTRY( HINSTANCE fp1, DWORD fp2, LPVOID fp3 ) \
    { \
        UNREFERENCED_PARAMETER( fp3 ); \
        if( fp2 == DLL_PROCESS_ATTACH ) { \
            hProxyDll = fp1; \
            DISABLE_THREAD_LIBRARY_CALLS( fp1 ); \
        } \
        return TRUE; \
    } \
    HRESULT STDAPICALLTYPE DLLREGISTERSERVER_ENTRY() \
    { \
        return NdrDllRegisterProxy( hProxyDll, p1, p2 ); \
    } \
    HRESULT STDAPICALLTYPE DLLUNREGISTERSERVER_ENTRY() \
    { \
        return NdrDllUnregisterProxy( hProxyDll, p1, p2 ); \
    }
#ifdef PROXY_CLSID
    #define CLSID_PSFACTORYBUFFER       extern CLSID PROXY_CLSID;
#else
    #ifdef PROXY_CLSID_IS
        #define CLSID_PSFACTORYBUFFER   const CLSID CLSID_PSFactoryBuffer = PROXY_CLSID_IS;
        #define PROXY_CLSID             CLSID_PSFactoryBuffer
    #else
        #define CLSID_PSFACTORYBUFFER
    #endif
#endif
#ifndef PROXY_CLSID
    #define GET_DLL_CLSID \
        (aProxyFileList[0]->pStubVtblList[0] != 0 ? \
        aProxyFileList[0]->pStubVtblList[0]->header.piid : 0)
#else
    #define GET_DLL_CLSID               &PROXY_CLSID
#endif
#define EXTERN_PROXY_FILE( x )          EXTERN_C const ProxyFileInfo x##_ProxyFileInfo;
#define PROXYFILE_LIST_START            const ProxyFileInfo *aProxyFileList[] = {
#define REFERENCE_PROXY_FILE( x )       &x##_ProxyFileInfo
#define PROXYFILE_LIST_END              0 };
#define DLLDATA_GETPROXYDLLINFO( p1, p2 ) \
    void RPC_ENTRY GetProxyDllInfo( const ProxyFileInfo ***fp1, const CLSID **fp2 ) \
    { \
        *fp1 = p1; \
        *fp2 = p2; \
    }
#define DLLGETCLASSOBJECTROUTINE( p1, p2, p3 ) \
    HRESULT STDAPICALLTYPE DLLGETCLASSOBJECT_ENTRY( REFCLSID fp1, REFIID fp2, \
                                                    void **fp3 ) \
    { \
        return NdrDllGetClassObject( fp1, fp2, fp3, p1, p2, p3 ); \
    }
#define DLLCANUNLOADNOW( x ) \
    HRESULT STDAPICALLTYPE DLLCANUNLOADNOW_ENTRY() \
    { \
        return NdrDllCanUnloadNow( x ); \
    }
#define DLLDUMMYPURECALL \
    void __cdecl _purecall( void ) \
    { \
    }
#define CSTDSTUBBUFFERRELEASE( x ) \
    ULONG STDMETHODCALLTYPE CStdStubBuffer_Release( IRpcStubBuffer *fx ) \
    { \
        return NdrCStdStubBuffer_Release( fx, (IPSFactoryBuffer *)x ); \
    }
#ifdef PROXY_DELEGATION
    #define CSTDSTUBBUFFER2RELEASE( x ) \
        ULONG STDMETHODCALLTYPE CStdStubBuffer2_Release( IRpcStubBuffer *fx ) \
        { \
            return NdrCStdStubBuffer2_Release( fx, (IPSFactoryBuffer *)x ); \
        }
#else
    #define CSTDSTUBBUFFER2RELEASE( x )
#endif
#ifdef REGISTER_PROXY_DLL
    #define DLLREGISTRY_ROUTINES( p1, p2 )  REGISTER_PROXY_DLL_ROUTINES( p1, p2 )
#else
    #define DLLREGISTRY_ROUTINES( p1, p2 )
#endif
#define DLLDATA_ROUTINES( p1, p2 ) \
    CLSID_PSFACTORYBUFFER \
    CStdPSFactoryBuffer gPFactory   = { 0, 0, 0, 0 }; \
    DLLDATA_GETPROXYDLLINFO( p1, p2 ) \
    DLLGETCLASSOBJECTROUTINE( p1, p2, &gPFactory ) \
    DLLCANUNLOADNOW( &gPFactory ) \
    CSTDSTUBBUFFERRELEASE( &gPFactory ) \
    CSTDSTUBBUFFER2RELEASE( &pPFactory ) \
    DLLDUMMYPURECALL \
    DLLREGISTRY_ROUTINES( p1, p2 )
#define DLLDATA_STANDARD_ROUTINES \
    DLLDATA_ROUTINES( (const ProxyFileInfo **)pProxyFileList, &CLSID_PSFactoryBuffer )

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __RPCPROXY_H__ */
