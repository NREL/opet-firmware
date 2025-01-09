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
	        EEPROM IO Header FILE
	=========================================
*/

#ifndef MPPT_PCB_MCU__EROM_H_
#define MPPT_PCB_MCU__EROM_H_

//===========================================================================================
// Definitions and constants
#define EEPROM_ADR_LENGH 5		// Address length of EEPROM
#define EEMEM_WRITE_VALUE 165 	// Value testing EEMEM written & valid

//===========================================================================================
// EXTERN VARIABLES and STRUCTURES
extern EEMEM float TEST_FLOAT;
extern EEMEM uint8_t TEST_UINT8;

//===========================================================================================
// FUNCTION Prototypes
void COM_EROM_ACCESS_FLOAT(float * EromVariable, uint8_t Write, char *ValueString, char *ReplyString);
void COM_EROM_ACCESS_UINT8(uint8_t * EromVariable, uint8_t Write, char *ValueString, char *ReplyString);
void COM_EROM_ACCESS_UINT16(uint16_t * EromVariable, uint8_t Write, char *ValueString, char *ReplyString);
void EEPROM_WRITE_FLOAT(float value, float * EEMEMvariable);
float EEPROM_READ_FLOAT(float * EEMEMvariable);
void EEPROM_WRITE_UINT8(uint8_t value, uint8_t * EEMEMvariable);
uint8_t EEPROM_READ_UINT8(uint8_t * EEMEMvariable);
void EEPROM_WRITE_INT16(int16_t value,int16_t * EEMEMvariable);
int16_t EEPROM_READ_INT16(int16_t * EEMEMvariable);
void EEPROM_WRITE_UINT16(uint16_t value,uint16_t * EEMEMvariable);
uint16_t EEPROM_READ_UINT16(uint16_t * EEMEMvariable);
void EEPROM_WRITE_INT32(int32_t value,int32_t * EEMEMvariable);
int32_t EEPROM_READ_INT32(int32_t * EEMEMvariable);
void EEPROM_WRITE_STRING(char * Value,char * EEMEMvariable,uint8_t Length);
void EEPROM_READ_STRING(volatile char * ReturnVar, char * EEMEMvariable, uint8_t Length);
void EEPROM_ACCESS_UART(char * EEPROM_Command, uint8_t EEPROM_Write);
void EEPROM_LOAD_VAL_CONFIG();
uint16_t EEROM_LOAD_TIMER_1_CM ();
void EEPROM_LOAD_VOLTAGE_RANGE(uint8_t Range_ID);
void EEPROM_LOAD_CURRENT_RANGE(uint8_t Range_ID);
void EEPROM_Range_Cal_Set_Scale(float Scale);
void EEPROM_Range_Cal_Set_Offset(float Scale);
float EEPROM_Range_Cal_Get_Scale();
float EEPROM_Range_Cal_Get_Offset();

// end
#endif /* MPPT_PCB_MCU__EROM_H_ */
