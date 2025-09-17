//Queue is a linked list with front and rear. 
//FRONT is a pointer to the last node of the list,
// REAR is a pointer to the first node of the list.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

typedef struct Queue {
	Node* front;
	Node* rear;
} Queue;

Queue* initialize();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
void display(Queue* q);
int dequeue(Queue* q);
int front(Queue* q);

int main() {
	
	Queue *q =initialize();
	enqueue(q,5);
	enqueue(q,7);
	enqueue(q,9);
	
	
	dequeue(q);
	
	display(q);
	printf("person in front of queue is %d\n",front(q));
}
Queue* initialize() {
	Queue *ptr = malloc(sizeof(Queue));
	ptr->front = NULL;
	ptr->rear = NULL;
	
	return ptr;
}

bool isFull(Queue* q) {
	
	return 0; //linked list can never be full!
}

bool isEmpty(Queue* q) {
	
	if(q->rear == NULL) {
		return 1;
	} else {
		return 0;
	}
}

void enqueue(Queue* q, int value) {
	
	Node *ptr = malloc(sizeof(Node));
	ptr->data = value;
	ptr->next = NULL;
	
	if(q->rear==NULL) {
		
		q->rear = ptr;
		q->front = ptr;
	} else {
		
		   q->front->next = ptr;
		   q->front = ptr;
	}
	
}
int dequeue(Queue* q) {
	
	if(q->rear!=NULL) {
		Node *temp = q->rear;
		int retval = q->rear->data;
		
		q->rear = q->rear->next;
		if(q->rear==NULL ){
			q->front ==NULL;
		}
		free(temp);
		
		return retval;
	}
}

int front(Queue* q) {
	
	if(q->rear!=NULL) {
		return q->rear->data;
	} else {
		printf("Queue is empty");
		return 0;
	}
}

void display(Queue* q) {
	
	if(q->rear!=NULL) {
		Node *trav = q->rear;
		
		printf("Queue starts here:\n");
		while(trav!=NULL) {
			printf("[%d]\n",trav->data);
			trav = trav->next;
		}
	} else {
		printf("Queue is currently empty");
	}
}
