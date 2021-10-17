/*
 *  qos.h       Quality of Service definitions
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

#ifndef __QOS_H_
#define __QOS_H_

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file;
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Service type data types */
typedef ULONG   SERVICETYPE;

/* Service types */
#define SERVICETYPE_NOTRAFFIC           0x00000000L
#define SERVICETYPE_BESTEFFORT          0x00000001L
#define SERVICETYPE_CONTROLLEDLOAD      0x00000002L
#define SERVICETYPE_GUARANTEED          0x00000003L
#define SERVICETYPE_NETWORK_UNAVAILABLE 0x00000004L
#define SERVICETYPE_GENERAL_INFORMATION 0x00000005L
#define SERVICETYPE_NOCHANGE            0x00000006L
#define SERVICETYPE_NONCONFORMING       0x00000009L
#define SERVICETYPE_NETWORK_CONTROL     0x0000000AL
#define SERVICETYPE_QUALITATIVE         0x0000000DL

/* Service type flags */
#define SERVICE_BESTEFFORT          0x80010000L
#define SERVICE_CONTROLLEDLOAD      0x80020000L
#define SERVICE_GUARANTEED          0x80040000L
#define SERVICE_QUALITATIVE         0x80200000L
#define SERVICE_NO_TRAFFIC_CONTROL  0x81000000L
#define SERVICE_NO_QOS_SIGNALING    0x40000000L

/* Flow specification special value */
#define QOS_NOT_SPECIFIED   0xFFFFFFFFL

/* Peak bandwidth special value */
#define POSITIVE_INFINITY_RATE  0xFFFFFFFEL

/* Quality of Service object identifiers */
#define QOS_GENERAL_ID_BASE     2000
#define QOS_OBJECT_END_OF_LIST  (0x00000001 + QOS_GENERAL_ID_BASE)
#define QOS_OBJECT_SD_MODE      (0x00000002 + QOS_GENERAL_ID_BASE)
#define QOS_OBJECT_SHAPING_RATE (0x00000003 + QOS_GENERAL_ID_BASE)
#define QOS_OBJECT_DESTRATE     (0x00000004 + QOS_GENERAL_ID_BASE)

/* Shape discarding mode values */
#define TC_NONCONF_BORROW       0L
#define TC_NONCONF_SHAPE        1L
#define TC_NONCONF_DISCARD      2L
#define TC_NONCONF_BORROW_PLUS  3L

/* Flow specification */
typedef struct _flowspec {
    ULONG       TokenRate;
    ULONG       TokenBucketSize;
    ULONG       PeakBandwidth;
    ULONG       Latency;
    ULONG       DelayVariation;
    SERVICETYPE ServiceType;
    ULONG       MaxSduSize;
    ULONG       MinimumPolicedSize;
} FLOWSPEC;
typedef FLOWSPEC    *PFLOWSPEC;
typedef FLOWSPEC    *LPFLOWSPEC;

/* Quality of Service object header */
typedef struct {
    ULONG   ObjectType;
    ULONG   ObjectLength;
} QOS_OBJECT_HDR;
typedef QOS_OBJECT_HDR  *LPQOS_OBJECT_HDR;

/* Quality of Service shape discard mode */
typedef struct _QOS_SD_MODE {
    QOS_OBJECT_HDR  ObjectHdr;
    ULONG           ShapeDiscardMode;
} QOS_SD_MODE;
typedef QOS_SD_MODE *LPQOS_SD_MODE;

/* Quality of Service shaping rate */
typedef struct _QOS_SHAPING_RATE {
    QOS_OBJECT_HDR  ObjectHdr;
    ULONG           ShapingRate;
} QOS_SHAPING_RATE;
typedef QOS_SHAPING_RATE    *LPQOS_SHAPING_RATE;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __QOS_H_ */
