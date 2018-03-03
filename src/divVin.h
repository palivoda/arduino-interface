#ifndef divVin_h
#define divVin_h

/*
Voltage divider volts recalculation
Reffer: http://www.ohmslawcalculator.com/voltage-divider-calculator
Use over voltage protetion: http://www.learningaboutelectronics.com/Articles/Overvoltage-protection-circuit.php
*/
float divVin(float R1, float R2, byte pin) {

  float vIn = 5.0 * analogRead(pin) / 1023.0 ;

  float vOut =  vIn/(R2/(R1+R2));

  #ifdef DIVVIN_DEBUG
    Serial.print("divVin: vIn=");
    Serial.print(vIn);
    Serial.print("vOut=");
    Serial.println(vOut);
  #endif

  return vOut;
}

#endif
