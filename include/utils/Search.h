#ifndef SEARCH_CLASSES
#define SEARCH_CLASSES

/**
 * @brief Search the array using binary search
 * @tparam T the type of the array
 * @param array the array to be searched
 * @param key the key to be searched
 * @param start the start index of the array
 * @param end the end index of the array
 * @return the index of the key, -1 if not found
 */
template <typename T>
int binarySearch(T array[], T key, int start, int end);

/**
 * @brief Search the array using sequential search
 * @tparam T the type of the array
 * @param array the array to be searched
 * @param key the key to be searched
 * @param length the length of the array
 * @return the index of the key, -1 if not found
 */
template <typename T>
int sequentialSearch(T array[], T key, int length);

#endif