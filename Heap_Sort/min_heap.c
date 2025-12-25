#include <stdio.h>

void swap(int* a, int* b);
void heapifyMin(int arr[], int n, int i);
void heapSortDesc(int arr[], int n);



int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSortDesc(arr, n);

    printf("Sorted array (Descending): \n");
    for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyMin(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

void heapSortDesc(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapifyMin(arr, i, 0);
    }
}

