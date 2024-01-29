
/**********************************************************************************************************************
 * PROTECTION AGAINST MULTIPLE INCLUSION
 *********************************************************************************************************************/
#if (!defined AP_DIAGMGR_H_)
#define AP_DIAGMGR_H_

extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgr10_ReportNTCStatus( VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, VAR(uint8, AUTOMATIC) Param_Cnt_T_u08, VAR(NxtrDiagMgrStatus, AUTOMATIC) Status_Cnt_T_enum );


#endif
/* ---- End of File --------------------------------------------------------- */
