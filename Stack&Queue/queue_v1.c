#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
	int items[MAX];
	int count;
}List;

typedef struct {
	List list;
	int front;
	int rear;
	
}Queue;

Queue* initialize();
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(Queue* q);
void display(Queue* q);
int main() {
	
	Queue *Q = initialize();

	enqueue(Q, 7);
	enqueue(Q, 1);
	enqueue(Q, 9);
	dequeue(Q);
	enqueue(Q, 8);
	
	display(Q);
	
	return 0;
}
Queue* initialize() {
	
	Queue *ptr = malloc(sizeof(Queue));
	ptr->list.count = 0;
	ptr->front = -1;
	ptr->rear = -1;
	
	return ptr;
}
void enqueue(Queue* q, int value) {
	
	if(q->list.count == MAX) {
		printf("queue is full");
	}
	if(q->list.count == 0) {
		q->front = 0;
		q->rear = 0;
	} else {
		q->rear = (q->rear+1) % MAX;
	}
	q->list.items[q->rear] = value;
	q->list.count++;
	
}
int dequeue(Queue* q) {
	if(q->list.count == 0) {
     return -1;
     }
     
     int value = q->list.items[q->front];
     
     if(q->list.count==1) {
     		q->list.count = 0;
		q->front = -1;
		q->rear = -1;
	 }  else {
	 	
	 	q->front = (q->front+1)% MAX;
	 	    q->list.count--;
	 }
	 
     return value;
}
int front(Queue* q) {
	
	if(q->list.count==0) {
		return -1;
	}
	return q->list.items[q->front];
}
void display(Queue* q) {
	
		if(q->list.count==0) {
		printf("queue is empty");
	}
	int i;
	
	printf("ROSE PHARMACY\n");
	printf("NOW SERVING:\n");
	for(i=q->front;i<=q->rear;i++) {
		printf("[%d]\n",q->list.items[i]);
	}
}
