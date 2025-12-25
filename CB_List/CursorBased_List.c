#include <stdio.h>

#define MAX 5     

typedef struct {
    int elem;
    int next;
} Cell, HeapSpace[MAX];

typedef struct {
    HeapSpace H;
    int avail;
} VHeap;

typedef int List;

void initialize(VHeap *V);
int allocSpace(VHeap *V);
void deallocSpace(VHeap *V, int index);

void insertFirst(List *L, VHeap *V, int elem);
void insertLast(List *L, VHeap *V, int elem);
void insertSorted(List *L, VHeap *V, int elem);

void deleteFirstOccurrence(List *L, VHeap *V, int elem);
void deleteAllOccurrence(List *L, VHeap *V, int elem);

void display(List L, VHeap V);

int main() {
    VHeap V;
    List L = -1;

    initialize(&V);

    insertSorted(&L, &V, 1);
    insertSorted(&L, &V, 0);
    insertSorted(&L, &V, 2);
    insertSorted(&L, &V, 3);
    insertSorted(&L, &V, 4);

    display(L, V);

    printf("\nAfter deleting all 2s:\n");
    deleteAllOccurrence(&L, &V, 2);
    display(L, V);

    return 0;
}

void initialize(VHeap *V) {
    int i;

    V->avail = 0;
    for (i = 0; i < MAX - 1; i++) {
        V->H[i].next = i + 1;
    }
    V->H[MAX - 1].next = -1;
}

int allocSpace(VHeap *V) {
    if (V->avail == -1) {
        return -1;   
    }

    int index = V->avail;
    V->avail = V->H[index].next;
    return index;
}

void deallocSpace(VHeap *V, int index) {
    V->H[index].next = V->avail;
    V->avail = index;
}

void insertFirst(List *L, VHeap *V, int elem) {
    int newcell = allocSpace(V);

    if (newcell != -1) {
        V->H[newcell].elem = elem;
        V->H[newcell].next = *L;
        *L = newcell;
    }
}

void insertLast(List *L, VHeap *V, int elem) {
    int newcell = allocSpace(V);

    if (newcell != -1) {
        V->H[newcell].elem = elem;
        V->H[newcell].next = -1;

        int *trav = L;
        while (*trav != -1) {
            trav = &V->H[*trav].next;
        }
        *trav = newcell;
    }
}

void insertSorted(List *L, VHeap *V, int elem) {
    int newcell = allocSpace(V);

    if (newcell != -1) {
        V->H[newcell].elem = elem;

        int *trav = L;
        while (*trav != -1 && V->H[*trav].elem < elem) {
            trav = &V->H[*trav].next;
        }

        V->H[newcell].next = *trav;
        *trav = newcell;
    }
}


void deleteFirstOccurrence(List *L, VHeap *V, int elem) {
    int *trav = L;
    int temp;

    while (*trav != -1 && V->H[*trav].elem != elem) {
        trav = &V->H[*trav].next;
    }

    if (*trav != -1) {
        temp = *trav;
        *trav = V->H[temp].next;
        deallocSpace(V, temp);
    }
}

void deleteAllOccurrence(List *L, VHeap *V, int elem) {
    int *trav = L;
    int temp;

    while (*trav != -1) {
        if (V->H[*trav].elem == elem) {
            temp = *trav;
            *trav = V->H[temp].next;
            deallocSpace(V, temp);
        } else {
            trav = &V->H[*trav].next;
        }
    }
}


void display(List L, VHeap V) {
    int i;

    for (i = L; i != -1; i = V.H[i].next) {
        printf("%d -> ", V.H[i].elem);
    }
    printf("NULL\n");
}

