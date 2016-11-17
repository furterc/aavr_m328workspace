/*
 * btn.c
 *
 *  Created on: 22 Apr 2016
 *      Author: cfurter
 */

#include "btn.h"
#include "led.h"
#include "config.h"
#include "terminal.h"

#include <avr/io.h>
#include <stdio.h>
#include <stdbool.h>

void (*buttonOneCallback)(void) = 0;
void (*buttonTwoCallback)(void) = 0;
void (*buttonThreeCallback)(void) = 0;
void (*buttonFourCallback)(void) = 0;

btn_state btn1State;
btn_state btn2State;
btn_state btn3State;
btn_state btn4State;

void btn_init()
{
	/* set buttons as inputs */
	BTN_1_DDR &= ~(1 << BTN_1_INPUTPIN);
	BTN_2_DDR &= ~(1 << BTN_2_INPUTPIN);
	BTN_3_DDR &= ~(1 << BTN_3_INPUTPIN);
	BTN_4_DDR &= ~(1 << BTN_4_INPUTPIN);

	btn1State = OFF;
	btn2State = OFF;
	btn3State = OFF;
	btn4State = OFF;
}

void btn_checkState()
{
	/* switch changed */
	if (!(BTN_1_PIN & (1 << BTN_1_INPUTPIN)))
	{
		if (btn1State != ON)
		{
			btn1State = ON;
			if(buttonOneCallback)
				buttonOneCallback();
		}
	}
	else
	{
		if (btn1State != OFF)
		{
			btn1State = OFF;
			if(buttonOneCallback)
				buttonOneCallback();
		}
	}

	if (!(BTN_2_PIN & (1 << BTN_2_INPUTPIN)))
	{
		if (btn2State != ON)
		{
			btn2State = ON;
			if(buttonTwoCallback)
				buttonTwoCallback();
		}
	}
	else
	{
		if (btn2State != OFF)
		{
			btn2State = OFF;
			if(buttonTwoCallback)
				buttonTwoCallback();
		}
	}

	if (!(BTN_3_PIN & (1 << BTN_3_INPUTPIN)))
	{
		if (btn3State != ON)
		{
			if(buttonThreeCallback)
				buttonThreeCallback();
		}
	}
	else
	{
		if (btn3State != OFF)
		{
			btn3State = OFF;
			if(buttonThreeCallback)
				buttonThreeCallback();
		}
	}

	if (!(BTN_4_PIN & (1 << BTN_4_INPUTPIN)))
	{
		if (btn4State != ON)
		{
			btn4State = ON;
			if(buttonFourCallback)
				buttonFourCallback();
		}
	}
	else
	{
		if (btn4State != OFF)
		{
			btn4State = OFF;
			if(buttonFourCallback)
				buttonFourCallback();
		}
	}
}

void buttonOne_setCB(void (*cb)(void))
{
	if(cb)
	{
		buttonOneCallback = cb;
	}
}

void buttonTwo_setCB(void (*cb)(void))
{
	if(cb)
	{
		buttonTwoCallback = cb;
	}
}

void buttonThree_setCB(void (*cb)(void))
{
	if(cb)
	{
		buttonThreeCallback = cb;
	}
}

void buttonFour_setCB(void (*cb)(void))
{
	if(cb)
	{
		buttonFourCallback = cb;
	}
}

