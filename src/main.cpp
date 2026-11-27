#include <Arduino.h>
#include "M5Unified.h"
#include "M5UnitENV.h"

SHT4X sht4;
BMP280 bmp;

void setup() {
  M5.begin();
  if (!sht4.begin(&Wire, SHT40_I2C_ADDR_44,32,33, 400000U)) {
    M5.Display.printf("Couldn't find SHT4x");
    while (1) delay(1);
  }

  sht4.setPrecision(SHT4X_HIGH_PRECISION);
  sht4.setHeater(SHT4X_NO_HEATER);
}

void loop() {
  if (sht4.update()) {
    M5.Display.clear();
    M5.Display.setCursor(0,0);
    M5.Display.printf("Temperature: %f [degC]\n", sht4.cTemp);
    M5.Display.printf("Humidity: %f [%%]\n", sht4.humidity);
  }
  delay(1000);
}