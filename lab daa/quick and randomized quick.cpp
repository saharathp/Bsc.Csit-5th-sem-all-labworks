#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random_shuffle(int arr[], int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int p, int r) {
    int pivotIndex = p + rand() % (r - p + 1); // Choose a random pivot index
    int pivot = arr[pivotIndex];
    swap(&arr[pivotIndex], &arr[r]); // Move pivot element to the end
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]); // Place pivot element in correct position
    return i + 1;
}

void quick_sort(int arr[], int p, int q) {
    if (p < q) {
        int j = partition(arr, p, q);
        quick_sort(arr, p, j - 1); // Recursively sort left subarray
        quick_sort(arr, j + 1, q); // Recursively sort right subarray
    }
}

void randomized_quick_sort(int arr[], int p, int q) {
    if (p < q) {
        int j = partition(arr, p, q);
        randomized_quick_sort(arr, p, j - 1); // Recursively sort left subarray
        randomized_quick_sort(arr, j + 1, q); // Recursively sort right subarray
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Perform Quick Sort
    quick_sort(arr, 0, n - 1);
    
    // Print sorted array using Quick Sort
    printf("\nSorted using Quick Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Shuffle the array again before using Randomized Quick Sort
    random_shuffle(arr, n);
    
    // Perform Randomized Quick Sort
    randomized_quick_sort(arr, 0, n - 1);
    
    // Print sorted array using Randomized Quick Sort
    printf("\nSorted using Randomized Quick Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}

