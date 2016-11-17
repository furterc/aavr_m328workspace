
#include "terminal.h"
#include "termHandler.h"
#include "timer_zero.h"

#include "pwm.h"
#include "delay.h"
#include "config.h"
#include "ledStates.h"
#include "btn.h"

#include <stdio.h>
#include <avr/interrupt.h>
#include <stdlib.h>

void timerZeroRun(void)
{
	pwm_run();
}


int main(void)
{
	term_init();
	pwm_init();
	btn_init();
	ledStates_init();

	sei();

	timerZero_init();
	timerZero_setCB(timerZeroRun);

	while(1)
	{
		/* Check terminal for valid data */
		if (validData == 1)
			handleTerm();

		ledStates_run();
		btn_checkState();
	}
	return 0;
}

