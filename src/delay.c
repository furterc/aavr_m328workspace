/*
 * delay.c
 *
 *  Created on: Jul 5, 2016
 *      Author: christo-laptop
 */

#include <avr/io.h>

#include "delay.h"


uint16_t delayCount1;
uint16_t delayCount2;

uint8_t status;
uint8_t delay_cnt(uint16_t delayCnt)
{
//	uint8_t totalDelay = delayCnt;
//	uint8_t cntDelay;
//
//	if (cntDelay == 0)
//		cntDelay = delayCnt;
//
//	if (status == 0)
////	uint16_t cnt = delayCnt;
//	if ((TCNT1 > 0xF000) && delayCnt)
//	{
//		TCNT1 = 0;
//		cntDelay--;
//	}
//
//	if (!cntDelay)
//		return 1;
//	else
//		return 0;


//	TCNT1 = 0xC000;
//	uint16_t cnt = 0;

//	while(TCNT1 < 0xFFFF);

//    delayCount2=0;
//    while(delayCount2 < delayCnt);
	return 0;
}


//void delay_run()
//{
//    if(++delayCount1 > 0xFF)
//        delayCount2++;
//}


