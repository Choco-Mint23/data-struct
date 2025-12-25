#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct stack {
	int items[MAX];
	int top;
}Stack;


Stack* initialize();
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
void display(Stack* s);
int main() {
	
	Stack *s  = initialize();
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    
   printf("value at the top is:%d\n",peek(s));
   display(s);
	return 0;
}
Stack* initialize() {
	
    Stack *ptr = malloc(sizeof(struct stack));
    ptr->top = -1;
    
    return ptr;
	
}
void push(Stack* s, int value) {
	
   if(s->top==MAX-1) {
   	printf("stack is full");
   } 
	s->top++;
	s->items[s->top] = value;
	
}
int pop(Stack* s) {
	
	if (s->top==-1) {
		return -1;
	}
	int value;
	value = s->items[s->top];
	s->top--;
	
	return value;
}
int peek(Stack* s) {
	
		if (s->top==-1) {
		return -1;
	}
	return s->items[s->top];
}
void display(Stack* s){
	
		if (s->top==-1) {
		printf("stack is empty");
	}
	int i;
	for(i=s->top;i>=0;i--) {
		printf("[%d]\n",s->items[i]);
	}
}
