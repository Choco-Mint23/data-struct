#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

typedef struct {
	int *elemPtr;
	int count;
	int max;
}List;

void initialize(List *L);
void insertPos(List *L, int data, int position);
void deletePos(List *L, int position);
int locate(List *L, int data);
int retrieve(List *L, int position);
void insertSorted(List *L, int data);
void display(List *L);
void resize(List *L);
void makeNULL(List *L);

int main() {
	
	List L;
	initialize(&L);
	insertPos(&L,5,0);
	insertPos(&L,4,1);
	insertPos(&L,51,2);
	insertPos(&L,62,3);
    insertSorted(&L,10);
	display(&L);

}
void initialize(List *L) {
	L->elemPtr = malloc(sizeof(int)*LENGTH);
    L->max = LENGTH;
    L->count = 0;
}
void insertPos(List *L, int data, int position) {
	
	int i;
	
	if (position>L->count) {
		printf("position is invalid!");
		return;
	} 
	
	if(L->count == L->max) {
		resize(L);
	} 
	
		for(i=L->count;i>position;i--) {
			L->elemPtr[i] = L->elemPtr[i-1];
		}
		L->elemPtr[position] = data;
		L->count++;
	}
	


void deletePos(List *L, int position) {
	
	int i;
	if(position>L->count) {
		printf("position is invalid!");
		return;
	}
	for(i=position;i<L->count;i++){
		L->elemPtr[i] = L->elemPtr[i+1];
	}
	L->count--;
}

int locate(List *L, int data) {
	int i;
	int index;
	for(i=0;i<L->count;i++) {
		if(L->elemPtr[i] == data){
			index = i;
		}
	}
	return index;
}
int retrieve(List *L, int position) {
	int i;
	int retVal = -1;
	if(position<=L->count) {
	 retVal = L->elemPtr[position];
	} else {
		printf("invalid position");
	}

	 return retVal;
}
void display(List *L) {
	int i;
	for(i=0;i<L->count;i++) {
	    printf("%d|",L->elemPtr[i]);
	}
	
}
void insertSorted(List *L, int data) {
	int i;
	if (L->count == L->max) {
		resize(L);
	}
	for(i=L->count-1;i>=0;i--) {
		if(L->elemPtr[i]>data) {
			L->elemPtr[i+1] = L->elemPtr[i];
		} else if (L->elemPtr[i]<data) {
			break;
		}
	}
	L->elemPtr[i+1] = data;
	L->count++;

}
void resize(List *L) {
	
	int newMax = L->max*2;
	int *newPtr = realloc(L->elemPtr,sizeof(int)*newMax);
	
	L->elemPtr = newPtr;
	L->max = newMax;
	
}
void makeNULL(List *L) {
	free(L->elemPtr);
	L->count =0;
	L->max =0;
}
