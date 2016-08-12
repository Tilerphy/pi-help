#include <stdio.h>
struct student{
	char* name;
	int age;	
};

void te(struct student *s);
int main(){
	struct student test ;
	test.name = "abcd";
	te(&test);
	printf(test.name);
	return 0;
}

void te(struct student *s){
	s->name = "hy";
}
