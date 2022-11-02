/*
 * global.h
 *
 *  Created on: Oct 22, 2022
 *      Author: shiba
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define RED				100
#define GREEN			101
#define YELLOW			102

#define MODIFY_MODE 	1999
#define AUTO_MODE		2000

#define RED_MODE		2001
#define GREEN_MODE 		2002
#define YELLOW_MODE		2003

#define RED_MODIFY 		3000
#define	GREEN_MODIFY    3001
#define YELLOW_MODIFY 	3002

extern int status; // status variable for state in MODIFY MODE
extern int status_1; // status variable for state road 1 in AUTO MODE
extern int status_2; // status variable for state road 2 in AUTO MODE
// status variable for choose mode display led 7seg between AUTO MODE and MODIFY MODE
extern int ledMode;
// time variable
extern int time_red;
extern int time_green;
extern int time_yellow;
// time buffer to save value and display on led7seg when modify in MODIFY MODE
extern int time_modify;

#endif /* INC_GLOBAL_H_ */
