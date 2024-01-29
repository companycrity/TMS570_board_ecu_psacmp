/**********************************************************************************************************************
 * PROTECTION AGAINST MULTIPLE INCLUSION
 *********************************************************************************************************************/
#if (!defined RTE_TYPE_H)
#define RTE_TYPE_H

typedef uint16 NTCNumber;
typedef uint8 NxtrDiagMgrStatus;

#define NTC_STATUS_PASSED (0U)
#define NTC_STATUS_FAILED (1U)
#define NTC_Num_EEPROMDiag (10U)
#define NTC_Num_NvMBlkDftActA (6U)
#define NTC_Num_NvMBlkDftActB (7U)
#define NTC_Num_NvMBlkDftActC (8U)
#endif /* RTE_TYPE_H */
/* ---- End of File --------------------------------------------------------- */
