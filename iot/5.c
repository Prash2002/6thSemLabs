// display string on interrupt

#include "NUC1xx"
#include "Driver\DrvGPIO.h"
#include "Driver\DrvSYS.h"
#include "NUC1xx-LB_002\LCD_Driver.h"

void EINT1Callback()
{
    Initial_panel();
    clr_all_panel();
    print_lcd(0, "test msg");
}

void main()
{
    UNLOCKREG();
    DrvSYS_Open(48000000);
    LOCKREG();

    DrvGPIO_Open(E_GPB, 15, E_IO_INPUT);
    DrvGPIO_EnableEINT1(E_IO_BOTH_EDGE, E_MODE_EDGE, EINT1Callback);
    while (1)
        ;
}