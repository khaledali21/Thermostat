/*
 * KEYPAD.c
 *
 *  Created on: Jan 11, 2022
 *      Author: Binary Beasts 
 */

#include "../../MCAL/DELAY/TIMER0.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_cfg.h"

// function to initialize keypad 
uint8_t KEYPAD_u8Init(void) {
	/*step 1 : config Col pins as output*/
	DIO_u8SetPinDirection(COL_PORT, COL_PIN0, DIO_OUTPUT);
	DIO_u8SetPinDirection(COL_PORT, COL_PIN1, DIO_OUTPUT);
	DIO_u8SetPinDirection(COL_PORT, COL_PIN2, DIO_OUTPUT);
	/*step 2 : config Rows pins as inputs , pull ups*/
	DIO_u8SetPinDirection(ROW_PORT, ROW_PIN0, DIO_INPUT_PULLUP);
	DIO_u8SetPinDirection(ROW_PORT, ROW_PIN1, DIO_INPUT_PULLUP);
	DIO_u8SetPinDirection(ROW_PORT, ROW_PIN2, DIO_INPUT_PULLUP);
	/*step 3 : Initialize Col pins -> HIGH*/
	DIO_u8SetPinData(COL_PORT, COL_PIN0, DIO_HIGH);
	DIO_u8SetPinData(COL_PORT, COL_PIN1, DIO_HIGH);
	DIO_u8SetPinData(COL_PORT, COL_PIN2, DIO_HIGH);
}

// function to check which key is pressed 
uint8_t KEYPAD_u8GetPressedKey(uint8_t* KeyPressed) {
	uint8_t u8ErrorState = STD_TYPES_OK;
	uint8_t LOC_u8ReturnVal = KEYPAD_NO_PRESSED_KEY;
	uint8_t col_indx;
	uint8_t row_indx;
	uint8_t Pin_State;
	uint8_t LOC_u8KEYPAD_Arr[KEYPAD_ROWS][KEYPAD_COL] = KEYPAD_VALUES;

	if (KeyPressed != NULL) {
		for (col_indx = COL_S; col_indx < COL_MAX; col_indx++) {
			/*select column and output low*/
			DIO_u8SetPinData(COL_PORT, col_indx, DIO_LOW);
			for (row_indx = ROW_S; row_indx < ROW_MAX; row_indx++) {
				DIO_u8GetPinData(ROW_PORT, row_indx, &Pin_State);
				if (Pin_State == 0) /*if true -> PB is pressed*/
				{
					LOC_u8ReturnVal =
							LOC_u8KEYPAD_Arr[row_indx - ROW_S][col_indx - COL_S];
					/*busy waiting loop*/

					/*debouncing button */
					TIMER0_u8PollingDelay(10);

				}
			}
			DIO_u8SetPinData(COL_PORT, col_indx, DIO_HIGH);
		}

		*KeyPressed = LOC_u8ReturnVal;
	} else {
		u8ErrorState = STD_TYPES_NOK;
	}
	return u8ErrorState;
}

