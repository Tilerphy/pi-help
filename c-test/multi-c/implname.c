#include "def.h"
#include <stdio.h>
void printName(char* name){
	printf("Name is :%s\n", name == ""? NAME: name);
}
