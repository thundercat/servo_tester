#include <avr/io.h>
#include <avr/interrupt.h>
#include "Pot.hpp"

#define PIN_ADC 2

#define PIN_OUT PINB0
#define PIN_OUT_PORT PORTB
#define PIN_OUT_DDR DDRB
#define PIN_OUT_M PIN_OUT_PORT, PIN_OUT

volatile unsigned int tick;
volatile unsigned int pulse;

uint8_t val = 0;

void timer0_setup()
{
    // 100 kHZ
    TCCR0A = (1 << WGM01);
    TCCR0B = (1 << CS00);
    TIMSK0 = (1 << OCIE0A);

    OCR0A = 95;
}
int main()
{
    adc_setup();
    timer0_setup();

    PIN_OUT_DDR |= (1 << 0);
    
    tick = 0;
    pulse = 0;

    sei();

    while (1)
    {
        val = adc_read();
        pulse = val * 8;
    }
    return 0;
}

ISR(TIM0_COMPA_vect)
{
    if (tick >= 2000) 
    {
        tick = 0;
    }

    tick++;
    tick <= pulse ? PIN_OUT_PORT |= (1 << PIN_OUT) : PIN_OUT_PORT &= ~(1 << PIN_OUT);
}