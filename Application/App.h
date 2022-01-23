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


// Motor Speeds
#define SLOW 30
#define MEDIUM 60
#define FAST 90

/**
 * @enum to define the possible system states
 *
 */
typedef enum{
	SETTINGS,//!< This is the state where the user choose what is the operating mode
	AUTO,    //!< This is the state where the operating mode is Automatic and depend on a sensor readings
	MANUAL   //!< This is the state where the operating mode is Manual and take the user input to update the actuators
}SysState_t;

/**
 * @enum To define the different possible user inputs through a KeyPad interface
 */
typedef enum{
	SETTINGS_KEY = 5,//!<	The user press this key to enter the settings state of the system
	AUTO_KEY = 6,    //!< 	The user press this key to choose the Automatic operation mode
	MANUAL_KEY = 4,  //!<	The user press this key to choose the Manual operation mode
	UP_KEY = 2,      //!<	The user press this key to speed up the motors in the Manual operation mode
	DOWN_KEY = 8     //!<	The user press this key to slow down the motors in the Manual operation mode
}KEY;

/**
 * @fn This contain the main operation and logic of the system
 * @param  takes no inputs
 * @return void
 */
void App(void);

/**
 * @fn uint8_t printLCD(SysState_t mode)
 * @brief this function is used to update the LCD page depending on the system state and variables
 * @param mode	: a one of the possible system states which are
 * 			-SETTINGS
 * 			-AUTO
 * 			-MANUAL
 * @return
 */
uint8_t printLCD(SysState_t mode);
#endif /* APP_H_ */
