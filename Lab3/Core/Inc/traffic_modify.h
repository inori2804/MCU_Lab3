/*
 * traffic_manual.h
 *
 *  Created on: Oct 22, 2022
 *      Author: shiba
 */

#ifndef INC_TRAFFIC_MODIFY_H_
#define INC_TRAFFIC_MODIFY_H_

#include"global.h"
#include"timer.h"
#include"set_traffic_light.h"
#include"traffic_blink.h"

#include"button.h"
#include"led7Seg.h"

// FSM for MODIFY MODE
void fsm_traffic_modify();

#endif /* INC_TRAFFIC_MODIFY_H_ */
