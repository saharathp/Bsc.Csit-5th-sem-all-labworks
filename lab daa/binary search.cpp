#include <stdio.h>

// Function to perform binary search
int binarySearch(int array[], int x, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;

    // If found at mid, then return it
    if (array[mid] == x)
      return mid;

    // Search the left half
    if (array[mid] > x)
      return binarySearch(array, x, low, mid - 1);

    // Search the right half
    return binarySearch(array, x, mid + 1, high);
  }

  return -1;
}

int main(void) {
  int n, x;

  // Taking input for the size of the array
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  int array[n];

  // Taking input for the array elements
  printf("Enter %d elements in sorted order:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }

  // Taking input for the target element to search
  printf("Enter the element to search: ");
  scanf("%d", &x);

  // Performing binary search
  int result = binarySearch(array, x, 0, n - 1);
  
  // Printing the result
  if (result == -1)
    printf("Not found\n");
  else
    printf("Element is found at index %d\n", result);

  return 0;
}

