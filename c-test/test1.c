#include <stdio.h>
#include <string.h>
int main(){
    unsigned i;
    float a = 0.235;
    
    int b = 10;
    switch (b){
        case 10:
            printf("aaa");
            break;
    }
    for(;i<10;i++){
        printf("%d\n",2+4*4+2);
    }
    char* string = "abcdefghijklmnopq";
    char str[] = "ab";
    printf("len with \\O: %d\n", sizeof(str));
    printf("len without \\O: %d\n", strlen(str));
    printf("%d\n", EOF);
    return 0;
}