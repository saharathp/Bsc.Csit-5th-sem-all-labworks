#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to compare two integers (used for qsort)
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Sorting-based approach (Non-linear)
int selection_sort_based(int arr[], int n, int k) {
    qsort(arr, n, sizeof(int), compare);
    return arr[k];
}

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function used in Quickselect
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quickselect algorithm (Expected linear)
int quickselect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pi = partition(arr, low, high);
        if (pi == k)
            return arr[pi];
        else if (pi > k)
            return quickselect(arr, low, pi - 1, k);
        else
            return quickselect(arr, pi + 1, high, k);
    }
    return -1;
}

// Function to generate a random array
void generate_random_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000;
    }
}

int main() {
    int n, k;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the index (0-based) of the element to find: ");
    scanf("%d", &k);

    if (k < 0 || k >= n) {
        printf("Invalid index\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    int *arr_copy = (int *)malloc(n * sizeof(int));

    if (arr == NULL || arr_copy == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Seed the random number generator
    srand(time(NULL));

    // Generate a random array
    generate_random_array(arr, n);
    for (int i = 0; i < n; i++) {
        arr_copy[i] = arr[i];
    }

    // Test sorting-based approach
    clock_t start_time = clock();
    int result_sort = selection_sort_based(arr, n, k);
    clock_t end_time = clock();
    double sort_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Sorting-based approach result: %d, Time taken: %f seconds\n", result_sort, sort_time);

    // Test Quickselect algorithm
    start_time = clock();
    int result_quickselect = quickselect(arr_copy, 0, n - 1, k);
    end_time = clock();
    double quickselect_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Quickselect approach result: %d, Time taken: %f seconds\n", result_quickselect, quickselect_time);

    // Free allocated memory
    free(arr);
    free(arr_copy);

    return 0;
}

