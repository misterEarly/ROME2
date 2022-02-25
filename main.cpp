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

  DigitalOut enable(PG_1); // initialisieren vom sensor-wert
  DigitalOut bit0(PF_0);   // multiplexer auswahlbit
  DigitalOut bit1(PF_1);   // multiplexer auswahlbit
  DigitalOut bit2(PF_2);   // multiplexer auswahlbit
  enable = 1;              // schaltet die Sensoren ein

  while (true) {
    bit0 = 1; // Wahl des Sensors mit dem Multiplexer (Sensor vorne)
    bit1 = 1;
    bit2 = 0;
    float d = 0.09f / (distance + 0.001f) - 0.03f;   // Lesen der Distanz in [m]
    printf("distance=%dmm\r\n", (int)(1000.0f * d)); // ausgeben der distanz
  }
}
