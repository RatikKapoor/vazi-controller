/*
 * File:   rgbmanager.c
 * Author: ratik
 *
 * Created on March 23, 2021, 2:48 PM
 */


#include <xc.h>

#include "rgbmanager.h"

void clearAllRGB();

void setSingleRGB(uint8_t r, uint8_t g, uint8_t b) {
    SPI1TXB = g;
    while (!SPI1STATUSbits.TXBE);
    SPI1TXB = r;
    while (!SPI1STATUSbits.TXBE);
    SPI1TXB = b;
    while (!SPI1STATUSbits.TXBE);
}

void handleColourChange() {
    char read[24];
    char temp[2];
    int rgb[12];
    int location=0;
    for (int i=0; i<24; i++) {
        read[i] = UART1_Read(); // Copy data into `read`
    }
    for (int j=0; j<12; j++) {   // Do three times for R, G, and B
        for (int k=0; k<2 ;k++) {    // Copy R/G/B into temp
            temp[k] = read[location++];
        }
        rgb[j] = atoi(temp);
    }
    for (int i=0; i<2; i++) {
        setSingleRGB(rgb[0], rgb[1], rgb[2]);
        setSingleRGB(rgb[3], rgb[4], rgb[5]);
        setSingleRGB(rgb[6], rgb[6], rgb[8]);
        setSingleRGB(rgb[9], rgb[10], rgb[11]);
    }
            
    location = 0;
    __delay_ms(1);
}

void clearAllRGB() {
    for (int i=0; i<256; i++) {
        setSingleRGB(0, 0, 0);
    }
    __delay_ms(1);
}

void handleUARTInput() {
    UART1_Receive_ISR();
    if (uart1RxCount == 24) {
        handleColourChange();
    }
}
