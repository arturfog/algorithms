#include "sort.hpp"
template <class T>
bool SelectionSort<T>::sort(std::vector<T>& vec, int32_t low, int32_t high) {
    int32_t min = 0;
    for(int32_t i = 0; i < high; i++) {
        min = i;
        for(int32_t j = i + 1; j < high; j++) {
            if(vec[j] < vec[min]) { min = j; }
        }
        Sort<T>::swap(vec, i, min);
    }
    return false;
}

template <class T>
bool InsertionSort<T>::sort(std::vector<T>& vec, int32_t low, int32_t high) {
    for(int32_t i = 0; i < high; i++) {
    }
    return false;
}

template <class T>
bool MergeSort<T>::sort(std::vector<T>& vec, int32_t low, int32_t high) {
    return false;
}

template <class T>
bool QuickSort<T>::sort(std::vector<T>& vec, int32_t low, int32_t high) {
    if(high <= low) { return false; }
    
    const uint32_t part = partition(vec, low, high);
    this->sort(vec, low, part - 1);
    this->sort(vec, part + 1, high);
    return false;
}

template <class T>
int32_t MergeSort<T>::merge(std::vector<T>& vec, const int32_t low, const int32_t high) {
    return 0;
}

template <class T>
int32_t QuickSort<T>::partition(std::vector<T>& vec, const int32_t low, const int32_t high) {
    uint32_t i = low;
    uint32_t j = high + 1;
    const T tmp = vec[low];
    while(true) {
        while(vec[++i] < tmp) { 
            if(i == high) { break; }
        }
        while(tmp < vec[--j]) {
            if(j == low) { break; }
        }
        if(i >= j) { break; }
        Sort<T>::swap(vec, i, j);
    }
    Sort<T>::swap(vec, low, j);
    return j;
}

//
template class SelectionSort<int32_t>;
template class SelectionSort<int64_t>;
//
template class InsertionSort<int32_t>;
//
template class MergeSort<int32_t>;
//
template class QuickSort<int32_t>;