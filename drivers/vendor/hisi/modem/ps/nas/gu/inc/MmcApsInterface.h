

#ifndef __MMC_APS_INTERFACE_H__
#define __MMC_APS_INTERFACE_H__

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
#include "vos.h"
#include "PsTypeDef.h"

/* ɾ��ExtAppMmcInterface.h*/
#include "TafMmcInterface.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

/*****************************************************************************
  2 �궨��
*****************************************************************************/

enum MMC_APS_MSG_ID_ENUM
{
    ID_MMC_APS_SERVICE_STATUS_IND = TAFMMC_APS_SERVICE_STATE_IND,               /* _H2ASN_MsgChoice MMC_APS_SERVICE_STATUS_IND_STRU */

    ID_MMC_APS_PS_REG_STATUS_IND  = TAFMMC_APS_PS_REG_STATUS_IND,

    /* �����ö��ֵ����ֱ�ӵ�����MMC�ж����ϱ�����Ϣ */

    ID_MMC_APS_MSG_ID_ENUM_BUTT

};
typedef VOS_UINT32 MMC_APS_MSG_ID_ENUM_UINT32;


/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/

enum MMC_APS_RAT_TYPE_ENUM
{
    MMC_APS_RAT_TYPE_NULL,          /* ��ǰδ���κ�������פ�� */
    MMC_APS_RAT_TYPE_GSM,           /* GSM���뼼�� */
    MMC_APS_RAT_TYPE_WCDMA,         /* WCDMA���뼼�� */
    MMC_APS_RAT_TYPE_LTE,           /* LTE���뼼�� */
    MMC_APS_RAT_TYPE_BUTT           /* ��Ч�Ľ��뼼�� */
};
typedef VOS_UINT32 MMC_APS_RAT_TYPE_ENUM_UINT32;


enum MMC_APS_PS_REG_RESULT_ENUM
{
    MMC_APS_PS_REG_RESULT_SUCCESS    = 0,    /*PS��ע��ɹ�*/
    MMC_APS_PS_REG_RESULT_FAILURE    = 1,    /*PS��ע��ʧ��*/
    MMC_APS_PS_REG_RESULT_BUTT
};
typedef VOS_UINT32 MMC_APS_PS_REG_RESULT_ENUM_U32;

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

typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /* ��Ϣͷ */ /*_H2ASN_Skip*/
    MMC_APS_RAT_TYPE_ENUM_UINT32        enRatType;                              /* ��ѯ���صĵ�ǰ���� */
    VOS_UINT32                          ulPsSimRegStatus;                       /* PS��SIM��״̬��Ϣ,VOS_TRUE:����Ч,VOS_FALSE:����Ч */
}MMC_APS_SERVICE_STATUS_IND_STRU;


typedef struct
{
    VOS_UINT32                          ulMcc;                                  /* MCC,3 bytes */
    VOS_UINT32                          ulMnc;                                  /* MNC,2 or 3 bytes */
}MMC_APS_PLMN_ID_STRU;


typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /* ��Ϣͷ */ /*_H2ASN_Skip*/
    MMC_APS_PS_REG_RESULT_ENUM_U32      enPsRegResult;                          /* PS��ע���� */
    MMC_APS_PLMN_ID_STRU                stPlmnId;                               /* ��ǰ��PLMN ID */
}MMC_APS_PS_REG_STATUS_IND_STRU;

/*****************************************************************************
  8 UNION����
*****************************************************************************/
/*****************************************************************************
  H2ASN������Ϣ�ṹ����
*****************************************************************************/
typedef struct
{
    MMC_APS_MSG_ID_ENUM_UINT32          enMsgID;                /*_H2ASN_MsgChoice_Export MMC_APS_MSG_ID_ENUM_UINT32 */
                                                                /* Ϊ�˼���NAS����Ϣͷ���壬����ת��ASN.MMC_APS_MSG_ID_ENUM_UINT32 */

    VOS_UINT8                           aucMsgBlock[4];
    /***************************************************************************
        _H2ASN_MsgChoice_When_Comment          MMC_APS_MSG_ID_ENUM_UINT32
    ****************************************************************************/
}MMC_APS_SND_INTERNAL_DATA;
/*_H2ASN_Length UINT32*/

typedef struct
{
    VOS_MSG_HEADER
    MMC_APS_SND_INTERNAL_DATA            stMsgData;
}MmcApsInterfacemsg_MSG;

/*****************************************************************************
  8 UNION����
*****************************************************************************/


/*****************************************************************************
  9 OTHERS����
*****************************************************************************/


/*****************************************************************************
  10 ��������
*****************************************************************************/



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

#endif /* end of MmcApsInteraface.h */
