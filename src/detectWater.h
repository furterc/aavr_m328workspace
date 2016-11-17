/*
 * detectWater.h
 *
 *  Created on: Jun 10, 2016
 *      Author: christo-laptop
 */

#ifndef SRC_DETECTWATER_H_
#define SRC_DETECTWATER_H_

#include <stdint-gcc.h>

/* Function to initiate ADC and pin */
void detectWater_init();
/* Function that returns 1 for water, 0 for no water */
uint16_t detectWater_run();


#endif /* SRC_DETECTWATER_H_ */
