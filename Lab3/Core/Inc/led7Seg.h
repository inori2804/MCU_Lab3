/*
 * led7Seg.h
 *
 *  Created on: Oct 25, 2022
 *      Author: shiba
 */

#ifndef INC_LED7SEG_H_
#define INC_LED7SEG_H_

#include"main.h"
#include"global.h"
#include"timer.h"

// display value with input on led7seg
void display7SEG(int num);
// scan led7seg and display value with input is time1 time2
void setEnableSignal(int index, int time1, int time2);

#endif /* INC_LED7SEG_H_ */
