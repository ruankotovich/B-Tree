#include <algorithm>

template <typename T, typename L>
/**
* Perform a binary search on the array
* @In : receive na array, a length and a value
* @Out : a pair, the first paramether regards if the search has found the value, false if it hasn't been found; the second paramether regards the index in the array
*/
static inline std::pair<bool, int> binarySearch(T* array, L length, T value)
{
  L _left = 0, _right = length - 1;
  L _middle;

  while (_left <= _right) {

    _middle = (_left + _right) / 2;

    if (array[_middle] < value) {
      _left = _middle + 1;
      continue;
    } else if (array[_middle] > value) {
      _right = _middle - 1;
      continue;
    }

    return { true, _middle };
  }
  return { false, _middle };
}

template <typename T, typename L>
/**
* Perform a ordered insert
* @In : receive an array, a length and a value
* @Out : void
*/
static inline void orderedInsert(T* array, L length, T value)
{
  L curIndex = 0;
  while (array[++curIndex] < value)
  ;
  --curIndex;

  while (array[--length] > curIndex) {
    array[length + 1] = array[length];
  }
  array[curIndex] = value;
}
