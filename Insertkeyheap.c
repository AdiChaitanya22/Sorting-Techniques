#include <stdio.h>
#include <stdlib.h>  // For malloc and free

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the max-heap property
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

// Function to insert a new key into the max-heap
void InsertKey(int A[], int *heap_size, int capacity, int key) {
    if (*heap_size >= capacity) {
        printf("Error: Heap is full\n");
        return;
    }

    // Insert the new key at the end of the heap
    (*heap_size)++;
    int i = *heap_size - 1;
    A[i] = key;

    // Restore the max-heap property
    while (i > 0 && A[(i - 1) / 2] < A[i]) {
        swap(&A[i], &A[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int main() {
    int capacity = 10;  // Maximum number of elements in the heap
    int *A = (int *)malloc(capacity * sizeof(int)); // Allocate memory for the heap
    int heap_size = 0;  // Current size of the heap

    // Example initial heap
    int initial_values[] = {16, 14, 10, 8, 7, 9};
    heap_size = sizeof(initial_values) / sizeof(initial_values[0]);
    for (int i = 0; i < heap_size; i++) {
        A[i] = initial_values[i];
    }

    // Print initial heap
    printf("Initial heap: ");
    for (int i = 0; i < heap_size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Insert a new key
    int new_key = 20;
    InsertKey(A, &heap_size, capacity, new_key);

    // Print the heap after insertion
    printf("Heap after inserting %d: ", new_key);
    for (int i = 0; i < heap_size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(A);

    return 0;
}
