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

// BuildMaxHeap function to build a max-heap from an unordered array
void BuildMaxHeap(int A[], int n) {
    // Build the max-heap by applying MaxHeapify from the last non-leaf node
    for (int i = n / 2 - 1; i >= 0; i--) {
        MaxHeapify(A, n, i);
    }
}

int main() {
    int A[] = {1, 12, 9, 5, 6, 10};
    int n = sizeof(A) / sizeof(A[0]);

    // Build the max-heap
    BuildMaxHeap(A, n);

    // Print the array after building the max-heap
    printf("Array after BuildMaxHeap: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
