#include <wiringPi.h>
#include <stdio.h>

// On a T-Extension it is B17
#define LED_PIN		0

int main(void) {
    // The wiringPiSetup method calls several setup functions. If one of them fail,
    // then it is considered a fatal program fault and the program execution will be
    // terminated at that point with an error message printed on the terminal.
    // See: http://wiringpi.com/reference/setup/
    wiringPiSetup();
    pinMode(LED_PIN, OUTPUT);

    int pin_status = LOW;
    printf("Starting blinking.\n");
    while(1) {
        pin_status = (pin_status == LOW) ? HIGH : LOW;
	digitalWrite(LED_PIN, pin_status);
        printf("Pin (%d) status changed(%d).\n", LED_PIN, pin_status);
	delay(500);
    }
    return 0;
}
