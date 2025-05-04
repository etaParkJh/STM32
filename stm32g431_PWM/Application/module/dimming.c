#include "dimming.h"

#define PWM_PULSE_MIN		0
#define PWM_PULSE_MAX		9999
#define DIMMING_LEVEL_MIN	0
#define DIMMING_LEVEL_MAX	99

static DimmingMode_t dimming_mode = DIMMING_NONE;
static uint8_t dimming_level = 0;

DimmingMode_t getDimmingMode(void)
{
	return dimming_mode;
}

void setDimmingMode(DimmingMode_t mode)
{
	dimming_mode = mode;
}

uint32_t dimmingLevelMapping(uint32_t current_val)
{
	return (uint32_t)map(current_val, PWM_PULSE_MIN, PWM_PULSE_MAX, DIMMING_LEVEL_MIN, DIMMING_LEVEL_MAX);
}

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
	if (htim != NULL && htim == &htim3)
	{
		if (dimming_level == DIMMING_LEVEL_MAX && dimming_mode == DIMMING_UP)
		{
			dimming_mode = DIMMING_DOWN;
		}
		else if (dimming_level == DIMMING_LEVEL_MIN && dimming_mode == DIMMING_DOWN)
		{
			dimming_mode = DIMMING_UP;
		}
	}
}

void dimmingProc(void)
{
	static uint32_t pre_time = 0;

	switch (dimming_mode)
	{
	case DIMMING_NONE:
		dimming_mode = DIMMING_UP;
		pre_time = HAL_GetTick();
		break;
	case DIMMING_UP:
		if (HAL_GetTick() - pre_time >= 10)
		{
			pre_time = HAL_GetTick();
			dimming_level = dimmingLevelMapping(htim3.Instance->CCR1);
			htim3.Instance->CCR1+=100;
		}
		break;
	case DIMMING_DOWN:
		if (HAL_GetTick() - pre_time >= 10)
		{
			pre_time = HAL_GetTick();
			dimming_level = dimmingLevelMapping(htim3.Instance->CCR1);
			htim3.Instance->CCR1-=100;
		}
		break;
	}
}
