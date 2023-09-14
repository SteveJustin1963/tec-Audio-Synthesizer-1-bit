#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

// Produce s samples of p periods of a sine wave
float* sample(int s, int p) {
    s = s - 1;
    float omega = (float) p * PI * 2 / s;
    float* pcm = (float*) malloc((s + 1) * sizeof(float));

    for (int i = 0; i <= s; i++) {
        pcm[i] = sin(omega * i);
    }

    return pcm;
}

// Encode samples into pulse-density modulation
float* encode(float* pcm, int s) {
    float* pdm = (float*) malloc((s + 1) * sizeof(float));
    float r = 1.0;

    for (int i = 0; i <= s; i++) {
        r = pcm[i] - r;
        if (r > 0) {
            pdm[i] = 1;
            r = 1 - r;
        } else {
            pdm[i] = 0;
            r = -1 - r;
        }
    }

    return pdm;
}

int main() {
    // Test the functions
    int s = 100, p = 2;
    float* pcm = sample(s, p);
    float* pdm = encode(pcm, s);

    // Do something with pcm and pdm arrays

    // Free the allocated memory
    free(pcm);
    free(pdm);

    return 0;
}
