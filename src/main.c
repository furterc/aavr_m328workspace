/*
 * main.c
 *
 *  Created on: Jun 4, 2016
 *      Author: christo-laptop
 */

#include "terminal.h"
#include "termHandler.h"
//#include "timer_one.h"
#include "timer_zero.h"
//#include "timer_two.h"
#include "pwm.h"
#include "delay.h"
#include "config.h"
#include "ledStates.h"
#include "btn.h"

//#include "iicDisplay/lcdpcf8574.h"

#include <stdio.h>
#include <avr/interrupt.h>
#include <stdlib.h>

void timerZeroRun(void)
{
	pwm_run();
//	btn_checkState();
}


void timerTwoRun(void)
{

}

int main(void)
{
	term_init();
	pwm_init();
	btn_init();

	/* Enable global interrupts */
	sei();

	timerZero_init();
	timerZero_setCB(timerZeroRun);


	while(1)
	{
		/* Check terminal for valid data */
		if (validData == 1)
			handleTerm();
//
		ledStates_run();
		btn_checkState();

//		uint16_t * del;
//		del= 5;
//		while (!delay_cnt(5));

//		TCNT1 = 0;
//		while ((TCNT1 < 0xF000));
//			{
//				TCNT1 = 0;
//			}

//		printf("cnt\n");

	}
	return 0;
}

