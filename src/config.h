/*
 * config.h
 *
 *  Created on: 12 Apr 2016
 *      Author: cfurter
 */

#ifndef SRC_CONFIG_H_
#define SRC_CONFIG_H_

#define VT100_OFF

/*Color codes*/
#ifndef VT100_OFF
#define COLOR(__c,__x)      "\x1b[3" #__c "m" __x "\x1b[0m"
#define COLOR_BOLD(__c,__x) "\x1b[3" #__c ";1m" __x "\x1b[0m"
#define UNDERLINE(__x)      "\x1b[4m" __x "\x1b[0m"
#define CLEAR_SCREEN        "\x1b[2J\x1b[H"
#else
#define COLOR(__c,__x)  __x
#define COLOR_BOLD(__c,__x) __x
#define UNDERLINE(__x) __x
#define CLEAR_SCREEN
#endif
#define RED(__x)            COLOR(1, __x )
#define GREEN(__x)          COLOR(2, __x )
#define YELLOW(__x)         COLOR(3, __x )
#define BLUE(__x)           COLOR(4, __x )
#define MAGENTA(__x)        COLOR(5, __x )
#define CYAN(__x)           COLOR(6, __x )
#define RED_B(__x)          COLOR_BOLD(1, __x )
#define GREEN_B(__x)        COLOR_BOLD(2, __x )
#define YELLOW_B(__x)       COLOR_BOLD(3, __x )
#define BLUE_B(__x)         COLOR_BOLD(4, __x )
#define MAGENTA_B(__x)      COLOR_BOLD(5, __x )
#define CYAN_B(__x)         COLOR_BOLD(6, __x )

/* Message defines */
#define BMS_VERSION             "0.0.1 April 2016\r\n"
#define TERM                ">> "
//#define MSG_NO_BATTERY          "No battery connected\r\n"


/* UART defines*/
#define SYSTEM_CLOCK    16000000 //1Mhz
#define BAUDRATE        115200
#define MYUBBR ((SYSTEM_CLOCK / (BAUDRATE * 8UL))-1)


#endif /* SRC_CONFIG_H_ */
