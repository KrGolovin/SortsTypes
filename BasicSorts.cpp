//
// Created by Macbook Pro on 12.04.2020.
//

#include "BasicSorts.h"
#include "List.h"
#include <cmath>
int countOfBitwise(int number) {
  if (number == 0) {
    return 1;
  }
  int count = 0;
  while (number > 0) {
    count++;
    number /= 10;
  }
  return count;
}

int getBitwise(int number, int k) {
  return ((number / (int)pow(10, k - 1)) % 10);
}

void copyArray(int * first, int * second, int size) {
  for (int i = 0; i < size; ++i) {
    first[i] = second[i];
  }
}

void counterSort(int *array, int size) {
  if (array == nullptr) {
    throw "nullpointer excepted";
  }
  if (size <= 0) {
    throw "Invalid size of array";
  }

  int k = 0;
  for (int i = 0; i < size; ++i) {
    if (array[i] < 0) {
      throw "invalid value in array";
    }
    k = (array[i] > k) ? array[i] : k;
  }

  int *c = new int[k + 1];

  for (int i = 0; i < k + 1; ++i) {
    c[i] = 0;
  }

  for (int i = 0; i < size; ++i) {
    c[array[i]]++;
  }

  for (int i = 1; i < k + 1; ++i) {
    c[i] += c[i - 1];
  }

  int j = 0;
  for (int i = 0; i < k + 1; ++i) {
    for (; j < c[i]; ++j) {
      array[j] = i;
    }
  }
  delete[] c;
}

void radixSort(int *array, int size) {
  if (array == nullptr) {
    throw "nullpointer excepted";
  }

  if (size <= 0) {
    throw "Invalid size of array";
  }

  int maxCountOfBitwise = 1;
  for (int i = 0; i < size; ++i) {
    if (array[i] < 0) {
      throw "invalid value in array";
    }
    int currCount = countOfBitwise(array[i]);
    maxCountOfBitwise = (currCount > maxCountOfBitwise) ? currCount : maxCountOfBitwise;
  }

  for (int k = 1; k <= maxCountOfBitwise; ++k) {
    int c[10] = {0};

    for (int i = 0; i < size; ++i) {
      c[getBitwise(array[i], k)]++;
    }

    int counter = 0;
    for (int i = 0; i < 10; ++i) {
      std::swap (counter, c[i]);
      counter += c[i];
    }

    int * b = new int[size];

    for (int i = 0; i < size; ++i) {
      int d = getBitwise(array[i], k);
      b[c[d]] = array[i];
      c[d]++;
    }
    copyArray(array, b, size);
    delete[] b;
  }
}

void bucketSort(double * array, int size) {
  if (array == nullptr) {
    throw "nullpointer excepted";
  }

  if (size <= 0) {
    throw "Invalid size of array";
  }

  List<double> * b = new List<double>[size];
  for (int i = 0; i < size; ++i) {
    if ((array[i] < 0) || (array[i] >= 1)) {
      throw "invalid value in array";
    }
    b[(int)floor((array[i] * size))] += array[i];
  }

  int counter = 0;
  for (int i = 0; i < size; ++i) {
    for (List<double>::Elem* curr = b[i].head_; curr != nullptr; curr = curr->getNext()) {
      array[counter] = curr->getValue();
      counter++;
    }
  }
}

