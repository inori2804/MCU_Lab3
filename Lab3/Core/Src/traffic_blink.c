/*
 * traffic_blink.c
 *
 *  Created on: Oct 22, 2022
 *      Author: shiba
 */

#include"traffic_blink.h"
// blink specific traffic led
void traffic_blink(int state) {
	switch (state) {
	case RED:
		HAL_GPIO_TogglePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin);
		HAL_GPIO_TogglePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin);
		break;
	case GREEN:
		HAL_GPIO_TogglePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin);
		HAL_GPIO_TogglePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin);
		break;
	case YELLOW:
		HAL_GPIO_TogglePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin);
		HAL_GPIO_TogglePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin);
		break;
	default:
		break;
	}
}
