#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // Required for boolean return types

// --- STRUCT DEFINITIONS ---

typedef struct node {
    char name[50];
    char role[50];  // Stores "Bride", "Groom", "Family", etc.
    int priority;   // Calculated based on role
    struct node* next;
} Node;

typedef struct {
    Node* front;
} PriorityQueue;

// --- FUNCTION PROTOTYPES ---

PriorityQueue* initialize();
void enqueue(PriorityQueue* pq, char* name, char* role);
char* dequeue(PriorityQueue* pq);
bool isGuestInQueue(PriorityQueue* pq, char* targetName);
void findGuestsLike(PriorityQueue* pq, char* roleFragment);
void display(PriorityQueue* pq);

// --- MAIN FUNCTION (TESTING) ---

int main() {
    // TEST 1: INITIALIZATION
    printf("--- TEST 1: Initialization ---\n");
    PriorityQueue* weddingQ = initialize();
    if (weddingQ != NULL && weddingQ->front == NULL) {
        printf("[PASS] Queue initialized successfully.\n");
    } else {
        printf("[FAIL] Queue initialization error.\n");
    }

    // TEST 2: ENQUEUE (Logic Check: Does it sort automatically?)
    printf("\n--- TEST 2: Enqueue (Checking Priority Logic) ---\n");
    // We insert them in RANDOM order. The code must sort them.
    // Expected Priority: Regular(1), VIP(20), Family(50), Groom(100)
    
    enqueue(weddingQ, "John Doe", "Regular Guest");       // Prio 1
    enqueue(weddingQ, "Auntie Julie", "Mother of Family"); // Prio 50 (strstr "Family")
    enqueue(weddingQ, "Mayor Tom", "VIP Sponsor");        // Prio 20 (strstr "VIP")
    enqueue(weddingQ, "Kevin Tan", "Groom");              // Prio 100 (strcmp "Groom")
    enqueue(weddingQ, "Jane Smith", "Regular Guest");     // Prio 1

    display(weddingQ); 
    // EXPECTED ORDER in Display: Kevin -> Auntie Julie -> Mayor Tom -> John -> Jane

    // TEST 3: BOOLEAN SEARCH (strcmp)
    printf("\n--- TEST 3: Check Specific Guest (isGuestInQueue) ---\n");
    
    // Case A: Guest exists
    if (isGuestInQueue(weddingQ, "Kevin Tan") == true) {
        printf("[PASS] Found 'Kevin Tan'.\n");
    } else {
        printf("[FAIL] Could not find 'Kevin Tan'.\n");
    }

    // Case B: Guest does not exist
    if (isGuestInQueue(weddingQ, "Harry Potter") == false) {
        printf("[PASS] Correctly did not find 'Harry Potter'.\n");
    } else {
        printf("[FAIL] False positive found for 'Harry Potter'.\n");
    }

    // TEST 4: SUBSTRING SEARCH (strstr)
    printf("\n--- TEST 4: Find Guests by Role Fragment (findGuestsLike) ---\n");
    printf("Searching for 'Guest'...\n");
    findGuestsLike(weddingQ, "Guest"); 
    // Should find John Doe and Jane Smith

    // TEST 5: DEQUEUE (Seating Order)
    printf("\n--- TEST 5: Dequeue (Seating High Priority First) ---\n");
    
    char* seated;
    int count = 1;

    // We loop until the queue is empty to test the full sequence
    while ((seated = dequeue(weddingQ)) != NULL) {
        printf("Seat #%d takes the table: %s\n", count++, seated);
        free(seated); // CRITICAL: Free the memory allocated in dequeue
    }

    // TEST 6: EMPTY QUEUE HANDLING
    printf("\n--- TEST 6: Empty Queue Handling ---\n");
    char* emptyCheck = dequeue(weddingQ);
    if (emptyCheck == NULL) {
        printf("[PASS] Handled empty queue correctly (returned NULL).\n");
    } else {
        printf("[FAIL] Queue should be empty but returned something.\n");
    }

    return 0;
}

// --- IMPLEMENT YOUR FUNCTIONS BELOW ---

// 1. Initialize the queue
PriorityQueue* initialize() {
	
	PriorityQueue *ptr = malloc(sizeof(PriorityQueue));
	ptr->front = NULL;
	
    // TODO: Allocate memory for PriorityQueue
    // TODO: Set front to NULL
    // TODO: Return the pointer
    return ptr; // Placeholder
}

// 2. Add guest (Sorted Insert)
void enqueue(PriorityQueue* pq, char* name, char* role) {
    // TODO: Allocate memory for newNode
    // TODO: strcpy name and role
    
    // TODO: Calculate Priority
    // If role is "Bride" or "Groom" (strcmp) -> 100
    // If role contains "Family" (strstr) -> 50
    // If role contains "VIP" (strstr) -> 20
    // Else -> 1

    // TODO: Insert into list based on priority (Head insert OR Traversal)
    
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

// 3. Remove highest priority guest
char* dequeue(PriorityQueue* pq) {
    // TODO: Check if empty
    // TODO: Save name to a new char* buffer (malloc) using strcpy
    // TODO: Move front pointer
    // TODO: Free the old node
    // TODO: Return the saved name
    
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

// 4. Check if exact name exists
bool isGuestInQueue(PriorityQueue* pq, char* targetName) {
    // TODO: Loop through list
    // TODO: Use strcmp to compare names
    // TODO: Return true if found, false otherwise
    
    
    Node *trav = pq->front;
    while(trav!=NULL) {
    	if(strcmp(targetName,trav->name)==0) {
    		return 1;
		}
		trav = trav->next;
	}
    
    return false; // Placeholder
}

// 5. Find guests with partial role match
void findGuestsLike(PriorityQueue* pq, char* roleFragment) {
    // TODO: Loop through list
    // TODO: Use strstr to see if roleFragment is inside temp->role
    // TODO: Print details if match found
    Node *trav = pq->front;
    while(trav!=NULL) {
        if(strstr(trav->role,roleFragment)!=NULL) {
        printf("Name: %s (Priority: %d)\n",trav->name,trav->priority);
          
		}
		trav = trav->next;
    	
	}
}

// 6. Print the whole list
void display(PriorityQueue* pq) {
    // TODO: Loop through list
    // TODO: Print Name, Role, and Priority
    
    Node *trav = pq->front;
    while(trav!= NULL) {
    	printf("Guest Arrived: %s | Role: %s | Priority: %d\n",trav->name,trav->role,trav->priority);
		trav = trav->next;	
	}
}
