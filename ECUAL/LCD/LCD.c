/*
 * LCD.c
 *
 * Created: 1/17/2022 12:19:06 AM
 *  Author: Khaled Ali
 */

#include "LCD.h"

uint8_t LCD_u8Init(void) {
DIO_u8SetPinDirection(RS_PORT, RS_PIN, DIO_OUTPUT);
DIO_u8SetPinDirection(RW_PORT, RW_PIN, DIO_OUTPUT);
DIO_u8SetPinDirection(E_PORT, E_PIN, DIO_OUTPUT);

DIO_u8SetPinDirection(D4_PORT, D4_PIN, DIO_OUTPUT);
DIO_u8SetPinDirection(D4_PORT, D5_PIN, DIO_OUTPUT);
DIO_u8SetPinDirection(D4_PORT, D6_PIN, DIO_OUTPUT);
DIO_u8SetPinDirection(D4_PORT, D7_PIN, DIO_OUTPUT);

TIMER0_u8PollingDelay(30);

LCD_u8SendCommand(0x33);
LCD_u8SendCommand(0x32);
LCD_u8SendCommand(0x28);
LCD_u8SendCommand(0x0c);
LCD_u8SendCommand(0x01);
LCD_u8SendCommand(0x06);
LCD_u8SendCommand(0x02);
return STD_TYPES_OK;

}


uint8_t LCD_u8SendCommand(uint8_t command){
	
uint8_t bit = GET_BIT(command, 4);
DIO_u8SetPinData(D4_PORT,D4_PIN,bit);
bit = GET_BIT(command, 5);
DIO_u8SetPinData(D5_PORT,D5_PIN,bit);
bit = GET_BIT(command, 6);
DIO_u8SetPinData(D6_PORT,D6_PIN,bit);
bit = GET_BIT(command, 7);
DIO_u8SetPinData(D7_PORT,D7_PIN,bit);

DIO_u8SetPinData(RS_PORT,RS_PIN,DIO_LOW);
DIO_u8SetPinData(RW_PORT,RW_PIN,DIO_LOW);
DIO_u8SetPinData(E_PORT,E_PIN,DIO_HIGH);
TIMER0_u8PollingDelay(2);
DIO_u8SetPinData(E_PORT,E_PIN,DIO_LOW);


bit = GET_BIT(command, 0);
DIO_u8SetPinData(D4_PORT,D4_PIN,bit);
bit = GET_BIT(command, 1);
DIO_u8SetPinData(D5_PORT,D5_PIN,bit);
bit = GET_BIT(command, 2);
DIO_u8SetPinData(D6_PORT,D6_PIN,bit);
bit = GET_BIT(command, 3);
DIO_u8SetPinData(D7_PORT,D7_PIN,bit);

DIO_u8SetPinData(RS_PORT,RS_PIN,DIO_LOW);
DIO_u8SetPinData(RW_PORT,RW_PIN,DIO_LOW);
DIO_u8SetPinData(E_PORT,E_PIN,DIO_HIGH);
TIMER0_u8PollingDelay(2);
DIO_u8SetPinData(E_PORT,E_PIN,DIO_LOW);

TIMER0_u8PollingDelay(5);
return STD_TYPES_OK;
}

uint8_t LCD_u8SendData(uint8_t data) {

uint8_t bit = GET_BIT(data, 4);
DIO_u8SetPinData(D4_PORT,D4_PIN,bit);
bit = GET_BIT(data, 5);
DIO_u8SetPinData(D5_PORT,D5_PIN,bit);
bit = GET_BIT(data, 6);
DIO_u8SetPinData(D6_PORT,D6_PIN,bit);
bit = GET_BIT(data, 7);
DIO_u8SetPinData(D7_PORT,D7_PIN,bit);

DIO_u8SetPinData(RS_PORT,RS_PIN,DIO_HIGH);
DIO_u8SetPinData(RW_PORT,RW_PIN,DIO_LOW);
DIO_u8SetPinData(E_PORT,E_PIN,DIO_HIGH);
TIMER0_u8PollingDelay(2);
DIO_u8SetPinData(E_PORT,E_PIN,DIO_LOW);

bit = GET_BIT(data, 0);
DIO_u8SetPinData(D4_PORT,D4_PIN,bit);
bit = GET_BIT(data, 1);
DIO_u8SetPinData(D5_PORT,D5_PIN,bit);
bit = GET_BIT(data, 2);
DIO_u8SetPinData(D6_PORT,D6_PIN,bit);
bit = GET_BIT(data, 3);
DIO_u8SetPinData(D7_PORT,D7_PIN,bit);

DIO_u8SetPinData(RS_PORT,RS_PIN,DIO_HIGH);
DIO_u8SetPinData(RW_PORT,RW_PIN,DIO_LOW);
DIO_u8SetPinData(E_PORT,E_PIN,DIO_HIGH);
TIMER0_u8PollingDelay(2);
DIO_u8SetPinData(E_PORT,E_PIN,DIO_LOW);


TIMER0_u8PollingDelay(5);
return STD_TYPES_OK;

}


uint8_t LCD_u8SendString(uint8_t *str){
	
	uint8_t* iterator = str;
	while(*iterator != '\0'){
		LCD_u8SendData(*iterator);
		TIMER0_u8PollingDelay(1);
		iterator++;
	}	
	return STD_TYPES_OK;

}
