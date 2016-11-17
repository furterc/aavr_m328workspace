/*
 * ledStates.h
 *
 *  Created on: 09 Jul 2016
 *      Author: christo
 */

#ifndef SRC_LEDSTATES_H_
#define SRC_LEDSTATES_H_

typedef enum
{
	LED_ON,
	LED_OFF,
	LED_ONDER
} LED_States;

void ledStates_init();
void ledStates_run();

#endif /* SRC_LEDSTATES_H_ */
