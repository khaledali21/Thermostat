/*
 * KEYPAD_cfg.h
 *
 *  Created on: Jan 11, 2022
 *      Author: Binary Beasts
 */

#ifndef ECUAL_KEYPAD_KEYPAD_CFG_H_
#define ECUAL_KEYPAD_KEYPAD_CFG_H_

#define KEYPAD_ROWS 3
#define KEYPAD_COL  3


#define COL_S   5
#define COL_MAX 8

#define ROW_S   2
#define ROW_MAX 5

#define COL_PORT  PORTC
#define ROW_PORT  PORTC

#define COL_PIN0  PIN5
#define COL_PIN1  PIN6
#define COL_PIN2  PIN7

#define ROW_PIN0  PIN2
#define ROW_PIN1  PIN3
#define ROW_PIN2  PIN4

#define KEYPAD_VALUES {{1,2,3},{4,5,6},{7,8,9}}


#endif /* ECUAL_KEYPAD_KEYPAD_CFG_H_ */
