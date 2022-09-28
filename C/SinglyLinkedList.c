#include <stdio.h>

typedef struct node{
    int data;
    struct node* next;
}node;

struct node* head;

void insertBeginning(int x){
    node* temp = (node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    if(head!= NULL)
        temp->next = head;
    head = temp;
}

void insertEnd(int x){
    node* newNode = (node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;

    if(head == NULL)
        head = newNode;

    else
    {
        struct node *lastNode = head;

        while(lastNode->next!= NULL)
            lastNode =lastNode->next;

        lastNode->next = newNode;
    }
}

void printList(){
    while(head!=NULL){
        printf("%i ",head->data);
        head = head->next;
    }
}

int main() {
    
    insertEnd(3);
    insertEnd(2);
    insertEnd(1);

    printList();

    return 0;
}