#include <stdio.h>

int main(){
    
    int i = 11;
    long l = 1000l;
    float f = 10.5f;
    double d = 9.9d;
    
    printf("%f\n", (float)l/i);
    printf("%f\n", f/l);
    printf("%f\n", l/f);
    printf("%f\n", l/d);
    
    return 0;
}