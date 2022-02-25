/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "IRSensor.h" // include class to easily read ir sensors
#include "mbed.h"

int main() {

  printf("start program");

  DigitalOut led0(PD_4);
  DigitalOut led1(PD_3);
  DigitalOut led2(PD_6);
  DigitalOut led3(PD_2);
  DigitalOut led4(PD_7);
  DigitalOut led5(PD_5);

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

    led0 = (irSensor0.read() <
            0.2); // wenn sensor 0 weniger als 20cm ist, schalte led 0 ein
    led1 = (irSensor1.read() < 0.2);
    led2 = (irSensor2.read() < 0.2);
    led3 = (irSensor3.read() < 0.2);
    led4 = (irSensor4.read() < 0.2);
    led5 = (irSensor5.read() < 0.2);
  }
}
