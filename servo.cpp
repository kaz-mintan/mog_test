#include <stdio.h>
#include <string>
#include <iostream>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
 
#include <wiringPi.h>
 
#define MOTORPWM 18
#define POW 1024

class mog_servo
{
  public:
    void setup();
    void move(int angle);
};

void mog_servo::setup(){

	if(wiringPiSetupGpio()==-1){
      std::cout<<"cannot setup gpio."<<std::endl;
  }
//motor setting
	pinMode(MOTORPWM,PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);
	pwmSetClock(400);
	pwmSetRange(1024);
}

void mog_servo::move(int angle){
  pwmWrite(MOTORPWM,angle);
}
