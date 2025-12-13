
#include <stdio.h>

#define MAX 4

typedef struct {
    int elem;
    int next;
}Cell, HeapSpace[MAX];

typedef struct {
    HeapSpace H;
    int avail;
}VHeap;

typedef int List;
int allocSpace(VHeap* V);
void initialize(VHeap *V);
void insertFirst(int* L, VHeap* V, int elem);
void display(int L, VHeap V);
void insertLast(int* L, VHeap* V, int elem);
void deleteFirst(int* L, VHeap* V, int elem);
void deallocSpace(VHeap* V, int index);
void insertSorted(int* L, VHeap* V, int elem);
void deleteAllOccurrence(int* L, VHeap* V, int elem);
int main () {
    

    VHeap V; 
    initialize(&V);
    List L = -1;
    
   
    insertSorted(&L,&V,1);
    insertSorted(&L,&V,0);
    insertSorted(&L,&V,2);
    insertSorted(&L,&V,3);
    deleteFirst(&L,&V,2);
  
    
    
    display(L,V);
    
    


  return 0;
}
void initialize(VHeap *V) {
    int i;
    
    V->avail = 0;
    for(i=0;i<MAX-1;i++) {
        V->H[i].next = i+1;
    }
    V->H[MAX-1].next = -1;
    
}
int allocSpace(VHeap* V) {
    
    int index = V->avail;
    
    V->avail = V->H[V->avail].next;
    
    return index; 
    
}
void insertFirst(int* L, VHeap* V, int elem) {
    
    int newcell = allocSpace(V);
    if(newcell!=-1) {
        V->H[newcell].elem = elem;
        V->H[newcell].next = *L;
        *L = newcell;
    }
}
 
 void insertLast(int* L, VHeap* V, int elem) {
     int newcell = allocSpace(V); 
     if(newcell!=-1) {
         V->H[newcell].elem = elem;
         V->H[newcell].next = -1;
         int *trav = L;
         while(*trav!=-1) {
             trav = &V->H[*trav].next;
         }
         *trav = newcell;
     }
 } 

void display(int L, VHeap V) {
    
    int i;
   for(i=L;i!=-1;i=V.H[i].next) {
       printf("%d -> ",V.H[i].elem);
   }
}
void deleteFirst(int* L, VHeap* V, int elem) {
    
    int *trav;
    int temp;
    
    trav = L;
    while(*trav!=-1 && V->H[*trav].elem!=elem) {
        trav = &V->H[*trav].next;
    }
    if(*trav!=-1) {
        temp = *trav;
        *trav = V->H[*trav].next;
        deallocSpace(V,temp);
    }
}

void deallocSpace(VHeap* V, int index) {
    V->H[index].next = V->avail;
    V->avail = index;
    
}

void insertSorted(int* L, VHeap* V, int elem) {
	
	int i;
	int j;
	int newcell = allocSpace(V);
	if(newcell!=-1) {
		V->H[newcell].elem = elem;
		
		if(*L==-1 || elem <V->H[*L].elem) {
			V->H[newcell].next = *L;
			*L = newcell;
			
		} else   {
			int *trav = L;
			while(*trav!=-1 && V->H[*trav].elem < elem) {
				trav = &V->H[*trav].next;
			}
		 
			V->H[newcell].next = *trav;
			*trav = newcell;
		} 
		
	}
}
void deleteAllOccurrence(int* L, VHeap* V, int elem) {
	
	int *trav;
	int temp;
	
	trav = L;
	
	while(*trav!=-1) {
		if(V->H[*trav].elem==elem) {
			temp = *trav;
			*trav = V->H[*trav].next;
			deallocSpace(V,temp);
		}
		trav = &V->H[*trav].next;
		
	}
	 
}
