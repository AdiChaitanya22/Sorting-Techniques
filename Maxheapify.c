#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// MaxHeapify function to maintain the max-heap property
void MaxHeapify(int A[], int n, int i) {
    int largest = i;         // Initialize largest as root
    int l = 2 * i + 1;       // Left child index
    int r = 2 * i + 2;       // Right child index

    // If left child is larger than root
    if (l < n && A[l] > A[largest])
        largest = l;

    // If right child is larger than the largest so far
    if (r < n && A[r] > A[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(&A[i], &A[largest]);  // Swap root with largest
        MaxHeapify(A, n, largest); // Recursively heapify the affected subtree
    }
}

int main() {
    int A[] = {1, 12, 9, 5, 6, 10};
    int n = sizeof(A) / sizeof(A[0]);

    // Applying MaxHeapify on the first non-leaf node (index 2)
    MaxHeapify(A, n, 0);

    // Print the array after MaxHeapify
    printf("Array after MaxHeapify: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
