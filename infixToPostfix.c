#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define Max 6

int topp(int stack[], int top) {
    return stack[top];
}

void push(int stack[], int* top, int value) {
    if (*top == Max - 1) {
        printf("overflow");
    } else {
        stack[++(*top)] = value;
    }
}

void display(int stack[], int top) {
    while (top >= 0) {
        printf("%d ", stack[top]);
        top--;
    }
}

bool empty(int stack[], int top) {
    return top == -1;
}

int pop(int stack[], int* top) {
    int temp;
    if (empty(stack, *top)) {
        printf("Underflow");
        return -1; 
    } else {
        temp = stack[(*top)--];
    }
    return temp;
}

int prio(char op) {
    switch (op) {
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
    }
    return 0; 
}

int main() {
    int top = -1;
    int stack[Max];
    char s[] = "a+b/c-d*e";
   //int x=s[5];
   // printf("%d",x);
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            printf("%c ", s[i]);
        } else {
            while (!empty(stack, top) && prio(s[i]) <= prio(topp(stack, top))) {
                printf("%c ", (char)pop(stack, &top));
            }
            push(stack, &top, s[i]);
        }
    }

    while (!empty(stack, top)) {
        printf("%c ", (char)pop(stack, &top));
    }

    return 0;
}
