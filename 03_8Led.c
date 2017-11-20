#include <wiringPi.h>
#include <stdio.h>

int main(void){
    // https://projects.drogon.net/raspberry-pi/wiringpi/pins/
    wiringPiSetup();

    int leds[4] = {0,1,2,3};

    int i;
    for (i = 0; i < 3; i++) {
	pinMode(leds[i], OUTPUT);
    }

    while(1) {
        for (i = 0; i < 3; i++) {
            digitalWrite(leds[i], LOW);
	    delay(500);
	}
	for (i = 0; i < 3; i++) {
	    digitalWrite(leds[i], HIGH);	
	}
    }
    return 0;
}
