
#ifndef NHET_H
#define NHET_H


#define HET_P1ACC_1	(e_HETPROGRAM1_UN.Program1_ST.P1ACC_1)
#define HET_P2ACC_1	(e_HETPROGRAM1_UN.Program1_ST.P2ACC_1)
#define HET_P3ACC_1	(e_HETPROGRAM1_UN.Program1_ST.P3ACC_1)


typedef volatile struct memory_format
{
  uint32 program_word  ;
  uint32 control_word  ;
  uint32 data_word     ;
  uint32 reserved_word ;
} HET_MEMORY  ;

typedef volatile struct ecnt_format
{
  uint32                      : 11 ;
  uint32 brk                  : 1 ;
  uint32 next_program_address : 8 ;
  uint32 op_code              : 4 ;
  uint32                      : 1 ;
  uint32 count_mode           : 2 ;
  uint32 cap_en               : 1 ;
  uint32                      : 4 ;
 
  uint32                      : 11 ;
  uint32 previous_bit         : 1 ;
  uint32 cond_addr            : 8 ;
  uint32 pin_select           : 5 ;
  uint32 count_cond           : 3 ;
  uint32                      : 1 ;
  uint32 t_register_select    : 1 ;
  uint32 ab_register_select   : 1 ;
  uint32 interrupt_enable     : 1 ;

  uint32                      : 7 ;
  uint32 data                 : 20 ;
  uint32                      : 5 ;
 
} ECNT_FIELDS ;
 
typedef volatile union
{
  ECNT_FIELDS  ecnt   ;
  HET_MEMORY   memory ;
} ECNT_INSTRUCTION;

typedef volatile struct CNT_format                     
{
  uint32                      : 11 ;          
  uint32 brk                  : 1 ;          
  uint32 next_program_address : 8 ;          
  uint32 op_code              : 4 ;
  uint32 angle_cnt            : 1 ;
  uint32 t_register_select    : 1 ;
  uint32 ab_register_select   : 1 ;
  uint32                      : 4 ;
  uint32 interrupt_enable     : 1 ;
 

  uint32                      : 11 ;
  uint32                      : 1 ;
  uint32 max                  : 20 ;

  uint32                      : 7 ;
  uint32 data                 : 20 ;
  uint32                      : 5 ;

} CNT_FIELDS ; 

typedef volatile union 
{
  CNT_FIELDS   cnt    ; 
  HET_MEMORY   memory ;
} CNT_INSTRUCTION;

typedef volatile struct br_format                     
{
  uint32                      : 11 ;
  uint32 brk                  : 1 ;
  uint32 next_program_address : 8 ;
  uint32 op_code              : 4 ;
  uint32                      : 8 ;

  uint32                      : 11 ;
  uint32 previous_bit         : 1 ;
  uint32 cond_addr            : 8 ;
  uint32 pin_select           : 5 ;
  uint32 branch_condition     : 3 ;
  uint32                      : 1 ;
  uint32                      : 1 ;
  uint32                      : 1 ;
  uint32 interrupt_enable     : 1 ;
 
  uint32                      : 7 ;
  uint32 data                 : 25 ;

} BR_FIELDS ;      

typedef volatile union 
{
  BR_FIELDS  br     ; 
  HET_MEMORY memory ;
} BR_INSTRUCTION;

typedef union 
{ 
 	HET_MEMORY	Memory1_PST[5];
	struct
	{
		CNT_INSTRUCTION FRCTR_1;
		ECNT_INSTRUCTION P1ACC_1;
		ECNT_INSTRUCTION P2ACC_1;
		ECNT_INSTRUCTION P3ACC_1;
		BR_INSTRUCTION END_1;
	} Program1_ST; 

} HETPROGRAM1_UN;


extern volatile HETPROGRAM1_UN e_HETPROGRAM1_UN;

#endif
