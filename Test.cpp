//
// Created by Macbook Pro on 12.04.2020.
//
#include <iostream>
#include "BasicSorts.h"
template <class T>
bool testFunction(T *array, int size) {
  if (size <= 0) {
    throw "Invalid size of array";
  }
  for (int i = 1; i < size; ++i) {
    if (array[i] < array[i - 1]) {
      return false;
    }
  }
  return true;
}
template <class T>
void printArray(T *array, int size) {
  if (size <= 0) {
    throw "Invalid size of array";
  }
  for (int i = 0; i < size; ++i) {
    std::cout << array[i] << ' ';
  }
  std::cout << '\n';
}

int printResult(bool result) {
  if (result) {
    std::cout << "Test passed" << "\n\n";
    return 1;
  } else {
    std::cout << "Test unpassed" << "\n\n";
    return 0;
  }

}

template <class T>
int testSort(T *array, int size, void (*sort)(T *, int)) {
  try {
    std::cout << "Input array: \n";
    printArray(array, size);
    sort(array, size);
    std::cout << "Output array: \n";
    printArray(array, size);
    std::cout << "//\n";
    return printResult(testFunction(array, size));
  } catch (const char *e) {
    std::cout << "Exception\n\n";
    return 0;
  }
}

int goodCounterSort() {

  std::cout << "Good CounterSort Test\n//\n";
  int size = 20;
  int array[size];
  for (int i = 0; i < size; ++i) {
    array[i] = rand() % 2;
  }
  return testSort(array, size, counterSort);
}

int randomCounterSort() {
  std::cout << "Random CounterSort Test\n//\n";
  int size = 20;
  int array[size];
  for (int i = 0; i < size; ++i) {
    array[i] = rand() % size;
  }
  return testSort(array, size, counterSort);
}

int badCounterSort() {
  std::cout << "Bad CounterSort Test\n//\n";
  int size = 2;
  int array[size];
  array[0] = 10000;
  array[1] = 0;
  return testSort(array, size, counterSort);
}

int goodRadixSort() {
  std::cout << "Good RadixSort Test\n//\n";
  int size = 20;
  int array[size];
  for (int i = 0; i < size; ++i) {
    array[i] = rand() % 10;
  }
  return testSort(array, size, radixSort);
}

int randomRadixSort() {
  std::cout << "Random RadixSort Test\n//\n";
  int size = 20;
  int array[size];
  for (int i = 0; i < size; ++i) {
    array[i] = rand() % 1000;
  }
  return testSort(array, size, radixSort);
}

int badRadixSort() {
  std::cout << "Bad RadixSort Test\n//\n";
  int size = 2;
  int array[size];
  for (int i = 0; i < size; ++i) {
    array[i] = rand() % 1000000;
  }
  return testSort(array, size, radixSort);
}

int goodBucketSort() {
  std::cout << "Good BucketSort Test\n//\n";
  int size = 10;
  double array[size];
  for (int i = 0; i < size; ++i) {
    array[i] = (9 - i) * 0.1;
  }
  return testSort(array, size, bucketSort);
}
int randomBucketSort() {
  std::cout << "Random BucketSort Test\n//\n";
  int size = 20;
  double array[size];
  for (int i = 0; i < size; ++i) {
    array[i] = (rand() % 100) * 0.01;
  }
  return testSort(array, size, bucketSort);
}
int badBucketSort() {
  std::cout << "Bad BucketSort Test\n//\n";
  int size = 20;
  double array[size];
  for (int i = 0; i < size; ++i) {
    array[i] = (rand() % 10) * 0.01;
  }
  return testSort(array, size, bucketSort);
}