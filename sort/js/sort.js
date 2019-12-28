"use strict";

class SelectionSort {
    sort(array, low, high) {
        const N = high - low;
        let min = 0;
        for(let i = 0; i < N; i++) {
            min = i;
            for(let j = i + 1; j < N; j++) {
                if(array[j] < array[min]) { 
                    min = j;
                }
            }
            [array[i], array[min]] = [array[min], array[i]];
        }
    }
}

class InsertionSort {
    sort(array, low, high) {
        const N = high - low;
        let j = 0;
        let key = 0;
        for(let i = 0; i < N; i++) {
            j = i - 1;
            key = array[i];
            while(j >= 0 && array[j] > key) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = key;
        }
    }
}

class MergeSort {
    sort(array, low, high) {
        if(high <= low) {
            return;
        }
        const mid = Math.floor(low + (high - low) / 2);
        this.sort(array, low, mid);
        this.sort(array, mid + 1, high);

        this.merge(array, low, mid, high);
    }

    merge(array, low, mid, high) {
        const leftHalfSize = mid - low + 1;
        const rightHalfSize = high - mid;

        let i = 0;
        let j = 0;
        let k = low;

        let left = new Array(leftHalfSize);
        let right = new Array(rightHalfSize);

        for (i = 0; i < leftHalfSize; i++) {
            left[i] = array[low + i]; 
        }

        for (j = 0; j < rightHalfSize; j++) {
            right[j] = array[mid + 1 + j];
        }

        i = j = 0;

        while(i < leftHalfSize && j < rightHalfSize) {
            if(left[i] <= right[j]) {
                array[k] = left[i];
                i++;
            } else {
                array[k] = right[j];
                j++;
            }
            k++;
        }

        while(i < leftHalfSize) {
            array[k] = left[i];
            i++;
            k++;
        }
    
        while(j < rightHalfSize) {
            array[k] = right[j];
            j++;
            k++;
        }
    }
}

class QuickSort {
    sort(array, low, high) {
        if(high <= low) {
            return
        }
        const part = this.partition(array, low, high)
        this.sort(array, low, part);
        this.sort(array, part + 1, high);
    }

    partition(array, low, high) {
        let i = low;
        let j = high + 1;
        const tmp = array[low];
        while(true) {
            while(array[++i] < tmp) { 
                if(i == high) { break; }
            }
            while(tmp < array[--j]) {
                if(j == low) { break; }
            }
            if(i >= j) { break; }
            [array[i], array[j]] = [array[j], array[i]];
        }
        [array[low], array[j]] = [array[j], array[low]];
        return j;
    }
}

function testSort(sort, name, decLen) {
    console.log("-=| TESTING " + name + " SORT |=-");
    let data = genRandomData(20);
    printArray(data);
    if(decLen) {
        sort.sort(data, 0, data.length - 1);
    } else {
        sort.sort(data, 0, data.length);
    }
    printArray(data);
}

function printArray(array) {
    console.log(array)
}

function getRandomInt(min, max) {
    min = Math.ceil(min);
    max = Math.floor(max);
    return Math.floor(Math.random() * (max - min)) + min;
}

function genRandomData(size) {
    let array = new Array(size);
    for(let i = 0; i < size; i++) {
        array[i] = getRandomInt(0, 1000);
    }
    return array;
}

let main = function() {
    let selectionSort = new SelectionSort();
    testSort(selectionSort, "SELECTION", false);
    let insSort = new InsertionSort();
    testSort(insSort, "INSERTION", false);
    let mergeSort = new MergeSort();
    testSort(mergeSort, "MERGE", true);
    let quickSort = new QuickSort();
    testSort(quickSort, "QUICK", true);
}

if (typeof require !== 'undefined' && require.main === module) {
    main();
}