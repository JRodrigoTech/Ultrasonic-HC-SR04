// Ultrasonic - Library for HR-SC04 Ultrasonic Ranging Module.
// GitHub: https://github.com/JRodrigoTech/Ultrasonic-HC-SR04
// #### LICENSE ####
// This code is licensed under Creative Commons Share alike
// and Attribution by J.Rodrigo ( http://www.jrodrigo.net ).
// Modified by Sebastian Tellez (@gorrotowi)

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(int TP, int EP)
{
   pinMode(TP,OUTPUT);
   pinMode(EP,INPUT);
   Trig_pin=TP;
   Echo_pin=EP;
   Time_out=3000;  // 30ms = 5 m // 3ms = 50cm
}

Ultrasonic::Ultrasonic(int TP, int EP, long TO)
{
   pinMode(TP,OUTPUT);
   pinMode(EP,INPUT);
   Trig_pin=TP;
   Echo_pin=EP;
   Time_out=TO;
}

long Ultrasonic::Timing()
{
  digitalWrite(Trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin, LOW);
  duration = pulseIn(Echo_pin,HIGH,Time_out);
  if ( duration == 0 ) {
	duration = Time_out; }
  return duration;
}

long Ultrasonic::Ranging(int sys)
{
  Timing();
  if (sys) {
    switch(sys)
      case 0:
        distance = duration /29 / 2 ;
      break;
      case 1:
        distance = duration /2.915 / 2 ;
      break;
      case 2:
        distance = duration / 74 / 2;
      break;
    }
    return distance;
  }
}
