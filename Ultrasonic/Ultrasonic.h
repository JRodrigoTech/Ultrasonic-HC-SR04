// Ultrasonic - Library for HR-SC04 Ultrasonic Ranging Module.
// Rev.4 (06/2012)
// J.Rodrigo ( http://www.jra.so )
// more info at http://www.ardublog.com
// GitHub: https://github.com/elrodri/Ultrasonic-HC-SR04

#ifndef Ultrasonic_h
#define Ultrasonic_h

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#define CM 1
#define INC 0

class Ultrasonic
{
  public:
    Ultrasonic(int TP, int EP);
	Ultrasonic(int TP, int EP, long TO);
    long Timing();
    long Ranging(int sys);

  private:
    int Trig_pin;
    int Echo_pin;
	long Time_out;
    long duration,distacne_cm,distance_inc;
};

#endif