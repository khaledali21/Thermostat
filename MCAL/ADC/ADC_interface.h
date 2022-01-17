/*
 * ADC_interface.h
 *
 *  Created on: Jan 16, 2022
 *      Author: Alhassan Mohsen
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#include "ADC_cfg.h"
#include "ADC_ERR_Handle.h"
#include "ADC_prv.h"

 typedef enum{
	CHANNEL1,
	CHANNEL2,
	CHANNEL3,
	CHANNEL4,
	CHANNEL5,
	CHANNEL6,
	CHANNEL7,
	CHANNEL8
}ChannelNumber_t;

typedef struct{
	ChannelNumber_t channel;

}ADCChannel_t;

uint8_t ADC_u8InitChannel(ADCChannel_t* st_ChannelConfig);
uint8_t ADC_u8StartConversion(ADCChannel_t* st_ChannelConfig);
uint8_t ADC_u8GetRead(uint16_t* u16_ADCReading);
uint8_t ADC_u8GetVolt(f32_t* u16_ADCReading);
uint8_t ADC_u8EnableInterrupt(void);
uint8_t ADC_u8DisableInterrupt(void);

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
