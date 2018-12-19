#include <Arduino.h>

#define PIN_ADC 2
#define PIN_OUT PINB0

uint8_t val = 0;

void setup() {
}

void loop() {
  val = map(analogRead(PIN_ADC), 0, 1023, 0,  255);
  analogWrite(PIN_OUT, val);
}