// Ultrasonic - Library for HR-SC04 Ultrasonic Ranging Module.
// Rev.4 (06/2012)
// J.Rodrigo ( www.jra.so )
// more info at www.ardublog.com

#include <Ultrasonic.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // LCD arduino library

Ultrasonic ultrasonic(9,8); // (Trig PIN,Echo PIN)

void setup() {
lcd.begin(16, 2);
}

void loop()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(ultrasonic.Ranging(CM)); // CM or INC
  lcd.print("cm");
  delay(100);
}