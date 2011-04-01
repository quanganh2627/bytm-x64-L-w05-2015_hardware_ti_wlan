/***************************************************************************
**+----------------------------------------------------------------------+**
**|                                ****                                  |**
**|                                ****                                  |**
**|                                ******o***                            |**
**|                          ********_///_****                           |**
**|                           ***** /_//_/ ****                          |**
**|                            ** ** (__/ ****                           |**
**|                                *********                             |**
**|                                 ****                                 |**
**|                                  ***                                 |**
**|                                                                      |**
**|     Copyright (c) 1998 - 2009 Texas Instruments Incorporated         |**
**|                        ALL RIGHTS RESERVED                           |**
**|                                                                      |**
**| Permission is hereby granted to licensees of Texas Instruments       |**
**| Incorporated (TI) products to use this computer program for the sole |**
**| purpose of implementing a licensee product based on TI products.     |**
**| No other rights to reproduce, use, or disseminate this computer      |**
**| program, whether in part or in whole, are granted.                   |**
**|                                                                      |**
**| TI makes no representation or warranties with respect to the         |**
**| performance of this computer program, and specifically disclaims     |**
**| any responsibility for any damages, special or consequential,        |**
**| connected with the use of this program.                              |**
**|                                                                      |**
**+----------------------------------------------------------------------+**
***************************************************************************/
 
/***************************************************************************/
/*																		   */
/*	  MODULE:	TxDataQueue.h										       */
/*    PURPOSE:	Tx Data Queue module Header file						   */
/*																		   */
/***************************************************************************/
#ifndef _TX_DATA_QUEUE_H_
#define _TX_DATA_QUEUE_H_


#include "TWDriver.h"
#include "DataCtrl_Api.h"
#include "wlanLinks.h"

#define TX_SEND_PACE_TIMEOUT_MSEC   1

/* Max number of packets in each queue */
#define DATA_QUEUE_DEPTH_BE  60
#define DATA_QUEUE_DEPTH_BK  10
#define DATA_QUEUE_DEPTH_VI  32
#define DATA_QUEUE_DEPTH_VO  10
#define DATA_QUEUE_DEPTH_TOTAL  (DATA_QUEUE_DEPTH_BE + DATA_QUEUE_DEPTH_BK + DATA_QUEUE_DEPTH_VI + DATA_QUEUE_DEPTH_VO)

/* Verify that there are enough TxCtrlBlks for all users that are queueing packets (driver + FW) */
#if ((DATA_QUEUE_DEPTH_TOTAL + (MGMT_QUEUES_DEPTH * 2) + NUM_TX_DESCRIPTORS) > (CTRL_BLK_ENTRIES_NUM - 2))
    #error  Not enough TxCtrlBlks for all users !!
#endif

/* Tx packets handling statistics */
typedef struct
{
	TI_UINT32 uEnqueuePacket;
	TI_UINT32 uDequeuePacket;
	TI_UINT32 uRequeuePacket;
	TI_UINT32 uXmittedPacket;
	TI_UINT32 uDroppedPacket;
} TTxDataQueueDebugCnt;

/* The LinkQ object. */
typedef struct 
{
	EWlanLinkType        eType;
	TI_BOOL              bBusy;                                /* Link is busy. */
	TI_BOOL              bEnabled;                             /* Link is enabled */
    TI_BOOL              bEncrypt;                             /* encrypt data packet */
	TI_HANDLE            aQueues[MAX_NUM_OF_AC];               /* The Tx aQueues handles */
	TTxDataQueueDebugCnt aQueueCounters[MAX_NUM_OF_AC];        /* Save Tx statistics per Tx-queue. */
	TI_BOOL	             aNetStackQueueStopped[MAX_NUM_OF_AC]; /* indicate if the current queue was full and caused Tx network stack stop*/
    TI_UINT8             cEncryptSize;
} TDataLinkQ;

/* The DataResources object */
typedef struct 
{
	/* Resources per Ac */
	TI_UINT32 uPktInUse_PerAc[MAX_NUM_OF_AC];           /* Packet counter per AC */
	TI_UINT32 uMinGuarantee_PerAc[MAX_NUM_OF_AC];       /* Configurable min guarantee packets per AC */
	TI_UINT32 uEffectiveTotal_Ac;                       /* Effective total packets for AC check */
	TI_UINT32 uEffectiveTotal_Ac_Min;                   /* Just for sunity check */
	/* Resources per Link */
	TI_UINT32 uPktInUse_PerLink[WLANLINKS_MAX_LINKS];   /* Packet counter per AC */
	TI_UINT32 uMinGuarantee_PerLink;                    /* Configurable min guarantee packets per AC */
	TI_UINT32 uEffectiveTotal_Link;                     /* Effective total packets for LINK check */
	TI_UINT32 uEffectiveTotal_Link_Min;                   /* Just for sunity check */
	/* MaxTotal packets */
	TI_UINT32 uMaxTotal;        
} TDataResources;

/* The LinkMac object. */
#define LINK_MAC_TABLE_SIZE  WLANLINKS_MAX_LINKS
typedef struct 
{
	TI_BOOL              uValid;
	TMacAddr             tMacAddr;
} TLinkMac;

/* The module's object */
typedef struct 
{
	TI_HANDLE            hContext;
	TI_HANDLE            hTxCtrl;
	TI_HANDLE            hOs;
	TI_HANDLE            hReport;
	TI_HANDLE            hTxMgmtQ;
	TI_HANDLE            hTWD;
			             
	TClsfrParams		 tClsfrParams;  /* The classifier sub-module parameters */

	TI_BOOL              bDataPortEnable; /* Data port open or not */
	TI_UINT32            uContextId;  /* ID allocated to this module on registration to context module */
	TI_HANDLE            hTxSendPaceTimer; /* If queued packets number doesn't reach threshold within timeout, Tx handling is started */  
						   
	/* Tx AC Info */	    	
	TI_UINT32            uNumQueues; /* Indicates the number of allocated aQueues */
	TI_UINT32            aQueueMaxSize[MAX_NUM_OF_AC]; /* indicates the max size of each Data queue */
	TI_UINT32            aTxSendPaceThresh[MAX_NUM_OF_AC]; /* Number of packets to queue before scheduling Tx handling */
	TI_UINT32            uNextQueId; /* the next queue should be processed by the scheduler */				
	TI_BOOL				 aNetStackQueueStopped[MAX_NUM_OF_AC];/*indicate if the current queue was full and caused Tx network stack stop*/
	TI_BOOL	             aQueueBusy[MAX_NUM_OF_AC];            /* per queue busy indication */
	TI_BOOL				 bStopNetStackTx;/*Flag to enable/disable Tx stop*/

	/* Tx Link Queues */	    	
	TDataLinkQ           aDataLinkQ[WLANLINKS_MAX_LINKS];   /* Link queues handles. */
	TI_UINT32            uBcastHlid;              /* Generic link id */
	TI_UINT32            uNextHlid;               /* Next HLID should be processed by scheduler */

	TLinkMac             aLinkMac[WLANLINKS_MAX_LINKS];     /* Link queues handles. */

	/* Data resources */	    	
	TDataResources       tDataRsrc; /* Resources object DB */

	/* Counters */
	TI_UINT32			 uClsfrMismatchCount;
	TI_UINT32			 uTxSendPaceTimeoutsCount;
	TI_UINT32			 uLinkNotFoundCount;
	TI_UINT32			 uNoResourcesCount;

} TTxDataQ;


/* TIDs Mapping to Queues */
static const TI_UINT32 aTidToQueueTable[MAX_NUM_OF_802_1d_TAGS] = {0, 1, 1, 0, 2, 2, 3, 3};

#endif /* _TX_DATA_QUEUE_H_ */