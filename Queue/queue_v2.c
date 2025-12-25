#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
	int items[MAX];
	int front;
	int rear;
	
}Queue;

Queue* initialize();
bool isEmpty(Queue* q);
bool isFull(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
void display(Queue* q);
int main() {
	
	
	Queue *Q = initialize();
	enqueue(Q,1);
	enqueue(Q,2);
	enqueue(Q,3);
	dequeue(Q);
	display(Q);
	
}

Queue* initialize() {
	
	Queue *ptr = malloc(sizeof(Queue));
	
	ptr->front = 1;
	ptr->rear = 0;
	
	return ptr;
}
bool isEmpty(Queue* q) {
	
	if (q->front==(q->rear+1)%MAX) {
		return 1;
	} else {
		return 0;
	}
	
}
bool isFull(Queue* q) {
	
	if(q->front == (q->rear+2)%MAX) {
		return 1;
		
	} else {
		return 0;
	}
}

void enqueue(Queue* q, int value) {
	
	if (q->front==(q->rear+2)%MAX) { 
		printf("queue is full\n");
	} else {
		q->rear = (q->rear+1)%MAX;
		q->items[q->rear] = value;
	}
}
int dequeue(Queue* q) {
	
	
	if (q->front==(q->rear+1)%MAX) {
		printf("queue is empty\n");
	} else {
	    int num = q->items[q->front];
		q->front = (q->front+1)%MAX;
			return num;
	}

		
}
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("queue is empty\n");
    } else {
        int i = q->front;
        while (i != (q->rear + 1) % MAX) {
            printf("%d\n", q->items[i]);
            i = (i + 1) % MAX;
        }
    }
}
