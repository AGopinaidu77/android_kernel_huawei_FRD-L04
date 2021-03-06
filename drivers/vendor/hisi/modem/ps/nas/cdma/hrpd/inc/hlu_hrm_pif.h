/** ****************************************************************************

                    Huawei Technologies Sweden AB (C), 2001-2016

 ********************************************************************************
 * @author    Automatically generated by DAISY
 * @version
 * @date      2016-02-25 09:58:32
 * @file
 * @brief
 * @copyright Huawei Technologies Sweden AB
 *******************************************************************************/
#ifndef HLU_HRM_PIF_H
#define HLU_HRM_PIF_H

/*******************************************************************************
 1. Other files included
*******************************************************************************/

#include "vos.h"
#include "cttf_hrpd_sig_public_pif.h"
#include "hrm_pif.h"

#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif /* __cpluscplus */
#endif /* __cpluscplus */
#pragma pack(4)

/*******************************************************************************
 2. Macro definitions
*******************************************************************************/


/*******************************************************************************
 3. Enumerations declarations
*******************************************************************************/

/** ****************************************************************************
 * Name        : HLU_HRM_PIF_MSG_TYPE_ENUM_UINT16
 *
 * Description :
 *******************************************************************************/
enum HLU_HRM_PIF_MSG_TYPE_ENUM
{
    ID_HRM_HLU_DATA_IND                 = 0x0000, /**< @sa HRM_HLU_DATA_IND_STRU */
    ID_HLU_HRM_DATA_REQ                 = 0x0001, /**< @sa HLU_HRM_DATA_REQ_STRU */
    ID_HRM_HLU_DATA_CNF                 = 0x0002, /**< @sa HRM_HLU_DATA_CNF_STRU */
    ID_HLU_HRM_DATA_CANCEL_NTF          = 0x0003, /**< @sa HLU_HRM_DATA_CANCEL_NTF_STRU */
    ID_HLU_HRM_PIF_MSG_TYPE_ENUM_BUTT   = 0x0004
};
typedef VOS_UINT16 HLU_HRM_PIF_MSG_TYPE_ENUM_UINT16;

/** ****************************************************************************
 * Name        : HRM_HLU_DATA_CNF_RSLT_ENUM_UINT32
 *
 * Description :
 *******************************************************************************/
enum HRM_HLU_DATA_CNF_RSLT_ENUM
{
    HRM_HLU_DATA_CNF_RSLT_SUCC          = 0x00000000,
    HRM_HLU_DATA_CNF_RSLT_FAIL          = 0x00000001,
    HRM_HLU_DATA_CNF_RSLT_NO_RF         = 0x00000002,
    HRM_HLU_DATA_CNF_RSLT_ENUM_BUTT     = 0x00000003
};
typedef VOS_UINT32 HRM_HLU_DATA_CNF_RSLT_ENUM_UINT32;

/*******************************************************************************
 4. Message Header declaration
*******************************************************************************/

/*******************************************************************************
 5. Message declaration
*******************************************************************************/

/*******************************************************************************
 6. STRUCT and UNION declaration
*******************************************************************************/

/*******************************************************************************
 7. OTHER declarations
*******************************************************************************/

/** ****************************************************************************
 * Name        : HRM_HLU_DATA_IND_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    HLU_HRM_PIF_MSG_TYPE_ENUM_UINT16    enMsgId;
    VOS_UINT16                          usOpId;
    CTTF_HRPD_PROTOCOL_TYPE_ENUM_UINT16 enProtocolType; /**< protocol type */
    CTTF_HRPD_INSTANCE_TYPE_ENUM_UINT8  enInstanceType; /**< InConfiguration or InUse instance */
    VOS_UINT8                           aucReserve[1];
    SNPITF_MSG_DATA_STRU                stMsgData;      /**< message data struct */
} HRM_HLU_DATA_IND_STRU;

/** ****************************************************************************
 * Name        : HLU_HRM_DATA_REQ_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    HLU_HRM_PIF_MSG_TYPE_ENUM_UINT16    enMsgId;
    VOS_UINT16                          usOpId;
    CNAS_HRM_DATA_REQ_TYPE_ENUM_UINT32  enDataReqType;
    CNAS_HRM_DATA_REQ_COMM_CONTENT_STRU stDataReqCommContent;
} HLU_HRM_DATA_REQ_STRU;

/** ****************************************************************************
 * Name        : HRM_HLU_DATA_CNF_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    HLU_HRM_PIF_MSG_TYPE_ENUM_UINT16                        enMsgId;
    VOS_UINT16                                              usOpId;
    HRM_HLU_DATA_CNF_RSLT_ENUM_UINT32                       enRslt;
    CTTF_HRPD_SNP_DATA_FAIL_REASON_ENUM_UINT32              enFailReason;
} HRM_HLU_DATA_CNF_STRU;

/** ****************************************************************************
 * Name        : HLU_HRM_DATA_CANCEL_NTF_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    HLU_HRM_PIF_MSG_TYPE_ENUM_UINT16    enMsgId;
    VOS_UINT16                          usOpId;
    CNAS_HRM_DATA_REQ_TYPE_ENUM_UINT32  enDataReqType;
} HLU_HRM_DATA_CANCEL_NTF_STRU;

/*******************************************************************************
 8. Global  declaration
*******************************************************************************/

/*******************************************************************************
 9. Function declarations
*******************************************************************************/

#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cpluscplus */
#endif /* __cpluscplus */

#endif
