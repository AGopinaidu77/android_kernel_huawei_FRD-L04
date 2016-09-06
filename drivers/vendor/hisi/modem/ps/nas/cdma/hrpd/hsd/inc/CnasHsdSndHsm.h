

#ifndef __CNAS_HSD_SND_HSM_H__
#define __CNAS_HSD_SND_HSM_H__

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
#include  "vos.h"
#include  "cas_hrpd_overheadmsg_nas_pif.h"
#include  "hsm_hsd_pif.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

/*****************************************************************************
  2 �궨��
*****************************************************************************/


/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/


/*****************************************************************************
  4 ȫ�ֱ�������
*****************************************************************************/


/*****************************************************************************
  5 ��Ϣͷ����
*****************************************************************************/


/*****************************************************************************
  6 ��Ϣ����
*****************************************************************************/


/*****************************************************************************
  7 STRUCT����
*****************************************************************************/


/*****************************************************************************
  8 UNION����
*****************************************************************************/


/*****************************************************************************
  9 OTHERS����
*****************************************************************************/


/*****************************************************************************
  10 ��������
*****************************************************************************/
#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)

extern VOS_VOID CNAS_HSD_SndHsmStartReq(VOS_VOID);

extern VOS_VOID CNAS_HSD_SndHsmPowerOffReq(VOS_VOID);

extern VOS_VOID CNAS_HSD_SndHsmSysAcqSuccInd(
    VOS_UINT32                                              aulSystemTime[],
    HSD_HSM_SYSTEM_ACQUIRE_TYPE_ENUM_UINT8                  enCurSysAcqType
);
extern VOS_VOID CNAS_HSD_SndHsmOverheadMsgInd(
    CAS_CNAS_HRPD_OVERHEAD_MSG_IND_STRU                    *pstCasOhmMsg
);

extern VOS_VOID CNAS_HSD_SndHsmOhmNotCurrentInd(VOS_VOID);


extern VOS_VOID CNAS_HSD_SndHsmIratFromLteInd(VOS_VOID);

extern VOS_VOID CNAS_HSD_SndHsmIratToLteInd(VOS_VOID);

extern VOS_VOID CNAS_HSD_SndHsmSuspendInd(VOS_VOID);

extern VOS_VOID CNAS_HSD_SndHsmResumeInd(VOS_VOID);

extern VOS_VOID CNAS_HSD_SndHsmPowerSaveReq(VOS_VOID);

extern VOS_VOID CNAS_HSD_SndHsmPilotSearchFailNtf(VOS_VOID);

#endif




#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of CnasHsdSndHsm.h */
