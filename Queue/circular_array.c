#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(Queue* q);
void display(Queue* q);
int main () {
	
	Queue *Q = initialize();
	enqueue(Q,1);
	enqueue(Q,3);
	enqueue(Q,2);
	enqueue(Q,5);
	dequeue(Q);
	
	printf("Queue starts here!:\n");
	display(Q);
}
Queue* initialize() {
	
	Queue *ptr = malloc(sizeof(Queue));
	ptr->front = -1;
	ptr->rear = -1;
	ptr->list.count = 0;
	return ptr;
}
bool isFull(Queue* q) {
	if (q->list.count==MAX) {
		return 1;
	}  else {
		return 0;
	}
}
bool isEmpty(Queue* q) {
	
	if(q->list.count==0) {
		return 1;
	} else {
		return 0;
	}
}
void enqueue(Queue* q, int value) {
	
	if(isEmpty(q)) {
		q->list.items[0] = value;
	
	    q->front = 0;
		q->rear = 0;	
		q->list.count++;
	} else if(isFull(q)) {
		printf("cannot enqueue, queue is empty");
	} else {
		q->rear = (q->rear+1)%MAX;
		q->list.items[q->rear] = value;
		q->list.count++;
	}
}
int dequeue(Queue* q) {
	
	if(isEmpty(q)) {
		return -1;
	}
	int retval = q->list.items[q->front];
	
	if(q->list.count == 1) {
		initialize(q);
	} else {
		q->front = (q->front+1)%MAX;
		q->list.count--;
	}
	return retval;
	
}
int front(Queue* q) {
	if(!isEmpty(q)) {
		return q->list.items[q->front];
	}
	
}
void display(Queue* q) {

	int j=0;
	if(!isEmpty(q)) {
       int i = q->front;
	   while(j!=q->list.count) {
	   	printf("     [%d]\n",q->list.items[i]);
	   	i = (i+1)%MAX;
	   	j++;
	   }	
	}
}
