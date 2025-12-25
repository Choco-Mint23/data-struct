#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> /


typedef struct node {
    char name[50];
    char role[50];  
    int priority;   
    struct node* next;
} Node;

typedef struct {
    Node* front;
} PriorityQueue;


PriorityQueue* initialize();
void enqueue(PriorityQueue* pq, char* name, char* role);
char* dequeue(PriorityQueue* pq);
bool isGuestInQueue(PriorityQueue* pq, char* targetName);
void findGuestsLike(PriorityQueue* pq, char* roleFragment);
void display(PriorityQueue* pq);


int main() {
   
    printf("--- TEST 1: Initialization ---\n");
    PriorityQueue* weddingQ = initialize();
    if (weddingQ != NULL && weddingQ->front == NULL) {
        printf("[PASS] Queue initialized successfully.\n");
    } else {
        printf("[FAIL] Queue initialization error.\n");
    }

    printf("\n--- TEST 2: Enqueue (Checking Priority Logic) ---\n");
    
    enqueue(weddingQ, "John Doe", "Regular Guest");       // Prio 1
    enqueue(weddingQ, "Auntie Julie", "Mother of Family"); // Prio 50 (strstr "Family")
    enqueue(weddingQ, "Mayor Tom", "VIP Sponsor");        // Prio 20 (strstr "VIP")
    enqueue(weddingQ, "Kevin Tan", "Groom");              // Prio 100 (strcmp "Groom")
    enqueue(weddingQ, "Jane Smith", "Regular Guest");     // Prio 1

    display(weddingQ); 

    printf("\n--- TEST 3: Check Specific Guest (isGuestInQueue) ---\n");
    
    if (isGuestInQueue(weddingQ, "Kevin Tan") == true) {
        printf("[PASS] Found 'Kevin Tan'.\n");
    } else {
        printf("[FAIL] Could not find 'Kevin Tan'.\n");
    }

    if (isGuestInQueue(weddingQ, "Harry Potter") == false) {
        printf("[PASS] Correctly did not find 'Harry Potter'.\n");
    } else {
        printf("[FAIL] False positive found for 'Harry Potter'.\n");
    }

    printf("\n--- TEST 4: Find Guests by Role Fragment (findGuestsLike) ---\n");
    printf("Searching for 'Guest'...\n");
    findGuestsLike(weddingQ, "Guest"); 

    printf("\n--- TEST 5: Dequeue (Seating High Priority First) ---\n");
    
    char* seated;
    int count = 1;

    while ((seated = dequeue(weddingQ)) != NULL) {
        printf("Seat #%d takes the table: %s\n", count++, seated);
        free(seated); 
    }

    printf("\n--- TEST 6: Empty Queue Handling ---\n");
    char* emptyCheck = dequeue(weddingQ);
    if (emptyCheck == NULL) {
        printf("[PASS] Handled empty queue correctly (returned NULL).\n");
    } else {
        printf("[FAIL] Queue should be empty but returned something.\n");
    }

    return 0;
}


PriorityQueue* initialize() {
	
	PriorityQueue *ptr = malloc(sizeof(PriorityQueue));
	ptr->front = NULL;
	

    return ptr; 
}

void enqueue(PriorityQueue* pq, char* name, char* role) {
    

    
    Node *newNode = malloc(sizeof(Node));
    strcpy(newNode->name,name);
    strcpy(newNode->role,role);
    newNode->next = NULL;
    
    if(strcmp(newNode->role,"Bride")== 0 || strcmp(newNode->role,"Groom")==0) {
    	newNode->priority = 100;
	} else if (strstr(newNode->role,"Family")!=NULL) {
		newNode->priority = 50;
	}else if (strstr(newNode->role,"VIP")!=NULL) {
		newNode->priority = 20;
	} else {
		newNode->priority = 1;
	}
    
   if(pq->front == NULL || pq->front->priority < newNode->priority){
   	
   	  newNode->next = pq->front;
   	  pq->front = newNode;
   } else {
   	
   	Node *trav = pq->front;
   	while(trav->next!=NULL && trav->next->priority >= newNode->priority) {
   	  trav = trav->next;		
		   }
		   newNode->next = trav->next;
		   trav->next = newNode;
	   }

}

char* dequeue(PriorityQueue* pq) {
    
    
    if(pq->front==NULL) {
    	return NULL;
	}
	Node *temp = pq->front;
	char *name = malloc(sizeof(pq->front->name));
	strcpy(name,pq->front->name);
	pq->front = pq->front->next;
	free(temp);
	
	return name;
    
    
    
    
    
    
}

bool isGuestInQueue(PriorityQueue* pq, char* targetName) {
    
    Node *trav = pq->front;
    while(trav!=NULL) {
    	if(strcmp(targetName,trav->name)==0) {
    		return 1;
		}
		trav = trav->next;
	}
    
    return false; // Placeholder
}

void findGuestsLike(PriorityQueue* pq, char* roleFragment) {
    
    Node *trav = pq->front;
    while(trav!=NULL) {
        if(strstr(trav->role,roleFragment)!=NULL) {
        printf("Name: %s (Priority: %d)\n",trav->name,trav->priority);
          
		}
		trav = trav->next;
    	
	}
}

void display(PriorityQueue* pq) {
    
    
    Node *trav = pq->front;
    while(trav!= NULL) {
    	printf("Guest Arrived: %s | Role: %s | Priority: %d\n",trav->name,trav->role,trav->priority);
		trav = trav->next;	
	}
}
