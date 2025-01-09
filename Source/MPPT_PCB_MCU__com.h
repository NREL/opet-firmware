/* 
	-----------------------------------------
	MPPT PCB MCU source
	-----------------------------------------
	Made by:	Martin Bliss
	Version:	1.00
	Date:		10.12.2023
	-----------------------------------------
	ATMega 324 Micro controller support
	-----------------------------------------
	      Communication Header FILE
	=========================================
*/

#ifndef MPPT_PCB_MCU__Com_H_
#define MPPT_PCB_MCU__Com_H_

//===========================================================================================
// Definitions and constants

#define UART_UBRR_CALC(BAUD_,FREQ_) ((FREQ_)/((BAUD_)*16L)-1)
#define UART_BAUD_RATE 200000 //250000	//38400  //125000 //38400 //19200
#define UART_TERM_CHAR 0x0A			// <Line Feed>
#define UART_SEP_CHAR 0x09			// <Tap>
#define UART_COM_LENGH 121
#define UART_ADDRESS_LENGH 21
#define UART_Value_LENGH 101
#define UART_ASCII_ADR_OFFSET 64	// @ = 0, A = 1, ...
#define UART_ADR_SEP_CHAR 0x23		// # - character separating address and command
#define UART_COM_SEP_CHAR 0x3A		// : - character separating command sections
#define UART_COM_READ_INDICATOR 0x3F	// ? - indicates value read back

//===========================================================================================
// VARIABLES and STRUCTURES
extern volatile char UART_In_Buff[UART_COM_LENGH+1];
extern volatile uint8_t UART_In_Buff_L;
extern volatile char UART_Comand[UART_COM_LENGH+1] ;
extern volatile uint8_t UART_Comand_L;
extern volatile char OutSTR[UART_COM_LENGH+1];			// command reply buffer (not in transfer)
extern volatile char UART_Reply[UART_COM_LENGH+1];
extern volatile uint8_t UART_Reply_P;
extern volatile uint8_t UART_Reply_L;
extern volatile uint8_t Com_ID;
extern volatile uint8_t Trans_IV_Point;

//===========================================================================================
// EXTERN EEPROM VARIABLES


//===========================================================================================
// FUNCTION Prototypes
void UART_WriteString (volatile char *STR);
void UART_WriteChar(char c);
void UART_Process_Input ();
void UART_Execute_Command();

bool COM_Compare_to_OutStr(char *ComandSTR);
bool COM_Compare_to_OutStr_Offset(char *ComandSTR, uint8_t Offset);
void COM_Copy_To_OutSTR_From_Start(char *CopySTR);
void COM_Add_To_OutSTR_No_Sep(char *CopySTR);
void COM_Add_To_OutSTR_with_Sep(volatile char *AddSTR);
void COM_Add_To_OutSTR_At_Position(char *CopySTR, uint8_t Position);
void COM_Add_QuestMark_To_OutSTR_No_Sep();

uint8_t Compare_String(char *STR1, volatile char *STR2, uint8_t Length);
void Copy_String(volatile char *CopSTR, char *OrigSTR);
void Concentrate_String(char *STR1, char *STR2, volatile char *ConSTR);

void AddEnd_String(volatile char *ConSTR, volatile char *AddSTR);
void AddEnd_String_with_Separation(volatile char *ConSTR, volatile char *AddSTR);
void FloatToString(char *STR, float Value);
float StringToFloat(char *STR);
void UART_Transfer_IV();


//end
#endif /* MPPT_PCB_MCU__Com_H_ */