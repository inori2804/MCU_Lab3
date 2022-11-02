/*
 * led7Seg.c
 *
 *  Created on: Oct 25, 2022
 *      Author: shiba
 */

#include"led7Seg.h"

void display7SEG(int num) {
	switch (num) {
//		using output data register to set value for port B
	case 0: {
//			using operator & with 0xFF00 to reset 7bits low
		GPIOB->ODR &= 0xFF80;
//			set value to 8bits low by using operator & to retain 8bits high
		GPIOB->ODR |= 0x0040;
		break;
	}
	case 1: {
		GPIOB->ODR &= 0xFF80;
		GPIOB->ODR |= 0x0079;
		break;
	}
	case 2: {
		GPIOB->ODR &= 0xFF80;
		GPIOB->ODR |= 0x0024;
		break;
	}
	case 3: {
		GPIOB->ODR &= 0xFF80;
		GPIOB->ODR |= 0x0030;
		break;
	}
	case 4: {
		GPIOB->ODR &= 0xFF80;
		GPIOB->ODR |= 0x0019;
		break;
	}
	case 5: {
		GPIOB->ODR &= 0xFF80;
		GPIOB->ODR |= 0x0012;
		break;
	}
	case 6: {
		GPIOB->ODR &= 0xFF80;
		GPIOB->ODR |= 0x0002;
		break;
	}
	case 7: {
		GPIOB->ODR &= 0xFF80;
		GPIOB->ODR |= 0x0078;
		break;
	}
	case 8: {
		GPIOB->ODR &= 0xFF80;
		GPIOB->ODR |= 0x0000;
		break;
	}
	case 9: {
		GPIOB->ODR &= 0xFF80;
		GPIOB->ODR |= 0x0010;
		break;
	}
	default:
		GPIOB->ODR &= 0xFF80;
		break;
	}
}

void setEnableSignal(int index, int time1, int time2) {
	int buffer[4];
//	Logic to calculate value to display on led7seg
	buffer[0] = time1 / 10;
	buffer[1] = time1 % 10;
	buffer[2] = time2 / 10;
	buffer[3] = time2 % 10;
//	set enable signal and display
	switch (index) {
	case 0:
		HAL_GPIO_WritePin(EN_0_GPIO_Port, EN_0_Pin, RESET);
		HAL_GPIO_WritePin(EN_1_GPIO_Port, EN_1_Pin, SET);
		HAL_GPIO_WritePin(EN_2_GPIO_Port, EN_2_Pin, SET);
		HAL_GPIO_WritePin(EN_3_GPIO_Port, EN_3_Pin, SET);

		display7SEG(buffer[0]);
		break;
	case 1:
		HAL_GPIO_WritePin(EN_0_GPIO_Port, EN_0_Pin, SET);
		HAL_GPIO_WritePin(EN_1_GPIO_Port, EN_1_Pin, RESET);
		HAL_GPIO_WritePin(EN_2_GPIO_Port, EN_2_Pin, SET);
		HAL_GPIO_WritePin(EN_3_GPIO_Port, EN_3_Pin, SET);

		display7SEG(buffer[1]);
		break;
	case 2:
		HAL_GPIO_WritePin(EN_0_GPIO_Port, EN_0_Pin, SET);
		HAL_GPIO_WritePin(EN_1_GPIO_Port, EN_1_Pin, SET);
		HAL_GPIO_WritePin(EN_2_GPIO_Port, EN_2_Pin, RESET);
		HAL_GPIO_WritePin(EN_3_GPIO_Port, EN_3_Pin, SET);

		display7SEG(buffer[2]);
		break;
	case 3:
		HAL_GPIO_WritePin(EN_0_GPIO_Port, EN_0_Pin, SET);
		HAL_GPIO_WritePin(EN_1_GPIO_Port, EN_1_Pin, SET);
		HAL_GPIO_WritePin(EN_2_GPIO_Port, EN_2_Pin, SET);
		HAL_GPIO_WritePin(EN_3_GPIO_Port, EN_3_Pin, RESET);

		display7SEG(buffer[3]);
		break;
	default:
		HAL_GPIO_WritePin(EN_0_GPIO_Port, EN_0_Pin, RESET);
		HAL_GPIO_WritePin(EN_1_GPIO_Port, EN_1_Pin, RESET);
		HAL_GPIO_WritePin(EN_2_GPIO_Port, EN_2_Pin, RESET);
		HAL_GPIO_WritePin(EN_3_GPIO_Port, EN_3_Pin, RESET);
		break;
	}
}

