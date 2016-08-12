#include <stdio.h>
#include <wiringPi.h>
int main(){
	wiringPiSetup();
	pinMode(7, OUTPUT);
	while(1){
		digitalWrite(7,  LOW);
		delay(500);
		digitalWrite(7, HIGH);
		delay(500);
	}
	return 0;
}
