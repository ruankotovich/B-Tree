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

/**
* Perform a binary search in the collection
* @In : receive na array, a length and a value
* @Out : a integer showing where the value must be placed
*/
template <typename T, typename K>
static inline std::pair<bool, int> binarySearch(T* array, int length, K value)
{
    int position = lowerBound(array, length, value);

    if (array[position] == value) {
        return { true, position };
    }

    return { false, position };
}

/**
* Perform a binary search in the collection
* @In : receive na array, a length and a value
* @Out : a integer showing where the value must be placed
*/
template <typename T, typename K>
static inline std::pair<bool, int> secondaryBinarySearch(T* array, int length, K value)
{
    int position = upperBound(array, length, value);


    if (array[position] == value) {
        return { true, position };
    }

    return { false, position };
}



/**
* Perform a ordered insert
* @In : receive an array, a length and a value
* @Out : void
*/
template <typename T>
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

/**
* Perform a transformation of the string in a long
* @In : receive a char array
* @Out : a string compressed to integers
*/
static inline unsigned long stringNumericRepresentation(char *str)
  {
      unsigned long hash = 5381;
      int c;

      while ((c = *str++))
          hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

      return hash;
  }
