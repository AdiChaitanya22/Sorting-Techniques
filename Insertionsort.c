#include <stdio.h>

void Insertion_sort(int A[], int n) {
    int i, j, Key;
    for (j = 1; j < n; j++) {
        Key = A[j];
        // Insert A[j] into the sorted sequence A[0...j-1]
        i = j - 1;
        while (i >= 0 && A[i] > Key) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = Key;
    }
}

int main() {
    int A[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(A) / sizeof(A[0]);

    // Sort the array
    Insertion_sort(A, n);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
