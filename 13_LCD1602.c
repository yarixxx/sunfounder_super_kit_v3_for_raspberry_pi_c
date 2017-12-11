#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <lcd.h>

const unsigned char Buf[] = "---SUNFOUNDER---";
const unsigned char myBuf[] = "  sunfounder.com";

int main(void) {
	int fd;
	wiringPiSetup();

	fd = lcdInit(2,16,4, 2,3, 6,5,4,1,0,0,0,0); //see /usr/local/include/lcd.h

	int i;
	i = 0;
	while(1){
		lcdClear(fd);
		lcdPosition(fd, 0, 0);
		lcdPuts(fd, "Hello!");
		lcdPosition(fd, 0, 1);
		lcdPuts(fd, "World");
		delay(1000);
		i++;
	}

	return 0;
}
