// toggle LED at port c12 to c15 based on interrupt
#include <stdio.h>
#include "NUC1xx"
#include "Driver\DrvSYS.h"
#include "Driver\DrvGPIO.h"

void EINT1Callback()
{
    DrvGPIO_ClrBit(E_GPC, 12);
    DrvSYS_Delay(1000);
    DrvGPIO_SetBit(E_GPC, 12);
    DrvSYS_Delay(1000);

    DrvGPIO_ClrBit(E_GPC, 13);
    DrvSYS_Delay(1000);
    DrvGPIO_SetBit(E_GPC, 13);
    DrvSYS_Delay(1000);

    DrvGPIO_ClrBit(E_GPC, 14);
    DrvSYS_Delay(1000);
    DrvGPIO_SetBit(E_GPC, 14);
    DrvSYS_Delay(1000);

    DrvGPIO_ClrBit(E_GPC, 15);
    DrvSYS_Delay(1000);
    DrvGPIO_SetBit(E_GPC, 15);
    DrvSYS_Delay(1000);
}

void INITLed()
{
    DrvGPIO_Open(E_GPC, 12, E_IO_OUTPUT);
    DrvGPIO_SetBit(E_GPC, 12);

    DrvGPIO_Open(E_GPC, 13, E_IO_OUTPUT);
    DrvGPIO_SetBit(E_GPC, 13);

    DrvGPIO_Open(E_GPC, 14, E_IO_OUTPUT);
    DrvGPIO_SetBit(E_GPC, 14);

    DrvGPIO_Open(E_GPC, 15, E_IO_OUTPUT);
    DrvGPIO_SetBit(E_GPC, 15);
}

void main()
{
    UNLOCKREG();
    DrvSYS_Open(48000000);
    LOCKREG();

    INITLed();
    DrvGPIO_Open(E_GPB, 15, E_IO_INPUT);
    DrvGPIO_EnableEINT1(E_IO_BOTH_EDGE, E_MODE_EDGE, EINT1Callback);
    while (1)
        ;
}