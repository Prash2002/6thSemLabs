// pwm vary intensity of a12
#include "NUC1xx"
#include "Driver\DrvSYS.h"
#include "Driver\DrvGPIO.h"
#include "NUC1xx-LB_002\LCD_Driver.h"
#include "Driver\DrvPWM.h"

void main()
{
    uint16_t x = 0xffff;
    UNLOCKREG();
    SYSCLK->PWRCON.XTL12M_EN = 1;
    SYSCLK->CLKSEL0.HCLK_S = 0;
    LOCKREG();

    InitPWM();

    while (1)
    {
        PWMA->CON = x;
        x = x - 1;
        DrvSYS_Delay(5000);
    }
}
