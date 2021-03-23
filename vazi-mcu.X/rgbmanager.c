/*
 * File:   rgbmanager.c
 * Author: ratik
 *
 * Created on March 23, 2021, 2:48 PM
 */


#include <xc.h>

#include "rgbmanager.h"
#include "mcc_generated_files/uart1.h"

void setSingleRGB(uint8_t r, uint8_t g, uint8_t b) {
    SPI1TXB = g;
    while (!SPI1STATUSbits.TXBE);
    SPI1TXB = r;
    while (!SPI1STATUSbits.TXBE);
    SPI1TXB = b;
    while (!SPI1STATUSbits.TXBE);
}

void handleColourChange() {
    char read[7];
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
    setSingleRGB(rgb[0]*2, rgb[1]*2, rgb[2]*2);
}