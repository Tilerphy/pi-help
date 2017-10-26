#include <stdio.h>
#include <wiringPi.h>
#define DIN 8
#define CS 9
#define CLK 7

void write7219(int line){
	int mask = 0x80;
	for(mask = 0x80; mask>0; mask >>= 1){
		//get ready
		digitalWrite(CLK, LOW);
		// B0110 1001 & B1000 0000
		// B0110 1001 & B1000 0000
		digitalWrite(DIN, (mask & line) != 0);
		digitalWrite(CLK, HIGH);
	}
}

void w(int line, int col){
	digitalWrite(CS, LOW);
	write7219(line);
	write7219(col);
	digitalWrite(CS, HIGH);
}
void clear(){
	int i=0;
	for(i=1;i<9;i++){
		w(i, 0x00);
	}
}
int main(){
	wiringPiSetup();
	pinMode(DIN, OUTPUT);
	pinMode(CS, OUTPUT);
	pinMode(CLK, OUTPUT);
	
	w(0x09, 0x00); // direct
	w(0x0b, 0x07); //scan 0:7
	w(0x0c, 0x01);
	w(0x0a, 0x01);
	int i = 0;
	while(i<8){
		w(1, 0x00);
		w(2, 0x66);
		w(3, 0x99);
		//w(3,0x00);
		w(4, 0x82);
		w(5, 0x44);
		//w(4, 0x00);
		//w(5, 0x00);
		w(6, 0x44);
		//w(6, 0x20);
		w(7, 0x28);
		//w(7, 0x18);
		w(8, 0x10);
		//w(8, 0x00);
		delay(200);
		clear();
		delay(100);
		i++;
		
	}
	return 0;
}
