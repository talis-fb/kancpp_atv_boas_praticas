#include <iostream>
#include "../../include/utils/Search.h"

/* Binary search has a time complexity of O(log n) */
template <typename T>
int binarySearch(T array[], T key, int start, int end){
  if (start > end) {
    // Element not found
    return -1;
  }
  
  int mid = start + (end - start) / 2;
  
  if (array[mid] == key) {
    // Element found at mid index
    return mid;
  } else if (array[mid] > key) {
    // Search in the left half of the array
    return binarySearch(array, key, start, mid - 1);
  } else {
    // Search in the right half of the array
    return binarySearch(array, key, mid + 1, end);
  }
}

/* The sequential search has a time complexity of O(n) */
template <typename T>
int sequentialSearch(T array[], T key, int length){
  for (int i = 0; i < length; i++) {
    if (array[i] == key) {
      // Element found at index i
      return i;
    }
  }
    
  // Element not found
  return -1;
}