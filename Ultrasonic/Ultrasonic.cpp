// Ultrasonic - Library for HR-SC04 Ultrasonic Ranging Module.
// GitHub: https://github.com/JRodrigoTech/Ultrasonic-HC-SR04
// #### LICENSE ####
// This code is licensed under Creative Commons Share alike
// and Attribution by J.Rodrigo ( http://www.jrodrigo.net ).

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(int TP, int EP)
  :trigger_pin(TP), echo_pin(EP), time_out(3000) { // 3000 µs = 50cm // 30000 µs = 5 m

   pinMode(TP, OUTPUT);
   pinMode(EP, INPUT);
}

Ultrasonic::Ultrasonic(int TP, int EP, long TO)
  :trigger_pin(TP), echo_pin(EP), time_out(TO) {

   pinMode(TP, OUTPUT);
   pinMode(EP, INPUT);
}

long Ultrasonic::Timing() {
  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigger_pin, LOW);

  duration = pulseIn(echo_pin, HIGH,time_out);

  return duration == 0 ? time_out : duration;
}

long Ultrasonic::Ranging(bool sys) {
  Timing();
  return sys ? duration /29 / 2 : duration / 74 / 2;
}
