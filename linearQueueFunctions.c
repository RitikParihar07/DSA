/*
                                          Linear queue
*/

#include <stdio.h>
#define Max 5

void enqueue(int queue[],int* f,int* r,int value){   //insert the value in queue
    if(*r==Max-1){              //if rear become Max than it will print 
       printf("queue is full");
    }
    else{
        if(*f==-1)                   //condition for first insert
            *f=0;                    // front become at 0;
        queue[++(*r)]=value;       //first it increase the rear part than insert the value in it
        
    }
}
int dequeue(int queue[],int* f,int* r){   //delete the values
    int temp;
    if(*r==-1){                           //check if rear become -1 reset postion
        printf("Nothing to delete ");
    }
    else{
        temp=queue[(*f)++];               //for return the value of delete element 
        if(*f>*r){                       //check if front become greater then rear then reset the value
            *f=-1;
            *r=-1;
        }
    }
    return temp;
}
void display(int queue[],int f,int r){        //for display the elements
    if(r==-1){
        printf("Nothing to display ");           //if no element found
    }
    else{
        while(f<=r){                             //loop will run until the front will equal to rear 
            printf("%d ",queue[f++]);
        }
        printf("\n");
    }
}

int main()
{
   int front=-1;
   int rear=-1;
   int queue[Max];
   enqueue(queue,&front,&rear,10);
   enqueue(queue,&front,&rear,20);
   enqueue(queue,&front,&rear,30);
   enqueue(queue,&front,&rear,40);
   enqueue(queue,&front,&rear,50);
   display(queue,front,rear);
   dequeue(queue,&front,&rear);
   dequeue(queue,&front,&rear);
   dequeue(queue,&front,&rear);
   dequeue(queue,&front,&rear);
   dequeue(queue,&front,&rear);
   dequeue(queue,&front,&rear);
   enqueue(queue,&front,&rear,50);
   display(queue,front,rear);
   
    return 0;
}
