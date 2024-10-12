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


;;;;;;;;;;;;;;;;;;;;;;
 ; Z80 Assembly code to output 8-bit sine wave values to port 0x12

    ORG 0x0000           ; Start of the program

    LD HL, SINE_TABLE    ; HL points to the sine wave table
    LD C, 0x12           ; C holds the DAC port address (0x12)
    LD B, 100            ; B holds the number of samples (100)

OUTPUT_LOOP:
    LD A, (HL)           ; Load the next 8-bit sine value into A
    OUT (C), A           ; Send the value to the DAC at port 0x12
    INC HL               ; Move to the next value in the table
    DJNZ OUTPUT_LOOP     ; Decrement B and loop if B != 0

    HALT                 ; Stop the program

; Pre-calculated 8-bit sine wave table, scaled from [-1, 1] to [0, 255]
SINE_TABLE:
    DB 128, 136, 144, 152, 159, 167, 174, 181, 188, 194
    DB 200, 206, 211, 216, 221, 225, 229, 233, 236, 239
    DB 241, 243, 244, 245, 246, 246, 246, 245, 244, 243
    DB 241, 239, 236, 233, 229, 225, 221, 216, 211, 206
    DB 200, 194, 188, 181, 174, 167, 159, 152, 144, 136
    DB 128, 119, 111, 103,  96,  88,  81,  74,  67,  61
    DB  55,  49,  44,  39,  34,  30,  26,  22,  19,  16
    DB  14,  12,  11,  10,  10,  10,  10,  11,  12,  14
    DB  16,  19,  22,  26,  30,  34,  39,  44,  49,  55
    DB  61,  67,  74,  81,  88,  96, 103, 111, 119, 128

    END                  ; End of program
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
