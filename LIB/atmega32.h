/*
 * atmega32.h
 *
 *  Created on: Jan 5, 2022
 *      Author: Binary Beasts
 */

#ifndef ATMEGA32_H_
#define ATMEGA32_H_

#define SREG_REG		(*((volatile uint8_t*) (0x5F)))
#define SPH_REG		    (*((volatile uint8_t*) (0x5E)))
#define SPL_REG			(*((volatile uint8_t*) (0x5D)))
#define OCR0_REG		(*((volatile uint8_t*) (0x5C)))
#define GICR_REG		(*((volatile uint8_t*) (0x5B)))
#define GIFR_REG		(*((volatile uint8_t*) (0x5A)))
#define TIMSK_REG		(*((volatile uint8_t*) (0x59)))
#define TIFR_REG		(*((volatile uint8_t*) (0x58)))
#define SPMCR_REG		(*((volatile uint8_t*) (0x57)))
#define TWCR_REG		(*((volatile uint8_t*) (0x56)))
#define MCUCR_REG		(*((volatile uint8_t*) (0x55)))
#define MCUCSR_REG		(*((volatile uint8_t*) (0x54)))
#define TCCR0_REG		(*((volatile uint8_t*) (0x53)))
#define TCNT0_REG		(*((volatile uint8_t*) (0x52)))
#define SFIOR_REG		(*((volatile uint8_t*) (0x50)))
#define TCCR1A_REG		(*((volatile uint8_t*) (0x4F)))
#define TCCR1B_REG		(*((volatile uint8_t*) (0x4E)))
#define TCNT1H_REG		(*((volatile uint8_t*) (0x4D)))
#define TCNT1L_REG		(*((volatile uint8_t*) (0x4C)))
#define TCNT1_REG		(*((volatile uint16_t*) (0x4C)))
#define OCR1AH_REG		(*((volatile uint8_t*) (0x4B)))
#define OCR1AL_REG		(*((volatile uint8_t*) (0x4A)))
#define OCR1A_REG		(*((volatile uint16_t*) (0x4A)))
#define OCR1BH_REG		(*((volatile uint8_t*) (0x49)))
#define OCR1BL_REG		(*((volatile uint8_t*) (0x48)))
#define OCR1B_REG		(*((volatile uint16_t*) (0x48)))
#define ICR1H_REG		(*((volatile uint8_t*) (0x47)))
#define ICR1L_REG		(*((volatile uint8_t*) (0x46)))
#define TCCR2_REG		(*((volatile uint8_t*) (0x45)))
#define TCNT2_REG		(*((volatile uint8_t*) (0x44)))
#define OCR2_REG		(*((volatile uint8_t*) (0x43)))
#define ASSR_REG		(*((volatile uint8_t*) (0x42)))
#define WDTCR_REG		(*((volatile uint8_t*) (0x41)))
#define UBRRH_REG		(*((volatile uint8_t*) (0x40)))
#define UCSRC_REG		(*((volatile uint8_t*) (0x40)))
#define EEARH_REG		(*((volatile uint8_t*) (0x3F)))
#define EEARL_REG		(*((volatile uint8_t*) (0x3E)))
#define EEDR_REG		(*((volatile uint8_t*) (0x3D)))
#define EECR_REG		(*((volatile uint8_t*) (0x3C)))
#define PORTA_REG		(*((volatile uint8_t*) (0x3B)))
#define DDRA_REG		(*((volatile uint8_t*) (0x3A)))
#define PINA_REG		(*((volatile uint8_t*) (0x39)))
#define PORTB_REG		(*((volatile uint8_t*) (0x38)))
#define DDRB_REG		(*((volatile uint8_t*) (0x37)))
#define PINB_REG		(*((volatile uint8_t*) (0x36)))
#define PORTC_REG		(*((volatile uint8_t*) (0x35)))
#define DDRC_REG		(*((volatile uint8_t*) (0x34)))
#define PINC_REG		(*((volatile uint8_t*) (0x33)))
#define PORTD_REG		(*((volatile uint8_t*) (0x32)))
#define DDRD_REG		(*((volatile uint8_t*) (0x31)))
#define PIND_REG		(*((volatile uint8_t*) (0x30)))
#define SPDR_REG		(*((volatile uint8_t*) (0x2F)))
#define SPSR_REG		(*((volatile uint8_t*) (0x2E)))
#define SPCR_REG		(*((volatile uint8_t*) (0x2D)))
#define UDR_REG			(*((volatile uint8_t*) (0x2C)))
#define UCSRA_REG		(*((volatile uint8_t*) (0x2B)))
#define UCSRB_REG		(*((volatile uint8_t*) (0x2A)))
#define UBRRL_REG		(*((volatile uint8_t*) (0x29)))
#define ACSR_REG		(*((volatile uint8_t*) (0x28)))
#define ADMUX_REG		(*((volatile uint8_t*) (0x27)))
#define ADCSRA_REG		(*((volatile uint8_t*) (0x26)))
#define ADCH_REG		(*((volatile uint8_t*) (0x25)))
#define ADCL_REG		(*((volatile uint8_t*) (0x24)))
#define TWDR_REG		(*((volatile uint8_t*) (0x23)))
#define TWAR_REG		(*((volatile uint8_t*) (0x22)))
#define TWSR_REG		(*((volatile uint8_t*) (0x21)))
#define TWBR_REG		(*((volatile uint8_t*) (0x20)))

// TCCR0 (TIMER0 Control Register) Register Bits
#define CS00_BIT	0
#define CS01_BIT	1
#define CS02_BIT	2
#define WGM01_BIT	3
#define COM00_BIT	4
#define COM01_BIT	5
#define WGM00_BIT	6
#define FOC0_BIT	7

//SREG Register Bits
#define I_BIT		7

//TIMSK Register Bits
#define TOIE0_BIT		0
#define OCIE0_BIT		1
#define TOIE1_BIT		2
#define OCIE1B_BIT		3
#define OCIE1A_BIT		4
#define TICIE1_BIT		5
#define TOIE2_BIT		6
#define OCIE2_BIT		7

//ADMUX Register BITS
#define REFS1_BIT	7
#define REFS0_BIT	6
#define ADLAR_BIT	5
#define MUX4_BIT	4
#define MUX3_BIT	3
#define MUX2_BIT	2
#define MUX1_BIT	1
#define MUX0_BIT	0

//ADCSRA Register BITS
#define ADPS0_BIT		0
#define ADPS1_BIT		1
#define ADPS2_BIT		2
#define ADIE_BIT	    3
#define ADIF_BIT	    4
#define ADATE_BIT	    5
#define ADSC_BIT	    6
#define ADEN_BIT		7

//SFIOR Register BITS
#define PSR10_BIT		0
#define PSR2_BIT		1
#define PUD_BIT			2
#define ACME_BIT		3
#define ADTS0_BIT		5
#define ADTS1_BIT		6
#define ADTS2_BIT		7

#endif /* ATMEGA32_H_ */
