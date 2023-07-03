#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define CARRIER_FREQUENCY 1000
#define MODULATION_FACTOR 500
#define AMPLITUDE 0.5

void generatePFMSignal(float duration) {
    uint32_t numSamples = duration * SAMPLE_RATE;
    float timeStep = 1.0 / SAMPLE_RATE;
    float phase = 0.0;

    for (uint32_t i = 0; i < numSamples; i++) {
        float analogSignal = AMPLITUDE * sinf(2 * M_PI * CARRIER_FREQUENCY * i * timeStep);
        float pulseFrequency = CARRIER_FREQUENCY + (analogSignal * MODULATION_FACTOR);
        float pulsePeriod = 1.0 / pulseFrequency;
        float pulseWidth = 0.2 * pulsePeriod; // 20% duty cycle

        for (float t = 0.0; t < pulsePeriod; t += timeStep) {
            float sample = (t < pulseWidth) ? 1.0 : 0.0;
            int16_t outputSample = (int16_t)(sample * 32767);
            fwrite(&outputSample, sizeof(outputSample), 1, stdout);
        }
    }
}

int main() {
    float duration = 5.0; // Duration of the PFM signal in seconds
    generatePFMSignal(duration);
    return 0;
}
