#include "ti_msp_dl_config.h"
#include "PWM.h"


void Motor_SetSpeed(int8_t Speed)
{
	if (Speed >= 0)
	{
		DL_GPIO_setPins (Motor_PORT , Motor_INA_PIN);
		DL_GPIO_clearPins (Motor_PORT , Motor_INB_PIN);
		CaptureCompare1(Speed);
	}
	else
	{
		DL_GPIO_clearPins (Motor_PORT , Motor_INA_PIN);
		DL_GPIO_setPins (Motor_PORT , Motor_INB_PIN);
		CaptureCompare1(-Speed);
	}
}
