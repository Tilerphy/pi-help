#include <wiringPi.h>
#include <string.h>
#include <stdio.h>
int main(int argc, char** argv){
	wiringPiSetup();
	pinMode(1, PWM_OUTPUT);
	int i;
	
	//float p = (strcmp(argv[2],"d")==0 ? 0.5f:2.5f); 
	//printf("%f\n", p);
	int c = atoi(argv[1]);
	//for(i=0;i<c;i++){
		//digitalWrite(1, HIGH);
		//delay(p);
		//digitalWrite(1,LOW);
		//delay(20);
	//}
	pwmWrite(1, c);
	delay(100);
	pwmWrite(1, 0);
	return 0;
}
