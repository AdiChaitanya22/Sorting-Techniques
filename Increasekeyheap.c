#include <stdio.h>


// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// HeapIncreaseKey function to increase the value of a key in the heap
void HeapIncreaseKey(int A[], int i, int key) {
    if (key < A[i]) {
        printf("Error: New key is smaller than the current key\n");
        return;
    }
    A[i] = key;
    // Move the new key up the heap until the max-heap property is restored
    while (i > 0 && A[(i - 1) / 2] < A[i]) {
        swap(&A[i], &A[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int main() {
    // Example usage
    int A[] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1}; // An example max-heap
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original heap: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Increase key at index 8 to 15
    HeapIncreaseKey(A, 8, 15);

    printf("Heap after increasing key at index 8 to 15: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
