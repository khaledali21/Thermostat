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

/*
 * Define The bits of each register 
 */

/*ADCSRA_REG bits */
#define ADEN		7
#define ADSC		6
#define ADATE		5
#define ADIF		4
#define ADIE		3
#define ADPS2		2
#define ADPS1		1
#define ADPS0		0

/*ADMUX_REG bits*/
#define REFS1		7
#define REFS0		6
#define ADLAR		5
#define MUX4		4
#define MUX3		3
#define MUX2		2
#define MUX1		1
#define MUX0		0

// define max ADC reading 
#define ADC_MAXREAD		1024

#endif /* MCAL_ADC_ADC_PRV_H_ */
