#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5


typedef struct {
    int items[MAX];
    int top;
} Stack;

void initialize(Stack *s);
bool isFull(Stack *s);
bool isEmpty(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
int top(Stack *s);
void display(Stack* s);

int main() {
    
    int i;
   Stack s[3];
   
   for(i=0;i<3;i++) {
       initialize(&s[i]);
   }
    
    int ID;
    int running = 1;
    int check;
    int operation;
    int id;
    int current;
    int popped;
    
    while(running) {
    	
	
    printf("--- Warehouse Inventory Management System ---");
    printf("\n1. Push a container");
    printf("\n2. Pop a container");
    printf("\n3. Check if a container exists");
    printf("\n4. Display all stacks");
    printf("\n5. Exit");
    printf("\nEnter your choice: ");
   scanf("%d",&operation);
   
    

    switch(operation) {
    	case 1:
    	
    	printf("Enter container ID to push: ");
    	scanf("%d",&id);
    	current = 0;
    	while(current<3&&isFull(&s[current])){
    		current++;
		}
    	if(current==3) {
    		printf("All stacks are full");
		} else {
			
			push(&s[current],id);
			printf("Container %d pushed successfully.\n",id);
			
			break;
		}
				
		case 2:
			
	        if(isEmpty(&s[0])==1) {
	        	printf("Error: All stacks are empty. Cannot pop container.\n");
			} else {
				
				for(i=2;i>=0;i--) {
					if(isEmpty(&s[i])==0) {
						int retVal = (pop(&s[i]));
						printf("Container %d popped successfully.\n",retVal);
						
					}
				}
			}

		
		     break;
		     
		case 3: 
		 
		  
		  printf("Enter container ID to check: ");
		  scanf("%d",&check);
		   
		  
		   int j;
		   int k;
		   int found = 0;
		   Stack copy[3];
		   for(i=0;i<3;i++) {
		   	copy[i] = s[i];
		   }
		   for(j=0;j<3;j++) {
		   	for(k=copy[j].top;k!=-1;k--){
		   		if(copy[j].items[k]!=check) {
		   			pop(&copy[j]);
				   } else {
			   	printf("Container %d exists in a stack.\n",check); 
				   found = 1; 
				   break;
			   }
			   } 
			 
		   }
		   
		     if(!found) {
		     	printf("Container %d does not exist in any stack.\n",check); 
				 } 
				 
			break;
			 
		  
		    
		   
			 
		case 4: 
		 
		   for(i=0;i<3;i++) {
		   	
		   	printf("\n--- Stack %d ---\n",i+1);
		    	display(&s[i]);
			}
			
			break;
		case 5: 
		    
		    printf("Exiting program.");
		    running = 0;
			 break;
			 	
	}
   printf("\n");
}
	


    return 0;
}

void initialize(Stack *s){
    
    s->top = -1;
   
    
}
bool isFull(Stack *s) {
    
    if (s->top == MAX-1) {
        return 1;
    } else {
    	return 0;
	}
}

bool isEmpty(Stack *s) {
	
	if(s->top == -1) {
		return 1;
	} else {
		return 0;
	}
}

void push(Stack *s, int value) {
	 if(s->top==MAX-1) {
   	printf("stack is full");
   } 
	s->top++;
	s->items[s->top] = value;
	
}

int pop(Stack *s) {
	
	if (s->top==-1) {
		return -1;
	}
	int value;
	value = s->items[s->top];
	s->top--;
	
	return value;
}

int peek(Stack *s) {
	
		if (s->top==0) {
		return -1;
	}
	return s->items[s->top];
	
}

int top(Stack *s) {
	
	return s->top;
}

void display(Stack* s){
	
		if (s->top==-1) {
		printf("Stack is empty.\n");
	
	}
	int i;
	for(i=s->top;i!=-1;i--) {
		printf("%d\n",s->items[i]);
	}
}
