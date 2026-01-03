#include <stdio.h>
#include <stdlib.h>


#define SIZE 10


struct Node {
    int data;
    struct Node* next;
};

struct Node* hashTable[SIZE]; 


void init();
void insert(int key);
void search(int key);  
void display();


int main() {
    init();

    
    insert(10);
    insert(20);
    insert(42);
    insert(15);
    insert(25);
    insert(30);

    display();

    
    printf("\n--- Search Results ---\n");
    search(25);  
    search(99);  

    return 0;
}


void init() {
	int i;
    for(i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }
}

void insert(int key) {
    int index = key % 10; 

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    
    
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

void search(int key) {
    int index = key % SIZE; 
    struct Node* temp = hashTable[index];
    
    
    while(temp != NULL) {
        if(temp->data == key) {
            printf("Found %d at Index %d\n", key, index);
            return; 
        }
        temp = temp->next;
    }
    
    
    printf("Number %d not found in the table.\n", key);
}

void display() {
    printf("\n--- Hash Table ---\n");
    int i;
    for(i = 0; i < SIZE; i++) {
        
        if(hashTable[i] != NULL) {
             printf("Index [%d]: ", i);
             struct Node* temp = hashTable[i];
             while(temp != NULL) {
                 printf("%d -> ", temp->data);
                 temp = temp->next;
             }
             printf("NULL\n");
        }
    }
}
