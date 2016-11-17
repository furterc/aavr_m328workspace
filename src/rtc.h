/*
 * rtc.h
 *
 *  Created on: 07 Apr 2016
 *      Author: cfurter
 */

#ifndef SRC_RTC_H_
#define SRC_RTC_H_
#include <stdint-gcc.h>

uint32_t uTime;

void rtc_init();
void print_Time();
void print_lcd_Time();
void rtc_setTime(uint32_t time);

void rtc_setHour(uint8_t hr);
void rtc_setMinute(uint8_t min);
void rtc_setSecond(uint8_t sec);

uint32_t rtc_getTime();

void rtc_incTime();

#endif /* SRC_RTC_H_ */

