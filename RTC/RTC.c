#include "SEVEN_SEGMENT_FUNC.h"
#include "TIMER2_FUNC.h"
#include "LCD_INTERFACE.h"
#include "KEYPAD_FUNC.h"
#include <avr/interrupt.h>
volatile uint_8 SECOND_COUNTER=0;
uint_8	MINUTE_COUNTER=0;
uint_8	HOUR_COUNTER=0;
uint_8 VAL,FIRST_DIGIT,SECOND_DIGIT;
int main(void)
{

/*___________________________________________________________________*/
/*___________________________________________________________________*/
	LCD_4_BIT_INIT(HIGH_NIPPLE);
	SEVEN_SEG_HIGH_NIPPLE_INIT(SEVEN_SEG_PORT);
	KEYPAD_INIT();
	
	DIO_SET_PIN_DIRECTION(SEVEN_SEG_PORT,0,PIN_OUTPUT);
	DIO_SET_PIN_DIRECTION(SEVEN_SEG_PORT,1,PIN_OUTPUT);
	DIO_SET_PIN_DIRECTION(SEVEN_SEG_PORT,2,PIN_OUTPUT);
	
	MOVE_CURSOR_4_BIT(1,2);
	LCD_WRITE_STRING_4_BIT("PRESS 1 TO SET");
	
	TIMER2_INIT(TIMER2_NORMAL,TIMER2_P128_CLOCK);
	TIMER2_CLOCK_MUX_MODE(EXTERNAL_MUX_CLOCK);
	TIMER2_INTERRUPT(TIMER2_OVF_INT_ENABLE);
/*___________________________________________________________________*/
/*___________________________________________________________________*/
	
    while(1)
    {

		VAL=KEYPAD_READ();
		if(VAL!=NOT_PRESSED)
		{
			if(VAL=='1')
			{
				LCD_SEND_CMD_FOUR_BIT(0x01,HIGH_NIPPLE);
				MOVE_CURSOR_4_BIT(1,3);
				LCD_WRITE_STRING_4_BIT("HR : MIN : SEC");
				MOVE_CURSOR_4_BIT(2,3);
				LCD_WRITE_STRING_4_BIT("-- : --  : --");
				MOVE_CURSOR_4_BIT(2,3);
				_delay_ms(200);
				do 
				{
					SECOND_DIGIT=KEYPAD_READ();
				} while (SECOND_DIGIT==NOT_PRESSED);
				LCD_SEND_DATA_FOUR_BIT(SECOND_DIGIT,HIGH_NIPPLE);
				SECOND_DIGIT=SECOND_DIGIT-48;
			/*__________________________________*/	
				MOVE_CURSOR_4_BIT(2,4);
				_delay_ms(200);
				do
				{
					FIRST_DIGIT=KEYPAD_READ();
				} while (FIRST_DIGIT==NOT_PRESSED);
				LCD_SEND_DATA_FOUR_BIT(FIRST_DIGIT,HIGH_NIPPLE);
				FIRST_DIGIT=FIRST_DIGIT-48;
				HOUR_COUNTER=FIRST_DIGIT+SECOND_DIGIT*10;
				FIRST_DIGIT=NOT_PRESSED;
				SECOND_DIGIT=NOT_PRESSED;
			/*__________________________________*/	
				MOVE_CURSOR_4_BIT(2,8);
				_delay_ms(200);
				do 
				{
					SECOND_DIGIT=KEYPAD_READ();
				} while (SECOND_DIGIT==NOT_PRESSED);
				LCD_SEND_DATA_FOUR_BIT(SECOND_DIGIT,HIGH_NIPPLE);
				SECOND_DIGIT=SECOND_DIGIT-48;
			/*__________________________________*/	
				MOVE_CURSOR_4_BIT(2,9);
				_delay_ms(200);
				do 
				{
					FIRST_DIGIT=KEYPAD_READ();
				} while (FIRST_DIGIT==NOT_PRESSED);
				LCD_SEND_DATA_FOUR_BIT(FIRST_DIGIT,HIGH_NIPPLE);
				FIRST_DIGIT=FIRST_DIGIT-48;
				MINUTE_COUNTER=FIRST_DIGIT+SECOND_DIGIT*10;
				FIRST_DIGIT=NOT_PRESSED;
				SECOND_DIGIT=NOT_PRESSED;
			/*__________________________________*/
				MOVE_CURSOR_4_BIT(2,14);
				_delay_ms(200);
				do
				{
					SECOND_DIGIT=KEYPAD_READ();
				} while (SECOND_DIGIT==NOT_PRESSED);
				LCD_SEND_DATA_FOUR_BIT(SECOND_DIGIT,HIGH_NIPPLE);
				SECOND_DIGIT=SECOND_DIGIT-48;
			/*__________________________________*/
				MOVE_CURSOR_4_BIT(2,15);
				_delay_ms(200);
				do
				{
					FIRST_DIGIT=KEYPAD_READ();
				} while (FIRST_DIGIT==NOT_PRESSED);
				LCD_SEND_DATA_FOUR_BIT(FIRST_DIGIT,HIGH_NIPPLE);
				FIRST_DIGIT=FIRST_DIGIT-48;
				SECOND_COUNTER=FIRST_DIGIT+SECOND_DIGIT*10;
				FIRST_DIGIT=NOT_PRESSED;
				SECOND_DIGIT=NOT_PRESSED;
			/*__________________________________*/
			LCD_SEND_CMD_FOUR_BIT(0x01,HIGH_NIPPLE);
			MOVE_CURSOR_4_BIT(1,2);
			LCD_WRITE_STRING_4_BIT("PRESS 1 TO SET");
			}

		}

/*___________________________________________________________________*/
/*___________________________________________________________________*/
		DIO_PORT_PIN_WRITE(SEVEN_SEG_PORT,0,PIN_HIGH);//-->101
		DIO_PORT_PIN_WRITE(SEVEN_SEG_PORT,1,PIN_LOW);
		DIO_PORT_PIN_WRITE(SEVEN_SEG_PORT,2,PIN_HIGH);
		SEVEN_SEG_WRITE_NIPPLE(SEVEN_SEG_PORT,HIGH_NIPPLE,HOUR_COUNTER/10);
		_delay_ms(5);
		DIO_PORT_PIN_WRITE(SEVEN_SEG_PORT,0,PIN_LOW);//-->100
		DIO_PORT_PIN_WRITE(SEVEN_SEG_PORT,1,PIN_LOW);
		DIO_PORT_PIN_WRITE(SEVEN_SEG_PORT,2,PIN_HIGH);
		SEVEN_SEG_WRITE_NIPPLE(SEVEN_SEG_PORT,HIGH_NIPPLE,HOUR_COUNTER%10);
		_delay_ms(5);
		DIO_PORT_PIN_WRITE(SEVEN_SEG_PORT,0,PIN_HIGH);//-->011
		DIO_PORT_PIN_WRITE(SEVEN_SEG_PORT,1,PIN_HIGH);
		DIO_PORT_PIN_WRITE(SEVEN_SEG_PORT,2,PIN_LOW);
		SEVEN_SEG_WRITE_NIPPLE(SEVEN_SEG_PORT,HIGH_NIPPLE,MINUTE_COUNTER/10);
		_delay_ms(5);
		DIO_PORT_PIN_WRITE(SEVEN_SEG_PORT,0,PIN_LOW);//-->010
		DIO_PORT_PIN_WRITE(SEVEN_SEG_PORT,1,PIN_HIGH);
		DIO_PORT_PIN_WRITE(SEVEN_SEG_PORT,2,PIN_LOW);
		SEVEN_SEG_WRITE_NIPPLE(SEVEN_SEG_PORT,HIGH_NIPPLE,MINUTE_COUNTER%10);
		_delay_ms(5);
		DIO_PORT_PIN_WRITE(SEVEN_SEG_PORT,0,PIN_HIGH);//-->001
		DIO_PORT_PIN_WRITE(SEVEN_SEG_PORT,1,PIN_LOW);
		DIO_PORT_PIN_WRITE(SEVEN_SEG_PORT,2,PIN_LOW);
		SEVEN_SEG_WRITE_NIPPLE(SEVEN_SEG_PORT,HIGH_NIPPLE,SECOND_COUNTER/10);
		_delay_ms(5);
		DIO_PORT_PIN_WRITE(SEVEN_SEG_PORT,0,PIN_LOW);//-->000
		DIO_PORT_PIN_WRITE(SEVEN_SEG_PORT,1,PIN_LOW);
		DIO_PORT_PIN_WRITE(SEVEN_SEG_PORT,2,PIN_LOW);
		SEVEN_SEG_WRITE_NIPPLE(SEVEN_SEG_PORT,HIGH_NIPPLE,SECOND_COUNTER%10);
		_delay_ms(5);
		
/*___________________________________________________________________*/
/*___________________________________________________________________*/

			if(SECOND_COUNTER>=60)
				{
				MINUTE_COUNTER++;
				SECOND_COUNTER=0;
				}
			if(MINUTE_COUNTER>=60)
				{
				HOUR_COUNTER++;
				MINUTE_COUNTER=0;
				}
			if(HOUR_COUNTER==24)
				{
				HOUR_COUNTER=0;
				}			
    }
}

/*___________________________________________________________________*/
/*___________________________________________________________________*/
/*___________________________________________________________________*/

ISR(TIMER2_OVF_vect)
{
	SECOND_COUNTER++;
}
/*___________________________________________________________________*/
/*___________________________________________________________________*/
/*___________________________________________________________________*/