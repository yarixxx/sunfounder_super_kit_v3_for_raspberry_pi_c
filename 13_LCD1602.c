#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <lcd.h>
#include "t_extension.h"

#define ROWS 2
#define COLUMNS 16
#define BITS 4
#define RS B27
#define STRB 3

int main(void) {
	int fd;
	wiringPiSetup();

     // RS -> B27 (2)
     // E  -> B22 (3)
     // D4 -> B25 (6)
     // D5 -> B24 (5) 
     // D6 -> B23 (4)
     // D7 -> B18 (1)
     // There is something strange here, D0-D3 shouldn't be used, D4-D7 should be.
     // fd = lcdInit(2,    16,      4,    2,  3,    6, 5, 4, 1, 0, 0, 0, 0); //see /usr/local/include/lcd.h
        fd = lcdInit(ROWS, COLUMNS, BITS, RS, STRB, 6, 5, 4, 1, 0, 0, 0, 0);	

	int i;
	i = 0;
	char scounter[15];
	while(1){		
		sprintf(scounter, "N: %d", i);
		lcdClear(fd);
		lcdPosition(fd, 0, 0);
		lcdPuts(fd, "Hello!");
		lcdPosition(fd, 0, 1);
		lcdPuts(fd, scounter);
		delay(1000);
		i++;
		printf("Number: %d\n", i);
	}

	return 0;
}
