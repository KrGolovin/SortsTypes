//
// Created by Macbook Pro on 12.04.2020.
//
#include <iostream>
#include "BasicSorts.h"
#include "ExtraSorts.h"
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

int goodBinaryInsertionSort() {
  std::cout << "Good BinaryInsertionSort Test\n//\n";
  int size = 20;
  int array[size];
  for (int i = 0; i < size / 2; ++i) {
    array[2 * i] = 2 * i + 1;
    array[2 * i + 1] = 2 * i;
  }
  return testSort(array, size, binaryInsertionSort);
}
int randomBinaryInsertionSort() {
  std::cout << "Random BinaryInsertionSort Test\n//\n";
  int size = 20;
  int array[size];
  for (int i = 0; i < size; ++i) {
    array[i] = rand() % 1000;
  }
  return testSort(array, size, binaryInsertionSort);
}
int badBinaryInsertionSort() {
  std::cout << "Bad BinaryInsertionSort Test\n//\n";
  int size = 20;
  int array[size];
  for (int i = 0; i < size; ++i) {
    array[i] = size - 1 -  i;
  }
  return testSort(array, size, binaryInsertionSort);
}

int goodShellInsertionSort() {
  std::cout << "Good shellSort Test\n//\n";
  int size = 20;
  int array[size];
  for (int i = 0; i < size; ++i) {
    array[i] = size - 1 - i;
  }
  return testSort(array, size, shellSort);
}
int randomShellInsertionSort() {
  std::cout << "Random shellSort Test\n//\n";
  int size = 20;
  int array[size];
  for (int i = 0; i < size; ++i) {
    array[i] = rand() % 100;
  }
  return testSort(array, size, shellSort);
}
int badShellInsertionSort() {
  std::cout << "Bad shellSort Test\n//\n";
  int size = 20;
  int array[] = {738, 57, 616, 790, 640, 679, 335, 6, 972, 98, 95, 319, 454, 223, 289, 760, 905, 126, 123, 506 };
  for (int i = 0; i < size / 4; ++i) {
  }
  return testSort(array, size, shellSort);
}

int goodHibbardInsertionSort() {
  std::cout << "Good hibbardSort Test\n//\n";
  int size = 20;
  int array[size];
  for (int i = 0; i < size; ++i) {
    array[i] = size - 1 - i;
  }
  return testSort(array, size, hibSort);
}
int randomHibbardInsertionSort() {
  std::cout << "Random hibbardSort Test\n//\n";
  int size = 20;
  int array[size];
  for (int i = 0; i < size; ++i) {
    array[i] = rand() % 100;
  }
  return testSort(array, size, hibSort);
}
int badHibbardInsertionSort() {
  std::cout << "Bad hibbardSort Test\n//\n";
  int size = 20;
  int array[] = {738, 57, 616, 790, 640, 679, 335, 6, 972, 98, 95, 319, 454, 223, 289, 760, 905, 126, 123, 506 };
  for (int i = 0; i < size / 4; ++i) {
  }
  return testSort(array, size, hibSort);
}

int goodSedgewickInsertionSort() {
  std::cout << "Good sedgewickSort Test\n//\n";
  int size = 20;
  int array[size];
  for (int i = 0; i < size; ++i) {
    array[i] = size - 1 - i;
  }
  return testSort(array, size, sedSort);
}
int randomSedgewickInsertionSort() {
  std::cout << "Random sedgewickSort Test\n//\n";
  int size = 20;
  int array[size];
  for (int i = 0; i < size; ++i) {
    array[i] = rand() % 100;
  }
  return testSort(array, size, sedSort);
}
int badSedgewickInsertionSort() {
  std::cout << "Bad sedgewickSort Test\n//\n";
  int size = 20;
  int array[] = {738, 57, 616, 790, 640, 679, 335, 6, 972, 98, 95, 319, 454, 223, 289, 760, 905, 126, 123, 506 };
  for (int i = 0; i < size / 4; ++i) {
  }
  return testSort(array, size, sedSort);
}