#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>
#define INTERVAL 5
int main(int argc, char** argv){
	int len = atoi(argv[1]);
	wiringPiSetup();
	pinMode(0,OUTPUT);
	pinMode(2,OUTPUT);
	pinMode(3,OUTPUT);
	pinMode(7, OUTPUT);
	digitalWrite(0, len > 0);
//	int num;
//	for(num=0;num<len;num++){
//		int step = num % 4;
//		printf("%d\n", step);
//		digitalWrite(0, step!=0);
//		digitalWrite(2, step!=1);
//		digitalWrite(3, step!=2);
//		digitalWrite(7, step!=3);
//		delay(INTERVAL);
		
//	}
	return 0;
}
