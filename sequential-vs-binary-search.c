#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sequentialSearch(int arr[], int size, int target){
  int count = 0; // Track the number of keys accessed
  for (int i = 0; i < size; i++) {
    count++;
    if (arr[i] == target) {
      printf("Number of keys checked: %d\n", count);
      return i; // Return the index of the found element
    }
  }
  printf("Number of keys checked: %d\n", count);
  return -1;
}

int binarySearch(int arr[], int low, int high, int target) {
  int count = 0; // Track the number of keys accessed
  while (low <= high) {
    count++; // increment the counter
    int mid = low + (high -low) / 2;

    if (arr[mid] == target) {
      printf("Number of keys accessed: %d\n", count);
      return mid; // Return the index if the target is found
    }
    else if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid + 1;
    }
  }
  return -1; // Return -1 if the target is not found
}

// Function that generates random numbers for the array
void generateNumbers(int arr[], int size) {
  // Initialize an array with numbers 0 to range - 1
  for (int i = 0; i < size; i++) {
    arr[i] = i;
  }
}

int main() {
  int size = 100000;
  int *arr = (int *)malloc(size * sizeof(int)); // Allocate memory for the array
  if (arr == NULL) {
    printf("Memory allocation failed!\n");
    return 1;
  }

  generateNumbers(arr, size); // Fill the array with numbers
  printf("Generated %d numbers. \n", size);

  int target;

  printf("Enter the element to search (0 - %d): ", size-1);
  scanf("%d", &target);

  // Output the sequential search result
  printf("Sequential search results:\n");
  int sequentialSearchResult = sequentialSearch(arr, size, target);
  if (sequentialSearchResult != -1) {
    printf("Element found at index %d.\n", sequentialSearchResult);
  } else {
    printf("Element not found in the array.\n");
  }

  // Output the binary search result
  printf("Binary search results:\n");
  int binarySearchResult = binarySearch(arr, 0, size, target);
  if (binarySearchResult != -1) {
    printf("Element found at index %d.\n", binarySearchResult);
  } else {
    printf("Element not found in the array.\n");
  }

  free(arr); // Free allocated memory
  return 0;
}