#include "sort.hpp"
#include <algorithm>
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
    int32_t j = 0;
    int32_t key = 0;
    for(int32_t i = 1; i < high; i++) {
        j = i - 1;
        key = vec[i];
        while(j >=0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j -= 1;
        }
        vec[j + 1] = key;
    }
    return false;
}

template <class T>
bool MergeSort<T>::sort(std::vector<T>& vec, int32_t low, int32_t high) {
    if(high <= low) { return false; }

    const int32_t mid = low + (high - low) / 2;
    sort(vec, low, mid);
    sort(vec, mid + 1, high);

    merge(vec, low, mid, high);
    return false;
}

template <class T>
bool QuickSort<T>::sort(std::vector<T>& vec, int32_t low, int32_t high) {
    if(high <= low) { return false; }
    
    const int32_t part = partition(vec, low, high);
    this->sort(vec, low, part - 1);
    this->sort(vec, part + 1, high);
    return false;
}
/**
 * Merge
 **/
template <class T>
void MergeSort<T>::merge(std::vector<T>& vec, const int32_t low, const int32_t mid, const int32_t high) {
    const int32_t leftHalfSize = mid - low + 1;
    const int32_t rightHalfSize = high - mid;

    std::vector<T> leftVec;
    std::vector<T> rightVec;

    int32_t i = 0;
    int32_t j = 0;
    int32_t k = low;

    for (i = 0; i < leftHalfSize; i++) 
        leftVec.emplace_back(vec[low + i]); 
    for (j = 0; j < rightHalfSize; j++) 
        rightVec.emplace_back(vec[mid + 1 + j]);

    i = j = 0;

    while(i < leftHalfSize && j < rightHalfSize) {
        if(leftVec[i] <= rightVec[j]) {
            vec[k] = leftVec[i];
            i++;
        } else {
            vec[k] = rightVec[j];
            j++;
        }
        k++;
    }

    while(i < leftHalfSize) {
        vec[k] = leftVec[i];
        i++;
        k++;
    }

    while(j < rightHalfSize) {
        vec[k] = rightVec[j];
        j++;
        k++;
    }
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
template class SelectionSort<float>;
//
template class InsertionSort<int32_t>;
template class InsertionSort<int64_t>;
template class InsertionSort<float>;
//
template class MergeSort<int32_t>;
template class MergeSort<int64_t>;
template class MergeSort<float>;
//
template class QuickSort<int32_t>;
template class QuickSort<int64_t>;
template class QuickSort<float>;