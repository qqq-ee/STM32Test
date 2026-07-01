#include "ti_msp_dl_config.h"
#include "Delay.h"
#include "OLED.h"
#include "Key.h"
#include "Motor.h"


uint8_t i;


uint8_t KeyNum;
int8_t Speed;

int main(void)
{
    SYSCFG_DL_init();
	 OLED_Init ();
	 OLED_ShowString (1,1,"Hello Word!");

	
    while (1)
    {
		 KeyNum = Key_GetNum();
		 
		 if (KeyNum == 1)
		 {
			 Speed += 20;
			 if (Speed > 100)
			 {
				 Speed = -100;
			 }
		 }
		 
		 Motor_SetSpeed(Speed);
		 
		 OLED_ShowSignedNum(1, 7, Speed, 3);
		 
		 Delay_ms (100);
    }
}