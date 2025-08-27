#include <stdio.h>
#include <stdlib.h>

#define MAX 10 

typedef struct{
    int elem[MAX];
    int  count;
}List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position); 
int locate(List L, int data);   
List insertSorted(List L, int data);
void display(List L);

int main() {
    
    List L = initialize(L);
    L = insertPos(L,1,0);
    L = insertPos(L,3,1);
    L = insertPos(L,4,2);
    L = insertPos(L,5,3);
    L = insertSorted(L,2);
    
    display(L);
    
     if (locate(L,4)!=-1) {
         printf("\n%d is found in index %d",L.elem[locate(L,4)],locate(L,4));
     } else {
     	return -1;
	 }
    return 0;
}

void display(List L) {
     int i;
     for(i=0;i<=L.count-1;i++) {
         printf("%d|",L.elem[i]);
     }    
}
List initialize(List L) {
    
    L.count = 0;
    return L;
}
List insertPos(List L, int data, int position) {
     
     int i;
     if (position <= L.count && L.count < MAX) {
     for(i=L.count;i>position;i--) {
         L.elem[i]=L.elem[i-1];
     }    
     L.elem[position] = data;
     } 
     
    L.count++;
    return L; 
}
List deletePos(List L, int position) {
    int i;
    for(i=position;i<L.count-1;i++) {
        L.elem[i]=L.elem[i+1];
    }
    L.count--;
    return L;
}
int locate(List L, int data) {
	
    int i;
    int index = -1;

    for(i=0;i<L.count;i++) {
        if(data == L.elem[i]) {
            index = i;
			break;      
        }
    }
    return index;
}
List insertSorted(List L, int data) {

     int i;
     for(i=L.count-1;i>=0;i--) {
     	if(L.elem[i]>data) {
     		L.elem[i+1] = L.elem[i]; 
		 } else if (L.elem[i]<data) {
		 	break;
		 }
		 
	 }
	 L.elem[i+1] = data;
	 L.count++;
	 return L;
}
