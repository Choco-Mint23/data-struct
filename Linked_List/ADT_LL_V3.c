#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int *elem;
    int count;
} List;

List initialize(List L);
List insertPos(List L, int data, int position);
void display(List L);

int main() {
    List L = initialize(L);

    L = insertPos(L, 1, 0);
    L = insertPos(L, 2, 1);
    L = insertPos(L, 3, 2);
    L = insertPos(L, 4, 3);
    L = insertPos(L, 5, 4);

    display(L);
    free(L.elem);
    return 0;
}

List initialize(List L) {
    L.elem = (int *)malloc(MAX * sizeof(int));
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position) {
    int i;
    if (position <= L.count && L.count < MAX) {
        for (i = L.count; i > position; i--) {
            L.elem[i] = L.elem[i - 1];
        }
        L.elem[position] = data;
        L.count++;
    }
    return L;
}

void display(List L) {
    int i;
    for (i = 0; i < L.count; i++) {
        printf("%d|", L.elem[i]);
    }
}
