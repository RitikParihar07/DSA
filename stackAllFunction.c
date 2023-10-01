#include <stdio.h>
#include<stdbool.h>
#define Max 6
int topp(int stack[],int top){              //return the top value of stack
    return stack[top];
}
void push(int stack[],int* top,int value){               //insert new element at the top .
    if(*top==Max-1){
        printf("overflow");
    }
    else{
        stack[++(*top)]=value;
    }
}
void display(int stack[],int top){                     //display the element of stack from top to bottom
    while(top>=0){
        printf("%d ",stack[top]);
        //printf("%d ",top);
        top--;
    }
}
bool empty(int stack[],int top){              //empty  return true if stack is empty either false
    return top==-1;
}
int pop(int stack[],int* top){               //delete top element from stack and return that element
    int temp;
    if(empty(stack,*top)){                     
        printf("Underflow");
    }
    else{
      temp=stack[(*top)--];
    }
    return temp;
    
}
void replace(int stack[],int* top,int new){             //replace using push and pop;
    pop(stack,top);
    push(stack,top,new);
}


int main()
{
    int top=-1;
    int stack[Max];
    push(stack,&top,10);
    
    push(stack,&top,20);

    push(stack,&top,30);

    push(stack,&top,40);
   
    push(stack,&top,50);
    push(stack,&top,60);
    
    display(stack,top);
    pop(stack,&top);
    
    printf("\n");
    int x=topp(stack,top);
    printf("%d",x);
    printf("\n");
    replace(stack,&top,80);
    display(stack,top);
    return 0;
}
