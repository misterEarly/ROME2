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

  DigitalOut enableMotorDriver(PG_0); // ein/ausschalten der motorentreiber
  DigitalIn motorDriverFault(PD_1);   // input für fehler der leistungstreiber
  DigitalIn motorDriverWarning(
      PD_0);             // input für temperaturwarnung der leistungstreiber
  PwmOut pwmLeft(PF_9);  // duty cycle für linker motor
  PwmOut pwmRight(PF_8); // duty cycle für rechter motor

  // lab 2 aufgabe 3
  // EncoderCounter counterLeft(PD_12, PD_13); // encoder counter für links
  // EncoderCounter counterRight(PB_4, PC_7); // encoder counter für rechts

    // erzeugen einer controller instanz
  // Controller controller(pwmLeft, pwmRight, counterLeft, counterRight);

  enable = 1; // schaltet die Sensoren ein

  // Setzt die Periode auf 50 μs
  pwmLeft.period(0.00005);
  pwmRight.period(0.00005);

  // Setzt die Duty-Cycle auf 50%
  pwmLeft = 0.5;
  pwmRight = 0.5;

  // controller.setDesiredSpeedLeft(50.0); // Drehzahl in [rpm]
  // controller.setDesiredSpeedRight(50.0);

  enableMotorDriver = 1; // Schaltet den Leistungstreiber ein
  while (true) {

    // wenn sensor 0 weniger als 20cm ist, schalte led 0 ein
    led0 = (irSensor0.read() < 0.2);
    led1 = (irSensor1.read() < 0.2);
    led2 = (irSensor2.read() < 0.2);
    led3 = (irSensor3.read() < 0.2);
    led4 = (irSensor4.read() < 0.2);
    led5 = (irSensor5.read() < 0.2);
  }
}
