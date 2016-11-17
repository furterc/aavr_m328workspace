/*
DHT Library 0x03

copyright (c) Davide Gironi, 2012

Released under GPLv3.
Please refer to LICENSE file for licensing information.

References:
  - DHT-11 Library, by Charalampos Andrianakis on 18/12/11
*/


#ifndef DHT_H_
#define DHT_H_

#include <stdio.h>
#include <avr/io.h>

//setup port
#define DHT_DDR DDRC
#define DHT_PORT PORTC
#define DHT_PIN PINC
#define DHT_INPUTPIN PC3

//sensor type
#define DHT_DHT11 1
#define DHT_DHT22 2
#define DHT_TYPE DHT_DHT22

//enable decimal precision (float)

#define DHT_FLOAT 1

//timeout retries
#define DHT_TIMEOUT 200

//functions

int8_t dht_getdata(int8_t *tempInt, uint8_t *tempDec, int8_t *humidInt, uint8_t *humidDec);
void dht_printdata(uint8_t lineNr);

#endif
