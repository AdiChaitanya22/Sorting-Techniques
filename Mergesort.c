#include <stdio.h>
#include <limits.h>  // For INT_MAX

// Merge function as defined earlier
void Merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    // Create temporary arrays L and R
    int L[n1 + 1], R[n2 + 1];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = A[q + 1 + j];
    }

    // Use INT_MAX to represent infinity
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0, j = 0;

    // Merge the temporary arrays back into A[p..r]
    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

// Merge_sort function that recursively sorts the array
void Merge_sort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2; // Find the midpoint
        Merge_sort(A, p, q);  // Sort the first half
        Merge_sort(A, q + 1, r); // Sort the second half
        Merge(A, p, q, r); // Merge the sorted halves
    }
}

int main() {
    int A[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(A) / sizeof(A[0]);

    // Perform the merge sort
    Merge_sort(A, 0, n - 1);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
