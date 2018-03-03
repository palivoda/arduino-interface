#include <Arduino.h>
#define ACS712_DEBUG
#include "acs712.h"
#define DIVVIN_DEBUG
#include "divVin.h"
#define HYSRF05_DEBUG
#include "hysrf05.h"
#define KTY81_DEBUG
#include "kty81.h"
#define LDR04_DEBUG
#include "ldr04.h"
#define NTCMF52AT_DEBUG
#include "NtcMf52at.h"

void setup() {
  ACS712(1);
  divVin(2200, 1100, 2);
  HYSRF05(3, 4);
  KTY81_210(5);
  LDR04(6);
  NTCMF52AT(7);
}

void loop() {
}
