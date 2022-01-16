/*
 * ADC_prv.h
 *
 *  Created on: Jan 16, 2022
 *      Author: Alhassan Mohsen
 */

#ifndef MCAL_ADC_ADC_PRV_H_
#define MCAL_ADC_ADC_PRV_H_

/*
 * The Different Possibilities to the Vref of the ADC
 */
#define ADC_AREF		0
#define ADC_AVCC		1
#define ADC_INTENRNAL	3

/*
 * Define The Different Possibilities to the data adjustment of the ADC
 */
#define ADC_RIGHT_ADJUST 0
#define ADC_LEFT_ADJUST	 1


#define ADC_PRESCALAR_2		1
#define ADC_PRESCALAR_4		2
#define ADC_PRESCALAR_8		3
#define ADC_PRESCALAR_16	4
#define ADC_PRESCALAR_32	5
#define ADC_PRESCALAR_64	6
#define ADC_PRESCALAR_128	7



#endif /* MCAL_ADC_ADC_PRV_H_ */
