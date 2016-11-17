
#include "ledStates.h"
#include "pwm.h"
#include "btn.h"

#include <avr/io.h>
#include <stdio.h>

LED_States mLED_State;

void buttonOneRun(void)
{
	// change state
	if(++mLED_State > 2)
		mLED_State = 0;

	printf("led State: %d\n\r", mLED_State);
}

void ledStates_init()
{
	buttonOne_setCB(buttonOneRun);
}

void ledStates_run()
{
	switch (mLED_State) {
	case LED_ON:
	{
		for (uint8_t idx = 0;idx < PWM_CHANNELS;idx++)
			pwm_setDuty(idx, 255);
	}break;

	case LED_OFF:
	{
		for (uint8_t idx = 0;idx < PWM_CHANNELS;idx++)
			pwm_setDuty(idx, 0);
	}break;

	case LED_ONDER:
	{
		for (uint8_t idx = 0;idx < PWM_CHANNELS-3;idx++)
			pwm_setDuty(idx, 10);
	}break;

	default:
	break;
	}
}
