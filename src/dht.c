/*
DHT Library 0x03

copyright (c) Davide Gironi, 2012

Released under GPLv3.
Please refer to LICENSE file for licensing information.
 */


#include <stdio.h>
#include <string.h>
#include <avr/io.h>
#include <util/delay.h>

#include <stdlib.h>

#include "dht.h"
#include "iicDisplay/lcdpcf8574.h"

/*
 * get data from sensor
 */
int8_t dht_getdata(int8_t *tempInt, uint8_t *tempDec, int8_t *humidInt, uint8_t *humidDec)
{
    uint8_t bits[5];
    uint8_t i,j = 0;

    memset(bits, 0, sizeof(bits));

    //reset port
    DHT_DDR |= (1<<DHT_INPUTPIN); //output
    DHT_PORT |= (1<<DHT_INPUTPIN); //high
    _delay_ms(100);

    //send request
    DHT_PORT &= ~(1<<DHT_INPUTPIN); //low
    _delay_us(500);

    DHT_PORT |= (1<<DHT_INPUTPIN); //high
    DHT_DDR &= ~(1<<DHT_INPUTPIN); //input
    _delay_us(40);

    //check start condition 1
    if((DHT_PIN & (1<<DHT_INPUTPIN))) {
        return -1;
    }
    _delay_us(80);
    //check start condition 2
    if(!(DHT_PIN & (1<<DHT_INPUTPIN))) {
        return -1;
    }
    _delay_us(80);

    //read the data
    uint16_t timeoutcounter = 0;
    for (j=0; j<5; j++) { //read 5 byte
        uint8_t result=0;
        for(i=0; i<8; i++) {//read every bit
            timeoutcounter = 0;
            while(!(DHT_PIN & (1<<DHT_INPUTPIN))) { //wait for an high input (non blocking)
                timeoutcounter++;
                if(timeoutcounter > DHT_TIMEOUT) {
                    return -1; //timeout
                }
            }
            _delay_us(30);
            if(DHT_PIN & (1<<DHT_INPUTPIN)) //if input is high after 30 us, get result
                result |= (1<<(7-i));
            timeoutcounter = 0;
            while(DHT_PIN & (1<<DHT_INPUTPIN)) { //wait until input get low (non blocking)
                timeoutcounter++;
                if(timeoutcounter > DHT_TIMEOUT) {
                    return -1; //timeout
                }
            }
        }
        bits[j] = result;
    }

    //reset port
    DHT_DDR |= (1<<DHT_INPUTPIN); //output
    DHT_PORT |= (1<<DHT_INPUTPIN); //low
    _delay_ms(100);

    //check checksum
    if ((uint8_t)(bits[0] + bits[1] + bits[2] + bits[3]) == bits[4]) {
        //return temperature and humidity
        uint16_t rawhumidity = bits[0]<<8 | bits[1];
        uint16_t rawtemperature = bits[2]<<8 | bits[3];

        int8_t tempI = (int8_t)(rawtemperature/10);
        uint8_t tempD = (uint8_t)((rawtemperature - (tempI*10))*100);
        *tempInt = tempI;
        *tempDec = tempD;

        int8_t humidI = (int8_t)(rawhumidity/10);
        uint8_t humidD = (uint8_t)((rawhumidity - (humidI*10))*10);
        *humidInt = humidI;
        *humidDec = humidD;

        return 0;
    }

    return -1;
}


void dht_printdata(uint8_t lineNr)
{
    int8_t tempI;
    uint8_t tempD;
    int8_t humidI;
    uint8_t humidD;
    if (dht_getdata(&tempI,&tempD,&humidI,&humidD) != -1)
    {
        char sTemp[20] =  "Temperature : ";
        itoa(tempI, sTemp+14,10);
        sTemp[16] = '.';
        itoa(tempD, sTemp+17,10);
        sTemp[19] = 0x00;
        lcd_gotoxy(0,lineNr);

        lcd_puts(sTemp);

        char sHumid[20] =  "Humidity    : ";
        itoa(humidI, sHumid+14,10);
        sHumid[16] = '.';
        itoa(humidD, sHumid+17,10);

        lcd_gotoxy(0,lineNr+1);
        lcd_puts(sHumid);

    }
}

