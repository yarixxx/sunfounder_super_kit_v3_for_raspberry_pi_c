// Original version has too many details. Here I've removed
// led switching so that now it is clear what is the purpose of this lesson.
#include "t_extension.h"
#include <wiringPi.h>
#include <stdio.h>

int main(void) {
    wiringPiSetup();	
    pinMode(B17, INPUT);
    pullUpDnControl(B17, PUD_UP);
    int button_status = 0;
    while(1){
        int new_button_status = digitalRead(B17);
        if (new_button_status != button_status) {
	    printf("Button status changed from %d to %d\n", button_status, new_button_status);
	    button_status = new_button_status;
            // This delay prevents fake events.
	    delay(400);
	}	
    }
    return 0;
}

