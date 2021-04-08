/*
 * File:   buttonmanager.c
 * Author: ratik
 *
 * Created on March 23, 2021, 5:31 PM
 */

#include <xc.h>
#include <stdio.h>
#include "buttonmanager.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/device_config.h"

void handleButtonUp()
{
    __delay_ms(5);
    BUTTON_UP_GetValue() ? printf("br-up\n") : printf("bp-up\n");
}

void handleButtonDown()
{
    __delay_ms(5);
    BUTTON_DOWN_GetValue() ? printf("br-down\n") : printf("bp-down\n");
}

void handleButtonLeft()
{
    __delay_ms(5);
    BUTTON_LEFT_GetValue() ? printf("br-left\n") : printf("bp-left\n");
}

void handleButtonRight()
{
    __delay_ms(5);
    BUTTON_RIGHT_GetValue() ? printf("br-right\n") : printf("bp-right\n");
}

void handleButtonSelect()
{
    __delay_ms(5);
    BUTTON_SELECT_GetValue() ? printf("br-select\n") : printf("bp-select\n");
}

void handleButtonStart()
{
    __delay_ms(5);
    BUTTON_START_GetValue() ? printf("br-start\n") : printf("bp-start\n");
}

void handleButtonA()
{
    __delay_ms(5);
    BUTTON_A_GetValue() ? printf("br-a\n") : printf("bp-a\n");
}

void handleButtonB()
{
    __delay_ms(5);
    BUTTON_B_GetValue() ? printf("br-b\n") : printf("bp-b\n");
}
