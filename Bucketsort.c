#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform insertion sort on a bucket
void InsertionSort(float arr[], int n) {
    int i;
    float key;
    int j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to perform bucket sort
void BucketSort(float arr[], int n) {
    // Create buckets
    int bucketCount = 10; // Number of buckets
    int i, j;
    int bucketSize = n / bucketCount + 1; // Size of each bucket

    // Create an array of buckets
    float** buckets = (float**)malloc(bucketCount * sizeof(float*));
    int* bucketSizes = (int*)malloc(bucketCount * sizeof(int));
    for (i = 0; i < bucketCount; i++) {
        buckets[i] = (float*)malloc(bucketSize * sizeof(float));
        bucketSizes[i] = 0;
    }

    // Distribute elements into buckets
    for (i = 0; i < n; i++) {
        int bucketIndex = (int)(arr[i] * bucketCount); // Determine bucket index
        if (bucketIndex >= bucketCount) {
            bucketIndex = bucketCount - 1; // Ensure index is within bounds
        }
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    // Sort each bucket and concatenate results
    int index = 0;
    for (i = 0; i < bucketCount; i++) {
        if (bucketSizes[i] > 0) {
            InsertionSort(buckets[i], bucketSizes[i]);
            for (j = 0; j < bucketSizes[i]; j++) {
                arr[index++] = buckets[i][j];
            }
        }
        free(buckets[i]); // Free memory for each bucket
    }
    free(buckets); // Free memory for bucket array
    free(bucketSizes); // Free memory for bucket sizes array
}

int main() {
    float arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");

    BucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");

    return 0;
}
