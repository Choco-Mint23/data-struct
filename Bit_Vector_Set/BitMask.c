#include <stdio.h>
#include <stdbool.h>

void initialize(unsigned char *set);
void insert(unsigned char *set, int element);
void delete(unsigned char *set, int element);
bool find(unsigned char set, int element);
unsigned char Union(unsigned char A, unsigned char B);
unsigned char intersection(unsigned char A, unsigned char B);
unsigned char difference(unsigned char A, unsigned char B);
void display(unsigned char set);



int main() {
    
    unsigned char A;
    unsigned char B;
    unsigned char C;
    initialize(&A);
    
    insert(&A,1);
    insert(&A,6);
  
    
    display(A);
    
    return 0;
}
void initialize(unsigned char *set) {
    
     *set = 0;
    
}
void insert(unsigned char *set, int element) {
    
    if(element >= 0 && element < 8) {
        
    unsigned int mask = 1 << element;
   
   *set |= mask;
    }
   
}

void delete(unsigned char *set, int element) {
    
    if(element >= 0 && element < 8) {
        
      unsigned int mask = 1 << element;
   *set &= ~mask;  
   
    }
    
}
bool find(unsigned char set, int element) {
    
    if(element >= 0 && element < 8) {
         unsigned int mask = 1 << element;
    set & mask;
    }
   
   
}
unsigned char Union(unsigned char A, unsigned char B) {
    
    return A | B;
    
}
unsigned char intersection(unsigned char A, unsigned char B) {
    
    return A & B;
      
}
unsigned char difference(unsigned char A, unsigned char B) {
    
    return A&~B;
    
}
void display(unsigned char set) {
 
int i = 0;
unsigned int mask = 1;
printf("{");
while(mask!=0) {
    if(set & mask){
        printf("%d,",i);
    }
    i++;
    mask = mask << 1;
    }
    printf("}");
}
