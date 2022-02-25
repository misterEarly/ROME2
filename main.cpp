/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "IRSensor.h" // include class to easily read ir sensors
#include "mbed.h"

int main() {

  printf("start program");

  AnalogIn distance(PA_0); // Kreieren der Ein- und Ausgangsobjekte
  DigitalOut enable(PG_1); // initialisieren vom sensor-wert
  DigitalOut bit0(PF_0);   // multiplexer auswahlbit
  DigitalOut bit1(PF_1);   // multiplexer auswahlbit
  DigitalOut bit2(PF_2);   // multiplexer auswahlbit

  IRSensor irSensor0(distance, bit0, bit1, bit2, 0); // Objekte kreieren
  IRSensor irSensor1(distance, bit0, bit1, bit2, 1);
  IRSensor irSensor2(distance, bit0, bit1, bit2, 2);
  IRSensor irSensor3(distance, bit0, bit1, bit2, 3);
  IRSensor irSensor4(distance, bit0, bit1, bit2, 4);
  IRSensor irSensor5(distance, bit0, bit1, bit2, 5);
  enable = 1; // schaltet die Sensoren ein

  while (true) {

    printf("distance=%dmm\r\n",
           (int)(1000.0f * irSensor0.read())); // ausgeben der distanz
  }
}
