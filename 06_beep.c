#include <wiringPi.h>
#include <stdio.h>

#define BREATH_SIZE 100
enum WiringPiToBCM {B17,B18,B27,B22,B23,B24,B25,B4};

int main(void) {
    wiringPiSetup();
    pinMode(B17, OUTPUT);

    int pin_status = LOW;
    printf("Lesson 6.\n");
    while(1) {
        pin_status = (pin_status == LOW) ? HIGH : LOW;
	digitalWrite(B17, pin_status);
        printf("Pin (%d) status changed(%d).\n", B17, pin_status);
	delay(500);
    }
    return 0;
}
