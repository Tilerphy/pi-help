#include <stdio.h>
#include <stdlib.h>
int main(){
    int c;
    FILE* file;
    file = fopen("/labs/labs/c-test/eof.c", "r");
    int line;
    line = 0;
    printf("%d. ", line);
    while((c = getc(file)) != EOF){
        putchar(c);
        if(c == '\n'){
            line ++;
            printf("%d. ", line);
        }
    }
    fclose(file);
    return 0;
}