/*
 * main.c
 *
 *  Created on: Jan 15, 2022
 *      Author:  Alhassan Mohsen
 */

#include "../LIB/Typedef.h"
#include "../LIB/BIT_Math.h"
#include "../ECUAL/LCD/LCD.h"
#include "../ECUAL/LED/LED.h"

int main() {

	LCD_u8Init();
	LCD_u8SendData('a');
	
	while(1)
	{
	}
	
	return 0;
}
