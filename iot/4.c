// Write an embedded C prog to blink LED on int0 and buzzer int1

#include <stdio.h>
#include "NUC1xx"
#include "Driver\DrvSYS.h"
#include "Driver\DrvGPIO.h"

void EINT1Callback()
{
    DrvGPIO_ClrBit(E_GPB, 11);
    DrvSYS_Delay(5000);
    DrvGPIO_SetBit(E_GPB, 11);
    DrvSYS_Delay(5000);
}
void EINT0Callback()
{
    DrvGPIO_ClrBit(E_GPA, 12);
    DrvSYS_Delay(5000);
    DrvGPIO_SetBit(E_GPA, 12);
    DrvSYS_Delay(5000);
}
void INITLed()
{
    DrvGPIO_Open(E_GPB, 11, E_IO_OUTPUT);
    DrvGPIO_SetBit(E_GPB, 11);

    DrvGPIO_Open(E_GPA, 12, E_IO_OUTPUT);
    DrvGPIO_SetBit(E_GPA, 12);
}

void main()
{
    UNLOCKREG();
    DrvSYS_Open(48000000);
    LOCKREG();

    INITLed();
    DrvGPIO_Open(E_GPB, 14, E_IO_INPUT);
    DrvGPIO_Open(E_GPB, 15, E_IO_INPUT);
    DrvGPIO_EnableEINT0(E_IO_BOTH_EDGE, E_MODE_EDGE, EINT0Callback);
    DrvGPIO_EnableEINT1(E_IO_BOTH_EDGE, E_MODE_EDGE, EINT1Callback);

    while (1)
        ;
}
