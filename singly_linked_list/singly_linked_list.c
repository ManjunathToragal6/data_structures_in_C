/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;



void creat_node(Node **head, int data){
    
    Node *newNode = malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;
    
    if(*head ==NULL){
        *head = newNode;
    }else{
        Node *temp = *head;
        
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}



void Print_List(Node *head){
    
    Node *temp = head;
    
    while(temp->next != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    
    printf("%d->NULL",temp->data);
    
    
}


int main()
{
    Node *head = NULL;
    
    int data_1 = 5;
    
    for(int i=0; i<5; i++){
    
        creat_node(&head, data_1);
        data_1 = data_1 + 5;
        
    }
    
    Print_List(head);
    
    return 0;
}
