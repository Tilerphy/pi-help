#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    int a = -6;
    char buff[24];
    printf("%32x, size: %d", a, sizeof(a));
    
    return 0;
}