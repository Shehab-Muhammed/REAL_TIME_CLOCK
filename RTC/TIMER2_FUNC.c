#include "TIMER2_FUNC.h"
/*____________________________*/


/*______________________________________________________________*/
/*______________________________________________________________*/
/*______________________________________________________________*/

void TIMER2_INIT(uint_8 MODE,uint_8 CLOCK)
{
/********************************************************/
		switch(MODE)
		{
			case TIMER2_NORMAL:
			CLEAR_BIT(TCCR2,WGM20);
			CLEAR_BIT(TCCR2,WGM21);
			break;
		
			case TIMER2_PHC_PWM:
			SET_BIT(TCCR2,WGM20);
			CLEAR_BIT(TCCR2,WGM21);
			break;
			
			case TIMER2_CTC:
			CLEAR_BIT(TCCR2,WGM20);
			SET_BIT(TCCR2,WGM21);
			break;
		
			case TIMER2_FAST_PWM:
			SET_BIT(TCCR2,WGM20);
			SET_BIT(TCCR2,WGM21);
			break;	
		}
/********************************************************/

		switch(CLOCK)		
		{
			case TIMER2_NO_CLOCK: //-->000
			CLEAR_BIT(TCCR2,CS20);
			CLEAR_BIT(TCCR2,CS21);
			CLEAR_BIT(TCCR2,CS22);
			break;
		/*_______________________________________*///TIMER2_OFF	
			case TIEMR2_MC_CLOCK://-->001
			SET_BIT(TCCR2,CS20);
			CLEAR_BIT(TCCR2,CS21);
			CLEAR_BIT(TCCR2,CS22);
			break;
		/*_______________________________________*///TIMER2_MC_CLOCK
			case TIMER2_P8_CLOCK://-->010
			CLEAR_BIT(TCCR2,CS20);
			SET_BIT(TCCR2,CS21);
			CLEAR_BIT(TCCR2,CS22);
			break;
		/*_______________________________________*///TIMER2_PRESCALED_CLOCK_8
			case TIMER2_P32_CLOCK://-->011
			SET_BIT(TCCR2,CS20);
			SET_BIT(TCCR2,CS21);
			CLEAR_BIT(TCCR2,CS22);
			break;
		/*_______________________________________*///TIMER2_PRESCALED_CLOCK_32
			case TIEMR2_P64_CLOCK://-->100
			CLEAR_BIT(TCCR2,CS20);
			CLEAR_BIT(TCCR2,CS21);
			SET_BIT(TCCR2,CS22);
			break;
		/*_______________________________________*///TIMER2_PRESCALED_CLOCK_64
			case TIMER2_P128_CLOCK://-->101
			SET_BIT(TCCR2,CS20);
			CLEAR_BIT(TCCR2,CS21);
			SET_BIT(TCCR2,CS22);
			break;
		/*_______________________________________*///TIMER2_PRESCALED_CLOCK_128	
			case TIMER2_P256_CLOCK://-->110
			CLEAR_BIT(TCCR2,CS20);
			SET_BIT(TCCR2,CS21);
			SET_BIT(TCCR2,CS22);
			break;
		/*_______________________________________*///TIMER2_PRESCALED_CLOCK_256
			case TIMER2_P1024_CLOCK://-->111
			SET_BIT(TCCR2,CS20);
			SET_BIT(TCCR2,CS21);
			SET_BIT(TCCR2,CS22);
			break;
		/*_______________________________________*///TIMER2_PRESCALED_CLOCK_1024
		}
/********************************************************/
}
/*______________________________________________________________*/
/*______________________________________________________________*/
/*______________________________________________________________*/


void TIMER2_INTERRUPT(uint_8 STATE)
{
		SET_BIT(STATUS_REG,GLOBAL_INTERRUPT);
		switch(STATE)
		{
			case TIMER2_OVF_INT_ENABLE:
			SET_BIT(TIMSK,TOIE2);//ISR(TIMER2_OVF_vect){}
			break;
			
			case TIMER2_CMP_INT_ENABLE:
			SET_BIT(TIMSK,OCIE2);//ISR(TIMER2_COMP_vect){}
			break;
		}
}

void TIMER2_INTERRUPT_DISABLE(void)
{
	CLEAR_BIT(STATUS_REG,GLOBAL_INTERRUPT);
	CLEAR_BIT(TIMSK,TOIE2);
	CLEAR_BIT(TIMSK,OCIE2);
}
/*______________________________________________________________*/
/*______________________________________________________________*/
/*______________________________________________________________*/


uint_8 TIMER2_FLAG_READ(uint_8 FLAG)
{
	uint_8 state;
	switch(FLAG)
	{
		case TOV2:
		state=READ_BIT(TIFR,TOV2);
		break;
		
		case OCF2:
		state=READ_BIT(TIFR,OCF2);
		break;
	}
	return state;
}
/*______________________________________________________________*/
/*______________________________________________________________*/
/*______________________________________________________________*/

void TIMER2_OCR2_WRITE(uint_8 VALUE)
{
	if((VALUE<256) && (VALUE>=0))
	{
		OCR2=VALUE;
	}
}
/*______________________________________________________________*/
/*______________________________________________________________*/
/*______________________________________________________________*/

void TIMER2_TCNT2_WRITE(uint_8 VALUE)
{
	if((VALUE<256) && (VALUE>=0))
	{
		TCNT2=VALUE;
	}
}
/*______________________________________________________________*/
/*______________________________________________________________*/
/*______________________________________________________________*/


void TIMER2_FOC2_PULSE(void)
{
	SET_BIT(TCCR2,FOC2);
}

/*______________________________________________________________*/
/*______________________________________________________________*/
/*______________________________________________________________*/


void TIMER2_CTC_OUTPUT_CLOCK(uint_8 CASE)
{
		DIO_SET_PIN_DIRECTION('D',7,PIN_OUTPUT);
		switch(CASE)
		{
			case CTC_NORMAL_OC2: //-->00
			CLEAR_BIT(TCCR2,COM20);
			CLEAR_BIT(TCCR2,COM21);
			break;
		
			case CTC_TOGGLE_OC2://-->01
			SET_BIT(TCCR2,COM20);
			CLEAR_BIT(TCCR2,COM21);
			break;
		
			case CTC_CLEAR_OC2://-->10
			CLEAR_BIT(TCCR2,COM20);
			SET_BIT(TCCR2,COM21);
			break;
		
			case CTC_SET_OC2://-->11
			SET_BIT(TCCR2,COM20);
			SET_BIT(TCCR2,COM21);
			break;
		
		
		}
}
/*______________________________________________________________*/
/*______________________________________________________________*/
/*______________________________________________________________*/


void TIMER2_FAST_PWM_OUTPUT_CLOCK(uint_8 CASE)
{
		DIO_SET_PIN_DIRECTION('D',7,PIN_OUTPUT);
		switch(CASE)
		{
			case FAST_PWM_NORMAL_OC2: //-->00
			CLEAR_BIT(TCCR2,COM20);
			CLEAR_BIT(TCCR2,COM21);
			break;
		
			case FAST_PWM_RESERVED_OC2://-->01
			SET_BIT(TCCR2,COM20);
			CLEAR_BIT(TCCR2,COM21);
			break;
		
			case FAST_PWM_NON_INVERTING_OC2://-->10
			CLEAR_BIT(TCCR2,COM20);
			SET_BIT(TCCR2,COM21);
			break;
		
			case FAST_PWM_INVERTING_OC2://-->11
			SET_BIT(TCCR2,COM20);
			SET_BIT(TCCR2,COM21);
			break;

		}
}

/*______________________________________________________________*/
/*______________________________________________________________*/
/*______________________________________________________________*/


void TIMER2_PHC_PWM_OUTPUT_CLOCK(uint_8 CASE)
{
		DIO_SET_PIN_DIRECTION('D',7,PIN_OUTPUT);
		switch(CASE)
		{
			case PHC_PWM_NORMAL_OC2: //-->00
			CLEAR_BIT(TCCR2,COM20);
			CLEAR_BIT(TCCR2,COM21);
			break;
			
			case PHC_PWM_RESERVED_OC2://-->01
			SET_BIT(TCCR2,COM20);
			CLEAR_BIT(TCCR2,COM21);
			break;
			
			case PHC_PWM_CLEAR_SET_OC2://-->10
			CLEAR_BIT(TCCR2,COM20);
			SET_BIT(TCCR2,COM21);
			break;
			
			case PHC_PWM_SET_CLEAR_OC2://-->11
			SET_BIT(TCCR2,COM20);
			SET_BIT(TCCR2,COM21);
			break;

		}
		
}

/*______________________________________________________________*/
/*______________________________________________________________*/
/*______________________________________________________________*/


void TIMER2_CLOCK_MUX_MODE(uint_8 MODE)
{
	switch(MODE)
	{
		case MC_MUX_CLOCK:
		CLEAR_BIT(ASSR,AS2);
		break;
		
		case EXTERNAL_MUX_CLOCK:
		SET_BIT(ASSR,AS2);
		break;
	}
}

/*______________________________________________________________*/
/*______________________________________________________________*/
/*______________________________________________________________*/