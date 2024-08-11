#ifndef TIMER2_INTERFACE.h
#define TIMER2_INTERFACE.h
#include "DIO_FUNC.h"
#include "TIMER2_CONFIG.h"
/*_____________________________________________________________________*/

#define TCNT2					*((volatile uint_8* )(0x44)) //-->TIMER/COUNTER2 REGISTER 
/*_____________________________________________________________________*/

#define OCR2					*((volatile uint_8* )(0x43))//-->TIMER/COUNTER2_COMP_REG
/*_____________________________________________________________________*/

#define OC2						7							/*******TIMER/COUNTER_OUTPUT_CLOCK*********/
/*_____________________________________________________________________*/

#define TCCR2					*((volatile uint_8* )(0x45)) //TIMER/COUNTER2_CONTROL_REG

#define FOC2					7							/******FORCE_CMP_TIMER2**********/

#define WGM20					6							/**********TIMER2_MODE*********/
#define WGM21					3							/**********TIMER2_MODE*********/

#define COM21					5							/**********OC2_CONTROL*************/
#define COM20					4							/**********OC2_CONTROL*************/

#define CS22					2							/********CLOCK_MODE*********/
#define CS21					1							/********CLOCK_MODE*********/
#define CS20					0							/********CLOCK_MODE*********/
/*_____________________________________________________________________*/

#define TIFR					*((volatile uint_8* )(0x58))//-->TIMER/COUNTER_FLAG_REG

#define OCF2					7							/*********TIMER/COUNTER2_CMP_FLAG********/
#define TOV2					6							/*********TIMER/COUNTER2_OVF_FLAG********/
/*_____________________________________________________________________*/ 

#define ASSR					*((volatile uint_8* )(0x42)) //-->TIMER/COUNTER2_ASYN_CONTROL

#define AS2						3							/*****INTERNAL/EXTRENAL_CLOCK******/
/*_____________________________________________________________________*/

#define TIMSK					*((volatile uint_8* )(0x59)) //-->TIMER/COUNTER2_INTERRUPTS_ENABLE

#define OCIE2					7							/****TIMER/COUNTER2_CMP_EN_INT*********/
#define TOIE2					6							/****TIMER/COUNTER2_OVF_EN_INT*********/
/*_____________________________________________________________________*/

#define STATUS_REG				*((volatile uint_8* )(0x5F)) //-->STATUS_REGISTER

#define GLOBAL_INTERRUPT		7							/*********I_BIT*******/
/*_____________________________________________________________________*/

#endif