#include "t_extension.h"
#include <wiringPi.h>
#include <stdio.h>

#define PINS_NUMBER 8

void switchPinsSequentially(int pins[], int status, int length) {
  printf("Switch pins: %d\n", status);
  int i;
  for (i = 0; i < length; i++) {
    digitalWrite(pins[i], status);
    delay(200);
  }
}

void initializePins(int pins[], int type, int length) {
  printf("Initialize pins.");
  int i;
  for (i = 0; i < length; i++) {
    pinMode(pins[i], type);
  }
}

int main(void) {
    // https://projects.drogon.net/raspberry-pi/wiringpi/pins/
    wiringPiSetup();

    int leds[PINS_NUMBER] = {B17,B18,B27,B22,B23,B24,B25,B4};
    printf("---Lesson 03---\n");

    initializePins(leds, OUTPUT, PINS_NUMBER);

    while(1) {
	switchPinsSequentially(leds, LOW, PINS_NUMBER);
	switchPinsSequentially(leds, HIGH, PINS_NUMBER);
    }
    return 0;
}
