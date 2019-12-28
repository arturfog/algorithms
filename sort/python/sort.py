#!/usr/bin/env python3
import random

class SelectionSort:
    def sort(self, data, low: int, high: int):
        min = 0
        for i in range(low, high):
            min = i
            for j in range(i + 1, high):
                if data[j] < data[min]:
                    min = j
            data[i], data[min] = data[min], data[i]


class InsertionSort:
    def sort(self, data, low: int, high: int):
        for i in range(low, high):
            key = data[i]
            j = i - 1
            while j >= 0 and data[j] > key:
                data[j + 1] = data[j]
                j-=1
            data[j + 1] = key

class MergeSort:
    def sort(self, data, low: int, high: int):
        if high <= low:
            return

        #print("low:" + str(low) + " high: " + str(high))
        mid:int = int(low + (high - low) / 2)
        self.sort(data, low, mid)
        self.sort(data, mid + 1, high)
        self.merge(data, low, mid, high)

    def merge(self, data, low: int, mid: int, high: int):
        leftHalfSize:int = mid - low + 1
        rightHalfSize:int = high - mid

        i:int = 0
        j:int = 0
        k:int = low

        left = []
        right = []
        for i in range(0, leftHalfSize):
            left.append(data[low + i])
        for i in range(0, rightHalfSize):
            right.append(data[mid + 1 + i])

        i = 0

        while i < leftHalfSize and j < rightHalfSize:
            if left[i] <= right[j]:
                data[k]=left[i]
                i+=1
            else:
                data[k]=right[j]
                j+=1
            k+=1

        while i < leftHalfSize:
            data[k] = left[i]
            i+=1
            k+=1

        while j < rightHalfSize:
            data[k] = right[j]
            j+=1
            k+=1

class QuickSort:
    def sort(self, data, low: int, high: int):
        if high <= low:
            return

        part: int = self.partition(data, low, high)
        self.sort(data, low, part - 1)
        self.sort(data, part + 1, high)

    def partition(self, data, low: int, high: int) -> int:
        i = low
        j = high + 1
        tmp = data[low]
        while True:
            i+=1
            while data[i] < tmp:
                i += 1
                if i == high:
                    break
            j-=1
            while tmp < data[j]:
                j-=1
                if j == low:
                    break
            if i >= j:
                break
            data[i], data[j] = data[j], data[i]
        data[low], data[j] = data[j], data[low]
        return j

def printData(data):
    print(data)


def genRandomData(size: int) -> []:
    data = []
    for _ in range(0, size):
        data.append(random.randint(1,1000))

    return data

def testSort(sort, name: str, decLen: bool):
    print("-=| TESTING " + name + " SORT |=-")
    data = genRandomData(20)
    printData(data)
    if decLen:
        sort.sort(data, 0, len(data) - 1)
    else:
        sort.sort(data, 0, len(data))
    printData(data)

def main():
    selSort = SelectionSort()
    testSort(selSort, "SELECTION", False)
    insSort = InsertionSort()
    testSort(insSort, "INSERTION", False)
    mergeSort = MergeSort()
    testSort(mergeSort, "MERGE", True)
    quickSort = QuickSort()
    testSort(quickSort, "QUICK", True)

if __name__ == "__main__":
    main()