/*
 * timer.h
 *
 *  Created on: Oct 20, 2022
 *      Author: shiba
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"

extern int timer0_flag;
extern int timer1_flag;
extern int timerLed7Seg_flag;
extern int timerLed_flag;
extern int timerCountDown_flag;

void setTimer0(int duration);

void setTimer1(int duration);

void setTimerLed7Seg(int duration);

void setTimerCountDown(int duration);

void setTimerLed(int duration);

void timerRun();

#endif /* INC_TIMER_H_ */
