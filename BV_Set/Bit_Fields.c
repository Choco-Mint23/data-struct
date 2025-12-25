#include <stdio.h>
#include <stdbool.h>

typedef struct {
	unsigned int field : 8;
}Set;


void insert(Set *set, int element);
void initialize(Set *set);
void deleteElem(Set *set, int element);
bool find(Set set, int element);
void display(unsigned char set);
Set intersection(Set A, Set B);
Set difference(Set A, Set B);
Set Union(Set A, Set B);


int main () {
	
	Set A;
	Set B;
	Set C;
	initialize(&A);
	initialize(&B);
	initialize(&C);
	
	insert(&A,0);
	insert(&A,4);
	insert(&A,5);
	
	insert(&B,2);
	insert(&B,5);
	

    
    C = difference(A,B);
    
    display(C.field);
    
    
		
	return 0;
}

void initialize(Set *set) {
   
   set->field = 0;
	
}


void insert(Set *set, int element){
	
	if(element<=8) {
		unsigned int mask = 1 << element ;
		
		set->field =  set->field | mask;
	} 
	
}

void deleteElem(Set *set, int element) {
	
	if( element<=8) {
		unsigned int mask = 1 << element  ;
		set->field = set->field & ~mask;
	}
}

bool find(Set set, int element) {
	
	unsigned int mask = 1 << element;
	
	set.field & mask;
	
	return set.field & mask;
}
Set Union(Set A, Set B) {
    
    Set result;
	result.field = A.field | B.field;
    
    return result;

}
Set intersection(Set A, Set B) {
	
	 Set result;
	result.field =  A.field & B.field;
	
   return result;
}

Set difference(Set A, Set B) {
	
    Set result;
	result.field = A.field & ~B.field;
	
  return result;
	
}

void display(unsigned char set) {
	
		int bits = sizeof(char)*8;
    int i=0;   
       unsigned int mask = 1;
       
       printf("{");
       while(mask!=0) {
       	if(set & mask) {
       		printf("%d, ",i);
		   }
		   i++;
       	mask = mask <<1;
	   }
	   printf("}");
}




