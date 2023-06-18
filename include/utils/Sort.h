#ifndef SORT_CLASSES
#define SORT_CLASSES

/**
 * @brief Partition the array into two parts, the left part is smaller than the pivot, the right part is larger than the pivot
 * @tparam T the type of the array
 * @param array the array to be sorted
 * @param start the start index of the array
 * @param end the end index of the array
 */
template <typename T>
int partition(T array[], int start, int end);

/**
 * @brief Sort the array using
 * @tparam T the type of the array
 * @param array the array to be sorted
 * @param start the start index of the array
 * @param end the end index of the array
 */
template <typename T>
void quickSort(T array[], int start, int end);

/**
 * @brief Sort the array using bubble sort
 * @tparam T the type of the array
 * @param array the array to be sorted
 * @param length the length of the array
 */
template <typename T>
void bubbleSort(T array[], int length);

/**
 * @brief Sort the array using insertion sort
 * @tparam T the type of the array
 * @param array the array to be sorted
 * @param length the length of the array
 */
template <typename T>
void selectionSort(T array[], int length);

#endif