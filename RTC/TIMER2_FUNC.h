#ifndef TIMER2_FUNC.h
#define TIMER2_FUNC.h
#include "TIMER2_INTERFACE.h"
/*____________________________*/

void TIMER2_INIT(uint_8 MODE,uint_8 CLOCK);			//-->TIMER/COUNTER2_CLCOK_SOURCE_AND_MODE
/*__________________________________________________*/

void TIMER2_INTERRUPT(uint_8 STATE);				//-->TIMER/COUNTER2_INTERRUPT_STATE
/*__________________________________________________*/

uint_8 TIMER2_FLAG_READ(uint_8 FLAG);					//-->TIMER/COUNTER2_READ_FLAGS
/*__________________________________________________*/
	
void TIMER2_OCR2_WRITE(uint_8 VALUE);				//-->TIMER/COUNTER2_WRITE_ON_OCR2
/*__________________________________________________*/

void TIMER2_TCNT2_WRITE(uint_8 VALUE);				//-->TIMER/COUNTER2_WRITE_ON_TCNT2
/*__________________________________________________*/

void TIMER2_FOC2_PULSE(void);						//-->TIMER/COUNTER2_FORCE_CMP_PULSE
/*__________________________________________________*/

void TIMER2_CTC_OUTPUT_CLOCK(uint_8 CASE);			//-->TIMER/COUNTER2_CTC_WAVE
/*__________________________________________________*/

void TIMER2_FAST_PWM_OUTPUT_CLOCK(uint_8 CASE);		//-->TIMER/COUNTER2_FAST_PWM_WAVE
/*__________________________________________________*/

void TIMER2_PHC_PWM_OUTPUT_CLOCK(uint_8 CASE);		//-->TIMER/COUNTER2_PHC_PWM_WAVE
/*__________________________________________________*/

void TIMER2_CLOCK_MUX_MODE(uint_8 MODE);			//-->TIMER/COUNTER2_CHOOSE_CLOCK_SOURCE
/*__________________________________________________*/ 

void TIMER2_INTERRUPT_DISABLE(void);				//-->TIMER/COUNTER2_DISABLE_INTERRUPT

#endif