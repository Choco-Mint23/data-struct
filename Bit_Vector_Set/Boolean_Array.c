#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 8

typedef bool Set[ARRAY_SIZE];

void initialize(Set set);
void insert(Set set, int element);
void deleteElem(Set set, int element);
bool find(Set set, int element);
void Union(Set A, Set B, Set C);
void intersection(Set A, Set B, Set C);
void difference(Set A, Set B, Set C);
void display(Set set);

int main() {
	
	Set A;
	Set B;
	Set C;
	initialize(A);
	initialize(B);
	initialize(C);
	
	insert(A,0);
	insert(A,2);
	insert(A,7);
	
	insert(B,2);
	insert(B,4);
	insert(B,5);
	
	difference(A,B,C);
	display(C);
	
	
}

void initialize(Set set) {
	
	int i;
	for(i=0;i<=ARRAY_SIZE-1;i++) {
		set[i] = 0;
	}
}

void insert(Set set, int element) {
	
	if(element<=8) {
		
		set[element] = 1;
		
	}
}
void deleteElem(Set set, int element) {
	
	if(element<=8) {
		
		set[element] = 0;
	}
	
}

bool find(Set set, int element) {
	
	if(element<=8) {
		
		return set[element];
	}
}
void Union(Set A, Set B, Set C) {
	
	int i;
	for(i=0;i<=ARRAY_SIZE-1;i++) {
		
		C[i] = A[i] | B[i];
	}
}
void intersection(Set A, Set B, Set C) {
	
	int i;
	for(i=0;i<=ARRAY_SIZE-1;i++) {
		
		C[i] = A[i] & B[i];
	}
}

void difference(Set A, Set B, Set C) {
	
		int i;
	for(i=0;i<=ARRAY_SIZE-1;i++) {
		
		C[i] = A[i] & ~B[i];
	}
	
}

void display(Set set) {
	
	int i;
	   
	   printf("{");
	for(i=0;i<=ARRAY_SIZE-1;i++) {
		if(set[i]) {
			printf("%d, ",i);
		}
	}
	
	   printf("}");
}
