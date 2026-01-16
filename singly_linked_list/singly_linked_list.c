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


void insert_at_first(Node **head, int data){
    Node *newNode = malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;
    
    if(*head == NULL){
        *head = newNode;
    }else{
        newNode->next = *head;
        *head = newNode;
    }
}


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


void insert_at_last(Node **head, int data){
    Node *newNode = malloc(sizeof(Node));
    
    newNode->next = NULL;
    newNode->data = data;
    
    if(*head == NULL){
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


int insert_at_pos(Node **head, int data, int pos){
    
    Node *newNode = malloc(sizeof(Node));
    
    newNode->next = NULL;
    newNode->data = data;
    
    
    Node *temp = *head;
    for(int i = 1; i<(pos-1) && temp->next != NULL; i++){
        
        temp = temp->next;
    }
    
    
    newNode->next = temp->next;
    temp->next = newNode;
}

void delete_first(Node **head){
    
    Node *temp = *head;
    
    if(*head == NULL){
        return;
    }else{
        *head = (*head)->next;
        free(temp);
    }
    
    
    
}


void delete_last(Node **head){
    Node *temp = *head;
    
    if(*head == NULL){
        return;
    }else{
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        Node *ToDelete = temp->next;
        temp->next = NULL;
        free(NULL);
        
    }
    
}


void delete_at_pos(Node **head, int pos){
    Node *temp = *head;
    
    if(*head == NULL){
        return;
    }else{
        
        
        for(int i=1; i<(pos-1) && temp->next != NULL; i++){
            temp = temp->next;
        }
        
        Node *ToDelete = temp->next;
        
        temp->next = temp->next->next;
        
        free(ToDelete);
        
    }
}

void sort_list(Node **head){
    
    Node *temp1 = *head;
    Node *temp2 = *head;
    while(temp1->next != NULL){
        temp2 = temp1;
        while(temp2->next != NULL){
            temp2 = temp2->next;
            if(temp1->data <temp2->data){
                int t = temp1->data;
                temp1->data = temp2->data;
                temp2->data = t;
            }
            
        }
        temp1 = temp1->next;
    }
}


int main()
{
    Node *head = NULL;
    
    int data_1 = 5;
    
    for(int i=0; i<5; i++){
    
        creat_node(&head, data_1);
        data_1 = data_1 + 5;
        
    }
    
    
    printf("\n");
    Print_List(head);
    
    insert_at_first(&head, 1500);
    
    printf("\n");
    Print_List(head);
    
    insert_at_last(&head, 2000);
    
    printf("\n");
    Print_List(head);
    
    insert_at_pos(&head,90000,2);
    printf("\n");
    Print_List(head);
    
    delete_first(&head);
    printf("\n");
    Print_List(head);
    
    delete_last(&head);
    printf("\n");
    Print_List(head);
    
    delete_at_pos(&head,5);
    printf("\n");
    Print_List(head);
    
    sort_list(&head);
    printf("\n");
    Print_List(head);
    
    return 0;
}
