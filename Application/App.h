/*
 * App.h
 *
 * Created: 1/18/2022 5:11:17 PM
 *  Author: Khaled Ali
 */ 


#ifndef APP_H_
#define APP_H_

#include "../LIB/Typedef.h"
#include "../ECUAL/LCD/LCD.h"
#include "../ECUAL/LED/LED.h"
#include "../ECUAL/MOTOR/MOTOR_interface.h"
#include "../ECUAL/KEYPAD/KEYPAD_interface.h"
#include "../ECUAL/TEMP_SENSOR/TEMP_interface.h"


// speeds
#define SLOW 30
#define MEDIUM 60
#define FAST 90


typedef enum{
	SETTINGS,
	AUTO,
	MANUAL
}APP_MODE;

typedef enum{
	SETTINGS_KEY = 5,
	AUTO_KEY = 6,
	MANUAL_KEY = 4,
	UP_KEY = 2,
	DOWN_KEY = 8
}KEY;
void App(void);
uint8_t printLCD(APP_MODE mode);
#endif /* APP_H_ */