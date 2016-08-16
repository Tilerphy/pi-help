#include <stdio.h>

int main(){
    unsigned long t = (unsigned long)time(0);
    printf("%d\n", t);
    printf("Year %.0f\n", 1970+(float)(t/(86400*365)));
    return 0;
}