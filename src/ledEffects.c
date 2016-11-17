/*
 * ledEffects.c
 *
 *  Created on: Jul 3, 2016
 *      Author: christo-laptop
 */

#include "ledEffects.h"

#include <stdint-gcc.h>


uint16_t pwmEffectsFlag;

uint8_t tmpDuty0;
uint8_t tmpDuty1;
uint8_t tmpDuty2;
uint8_t tmpDuty3;
uint8_t tmpDuty4;
uint8_t tmpDuty5;
uint8_t tmpDuty6;
uint8_t tmpDuty7;
uint8_t tmpDuty8;

void pwmEffectsRun()
{
//    if (!pwmEffectsFlag)
//        return;
//    if ((pwmZeroDuty != tmpDuty0) && (pwmEffectsFlag & (1<<0)))
//    {
//        if (pwmZeroDuty < tmpDuty0)
//            pwmZeroDuty++;
//        else
//            pwmZeroDuty--;
//        if (pwmZeroDuty == tmpDuty0)
//            pwmEffectsFlag &= ~(1<<0);
//    }
//    if ((pwmOneDuty != tmpDuty1) && (pwmEffectsFlag & (1<<1)))
//    {
//        if (pwmOneDuty < tmpDuty1)
//            pwmOneDuty++;
//        else
//            pwmOneDuty--;
//        if (pwmOneDuty == tmpDuty1)
//            pwmEffectsFlag &= ~(1<<1);
//    }
//    if ((pwmTwoDuty != tmpDuty2) && (pwmEffectsFlag & (1<<2)))
//    {
//        if (pwmTwoDuty < tmpDuty2)
//            pwmTwoDuty++;
//        else
//            pwmTwoDuty--;
//        if (pwmTwoDuty == tmpDuty2)
//            pwmEffectsFlag &= ~(1<<2);
//    }
//    if ((pwmThreeDuty != tmpDuty3) && (pwmEffectsFlag & (1<<3)))
//    {
//        if (pwmThreeDuty < tmpDuty3)
//            pwmThreeDuty++;
//        else
//            pwmThreeDuty--;
//        if (pwmThreeDuty == tmpDuty3)
//            pwmEffectsFlag &= ~(1<<3);
//    }
//    if ((pwmFourDuty != tmpDuty4) && (pwmEffectsFlag & (1<<4)))
//    {
//        if (pwmFourDuty < tmpDuty4)
//            pwmFourDuty++;
//        else
//            pwmFourDuty--;
//        if (pwmFourDuty == tmpDuty4)
//            pwmEffectsFlag &= ~(1<<4);
//    }
//    if ((pwmFiveDuty != tmpDuty5) && (pwmEffectsFlag & (1<<5)))
//    {
//        if (pwmFiveDuty < tmpDuty5)
//            pwmFiveDuty++;
//        else
//            pwmFiveDuty--;
//        if (pwmFiveDuty == tmpDuty5)
//            pwmEffectsFlag &= ~(1<<5);
//    }
//    if ((pwmSixDuty != tmpDuty6) && (pwmEffectsFlag & (1<< 6)))
//    {
//        if (pwmSixDuty < tmpDuty6)
//            pwmSixDuty++;
//        else
//            pwmSixDuty--;
//        if (pwmSixDuty == tmpDuty6)
//            pwmEffectsFlag &= ~(1<<6);
//    }
//    if ((pwmSevenDuty != tmpDuty7) && (pwmEffectsFlag & (1<< 7)))
//    {
//        if (pwmSevenDuty < tmpDuty7)
//            pwmSevenDuty++;
//        else
//            pwmSevenDuty--;
//        if (pwmSevenDuty == tmpDuty7)
//            pwmEffectsFlag &= ~(1<<7);
//    }
//    if ((pwmEightDuty != tmpDuty8) && (pwmEffectsFlag & (1<< 8)))
//    {
//        if (pwmEightDuty < tmpDuty8)
//            pwmEightDuty++;
//        else
//            pwmEightDuty--;
//        if (pwmEightDuty == tmpDuty8)
//            pwmEffectsFlag &= ~(1<<8);
//    }
}

void pwmEffects(uint8_t pwmChannel, uint8_t pwmDuty)
{

    switch (pwmChannel) {
    case 0:
    {
        tmpDuty0 = pwmDuty;
        pwmEffectsFlag |= (1<<0);
    }break;
    case 1:
    {
        tmpDuty1 = pwmDuty;
        pwmEffectsFlag |= (1<<1);
    }break;
    case 2:
    {
        tmpDuty2 = pwmDuty;
        pwmEffectsFlag |= (1<<2);
    }break;
    case 3:
    {
        tmpDuty3 = pwmDuty;
        pwmEffectsFlag |= (1<<3);
    }break;
    case 4:
    {
        tmpDuty4 = pwmDuty;
        pwmEffectsFlag |= (1<<4);
    }break;
    case 5:
    {
        tmpDuty5 = pwmDuty;
        pwmEffectsFlag |= (1<<5);
    }break;
    case 6:
    {
        tmpDuty6 = pwmDuty;
        pwmEffectsFlag |= (1<<6);
    }break;
    case 7:
    {
        tmpDuty7 = pwmDuty;
        pwmEffectsFlag |= (1<<7);
    }break;
    case 8:
    {
        tmpDuty8 = pwmDuty;
        pwmEffectsFlag |= (1<<8);
    }break;


    default:
        break;
    }

}

