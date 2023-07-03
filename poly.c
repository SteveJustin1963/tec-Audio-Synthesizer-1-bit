#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define SAMPLE_RATE 44100
#define AMPLITUDE 32767
#define FREQUENCY_1 440
#define FREQUENCY_2 660
#define INTERLEAVE_RATIO 0.5

void generatePolyphonicSound(float duration) {
    uint32_t numSamples = duration * SAMPLE_RATE;
    float phase_1 = 0.0;
    float phase_2 = 0.0;
    float step_1 = (2 * FREQUENCY_1 * M_PI) / SAMPLE_RATE;
    float step_2 = (2 * FREQUENCY_2 * M_PI) / SAMPLE_RATE;

    for (uint32_t i = 0; i < numSamples; i++) {
        float sample = 0.0;

        if (phase_1 < INTERLEAVE_RATIO * M_PI) {
            sample += sinf(phase_1) * AMPLITUDE;
        }

        if (phase_2 < (1 - INTERLEAVE_RATIO) * M_PI) {
            sample += sinf(phase_2) * AMPLITUDE;
        }

        phase_1 += step_1;
        phase_2 += step_2;

        if (phase_1 >= 2 * M_PI) {
            phase_1 -= 2 * M_PI;
        }

        if (phase_2 >= 2 * M_PI) {
            phase_2 -= 2 * M_PI;
        }

        int16_t outputSample = (int16_t)sample;
        fwrite(&outputSample, sizeof(outputSample), 1, stdout);
    }
}

int main() {
    float duration = 5.0; // Duration of the polyphonic sound in seconds
    generatePolyphonicSound(duration);
    return 0;
}
