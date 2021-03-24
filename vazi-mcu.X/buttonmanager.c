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

void handleButtonUp() {
    __delay_ms(5);
    BUTTON_UP_GetValue()        ?   printf("br-up\n\r")     :   printf("bp-up\n\r");
}

void handleButtonDown() {
    __delay_ms(5);
    BUTTON_DOWN_GetValue()      ?   printf("br-down\n\r")   :   printf("bp-down\n\r");
}

void handleButtonLeft() {
    __delay_ms(5);
    BUTTON_LEFT_GetValue()      ?   printf("br-left\n\r")   :   printf("bp-left\n\r");
}

void handleButtonRight() {
    __delay_ms(5);
    BUTTON_RIGHT_GetValue()     ?   printf("br-right\n\r")  :   printf("bp-right\n\r");
}

void handleButtonSelect() {
    __delay_ms(5);
    BUTTON_SELECT_GetValue()    ?   printf("br-select\n\r") :   printf("bp-select\n\r");
}

void handleButtonStart() {
    __delay_ms(5);
    BUTTON_START_GetValue()     ?   printf("br-start\n\r")  :   printf("bp-start\n\r");
}

void handleButtonA() {
    __delay_ms(5);
    BUTTON_A_GetValue()         ?   printf("br-a\n\r")      :   printf("bp-a\n\r");
}

void handleButtonB() {
    __delay_ms(5);
    BUTTON_B_GetValue()         ?   printf("br-b\n\r")      :   printf("bp-b\n\r");
}

