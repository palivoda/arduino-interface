#ifndef KTY81_h
#define KTY81_h

/*
Converts termistor KTY81-110 analog readings to celsius.
DataSheet - http://www.tme.eu/ru/Document/63412cca845bf05e8bcce2eecca1aa6d/KTY81-210.pdf
Code sample - http://electronics.stackexchange.com/questions/188813/strange-result-adcarduino-micro-thermistor-kty-10-6
Hardware - https://www.lemona.lv/?page=item&i_id=30742

  resistor - tuning value, for 2k2k resistor should be 2200 but could vary. In charge mode 2600, in usb connection 1950, use resistors +/- 1% deviation
*/
float KTY81_210(byte pin, const int resistor = 2200) {

  float ukty = 5.1 * analogRead(pin) / 1023.0 ;
  float a = 0.01874;
  float b = 7.884;
  float c = 1000 - resistor * ukty / (5 - ukty);
  float delta = b * b - 4 * a * c;
  float delta1 = sqrt (delta);
  float x2 =(-b + delta1)/(2 * a);
  float temp1 = x2 + 25;
  return temp1;
}

#endif
