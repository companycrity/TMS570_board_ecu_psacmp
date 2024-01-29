
#ifndef IL_INC_H
#define IL_INC_H


#define kETAT_PRINCIP_SEV_DEM                2
#define kETAT_PRINCIP_SEV_Contact            1
#define kETAT_PRINCIP_SEV_Stop               0

#define kETAT_RESEAU_ELEC_TA_SECU            7
#define kETAT_RESEAU_ELEC_TA_DEGRADE         6
#define kETAT_RESEAU_ELEC_TA_NOMINAL         5
#define kETAT_RESEAU_ELEC_REDEMARRAGE        4
#define kETAT_RESEAU_ELEC_DEMARRAGE          3
#define kETAT_RESEAU_ELEC_TI_DISPO_DEM       2
#define kETAT_RESEAU_ELEC_TI_Degrade         1
#define kETAT_RESEAU_ELEC_TI_Nominal         0


#define kETAT_MT_Invalid                     15
#define kETAT_MT_Autonomous_Restart          13
#define kETAT_MT_Autonomous_Starting         10
#define kETAT_MT_Engine_Preparing            7
#define kETAT_MT_Degraded_Restart            6
#define kETAT_MT_Driven_Restart              5
#define kETAT_MT_Stopped                     4
#define kETAT_MT_Engine_Running              3
#define kETAT_MT_Starting                    2
#define kETAT_MT_Cut                         1
#define kETAT_MT_Locked                      0


#define kDIAG_MUX_ON_Enable_SCom_Diagnostics 1
#define kDIAG_MUX_ON_Disable_SCom_Diagnostics 0


#define kVITESSE_VEHICULE_ROUES_Invalid      65535


#define kCODE_DEFAUT_Fault_Code_Exists       1
#define kCODE_DEFAUT_No_Fault_Code           0

#define kETAT_ASSIST_DA_Disability_Parameter 7
#define kETAT_ASSIST_DA_STTd_Assist_Active   4
#define kETAT_ASSIST_DA_STTa_Assist_Active   3
#define kETAT_ASSIST_DA_Dmg_Assist_Active    2
#define kETAT_ASSIST_DA_Nominal_Assist_Active 1
#define kETAT_ASSIST_DA_Assist_Not_Active    0

#define kETAT_LIGNE_APC_Ignition_On          1
#define kETAT_LIGNE_APC_Ignition_Off         0


#define kCPLE_VOLANT_Invalid                 127

#define kETAT_DA_2004_Reserved               3
#define kETAT_DA_2004_Orange_LED             2
#define kETAT_DA_2004_Red_LED                1
#define kETAT_DA_2004_No_Demand              0

#define kETAT_DA_DYN_Invalid                 3
#define kETAT_DA_DYN_Adjustable_Mode         2
#define kETAT_DA_DYN_Dynamic_Mode            1
#define kETAT_DA_DYN_Normal_Mode             0

#define kETAT_DA_2010_Reserved               3
#define kETAT_DA_2010_Orange_LED             2
#define kETAT_DA_2010_Red_LED                1
#define kETAT_DA_2010_No_Demand              0

#define kTRQ_LIMIT_STATE_Saturation_Effective 1
#define kTRQ_LIMIT_STATE_No_Saturation       0

#define kSTEERWHL_HOLD_BY_DRV_Steer_Activity_From_Drv_Trq 1
#define kSTEERWHL_HOLD_BY_DRV_No_Steer_Activity_From_Drv_Trq 0

#define kEPS_STATE_LKA_Defect                4
#define kEPS_STATE_LKA_Active                3
#define kEPS_STATE_LKA_Available             2
#define kEPS_STATE_LKA_Authorised            1
#define kEPS_STATE_LKA_Unauthorised          0

#define kAUTOR_ARRET_MOT_DA_Permission_to_Stop 1
#define kAUTOR_ARRET_MOT_DA_No_Permission_to_Stop 0

#define kDDE_REDEM_DA_Request_Reboot         1
#define kDDE_REDEM_DA_No_Reboot_Required     0


#define kCPLE_VOLANT_OPTMSE_Invalid          127

#define kCAUSE_DESACTIV_CPK_Other_Faults     7
#define kCAUSE_DESACTIV_CPK_EPS_Thermal_Safety_Catch 6
#define kCAUSE_DESACTIV_CPK_Maneuvering_Number_Too_High 5
#define kCAUSE_DESACTIV_CPK_Obstacle_At_Wheel 4
#define kCAUSE_DESACTIV_CPK_Angular_Error_Too_High 3
#define kCAUSE_DESACTIV_CPK_Vehicle_Speed_Too_High 2
#define kCAUSE_DESACTIV_CPK_Driver_Hands_On  1
#define kCAUSE_DESACTIV_CPK_No_Control_Interruption 0

#define kETAT_DAE_CPK_Invalid                3
#define kETAT_DAE_CPK_Control_In_Progress    2
#define kETAT_DAE_CPK_Available              1
#define kETAT_DAE_CPK_Unavailable            0

#define kANGLE_COLONNE_Invalid               32767

#define kVITESSE_COLONNE_Invalid             2047

#define kETAT_SECU_ANGLE_COL_Secure          1
#define kETAT_SECU_ANGLE_COL_Not_Secure      0

#define kETAT_DAE_CAV3_VIRTUEL_Invalid       7
#define kETAT_DAE_CAV3_VIRTUEL_Reserved      6
#define kETAT_DAE_CAV3_VIRTUEL_EPS_Works_with_SelfDet_Offset 5
#define kETAT_DAE_CAV3_VIRTUEL_EPS_Works_with_Calibrated_Offset 4
#define kETAT_DAE_CAV3_VIRTUEL_EPS_Works_with_ESC_Offset 3
#define kETAT_DAE_CAV3_VIRTUEL_Offset_Search_Authorization 2
#define kETAT_DAE_CAV3_VIRTUEL_Offset_Initialization_Request 1
#define kETAT_DAE_CAV3_VIRTUEL_Initialization 0


#define kDownload_Month_December             12
#define kDownload_Month_November             11
#define kDownload_Month_October              10
#define kDownload_Month_September            9
#define kDownload_Month_August               8
#define kDownload_Month_July                 7
#define kDownload_Month_June                 6
#define kDownload_Month_May                  5
#define kDownload_Month_April                4
#define kDownload_Month_March                3
#define kDownload_Month_February             2
#define kDownload_Month_January              1


#define kReq_Mode_DA_Reserved                3
#define kReq_Mode_DA_Adjustable_Mode_Request 2
#define kReq_Mode_DA_Dynamic_Mode_Request    1
#define kReq_Mode_DA_Normal_Mode_Request     0


#define kCONS_ANGLE_CPK_Invalid              32767

#define kDMD_RELAXE_CPK_Invalid              3
#define kDMD_RELAXE_CPK_Relaxe_Request       2
#define kDMD_RELAXE_CPK_No_Request           1
#define kDMD_RELAXE_CPK_Reserved             0

#define kDMD_FCT_CPK_Invalid                 3
#define kDMD_FCT_CPK_SCP9_Control_Request    2
#define kDMD_FCT_CPK_SCP6_Control_Request    1
#define kDMD_FCT_CPK_No_Request              0


#define kANGLE_VOLANT_Invalid                32767

#define kVITESSE_ROT_VOL_Invalid             255

#define kETAT_CAPT_VOL_Sensor_Is_Okay        1
#define kETAT_CAPT_VOL_Sensor_Is_Faulty      0

#define kCALIBRATION_VOL_Calibrated          1
#define kCALIBRATION_VOL_Not_Calibrated      0

#define kTRIM_VOL_Trimmed                    1
#define kTRIM_VOL_Not_Trimmed                0

#define kCODE_DEFAUT_VOL_Internal_Failures_by_SWS_ 4
#define kCODE_DEFAUT_VOL_Failure_on_SWS_Angle__RotSpeed_ 3
#define kCODE_DEFAUT_VOL_Failure_on_SWS_Angle 2
#define kCODE_DEFAUT_VOL_Failure_on_SWS_Rotation_Speed_ 1
#define kCODE_DEFAUT_VOL_No_Default___Failure 0

#define kSENS_ROT_VOL_Clockwise              1
#define kSENS_ROT_VOL_Counter_Clockwise      0

#define kVITESSE_ROT_VOL_OPTIMISE_Invalid    255

#define kANGLE_VOLANT_ORIGINE_Other          3
#define kANGLE_VOLANT_ORIGINE_CAV3           2
#define kANGLE_VOLANT_ORIGINE_Integreated_CAV3 1
#define kANGLE_VOLANT_ORIGINE_Estimator      0

#define kFLG_AVOL_ICN_Uncertain_yet_Valid_Value 1
#define kFLG_AVOL_ICN_Valid_Value_in_Range   0

#define kFLG_INIT_AVOL_Steering_Wheel_Angle_Memorized 1
#define kFLG_INIT_AVOL_Steering_Wheel_Angle_Available 0


#define kDMD_DELEST_DA_Power_Cut_Request     1
#define kDMD_DELEST_DA_Not_Requested         0

#define kLKA_STATE_Reserved                  7
#define kLKA_STATE_Collision                 6
#define kLKA_STATE_Defect                    5
#define kLKA_STATE_Active                    4
#define kLKA_STATE_Authorized                3
#define kLKA_STATE_Selected                  2
#define kLKA_STATE_Unselected                1
#define kLKA_STATE_Unavailable               0

#define kLXA_ACTIVATION_LPA_Function         1
#define kLXA_ACTIVATION_LKA_Function         0

#define kLKA_TRQ_FACT_REQ_Invalid            127
#define kLKA_TRQ_FACT_REQ_Unavailable        126


#define kEFFAC_DEFAULT_DIAG_Default_Memory_Erase 1
#define kEFFAC_DEFAULT_DIAG_No_Specific_Action 0

#define kMODE_DIAG_Operation_and_Comm_Inhibited 1
#define kMODE_DIAG_No_Particular_Operation   0

#define kDIAG_INTEGRA_ELEC_No_Frame_Transmission 1
#define kDIAG_INTEGRA_ELEC_No_Particular_Operation 0


#define kVITESSE_VEHICLE_BV_Invalid          65535


#define kDTC_State_Current                   1
#define kDTC_State_History                   0


#define kRegul_ABR_Active_Regulation         1
#define kRegul_ABR_No_Regulation             0


#define kAccel_Lat_Invalid                   32767


#define kREQ_Lampe_DEF_ESP_Request_On        1
#define kREQ_Lampe_DEF_ESP_No_Request        0

#define kRegul_ESP_Active_Regulation         1
#define kRegul_ESP_No_Regulation             0

#define kESP_Deconnecte_Disconnected         1
#define kESP_Deconnecte_Connected            0


#define kOFFSET_Invalid                      32767
#define kOFFSET_Unavailable                  32766

#define kACQ_INTERRUPT_DAE_Acknowledge       1
#define kACQ_INTERRUPT_DAE_No_Acknowledge    0

#define kPRECISION_OFFSET_Invalid            31
#define kPRECISION_OFFSET_Unavailable        30


#define kCONFIG_VHL_INVALID                  7
#define kCONFIG_VHL_SHOW_ROOM                6
#define kCONFIG_VHL_APV                      5
#define kCONFIG_VHL_CLIENT                   4
#define kCONFIG_VHL_STORAGE___TRANSPORT      3
#define kCONFIG_VHL_CHECK                    2
#define kCONFIG_VHL_PLANT                    1
#define kCONFIG_VHL_FITTING                  0


#endif
