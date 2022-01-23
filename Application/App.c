/*
 * App.c
 *
 * Created: 1/18/2022 5:11:05 PM
 *  Author: Binary Beasts
 */ 

#include "App.h"

/*
 * Defining all LEDs in our project
 */
LED_t led_err = {PORTB, PIN7};

/*
 * Define the Temperature Sensor
 */
TEMPElement_t temp_sensor = {PORTA, PIN0};

/*
 * Define a Motor Element
 */
MotorDef_t motor = {PORTD, PIN2, PIN3, PIN4, CHANNELA};

/*
 * Global Variables Definitions
 */

// Initiating the program state to SETTINGS
SysState_t volatile u8State = SETTINGS;
uint16_t u16TempValue; 			// To save the updated readings of the temperature sensor
uint16_t u16OldTemp;			// to save the previous reading of the temperature sensor
uint8_t u8MotorSpeed = 0; 		//  this variable is updated by user input used to update the motor speed and
uint8_t u8OldSpeed = 0;			// to save the previous motor speed
uint8_t u8PressedKey;			// to save the user input through the key pad interface


void App(void){
/*
 * Initiating the used modules and sensors
 */
	LED_u8Init(&led_err);
	LCD_u8Init();
	KEYPAD_u8Init();
	TEMP_u8Init();
	MOTOR_init(&motor);

/*
 * printing the LCD page concerning  the current state
 */
	printLCD(u8State);

	while(1){

		// At the beginning of every loop get the keypad pressed key first
		KEYPAD_u8GetPressedKey(&u8PressedKey);

		// The State machine Implementation (switching on the u8State Variable)
		switch(u8State){
			case SETTINGS:
				//if we are in the SETTINGS State this state is waiting the user input to perform a transition to another state
				switch(u8PressedKey)
				{
					case MANUAL_KEY:
					//if the pressed Key is The MANUAL Key then change the State of the Program to MANUAL
					u8State = MANUAL;
					//After changing the program state print the LCD page conercing the new one
					printLCD(u8State);
					break;
					case AUTO_KEY:
					//if the pressed Key is The AUTO Key then change the State of the Program to AUTO
					u8State = AUTO;
					//After changing the program state print the LCD page conercing the new one
					printLCD(u8State);
					break;
					default:
					break;
				}

				break;
			case MANUAL:
				// if the Program state is MANUAL -> in this state the program uses the user input to change the motor speed
				// the only state transition possible while in MANUAL State is when the user input (the pressed Key) is SETTINGS_KEY then the state is updated to be SETTINGS
				switch(u8PressedKey)
				{
				case UP_KEY:
				//if the user input is UP_KEY increase the motor speed if it is less than 100
				if(u8MotorSpeed < 100){
					u8MotorSpeed += 10;
					//update the LCD page with the new information
					printLCD(u8State);
				}
				break;
				case DOWN_KEY:
				//if the user input is DOWN_KEY decrease the motor speed if it is higher than 0
				if(u8MotorSpeed > 0){
					u8MotorSpeed -= 10;
					//update the LCD page with the new information
					printLCD(u8State);
				}
				break;
				case SETTINGS_KEY:
				//if the user input is SETTINGS_KEY update the program state to SETTINGS
				u8State = SETTINGS;
				//update the LCD page with the new information
				printLCD(u8State);
				break;
				default:
				break;
				}
				// update the motor speed with the new speed as the user set it
				if(u8MotorSpeed <=30 && u8MotorSpeed > 0){
					MOTOR_Move(&motor, SLOW, CLOCKWISE);
				}
				else if(u8MotorSpeed == 0){
					MOTOR_Stop(&motor);
				}
				else{
					MOTOR_Move(&motor, u8MotorSpeed, CLOCKWISE);
				}
				break;
			case AUTO:
			// if the Program state is MANUAL -> in this state the program uses the temperature sensor readings to change the motor speed
			// the only state transition possible while in MANUAL State is when the user input (the pressed Key) is SETTINGS_KEY then the state is updated to be SETTING
				// first we get the temperature sensor readings
				TEMP_u8GetRead(&temp_sensor, &u16TempValue);
				// use the temperature sensor readings to take a decision
				if(u16TempValue < 20){
					// if the temperature is less than 20 then stop the motors
					u8MotorSpeed = 0;
					MOTOR_Stop(&motor);
				}
				else if(u16TempValue > 21 && u16TempValue < 25){
					// if the temperature is higher than 21 and less than 25 then run the motors with SLOW speed
					u8MotorSpeed = SLOW;
					MOTOR_Move(&motor, SLOW, CLOCKWISE);
				}
				else if(u16TempValue > 26 && u16TempValue < 30){
					// if the temperature is higher than 26 and less than 30 then run the motors with MEDIUM speed
					u8MotorSpeed = MEDIUM;
					MOTOR_Move(&motor, MEDIUM, CLOCKWISE);
				}
				else if(u16TempValue > 31){
					// if the temperature is higher than 31 then run the motors with FAST speed
					u8MotorSpeed = FAST;
					MOTOR_Move(&motor, FAST, CLOCKWISE);
				}

				// only update the LCD if there is a change in temperature more than 3 degrees or the motor speed is updated
				if((abs(u16TempValue, u16OldTemp) > 1)|| (u8MotorSpeed != u8OldSpeed)){
					printLCD(u8State);
					TIMER0_u8PollingDelay(100);
				}
				u16OldTemp = u16TempValue;
				u8OldSpeed = u8MotorSpeed;

				// check if the user pressed on the SETTINGS_KEY then change the system state to SETTINGS
				if(u8PressedKey==SETTINGS_KEY)
				{
					u8State = SETTINGS;
					printLCD(u8State);
				}
				break;
			default:
			break;
		}
	}
}


uint8_t printLCD(SysState_t lcd_mode){
	uint8_t u8ErrorState = STD_TYPES_OK;
	//first clear the LCD
		LCD_u8SendCommand(0x01);

	//Check what is the state of the system and depending on it decide what to print
		switch(lcd_mode){
			case SETTINGS:{
			uint8_t line1[] = "Choose a mode:";
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
			LCD_u8SendNumber(u8MotorSpeed);
			break;}
			case AUTO:{
			uint8_t line1[] = "Temp:    Speed:";
			LCD_u8SendString(line1);
			LCD_u8SetCursor(1, 0);
			LCD_u8SendNumber(u16TempValue);
			uint8_t line2[] = "          ";
			LCD_u8SendString(line2);
			LCD_u8SendNumber(u8MotorSpeed);
			break;}
			default:
				u8ErrorState = STD_TYPES_NOK;
			break;
	}
	return u8ErrorState;
}
