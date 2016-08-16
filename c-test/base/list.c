#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Define a struct as Node
*/
typedef struct _Node {
    struct _Node* next; // include a pointer of the next _Node
    char val[16]; // include a string value
} Node;

/*
    Define a method to add node the the list
    You can find the list data from head pointer
*/
void addNode(Node* head, Node* node);
void print(Node* head);
void clear(Node* head);

int main(){
    printf("Node is : %d\n", sizeof(Node));
    //create a headPointer
    //malloc a size of Node
    Node* headPointer = (Node*)malloc(sizeof(Node));
    while(1){
        Node* tmp= (Node*)malloc(sizeof(Node));
        scanf("%s", tmp->val);
        printf("%s\n", tmp->val);
        if(strcmp(tmp->val, "q") == 0){
            free(tmp);
            break;
        }else{
            addNode(headPointer, tmp);
        }
    }
    
    print(headPointer);
    clear(headPointer);
    print(headPointer);
    return 0;
}

void clear(Node* head){
    if(head){
        if(head->next){
            clear(head->next);
        }
        free(head);
        head= NULL;
    }
}

void print(Node* head){
    printf("start print");
    if(head){
            Node* cursor;
            for(cursor = head; cursor; cursor = cursor->next){
                printf("%s\n", cursor->val);
            }
    }else{
        printf("list head is NULL.");
    }
}

void addNode(Node* head, Node* node){
    printf("start addNode, val is %s\n", node->val);
    printf("head  is %p\n", head);
    printf("head->next  is %p\n", head->next);
    if(head){
        if(node){
            Node* cursor;
            //cursor goes to the end of the list 
            for(cursor = head; cursor->next; cursor = cursor->next){
                 printf("cursor is on: %p\n", cursor);
            }
            //printf("cursor->next  is %p\n", cursor->next);
            cursor->next = node;
        }else{
            printf("cannot add NULL to a list.");
        }
    }else{
        printf("list head is NULL.");
    }
}