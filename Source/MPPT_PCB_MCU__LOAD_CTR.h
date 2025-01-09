/* 
	-----------------------------------------
	MPPT PCB MCU source
	-----------------------------------------
	Made by:	Martin Bliss
	Version:	1.00
	Date:		07.09.2021
	-----------------------------------------
	ATMega 324 Micro controller support
	-----------------------------------------
	   Load Control header file
	=========================================
*/

#ifndef MPPT_PCB_MCU__LOAD_CTR_H_
#define MPPT_PCB_MCU__LOAD_CTR_H_

//===========================================================================================
// Definitions and constants
#define NAME_LENGTH 21
#define BIAS_VOLT_ERROR_TIMEOUT_MAX 200 // counter max dependent on load control loop time -> 200 @ 0.025s = 5s timeout
#define BIAS_VOLT_ERROR_DELAY_MAX 20 // counter max dependent on load control loop time -> 200 @ 0.025s = 0.5s timeout
#define FAN_RELAY_SWITCH_TIME_MS 5

// PV mode definitions ( 0 is uninitialized)
#define PV_Mode__NONE			0
#define PV_Mode__VOC			1
#define PV_Mode__ISC			2
#define PV_Mode__Const_Volt		3
#define PV_Mode__Const_Curr		4
#define PV_Mode__MPPT_Simple	5

//----------------------------------------
//	Track_Status:
//		Bit0:	Direction voltage Up
				#define SET__Track_Status_Dir_Volt_Up (SETBIT(Track_Status, 0))
				#define CLR__Track_Status_Dir_Volt_Up (CLRBIT(Track_Status, 0))
				#define is_Track_Status_Dir_Volt_Up ((Track_Status & BIT(0)))
//		Bit1:	none
//		Bit2:	none
//		Bit3:	none
//		Bit4:	none
//		Bit5:	none
//		Bit6:	none
//		Bit7:	New IV curve data ready
				#define SET__Track_Status_new_IV_curve (SETBIT(Track_Status, 7))
				#define CLR__Track_Status_new_IV_curve (CLRBIT(Track_Status, 7))
				#define is_Track_Status_new_IV_curve (Track_Status & BIT(7))
				
//----------------------------------------
//	FAN_CTR_State:
//		Bit0:	FAN is enabled?
			#define SET__FAN_IS_ENABLED (SETBIT(FAN_CTR_State, 0))
			#define CLR__FAN_IS_ENABLED (CLRBIT(FAN_CTR_State, 0))
			#define is_FAN_IS_ENABLED ((FAN_CTR_State & BIT(0)))
//		Bit1:	FAN enabled request
			#define SET__FAN_ENABLED_Request (SETBIT(FAN_CTR_State, 1))
			#define CLR__FAN_ENABLED_Request (CLRBIT(FAN_CTR_State, 1))
			#define is_FAN_ENABLED_Request ((FAN_CTR_State & BIT(1)))
//		Bit2:	none
//		Bit3:	none
//		Bit4:	none
//		Bit5:	none
//		Bit6:	none
//		Bit7:	FAN manual mode
			#define SET__FAN_MAN_Mode (SETBIT(FAN_CTR_State, 7))
			#define CLR__FAN_MAN_Mode (CLRBIT(FAN_CTR_State, 7))
			#define is_FAN_MAN_Mode (FAN_CTR_State & BIT(7))

//===========================================================================================
// EXTERN VARIABLES and STRUCTURES

extern volatile int32_t F_CPU_CAL;
extern volatile char Sample_Name[NAME_LENGTH];

// Load control Variables
extern volatile uint8_t PV_Mode_CTR;
extern volatile uint8_t PV_Mode_ACT;

// Output Voltage Control Variables
extern volatile float PV_Volt_Setpoint;
extern volatile float PV_Volt_DAQ_New;
extern volatile float PV_Volt_DAC_ACT;

// Output current/mppt control variables
extern volatile float PV_Curr_Setpoint;
extern volatile uint8_t Track_Status;
extern volatile float LOAD_MPPT_Max_Step_CND;
extern volatile float LOAD_MPPT_Min_Step_CND;
extern volatile float LOAD_MPPT_Step_Increase_Fact;
extern volatile float LOAD_MPPT_Step_Reduction_Fact;
extern volatile float LOAD_MPPT_Tolerance_CND;
extern volatile uint16_t LOAD_MPPT_Timer_Update_Delay;
extern volatile float LOAD_CurrT_Max_Step_CND;
extern volatile float LOAD_CurrT_Min_Step_CND;
extern volatile float LOAD_CurrT_Step_Increase_Fact;
extern volatile float LOAD_CurrT_Step_Reduction_Fact;
extern volatile float LOAD_CurrT_Tolerance_CND;

// Fan control variables
extern volatile uint8_t FAN_CTR_State;
extern volatile float FAN_NTC1_T_On;
extern volatile float FAN_NTC1_T_Off;
extern volatile float FAN_NTC2_T_On;
extern volatile float FAN_NTC2_T_Off;
extern volatile float FAN_Power_On;
extern volatile float FAN_Power_Off;
extern volatile uint16_t FAN_Switch_Counter;
extern volatile uint16_t FAN_Switch_Timer_Max;

// Temperature limit variables
extern volatile float Temp_NTC1_MIN_DisCon;
extern volatile float Temp_NTC1_MAX_DisCon;
extern volatile float Temp_NTC1_MIN_ReCon;
extern volatile float Temp_NTC1_MAX_ReCon;
extern volatile float Temp_NTC2_MIN_DisCon;
extern volatile float Temp_NTC2_MAX_DisCon;
extern volatile float Temp_NTC2_MIN_ReCon;
extern volatile float Temp_NTC2_MAX_ReCon;

// Bias Voltage Limit variables
volatile float BiasV_Range_Min;
volatile float BiasV_Range_Max;

//===========================================================================================
// EXTERN EEPROM VARIABLES

extern EEMEM int32_t EROM_F_CPU_CAL;
extern EEMEM char EROM_Sample_Name[NAME_LENGTH];
extern EEMEM float EROM_Temp_NTC1_MIN_DisCon;
extern EEMEM float EROM_Temp_NTC1_MAX_DisCon;
extern EEMEM float EROM_Temp_NTC1_MIN_ReCon;
extern EEMEM float EROM_Temp_NTC1_MAX_ReCon;
extern EEMEM float EROM_Temp_NTC2_MIN_DisCon;
extern EEMEM float EROM_Temp_NTC2_MAX_DisCon;
extern EEMEM float EROM_Temp_NTC2_MIN_ReCon;
extern EEMEM float EROM_Temp_NTC2_MAX_ReCon;
extern EEMEM float EROM_BiasV_Range_Min;
extern EEMEM float EROM_BiasV_Range_Max;
extern EEMEM float EROM_LOAD_MPPT_Max_Step_CND;
extern EEMEM float EROM_LOAD_MPPT_Min_Step_CND;
extern EEMEM float EROM_LOAD_MPPT_Step_Increase_Fact;
extern EEMEM float EROM_LOAD_MPPT_Step_Reduction_Fact;
extern EEMEM float EROM_LOAD_MPPT_Tolerance_CND;
extern EEMEM uint16_t EROM_LOAD_MPPT_Timer_Update_Delay;
extern EEMEM float EROM_LOAD_CurrT_Max_Step_CND;
extern EEMEM float EROM_LOAD_CurrT_Min_Step_CND;
extern EEMEM float EROM_LOAD_CurrT_Step_Increase_Fact;
extern EEMEM float EROM_LOAD_CurrT_Step_Reduction_Fact;
extern EEMEM float EROM_LOAD_CurrT_Tolerance_CND;
extern EEMEM uint8_t EROM_PV_Mode_CTR;
extern EEMEM float EROM_PV_Volt_Setpoint;
extern EEMEM float EROM_PV_Curr_Setpoint;
extern EEMEM uint8_t EROM_FAN_CTR_Mode;
extern EEMEM float EROM_FAN_NTC1_T_ON;
extern EEMEM float EROM_FAN_NTC1_T_OFF;
extern EEMEM float EROM_FAN_NTC2_T_ON;
extern EEMEM float EROM_FAN_NTC2_T_OFF;
extern EEMEM float EROM_FAN_Power_ON;
extern EEMEM float EROM_FAN_Power_OFF;
extern EEMEM uint16_t EROM_FAN_Switch_Timer_Max;


//===========================================================================================
// FUNCTION Prototypes
void LOAD_CTR_MAIN();
void Process_Operating_Temperature_State();
void Process_Bias_Voltage_State();
void Process_Fan_Control();
void Reset_Fan_Control();
void Process_Error_LED_State();
bool Check_if_Active_Errors_Output_Disabled();
bool Check_Temp_Disconnect_State();
void PV_Mode__Constant_Current_Main();
void PV_Mode__Constant_Current_Init();
void PV_Mode__MPPT_Simple_Main();
void PV_Mode__MPPT_Simple_Init();

//end
#endif /* MPPT_PCB_MCU__LOAD_CTR_H_ */