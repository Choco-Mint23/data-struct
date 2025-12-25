#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} List;

void initialize(List *L);
void insertPos(List *L, int data, int position);
void deletePos(List *L, int position);
int locate(List L, int data);
void insertSorted(List *L, int data);
void display(List L);

int main() {
    List L;

    initialize(&L);
    insertPos(&L, 1, 0);
    insertPos(&L, 3, 1);
    insertPos(&L, 4, 2);
    insertPos(&L, 5, 3);
    insertSorted(&L, 2);

    display(L);
    return 0;
}

void initialize(List *L) {
    L->count = 0;
}

void insertPos(List *L, int data, int position) {
    int i;
    if (position <= L->count && L->count < MAX) {
        for (i = L->count; i > position; i--) {
            L->elem[i] = L->elem[i - 1];
        }
        L->elem[position] = data;
        L->count++;
    }
}

void deletePos(List *L, int position) {
    int i;
    for (i = position; i < L->count - 1; i++) {
        L->elem[i] = L->elem[i + 1];
    }
    L->count--;
}

int locate(List L, int data) {

    int i;
    for (i = 0; i < L.count; i++) {
        if (L.elem[i] == data)
            return i;
    }
    return -1;
}

void insertSorted(List *L, int data) {
    int i;
    for (i = L->count - 1; i >= 0 && L->elem[i] > data; i--) {
        L->elem[i + 1] = L->elem[i];
    }
    L->elem[i + 1] = data;
    L->count++;
}

void display(List L) {
    int i;

    for (i = 0; i < L.count; i++) {
        printf("%d|", L.elem[i]);
    }
}
