/*
 * detectWater.c
 *
 *  Created on: Jun 10, 2016
 *      Author: christo-laptop
 */

#include "detectWater.h"
#include <avr/io.h>

#include <stdio.h>

/* Function that returns 1 for water, 0 for no water */
uint16_t detectWater_run()
{
    DDRC &= ~(1<<PC1);
//    DIDR0 |= (1<<ADC1D);

    /* Select ADC1 as input */
    ADMUX = (1<<MUX0) | (1<<MUX1) | (1<<MUX2) | (1<<REFS0);

    //Enable the ADC | start conversion | clear the interrupt flag
    ADCSRA = _BV(ADEN) | (1<<ADPS0) | (1<<ADPS1) | _BV(ADSC) | _BV(ADIF);

    //Wait for the ADC to finish sampling
    while ( !(ADCSRA & _BV(ADIF)));

//    if (ADC != 0xFFFF)
//        return 0;
//    else
//        return 1;

    if (ADC > 0x030)
        printf("ADC: %d\n\r",ADC);

    return ADC;
}
