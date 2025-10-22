#include <stdio.h>
#include <stdbool.h>

void display(unsigned char set);
void initialize(unsigned char *set);
void insert(unsigned char *set, int element);
void deleteElem(unsigned char *set, int element);
bool find(unsigned char set, int element);
unsigned char Union(unsigned char A, unsigned char B);
unsigned char intersection(unsigned char A, unsigned char B);
unsigned char difference(unsigned char A, unsigned char B);
int main() {
	
	unsigned char A;
	unsigned char B;
	unsigned char C;
	
	initialize(&A);
	insert(&A,1);
    insert(&A,6);
    
    initialize(&B);
    insert(&B,3);
    insert(&B,6);
    insert(&B,7);
    
    initialize(&C);
    
    C = Union(A,B);
    
	display(C);
	
	return 0;
}
void initialize(unsigned char *set) {
	
	*set = 0;
}

void insert(unsigned char *set, int element) {
	
	if(element <=8) {

	unsigned int mask = 1 << (element-1);
	  *set = *set | mask;
	  
	}
}

void deleteElem(unsigned char *set, int element) {
	
		if(element>0 && element <=7) {
		unsigned int mask = 1 << (element-1);
	    
		*set = *set& ~mask; //~mask is flipping the mask so if mask 101 then ~mask is 010
			
		}
}

unsigned char Union(unsigned char A, unsigned char B) {
	
	return A | B;
}

unsigned char intersection(unsigned char A, unsigned char B) {
	
	return A & B;
}

bool find(unsigned char set, int element) {
	
	
	unsigned int mask = 1 << (element-1);
	
	set & mask;
}

unsigned char difference(unsigned char A, unsigned char B) {
	
	return A & ~B;
}

void display(unsigned char set) {
	
	int bits = sizeof(char)*8;
    int i=1;   
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
