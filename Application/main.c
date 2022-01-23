/*
 * main.c
 *
 * Created: 1/17/2022 11:41:55 PM
 *  Author: Khaled Ali
 */ 

#include "App.h"
//#include "../ECUAL/LCD/LCD.h"
//#include "../ECUAL/TEMP_SENSOR/TEMP_interface.h"

//TEMPElement_t temp_sensor = {PORTA, PIN0};
int main(void){
	App();
	//TEMP_u8Init();
	//LCD_u8Init();
	//f32_t temp_value;
	//while(1){
			//TEMP_u8GetRead(&temp_sensor, &temp_value);
			//LCD_u8SendNumber((uint16_t) temp_value );
			//TIMER0_u8PollingDelay(1000);
			//LCD_u8SendCommand(0x01);
	//}
	return 1;
}