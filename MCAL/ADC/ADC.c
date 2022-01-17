/*
 * ADC.c
 *
 *  Created on: Jan 16, 2022
 *      Author: Abdelrhman Elsawy
 */

#include "../../LIB/Typedef.h"
#include "../../LIB/BIT_Math.h"
#include "../../LIB/atmega32.h"
#include "../DELAY/TIMER0.h"
#include "ADC_interface.h"

uint8_t ADC_u8InitChannel(ADCChannel_t* st_ChannelConfig)
{
	
}

uint8_t ADC_u8StartConversion(ADCChannel_t* st_ChannelConfig)
{
	
}

uint8_t ADC_u8GetRead(uint16_t* u16_ADCReading)
{	
	uint8_t u8ErrorState = STD_TYPES_OK ;
	if ( GET_BIT(ADCSRA_REG,ADSC) == 1 )
	{
		if ( TIMER0_u8PollingDelay(10) == STD_TYPES_NOK )
			u8ErrorState = ADC_GetRead_Error ; 
	}
//while ( GET_BIT(ADCSRA_REG,ADSC) == 1 ) {}
	if ( GET_BIT(ADCSRA_REG,ADSC) == 1 )
	{
		u8ErrorState = ADC_GetRead_Error ;
	}
	else 
	{
		SET_BIT(ADCSRA_REG,ADSC);
		while( GET_BIT(ADCSRA_REG,ADIF) != 1 ){}
		*u16_ADCReading = ADCL_REG | ( ADCH_REG << 8 );
		CLR_BIT(ADCSRA_REG,ADIF);
	}
	return u8ErrorState ;
}

uint8_t ADC_u8GetVolt(f32_t* u16_ADCVolt)
{
	uint8_t u8ErrorState = STD_TYPES_OK ;
	uint16_t u16_ADCReading = 0 ;
	if ( ADC_u8GetRead(&u16_ADCReading) == STD_TYPES_OK )
	{
		*u16_ADCVolt = ( u16_ADCReading * ADC_VREF ) / ADC_MAXREAD ;	
	}
	else
	{
		u8ErrorState = ADC_GetVolt_Error ;
	}
	return u8ErrorState ;
}

uint8_t ADC_u8EnableInterrupt(void)
{
	uint8_t u8ErrorState = STD_TYPES_OK ;
	SET_BIT(SREG_REG, I_BIT);
	SET_BIT(ADCSRA_REG,ADIE);
	if ( GET_BIT(SREG_REG, I_BIT) == 0 || GET_BIT(ADCSRA_REG,ADIE) == 0 )
	{
		u8ErrorState = ADC_EnableInterrupt_Error ;
	}
	return u8ErrorState ; 
}

uint8_t ADC_u8DisableInterrupt(void)
{
	uint8_t u8ErrorState = STD_TYPES_OK ;
	CLR_BIT(ADCSRA_REG,ADIE);
	if ( GET_BIT(ADCSRA_REG,ADIE) != 0 )
	{
		u8ErrorState = ADC_DisableInterrupt_Error ;
	}
	return u8ErrorState ;
}
