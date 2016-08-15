#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int* (*func)(int);
void try_test(func f, int* *result);
int* test(int num);
int main(){
    
    int* result;
    int counter;
    try_test(test, &result);
    for(counter =0; counter< 100; counter++){
        printf("%d\n", result[counter]);
    }
    return 0;
}

void try_test(func f, int* *result){
    *result = f(100);
}

int* test(int num){
    int* result;
    int counter;
    result = (int*)malloc(num);
    memset(result, 0, num);
    for(counter =0; counter <num; counter++){
        result[counter] = counter;
    }
    return result;
}