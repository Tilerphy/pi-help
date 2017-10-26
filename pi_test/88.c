#include <stdio.h>
#include <wiringPi.h>
#define DIN 8
#define CS 0
#define CLK 25

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

void printStar(int t){
	
	w(4, 0x18);
	w(5, 0x18);
	delay(t);
	clear();
	w(3, 0x18);
	w(4, 0x24);
	w(5, 0x24);
	w(6, 0x18);
	delay(t);
	clear();
	w(2, 0x3c);
	w(3, 0x42);
	w(4, 0x42);
	w(5, 0x42);
	w(6, 0x42);
	w(7, 0x3c);
	delay(t);
	clear();
	w(1, 0xff);
	w(2, 0x81);
	w(3, 0x81);
	w(4, 0x81);
	w(5, 0x81);
	w(6, 0x81);
	w(7, 0x81);
	w(8, 0xff);
	delay(t);
	clear();
}

void printDEC(int i){
	clear();
	switch(i){
		case 0:
			w(2, 0x3c);
			w(3, 0x24);
			w(4, 0x24);
			w(5, 0x24);
			w(6, 0x24);
			w(7, 0x3c);
			break;
		case 1:
			w(2, 0x08);
			w(3, 0x08);
			w(4, 0x08);
			w(5, 0x08);
			w(6, 0x08);
			w(7, 0x08);
			break;
		case 2:
			w(2, 0x3c);
			w(3, 0x04);
			w(4, 0x3c);
			w(5, 0x20);
			w(6, 0x20);
			w(7, 0x3c);
			break;
		case 3:
			w(2, 0x3c);
			w(3, 0x04);
			w(4, 0x3c);
			w(5, 0x04);
			w(6, 0x04);
			w(7, 0x3c);
			break;
		case 4:
			w(2, 0x04);
			w(3, 0x0c);
			w(4, 0x14);
			w(5, 0x24);
			w(6, 0x3e);
			w(7, 0x04);
			break;
		case 5:
			w(2, 0x3c);
			w(3, 0x20);
			w(4, 0x3c);
			w(5, 0x04);
			w(6, 0x04);
			w(7, 0x3c);
			break;
		case 6:
			w(2, 0x3c);
			w(3, 0x20);
			w(4, 0x3c);
			w(5, 0x24);
			w(6, 0x24);
			w(7, 0x3c);
			break;
		case 7:
			w(2, 0x3c);
			w(3, 0x04);
			w(4, 0x04);
			w(5, 0x04);
			w(6, 0x04);
			w(7, 0x04);
			break;
		case 8:
			w(2, 0x3c);
			w(3, 0x24);
			w(4, 0x3c);
			w(5, 0x24);
			w(6, 0x24);
			w(7, 0x3c);
			break;
		case 9:
			w(2, 0x3c);
			w(3, 0x24);
			w(4, 0x3c);
			w(5, 0x04);
			w(6, 0x04);
			w(7, 0x3c);
			break;
		default:
			break;
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
	i++;
		//w(1, 0x00);
		//w(2, 0x66);
		//w(3, 0x99);
		//w(3,0x00);
		//w(4, 0x82);
		//w(5, 0x44);
		//w(4, 0x00);
		//w(5, 0x00);
		//w(6, 0x44);
		//w(6, 0x20);
		//w(7, 0x28);
		//w(7, 0x18);
		//w(8, 0x10);
		//w(8, 0x00);
	//	w(1, 0x01);
	//	w(2, 0x02);
	//	w(3, 0x04);
	//	w(4, 0x08);
	//	w(5, 0x10);
	//	delay(200);
	//	clear();
	//	delay(100);
	//	i++;
	//
		printStar(100);	
	}
	for(i=0;i<10;i++){
		printDEC(i);
		printDEC(i);
		printDEC(i);
		delay(500);
	}
	return 0;
}
