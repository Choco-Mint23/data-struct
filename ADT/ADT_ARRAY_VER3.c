#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

typedef struct{
	int *elemPtr;
	int count;
	int max;
}List;

List initialize(List L);
List insertPos(List L, int data, int position);
List resize(List L);
void display(List L);
List deletePos(List L, int position);
int locate (List L, int data);
List  insertSorted(List L, int data);
int main() {
	
	List L;
	L = initialize(L);
	L = insertPos(L,2,0);
	L = insertPos(L,3,1);
	L = insertPos(L,74,2);
	L = insertPos(L,100,3);
	L = insertSorted(L,82);
	display(L);
    
	printf("\n%d is at index %d",74,locate(L,74));

}
List initialize(List L) {
	
	L.elemPtr= malloc(sizeof(int)*LENGTH);
	L.max = LENGTH;
	L.count = 0;
	
	return L;
}
List insertPos(List L, int data, int position) {
	
	int i;
	
	if(position>L.count ) {
		printf("invalid position");
	}
	 if(L.count == L.max) {
	 	resize(L);
		 }
		 	
		 
		for(i=L.count;i>position;i--) {
			L.elemPtr[i] = L.elemPtr[i-1];
		 }
		 L.elemPtr[position] = data; 
		L.count++;
		
	return L;
}
List deletePos(List L, int position) {
	int i;
	if(position>L.count) {
			printf("invalid position");
	} else {
		for(i=position;i<L.count;i++) {
			 L.elemPtr[i] = L.elemPtr[i+1];
		}
			L.count--;
		}
	
			return L;
	}
	
List  insertSorted(List L, int data) {
	int i;
	if(L.count == L.max) {
		resize(L);
	} else {

		for(i=L.count-1;i>=0;i--) {
			if( L.elemPtr[i] > data ) {
				L.elemPtr[i+1] = L.elemPtr[i];
			} else if(L.elemPtr[i]<data) {
				break;
			}
		}
		L.elemPtr[i+1] = data;
		L.count++;
	}
       return L;

}	

int locate (List L, int data) {

	int i;
	int index = -1;
	for(i=0;i<L.count;i++) {
		if(L.elemPtr[i] == data) {
           index = i;
		}
	}
	return index;
}

List resize(List L) {
	
	int newMax= L.max*2;
	int *newPtr = realloc(L.elemPtr,sizeof(int)*newMax);
	
	L.elemPtr = newPtr;
	L.max = newMax;
	
	return L;
}

void display(List L) {
	int i;
	for(i=0;i<L.count;i++) {
		printf("%d|", L.elemPtr[i]);
	}
}
