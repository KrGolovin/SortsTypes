//
// Created by Macbook Pro on 12.04.2020.
//

#include "ExtraSorts.h"
#include <algorithm>
int binSearch(int * array, int value,  int begin, int end) {
  if (begin == end) {
    if (value > array[begin]) {
      return begin + 1;
    }
    return begin;
  }

  int mid = (begin + end) / 2;
  if (array[mid] > value) {
    return binSearch(array, value, begin, mid);
  } else {
    return binSearch(array, value, mid + 1, end);
  }

}

void binaryInsertionSort(int * array, int size) {
  for (int i = 1; i < size; ++i) {
    int position = binSearch(array, array[i], 0, i - 1);
    for (int j = i - 1; j >= position; --j) {
      std::swap(array[j], array[j + 1]);
    }
  }
}