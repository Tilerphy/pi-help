#include <stdio.h>
#include <string.h>
int main(){
    
    char _char_a_noset[12];
    char _char_a_set[12];
    char* _char_p = "Hellp";
    memset(_char_a_set, 'a', 12);
    printf("noset: %s\n", _char_a_noset);
    printf("set: %s\n", _char_a_set);
    //memset(_char_p, 'a', 5);//left \0 , but not allow _char_p's memory cannot be changed.
    //_char_p[4]='o';
    printf("p set: %s\n", _char_p);
    return 0;
}