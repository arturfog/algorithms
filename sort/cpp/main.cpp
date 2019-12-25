#include <iostream>
#include <fstream>
#include <random>
#include "sort.hpp"

template <class T>
void printVector(std::vector<T>& vec, const uint32_t size) {
  std::cout << "(" << size << "):[";
  for(uint32_t i = 0; i < size; i++) {
    std::cout << " " << vec[i]; 
  }
  std::cout << "]" << std::endl;
}

template <class T>
std::vector<T> genRandomVector(const uint32_t size) {
  std::srand(1);
  std::vector<T> vec;
  for(uint32_t i = 0; i < size; i++) {
    vec.emplace_back(std::rand() % 1000);
  }

  return vec;
}
template<class T>
void testSort(Sort<T>& sort, const std::string& sortName, bool decreaseLen) {
  std::cout << "-=| TESTING " << sortName << " SORT |=-" << std::endl;
  std::vector<int> A = genRandomVector<int>(15);
  printVector<int>(A, A.size());
  if(decreaseLen) {
    sort.sort(A, 0, A.size() - 1);
  } else {
    sort.sort(A, 0, A.size());
  }
  
  printVector<int>(A, A.size());
}

void testSelectionSort() {
  SelectionSort<int> selSort;
  testSort<int>(selSort, "SELECTION", false);
}

void testInsertionSort() {
  InsertionSort<int> insSort;
  testSort<int>(insSort, "INSERTION", false);
}

void testMergeSort() {
  MergeSort<int> mergeSort;
  testSort<int>(mergeSort, "MERGE", true);
}

void testQuickSort() {
  QuickSort<int> quickSort;
  testSort<int>(quickSort, "QUICK", true);
}

int main(int argc, char* argv[]) {
  testSelectionSort();
  testInsertionSort();
  testMergeSort();
  testQuickSort();
  return 0;
}

void loadFile(const std::string& path) {
  std::fstream file = std::fstream(path, std::ios::in);
  if(file.is_open()) {
    file.close();
  }
}