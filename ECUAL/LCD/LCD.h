/*
 * LCD.h
 *
 * Created: 1/17/2022 12:19:20 AM
 *  Author: Khaled Ali
 */

#ifndef LCD_H_
#define LCD_H_

#include "../../LIB/Typedef.h"
#include "LCD_cfg.h"
#include "../../MCAL/DIO/DIO_interface.h"

uint8_t LCD_u8Init(void);

uint8_t LCD_u8SendCommand(uint8_t command);

uint8_t LCD_u8SendData(uint8_t data);

uint8_t LCD_u8SendString(uint8_t *str);

#endif /* LCD_H_ */
