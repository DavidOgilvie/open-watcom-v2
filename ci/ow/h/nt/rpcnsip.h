/*
 *  rpcnsip.h   RPC Name Service Independent private functions
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

#ifndef __RPCNSIP_H__
#define __RPCNSIP_H__

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file;
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* RPC import context */
typedef struct {
    RPC_NS_HANDLE       LookupContext;
    RPC_BINDING_HANDLE  ProposedHandle;
    RPC_BINDING_VECTOR  *Bindings;
} RPC_IMPORT_CONTEXT_P;
typedef RPC_IMPORT_CONTEXT_P    *PRPC_IMPORT_CONTEXT_P;

/* Functions in RPCNS4.DLL */
RPCNSAPI RPC_STATUS RPC_ENTRY   I_RpcNsGetBuffer( PRPC_MESSAGE );
RPCNSAPI void RPC_ENTRY         I_RpcNsRaiseException( PRPC_MESSAGE, RPC_STATUS );
RPCNSAPI RPC_STATUS RPC_ENTRY   I_RpcNsSendReceive( PRPC_MESSAGE, RPC_BINDING_VECTOR * );
RPCNSAPI RPC_STATUS RPC_ENTRY   I_RpcReBindBuffer( PRPC_MESSAGE );

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __RPCNSIP_H__ */
