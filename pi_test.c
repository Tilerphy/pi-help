#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
int main(int argc, char** argvs){
	wiringPiSetup();
	pinMode(0, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(2, OUTPUT);
        pinMode(3, OUTPUT);
	int a  = atoi(argvs[1]);
	printf("%d\n", a);
	int i = 5;
	int count = 0 ;
	while(count <= 64 * 8 *a){
		
//A
		digitalWrite(7,  HIGH);
		digitalWrite(0, LOW);
		 digitalWrite(2,  LOW);
                digitalWrite(3, LOW);
		delay(i);
//AB
		digitalWrite(7, HIGH);
		digitalWrite(0, HIGH);
		digitalWrite(2,  LOW);
                digitalWrite(3, LOW);

		delay(i);
//B
		digitalWrite(7, LOW);
                digitalWrite(0, HIGH);
                digitalWrite(2,  LOW);
                digitalWrite(3, LOW);

                delay(i);
//BC
		digitalWrite(7, LOW);
                digitalWrite(0, HIGH);
                digitalWrite(2,  HIGH);
                digitalWrite(3, LOW);

                delay(i);
//C		
		digitalWrite(7, LOW);
                digitalWrite(0, LOW);
                digitalWrite(2,  HIGH);
                digitalWrite(3, LOW);

                delay(i);
//CD
		digitalWrite(7, LOW);
                digitalWrite(0, LOW);
                digitalWrite(2,  HIGH);
                digitalWrite(3, HIGH);

                delay(i);
//D
		digitalWrite(7, LOW);
                digitalWrite(0, LOW);
                digitalWrite(2,  LOW);
                digitalWrite(3, HIGH);

                delay(i);
//DA
		digitalWrite(7, HIGH);
                digitalWrite(0, LOW);
                digitalWrite(2,  LOW);
                digitalWrite(3, HIGH);

                delay(i);


		count++;


	}
	return 0;
}
