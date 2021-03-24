/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18LF45K42
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 procedures
#define RA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define RA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define RA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define RA0_GetValue()              PORTAbits.RA0
#define RA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define RA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define RA0_SetPullup()             do { WPUAbits.WPUA0 = 1; } while(0)
#define RA0_ResetPullup()           do { WPUAbits.WPUA0 = 0; } while(0)
#define RA0_SetAnalogMode()         do { ANSELAbits.ANSELA0 = 1; } while(0)
#define RA0_SetDigitalMode()        do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set BUTTON_UP aliases
#define BUTTON_UP_TRIS                 TRISAbits.TRISA6
#define BUTTON_UP_LAT                  LATAbits.LATA6
#define BUTTON_UP_PORT                 PORTAbits.RA6
#define BUTTON_UP_WPU                  WPUAbits.WPUA6
#define BUTTON_UP_OD                   ODCONAbits.ODCA6
#define BUTTON_UP_ANS                  ANSELAbits.ANSELA6
#define BUTTON_UP_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define BUTTON_UP_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define BUTTON_UP_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define BUTTON_UP_GetValue()           PORTAbits.RA6
#define BUTTON_UP_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define BUTTON_UP_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define BUTTON_UP_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define BUTTON_UP_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define BUTTON_UP_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define BUTTON_UP_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define BUTTON_UP_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define BUTTON_UP_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSELB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set BUTTON_B aliases
#define BUTTON_B_TRIS                 TRISBbits.TRISB2
#define BUTTON_B_LAT                  LATBbits.LATB2
#define BUTTON_B_PORT                 PORTBbits.RB2
#define BUTTON_B_WPU                  WPUBbits.WPUB2
#define BUTTON_B_OD                   ODCONBbits.ODCB2
#define BUTTON_B_ANS                  ANSELBbits.ANSELB2
#define BUTTON_B_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define BUTTON_B_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define BUTTON_B_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define BUTTON_B_GetValue()           PORTBbits.RB2
#define BUTTON_B_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define BUTTON_B_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define BUTTON_B_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define BUTTON_B_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define BUTTON_B_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define BUTTON_B_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define BUTTON_B_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define BUTTON_B_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set BUTTON_A aliases
#define BUTTON_A_TRIS                 TRISBbits.TRISB3
#define BUTTON_A_LAT                  LATBbits.LATB3
#define BUTTON_A_PORT                 PORTBbits.RB3
#define BUTTON_A_WPU                  WPUBbits.WPUB3
#define BUTTON_A_OD                   ODCONBbits.ODCB3
#define BUTTON_A_ANS                  ANSELBbits.ANSELB3
#define BUTTON_A_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define BUTTON_A_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define BUTTON_A_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define BUTTON_A_GetValue()           PORTBbits.RB3
#define BUTTON_A_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define BUTTON_A_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define BUTTON_A_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define BUTTON_A_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define BUTTON_A_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define BUTTON_A_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define BUTTON_A_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define BUTTON_A_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set BUTTON_START aliases
#define BUTTON_START_TRIS                 TRISBbits.TRISB4
#define BUTTON_START_LAT                  LATBbits.LATB4
#define BUTTON_START_PORT                 PORTBbits.RB4
#define BUTTON_START_WPU                  WPUBbits.WPUB4
#define BUTTON_START_OD                   ODCONBbits.ODCB4
#define BUTTON_START_ANS                  ANSELBbits.ANSELB4
#define BUTTON_START_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define BUTTON_START_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define BUTTON_START_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define BUTTON_START_GetValue()           PORTBbits.RB4
#define BUTTON_START_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define BUTTON_START_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define BUTTON_START_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define BUTTON_START_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define BUTTON_START_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define BUTTON_START_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define BUTTON_START_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define BUTTON_START_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set BUTTON_SELECT aliases
#define BUTTON_SELECT_TRIS                 TRISBbits.TRISB5
#define BUTTON_SELECT_LAT                  LATBbits.LATB5
#define BUTTON_SELECT_PORT                 PORTBbits.RB5
#define BUTTON_SELECT_WPU                  WPUBbits.WPUB5
#define BUTTON_SELECT_OD                   ODCONBbits.ODCB5
#define BUTTON_SELECT_ANS                  ANSELBbits.ANSELB5
#define BUTTON_SELECT_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define BUTTON_SELECT_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define BUTTON_SELECT_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define BUTTON_SELECT_GetValue()           PORTBbits.RB5
#define BUTTON_SELECT_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define BUTTON_SELECT_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define BUTTON_SELECT_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define BUTTON_SELECT_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define BUTTON_SELECT_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define BUTTON_SELECT_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define BUTTON_SELECT_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define BUTTON_SELECT_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set BUTTON_RIGHT aliases
#define BUTTON_RIGHT_TRIS                 TRISCbits.TRISC0
#define BUTTON_RIGHT_LAT                  LATCbits.LATC0
#define BUTTON_RIGHT_PORT                 PORTCbits.RC0
#define BUTTON_RIGHT_WPU                  WPUCbits.WPUC0
#define BUTTON_RIGHT_OD                   ODCONCbits.ODCC0
#define BUTTON_RIGHT_ANS                  ANSELCbits.ANSELC0
#define BUTTON_RIGHT_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define BUTTON_RIGHT_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define BUTTON_RIGHT_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define BUTTON_RIGHT_GetValue()           PORTCbits.RC0
#define BUTTON_RIGHT_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define BUTTON_RIGHT_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define BUTTON_RIGHT_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define BUTTON_RIGHT_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define BUTTON_RIGHT_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define BUTTON_RIGHT_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define BUTTON_RIGHT_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define BUTTON_RIGHT_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set BUTTON_LEFT aliases
#define BUTTON_LEFT_TRIS                 TRISCbits.TRISC1
#define BUTTON_LEFT_LAT                  LATCbits.LATC1
#define BUTTON_LEFT_PORT                 PORTCbits.RC1
#define BUTTON_LEFT_WPU                  WPUCbits.WPUC1
#define BUTTON_LEFT_OD                   ODCONCbits.ODCC1
#define BUTTON_LEFT_ANS                  ANSELCbits.ANSELC1
#define BUTTON_LEFT_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define BUTTON_LEFT_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define BUTTON_LEFT_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define BUTTON_LEFT_GetValue()           PORTCbits.RC1
#define BUTTON_LEFT_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define BUTTON_LEFT_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define BUTTON_LEFT_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define BUTTON_LEFT_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define BUTTON_LEFT_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define BUTTON_LEFT_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define BUTTON_LEFT_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define BUTTON_LEFT_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set BUTTON_DOWN aliases
#define BUTTON_DOWN_TRIS                 TRISCbits.TRISC2
#define BUTTON_DOWN_LAT                  LATCbits.LATC2
#define BUTTON_DOWN_PORT                 PORTCbits.RC2
#define BUTTON_DOWN_WPU                  WPUCbits.WPUC2
#define BUTTON_DOWN_OD                   ODCONCbits.ODCC2
#define BUTTON_DOWN_ANS                  ANSELCbits.ANSELC2
#define BUTTON_DOWN_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define BUTTON_DOWN_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define BUTTON_DOWN_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define BUTTON_DOWN_GetValue()           PORTCbits.RC2
#define BUTTON_DOWN_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define BUTTON_DOWN_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define BUTTON_DOWN_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define BUTTON_DOWN_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define BUTTON_DOWN_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define BUTTON_DOWN_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define BUTTON_DOWN_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define BUTTON_DOWN_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSELC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSELC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set IO_RC5 aliases
#define IO_RC5_TRIS                 TRISCbits.TRISC5
#define IO_RC5_LAT                  LATCbits.LATC5
#define IO_RC5_PORT                 PORTCbits.RC5
#define IO_RC5_WPU                  WPUCbits.WPUC5
#define IO_RC5_OD                   ODCONCbits.ODCC5
#define IO_RC5_ANS                  ANSELCbits.ANSELC5
#define IO_RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define IO_RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define IO_RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define IO_RC5_GetValue()           PORTCbits.RC5
#define IO_RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define IO_RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define IO_RC5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define IO_RC5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define IO_RC5_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define IO_RC5_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define IO_RC5_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define IO_RC5_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSELC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSELC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSELC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF6 pin functionality
 * @Example
    IOCAF6_ISR();
 */
void IOCAF6_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF6 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF6 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF6_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF6_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF6 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF6_SetInterruptHandler() method.
    This handler is called every time the IOCAF6 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF6_SetInterruptHandler(IOCAF6_InterruptHandler);

*/
extern void (*IOCAF6_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF6 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF6_SetInterruptHandler() method.
    This handler is called every time the IOCAF6 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF6_SetInterruptHandler(IOCAF6_DefaultInterruptHandler);

*/
void IOCAF6_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF2 pin functionality
 * @Example
    IOCBF2_ISR();
 */
void IOCBF2_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF2 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF2 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF2_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF2 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF2_SetInterruptHandler() method.
    This handler is called every time the IOCBF2 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF2_SetInterruptHandler(IOCBF2_InterruptHandler);

*/
extern void (*IOCBF2_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF2 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF2_SetInterruptHandler() method.
    This handler is called every time the IOCBF2 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF2_SetInterruptHandler(IOCBF2_DefaultInterruptHandler);

*/
void IOCBF2_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF3 pin functionality
 * @Example
    IOCBF3_ISR();
 */
void IOCBF3_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF3 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF3 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF3_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF3_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF3 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF3_SetInterruptHandler() method.
    This handler is called every time the IOCBF3 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF3_SetInterruptHandler(IOCBF3_InterruptHandler);

*/
extern void (*IOCBF3_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF3 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF3_SetInterruptHandler() method.
    This handler is called every time the IOCBF3 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF3_SetInterruptHandler(IOCBF3_DefaultInterruptHandler);

*/
void IOCBF3_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF4 pin functionality
 * @Example
    IOCBF4_ISR();
 */
void IOCBF4_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF4 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF4 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF4_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF4_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF4 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF4_SetInterruptHandler() method.
    This handler is called every time the IOCBF4 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF4_SetInterruptHandler(IOCBF4_InterruptHandler);

*/
extern void (*IOCBF4_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF4 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF4_SetInterruptHandler() method.
    This handler is called every time the IOCBF4 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF4_SetInterruptHandler(IOCBF4_DefaultInterruptHandler);

*/
void IOCBF4_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF5 pin functionality
 * @Example
    IOCBF5_ISR();
 */
void IOCBF5_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF5 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF5 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF5_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF5_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF5 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF5_SetInterruptHandler() method.
    This handler is called every time the IOCBF5 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF5_SetInterruptHandler(IOCBF5_InterruptHandler);

*/
extern void (*IOCBF5_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF5 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF5_SetInterruptHandler() method.
    This handler is called every time the IOCBF5 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF5_SetInterruptHandler(IOCBF5_DefaultInterruptHandler);

*/
void IOCBF5_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF0 pin functionality
 * @Example
    IOCCF0_ISR();
 */
void IOCCF0_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF0 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF0 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF0_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF0_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF0 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF0_SetInterruptHandler() method.
    This handler is called every time the IOCCF0 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF0_SetInterruptHandler(IOCCF0_InterruptHandler);

*/
extern void (*IOCCF0_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF0 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF0_SetInterruptHandler() method.
    This handler is called every time the IOCCF0 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF0_SetInterruptHandler(IOCCF0_DefaultInterruptHandler);

*/
void IOCCF0_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF1 pin functionality
 * @Example
    IOCCF1_ISR();
 */
void IOCCF1_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF1 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF1 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF1 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF1_SetInterruptHandler() method.
    This handler is called every time the IOCCF1 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(IOCCF1_InterruptHandler);

*/
extern void (*IOCCF1_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF1 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF1_SetInterruptHandler() method.
    This handler is called every time the IOCCF1 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(IOCCF1_DefaultInterruptHandler);

*/
void IOCCF1_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF2 pin functionality
 * @Example
    IOCCF2_ISR();
 */
void IOCCF2_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF2 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF2 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF2_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF2 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF2_SetInterruptHandler() method.
    This handler is called every time the IOCCF2 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF2_SetInterruptHandler(IOCCF2_InterruptHandler);

*/
extern void (*IOCCF2_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF2 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF2_SetInterruptHandler() method.
    This handler is called every time the IOCCF2 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF2_SetInterruptHandler(IOCCF2_DefaultInterruptHandler);

*/
void IOCCF2_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF5 pin functionality
 * @Example
    IOCCF5_ISR();
 */
void IOCCF5_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF5 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF5 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF5_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF5_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF5 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF5_SetInterruptHandler() method.
    This handler is called every time the IOCCF5 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF5_SetInterruptHandler(IOCCF5_InterruptHandler);

*/
extern void (*IOCCF5_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF5 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF5_SetInterruptHandler() method.
    This handler is called every time the IOCCF5 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF5_SetInterruptHandler(IOCCF5_DefaultInterruptHandler);

*/
void IOCCF5_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/