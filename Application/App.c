/*
 * App.c
 *
 * Created: 1/18/2022 5:11:05 PM
 *  Author: Khaled Ali
 */ 


#include "App.h"
LED_t led0 = {PORTB, PIN4};
LED_t led1 = {PORTB, PIN5};
LED_t led_err = {PORTB, PIN7};
TEMPElement_t temp_sensor = {PORTA, PIN0};
MotorDef_t motor = {PORTD, PIN2, PIN3, PIN4, CHANNELA};
APP_MODE mode = SETTINGS;
f32_t temp_value;
uint8_t motor_speed = 0;
void App(void){
	uint8_t state = STD_TYPES_OK;
	LED_u8Init(&led0);
	LED_u8Init(&led1);
	LED_u8Init(&led_err);
	LCD_u8Init();
	KEYPAD_u8Init();
	TEMP_u8Init(&temp_sensor);
	MOTOR_init(&motor);
	uint8_t key;
	while(1){
		KEYPAD_u8GetPressedKey(&key);
		switch(mode){
			case SETTINGS:
			printLCD(mode);
			switch(key){
				case 4:
				mode = MANUAL;
				break;
				case 6:
				mode = AUTO;
				break;
				default:
				break;
			}
			break;
			case MANUAL:
			printLCD(mode);
			switch(key){
				case 2:
				//Motor Increase Speed
				break;
				case 8:
				//Motor Decrease Speed
				break;
				case 5:
				mode = SETTINGS;
				break;
				default:
				break;
			}
			break;
			case AUTO:
			TEMP_u8GetRead(&temp_sensor, &temp_value);
			if(temp_value < 20){
				//Motor off
			}
			else if(temp_value > 21 && temp_value < 25){
				//MOTOR 30%
			}
			else if(temp_value > 26 && temp_value < 30){
				//MOTOR 60%
			}
			else if(temp_value > 31){
				//MOTOR 90%
			}
			printLCD(mode);
			switch(key){
				case  5:
				mode = SETTINGS;
				break;
				default:
				break;
			}
			break;
			default:
			break;
		}
	}
}

void printLCD(APP_MODE mode){
	switch(mode){
		case SETTINGS:
		//to be printed
		break;
		case MANUAL:
		//to be printed
		break;
		case AUTO:
		//to be printed
		break;
	}
}