/*
 * traffic_automatic.c
 *
 *  Created on: Oct 22, 2022
 *      Author: shiba
 */

#include"traffic_automatic.h"

int SCALE = 1000;
//	Set default time when using first time
int time_red = 5;
int time_green = 3;
int time_yellow = 2;
//	Set default value time display on led7SEG when using first time
int time1 = 5;
int time2 = 3;

//	check if change from AUTO MODE to MODIFY MODE
void is_change_mode() {
	if (is_button1_pressed()) {
		clearLight();
		status = RED_MODE;
		ledMode = MODIFY_MODE;

		status_1 = MODIFY_MODE;
		status_2 = MODIFY_MODE;

		time_modify = 0;
	}
}
//	FSM for run automatic traffic led
void fsm_traffic_automatic() {
//	FSM for road 1
	switch (status_1) {
	case RED:
//		TODO
		set_traffic_light(RED, 1);
//		calculate count down time to display on led 7 SEG
//		because cycle time count down for led in each road is 1s
//		so calculate time for two led in same timer
		if (timerCountDown_flag == 1) {
			setTimerCountDown(1000);
			time1--;
			time2--;
		}
//		Change mode
		if (timer0_flag == 1) {
			setTimer0(time_green * SCALE);
			status_1 = GREEN;
			time1 = time_green;
		}
		is_change_mode();
		break;
	case GREEN:
//		TODO
		set_traffic_light(GREEN, 1);
		if (timerCountDown_flag == 1) {
			setTimerCountDown(1000);
			time1--;
			time2--;
		}
//		Change mode
		if (timer0_flag == 1) {
			setTimer0(time_yellow * SCALE);
			status_1 = YELLOW;
			time1 = time_yellow;
		}
		is_change_mode();
		break;
	case YELLOW:
//		TODO
		set_traffic_light(YELLOW, 1);
//		Change mode
		if (timerCountDown_flag == 1) {
			setTimerCountDown(1000);
			time1--;
			time2--;
		}
		if (timer0_flag == 1) {
			setTimer0(time_red * SCALE);
			status_1 = RED;
			time1 = time_red;
		}
		is_change_mode();
		break;
	default:
		break;
	}
//  FSM for road 2
	switch (status_2) {
	case RED:
//		TODO
		set_traffic_light(RED, 2);
//		Change mode
		if (timer1_flag == 1) {
			setTimer1(time_green * SCALE);
			status_2 = GREEN;
			time2 = time_green;
		}
		is_change_mode();
		break;
	case GREEN:
//		TODO
		set_traffic_light(GREEN, 2);
//		Change mode
		if (timer1_flag == 1) {
			setTimer1(time_yellow * SCALE);
			status_2 = YELLOW;
			time2 = time_yellow;
		}
		is_change_mode();
		break;
	case YELLOW:
//		TODO
		set_traffic_light(YELLOW, 2);
//		Change mode
		if (timer1_flag == 1) {
			setTimer1(time_red * SCALE);
			status_2 = RED;
			time2 = time_red;
		}
		is_change_mode();
		break;
	default:
		break;
	}
}
