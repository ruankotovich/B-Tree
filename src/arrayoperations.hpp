#pragma once
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

template <typename T, typename K>
static inline std::pair<bool, int> secondaryBinarySearch(T* array, int length, K value)
{
    int position = upperBound(array, length, value);
    

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
static inline std::pair<bool, unsigned short> orderedInsert(T* array, unsigned short &length, T& value)
{
  unsigned short currentSeekPosition = 0;

  while(currentSeekPosition < length){
    if(array[currentSeekPosition] < value){
      currentSeekPosition++;
      continue;
    }
    break;
  }

  if(currentSeekPosition < length){
    if(array[currentSeekPosition] == value){
      return {false, 0};
    }
  }

  for(int i=length; i > currentSeekPosition; --i){
    array[i] = array[i-1];
  }

  array[currentSeekPosition] = value;
  ++length;
  return {true, currentSeekPosition};

}