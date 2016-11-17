/*
 * ledStates.c
 *
 *  Created on: 09 Jul 2016
 *      Author: christo
 */

#include "ledStates.h"
#include "pwm.h"
#include "delay.h"
#include "util/delay.h"

#include <avr/io.h>

void tableDance();
void tableBreathe();
void runBreathe(uint8_t);

void ledStates_run()
{
	switch (mLED_State) {
	case LED_ON_STATE:
	{
		for (uint8_t idx = 0;idx < PWM_CHANNELS;idx++)
			pwm_setDuty(idx, 255);
	}break;

	case LED_ON_OFF_TRANSITION:
	{
		tableDance();
	}break;

	case LED_OFF_STATE:
	{
		for (uint8_t idx = 0;idx < PWM_CHANNELS;idx++)
			pwm_setDuty(idx, 0);
	}break;

	case LED_OFF_ON_TRANSITION:
	{
		tableBreathe();
	}break;
	case LED_FREE:
	{

	}break;

	break;
	default:
		break;
	}
}

void tableDance()
{
	for (uint8_t idx = 3; idx < PWM_CHANNELS; idx++)
	{
		pwm_setDuty(idx, 255);
		_delay_ms(100);
		//		delay_cnt(1);
		pwm_setDuty(idx, 0);

	}
}

void tableBreathe()
{
	uint8_t breathCnt = 0;

	for (uint8_t idx = 0; idx < 3;idx++)
	{
		TCNT1 = 0;
		while ((TCNT1 < 0xFFF0));
	}

	//		_delay_ms(5);

	for (breathCnt = 0; breathCnt < 30; breathCnt++)
	{
		runBreathe(breathCnt);
	}

	for (breathCnt = 30; breathCnt > 0; breathCnt--)
	{
		runBreathe(breathCnt);
	}
	uint8_t pwmDuties[PWM_CHANNELS] = {0,0,0,0,0,0,0,0,0};
	pwm_setDuties(pwmDuties);
}
void runBreathe(uint8_t bCnt)
{

	//	for (uint8_t idx = 0; idx < 3;idx++)
	//	{
	TCNT1 = 0;
	while ((TCNT1 < 0x2500));
	//	}
	//		_delay_ms(15);
	if ((bCnt >= 0)&&(bCnt <= 15))
	{
		uint8_t pwmDuties[PWM_CHANNELS] = {0,bCnt,0,0,bCnt,0,0,bCnt,0};
		pwm_setDuties(pwmDuties);
	}
	else
	{
		uint8_t dutyTmp = bCnt-15;
		uint8_t pwmDuties[PWM_CHANNELS] = {dutyTmp,bCnt,dutyTmp,dutyTmp,bCnt,dutyTmp,dutyTmp,bCnt,dutyTmp};
		pwm_setDuties(pwmDuties);
	}
}


