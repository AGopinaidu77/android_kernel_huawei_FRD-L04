

/*****************************************************************************
  1 头文件包含
*****************************************************************************/
#include "NasMsccSndXsd.h"
#include "NasMntn.h"
#include "xsd_mscc_pif.h"
#include "MmaMsccInterface.h"
#include "NasMsccComFunc.h"

#ifdef  __cplusplus
#if  __cplusplus
extern "C"{
#endif
#endif

#define THIS_FILE_ID                    PS_FILE_ID_NAS_MSCC_SND_XSD_C

#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)

/*****************************************************************************
  2 全局变量定义
*****************************************************************************/

/*****************************************************************************
  3 函数定义
*****************************************************************************/


VOS_VOID NAS_MSCC_SndXsdStartReq(
    NAS_MSCC_PIF_CARD_STATUS_ENUM_UINT8                     enCsimStatus,
    NAS_MSCC_PIF_RAT_PRIO_STRU                             *pstRatPrio
)
{
    MSCC_XSD_START_REQ_STRU            *pstMsg = VOS_NULL_PTR;
    VOS_UINT32                          i;

    /* Allocate the memory for Message */
    pstMsg = (MSCC_XSD_START_REQ_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(UEPS_PID_MSCC,
                           sizeof(MSCC_XSD_START_REQ_STRU));

    if (VOS_NULL_PTR == pstMsg)
    {
        NAS_ERROR_LOG(UEPS_PID_MSCC, "NAS_MSCC_SndXsdStartReq:ERROR: Memory Alloc Error for pMsg");

        return;
    }

    PS_MEM_SET((VOS_INT8*)pstMsg + VOS_MSG_HEAD_LENGTH, 0,
                     sizeof(MSCC_XSD_START_REQ_STRU) - VOS_MSG_HEAD_LENGTH);

    pstMsg->stMsgHeader.ulReceiverCpuId  = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulReceiverPid    = UEPS_PID_XSD;
    pstMsg->stMsgHeader.ulSenderCpuId    = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulSenderPid      = UEPS_PID_MSCC;
    pstMsg->stMsgHeader.ulLength         = sizeof(MSCC_XSD_START_REQ_STRU) - VOS_MSG_HEAD_LENGTH;
    pstMsg->stMsgHeader.ulMsgName        = ID_MSCC_XSD_START_REQ;
    pstMsg->enCardStatus                 = enCsimStatus;

    pstMsg->enModemId                    = VOS_GetModemIDFromPid(UEPS_PID_MSCC);
    pstMsg->ucSuppRatNum                 = pstRatPrio->ucRatNum;

    for (i = 0; i < NAS_MSCC_PIF_MAX_RAT_NUM; i++)
    {
        pstMsg->aenRatMode[i] = NAS_MSCC_TransferMsccToVosRat(pstRatPrio->aucRatPrio[i]);
    }


    pstMsg->ucIsCardChanged             = NAS_MSCC_GetIsCardChangedFlg();

    NAS_MSCC_LogMsgInfo((MSG_HEADER_STRU*)pstMsg);

    /* send the start request to XSD */
    PS_SEND_MSG(UEPS_PID_MSCC, pstMsg);

    NAS_TRACE_HIGH("NAS_MSCC_SndXsdStartReq successfully...");

    return;
}



VOS_VOID NAS_MSCC_SndXsdPowerOffReq(
    NAS_MSCC_PIF_POWER_OFF_CAUSE_ENUM_UINT32 enCause
)
{
    MSCC_XSD_POWER_OFF_REQ_STRU        *pstMsg = VOS_NULL_PTR;

    /* Allocate memory to send message  */
    pstMsg = (MSCC_XSD_POWER_OFF_REQ_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(UEPS_PID_MSCC,
                           sizeof(MSCC_XSD_POWER_OFF_REQ_STRU));

    if (VOS_NULL_PTR == pstMsg)
    {
        NAS_ERROR_LOG(UEPS_PID_MSCC, "NAS_MSCC_SndXsdPowerOffReq:ERROR: Memory Alloc Error for pMsg");

        return;
    }

    PS_MEM_SET((VOS_INT8*)pstMsg + VOS_MSG_HEAD_LENGTH, 0,
                     sizeof(MSCC_XSD_POWER_OFF_REQ_STRU) - VOS_MSG_HEAD_LENGTH);

    pstMsg->MsgHeader.ulReceiverCpuId  = VOS_LOCAL_CPUID;
    pstMsg->MsgHeader.ulReceiverPid    = UEPS_PID_XSD;
    pstMsg->MsgHeader.ulSenderCpuId    = VOS_LOCAL_CPUID;
    pstMsg->MsgHeader.ulSenderPid      = UEPS_PID_MSCC;
    pstMsg->MsgHeader.ulLength         = sizeof(MSCC_XSD_POWER_OFF_REQ_STRU) - VOS_MSG_HEAD_LENGTH;
    pstMsg->MsgHeader.ulMsgName        = ID_MSCC_XSD_POWER_OFF_REQ;
    pstMsg->enCause                    = enCause;

    NAS_MSCC_LogMsgInfo((MSG_HEADER_STRU*)pstMsg);

    /* Send Message */
    PS_SEND_MSG(UEPS_PID_MSCC, pstMsg);

    NAS_TRACE_HIGH("Send xsd Cdma Power Off Msg!");

    return;
}





VOS_VOID NAS_MSCC_SndXsdCdmaMoCallStartNtf(
    MMA_MSCC_CDMA_MO_CALL_START_NTF_STRU         *pstCdmaMoCallStartNtf
)
{
    MSCC_XSD_MO_CALL_START_NTF_STRU    *pstMsg = VOS_NULL_PTR;

    /* Allocate memory to send message  */
    pstMsg = (MSCC_XSD_MO_CALL_START_NTF_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(WUEPS_PID_MMA,
                           sizeof(MSCC_XSD_MO_CALL_START_NTF_STRU));

    if (VOS_NULL_PTR == pstMsg)
    {
        NAS_ERROR_LOG(UEPS_PID_MSCC, "NAS_MSCC_SndXsdCdmaMoCallStartNtf:ERROR: Memory Alloc Error for pMsg");

        return;
    }

    PS_MEM_SET((VOS_INT8*)pstMsg + VOS_MSG_HEAD_LENGTH, 0,
                     sizeof(MSCC_XSD_MO_CALL_START_NTF_STRU) - VOS_MSG_HEAD_LENGTH);

    pstMsg->stMsgHeader.ulReceiverCpuId  = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulReceiverPid    = UEPS_PID_XSD;
    pstMsg->stMsgHeader.ulSenderCpuId    = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulSenderPid      = UEPS_PID_MSCC;
    pstMsg->stMsgHeader.ulLength         = sizeof(MSCC_XSD_MO_CALL_START_NTF_STRU) - VOS_MSG_HEAD_LENGTH;
    pstMsg->stMsgHeader.ulMsgName        = ID_MSCC_XSD_MO_CALL_START_NTF;
    pstMsg->enCallType                   = pstCdmaMoCallStartNtf->enCallType;

    NAS_MSCC_LogMsgInfo((MSG_HEADER_STRU*)pstMsg);

    /* Send Message */
    PS_SEND_MSG(UEPS_PID_MSCC, pstMsg);


}



VOS_VOID NAS_MSCC_SndXsdCdmaMoCallRedialSysAcqNtf(
    MMA_MSCC_CDMA_MO_CALL_REDIAL_SYS_ACQ_NTF_STRU         *pstCdmaMoCallRedialSysAcqNtf
)
{
    MSCC_XSD_CALL_REDIAL_SYSTEM_ACQUIRE_NTF_STRU    *pstMsg = VOS_NULL_PTR;

    /* Allocate memory to send message  */
    pstMsg = (MSCC_XSD_CALL_REDIAL_SYSTEM_ACQUIRE_NTF_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(WUEPS_PID_MMA,
                           sizeof(MSCC_XSD_CALL_REDIAL_SYSTEM_ACQUIRE_NTF_STRU));

    if (VOS_NULL_PTR == pstMsg)
    {
        NAS_ERROR_LOG(UEPS_PID_MSCC, "NAS_MSCC_SndXsdCdmaMoCallRedialSysAcqNtf:ERROR: Memory Alloc Error for pMsg");

        return;
    }

    PS_MEM_SET((VOS_INT8*)pstMsg + VOS_MSG_HEAD_LENGTH, 0,
                     sizeof(MSCC_XSD_CALL_REDIAL_SYSTEM_ACQUIRE_NTF_STRU) - VOS_MSG_HEAD_LENGTH);

    pstMsg->stMsgHeader.ulReceiverCpuId  = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulReceiverPid    = UEPS_PID_XSD;
    pstMsg->stMsgHeader.ulSenderCpuId    = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulSenderPid      = UEPS_PID_MSCC;
    pstMsg->stMsgHeader.ulLength         = sizeof(MSCC_XSD_CALL_REDIAL_SYSTEM_ACQUIRE_NTF_STRU) - VOS_MSG_HEAD_LENGTH;
    pstMsg->stMsgHeader.ulMsgName        = ID_MSCC_XSD_CALL_REDIAL_SYSTEM_ACQUIRE_NTF;
    pstMsg->enCallType                   = pstCdmaMoCallRedialSysAcqNtf->enCallType;
    pstMsg->enCause                      = pstCdmaMoCallRedialSysAcqNtf->enCause;

    NAS_MSCC_LogMsgInfo((MSG_HEADER_STRU*)pstMsg);

    /* Send Message */
    PS_SEND_MSG(UEPS_PID_MSCC, pstMsg);

}




VOS_VOID NAS_MSCC_SndXsdCdmaMoCallSuccessNtf(
    MMA_MSCC_CDMA_MO_CALL_SUCCESS_NTF_STRU         *pstCdmaMoCallSuccessNtf
)
{
    MSCC_XSD_MO_CALL_SUCCESS_NTF_STRU  *pstMsg = VOS_NULL_PTR;

    /* Allocate memory to send message  */
    pstMsg = (MSCC_XSD_MO_CALL_SUCCESS_NTF_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(WUEPS_PID_MMA,
                           sizeof(MSCC_XSD_MO_CALL_SUCCESS_NTF_STRU));

    if (VOS_NULL_PTR == pstMsg)
    {
        NAS_ERROR_LOG(UEPS_PID_MSCC, "NAS_MSCC_SndXsdCdmaMoCallSuccessNtf:ERROR: Memory Alloc Error for pMsg");

        return;
    }

    PS_MEM_SET((VOS_INT8*)pstMsg + VOS_MSG_HEAD_LENGTH, 0,
                     sizeof(MSCC_XSD_MO_CALL_SUCCESS_NTF_STRU) - VOS_MSG_HEAD_LENGTH);

    pstMsg->stMsgHeader.ulReceiverCpuId  = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulReceiverPid    = UEPS_PID_XSD;
    pstMsg->stMsgHeader.ulSenderCpuId    = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulSenderPid      = UEPS_PID_MSCC;
    pstMsg->stMsgHeader.ulLength         = sizeof(MSCC_XSD_MO_CALL_SUCCESS_NTF_STRU) - VOS_MSG_HEAD_LENGTH;
    pstMsg->stMsgHeader.ulMsgName        = ID_MSCC_XSD_MO_CALL_SUCCESS_NTF;
    pstMsg->enCallType                   = pstCdmaMoCallSuccessNtf->enCallType;

    NAS_MSCC_LogMsgInfo((MSG_HEADER_STRU*)pstMsg);

    /* Send Message */
    PS_SEND_MSG(UEPS_PID_MSCC, pstMsg);

}



VOS_VOID NAS_MSCC_SndXsdCdmaMoCallEndNtf(
    MMA_MSCC_CDMA_MO_CALL_END_NTF_STRU *pstCdmaMoCallEndNtf
)
{
    MSCC_XSD_1X_MO_CALL_END_NTF_STRU                       *pstMsg = VOS_NULL_PTR;

    /* Allocate memory to send message  */
    pstMsg = (MSCC_XSD_1X_MO_CALL_END_NTF_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(WUEPS_PID_MMA,
                           sizeof(MSCC_XSD_1X_MO_CALL_END_NTF_STRU));

    if (VOS_NULL_PTR == pstMsg)
    {
        NAS_ERROR_LOG(UEPS_PID_MSCC, "NAS_MSCC_SndXsdCdmaMoCallEndNtf:ERROR: Memory Alloc Error for pMsg");

        return;
    }

    PS_MEM_SET((VOS_INT8*)pstMsg + VOS_MSG_HEAD_LENGTH, 0,
                     sizeof(MSCC_XSD_1X_MO_CALL_END_NTF_STRU) - VOS_MSG_HEAD_LENGTH);

    pstMsg->stMsgHeader.ulReceiverCpuId  = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulReceiverPid    = UEPS_PID_XSD;
    pstMsg->stMsgHeader.ulSenderCpuId    = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulSenderPid      = UEPS_PID_MSCC;
    pstMsg->stMsgHeader.ulLength         = sizeof(MSCC_XSD_1X_MO_CALL_END_NTF_STRU) - VOS_MSG_HEAD_LENGTH;
    pstMsg->stMsgHeader.ulMsgName        = ID_MSCC_XSD_MO_CALL_END_NTF;
    pstMsg->enCallType                   = pstCdmaMoCallEndNtf->enCallType;

    NAS_MSCC_LogMsgInfo((MSG_HEADER_STRU*)pstMsg);

    /* Send Message */
    PS_SEND_MSG(UEPS_PID_MSCC, pstMsg);

}



VOS_VOID NAS_MSCC_SndXsdCfreqLockNtf(
    MMA_MSCC_CFREQ_LOCK_NTF_STRU       *pstCfreqLockNtf,
    VOS_UINT32                          ulIsSupport1x
)
{
    MSCC_XSD_CFREQ_LOCK_NTF_STRU       *pstMsg = VOS_NULL_PTR;

    /* Allocate memory to send message  */
    pstMsg = (MSCC_XSD_CFREQ_LOCK_NTF_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(WUEPS_PID_MMA,
                           sizeof(MSCC_XSD_CFREQ_LOCK_NTF_STRU));

    if (VOS_NULL_PTR == pstMsg)
    {
        NAS_ERROR_LOG(UEPS_PID_MSCC, "NAS_MSCC_SndXsdCfreqLockNtf:ERROR: Memory Alloc Error for pMsg");

        return;
    }

    PS_MEM_SET((VOS_INT8*)pstMsg + VOS_MSG_HEAD_LENGTH, 0,
                     sizeof(MSCC_XSD_CFREQ_LOCK_NTF_STRU) - VOS_MSG_HEAD_LENGTH);

    pstMsg->stMsgHeader.ulReceiverCpuId  = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulReceiverPid    = UEPS_PID_XSD;
    pstMsg->stMsgHeader.ulSenderCpuId    = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulSenderPid      = UEPS_PID_MSCC;
    pstMsg->stMsgHeader.ulLength         = sizeof(MSCC_XSD_CFREQ_LOCK_NTF_STRU) - VOS_MSG_HEAD_LENGTH;
    pstMsg->stMsgHeader.ulMsgName        = ID_MSCC_XSD_CFREQLOCK_NTF;

    pstMsg->ulIsSupport1x   = ulIsSupport1x;
    pstMsg->enFreqLockMode  = pstCfreqLockNtf->enFreqLockMode;
    pstMsg->usCdmaBandClass = pstCfreqLockNtf->usCdmaBandClass;
    pstMsg->usSid           = pstCfreqLockNtf->usSid;
    pstMsg->usNid           = pstCfreqLockNtf->usNid;
    pstMsg->usCdmaFreq      = pstCfreqLockNtf->usCdmaFreq;
    pstMsg->usCdmaPn        = pstCfreqLockNtf->usCdmaPn;

    NAS_MSCC_LogMsgInfo((MSG_HEADER_STRU*)pstMsg);

    /* Send Message */
    PS_SEND_MSG(UEPS_PID_MSCC, pstMsg);

}



VOS_VOID NAS_MSCC_SndXsdCdmacsqSetReq(
    MMA_MSCC_CDMACSQ_SET_REQ_STRU       *pstCdmacsqSetReq
)
{
    MSCC_XSD_CDMACSQ_SET_REQ_STRU      *pstMsg = VOS_NULL_PTR;

    /* Allocate memory to send message  */
    pstMsg = (MSCC_XSD_CDMACSQ_SET_REQ_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(WUEPS_PID_MMA,
                           sizeof(MSCC_XSD_CDMACSQ_SET_REQ_STRU));

    if (VOS_NULL_PTR == pstMsg)
    {
        NAS_ERROR_LOG(UEPS_PID_MSCC, "NAS_MSCC_SndXsdCdmacsqSetReq:ERROR: Memory Alloc Error for pMsg");

        return;
    }

    PS_MEM_SET((VOS_INT8*)pstMsg + VOS_MSG_HEAD_LENGTH, 0,
                     sizeof(MSCC_XSD_CDMACSQ_SET_REQ_STRU) - VOS_MSG_HEAD_LENGTH);

    PS_MEM_CPY((VOS_INT8*)pstMsg, (VOS_INT8*)pstCdmacsqSetReq, sizeof(MSCC_XSD_CDMACSQ_SET_REQ_STRU));

    pstMsg->stMsgHeader.ulReceiverCpuId  = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulReceiverPid    = UEPS_PID_XSD;
    pstMsg->stMsgHeader.ulSenderCpuId    = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulSenderPid      = UEPS_PID_MSCC;
    pstMsg->stMsgHeader.ulLength         = sizeof(MSCC_XSD_CDMACSQ_SET_REQ_STRU) - VOS_MSG_HEAD_LENGTH;
    pstMsg->stMsgHeader.ulMsgName        = ID_MSCC_XSD_CDMACSQ_SET_REQ;

    NAS_MSCC_LogMsgInfo((MSG_HEADER_STRU*)pstMsg);

    /* Send Message */
    PS_SEND_MSG(UEPS_PID_MSCC, pstMsg);

}


VOS_VOID NAS_MSCC_SndXsdSysAcqReq(
    MSCC_XSD_SYS_ACQ_TYPE_ENUM_UINT8    enXsdSystemAcqType
)
{
    MSCC_XSD_SYSTEM_ACQUIRE_REQ_STRU                       *pstMsg = VOS_NULL_PTR;

    /* Allocate memory to send message  */
    pstMsg = (MSCC_XSD_SYSTEM_ACQUIRE_REQ_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(UEPS_PID_MSCC,
                           sizeof(MSCC_XSD_SYSTEM_ACQUIRE_REQ_STRU));

    if (VOS_NULL_PTR == pstMsg)
    {
        NAS_ERROR_LOG(UEPS_PID_MSCC, "NAS_MSCC_SndXsdSysAcqReq:ERROR: Memory Alloc Error for pMsg");

        return;
    }

    PS_MEM_SET((VOS_INT8*)pstMsg + VOS_MSG_HEAD_LENGTH, 0,
                     sizeof(MSCC_XSD_SYSTEM_ACQUIRE_REQ_STRU) - VOS_MSG_HEAD_LENGTH);

    pstMsg->stMsgHeader.ulReceiverCpuId  = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulReceiverPid    = UEPS_PID_XSD;
    pstMsg->stMsgHeader.ulSenderCpuId    = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulSenderPid      = UEPS_PID_MSCC;
    pstMsg->stMsgHeader.ulLength         = sizeof(MSCC_XSD_SYSTEM_ACQUIRE_REQ_STRU) - VOS_MSG_HEAD_LENGTH;
    pstMsg->stMsgHeader.ulMsgName        = ID_MSCC_XSD_SYSTEM_ACQUIRE_REQ;

    pstMsg->enSysAcqType                 = enXsdSystemAcqType;

    NAS_MSCC_LogMsgInfo((MSG_HEADER_STRU*)pstMsg);

    /* Send Message */
    PS_SEND_MSG(UEPS_PID_MSCC, pstMsg);

    if (MSCC_XSD_SYS_ACQ_TYPE_INIT_SEARCH == enXsdSystemAcqType)
    {
        NAS_TRACE_HIGH("NAS_MSCC_SndXsdSysAcqReq():Mscc send sys acq to xsd for init search");
    }
    return;
}


VOS_VOID NAS_MSCC_SndXsdPowerSaveReq(
    NAS_MSCC_PIF_POWER_SAVE_TYPE_ENUM_UINT8                 enPowerSaveReason
)
{
    MSCC_XSD_POWER_SAVE_REQ_STRU       *pstMsg = VOS_NULL_PTR;

    /* Allocate the memory for Message */
    pstMsg = (MSCC_XSD_POWER_SAVE_REQ_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(UEPS_PID_MSCC,
                           sizeof(MSCC_XSD_POWER_SAVE_REQ_STRU));

    if (VOS_NULL_PTR == pstMsg)
    {
        NAS_ERROR_LOG(UEPS_PID_MSCC, "NAS_MSCC_SndXsdPowerSaveReq:ERROR: Memory Alloc Error for pMsg");

        return;
    }

    PS_MEM_SET((VOS_INT8*)pstMsg + VOS_MSG_HEAD_LENGTH, 0,
                     sizeof(MSCC_XSD_POWER_SAVE_REQ_STRU) - VOS_MSG_HEAD_LENGTH);

    pstMsg->stMsgHeader.ulReceiverCpuId  = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulReceiverPid    = UEPS_PID_XSD;
    pstMsg->stMsgHeader.ulSenderCpuId    = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulSenderPid      = UEPS_PID_MSCC;
    pstMsg->stMsgHeader.ulLength         = sizeof(MSCC_XSD_POWER_SAVE_REQ_STRU) - VOS_MSG_HEAD_LENGTH;
    pstMsg->stMsgHeader.ulMsgName        = ID_MSCC_XSD_POWER_SAVE_REQ;
    pstMsg->enPowerSaveReason            = enPowerSaveReason;

    NAS_MSCC_LogMsgInfo((MSG_HEADER_STRU*)pstMsg);

    /* send the Power save request to XSD */
    PS_SEND_MSG(UEPS_PID_MSCC, pstMsg);

    return;
}


VOS_VOID NAS_MSCC_SndXsdSysCfgReq(
    MMA_MSCC_SYS_CFG_SET_REQ_STRU      *pstSysCfgReq
)
{
    MSCC_XSD_SYS_CFG_REQ_STRU          *pstMsg = VOS_NULL_PTR;
    VOS_UINT16                          i;

    /* Allocate the memory for Message */
    pstMsg = (MSCC_XSD_SYS_CFG_REQ_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(UEPS_PID_MSCC,
                           sizeof(MSCC_XSD_SYS_CFG_REQ_STRU));

    if (VOS_NULL_PTR == pstMsg)
    {
        NAS_ERROR_LOG(UEPS_PID_MSCC, "NAS_MSCC_SndXsdSysCfgReq:ERROR: Memory Alloc Error for pMsg");

        return;
    }

    PS_MEM_SET((VOS_INT8*)pstMsg + VOS_MSG_HEAD_LENGTH, 0,
                     sizeof(MSCC_XSD_SYS_CFG_REQ_STRU) - VOS_MSG_HEAD_LENGTH);

    pstMsg->stMsgHeader.ulReceiverCpuId  = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulReceiverPid    = UEPS_PID_XSD;

    pstMsg->stMsgHeader.ulMsgName        = ID_MSCC_XSD_SYS_CFG_REQ;
    pstMsg->ucSuppRatNum                 = pstSysCfgReq->stRatPrioList.ucRatNum;
    pstMsg->stCdmaBand                   = pstSysCfgReq->stBand.unCdmaBand.stCdmaBitBand;

    for (i = 0; i < pstSysCfgReq->stRatPrioList.ucRatNum; i++)
    {
        pstMsg->aenRatMode[i]            = NAS_MSCC_TransferMsccToVosRat(pstSysCfgReq->stRatPrioList.aucRatPrio[i]);
    }

    NAS_MSCC_LogMsgInfo((MSG_HEADER_STRU*)pstMsg);

    /* send the system config request to XSD */
    PS_SEND_MSG(UEPS_PID_MSCC, pstMsg);

    return;
}



VOS_VOID NAS_MSCC_SndXsdHandsetInfoQryReq(
    VOS_UINT32                          ulInfoType
)
{
    MSCC_XSD_HANDSET_INFO_QRY_STRU      *pstMsg = VOS_NULL_PTR;

    /* Allocate memory to send message  */
    pstMsg = (MSCC_XSD_HANDSET_INFO_QRY_STRU *)PS_ALLOC_MSG_WITH_HEADER_LEN(WUEPS_PID_MMA,
                           sizeof(MSCC_XSD_HANDSET_INFO_QRY_STRU));

    if (VOS_NULL_PTR == pstMsg)
    {
        NAS_ERROR_LOG(UEPS_PID_MSCC, "NAS_MSCC_SndXsdHandsetInfoQryReq:ERROR: Memory Alloc Error for pMsg");

        return;
    }

    PS_MEM_SET((VOS_INT8*)pstMsg + VOS_MSG_HEAD_LENGTH, 0,
                     sizeof(MSCC_XSD_HANDSET_INFO_QRY_STRU) - VOS_MSG_HEAD_LENGTH);

    pstMsg->stMsgHeader.ulReceiverCpuId  = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulReceiverPid    = UEPS_PID_XSD;
    pstMsg->stMsgHeader.ulSenderCpuId    = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulSenderPid      = UEPS_PID_MSCC;
    pstMsg->stMsgHeader.ulLength         = sizeof(MSCC_XSD_HANDSET_INFO_QRY_STRU) - VOS_MSG_HEAD_LENGTH;
    pstMsg->stMsgHeader.ulMsgName        = ID_MSCC_XSD_HANDSET_INFO_QRY_REQ;
    pstMsg->ulInfoType                   = ulInfoType;

    NAS_MSCC_LogMsgInfo((MSG_HEADER_STRU*)pstMsg);

    /* Send Message */
    PS_SEND_MSG(UEPS_PID_MSCC, pstMsg);

    return;
}


VOS_VOID NAS_MSCC_SndXsdSrvAcqReq(
    MMA_MSCC_SRV_ACQ_REQ_STRU          *pstSrvAcqReq
)
{
    MSCC_XSD_SRV_ACQ_REQ_STRU          *pstMsg = VOS_NULL_PTR;

    /* 申请内存  */
    pstMsg = (MSCC_XSD_SRV_ACQ_REQ_STRU *)PS_ALLOC_MSG(UEPS_PID_MSCC,
                           sizeof(MSCC_XSD_SRV_ACQ_REQ_STRU) - VOS_MSG_HEAD_LENGTH);

    if (VOS_NULL_PTR == pstMsg)
    {
        NAS_ERROR_LOG(UEPS_PID_MSCC, "NAS_MSCC_SndXsdSrvAcqReq:ERROR: Memory Alloc Error for pMsg");
        return;
    }

    PS_MEM_SET((VOS_INT8*)pstMsg + VOS_MSG_HEAD_LENGTH, 0,
                     sizeof(MSCC_XSD_SRV_ACQ_REQ_STRU) - VOS_MSG_HEAD_LENGTH);

    pstMsg->stMsgHeader.ulReceiverCpuId  = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulReceiverPid    = UEPS_PID_XSD;
    pstMsg->stMsgHeader.ulSenderCpuId    = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulSenderPid      = UEPS_PID_MSCC;
    pstMsg->stMsgHeader.ulLength         = sizeof(MSCC_XSD_SRV_ACQ_REQ_STRU) - VOS_MSG_HEAD_LENGTH;
    pstMsg->stMsgHeader.ulMsgName        = ID_MSCC_XSD_SRV_ACQ_REQ;
    pstMsg->enSrvType                    = pstSrvAcqReq->enSrvType;

    NAS_MSCC_LogMsgInfo((MSG_HEADER_STRU*)pstMsg);

    /* 调用VOS发送原语 */
    PS_SEND_MSG(UEPS_PID_MSCC, pstMsg);

    return;
}


VOS_VOID NAS_MSCC_SndXsdBeginSessionNotify(
    MMA_MSCC_BEGIN_SESSION_NOTIFY_STRU *pstBeginSessionNtf
)
{
    MSCC_XSD_BEGIN_SESSION_NOTIFY_STRU *pstMsg = VOS_NULL_PTR;

    /* 申请内存  */
    pstMsg = (MSCC_XSD_BEGIN_SESSION_NOTIFY_STRU *)PS_ALLOC_MSG(UEPS_PID_MSCC,
                           sizeof(MSCC_XSD_BEGIN_SESSION_NOTIFY_STRU) - VOS_MSG_HEAD_LENGTH);

    if (VOS_NULL_PTR == pstMsg)
    {
        NAS_ERROR_LOG(UEPS_PID_MSCC, "NAS_MSCC_SndXsdBeginSessionNotify:ERROR: Memory Alloc Error for pMsg");
        return;
    }

    PS_MEM_SET((VOS_INT8*)pstMsg + VOS_MSG_HEAD_LENGTH, 0,
                     sizeof(MSCC_XSD_BEGIN_SESSION_NOTIFY_STRU) - VOS_MSG_HEAD_LENGTH);

    pstMsg->stMsgHeader.ulReceiverCpuId  = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulReceiverPid    = UEPS_PID_XSD;
    pstMsg->stMsgHeader.ulSenderCpuId    = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulSenderPid      = UEPS_PID_MSCC;
    pstMsg->stMsgHeader.ulLength         = sizeof(MSCC_XSD_BEGIN_SESSION_NOTIFY_STRU) - VOS_MSG_HEAD_LENGTH;
    pstMsg->stMsgHeader.ulMsgName        = ID_MSCC_XSD_BEGIN_SESSION_NOTIFY;

    pstMsg->enSrvType                    = pstBeginSessionNtf->enSrvType;

    NAS_MSCC_LogMsgInfo((MSG_HEADER_STRU*)pstMsg);

    /* 调用VOS发送原语 */
    PS_SEND_MSG(UEPS_PID_MSCC, pstMsg);

    return;
}


VOS_VOID NAS_MSCC_SndXsdEndSessionNotify(
    MMA_MSCC_END_SESSION_NOTIFY_STRU   *pstEndSessionNtf
)
{
    MSCC_XSD_END_SESSION_NOTIFY_STRU   *pstMsg = VOS_NULL_PTR;

    /* 申请内存  */
    pstMsg = (MSCC_XSD_END_SESSION_NOTIFY_STRU *)PS_ALLOC_MSG(UEPS_PID_MSCC,
                           sizeof(MSCC_XSD_END_SESSION_NOTIFY_STRU) - VOS_MSG_HEAD_LENGTH);

    if (VOS_NULL_PTR == pstMsg)
    {
        NAS_ERROR_LOG(UEPS_PID_MSCC, "NAS_MSCC_SndXsdEndSessionNotify:ERROR: Memory Alloc Error for pMsg");
        return;
    }

    PS_MEM_SET((VOS_INT8*)pstMsg + VOS_MSG_HEAD_LENGTH, 0,
                     sizeof(MSCC_XSD_END_SESSION_NOTIFY_STRU) - VOS_MSG_HEAD_LENGTH);

    pstMsg->stMsgHeader.ulReceiverCpuId  = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulReceiverPid    = UEPS_PID_XSD;
    pstMsg->stMsgHeader.ulSenderCpuId    = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulSenderPid      = UEPS_PID_MSCC;
    pstMsg->stMsgHeader.ulLength         = sizeof(MSCC_XSD_END_SESSION_NOTIFY_STRU) - VOS_MSG_HEAD_LENGTH;
    pstMsg->stMsgHeader.ulMsgName        = ID_MSCC_XSD_END_SESSION_NOTIFY;

    pstMsg->enSrvType                    = pstEndSessionNtf->enSrvType;

    NAS_MSCC_LogMsgInfo((MSG_HEADER_STRU*)pstMsg);

    /* 调用VOS发送原语 */
    PS_SEND_MSG(UEPS_PID_MSCC, pstMsg);

    return;
}


VOS_VOID NAS_MSCC_SndXsdEndEmcCallBackNtf( VOS_VOID )
{
    MSCC_XSD_END_EMC_CALLBACK_NTF_STRU          *pstMsg = VOS_NULL_PTR;

    /* 申请内存  */
    pstMsg = (MSCC_XSD_END_EMC_CALLBACK_NTF_STRU *)PS_ALLOC_MSG(UEPS_PID_MSCC,
                           sizeof(MSCC_XSD_END_EMC_CALLBACK_NTF_STRU) - VOS_MSG_HEAD_LENGTH);

    if (VOS_NULL_PTR == pstMsg)
    {
        NAS_ERROR_LOG(UEPS_PID_MSCC, "NAS_MSCC_SndXsdSrvAcqReq:ERROR: Memory Alloc Error for pMsg");
        return;
    }

    PS_MEM_SET((VOS_INT8*)pstMsg + VOS_MSG_HEAD_LENGTH, 0x00,
                     sizeof(MSCC_XSD_END_EMC_CALLBACK_NTF_STRU) - VOS_MSG_HEAD_LENGTH);

    pstMsg->stMsgHeader.ulReceiverCpuId  = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulReceiverPid    = UEPS_PID_XSD;
    pstMsg->stMsgHeader.ulSenderCpuId    = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulSenderPid      = UEPS_PID_MSCC;
    pstMsg->stMsgHeader.ulLength         = sizeof(MSCC_XSD_END_EMC_CALLBACK_NTF_STRU) - VOS_MSG_HEAD_LENGTH;
    pstMsg->stMsgHeader.ulMsgName        = ID_MSCC_XSD_END_EMC_CALLBACK_NTF;

    NAS_MSCC_LogMsgInfo((MSG_HEADER_STRU*)pstMsg);

    /* 调用VOS发送原语 */
    PS_SEND_MSG(UEPS_PID_MSCC, pstMsg);

    return;
}


VOS_VOID NAS_MSCC_SndXsdNormalServiceInd(
    VOS_UINT32                                              ulmcc,
    VOS_RATMODE_ENUM_UINT32                                 ulRatType
)
{
    MSCC_XSD_NORMAL_SERVICE_IND_STRU          *pstMsg = VOS_NULL_PTR;

    /* 申请内存  */
    pstMsg = (MSCC_XSD_NORMAL_SERVICE_IND_STRU *)PS_ALLOC_MSG(UEPS_PID_MSCC,
                           sizeof(MSCC_XSD_NORMAL_SERVICE_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    if (VOS_NULL_PTR == pstMsg)
    {
        NAS_ERROR_LOG(UEPS_PID_MSCC, "NAS_MSCC_SndXsdNormalServiceInd:ERROR: Memory Alloc Error for pMsg");
        return;
    }

    PS_MEM_SET((VOS_INT8*)pstMsg + VOS_MSG_HEAD_LENGTH, 0x00,
                     sizeof(MSCC_XSD_NORMAL_SERVICE_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    pstMsg->stMsgHeader.ulReceiverCpuId  = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulReceiverPid    = UEPS_PID_XSD;
    pstMsg->stMsgHeader.ulSenderCpuId    = VOS_LOCAL_CPUID;
    pstMsg->stMsgHeader.ulSenderPid      = UEPS_PID_MSCC;
    pstMsg->stMsgHeader.ulLength         = sizeof(MSCC_XSD_NORMAL_SERVICE_IND_STRU) - VOS_MSG_HEAD_LENGTH;
    pstMsg->stMsgHeader.ulMsgName        = ID_MSCC_XSD_NORMAL_SERVICE_IND;
    pstMsg->ulMcc                        = ulmcc;
    pstMsg->ulRatMode                    = ulRatType;

    NAS_MSCC_LogMsgInfo((MSG_HEADER_STRU*)pstMsg);

    /* 调用VOS发送原语 */
    PS_SEND_MSG(UEPS_PID_MSCC, pstMsg);

    return;
}


VOS_VOID NAS_MSCC_SndXsdLteHrpdConnInfoInd(
    VOS_UINT8                           ucHrpdConnExistFlg,
    VOS_UINT8                           ucLteEpsConnExistFlg
)
{
    MSCC_XSD_LTE_HRPD_CONN_INFO_IND_STRU  *pstMsg = VOS_NULL_PTR;

    /* 申请内存  */
    pstMsg = (MSCC_XSD_LTE_HRPD_CONN_INFO_IND_STRU *)PS_ALLOC_MSG(UEPS_PID_MSCC,
                           sizeof(MSCC_XSD_LTE_HRPD_CONN_INFO_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    if (VOS_NULL_PTR == pstMsg)
    {
        NAS_ERROR_LOG(UEPS_PID_MSCC, "NAS_MSCC_SndXsdLteHrpdConnInfoInd:ERROR: Memory Alloc Error for pMsg");
        return;
    }

    PS_MEM_SET((VOS_INT8*)pstMsg + VOS_MSG_HEAD_LENGTH, 0x00,
                     sizeof(MSCC_XSD_LTE_HRPD_CONN_INFO_IND_STRU) - VOS_MSG_HEAD_LENGTH);

    pstMsg->ulReceiverCpuId             = VOS_LOCAL_CPUID;
    pstMsg->ulReceiverPid               = UEPS_PID_XSD;
    pstMsg->ulSenderCpuId               = VOS_LOCAL_CPUID;
    pstMsg->ulSenderPid                 = UEPS_PID_MSCC;
    pstMsg->ulLength                    = sizeof(MSCC_XSD_LTE_HRPD_CONN_INFO_IND_STRU) - VOS_MSG_HEAD_LENGTH;
    pstMsg->enMsgId                     = ID_MSCC_XSD_LTE_HRPD_CONN_INFO_IND;
    pstMsg->ucHrpdConnExistFlg          = ucHrpdConnExistFlg;
    pstMsg->ucLteEpsConnExistFlg        = ucLteEpsConnExistFlg;

    NAS_MSCC_LogMsgInfo((MSG_HEADER_STRU*)pstMsg);

    /* 调用VOS发送原语 */
    PS_SEND_MSG(UEPS_PID_MSCC, pstMsg);

    return;
}
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cpluscplus */
#endif /* __cpluscplus */



