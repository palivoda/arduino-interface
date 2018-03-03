#ifndef ACS712_h
#define ACS712_h

/*
  Returns  current consumption reading from ACS712 sensor.
  Motor max I (amps) = U (volts) / R (ohms), where U=12V and R is resistance of motor coil.
  Feeder - 10A max
  Fan 4mA - max
 */

 enum ACS712_A {
   ACS712_30A = 66,
   ACS712_20A = 100,
   ACS712_10A = 185
 };

float ACS712(byte pin, const ACS712_A mVperAmp = ACS712_30A) {
  const short ACSoffset = 2485; //milivolts

  short rawVal = analogRead(pin);
  float mVolts = ((rawVal+1) / 1024.0) * 5000;
  float amps = ((mVolts - ACSoffset) / mVperAmp);

  #ifdef ACS712_DEBUG
    Serial.println(String("ACS712 ") + pin + "=" + rawVal + " => " + mVolts + "mV, " + amps  + "A");
  #endif

  return amps;
}

#endif
