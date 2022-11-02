/*
 * button.h
 *
 *  Created on: Sep 27, 2022
 *      Author: shiba
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "global.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

extern int button1_flag;
extern int button2_flag;
extern int button3_flag;

extern int time1; // time value display on led7seg 1 and 2
extern int time2; // time value display on led7seg 3 and 4

unsigned char is_button1_pressed(); // check if button 1 is pressed
unsigned char is_button2_pressed(); // check if button 2 is pressed
unsigned char is_button3_pressed(); // check if button 3 is pressed

void getKeyInput();

#endif /* INC_BUTTON_H_ */
