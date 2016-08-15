#include <stdio.h>
#include <stdlib.h>
int main(){
    
    char* cs;
    printf("%d\n", sizeof(char));
    cs = (char*)malloc(5);
    cs[0] = '1';
    cs[1] = '2';
    cs[2] = '3';
    cs[3] = '4';
    cs[4] = '5';
    
    printf("is same? %d \n", &cs[0] == cs);
    
    printf("%c is in pointer: %p \n", cs[4], &cs[4]);
    free(cs);
    printf("%c is in pointer: %p \n", cs[4], &cs[4]);
    //address of cs is not change after 'free()' function
    cs = NULL;
    printf("IS NULL? %d . ADDRESS: %p \n", cs == NULL, &cs);
    return 0;
}