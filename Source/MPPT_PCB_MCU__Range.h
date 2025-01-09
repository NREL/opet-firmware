/* 
	-----------------------------------------
	MPPT PCB MCU source
	-----------------------------------------
	Made by:	Martin Bliss
	Version:	1.16
	Date:		08.03.2024
	-----------------------------------------
	ATMega 128 Micro controller support
	-----------------------------------------
	   Range Selection header file
	=========================================
*/

#ifndef MPPT_PCB_MCU__Range_H_
#define MPPT_PCB_MCU__Range_H_

//===========================================================================================
// Definitions and constants

#define RANGE_ID_AUTORANGE 255
#define Volt_range_max_ID 4
#define Curr_range_max_ID 5
#define Over_Range_Threshold_Fact 1.03
#define Under_Range_Threshold_Fact 0.90
#define ADC_Range_Norm_Scale_Count 62200.0 // 16bit 65536 with 4% over range minus offset 700 counts


//	Range_Status_A:
//		Bit0:	R_Stat_Volt_R_Manual
				#define SET__R_Stat_Volt_R_Manual (SETBIT(Range_Status_A, 0))
				#define CLR__R_Stat_Volt_R_Manual (CLRBIT(Range_Status_A, 0))
				#define is_manual_Volt_Range_Set (Range_Status_A & BIT(0))
//		Bit1:	R_Stat_Curr_R_Manual
				#define SET__R_Stat_Curr_R_Manual (SETBIT(Range_Status_A, 1))
				#define CLR__R_Stat_Curr_R_Manual (CLRBIT(Range_Status_A, 1))
				#define is_manual_Curr_Range_Set (Range_Status_A & BIT(1))
//		Bit2:	R_Stat_Cal_Mode_Volt_Act
				#define SET__R_Stat_Cal_Mode_Volt_Act (SETBIT(Range_Status_A, 2))
				#define CLR__R_Stat_Cal_Mode_Volt_Act (CLRBIT(Range_Status_A, 2))
				#define is_R_Stat_Cal_Mode_Volt_Act (Range_Status_A & BIT(2))
//		Bit3:	R_Stat_Cal_Mode_Curr_Act
				#define SET__R_Stat_Cal_Mode_Curr_Act (SETBIT(Range_Status_A, 3))
				#define CLR__R_Stat_Cal_Mode_Curr_Act (CLRBIT(Range_Status_A, 3))
				#define is_R_Stat_Cal_Mode_Curr_Act (Range_Status_A & BIT(3))
//		Bit4:	R_Stat_Volt_AI_Over_Load
				#define SET__R_Stat_Volt_Over_Load (SETBIT(Range_Status_A, 4))
				#define CLR__R_Stat_Volt_Over_Load (CLRBIT(Range_Status_A, 4))
				#define is_Volt_Over_Load (Range_Status_A & BIT(4))
//		Bit5:	R_Stat_Volt_AI_Under_R
				#define SET__R_Stat_Volt_Under_Load (SETBIT(Range_Status_A, 5))
				#define CLR__R_Stat_Volt_Under_Load (CLRBIT(Range_Status_A, 5))
//		Bit6:	R_Stat_Curr_AI_Over_R
				#define SET__R_Stat_Curr_Over_Load (SETBIT(Range_Status_A, 6))
				#define CLR__R_Stat_Curr_Over_Load (CLRBIT(Range_Status_A, 6))
				#define is_Curr_Over_Load (Range_Status_A & BIT(6))
//		Bit7:	R_Stat_Curr_AI_Under_R
				#define SET__R_Stat_Curr_Under_Load (SETBIT(Range_Status_A, 7))
				#define CLR__R_Stat_Curr_Under_Load (CLRBIT(Range_Status_A, 7))
				
//	Range_Status_B:
//		Bit0:	R_Stat_Volt_Clear_Buffer
				#define SET__R_Stat_Volt_Clear_Buffer (SETBIT(Range_Status_B, 0))
				#define CLR__R_Stat_Volt_Clear_Buffer (CLRBIT(Range_Status_B, 0))
				#define is_R_Stat_Volt_Clear_Buffer_Set (Range_Status_B & BIT(0))
//		Bit1:	R_Stat_Volt_Clear_Buffer
				#define SET__R_Stat_Curr_Clear_Buffer (SETBIT(Range_Status_B, 1))
				#define CLR__R_Stat_Curr_Clear_Buffer (CLRBIT(Range_Status_B, 1))
				#define is_R_Stat_Curr_Clear_Buffer_Set (Range_Status_B & BIT(1))
//		Bit2:	Temp -
//		Bit3:	none
//		Bit4:	none
//		Bit5:	none
//		Bit6:	none
//		Bit7:	none

//	Range_Volt_Enable:
//		Bit0:	is_Volt_Range_0_Enable
				#define is_Volt_Range_0_Enable (Range_Volt_Enable & BIT(0))
//		Bit1:	is_Volt_Range_1_Enable
				#define is_Volt_Range_1_Enable (Range_Volt_Enable & BIT(1))
//		Bit2:	is_Volt_Range_2_Enable
				#define is_Volt_Range_2_Enable (Range_Volt_Enable & BIT(2))
//		Bit3:	is_Volt_Range_3_Enable
				#define is_Volt_Range_3_Enable (Range_Volt_Enable & BIT(3))
//		Bit4:	is_Volt_Range_4_Enable
				#define is_Volt_Range_4_Enable (Range_Volt_Enable & BIT(4))
//		Bit5:	none
//		Bit6:	none
//		Bit7:	none

//	Range_Curr_Enable:
//		Bit0:	is_Curr_Range_0_Enable
				#define is_Curr_Range_0_Enable (Range_Curr_Enable & BIT(0))
//		Bit1:	is_Curr_Range_1_Enable
				#define is_Curr_Range_1_Enable (Range_Curr_Enable & BIT(1))
//		Bit2:	is_Curr_Range_2_Enable
				#define is_Curr_Range_2_Enable (Range_Curr_Enable & BIT(2))
//		Bit3:	is_Curr_Range_3_Enable
				#define is_Curr_Range_3_Enable (Range_Curr_Enable & BIT(3))
//		Bit4:	is_Curr_Range_4_Enable
				#define is_Curr_Range_4_Enable (Range_Curr_Enable & BIT(4))
//		Bit5:	is_Curr_Range_5_Enable
				#define is_Curr_Range_5_Enable (Range_Curr_Enable & BIT(5))
//		Bit6:	none
//		Bit7:	none


//===========================================================================================
// EXTERN VARIABLES and STRUCTURES

// Range Control Values
extern volatile uint8_t Range_Volt_ID_Act; // range ID integer (0:1V to 5:100V)
extern volatile float Range_Volt_Val_Act;  // range value in V
extern volatile uint8_t Range_Volt_ID_Man;   // manual range control
extern volatile uint8_t Range_Volt_Enable;	// if byte number associated with range number is true, range is enabled
extern volatile uint8_t Range_Curr_ID_Act; // range ID integer (0:0.5mA to 5:150mA) or(0:50mA to 5:15A)
extern volatile float Range_Curr_Val_Act;  // range value in A
extern volatile uint8_t Range_Curr_ID_Man;   // manual range control
extern volatile uint8_t Range_Curr_Enable;
extern volatile float Threshold_Volt_Over_Range[Volt_range_max_ID+1];
extern volatile uint16_t Range_Curr_Switch_Freq_Ctr_Max;
extern volatile uint16_t Range_Volt_Switch_Freq_Ctr_Max;
extern volatile uint16_t Range_Curr_Switch_Freq_Counter;
extern volatile uint16_t Range_Volt_Switch_Freq_Counter;
extern volatile uint8_t Range_Curr_Switch_Delay_Counter;
extern volatile uint8_t Range_Curr_Switch_Delay_Ctr_Max;
extern volatile uint8_t Range_Volt_Switch_Delay_Counter;
extern volatile uint8_t Range_Volt_Switch_Delay_Ctr_Max;

// Voltage Range
extern volatile float AI_Volt_Offset;
extern volatile float AI_Volt_Scale;
extern volatile float AI_Volt_R_Leak;
extern volatile float AI_Volt_Range_Val;

// Current Range
extern volatile float AI_Curr_Offset;
extern volatile float AI_Curr_Scale;
extern volatile float AI_Curr_Range_Val;

// Range Status
extern volatile uint8_t Range_Status_A;
extern volatile uint8_t Range_Status_B;

//===========================================================================================
// EXTERN EEPROM VARIABLES
// Range control Variables
extern EEMEM uint8_t EROM_Range_Status_A;
extern EEMEM uint8_t EROM_Range_Volt_ID_Man;
extern EEMEM uint8_t EROM_Range_Curr_ID_Man;
extern EEMEM uint8_t EROM_Range_Volt_Enable;
extern EEMEM uint8_t EROM_Range_Curr_Enable;
extern EEMEM uint16_t EROM_Range_Curr_Switch_Freq_Ctr_Max;
extern EEMEM uint16_t EROM_Range_Volt_Switch_Freq_Ctr_Max;
extern EEMEM uint8_t EROM_Range_Curr_Switch_Delay_Ctr_Max;
extern EEMEM uint8_t EROM_Range_Volt_Switch_Delay_Ctr_Max;

// Voltage Calibration values
extern EEMEM float EROM_V_R1_A0;
extern EEMEM float EROM_V_R1_A1;
extern EEMEM float EROM_V_R1_Val_Nom;
extern EEMEM float EROM_V_R1_R_Leak;

extern EEMEM float EROM_V_R2_A0;
extern EEMEM float EROM_V_R2_A1;
extern EEMEM float EROM_V_R2_Val_Nom;
extern EEMEM float EROM_V_R2_R_Leak;

extern EEMEM float EROM_V_R3_A0;
extern EEMEM float EROM_V_R3_A1;
extern EEMEM float EROM_V_R3_Val_Nom;
extern EEMEM float EROM_V_R3_R_Leak;

extern EEMEM float EROM_V_R4_A0;
extern EEMEM float EROM_V_R4_A1;
extern EEMEM float EROM_V_R4_Val_Nom;
extern EEMEM float EROM_V_R4_R_Leak;

extern EEMEM float EROM_V_R5_A0;
extern EEMEM float EROM_V_R5_A1;
extern EEMEM float EROM_V_R5_Val_Nom;
extern EEMEM float EROM_V_R5_R_Leak;

// Current Calibration values
extern EEMEM float EROM_C_R1_A0;
extern EEMEM float EROM_C_R1_A1;
extern EEMEM float EROM_C_R1_Val_Nom;

extern EEMEM float EROM_C_R2_A0;
extern EEMEM float EROM_C_R2_A1;
extern EEMEM float EROM_C_R2_Val_Nom;

extern EEMEM float EROM_C_R3_A0;
extern EEMEM float EROM_C_R3_A1;
extern EEMEM float EROM_C_R3_Val_Nom;

extern EEMEM float EROM_C_R4_A0;
extern EEMEM float EROM_C_R4_A1;
extern EEMEM float EROM_C_R4_Val_Nom;

extern EEMEM float EROM_C_R5_A0;
extern EEMEM float EROM_C_R5_A1;
extern EEMEM float EROM_C_R5_Val_Nom;

extern EEMEM float EROM_C_R6_A0;
extern EEMEM float EROM_C_R6_A1;
extern EEMEM float EROM_C_R6_Val_Nom;

//===========================================================================================
// FUNCTION Prototypes
void Check_Input_Range_Selection();
void Process_Voltage_Auto_Range();
void Process_Current_Auto_Range();
void Reset_Over_Current_Clamp();
void Preare_Auto_Range_Selection();
uint8_t Get_Best_Voltage_Range_From_Value(float Value);
uint8_t Get_Best_Current_Range_From_Value(float Value);
void SET_VOLTAGE_RANGE(uint8_t Range_ID);
void SET_CURRENT_RANGE(uint8_t Range_ID);
uint8_t Check_Voltage_Range_Enabled_Correct(uint8_t Range_ID);
uint8_t Check_Current_Range_Enabled_Correct(uint8_t Range_ID);

//end
#endif /* MPPT_PCB_MCU__Range_H_ */