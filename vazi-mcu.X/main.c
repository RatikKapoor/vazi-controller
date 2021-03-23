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
 * 25 bytes
 * Byte     0       :   Clear LEDs
 * Bytes    1-6     :   RRGGBB (LED #1)
 * Bytes    7-12    :   RRGGBB (LED #2)
 * Bytes    13-18   :   RRGGBB (LED #3)
 * Bytes    19-24   :   RRGGBB (LED #4)
 * 
 * 
 * Button Press UART Send Schema:
 * "{action (button press (bp))}-{button name (up)}"
 * 
 * Up Button Press          -   "bp-up"
 * Down Button Press        -   "bp-down"
 * Left Button Press        -   "bp-left"
 * Right Button Press       -   "bp-right"
 * Select Button Press      -   "bp-select"
 * Start Button Press       -   "bp-start"
 * A Button Press           -   "bp-a"
 * B Button Press           -   "bp-b"
 * 
 */

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();
    
    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();
    
    /** Code for aRGBs */
    // Turn off all LEDs
    for (int i=0; i<256; i++) {
        setSingleRGB(0, 0, 0);
    }
    __delay_ms(1);
 
    /** Set button interrupt handlers */
    
    IOCCF2_SetInterruptHandler(handleButtonPress);
    
    
    printf("Ready\n\r");
    while (1)
    {
        if (uart1RxCount == 25) {
            handleColourChange();
        }      
    }
}
/**
 End of File
*/