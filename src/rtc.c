/*
 * rtc.c
 *
 *  Created on: 07 Apr 2016
 *      Author: cfurter
 */

#include "rtc.h"
#include "config.h"
#include "iicDisplay/lcdpcf8574.h"

#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>

/* RTC defines */
#define RTC_C2_TNT2_reg     0x05
#define RTC_C2_DIV_TIME     1000


struct time{
    uint8_t uHours;
    uint8_t uMinutes;
    uint8_t uSeconds;
} rtcTime;



void inc_Time();
uint16_t divTime;

void rtc_init()
{
    /* Set initial values of Struct */
    rtcTime.uSeconds = 0;
    rtcTime.uMinutes = 0;
    rtcTime.uHours   = 0;

//    lcd_gotoxy(8,0);
//    lcd_puts(":");
//
//    lcd_gotoxy(11,0);
//    lcd_puts(":");

}

void rtc_setTime(uint32_t time)
{
    uTime = time;
}

void rtc_setHour(uint8_t hr)
{
    rtcTime.uHours = hr;
}
void rtc_setMinute(uint8_t min)
{
    rtcTime.uMinutes = min;
}
void rtc_setSecond(uint8_t sec)
{
    rtcTime.uSeconds = sec;
}



uint32_t rtc_getTime()
{
    return uTime;
}

void print_Time()
{
    printf("%02d:%02d:%02d\r\n", rtcTime.uHours, rtcTime.uMinutes, rtcTime.uSeconds);
}

void print_lcd_Time()
{
    uint8_t currSeconds = rtcTime.uSeconds;

    char tHr[4];
    itoa(rtcTime.uHours, tHr, 10);
    char tMin[4];
    itoa(rtcTime.uMinutes, tMin, 10);
    char tSec[4];
    itoa(currSeconds, tSec, 10);
    lcd_gotoxy(6,0);


    if (rtcTime.uHours < 9)
        lcd_puts("0");
    lcd_puts(tHr);
    lcd_puts(":");
    if (rtcTime.uMinutes < 10)
        lcd_puts("0");
    lcd_puts(tMin);
    lcd_puts(":");
    if (currSeconds < 10)
        lcd_puts("0");
    lcd_puts(tSec);
}

//void lcd_updateHours()
//{
//    lcd_gotoxy(6,0);
//    char tHr[3];
//    itoa(rtcTime.uHours, tHr, 10);
//    if (rtcTime.uHours < 10)
//        lcd_puts("0");
//    lcd_puts(tHr);
//}
//
//void lcd_updateMinutes()
//{
//    lcd_gotoxy(9,0);
//    char tMin[3];
//    itoa(rtcTime.uMinutes, tMin, 10);
//    if (rtcTime.uMinutes < 10)
//        lcd_puts("0");
//    lcd_puts(tMin);
//}
//
//void lcd_updateSeconds()
//{
//    lcd_gotoxy(12,0);
//    char tSec[3];
//    itoa(rtcTime.uSeconds, tSec, 10);
//    if (rtcTime.uSeconds < 10)
//        lcd_puts("0");
//    lcd_puts(tSec);
//}

void inc_Time()
{
    if(rtcTime.uSeconds < 59)
        rtcTime.uSeconds++;
    else
    {
        rtcTime.uSeconds = 0;
        if(rtcTime.uMinutes < 59)
            rtcTime.uMinutes++;
        else
        {
            rtcTime.uMinutes = 0;
            if (rtcTime.uHours < 23)
                rtcTime.uHours++;
            else
                rtcTime.uHours = 0;
        }

    }

}

void rtc_incTime()
{
    if (divTime == (RTC_C2_DIV_TIME))
    {
        divTime = 0;
        inc_Time();
    }
    divTime++;
    uTime++;
}
