#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Selection Sort function
void SelectionSort(int a[], int n) {
    int i, j, min_index;
    for (i = 0; i < n - 1; i++) {
        // Find the index of the minimum element in the unsorted part
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min_index]) {
                min_index = j;
            }
        }
        // Swap the found minimum element with the first element of the unsorted part
        if (min_index != i) {
            swap(&a[i], &a[min_index]);
        }
    }
}

int main() {
    int a[] = {64, 34, 25, 12, 22, 11, 90}; // Example array
    int n = sizeof(a) / sizeof(a[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    SelectionSort(a, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
