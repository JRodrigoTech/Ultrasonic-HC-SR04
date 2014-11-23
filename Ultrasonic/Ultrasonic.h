// Ultrasonic - Library for HR-SC04 Ultrasonic Ranging Module.
// GitHub: https://github.com/JRodrigoTech/Ultrasonic-HC-SR04
// #### LICENSE ####
// This code is licensed under Creative Commons Share alike 
// and Attribution by J.Rodrigo ( http://www.jrodrigo.net ).
// Modified by Javier Herrera Serpa (Daklon)

#ifndef Ultrasonic_h
#define Ultrasonic_h

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#define CM 1
#define MM 2
#define INC 3

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
    long duration,distance_cm,distance_inc,distance_mm;
};

#endif