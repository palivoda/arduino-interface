#ifndef HYSRF05_h
#define HYSRF05_h

/*
Returns CMs readings from ultrasonic sensor.
Reffer: http://arduino-project.net/podklyuchenie-ul-trazvukovogo-dal-nomera-hc-sr04-k-arduino/

  byte pinTrig - trigger PIN
  byte pinEcho - echo reading PIN
  targetDistance -  depends on max distance - 3000 µs = 50cm // 30000 µs = 5 m

*/
byte HYSRF05(byte pinTrig, byte pinEcho, const short targetDistance = 15000) {

  digitalWrite(pinTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);

  short duration = pulseIn(pinEcho, HIGH, targetDistance);

  #ifdef HYSRF05_DEBUG
    Serial.print("HYSRF05 (");
    Serial.print(pinTrig);
    Serial.print("->");
    Serial.print(pinEcho);
    Serial.print(") ");
    Serial.print(duration);
    Serial.println("cm");
  #endif

  if (duration == 0) duration = targetDistance; //set to max if no reading

  return duration / 29 / 2; //return centemeters
}

#endif
