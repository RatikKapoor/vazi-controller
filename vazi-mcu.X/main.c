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

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */

//void myLEDArray(uint8_t r, uint8_t g, uint8_t b) {
//    SPI1TXB = g;
//    while (!SPI1STATUSbits.TXBE);
//    SPI1TXB = r;
//    while (!SPI1STATUSbits.TXBE);
//    SPI1TXB = b;
//    while (!SPI1STATUSbits.TXBE);
//}

void setRGB(uint8_t r, uint8_t g, uint8_t b) {
    PWM6_LoadDutyValue(r);
    PWM7_LoadDutyValue(g);
    PWM8_LoadDutyValue(b);
}

void handleColourChange() {
    char read[6];
    char temp[2];
    int rgb[3];
    int location=0;
    for (int i=0; i<6; i++) {
        read[i] = UART1_Read();
    }
    for (int i=0; i<3; i++) {
        for (int j=0; j<2; j++) {
            temp[j] = read[location];
            location++;
        }
        rgb[i] = atoi(temp);
    }
    setRGB(rgb[0]*2, rgb[1]*2, rgb[2]*2);
}

void handleButtonPress() {
    printf("bp\n\r");
    __delay_ms(3);
    
}

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
    
    /** Code for  */
    // Turn off all LEDs
//    for (int i=0; i<256; i++) {
//        myLEDArray(0, 0, 0);
//    }
//    __delay_ms(1);
 
    IOCCF2_SetInterruptHandler(handleButtonPress);
    printf("Ready\n\r");
    while (1)
    {

        if (uart1RxCount == 6) {
            handleColourChange();
        }
        
//        printf("b1");
//        printf(" Count: %u\n",uart1RxCount);
//        while (uart1RxCount != 0) {
//            printf("%c", UART1_Read());
//            if (uart1RxCount == 0) printf("\n");
//        }
        __delay_ms(500);        
    }
}
/**
 End of File
*/