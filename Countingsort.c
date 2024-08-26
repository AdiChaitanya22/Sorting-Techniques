#include <stdio.h>
#include <stdlib.h>

// Function to perform counting sort
void CountingSort(int arr[], int n) {
    // Find the maximum value in the array
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Create a count array and initialize all elements to 0
    int* count = (int*)calloc(max + 1, sizeof(int));
    if (count == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Store the count of each number
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Reconstruct the sorted array
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }

    // Free the count array
    free(count);
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    CountingSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
