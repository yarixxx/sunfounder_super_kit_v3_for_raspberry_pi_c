#include <wiringPi.h>
#include <stdio.h>

#define BREATH_SIZE 265
enum WiringPiToBCM {B17,B18,B27,B22,B23,B24,B25,B4};


void changePinTo(int pin, int value) {
  printf("Changing pin %d to %d\n", pin, value);
  int i;
  for (i = 0; i < value; i++) {
    softPwmWrite(pin, i);
    delay(10);
  }
}

void setRGB(int red, int green, int blue) {
  changePinTo(B17, red);
  changePinTo(B18, green);
  changePinTo(B27, blue);
}

int main(void) {
  wiringPiSetup();
  softPwmCreate(B17, 0, BREATH_SIZE);
  softPwmCreate(B18, 0, BREATH_SIZE);
  softPwmCreate(B27, 0, BREATH_SIZE);
  printf("---Lesson 5.---\n");
  while(1) {
    printf("Set RED\n");
    setRGB(256,0,0);
    delay(500);
    printf("Set GREEN\n");
    setRGB(0, 256, 0);
    delay(500);
    printf("Set BLUE\n");
    setRGB(0, 0, 256);
    delay(500);
    printf("Set YELLOW\n");
    setRGB(256, 256, 0);
    delay(500);
    printf("Set PURPLE\n");
    setRGB(256, 0, 256);
    delay(500);
  }

  return 0;
}
