/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

// Blinking rate in milliseconds
#define BLINKING_RATE 500ms

int main() {

  DigitalOut led0(PD_4);
  DigitalOut led1(PD_3);
  DigitalOut led2(PD_6);
  DigitalOut led3(PD_2);
  DigitalOut led4(PD_7);
  DigitalOut led5(PD_5);

  while (true) {
    led5 = 0;
    led0 = 1;
    ThisThread::sleep_for(BLINKING_RATE);
    led0 = 0;
    led1 = 1;
    ThisThread::sleep_for(BLINKING_RATE);
    led1 = 0;
    led2 = 1;
    ThisThread::sleep_for(BLINKING_RATE);
    led2 = 0;
    led3 = 1;
    ThisThread::sleep_for(BLINKING_RATE);
    led3 = 0;
    led4 = 1;
    ThisThread::sleep_for(BLINKING_RATE);
    led4 = 0;
    led5 = 1;
    ThisThread::sleep_for(BLINKING_RATE);
  }
}
