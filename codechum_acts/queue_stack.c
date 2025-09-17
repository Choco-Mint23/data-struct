#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int count;
} List;

typedef struct {
    List list;
    int front;
    int rear;
} Queue;

Queue* initialize();
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void display(Queue* q);

int main() {
   
    Queue *regular = initialize();
    Queue *priority = initialize();
    int choice;
    int running =1;
    int queue = 1;
    
    while(running) {
    	
    	printf("--- Pharmacy Queueing System ---\n");
    printf("1. Enter Regular Queue\n");
    printf("2. Enter Priority Queue\n");
    printf("3. Call Next Customer\n");
    printf("4. Display Queues\n");
    printf("5. Exit\n");
    
    printf("Enter your choice: ");
    scanf("%d",&choice);
    
      switch(choice)  {

      	case 1:
      		
      		if(regular->list.count == MAX) {
      			printf("Regular queue is full. Please try again later.\n\n");
			  } else {
			  	printf("You have entered the Regular queue. Your number is %d.\n\n",queue);
      		enqueue(regular,queue);
      		queue++;
			  }
      	
      		
      		
      		break;
      		
	  
         case 2:
         	
         	if(priority->list.count == MAX) {
         		printf("Priority queue is full. Please try again later.\n\n");
			 } else {
			 		printf("You have entered the Priority queue. Your number is %d.\n\n",queue);
      		enqueue(priority,queue);
      		queue++;
			 }
         
    		break;
	
	
		case 3:
			
			if(!isEmpty(priority)) {
				 
				printf("Calling next customer from Priority Queue. Customer number: %d\n\n",dequeue(priority));
			} else if (isEmpty(priority)){
			 
				printf("Calling next customer from Regular Queue. Customer number: %d\n\n",dequeue(regular));
			} else {
				printf("No customers in queue.\n");
			}
			break;
			
			 case 4:
			 	
			 	
			 	printf("\n-- Current Queue Status --\n");
			 	printf("Regular Queue: ");
                display(regular);
			 	
                printf("Priority Queue: ");
                display(priority);
                printf("\n");
                break;
            
            case 5:
                running = 0;
                printf("Exiting program. Goodbye!");
                break;

              }
          }
    
    
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
bool isFull(Queue* q) {
	
	if(q->list.count==MAX) {
		return 1;
		
	} else {
		return 0;
	}
}
bool isEmpty(Queue* q) {
	
	if (q->list.count == 0) {
		return 1;
	} else {
		return 0;
	}
	
}
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        int i = q->front;
        int cnt = q->list.count;
        while (cnt > 0) {
            printf("%d ", q->list.items[i]);
            i = (i + 1) % MAX;
            cnt--;
        }
        printf("\n");
    }
}
