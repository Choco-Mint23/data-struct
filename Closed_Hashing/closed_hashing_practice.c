#include <stdio.h>
#include <stdlib.h>

#define SIZE 10


int hashTable[SIZE]; 

void init();
void insert(int key);
void search(int key);
void display();


int main() {
    init();

    insert(10);
    insert(21); 
    insert(30);
    insert(42); 
    
    display();

    printf("\n--- Search Results ---\n");
    search(30);
    search(99);

    return 0;
}


void init() {
    int i; 
    
    for(i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
}

void insert(int key) {
    int index = key % SIZE; 
    
    
    while(hashTable[index] != -1) {
        printf("Collision at index %d for key %d. Probing to next index\n", index, key);
        index = (index + 1) % SIZE; 
    }

    hashTable[index] = key;
    printf("Inserted %d at Index %d\n", key, index);
}

void search(int key) {
    int index = key % SIZE; 
    int start = index; 

    while(hashTable[index] != -1) {
        if(hashTable[index] == key) {
            printf("Found %d at Index %d\n", key, index);
            return;
        }
        
        index = (index + 1) % SIZE;

        if(index == start) break; 
    }
    
    printf("Number %d not found.\n", key);
}

void display() {
    int i; 
    
    printf("\n--- Hash Table Contents ---\n");
    for(i = 0; i < SIZE; i++) {
        printf("Index [%d]: ", i);
        
        if(hashTable[i] == -1) {
            printf("Empty\n");
        } else {
            printf("%d\n", hashTable[i]);
        }
    }
}
