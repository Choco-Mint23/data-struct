#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

typedef struct Stack {
	Node* top;
}Stack;


Stack* initialize();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
void display(Stack* s);

int main () {
	
	Stack *s = initialize();
	
    push(s,5);
    push(s,4);
    pop(s);
    push(s,2);

	display(s);
	printf("\ntop node value is : %d", peek(s));
	
}
Stack* initialize() {
	
	Stack *ptr = malloc(sizeof(Stack));
    ptr->top = NULL;
    return ptr;
}
bool isFull(Stack* s) {
	return 0;
}
bool isEmpty(Stack* s) {
	
	if(s->top==NULL) {
		return 1;
	} else {
		return 0;
	}
}
void push(Stack* s, int value) {
	
	Node *newNode = malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = s->top;
	s->top = newNode;
}
void display(Stack* s) {
	
	if(isEmpty(s)) {
		printf("nothing to see here, stack is currenlty empty\n");
	} else {
		Node *trav = s->top;
		printf("top -> ");
		while(trav!=NULL) {
			printf("%d -> ",trav->data);
			
			trav = trav->next;
		}
		printf("NULL");
		
	}
}
int pop(Stack* s) {
	
	if(isEmpty(s)) {
		printf("stack is empty, nothing to pop :(\n");
		return 0;
	} else {
		
		Node *temp = s->top;
		int value = s->top->data;
		s->top = s->top->next;
		free(temp);
		return value;
	}
	
}
int peek(Stack* s) {
	
	if(isEmpty(s)) {
		printf("stack is currently empty\n");
		return 0;
	} else {
		return s->top->data;
	}
}
