

#ifndef __SCOPERATOR_H__
#define __SCOPERATOR_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(4)

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
#include "vos.h"
#include "omnvinterface.h"

/*****************************************************************************
  2 �궨��
*****************************************************************************/


#define   SC_IMSI_FIRST_BYTE        (0x08)                      /* IMSI��һ���ֽڵ�ֵ */

#define   EF_IMSI_FILE_ID           (0x6F07)                    /* IMSI���ļ�ID */

#define   EF_GID1_FILE_ID           (0x6F3E)                    /* GID1���ļ�ID */

#define   SC_PLMN_LEN(plmn)         ((0x0F == (((*((plmn)+1))>>4)&0x0F))?5:6)   /* �ж�PLMN��λ�� */

#define   SC_IMSI_DEPART_LEN        (15)                        /* IMSI��ֳ��� */

#define   SC_CODE_DEPART_LEN        (2*SC_MAX_CODE_LEN)         /* �Ŷβ�ֺ�ĳ��� */

#define   SC_NET_CODE_LEN           (3)                         /* �����Ŷγ��� */

#define   SC_NETSUB_CODE_LEN        (4)                         /* �������Ŷγ��� */

#define   SC_SP_CODE_LEN            (4)                         /* ��SP�Ŷγ��� */

#define   SC_NET_CODE_DEPART_LEN    (2*SC_NET_CODE_LEN)         /* �����Ŷβ�ֳ��� */

#define   SC_SP_LEN                 (1)                         /* SP�ĳ��� */

#define   SC_SP_DEPART_LEN          (2*SC_SP_LEN)               /* SP��ֳ��� */

#define   SC_NET_SUB_DEPART_LEN     (2)                         /* �����Ų�ֳ��� */

#define   SC_CODE_FOURTH_NUM_INDEX  (3)                         /* ��ֺ����������������ĸ����ֵ����� */

#define   SC_MAX_CMP_IMEI           (3)                         /* ��IMEI���У����� */

#define   SC_IMEI0_REPLACE_IMEI2_FLG    (0x5A5A)                /* ����IMEI0�滻IMEI2��� */

#define   SC_CDMA_PLMN_LEN          (5)                         /* CDMA PLMN���� */
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

SC_PERS_PLATFORM_ENUM_UINT32 SC_PERS_SupportPlatform(
    MODEM_ID_ENUM_UINT16                enModemID
);


VOS_UINT32 SC_PERS_ChangeNum(VOS_UINT32 ulSrcValude, VOS_UINT32 ulCodeMode);


VOS_UINT32 SC_PERS_CDMAImsiBcd2Num(
    VOS_UINT8                           ucLen,
    const VOS_UINT8                    *pucImsi,
    VOS_UINT8                          *pucNum
);


VOS_UINT32 SC_PERS_CDMACheckCode(
    SC_SIMLOCK_CATEGORY_STRU           *pstSimLockCat,
    VOS_UINT8                          *pucIMSI,
    MODEM_ID_ENUM_UINT16                enModemID
);


VOS_UINT32 SC_PERS_CDMAVrifySimLock(
    SC_VERIFY_SIMLOCK_RESULT_ENUM_UINT8 *penVerifySimlockRslt,
    SC_PI_FILE_STRU                     *pstPIFile,
    MODEM_ID_ENUM_UINT16                 enModemID
);

#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif