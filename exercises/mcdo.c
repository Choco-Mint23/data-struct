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
	Queue *Serving = initialize();

	enqueue(Q, 17);
	enqueue(Q, 18);
	enqueue(Q, 19);
	enqueue(Q, 20);
	enqueue(Q, 21);
	enqueue(Serving,dequeue(Q));
	enqueue(Serving,dequeue(Q));
	
	printf("PREPARING\n");

	display(Q);
	printf("NOW SERVING\n");
	display(Serving);
	
	
	
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

//Check if the queue is empty (count == 0)
//Store the value found at the front of the queue before it is removed
//If this is the last element in the queue, reset the queue to its initial empty state
//If not, update the front pointer circularly (front = (front + 1) % MAX)
//Decrement the count
//Return the removed value

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
	

	for(i=q->front;i<=q->rear;i++) {
		printf("[%d]\n",q->list.items[i]);
	}
}
