# SunFounder Super Kit V3.0 for Raspberry Pi (C language).
This is my own version of C lessons of SunFounder Super Kit V3.0 for Raspberry Pi. It is NOT official.

Original code: https://github.com/sunfounder/Sunfounder_SuperKit_C_code_for_RaspberryPi

## How to compile?
gcc helloworld.c -o helloworld -lwiringPi

## To compile with lwiringPiDev
gcc helloworld.c -o helloworld -lwiringPi -lwiringPiDev

After this we can run our application.

./helloworld
