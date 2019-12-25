#include <stdint.h>
#include <memory>
#include <vector>
template <class T>
class Sort {
public:
  virtual bool sort(std::vector<T>& vec, int32_t low, int32_t high) = 0;
  void swap(std::vector<T>& vec, uint32_t left, uint32_t right) {
    const T tmp = vec[left];
    vec[left] = vec[right];
    vec[right] = tmp;
  }
};
/**
 * Worst case:
 * Average:
 **/
template <class T>
class SelectionSort : public Sort<T> {
public:
  virtual bool sort(std::vector<T>& vec, int32_t low, int32_t high);
};
/**
 * Worst case:
 * Average:
 **/
template <class T>
class InsertionSort : public Sort<T> {
public:
  virtual bool sort(std::vector<T>& vec, int32_t low, int32_t high);
};
/**
 * Merge sort
 * 
 * Worst case: O(n log n)
 * Average: O(n log n)
 * Space: О(n)
 **/
template <class T>
class MergeSort : public Sort<T> {
public:
  virtual bool sort(std::vector<T>& vec, int32_t low, int32_t high);
private:
  void merge(std::vector<T>& vec, int32_t low, const int32_t mid, int32_t high);  
};
/**
 * Quick sort
 * 
 * Worst case: O(n2)
 * Average: O(n log n)
 * Space: О(n)
 **/
template <class T>
class QuickSort : public Sort<T> {
public:
  virtual bool sort(std::vector<T>& vec, const int32_t low, const int32_t high);
private:
  int32_t partition(std::vector<T>& vec, const int32_t low, const int32_t high);
};
