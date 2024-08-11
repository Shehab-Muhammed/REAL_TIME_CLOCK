#include "KEYPAD_FUNC.h"
/*_________________________________________________*///BUTTON_READ///*_________________________________________________*/
/*_________________________________________________*///BUTTON_READ///*_________________________________________________*/
/*_________________________________________________*///BUTTON_READ///*_________________________________________________*/

uint_8	BUTTON_READ_STATE	(uint_8 port, uint_8 pin)
{
	uint_8 state;
	state = DIO_PIN_READ(port,pin);
	return state;
}
/*_________________________________________________*///BUTTON_READ///*_________________________________________________*/
/*_________________________________________________*///BUTTON_READ///*_________________________________________________*/
/*_________________________________________________*///BUTTON_READ///*_________________________________________________*/





/*_________________________________________________*///KEYPAD_INIT///*_________________________________________________*/
/*_________________________________________________*///KEYPAD_INIT///*_________________________________________________*/
/*_________________________________________________*///KEYPAD_INIT///*_________________________________________________*/

void KEYPAD_INIT(void)
{
	DIO_SET_PORT_DIRECTION(KEYPAD_PORT,0x0f);
	DIO_CONNECT_PULL_UP(KEYPAD_PORT,4,PULL_UP_ENABLE);
	DIO_CONNECT_PULL_UP(KEYPAD_PORT,5,PULL_UP_ENABLE);
	DIO_CONNECT_PULL_UP(KEYPAD_PORT,6,PULL_UP_ENABLE);
	DIO_CONNECT_PULL_UP(KEYPAD_PORT,7,PULL_UP_ENABLE);
}
/*_________________________________________________*///KEYPAD_INIT///*_________________________________________________*/
/*_________________________________________________*///KEYPAD_INIT///*_________________________________________________*/
/*_________________________________________________*///KEYPAD_INIT///*_________________________________________________*/





/*_________________________________________________*///KEYPAD_READ///*_________________________________________________*/
/*_________________________________________________*///KEYPAD_READ///*_________________________________________________*/
/*_________________________________________________*///KEYPAD_READ///*_________________________________________________*/


uint_8 KEYPAD_READ(void)
{
		uint_8 row,column,val=NOT_PRESSED;
		uint_8 arr[4][4]={{'7','8','9','+'},{'4','5','6','-'},{'1','2','3','/'},{'*','0','%','='}};
		for(row=0;row<=3;row++)
		{
			DIO_PORT_PIN_WRITE(KEYPAD_PORT,0,PIN_HIGH);		//*********************************************************//
			DIO_PORT_PIN_WRITE(KEYPAD_PORT,1,PIN_HIGH);		//*********************************************************//
			DIO_PORT_PIN_WRITE(KEYPAD_PORT,2,PIN_HIGH);		//****************KEYPAD_CONTROLLED_PINS*******************//
			DIO_PORT_PIN_WRITE(KEYPAD_PORT,3,PIN_HIGH);		//*********************************************************//
			DIO_PORT_PIN_WRITE(KEYPAD_PORT,row,PIN_LOW);	//********************************************************//
			
				for(column=0;column<=3;column++)
				{
					if(BUTTON_READ_STATE(KEYPAD_PORT,column+4)==0) //----> CHECK_INPUT_STATE	
					{
						val=arr[row][column];
						break;
					}	
				}
			if(val!=NOT_PRESSED)
			{
				break;
			}
			
		}
		return val;
}


/*_________________________________________________*///KEYPAD_READ///*_________________________________________________*/
/*_________________________________________________*///KEYPAD_READ///*_________________________________________________*/
/*_________________________________________________*///KEYPAD_READ///*_________________________________________________*/




/*_________________________________________________*///KEYPAD_RETURN_NUMBER///*________________________________________*/
/*_________________________________________________*///KEYPAD_RETURN_NUMBER///*________________________________________*/
/*_________________________________________________*///KEYPAD_RETURN_NUMBER///*________________________________________*/


uint_8		KEYPAD_PRESSED_NUM		(void)
{
	uint_8 num;
	num = KEYPAD_READ();
	if(num!=NOT_PRESSED)
	{
		return num-48;
	}
	
}
/*_________________________________________________*///KEYPAD_RETURN_NUMBER///*________________________________________*/
/*_________________________________________________*///KEYPAD_RETURN_NUMBER///*________________________________________*/
/*_________________________________________________*///KEYPAD_RETURN_NUMBER///*________________________________________*/