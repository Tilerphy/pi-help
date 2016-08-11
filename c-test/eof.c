#include <stdio.h>
#include <stdlib.h>
int main(){
    int c;
    FILE* file;
    file = fopen("/labs/labs/c-test/eof.c", "r");
    while((c = getc(file)) != EOF){
        putchar(c);
    }
    fclose(file);
    return 0;
}