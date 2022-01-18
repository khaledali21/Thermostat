/*
 * LCD.c
 *
 * Created: 1/17/2022 12:19:06 AM
 *  Author: Khaled Ali
 */

#include "LCD.h"
#include "../LED/LED.h"
uint8_t LCD_u8Init(void) {
	uint8_t state = STD_TYPES_OK;
	state = DIO_u8SetPinDirection(RS_PORT, RS_PIN, DIO_OUTPUT);
	if(state == STD_TYPES_OK){
		state = DIO_u8SetPinDirection(RW_PORT, RW_PIN, DIO_OUTPUT);
	}
	if(state == STD_TYPES_OK){
		state = DIO_u8SetPinDirection(E_PORT, E_PIN, DIO_OUTPUT);
	}
	if(state == STD_TYPES_OK){
		state = DIO_u8SetPinDirection(D4_PORT, D4_PIN, DIO_OUTPUT);
	}
	if(state == STD_TYPES_OK){
		state = DIO_u8SetPinDirection(D4_PORT, D5_PIN, DIO_OUTPUT);
	}
	if(state == STD_TYPES_OK){
		state = DIO_u8SetPinDirection(D4_PORT, D6_PIN, DIO_OUTPUT);
	}
	if(state == STD_TYPES_OK){
		state = DIO_u8SetPinDirection(D4_PORT, D7_PIN, DIO_OUTPUT);
	}

	if(state == STD_TYPES_OK){
		state = LCD_u8SendCommand(0x33);
	}

	if(state == STD_TYPES_OK){
		state = LCD_u8SendCommand(0x32);
	}
	if(state == STD_TYPES_OK){
		state = LCD_u8SendCommand(0x28);
	}
	if(state == STD_TYPES_OK){
		state = LCD_u8SendCommand(0x0c);
	}
	if(state == STD_TYPES_OK){
		state = LCD_u8SendCommand(0x06);
	}
	if(state == STD_TYPES_OK){
		state = LCD_u8SendCommand(0x01);
	}

	return state;

}


uint8_t LCD_u8SendCommand(uint8_t command){
	uint8_t state = STD_TYPES_OK;	
	uint8_t bit = GET_BIT(command, 4);
	state = DIO_u8SetPinData(D4_PORT,D4_PIN,bit);
	if(state == STD_TYPES_OK){
		bit = GET_BIT(command, 5);
		state = DIO_u8SetPinData(D5_PORT,D5_PIN,bit);
	}

	if(state == STD_TYPES_OK){
		bit = GET_BIT(command, 6);
		DIO_u8SetPinData(D6_PORT,D6_PIN,bit);
	}
	if(state == STD_TYPES_OK){
		bit = GET_BIT(command, 7);
		DIO_u8SetPinData(D7_PORT,D7_PIN,bit);
	}
	if(state == STD_TYPES_OK){
		state = DIO_u8SetPinData(RS_PORT,RS_PIN,DIO_LOW);
	}
	if(state == STD_TYPES_OK){
		state = DIO_u8SetPinData(RW_PORT,RW_PIN,DIO_LOW);
	}
	if(state == STD_TYPES_OK){
		state = DIO_u8SetPinData(E_PORT,E_PIN,DIO_HIGH);
	}

	if(state == STD_TYPES_OK){
		TIMER0_u8PollingDelay(2);
		state = DIO_u8SetPinData(E_PORT,E_PIN,DIO_LOW);
	}

	if(state == STD_TYPES_OK){
		bit = GET_BIT(command, 0);
		state = DIO_u8SetPinData(D4_PORT,D4_PIN,bit);
	}
	if(state == STD_TYPES_OK){
		bit = GET_BIT(command, 1);
		DIO_u8SetPinData(D5_PORT,D5_PIN,bit);
	}
	if(state == STD_TYPES_OK){
		bit = GET_BIT(command, 2);
		DIO_u8SetPinData(D6_PORT,D6_PIN,bit);
	}
	if(state == STD_TYPES_OK){
		bit = GET_BIT(command, 3);
		DIO_u8SetPinData(D7_PORT,D7_PIN,bit);
	}
	if(state == STD_TYPES_OK){
		state = DIO_u8SetPinData(RS_PORT,RS_PIN,DIO_LOW);
	}
	if(state == STD_TYPES_OK){
		state = DIO_u8SetPinData(RW_PORT,RW_PIN,DIO_LOW);
	}
	if(state == STD_TYPES_OK){
		state = DIO_u8SetPinData(E_PORT,E_PIN,DIO_HIGH);
	}
	if(state == STD_TYPES_OK){
		TIMER0_u8PollingDelay(2);
		state = DIO_u8SetPinData(E_PORT,E_PIN,DIO_LOW);
	}
	if(state == STD_TYPES_OK){
		state = TIMER0_u8PollingDelay(5);	
	}
	return state;
}

uint8_t LCD_u8SendData(uint8_t data) {

	uint8_t state = STD_TYPES_OK;
	uint8_t bit = GET_BIT(data, 4);
	state = DIO_u8SetPinData(D4_PORT,D4_PIN,bit);
	if(state == STD_TYPES_OK){
		bit = GET_BIT(data, 5);
		state = DIO_u8SetPinData(D5_PORT,D5_PIN,bit);
	}
	if(state == STD_TYPES_OK){
		bit = GET_BIT(data, 6);
		DIO_u8SetPinData(D6_PORT,D6_PIN,bit);
	}
	if(state == STD_TYPES_OK){
		bit = GET_BIT(data, 7);
		DIO_u8SetPinData(D7_PORT,D7_PIN,bit);
	}
	if(state == STD_TYPES_OK){
		state = DIO_u8SetPinData(RS_PORT,RS_PIN,DIO_HIGH);
	}
	if(state == STD_TYPES_OK){
		state = DIO_u8SetPinData(RW_PORT,RW_PIN,DIO_LOW);
	}
	if(state == STD_TYPES_OK){
		state = DIO_u8SetPinData(E_PORT,E_PIN,DIO_HIGH);
	}
	if(state == STD_TYPES_OK){
		TIMER0_u8PollingDelay(2);
		state = DIO_u8SetPinData(E_PORT,E_PIN,DIO_LOW);
	}

	if(state == STD_TYPES_OK){
		bit = GET_BIT(data, 0);
		state = DIO_u8SetPinData(D4_PORT,D4_PIN,bit);
	}
	if(state == STD_TYPES_OK){
		bit = GET_BIT(data, 1);
		DIO_u8SetPinData(D5_PORT,D5_PIN,bit);
	}
	if(state == STD_TYPES_OK){
		bit = GET_BIT(data, 2);
		DIO_u8SetPinData(D6_PORT,D6_PIN,bit);
	}
	if(state == STD_TYPES_OK){
		bit = GET_BIT(data, 3);
		DIO_u8SetPinData(D7_PORT,D7_PIN,bit);
	}
	if(state == STD_TYPES_OK){
		state = DIO_u8SetPinData(RS_PORT,RS_PIN,DIO_HIGH);
	}
	if(state == STD_TYPES_OK){
		state = DIO_u8SetPinData(RW_PORT,RW_PIN,DIO_LOW);
	}
	if(state == STD_TYPES_OK){
		state = DIO_u8SetPinData(E_PORT,E_PIN,DIO_HIGH);
	}
	if(state == STD_TYPES_OK){
		TIMER0_u8PollingDelay(2);
		state = DIO_u8SetPinData(E_PORT,E_PIN,DIO_LOW);
	}
	state = TIMER0_u8PollingDelay(5);
	return state;

}


uint8_t LCD_u8SendString(uint8_t *str){
	uint8_t state = STD_TYPES_OK;
	if(str == NULL){
		state = STD_TYPES_NOK;
	}
	else{
		uint8_t* iterator = str;
		while(*iterator != '\0' && state == STD_TYPES_OK){
			state = LCD_u8SendData(*iterator);
			state = TIMER0_u8PollingDelay(1);
			iterator++;
		}	
	}
	return state;

}

void LCD_u8SendNumber(sint8_t num)
{
	sint8_t y=1;
	if(num<0)
	{
		LCD_u8SendData('-');
		num*=-1;

	while(y>1)
	{
	LCD_u8SendData((y%10)+48);
	y=y/10;
	}
}
}

uint8_t LCD_u8SetCursor(uint8_t row, uint8_t col)
{	uint8_t state = STD_TYPES_OK;
	if(col > 15){
		state = STD_TYPES_NOK;
	}
	else{
		switch (row)
		{
			case 0:
			col |= 0x80;
			break;
			case 1:
			col |= 0xC0;
			break;
			default:
			state = STD_TYPES_NOK;
			break;
		}
	}
	if(state == STD_TYPES_OK){
		state = LCD_u8SendCommand(col);
	}
	return state;
}
