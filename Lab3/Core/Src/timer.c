/*
 * timer.c
 *
 *  Created on: Oct 20, 2022
 *      Author: shiba
 */

#include"timer.h"

int TIMER_CYCLE = 10; // timer cycle need change when we modify time interrupt
// timer for automatic mode road 1
int timer0_flag = 0;
int timer0_counter = 0;
// timer for automatic mode road 2
int timer1_flag = 0;
int timer1_counter = 0;
// timer for blink led with F = 2Hz
int timerLed_flag = 0;
int timerLed_counter = 0;
// timer for scan led 7 seg
int timerLed7Seg_flag = 0;
int timerLed7Seg_counter = 0;
// timer for count down time when display on led 7 seg
int timerCountDown_flag = 0;
int timerCountDown_counter = 0;
// function to set counter for timer0
void setTimer0(int duration) {
	timer0_flag = 0;
	timer0_counter = duration / TIMER_CYCLE;
}
// function to set counter for timer1
void setTimer1(int duration) {
	timer1_flag = 0;
	timer1_counter = duration / TIMER_CYCLE;
}
// function to set counter for timer Led blink
void setTimerLed(int duration) {
	timerLed_flag = 0;
	timerLed_counter = duration / TIMER_CYCLE;
}
// function to set counter for timer scan led7seg
void setTimerLed7Seg(int duration) {
	timerLed7Seg_flag = 0;
	timerLed7Seg_counter = duration / TIMER_CYCLE;
}
// function to set counter for timer count down time
void setTimerCountDown(int duration) {
	timerCountDown_flag = 0;
	timerCountDown_counter = duration / TIMER_CYCLE;
}
// run timer
void timerRun() {
	if (timer0_counter > 0) {
		timer0_counter--;
		if (timer0_counter <= 0) {
			timer0_flag = 1;
		}
	}
	if (timer1_counter > 0) {
		timer1_counter--;
		if (timer1_counter <= 0) {
			timer1_flag = 1;
		}
	}
	if (timerLed_counter > 0) {
		timerLed_counter--;
		if (timerLed_counter <= 0) {
			timerLed_flag = 1;
		}
	}
	if (timerLed7Seg_counter > 0) {
		timerLed7Seg_counter--;
		if (timerLed7Seg_counter <= 0) {
			timerLed7Seg_flag = 1;
		}
	}

	if (timerCountDown_counter > 0) {
		timerCountDown_counter--;
		if (timerCountDown_counter <= 0) {
			timerCountDown_flag = 1;
		}
	}
}
