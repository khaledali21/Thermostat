/*
 * TEMP.c
 *
 *  Created on: Jan 17, 2022
 *      Author: vip
 */

#include "TEMP_interface.h"




void TEMP_u8Init(void)
{
	DIO_u8SetPinDirection(PORTA,PIN0,DIO_INPUT);


	ADC_u8Init();
}


uint8_t TEMP_u8GetRead(TEMPElement_t* TempElement, uint16_t* f32TempReading)
{
	uint8_t u8ErrorState = TEMP_OK;
	uint16_t u16PreRead;
	uint8_t u8ReadingCounts=0;
	uint8_t u8TimeoutCounter=0;
	if (TempElement!= NULL && f32TempReading !=NULL )
	{
		ADCChannel_t TempSensor = {TempElement->port,TempElement->pin, ADC_SINGLE_CONVERSION};
		if (ADC_u8StartConversion(&TempSensor) != ADC_OK)
		{
			u8ErrorState = TEMP_ADC_Error;
		}else
		{
			while (u8ReadingCounts<15 && u8TimeoutCounter<200)
			{
				ADC_u8GetVolt(f32TempReading);
				*f32TempReading = ((uint16_t)*f32TempReading/10);
				if (*f32TempReading!= u16PreRead)
				{
					u8ReadingCounts = 0;
				}else
				{
					u8ReadingCounts++;
				}
				u16PreRead = *f32TempReading;
				u8TimeoutCounter++;
			}

		}
		if (u8TimeoutCounter==200)
		{
			u8ErrorState ==TEMP_UNSTABLE;
		}
	}else
	{
		u8ErrorState = TEMP_NULL_INPUT;
	}

	return u8ErrorState;
}
