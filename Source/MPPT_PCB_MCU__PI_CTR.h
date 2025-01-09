/* 
	-----------------------------------------
	MPPT PCB MCU source
	-----------------------------------------
	Made by:	Martin Bliss
	Version:	1.00
	Date:		07.09.2021
	-----------------------------------------
	ATMega 128 Micro controller support
	-----------------------------------------
	   PI controller header file
	=========================================
*/

#ifndef MPPT_PCB_MCU__PI_CTR_H_
#define MPPT_PCB_MCU__PI_CTR_H_

//===========================================================================================
// Definitions and constants
#define PI_CTR_PROP_ID_MAX 3
#define PI_CTR_INT_ID_MAX 3

//===========================================================================================
// EXTERN VARIABLES and STRUCTURES

// PI controller config variables
extern volatile uint8_t PI_CTR_Prop_ID_Act;
extern volatile uint8_t PI_CTR_Prop_ID_Man;
extern volatile uint8_t PI_CTR_Int_ID_Act;
extern volatile uint8_t PI_CTR_Int_ID_Man;


//===========================================================================================
// EXTERN EEPROM VARIABLES

extern EEMEM uint8_t EROM_PI_CTR_Prop_ID;
extern EEMEM uint8_t EROM_PI_CTR_Int_ID;


//===========================================================================================
// FUNCTION Prototypes
void PI_CRT__Process_Controller_Settings();
void PI_CTR__Set_New_Prop_ID(uint8_t Prop_ID);
void PI_CTR__Set_New_Int_ID(uint8_t Int_ID);


//end
#endif /*MPPT_PCB_MCU__PI_CTR_H_ */