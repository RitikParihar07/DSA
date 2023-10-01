#include <stdio.h>
#define Max 5

void enqueue(int queue[], int* f, int* r, int value) {
    if ((*r + 1) % Max == *f) {             //formula for circular queue.
        printf("Queue is full\n");
    } else {
        if (*f == -1) {
            *f = 0;
        }
        *r = (*r + 1) % Max;
        queue[*r] = value;
    }
}

int dequeue(int queue[], int* f, int* r) {
    int temp;
    if (*f == -1) {
        printf("Queue is empty\n");
        return -1;
    } else {
        temp = queue[*f];
        if (*f == *r) {
            *f = -1;
            *r = -1;
        } else {
            *f = (*f + 1) % Max;
        }
        return temp;
    }
}

void display(int queue[], int f, int r) {
    if (f == -1) {
        printf("Queue is empty\n");
    } else {
        int i = f;
        do {
            printf("%d ", queue[i]);
            i = (i + 1) % Max;
        } while (i != (r + 1) % Max);
        printf("\n");
    }
}

int main() {
    int front = -1;
    int rear = -1;
    int queue[Max];

    enqueue(queue, &front, &rear, 10);
    enqueue(queue, &front, &rear, 20);
    enqueue(queue, &front, &rear, 30);
    enqueue(queue, &front, &rear, 40);
    enqueue(queue, &front, &rear, 50);

    display(queue, front, rear);

    dequeue(queue, &front, &rear);
    dequeue(queue, &front, &rear);
    dequeue(queue, &front, &rear);
    dequeue(queue, &front, &rear);
   

    enqueue(queue, &front, &rear, 60);
    enqueue(queue, &front, &rear, 70);

    display(queue, front, rear);

    return 0;
}
