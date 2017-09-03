#include <algorithm>
#include <iostream>

#define RELATIVE_LEFT -1
#define RELATIVE_MIDDLE 0
#define RELATIVE_RIGHT 1

/**
* Perform a binary search on the array
* @In : receive na array, a length and a value
* @Out : a pair, the first paramether regards if the search has found the value, false if it hasn't been found; the second paramether regards the index in the array
*/

/**
* Perform a upper_bound search on the array
* @In : receive na array, a length and a value
* @Out : a integer showing where the value must be placed
*/
template <typename T, typename K>
static inline int upperBound(T* array, int length, K value)
{
    return std::upper_bound(array, array + length, value) - array;
}

/**
* Perform a lower_bound search on the array
* @In : receive na array, a length and a value
* @Out : a integer showing where the value must be placed
*/
template <typename T, typename K>
static inline int lowerBound(T* array, int length, K value)
{
    return std::lower_bound(array, array + length, value) - array;
}

template <typename T, typename K>
static inline std::pair<bool, int> binarySearch(T* array, int length, K value)
{
    int position = lowerBound(array, length, value);

    if (array[position] == value) {
        return { true, position };
    }
    return { false, position };
}

template <typename T>
/**
* Perform a ordered insert
* @In : receive an array, a length and a value
* @Out : void
*/
static inline void orderedInsert(T* array, int length, T value)
{
    int curIndex = 0;
    while (array[++curIndex] < value)
        ;
    --curIndex;

    while (array[--length] > curIndex) {
        array[length + 1] = array[length];
    }
    array[curIndex] = value;
}
