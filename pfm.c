loop for generating the PFM signal to consider both the modulated pulse frequency and the original sample rate.

currentTime keeps track of the current time in the signal generation process and ensures that 
you don't exceed the intended signal duration.

A nested loop is used for generating the pulse at the modulated frequency.

It's worth noting that this code will produce a PFM signal with a varying pulse frequency around a fixed carrier frequency. 
The modulation is done by a sine wave.

The output samples are written to stdout, which is useful for piping into other tools for further analysis 
or playback but might not be the most user-friendly approach. 
You may want to write them to a file or send them to an audio output interface depending on your application.

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

// Constants
#define SAMPLE_RATE 44100 // Sample rate in Hz
#define CARRIER_FREQUENCY 1000 // Carrier frequency in Hz
#define MODULATION_FACTOR 500 // Modulation factor
#define AMPLITUDE 0.5 // Amplitude of the analog signal

// Function to generate a PFM signal
void generatePFMSignal(float duration) {
    uint32_t numSamples = duration * SAMPLE_RATE; // Total number of samples
    float timeStep = 1.0 / SAMPLE_RATE; // Time step in seconds
    float currentTime = 0.0; // Current time in seconds

    // Loop through each sample
    for (uint32_t i = 0; i < numSamples; i++) {
        // Calculate the analog signal value
        float analogSignal = AMPLITUDE * sinf(2 * M_PI * CARRIER_FREQUENCY * i * timeStep);

        // Calculate the modulated pulse frequency
        float pulseFrequency = CARRIER_FREQUENCY + (analogSignal * MODULATION_FACTOR);

        // Calculate the pulse period and pulse width
        float pulsePeriod = 1.0 / pulseFrequency;
        float pulseWidth = 0.2 * pulsePeriod; // 20% duty cycle

        // Generate the pulse
        for (float t = 0.0; t < pulsePeriod; t += timeStep) {
            float sample = (t < pulseWidth) ? 1.0 : 0.0;
            int16_t outputSample = (int16_t)(sample * 32767);

            // Write the sample to stdout
            fwrite(&outputSample, sizeof(outputSample), 1, stdout);

            currentTime += timeStep;

            // Break the inner loop if we have generated the signal for the intended duration
            if (currentTime >= duration) {
                return;
            }
        }
    }
}

// Main function
int main() {
    float duration = 5.0; // Duration of the PFM signal in seconds
    generatePFMSignal(duration); // Generate the PFM signal
    return 0;
}
