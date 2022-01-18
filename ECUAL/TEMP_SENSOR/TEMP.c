/*
 * TEMP.c
 *
 *  Created on: Jan 17, 2022
 *      Author: vip
 */

#include "TEMP_interface.h"



uint8_t TEMP_u8Init(TEMPElement_t* TempElement)
{

	ADCChannel_t TempSensor = {TempElement->port,TempElement->pin, ADC_FREE_RUNNIG};

	uint8_t u8ErrorState= TEMP_OK;
	if (TempElement != NULL)
	{
		ADC_u8Init();
		ADC_u8StartConversion();
	}else{
		u8ErrorState = TEMP_NULL_INPUT;
	}
}
uint8_t TEMP_u8GetRead(TEMPElement_t* TempElement, f32_t* f32TempReading);
