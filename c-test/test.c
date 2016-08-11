#include <stdio.h>
int (*b)(int a);
int hello(int c);
typedef char* STR;
int main(){
    
    //name: str
    //PTR Type: char*
    //PTR pointing type: char
    char* str = "Todaymnvuio.";
    //print the 4th char
    printf("%c\n", str[3]);
    //print the size of char* 
    printf("%d\n", sizeof(str));
    //print the first addr
    printf("%d\n", &str);
    //int next8 = &str +1;
    
    //&str is a PTR
    //*<addr> is the object which <addr>'s storing
    
    printf("%s\n", *(&str));
    
    printf ("%s\n" , str+1);
    printf("%d\n", str);
    
    //PTR type: char* []
    //PTR pointing type: char[]
    char* strs[] = {"abcd", "efgh"};
    printf("%s\n", *(strs+1));
    
    int charArray[] = {1,2,3,4,5,6,7};
    printf("%s\n", charArray);
    printf("%d\n", sizeof(charArray));
    printf("%c\n", *charArray);
    
    //
    STR aaa = "sdsds";
    b = hello;
    b(10);
    return 0;
}

int hello(int c){
    printf(" is %d? ", c);
}