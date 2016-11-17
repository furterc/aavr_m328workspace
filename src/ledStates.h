/*
 * ledStates.h
 *
 *  Created on: 09 Jul 2016
 *      Author: christo
 */

#ifndef SRC_LEDSTATES_H_
#define SRC_LEDSTATES_H_

typedef enum {
	LED_ON_STATE,
	LED_ON_OFF_TRANSITION,
	LED_OFF_STATE,
	LED_OFF_ON_TRANSITION,
	LED_FREE
} LED_States;

void ledStates_run();

LED_States mLED_State;

#endif /* SRC_LEDSTATES_H_ */
