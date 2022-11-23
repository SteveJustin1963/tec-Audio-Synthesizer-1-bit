 // pseudo  


function PPM(freq1, freq2, duty1, duty2) {
  while (true) {
    digitalWrite(freq1, HIGH);
    delay(duty1);
    digitalWrite(freq1, LOW);
    digitalWrite(freq2, HIGH);
    delay(duty2);
    digitalWrite(freq2, LOW);
  }
}


//  c code program 

 

#include <stdio.h>
#include <wiringPi.h>

#define freq1 1
#define freq2 2

int main(void) {
  int duty1, duty2;

  printf("Enter duty cycle for freq1 (0-100): ");
  scanf("%d", &duty1);

  printf("Enter duty cycle for freq2 (0-100): ");
  scanf("%d", &duty2);

  if (wiringPiSetup() == -1)
    return 1;

  pinMode(freq1, OUTPUT);
  pinMode(freq2, OUTPUT);

  while(1) {
    digitalWrite(freq1, HIGH);
    delay(duty1);
    digitalWrite(freq1, LOW);
    digitalWrite(freq2, HIGH);
    delay(duty2);
    digitalWrite(freq2, LOW);
  }

  return 0;
}

// forth 83 code



: PPM  ( freq1 freq2 duty1 duty2 -- )
     BEGIN
          1 HIGH FREQ1 WRITE
          2 HIGH FREQ2 WRITE
          1 LOW  FREQ1 WRITE
          2 LOW  FREQ2 WRITE
     AGAIN ;
