#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    int a = -6;
    char buff[24];
   
    char* str = "ppp01234567";
    char** strs;
    *(strs) = "123456";
    *(strs+1) = "234567";
    
    printf("%s %s\n", strs[0], strs[1]);
    printf("%p %p\n", strs, *strs);
    /*
        char* str =  "1   2   3  4  5  6  7";
                     str
              &str    
        str[0] is the value of 1
    */
    
    
    printf("str %p\n", str);// str is the first address of the data of "1234567"
    printf("&str %p\n", &str);
    printf("str[0] %p\n", str[0]);
    printf("&str[0] %p\n", &str[0]);
    printf("%32x, size: %d\n", a, sizeof(a));
    
    int* ints = (int*)malloc(6);
    *(ints) = 1;
    *(ints+1) = 2;
    ints[2] = 3;
    ints[3] = 4;
    ints[4] =5;
    ints[5] =6;
    
    printf("ints %p\n", ints);// str is the first address of the data of "1234567"
    printf("&ints %p\n", &ints);
    printf("ints[0] %p\n", ints[0]);
    printf("&ints[0] %p\n", &ints[0]);
    printf("&ints[0] %d\n", *(&ints[0]+2));
    free(ints);
    
    printf("-3<-2<1 %d\n", -3<-2==1);
    return 0;
}