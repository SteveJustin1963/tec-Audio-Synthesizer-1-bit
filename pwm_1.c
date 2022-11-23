// pulse width modulation control works by driving a digital output with a series of “ON-OFF” 
// pulses and then varying the duty cycle, the fraction of time that the output voltage is “ON” 
// compared to when it is “OFF”, of the pulses while keeping the frequency constant.
//  c code   

 
int main()
{
    // PWM output on PD6/OC0A
    DDRD |= 1 << PD6;
 
    // set up timer with prescaler = 256
    TCCR0B |= 1 << CS02;
 
    while (1)
    {
        // loop through different duty cycles
        for (int i = 0; i <= 255; i++)
        {
            // set duty cycle
            OCR0A = i;
 
            // delay
            _delay_ms(10);
        }
 
        // loop through different duty cycles in reverse order
        for (int i = 255; i >= 0; i--)
        {
            // set duty cycle
            OCR0A = i;
 
            // delay
            _delay_ms(10);
        }
    }
}


=================
 
// c code to do the above for a z80 cpu

   // set output pin to digital output mode
   DDRB |= (1 << DDB5);

// loop forever
   while (1)
   {
       // turn on output pin
       PORTB |= (1 << PB5);

       // wait for 1/2 second
       _delay_ms(500);

       // turn off output pin
       PORTB &= ~(1 << PB5);

       // wait for 1/2 second
       _delay_ms(500);
   }
