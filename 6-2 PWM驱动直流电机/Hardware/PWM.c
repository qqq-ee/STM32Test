#include "ti_msp_dl_config.h"
#include "Delay.h"


void CaptureCompare1 ( uint8_t Compare )
{
	DL_TimerG_setCaptureCompareValue(PWM_INST, Compare, GPIO_PWM_C1_IDX);
}
