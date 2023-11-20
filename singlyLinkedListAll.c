/******************************************************************************

Singly linked list all function 
1.Insert at first and last.
2.Delete from first and last.
3.Display function.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
typedef struct node{
    int info;
    struct node *next;
}node;

//insert the elements at first 
void insertatfirst(node** head,int value){
    node *temp=(node*)malloc(sizeof(node));
    temp->info=value;
    temp->next=*head;
    *head=temp;
}

//insert the elements at last
void insertatlast(node** head,int value){
    node *temp=(node*)malloc(sizeof(node));
    temp->info=value;
    temp->next=NULL;
    if(*head==NULL){
        *head=temp;
    }
    else{
        node *last=*head;
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=temp;
    }
}

//delete the elements from last
int deleteFromLast(node** head) {
    if (*head == NULL) {
        printf("Error: List is empty\n");
    }
    int value;
    node *current = *head, *prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    if (prev != NULL) {
        prev->next = NULL;
    } else {
        *head = NULL;
    }
    value = current->info;
    free(current);
    return value;
}


//delete the elements from first
int deletefromfirst(node** head){
    if (*head == NULL) {
        printf("Error: List is empty\n");
    }
    node* temp=*head;
    int value=temp->info;
    *head=temp->next;
    temp->next=NULL;
    free(temp);
    return value;
}

//display the elements 1->2->3->NULL
void display(node *head){
    node* temp=head;
    while(temp){
        printf("%d->",temp->info);
        temp=temp->next;
    }
    printf("NULL");
    printf("\n");
}

int main()
{
    node *head=NULL;
    int n;
    printf("Enter number of element: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(int i=0;i<n;i++){
        int value;
        scanf("%d",&value);
        insertatlast(&head,value);
    }
    display(head);
    deleteFromLast(&head);
    display(head);
}
