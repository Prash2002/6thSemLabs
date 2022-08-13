#include "NUC1xx.h"
#include "Driver\DrvSYS.h"
#include "Driver\DrvGPIO.h"
#include "DrvADC.h"
#include "LCD_Driver.h"
#include "Seven_Segment.h"

int main()
{
    int value;
    char TEXT[16];

    UNLOCKREG();
    // in driver search for 12mz xtl =1 and hclk = 0
    SYSCLK->PWRCON.XTL12M_EN = 1;
    SYSCLK->CLKSEL0.HCLK_S = 0;
    LOCKREG();

    Initial_panel();
    clr_all_panel();
    print_lcd(0, "Variable Resistor");

    DrvADC_Open(ADC_SINGLE_END, ADC_SINGLE_OP, 0x40, INTERNAL_HCLK, 1);

    while (1)
    {
        DrvADC_StartConvert();
        while (DrvADC_IsConversionDone == FALSE)
            ;
        value = ADC->ADDR[6].RSLT & 0xFFF;
        sprintf(TEXT, "Value: %d", value);
        print_lcd(1, TEXT);
    }
}