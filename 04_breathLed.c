#include <wiringPi.h>
#include <stdio.h>

#define BREATH_SIZE 100
enum WiringPiToBCM {B17,B18,B27,B22,B23,B24,B25,B4};

void breathOn(int pin) {
  printf("Breath on\n");
  int i;
  for (i = 0; i < BREATH_SIZE; i++) {
    softPwmWrite(pin, i);
    delay(20);
  }
}

void breathOff(int pin) {
  printf("Breath off\n");
  int i;
  for (i = BREATH_SIZE; i > 0; i--) {
    softPwmWrite(pin, i);
    delay(20);
  }
}

int main(void) {
  wiringPiSetup();
  softPwmCreate(B17, 0, BREATH_SIZE);
  printf("---Lesson 4.---\n");
  while(1) {
    breathOn(B17);
    breathOff(B17);
  }

  return 0;
}
