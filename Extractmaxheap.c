#include <stdio.h>
#include <stdlib.h>  // For malloc and free
#include <limits.h>  // For INT_MIN

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

// Structure to represent a max heap
struct MaxHeap {
    int *array;
    int heap_size;
    int capacity;
};

// Function to initialize a max heap
struct MaxHeap createMaxHeap(int capacity) {
    struct MaxHeap heap;
    heap.heap_size = 0;
    heap.capacity = capacity;
    heap.array = (int *)malloc(capacity * sizeof(int)); // Allocate memory for the heap
    return heap;
}

// Function to extract the maximum element from the heap
int ExtractMax(struct MaxHeap *heap) {
    if (heap->heap_size < 1) {
        printf("Heap underflow\n");
        return INT_MIN; // Return a minimum value to indicate underflow
    }

    int max = heap->array[0];
    heap->array[0] = heap->array[heap->heap_size - 1];
    heap->heap_size--;
    MaxHeapify(heap->array, heap->heap_size, 0);
    return max;
}

int main() {
    // Example usage of the heap and extract max function
    struct MaxHeap heap = createMaxHeap(10);

    // Assuming the heap is already built (you can add a BuildMaxHeap function)
    heap.array[0] = 12;
    heap.array[1] = 7;
    heap.array[2] = 10;
    heap.array[3] = 5;
    heap.array[4] = 6;
    heap.heap_size = 5; // Manually setting heap size

    // Extract the maximum element
    int max = ExtractMax(&heap);
    if (max != INT_MIN) {
        printf("The maximum element is: %d\n", max);
    }

    // Print the heap after extraction
    printf("Heap after extracting max: ");
    for (int i = 0; i < heap.heap_size; i++) {
        printf("%d ", heap.array[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(heap.array);

    return 0;
}
