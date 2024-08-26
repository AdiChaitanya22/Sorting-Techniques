#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function that partitions the array and returns the pivot index
int Partition(int A[], int p, int r) {
    int x = A[r];  // Pivot element
    int i = p - 1; // Index of the smaller element

    for (int j = p; j <= r - 1; j++) {
        if (A[j] <= x) {
            i++;
            swap(&A[i], &A[j]); // Swap A[i] and A[j]
        }
    }
    swap(&A[i + 1], &A[r]); // Place the pivot element in the correct position
    return i + 1;
}

// Quicksort function that sorts the array
void Quicksort(int A[], int p, int r) {
    if (p < r) {
        int q = Partition(A, p, r); // Partition the array and get the pivot index
        Quicksort(A, p, q - 1);      // Recursively sort the elements before the pivot
        Quicksort(A, q + 1, r);      // Recursively sort the elements after the pivot
    }
}

int main() {
    int A[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(A) / sizeof(A[0]);

    // Perform the quicksort
    Quicksort(A, 0, n - 1);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
