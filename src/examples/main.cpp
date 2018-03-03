#include <Arduino.h>
#include "acs712.h"
#include "divVin.h"
#include "hysrf05.h"
#include "kty81.h"
#include "ldr04.h"

void setup() {
}

void loop() {

  ACS712(1);
  divVin(2200, 1100, 2);
  HYSRF05(3, 4);
  KTY81_210(5);
  LDR04(6);

}
