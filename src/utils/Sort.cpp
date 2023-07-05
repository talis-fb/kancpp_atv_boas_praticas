#include <iostream>
#include "../../include/utils/Sort.h"

template <typename T>
void bubbleSort(T array[], int length) {
  bool swapped = true;
  int end = length;

  while (swapped) {
    swapped = false;
    for (int i = 0; i < end - 1; i++) {
      if (array[i] > array[i + 1]) {
        T temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        swapped = true;
      }
    }
    end--;
  }
}

template <typename T>
void selectionSort(T array[], int length) {
  for (int i = 0; i < length; i++) {
    
    int minIndex = i;
    
    for (int j = i + 1; j < length; j++) {
      if (array[j] < array[minIndex])
        minIndex = j;
    }
    
    if (i != minIndex) {
      T temp = array[i];
      array[i] = array[minIndex];
      array[minIndex] = temp;
    }
  }
}

template <typename T>
int findMedian(T array[], int start, int end) {
  int mid = start + (end - start) / 2;
  
  if (array[start] > array[mid])
    std::swap(array[start], array[mid]);
  if (array[start] > array[end])
    std::swap(array[start], array[end]);
  if (array[mid] > array[end])
    std::swap(array[mid], array[end]);
  
  return mid;
}

template <typename T>
int partition(T array[], int start, int end) {
  int pivotIndex = findMedian(array, start, end);
  T pivot = array[pivotIndex];
  int i = start;
  int j = end - 1;

  while (j >= i) {
    while (array[i] < pivot && j >= i)
      i++;
    while (array[j] > pivot && j >= i)
      j--;
    if (j >= i) {
      std::swap(array[i], array[j]);
      i++;
      j--;
    }
  }
  std::swap(array[i], array[end]);
  return i;
}

template <typename T>
void quickSort(T array[], int start, int end) {
  if (start < end) {
    int pivotIndex = partition(array, start, end);
    quickSort(array, start, pivotIndex - 1);
    quickSort(array, pivotIndex + 1, end);
  }
}