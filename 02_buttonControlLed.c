// Original version has too many details. Here I've removed
// led switching so that now it is clear what is the purpose of this lesson.
#include <wiringPi.h>
#include <stdio.h>

#define BUTTON_PIN 	0

int main(void) {
    wiringPiSetup();	
    pinMode(BUTTON_PIN, INPUT);
    pullUpDnControl(BUTTON_PIN, PUD_UP);
    int button_status = 0;
    while(1){
        int new_button_status = digitalRead(BUTTON_PIN);
        if (new_button_status != button_status) {
	    printf("Button status changed from %d to %d\n", button_status, new_button_status);
	    button_status = new_button_status;
            // This delay prevents fake events.
	    delay(400);
	}	
    }
    return 0;
}

