/*
 * traffic_automatic.h
 *
 *  Created on: Oct 22, 2022
 *      Author: shiba
 */

#ifndef INC_TRAFFIC_AUTOMATIC_H_
#define INC_TRAFFIC_AUTOMATIC_H_

#include"global.h"
#include"timer.h"
#include"set_traffic_light.h"
#include"traffic_blink.h"

#include"button.h"
#include"led7Seg.h"

// check if change mode from AUTO MODE to MODIFY MODE
void is_change_mode();
// FSM for AUTO MODE
void fsm_traffic_automatic();

#endif /* INC_TRAFFIC_AUTOMATIC_H_ */
