/*
 * trafic_manual.c
 *
 *  Created on: Oct 22, 2022
 *      Author: shiba
 */

#include"traffic_modify.h"

void fsm_traffic_modify() {
	switch (status) {
	case RED_MODE:
//		TODO
		if (timerLed_flag == 1) {
			setTimerLed(500);
			traffic_blink(RED);
		}
//		Change mode from RED MODE to YELLOW MODE
		if (is_button1_pressed()) {
			clearLight();
			status = YELLOW_MODE;

			time_modify = 0;
		}
//		Change mode from RED MODE to RED MODIFY MODE
		if (is_button2_pressed()) {
			status = RED_MODIFY;
			time_red = 0;
		}
		break;
	case RED_MODIFY:
		//TODO
		if (timerLed_flag == 1) {
			setTimerLed(500);
			traffic_blink(RED);
		}
//		Change mode from RED MODIFY MODE to RED MODE
		if (is_button3_pressed()) {
			status = RED_MODE;
		}
		break;
	case YELLOW_MODE:
//		TODO
		if (timerLed_flag == 1) {
			setTimerLed(500);
			traffic_blink(YELLOW);
		}
//		Change mode from YELLOW MODE to GREEN MODE
		if (is_button1_pressed()) {
			clearLight();
			status = GREEN_MODE;

			time_modify = 0;
		}
//		Change mode from YELLOW MODE to YELLOW MODIFY MODE
		if (is_button2_pressed()) {
			status = YELLOW_MODIFY;
			time_yellow = 0;
		}
		break;
	case YELLOW_MODIFY:
		//TODO
		if (timerLed_flag == 1) {
			setTimerLed(500);
			traffic_blink(YELLOW);
		}
//		Change mode from YELLOW MODIFY MODE to YELLOW MODE
		if (is_button3_pressed()) {
			status = YELLOW_MODE;
		}
		break;
	case GREEN_MODE:
//		TODO
		if (timerLed_flag == 1) {
			setTimerLed(500);
			traffic_blink(GREEN);
		}
//		Change mode from MODIFY MODE to AUTO MODE
		if (is_button1_pressed()) {
			clearLight();
			ledMode = AUTO_MODE;
			status = AUTO_MODE;

			status_1 = RED;
			status_2 = GREEN;

			setTimer0(time_red * 1000);
			setTimer1(time_green * 1000);

			time1 = time_red;
			time2 = time_green;

			time_modify = 0;
		}
//		Change mode from GREEN MODE to GREEN MODIFY MODE
		if (is_button2_pressed()) {
			status = GREEN_MODIFY;
			time_green = 0;
		}
		break;
	case GREEN_MODIFY:
		//TODO
		if (timerLed_flag == 1) {
			setTimerLed(500);
			traffic_blink(GREEN);
		}
//		Change mode from GREEN MODIFY MODE to GREEN MODE
		if (is_button3_pressed()) {
			status = GREEN_MODE;
		}
		break;
	default:
		break;
	}
}
