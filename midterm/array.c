#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int set[MAX];
    int size;
} Set;


void insertToSet(Set *S, int data);
void deleteFromSet(Set *S, int data);
void populateSet(Set *S);
void printSet(Set S);
Set Union(Set A, Set B);
Set Intersection(Set A, Set B);
Set Difference(Set A, Set B);

int main () {
	
	Set A = {{},0};
	Set B = {{},0};
	
	
	return 0;
	
}
void insertToSet(Set *S, int data) {
	
	int i;
	if(S->size<MAX) {
		
		for(i=0;i<S->size && S->set[i]!=data;i++) { //cant have duplicates in set
		S->set[i] = data;

	}
	if(i==S->size) {
		S->set[S->size++] = data;
	}
		
	}
	
}

void deleteFromSet(Set *S, int data) {
	

    if(S->size > 0) {
        int i;

        for(i = 0; i < S->size && S->set[i] != data; i++) {} //go to i = index where data is found

        if(i < S->size) {
            S->size--;

            if(S->size > 0) {
                S->set[i] = S->set[S->size]; //doesnt matter if dile in "order" ang set kay this doesnt matter in SETS 
                
            }
        }
    }
}



















void deleteFromSet(Set *S, int data) {
	

    if(S->size > 0) {
        int i;

        for(i = 0; i < S->size && S->set[i] != data; i++) {} //go to i = index where data is found

        
            S->size--;

            if(S->size > 0) {
                S->set[i] = S->set[S->size]; //doesnt matter if dile in "order" ang set kay this doesnt matter in SETS 
                
            }
        
    }
}
