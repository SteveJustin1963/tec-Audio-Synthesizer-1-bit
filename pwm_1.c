// pulse width modulation control works by driving a digital output with a series of “ON-OFF” 
// pulses and then varying the duty cycle, the fraction of time that the output voltage is “ON” 
// compared to when it is “OFF”, of the pulses while keeping the frequency constant.
// write c code to do the above 

 
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
