#include <stdio.h>
#include <stdlib.h>
int main(){
    int _int = 10;
    short _short = 10;
    long _long = 10L;
    long int _li = 10;
    long long _ll = 10;
    char _char = 'a';
    char* _char_p = "12345";
    char _char_a[] = "123456";
    //overflow
    char _char_a_b[7] = "123456"; // 7
    int _int_p[10] = {1,2,3,4,5,6,7,8,9,0};
    unsigned long _ul = 100;
    unsigned int _ui = 100;
    int* malloc_int_p = (int*) malloc(100);
    //auto alignment 内存对齐
    struct pet_define {
            int name;
            char type[5];
            int age;
        } Pet;
    struct pet_define cat;
    
    printf("int %d\n" , sizeof(10));
    printf("int %d\n" , sizeof(_int));
    printf("short %d\n" , sizeof(_short));
    printf("long %d\n", sizeof(_long));
    printf("long int %d\n", sizeof(_li));
    printf("long long %d\n" , sizeof(_ll));
    printf("char %d\n" , sizeof(_char));
    printf("char* %d\n" , sizeof(_char_p));
    printf("char[*] %d\n" , sizeof(_char_a));
    printf("char[6] %d\n" , sizeof(_char_a_b));
    printf("int[] %d\n" , sizeof(_int_p));
    printf("first point of int[] %d\n" , sizeof(_int_p[0]));
   
    printf("method %d\n" , sizeof(main));
    printf("unsigned long %d\n" , sizeof(_ul));
    printf("unsigned int %d\n" , sizeof(_ui));
    printf("malloc() for int pointers %d\n", sizeof(malloc_int_p));
    printf("struct: %d\n", sizeof(Pet));
    printf("struct: %d. name is start at %p, age is start at %p", sizeof(cat), &cat.name, &cat.age);
    
    return 0;
}