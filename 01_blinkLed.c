#include "t_extension.h"
#include <wiringPi.h>
#include <stdio.h>

int main(void) {
    // The wiringPiSetup method calls several setup functions. If one of them fail,
    // then it is considered a fatal program fault and the program execution will be
    // terminated at that point with an error message printed on the terminal.
    // See: http://wiringpi.com/reference/setup/
    wiringPiSetup();
    pinMode(B17, OUTPUT);

    int pin_status = LOW;
    printf("Starting blinking.\n");
    while(1) {
        pin_status = (pin_status == LOW) ? HIGH : LOW;
	digitalWrite(B17, pin_status);
        printf("Pin (%d) status changed(%d).\n", B17, pin_status);
	delay(500);
    }
    return 0;
}
