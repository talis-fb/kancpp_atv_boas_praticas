#ifndef SEARCH_FUNCTIONS
#define SEARCH_FUNCTIONS

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
int binarySearch(T array[], T key, int start, int end)
{
    if (start > end)
    {
        return -1;
    }

    int mid = start + (end - start) / 2;

    if (array[mid] == key)
    {
        return mid;
    }
    else if (array[mid] > key)
    {
        return binarySearch(array, key, start, mid - 1);
    }
    else
    {
        return binarySearch(array, key, mid + 1, end);
    }
}

/**
 * @brief Search the array using sequential search
 * @tparam T the type of the array
 * @param array the array to be searched
 * @param key the key to be searched
 * @param length the length of the array
 * @return the index of the key, -1 if not found
 */
template <typename T>
int sequentialSearch(T array[], T key, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (array[i] == key)
        {
            return i;
        }
    }

    return -1;
}

#endif