#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef  struct _Node{
        struct _Node* next;
        char* val;
    } Node;
    
void print_list(Node* head);
void create_list(Node* head);
int main(){
    Node* head = (Node*)malloc(sizeof(Node));
    head->val= "";
    Node** current;
    *current = head;
    while(1){
        Node* tmp = (Node*)malloc(sizeof(Node));
        tmp->val = (char*) malloc (128);
        scanf("%s", tmp->val);
        if(strcmp(tmp->val, "q")==0){
            break;
        }
        tmp->next = NULL;
        (*current)->next = tmp;
        *current = tmp;
    }
    print_list(head);
    return 0;
}

void print_list(Node* head){
    Node* next = head->next;
    if(next){
        printf("%s\n", next->val);
        print_list(next);  
    }else{
        printf("finished.\n");
    }
}