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

static void (*ADC_callBack)(void);

uint8_t ADC_u8Init(void)
{
	uint8_t u8ErrorState = STD_TYPES_OK ;
	// Set the Reference Voltage to be ADC_VREF configured in the ADC configuration file
	ADMUX_REG &=~ ADC_VREF_MASK;
	ADMUX_REG |= (ADC_VREF<<REFS0);

	// Set the Data Adjustment of the ADC depending on the ADC_DATA_ADJUSMENT configured in the ADC configuration file
	if (ADC_DATA_ADJUSMENT == ADC_LEFT_ADJUST)
	{
		SET_BIT(ADMUX_REG,ADLAR);
		}else{
		CLR_BIT(ADMUX_REG,ADLAR);
	}

	//Set the prescaler of the ADC depending on the ADC_PRESCALAR configured in the ADC configuration file
	ADMUX_REG &=~ ADC_PRESCALAR_MASK;
	ADMUX_REG |= (ADC_PRESCALAR<<ADC_PRESCALAR_BITS);
	return u8ErrorState ;
}

uint8_t ADC_u8StartConversion(ADCChannel_t* st_ChannelConfig)
{
	uint8_t u8ErrorState = STD_TYPES_OK ;

	if (st_ChannelConfig != NULL)
	{
		// Choose the ADC Channel to convert from
		ADMUX_REG &=~ ADC_MUX_MASK;
		ADMUX_REG |= (st_ChannelConfig->channel<<ADC_MUX_BITS);

		//Set the conversion mode and trigger source
		if (st_ChannelConfig->triggerSource == ADC_SINGLE_CONVERSION)
		{
			// if the conversion mode is single conversion disable the auto trigger then give the start signal
			CLR_BIT(ADCSRA_REG, ADATE);
			SET_BIT(ADCSRA_REG,ADSC);
			}else{
			//if the conversion is not single then enable the Auto trigger mode
			SET_BIT(ADCSRA_REG, ADATE);
			// After Enabling the auto trigger mode Set the trigger source
			SFIOR_REG &=~ ADC_TRIGGER_SOURCE_MASK;
			SFIOR_REG |=  (st_ChannelConfig->triggerSource<<ADTS0);
			//if the trigger source is the ending of the current conversion (free running) then you need to start the first conversion manually
			if (st_ChannelConfig->triggerSource == ADC_FREE_RUNNIG)
			{
				SET_BIT(ADCSRA_REG,ADSC);
			}
			else{
				//NOP
			}
		}
		//After configuring the conversion enable the ADC to start the conversion process
		SET_BIT(ADCSRA_REG, ADEN);

		}else{

		u8ErrorState = ADC_StartConversion_Error ;
	}

	return u8ErrorState;	
}

uint8_t ADC_u8GetRead(uint16_t* u16_ADCReading)
{	
	uint8_t u8ErrorState = STD_TYPES_OK ;
	if ( GET_BIT(ADCSRA_REG,ADSC) == 0 )
	{
		u8ErrorState = ADC_GetRead_Error ;
	}
	else 
	{
		while( GET_BIT(ADCSRA_REG,ADIF) != 1 ){}
		*u16_ADCReading = ADCL_REG | ( ADCH_REG << 8 );
		CLR_BIT(ADCSRA_REG,ADIF);
	}
	return u8ErrorState ;
}

uint8_t ADC_u8GetVolt(f32_t* f32_ADCVolt)
{
	uint8_t u8ErrorState = STD_TYPES_OK ;
	uint16_t u16_ADCReading = 0 ;
	if ( ADC_u8GetRead(&u16_ADCReading) == STD_TYPES_OK )
	{
		*f32_ADCVolt = ( u16_ADCReading * ADC_VREF ) / ADC_MAXREAD ;	
	}
	else
	{
		u8ErrorState = ADC_GetVolt_Error ;
	}
	return u8ErrorState ;
}

uint8_t ADC_u8EnableInterrupt(void (*fnCallBack)(void))
{
	uint8_t u8ErrorState = STD_TYPES_OK ;
	if(fnCallBack != NULL)
	{
		ADC_callBack = fnCallBack ;
		SET_BIT(SREG_REG, I_BIT);
		SET_BIT(ADCSRA_REG,ADIE);
		if ( (GET_BIT(SREG_REG, I_BIT) == 0) || (GET_BIT(ADCSRA_REG,ADIE) == 0) )
		{
			u8ErrorState = ADC_EnableInterrupt_Error ;
		}
	}
	else
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

void __vector_16(void)
{
	if ( ADC_callBack != NULL )
	{
		ADC_callBack();
	}
}
