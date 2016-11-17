/*
 * btn.h
 *
 *  Created on: 22 Apr 2016
 *      Author: cfurter
 */

#ifndef SRC_BTN_H_
#define SRC_BTN_H_

/* External button defines */

/* Setup Button port */
#define BTN_1_DDR DDRC
#define BTN_1_PORT PORTC
#define BTN_1_PIN PINC
#define BTN_1_INPUTPIN PC3

#define BTN_2_DDR DDRC
#define BTN_2_PORT PORTC
#define BTN_2_PIN PINC
#define BTN_2_INPUTPIN PC5

#define BTN_3_DDR DDRC
#define BTN_3_PORT PORTC
#define BTN_3_PIN PINC
#define BTN_3_INPUTPIN PC2

#define BTN_4_DDR DDRC
#define BTN_4_PORT PORTC
#define BTN_4_PIN PINC
#define BTN_4_INPUTPIN PC4

typedef enum {
	ON,
	OFF
} btn_state;

/* Function Prototypes */
void btn_init();
void btn_checkState();

#endif /* SRC_BTN_H_ */
