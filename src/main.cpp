#include <Arduino.h>
#include "Pot.hpp"

#define PIN_ADC 2
#define PIN_OUT PINB0

uint8_t val = 0;


void setup() {
  adc_setup();
}

void loop() {
  val = adc_read();
  analogWrite(PIN_OUT, val);
}