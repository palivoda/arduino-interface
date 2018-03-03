#ifndef LDR04_h
#define LDR04_h

/*
Converts photo resistor LDR04 analog readings to percent.
DataSheet - http://www.velleman.eu/products/view/?country=be&lang=en&id=167303

   Res1 = 2200 if resistor 1 is 2k2

*/

float LDR04(byte pin, const int Res1 = 2200) {

  short sensorValue = analogRead(pin);
  float Vout1 = sensorValue * (5.0/1023.0);      // calculate Voltage 1 (one unit = 5v / 1024)
  float Res2 = ((5.0  * Res1) / Vout1) - Res1;   // caclulate  Resistor 2
  float retVal = (Res2 / (Res1 + Res2)) * 100;

  #ifdef LDR04_DEBUG
    Serial.println(String("_LDR04:") + retVal);
  #endif

  return retVal;
}

#endif
