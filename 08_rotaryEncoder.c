#include "t_extension.h"
#include <wiringPi.h>
#include <stdio.h>

int main(void) {
    wiringPiSetup();

    printf("Lesson 08: Rotary Encoder");
    
    pinMode(B17, INPUT);
    pinMode(B18, INPUT);
    pinMode(B27, INPUT);

    int angle = 0;

    while(1){
        int button = digitalRead(B18);
        if (!button) {
            printf("Button Pressed.\n");
	    delay(200);
        }
        int turnBackPin = digitalRead(B17);
        int turnForwardPin = digitalRead(B27);
        if (!turnBackPin) {
	    angle = angle - 1;
	    printf("Angle: %d\n", angle);
	    delay(100);
        }
	if (!turnForwardPin) {
	    angle = angle + 1;
	    printf("Angle: %d\n", angle);
	    delay(100);
        }    
    }

    return 0;
}
