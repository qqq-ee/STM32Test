#include "ti_msp_dl_config.h"
#include "Delay.h"

static uint8_t Key_State = 0;
static uint8_t Key_Count = 0;

uint8_t Key_GetNum(void)
{
    uint8_t key_val = DL_GPIO_readPins(Key_PORT, Key_PIN_21_PIN);
    
    switch(Key_State)
    {
        case 0:
            if(key_val == 0)
            {
                Key_Count = 0;
                Key_State = 1;
            }
            break;
        case 1:
            Key_Count++;
            if(Key_Count >= 5)
            {
                if(key_val == 0)
                {
                    Key_State = 2;
                    return 1;
                }
                else
                {
                    Key_State = 0;
                }
            }
            break;
        case 2:
            if(key_val != 0)
            {
                Key_Count = 0;
                Key_State = 0;
            }
            break;
    }
    
    return 0;
}