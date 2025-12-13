#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void heapify(char *arr[], int n, int i) {
    int largest = i;           // Initialize largest as root
    int left = 2 * i + 1;      // left child index
    int right = 2 * i + 2;     // right child index

    // If left child is larger (alphabetically)
    if (left < n && strcmp(arr[left], arr[largest]) > 0)
        largest = left;

    // If right child is larger (alphabetically)
    if (right < n && strcmp(arr[right], arr[largest]) > 0)
        largest = right;

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        char *temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(char *arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
    	heapify(arr, n, i);
	}
    
    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root (max) to end
        char *temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call heapify on reduced heap
        heapify(arr, i, 0);
    }
}

void printArray(char *arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

int main() {
    char *arr[] = {"Charlie", "Alice", "Bob", "Eve", "David", "Frank"};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array of names: ");
    printArray(arr, n);

    // Perform Heap Sort (sorts alphabetically A-Z)
    heapSort(arr, n);

    printf("Sorted array of names:   ");
    printArray(arr, n);

    return 0;
}
