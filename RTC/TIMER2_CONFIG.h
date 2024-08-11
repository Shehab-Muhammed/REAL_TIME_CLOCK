#ifndef TIMER2_CONFIG.h
#define TIMER2_CONFIG.h
/*_______________________*/

#define TIMER2_NO_CLOCK					0
#define TIEMR2_MC_CLOCK					1	
#define TIMER2_P8_CLOCK					2		/*******************************/
#define TIMER2_P32_CLOCK				3		/*******TIMER2_CLOCK************/
#define TIEMR2_P64_CLOCK				4		/*******TIMER2_CLOCK************/
#define TIMER2_P128_CLOCK				5		/*******TIMER2_CLOCK************/
#define TIMER2_P256_CLOCK				6		/*******************************/
#define TIMER2_P1024_CLOCK				7
/*______________________________*/

#define TIMER2_NORMAL					0		/*******************************/
#define TIMER2_CTC						1		/*********TIMER2_MODE***********/
#define TIMER2_FAST_PWM					2		/*******************************/
#define TIMER2_PHC_PWM					3
/*______________________________*/

#define TIMER2_OVF_INT_ENABLE			0		/*****INTERRUPT_SOURCE_ENABLE******/
#define	TIMER2_CMP_INT_ENABLE			1		/*****INTERRUPT_SOURCE_ENABLE******/
/*______________________________*/

#define CTC_NORMAL_OC2					0		/*******************************/
#define CTC_TOGGLE_OC2					1		/****CTC_WAVE_MODE******/
#define CTC_CLEAR_OC2					2		/****CTC_WAVE_MODE******/
#define CTC_SET_OC2						3		/*******************************/

/*______________________________*/

#define FAST_PWM_NORMAL_OC2				0		/*******************************/
#define FAST_PWM_RESERVED_OC2			1		/****FAST_PWM_WAVE_MODE******/
#define FAST_PWM_NON_INVERTING_OC2		2		/****FAST_PWM_WAVE_MODE******/
#define FAST_PWM_INVERTING_OC2			3		/*******************************/

/*______________________________*/

#define PHC_PWM_NORMAL_OC2				0		/*******************************/
#define PHC_PWM_RESERVED_OC2			1		/****PHC_PWM_WAVE_MODE******/
#define PHC_PWM_CLEAR_SET_OC2			2		/****PHC_PWM_WAVE_MODE******/
#define PHC_PWM_SET_CLEAR_OC2			3		/*******************************/
/*______________________________*/

#define MC_MUX_CLOCK					0		/*******ASYN_MUX*******/
#define EXTERNAL_MUX_CLOCK				1		/*******ASYN_MUX*******/
#endif