#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
	int elem[MAX];
	int count;
}Etype, *EPtr;

void initialize(EPtr L);
void insertPos(EPtr L, int data, int position);
void display(EPtr L);
void deletePos(EPtr L, int position);
int locate(EPtr L, int data);
int retrieve(EPtr L, int position);
void insertSorted(EPtr L, int data);
void makeNULL(EPtr L);
int main() {
	
	
	EPtr L = malloc(sizeof( Etype));
	initialize(L);
    insertPos(L,1,0);
    insertPos(L,2,1);
    insertPos(L,4,2);
    insertPos(L,5,3);
    insertSorted(L,3);
    display(L);
    makeNULL(L);
    
	
	return 0;
}
void initialize(EPtr L) { 
    
    L->count = 0;
}
void insertPos(EPtr L, int data, int position) {
	
	int i;
	if(position <= L->count && L->count < MAX) {
		for(i=L->count;i>position;i--) {
			L->elem[i] = L->elem[i-1];
		}	
		L->elem[position] = data;
	}
		L->count++;
}
void deletePos(EPtr L, int position) {
	
	int i;
	if(position <= L->count && L->count < MAX) {
		for(i=position;i<L->count;i++) {
			L->elem[i] = L->elem[i+1];
		}	
	}
		L->count--;
}

int locate(EPtr L, int data) {
	
	int i;
	int location = -1;
	for(i=0;i<L->count;i++) {
		if(L->elem[i]== data) {
			location = i;
		}
	}
	return location;
	
}

int retrieve(EPtr L, int position) {
	
	
	int retVal = -1;
	if(position <= L->count) {
	  retVal = L->elem[position];	
	}
	
	
	return retVal;
}

void insertSorted(EPtr L, int data) {
	
	int i;
	for(i=L->count-1;i>=0;i--) {
	  if(L->elem[i]>data) {
	  	L->elem[i+1] = L->elem[i];
	  } else if (L->elem[i]<data) {
	  	break;
	  }
	  
	}
	L->elem[i+1] = data;
	L->count++;
	
}

void makeNULL(EPtr L) {
	
	free(L);


}
	
void display(EPtr L) {
	int i;
	for(i=0;i<L->count;i++) {
		printf("%d|",L->elem[i]);
	}
}
