// get port and identify a0, a1, a2, a3

#include "NUC1xx"
#include "Driver\DrvSYS.h"
#include "Driver\DrvGPIO.h"
#include "NUC1xx-LB_002\LCD_Driver.h"

int main()
{
    UNLOCKREG();
    DrvSYS_Open(48000000);
    LOCKREG();

    char TEXT0[16] = "Sample Text";
    char TEXT1[16];
    int num;

    Initial_panel();
    clr_all_panel();

    print_lcd(0, TEXT0);

    while (1)
    {
        num = DrvGPIO_GetPortBits(E_GPA);
        sprintf(TEXT1, "Value: %d", num);
        print_lcd(1, TEXT1);
        if (num == 0xfffe)
            print_lcd(2, "A0");
        if (num == 0xfffd)
            print_lcd(2, "A1");
        if (num == 0xfffb)
            print_lcd(2, "A2");
        if (num == 0xfff7)
            print_lcd(2, "A3");
    }
}