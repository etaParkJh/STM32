/*
 * dimming.h
 *
 *  Created on: May 4, 2025
 *      Author: robo7
 */

#ifndef MODULE_DIMMING_H_
#define MODULE_DIMMING_H_

#include "driver.h"
#include "common.h"


typedef enum
{
	DIMMING_NONE,
	DIMMING_UP,
	DIMMING_DOWN
}DimmingMode_t;


uint32_t dimmingLevelMapping(uint32_t current_val);
void dimmingProc(void);
void setDimmingMode(DimmingMode_t mode);
DimmingMode_t getDimmingMode(void);
#endif /* MODULE_DIMMING_H_ */
