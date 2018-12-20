#include "Pot.hpp"

void adc_setup()
{
    ADMUX |= (1 << MUX1);
    ADMUX |= (1 << ADLAR);

    ADCSRA |= (1 << ADPS1) | (1 << ADPS0) | (1 << ADEN);
}

uint16_t adc_read()
{
      // Start the conversion
    ADCSRA |= (1 << ADSC);

    // Wait for it to finish - blocking
    while (ADCSRA & (1 << ADSC));

    return ADCH;
}