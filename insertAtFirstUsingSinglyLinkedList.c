#include <stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *next;
};
typedef struct node node;
void insertAtFirst(node** head,int value){
    node* temp=(node* )malloc(sizeof(node));
    temp->info=value;                               
    temp->next=*head;                                 //In first node head will null 
    *head=temp;                                     // so head will point to first node always

}
void display(node* head){
    node* temp=head;
    if(head==NULL){
        printf("Nothing to display");
    }
    while(temp){
        printf("%d ",temp->info);
        temp=temp->next;
    }
    printf("\n");
}
int dltAtFirst(node** head){
    node* temp=*head;
    int t;
    if(*head==NULL){
        printf("Nothing to dlt");
    }
    else{
        *head=((*head)->next);
        temp->next=NULL;
        t=temp->info;
        free(temp);
    }
    return t;
}
int main(){
    node* head=NULL;
    insertAtFirst(&head,10);
    insertAtFirst(&head,20);
    insertAtFirst(&head,30);
    display(head);
    dltAtFirst(&head);
     dltAtFirst(&head);
      
    display(head);
}