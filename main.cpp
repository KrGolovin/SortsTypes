#include <iostream>
#include "BasicSorts.h"
#include "Test.h"


int main() {
  int counterPassedTest = 0;
  int countOfTests = 12;
  counterPassedTest += goodCounterSort();
  counterPassedTest += randomCounterSort();
  counterPassedTest += badCounterSort();

  counterPassedTest += goodRadixSort();
  counterPassedTest += randomRadixSort();
  counterPassedTest += badRadixSort();

  counterPassedTest += goodBucketSort();
  counterPassedTest += randomBucketSort();
  counterPassedTest += badBucketSort();

  counterPassedTest += goodBinaryInsertionSort();
  counterPassedTest += randomBinaryInsertionSort();
  counterPassedTest += badBinaryInsertionSort();





  std::cout << counterPassedTest << " of " << countOfTests << " tests passed";

  return 0;
}
