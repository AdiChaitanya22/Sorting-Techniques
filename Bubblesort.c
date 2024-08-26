#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort function
void BubbleSort(int a[], int n) {
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0; // Reset swapped flag
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]); // Swap if elements are out of order
                swapped = 1; // Set swapped flag
            }
        }
        // If no elements were swapped, the array is already sorted
        if (swapped == 0)
            break;
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

    BubbleSort(a, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
