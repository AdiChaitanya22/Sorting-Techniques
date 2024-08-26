#include <stdio.h>
#include <stdlib.h>  // For malloc and free

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

// HeapSort function to sort an array using heap sort
void HeapSort(int A[], int n) {
    BuildMaxHeap(A, n); // Build a max-heap

    for (int i = n - 1; i >= 1; i--) {
        // Swap the root of the heap (maximum value) with the last element
        swap(&A[0], &A[i]);

        // Reduce the size of the heap and maintain the max-heap property
        MaxHeapify(A, i, 0);
    }
}

int main() {
    int A[] = {4, 10, 3, 5, 1};  // Example array
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    HeapSort(A, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
