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
MotorDef_t motor = {PORTD, PIN6, PIN7, PIN5, CHANNELA};
APP_MODE volatile mode = SETTINGS;
uint16_t temp_value;
uint16_t temp_value;
uint16_t old_temp;
uint8_t motor_speed = 0;
uint8_t old_speed = 0;
uint8_t key;
void App(void){
	uint8_t state = STD_TYPES_OK;
	LED_u8Init(&led0);
	LED_u8Init(&led1);
	LED_u8Init(&led_err);
	LCD_u8Init();
	KEYPAD_u8Init();
	TEMP_u8Init();
	MOTOR_init(&motor);
	printLCD(mode);
	while(1){
		KEYPAD_u8GetPressedKey(&key);
		switch(mode){
			case SETTINGS:
			switch(key){
				case 4:
				mode = MANUAL;
				printLCD(mode);
				break;
				case 6:
				mode = AUTO;
				printLCD(mode);
				break;
				default:
				break;
			}
			break;
			case MANUAL:
			switch(key){
				case 2:
				if(motor_speed < 100){
					motor_speed += 10;
					printLCD(mode);
				}
				break;
				case 8:
				if(motor_speed > 0){
					motor_speed -= 10;
					printLCD(mode);
				}
				break;
				case 5:
				mode = SETTINGS;
				printLCD(mode);
				break;
				default:
				break;
			}
			if(motor_speed <=30 && motor_speed > 0){
				MOTOR_Move(&motor, 30, CLOCKWISE);
			}
			else if(motor_speed == 0){
				MOTOR_Stop(&motor);
			}
			else{
				MOTOR_Move(&motor, motor_speed, CLOCKWISE);
			}
			break;
			case AUTO:
			TEMP_u8GetRead(&temp_sensor, &temp_value);
			if(temp_value < 20){
				motor_speed = 0;
				MOTOR_Stop(&motor);
			}
			else if(temp_value > 21 && temp_value < 25){
				motor_speed = 30;
				MOTOR_Move(&motor, 30, CLOCKWISE);
			}
			else if(temp_value > 26 && temp_value < 30){
				motor_speed = 60;
				MOTOR_Move(&motor, 60, CLOCKWISE);
			}
			else if(temp_value > 31){
				motor_speed = 90;
				MOTOR_Move(&motor, 90, CLOCKWISE);
			}
			if((temp_value != old_temp)|| (motor_speed != old_speed)){
				printLCD(mode);
				TIMER0_u8PollingDelay(100);
			}
			old_temp = temp_value;
			old_speed = motor_speed;
			switch(key){
				case  5:
				mode = SETTINGS;
				printLCD(mode);
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
uint8_t printLCD(APP_MODE lcd_mode){
	uint8_t state = STD_TYPES_OK;
		LCD_u8SendCommand(0x01);
		switch(lcd_mode){
			case SETTINGS:{
			uint8_t line1[] = "Choose a mode.";
			LCD_u8SendString(line1);
			LCD_u8SetCursor(1, 0);
			uint8_t line2[] = "4)Manual 6)Auto";
			LCD_u8SendString(line2);
			break;}
			case MANUAL:{
			uint8_t line1[] = "To change Speed";
			LCD_u8SendString(line1);
			LCD_u8SetCursor(1, 0);
			uint8_t line2[] = "2)Up 8)Down   ";
			LCD_u8SendString(line2);
			LCD_u8SendNumber(motor_speed);
			break;}
			case AUTO:{
			uint8_t line1[] = "Temp:    Speed:";
			LCD_u8SendString(line1);
			LCD_u8SetCursor(1, 0);
			LCD_u8SendNumber(temp_value);
			uint8_t line2[] = "          ";
			LCD_u8SendString(line2);
			LCD_u8SendNumber(motor_speed);
			break;}
			default:
			break;
	}
	return state;
}
