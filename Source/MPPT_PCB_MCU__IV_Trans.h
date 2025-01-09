/* 
	-----------------------------------------
	MPPT PCB MCU source
	-----------------------------------------
	Made by:	Martin Bliss
	Version:	1.15
	Date:		02.03.2024
	-----------------------------------------
	ATMega 128 Micro controller support
	-----------------------------------------
	   IV & Transient meas header file
	=========================================
*/

#ifndef MPPT_PCB_MCU__IV_TRANS_H_
#define MPPT_PCB_MCU__IV_TRANS_H_

//===========================================================================================
// Definitions and constants
#define MAX_IV_POINTS 251
#define MIN_IV_POINTS 3
#define Trs_Meas_Time_cycls 189.0
#define Trs_Delay_Res_cycls 8.0
#define IV_Range_Set_Settle_Time_ms 50 // setting time for range control
#define IV_Setup_Signal_Set_Multiplier 3 // multiplier of PV delay time to get setup signal settling time for VOC and ISC
#define IV_Setup_Max_Delay_For_Mul 20000 // max PV delay to apply multiplier, or just use maximum value, linked to above
#define IV_Temp_Bias_Mon_No_Meas 20 // number of averages of bias and temperature measurements
#define IV_Temp_Bias_Mon_No_Meas_Devider (1.0/IV_Temp_Bias_Mon_No_Meas) //average divider

//	IV_Mode:
//		Bit0:	IV_Mode__Cos_Sweep
			#define SET__IV_Mode__Cos_Sweep (SETBIT(IV_Mode, 0))
			#define CLR__IV_Mode__Cos_Sweep (CLRBIT(IV_Mode, 0))
			#define is_IV_Mode__Cos_Sweep (IV_Mode & BIT(0))
//		Bit1:	IV_Mode__Asym_Volt
			#define SET__IV_Mode__Asym_Volt (SETBIT(IV_Mode, 1))
			#define CLR__IV_Mode__Asym_Volt (CLRBIT(IV_Mode, 1))
			#define is_IV_Mode__Asym_Volt (IV_Mode & BIT(1))
//		Bit2:	IV_Mode__Reverse
			#define SET__IV_Mode__Reverse (SETBIT(IV_Mode, 2))
			#define CLR__IV_Mode__Reverse (CLRBIT(IV_Mode, 2))
			#define is_IV_Mode__Reverse (IV_Mode & BIT(2))
//		Bit3:	none
//		Bit4:	none
//		Bit5:	none
//		Bit6:	none
//		Bit7:	none

//	IV_Report:
//		Bit0:	IV_Report_OverCurr_Bypass_Active
			#define SET__IV_Report_OverCurr_Bypass_Active (SETBIT(IV_Report, 0))
			#define CLR__IV_Report_OverCurr_Bypass_Active (CLRBIT(IV_Report, 0))
//		Bit1:	IV_Report_OverTemp_Active
			#define SET__IV_Report_OverTemp_Active (SETBIT(IV_Report, 1))
			#define CLR__IV_Report_OverTemp_Active (CLRBIT(IV_Report, 1))
//		Bit2:	IV_Report_BiasVolt_Fault
			#define SET__IV_Report_BiasVolt_Fault (SETBIT(IV_Report, 2))
			#define CLR__IV_Report_BiasVolt_Fault (CLRBIT(IV_Report, 2))
//		Bit3:	none
//		Bit4:	IV_Report_Volt_AI_Over_Load
			#define SET__IV_Report_Volt_Over_Load (SETBIT(IV_Report, 4))
			#define CLR__IV_Report_Volt_Over_Load (CLRBIT(IV_Report, 4))
//		Bit5:	IV_Report_Volt_AI_Under_R
			#define SET__IV_Report_Volt_Under_Load (SETBIT(IV_Report, 5))
			#define CLR__IV_Report_Volt_Under_Load (CLRBIT(IV_Report, 5))
//		Bit6:	IV_Report_Curr_AI_Over_R
			#define SET__IV_Report_Curr_Over_Load (SETBIT(IV_Report, 6))
			#define CLR__IV_Report_Curr_Over_Load (CLRBIT(IV_Report, 6))
//		Bit7:	IV_Report_Curr_AI_Under_R
			#define SET__IV_Report_Curr_Under_Load (SETBIT(IV_Report, 7))
			#define CLR__IV_Report_Curr_Under_Load (CLRBIT(IV_Report, 7))

//===========================================================================================
// EXTERN VARIABLES and STRUCTURES

//Transient measurement variables
extern volatile float PV_Volt_Trs;
extern volatile float Trs_Delay_us;
extern volatile float Trs_Meas_Time_us;
extern volatile float Trs_Delay_Res_us;

// IV measurements variables
extern volatile uint8_t IV_Mode;
extern volatile uint8_t IV_Meas_Points;
extern volatile float IV_Voc_Overshoot_Fact;
extern volatile float IV_Cos_Max_Phase;
extern volatile uint16_t IV_Point_Set_Delay_ms;
extern volatile uint16_t IV_Setup_Signal_Set_Time;
extern volatile uint8_t IV_Point_Meas_Nu_AVR_Sets;
extern volatile uint8_t IV_Point_Meas_Nu_AVR_VoltCurr;
extern volatile uint8_t IV_Report;
extern volatile float PV_IV_Current[MAX_IV_POINTS];
extern volatile float PV_IV_Voltage[MAX_IV_POINTS];

//===========================================================================================
// EXTERN EEPROM VARIABLES
extern EEMEM uint8_t EROM_IV_Meas_Points;
extern EEMEM uint8_t EROM_IV_Mode;
extern EEMEM float EROM_IV_Cos_Max_Phase;
extern EEMEM float EROM_IV_Voc_Overshoot_Fact;
extern EEMEM uint16_t EROM_IV_Point_Set_Delay_ms;
extern EEMEM uint8_t EROM_IV_Point_Meas_Nu_AVR_Sets;
extern EEMEM uint8_t EROM_IV_Point_Meas_Nu_AVR_VoltCurr;

//===========================================================================================
// FUNCTION Prototypes
void PV_IV_MEAS();
void PV_TRANS_MEAS();
float IV_MEAS__Get_Voc_Set_Optimum_Range();
void IV_MEAS__Get_Curr_Optimum_Range();
void IV_MEAS__Meas_Curr_Volt_Point(float Volt_AVR_Mult, float Curr_AVR_Mult);
float get_DAC_Volt_at_Pmax_from_IV();
bool meas_NTC1_Temp_control_fan_over_Temp();
bool meas_NTC2_Temp_control_fan_over_Temp();
void meas_Bias_Volt_Range_Check();


#endif /* MPPT_PCB_MCU__IV_TRANS_H_ */