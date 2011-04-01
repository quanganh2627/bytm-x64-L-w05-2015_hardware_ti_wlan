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

/** \file  CmdBldDb.h 
 *  \brief Command builder database
 *
 *  \see   CmdBld.h 
 */

#ifndef CMDBLDDB_H
#define CMDBLDDB_H


#include "TWDriverInternal.h"
#include "public_infoele.h"


/* 
 * Dot11 params
 * ------------
 */
typedef struct
{
    TI_UINT16                  RtsThreshold;
    TI_UINT8                   CtsToSelf;
    TRxTimeOut                 rxTimeOut;
    TI_UINT16                  FragmentThreshold;
    TI_UINT8                   ListenInterval;
    TI_UINT16                  Capabilities;
    TI_UINT32                  MaxTxMsduLifetime;
    TI_UINT32                  MaxRxMsduLifetime;
    TI_UINT8                   calibrationChannel2_4;
    TI_UINT8                   calibrationChannel5_0;
    TI_UINT16                  Aid;
    TI_UINT8                   CurrAntenna;
    TI_UINT8                   TxAntenna;
    TI_UINT8                   RxAntenna;
    TI_UINT8                   Hw_TxAntenna;
    TI_UINT8                   Hw_RxAntenna;
    TI_UINT16                  CwMin;
    TI_UINT8                   RateFallback;
    TI_UINT32                  RxConfigOption;
    TI_UINT32                  RxFilterOption;
    TI_BOOL                    WiFiWmmPS;

    /* Data interrupts pacing */
    TI_UINT16                  TxCompletePacingThreshold;
    TI_UINT16                  TxCompletePacingTimeout; 
    TI_UINT16                  RxIntrPacingThreshold;	 
    TI_UINT16                  RxIntrPacingTimeout;	 
    TI_UINT8                   GenFwCmd[GEN_FW_CMD_SIZE];
    TI_UINT32                  HostIfCfgBitmap;
    /* ARP IP Addr table */
    TI_UINT32                  arp_IP_ver;
    EArpFilterType             arpFilterType;
    TIpAddr                    arp_IP_addr;

    /* Mac addresses filter */
    TI_UINT8                   isMacAddrFilteringnabled;
    TI_UINT8                   numGroupAddrs;
    TMacAddr                   aGroupAddr[MAX_MULTICAST_GROUP_ADDRS];

    TI_UINT32                  FeatureOptions;
    TI_UINT32                  FeatureDataFlowOptions;
    TI_UINT8                   SlotTime;
    TI_UINT8                   preamble;
    TI_UINT8                   RadioBand;
    TI_UINT8                   MacClock;
    TI_UINT8                   ArmClock;
    TI_UINT8                   CurrPowerSaveState;
    ESoftGeminiEnableModes     SoftGeminiEnable;
    TSoftGeminiParams          SoftGeminiParams;
    TFmCoexParams              tFmCoexParams;
    TI_UINT8                   maxSitesFragCollect;
    TI_UINT8                   hwAccessMethod;
    TI_UINT32                  nullTemplateSize;
    TI_UINT32                  disconnTemplateSize;
    TI_UINT32                  beaconTemplateSize;
    TI_UINT32                  probeRequestTemplateSize;
    TI_UINT32                  probeResponseTemplateSize;
    TI_UINT32                  PsPollTemplateSize;
    TI_UINT32                  qosNullDataTemplateSize;
    TI_UINT32                  ArpRspTemplateSize;
    TI_BOOL                    ch14TelecCca;
    TI_UINT8                   PacketDetectionThreshold;
    TI_UINT8                   FcsErrThrsh;
    TI_UINT8                   UseDeviceErrorInterrupt;
    TI_BOOL                    RetryPreemption;
    /* This flag indicate if to discards all broadcast frames */
    TI_BOOL                    RxDisableBroadcast; 
    /* Indicate if the station is joined */
    TI_BOOL                    bJoin;              
    /* Indicate if the station is connected */
    TI_BOOL                    bStaConnected;              
    TI_UINT8                   AntDiversity;
    /* Parameters for roaming triggers configuration */
    TRroamingTriggerParams     roamTriggers;
    /* Power control param */
    EPowerPolicy               minPowerLevel;
    TBcnBrcOptions             BcnBrcOptions;
    TBeaconFilterIeTable       beaconFilterIETable;
    TBeaconFilterInitParams    beaconFilterParams;

    TI_BOOL                    bApBeaconFilterEnabled; /* if true, fw won't pass beacons to driver */

    /*Beacon Early Termination (Bet)*/
    TI_UINT8                   BetEnable;
    TI_UINT8                   MaximumConsecutiveET;
    TI_UINT8                   ConsecutivePsPollDeliveryFailureThreshold;

    /* RSSI/SNR triggers */
    RssiSnrTriggerCfg_t        tRssiSnrTrigger[NUM_OF_RSSI_SNR_TRIGGERS];
    RssiSnrAverageWeights_t    tRssiSnrWeights;

    TI_UINT32                  uSlicedScanTimeOut;

    /* HT capabilities */
    TTwdHtCapabilities         tTwdHtCapabilities;

    /* PM Config params */
    TI_UINT32                  uHostClkSettlingTime;	 
    TI_UINT8                   uHostFastWakeupSupport;

    TI_UINT8                   TxPowerDbm;

    /* CoexActivity Table */
    THalCoexActivityTable      tWlanParamsCoexActivityTable;

    /* DCO Itrim params */
    TI_BOOL                    dcoItrimEnabled;
    TI_UINT32                  dcoItrimModerationTimeoutUsec;
#ifdef TNETW1283
    /* TCXO parameters */
    TI_UINT8                   TcxoRefClk;
    TI_UINT8                   TcxoSettlingTime;
    TI_UINT8                   TcxoValidOnWakeup;
    TI_UINT8                   TcxoLdoVoltage; 
    TI_UINT8                   NewPllAlgo; 
#endif
    
} TWlanParams;


/* 
 * BssInfo params
 * --------------
 */
typedef struct
{
    TI_UINT8                   ReqBssType;
    TI_UINT8                   BssType;
    TI_UINT16                  BeaconInterval;
    TI_UINT8                   DtimInterval; 
    TI_UINT8                   RadioChannel;
    TI_UINT8                   BssId[MAC_ADDR_LEN];
    TSsid                      tSsid;
    /* Policy for recovery */  
    TTxRatePolicy              TxRateClassParams; 
    TI_UINT32                  BasicRateSet;   
    /* The ctrl field in the Join-Command (see StartJoinRequest_t) */
    TI_UINT8                   Ctrl;                                 
    /* ATIM window of IBSS*/
    /* Note that when ATIM window is zero the*/
    /* initiated IBSS does not support powersave*/
    TI_UINT16                  ATimWindow;     
    /* Specifies the PLCP preamble type used*/
    /* 0 for long preamble*/
    /* 1 for short preamble*/
    TI_UINT8                   DefaultPreamble;

    /* 
     * HT setting 
     */
    /* capabilities */
    TI_BOOL   bHtCap;
    TI_UINT32 uHtCapabilites;
    TMacAddr  tMacAddress;
    TI_UINT8  uAmpduMaxLeng;
    TI_UINT8  uAmpduMinSpac;
    /* Information */
    TI_BOOL   bHtInf;
    TI_UINT8  uRifsMode;     
    TI_UINT8  uHtProtection;
    TI_UINT8  uGfProtection;     
    TI_UINT8  uHtTxBurstLimit;
    TI_UINT8  uDualCtsProtection;
    /* BA session */
    TI_BOOL                               bBaInitiator[MAX_NUM_OF_802_1d_TAGS];
    TAxcBaSessionInitiatorResponderPolicy tBaSessionInitiatorPolicy[MAX_NUM_OF_802_1d_TAGS]; 
    TI_BOOL                               bBaResponder[MAX_NUM_OF_802_1d_TAGS];
    TAxcBaSessionInitiatorResponderPolicy tBaSessionResponderPolicy[MAX_NUM_OF_802_1d_TAGS]; 

} TBssInfoParams;


/* 
 * General counters
 * ----------------
 */
typedef struct
{
    TI_UINT32                  FcsErrCnt;

} TGenCounters;


/*
 * queuesParam_T - Queue params for Quality Of Service
 * ------------------------------------------
 */
typedef struct
{
    TQueueTrafficParams        queues[MAX_NUM_OF_AC];
    TI_BOOL                    isQueueConfigured[MAX_NUM_OF_AC];

} TQueuesParams;


typedef struct 
{
    TAcQosParams               ac[MAX_NUM_OF_AC];
    TI_BOOL                    isAcConfigured[MAX_NUM_OF_AC];
	TI_BOOL					   isBurstModeEnabled;
} TAcConfParams;


typedef struct 
{
    TPsRxStreaming             tid[MAX_NUM_OF_802_1d_TAGS];

} TPsRxStreamingParams;


/* 
 * Templates params
 * ----------------
 */
typedef struct
{
    TTemplateParams            Beacon;
    TTemplateParams            ProbeReq24;
    TTemplateParams            ProbeReq50;
    TTemplateParams            ProbeResp;
    TTemplateParams            NullData;
    TTemplateParams            PsPoll;
    TTemplateParams            QosNullData;
    TTemplateParams            KeepAlive[ KLV_MAX_TMPL_NUM ];
    TTemplateParams            Disconn;
    TTemplateParams            ArpRsp;
    TTemplateParams            ApBeacon;
    TTemplateParams            ApProbeResponse;
    TTemplateParams            ApDeauthSta;

} TTemplateListParams;

typedef struct
{
    TI_UINT8                   enaDisFlag;
    TKeepAliveParams           keepAliveParams[ KLV_MAX_TMPL_NUM ];
} TKeepAliveList;

/* Security keys structure for reconfigure phase */
typedef struct
{
    TI_BOOL                    bReconfHwEncEnable;     
    TI_BOOL                    bHwEncDecrEnableValid; 
    TI_UINT8                   uReconfDefaultKeyId;   
    TI_BOOL                    bDefaultKeyIdValid;  
    TSecurityKeys*             pReconfKeys; 
                                   
} TSecurReconf;


/* Rx Data Filters */
typedef struct
{
    TI_UINT8                   uIndex;
    TI_UINT8                   uCommand; 
    filter_e                   eAction;
    TI_UINT8                   uNumFieldPatterns;
    TI_UINT8                   uLenFieldPatterns;
    TI_UINT8                   aFieldPattern[MAX_DATA_FILTER_SIZE];
                                   
} TRxDataFilter;

typedef struct
{
    TI_BOOL                    bEnabled;
    filter_e                   eDefaultAction;
    TRxDataFilter              aRxDataFilter[MAX_DATA_FILTERS];
                                   
} TRxDataFiltersTable;

typedef struct
{
 ACXSmartReflexConfigParams_t     tSmartReflexParams;       
 ACXSmartReflexDebugParams_t      tSmartReflexDebugParams;  
 ACXSmartReflexState_t            tSmartReflexState;        

}TSmartReflexParams ;

typedef struct
{  
	RateMangeParams_t rateMngParams;

} TRateMngParams;



/*
 * ----------------------------------------------------------------
 *                  MAIN PARAMETERS STRUCTURE
 * ----------------------------------------------------------------
 */
typedef struct 
{
    TDmaParams                 dma;                 /* Rx/Tx queue parameters   */
    TQueuesParams              queues;              /* Queues params for QOS    */
    TAcConfParams              ac;                  /* AC params for QoS        */
    TPsRxStreamingParams       psStream;            /* PS-Rx-Streaming params   */
    TWlanParams                wlan;                /* Wlan parameters          */
    TBssInfoParams             bss;                 /* Bss information          */
    TFwInfo                    hw;                  /* HW eeprom & versions info*/
    TGenCounters               counters;            /* General counters         */
    TTemplateListParams        templateList;        /* Templates for recovery   */
    TKeepAliveList             klvList;             /* Keep-Alive paramters     */  
    TSecurReconf               keys;                /* Security keys            */
    TRxDataFiltersTable        rxDataFilters;       /* Rx data filters          */
    IniFileGeneralParam        tPlatformGenParams;  /* platfrom gen params from public_radio.h  */   
    IniFileRadioParam          tRadioIniParams[NUMBER_OF_FEM_TYPES_E];     /* Radio ini params from public_radio.h     */
    IniFileExtendedRadioParam  tExtRadioIniParams[NUMBER_OF_FEM_TYPES_E];  /* Extended Radio ini params from public_radio.h     */
	TSmartReflexParams         tSmartReflex;
	TRateMngParams		       tRateMngParams;      /* rate management params */
} TCmdBldDb;

#endif


