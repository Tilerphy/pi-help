#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>

int main(int argc, char ** argv){
	wiringPiSetup();
	pinMode(1, PWM_OUTPUT);
	pinMode(24, INPUT);
	int pwm_v =atoi(argv[1]);
	printf("%d", pwm_v);
	pwmWrite(1, pwm_v);
	return 0;
}
