/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18LF45K42
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include <pic18lf45k42.h>

#include "mcc_generated_files/mcc.h"
#include "rgbmanager.h"
#include "buttonmanager.h"

/*
 * Main application
 * 
 * 
 * RGB UART Receive Schema:
 * 
 * 24 bytes
 * Bytes    0-5     :   RRGGBB (LED #1)
 * Bytes    6-11    :   RRGGBB (LED #2)
 * Bytes    12-17   :   RRGGBB (LED #3)
 * Bytes    18-23   :   RRGGBB (LED #4)
 * 
 * 
 * Button Press UART Send Schema:
 * Newline delimited
 * "{action (button press (bp))}-{button name (up)}\n"
 * 
 * Up Button Press          -   "bp-up\n"
 * Down Button Press        -   "bp-down\n"
 * Left Button Press        -   "bp-left\n"
 * Right Button Press       -   "bp-right\n"
 * Select Button Press      -   "bp-select\n"
 * Start Button Press       -   "bp-start\n"
 * A Button Press           -   "bp-a\n"
 * B Button Press           -   "bp-b\n"
 * 
 */

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();
        
    // Turn off all LEDs 
    clearAllRGB();
 
    // Set button interrupt handlers
    IOCAF6_SetInterruptHandler(handleButtonUp);        // Up
    IOCCF0_SetInterruptHandler(handleButtonRight);     // Right
    IOCCF1_SetInterruptHandler(handleButtonLeft);      // Left
    IOCCF2_SetInterruptHandler(handleButtonDown);      // Down
    IOCBF5_SetInterruptHandler(handleButtonSelect);    // Select
    IOCBF4_SetInterruptHandler(handleButtonStart);     // Start
    IOCBF3_SetInterruptHandler(handleButtonA);         // A
    IOCBF2_SetInterruptHandler(handleButtonB);         // B
    
    // Setup UART input handling
    UART1_SetRxInterruptHandler(handleUARTInput);
    
    // Set power save mode operation state
    DOZE0 = 1;
    DOZE1 = 1;
    DOZE2 = 1;
    
//    setSingleRGB(100, 100, 100);
//    setSingleRGB(0, 100, 50);
//    setSingleRGB(100, 100, 50);
//    setSingleRGB(255, 100, 50);
//    setSingleRGB(50, 100, 150);
//    setSingleRGB(0, 100, 200);
//    setSingleRGB(75, 150, 50);
//    setSingleRGB(255, 0, 0);
 
    while (1)
    {
//        if (uart1RxCount == 25) {
//            handleColourChange();
//        }
        DOZEN = 1;
//        printf("Yeet");
//        __delay_ms(1000);
    }
}

/**
 End of File
*/