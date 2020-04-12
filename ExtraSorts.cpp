//
// Created by Macbook Pro on 12.04.2020.
//

#include "ExtraSorts.h"
#include "List.h"
#include <algorithm>
#include <cmath>
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

void shellSort(int * array, int size) {
  int counter = 0;
  for (int step = size / 2; step > 0; step /= 2) {
    for (int i = 0; i < step; ++i) {
      List<int> list;
      for (int curr = i; curr < size; curr += step) {
        counter += (list += array[curr]);
      }
      List<int>::Elem * currElem = list.head_;
      for (int curr = i; curr < size; curr += step) {
        array[curr] = currElem->getValue();
        currElem = currElem->getNext();
      }
    }
  }
  std::cout << "Time of Shell on array of " << size << " elements is "<< counter << '\n';
}

void hibSort(int * array, int size) {
  int counter = 0;
  int k = (int)log2(size + 1);
  for (int step = pow(2, k) - 1; step > 0; step =  pow(2, k) - 1) {
    for (int i = 0; i < step; ++i) {
      List<int> list;
      for (int curr = i; curr < size; curr += step) {
        counter += (list += array[curr]);
      }
      List<int>::Elem * currElem = list.head_;
      for (int curr = i; curr < size; curr += step) {
        array[curr] = currElem->getValue();
        currElem = currElem->getNext();
      }
    }
    k--;
  }
  std::cout << "Time of Hibbard on array of " << size << " elements is "<< counter << '\n';
}

void sedSort(int * array, int size) {
  int counter = 0;
  int k = 2 * (int)log2((size - 1)/ 9);
  while (k >= 0) {
    int step;
    if (k % 2 == 0) {
      step = 9 * pow(2, k) - 9 * pow(2, k / 2) + 1;
    } else {
      step = 8 * pow(2, k) - 6 * pow(2, (k + 1)/ 2) + 1;
    }
    for (int i = 0; i < step; ++i) {
      List<int> list;
      for (int curr = i; curr < size; curr += step) {
        counter += (list += array[curr]);
      }
      List<int>::Elem * currElem = list.head_;
      for (int curr = i; curr < size; curr += step) {
        array[curr] = currElem->getValue();
        currElem = currElem->getNext();
      }
    }
    k--;
  }
  std::cout << "Time of Sedgewick on array of " << size << " elements is "<< counter << '\n';
}