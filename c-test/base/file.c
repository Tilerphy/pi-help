#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    FILE* fp = fopen("/labs/labs/c-test/base/file.c", "r+");
   
    
    int read;
    while((read = getc(fp))!= EOF){
        putchar(read);
    }
    putc('9',fp);
    putc('9',fp);
    putc('9',fp);
    putc('9',fp);
    fclose(fp);
    return 0;
}