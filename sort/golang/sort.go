package main

import (
	"fmt"
	"math/rand"
)

//
type Sort interface {
	sort(data []int, low int, high int)
}

//
type SelectionSort struct {
	Sort
}

func (s *SelectionSort) sort(data []int, low int, high int) {
	var N int = high - low
	var min int = 0
	for i := 0; i < N; i++ {
		min = i
		for j := i + 1; j < N; j++ {
			if data[j] < data[min] {
				min = j
			}
		}
		data[i], data[min] = data[min], data[i]
	}
}

//
type InsertionSort struct {
	Sort
}

func (s *InsertionSort) sort(data []int, low int, high int) {
	var N int = high - low
	var j int = 0
	var key int = 0
	for i := 1; i < N; i++ {
		j = i - 1
		key = data[i]
		for j >= 0 && data[j] > key {
			data[j+1] = data[j]
			j--
		}
		data[j+1] = key
	}
}

//
type MergeSort struct {
	Sort
}

func (s *MergeSort) sort(data []int, low int, high int) {
	if high <= low {
		return
	}
	var mid int = low + (high-low)/2
	s.sort(data, low, mid)
	s.sort(data, mid+1, high)
	s.merge(data, low, mid, high)
}

func (s *MergeSort) merge(data []int, low int, mid int, high int) {
	var leftHalfSize = mid - low + 1
	var rightHalfSize = high - mid

	var i int = 0
	var j int = 0
	var k int = low

	var left []int
	var right []int

	for i = 0; i < leftHalfSize; i++ {
		left = append(left, data[low+i])
	}
	for j = 0; j < rightHalfSize; j++ {
		right = append(right, data[mid+1+j])
	}

	i = 0
	j = 0

	for i < leftHalfSize && j < rightHalfSize {
		if left[i] <= right[j] {
			data[k] = left[i]
			i++
		} else {
			data[k] = right[j]
			j++
		}
		k++
	}

	for i < leftHalfSize {
		data[k] = left[i]
		i++
		k++
	}

	for j < rightHalfSize {
		data[k] = right[j]
		j++
		k++
	}
}

//
type QuickSort struct {
	Sort
}

func (s *QuickSort) sort(data []int, low int, high int) {
	if high <= low {
		return
	}
	var part int = s.partition(data, low, high)
	s.sort(data, low, part-1)
	s.sort(data, part+1, high)
}

func (s *QuickSort) partition(data []int, low int, high int) int {
	var i int = low
	var j int = high + 1
	var tmp int = data[low]
	for true {
		i++
		for data[i] < tmp {
			i++
			if i == high {
				break
			}
		}
		j--
		for tmp < data[j] {
			j--
			if j == low {
				break
			}
		}
		if i >= j {
			break
		}
		data[i], data[j] = data[j], data[i]
	}
	data[low], data[j] = data[j], data[low]
	return j
}

func genRandomData(size int) []int {
	var data []int = make([]int, size)

	rand.Seed(42)
	for i := 0; i < size; i++ {
		data[i] = rand.Intn(100)
	}

	return data
}

func printData(data []int) {
	fmt.Print("[ ")
	for index := 0; index < len(data); index++ {
		fmt.Print(data[index], " ")
	}
	fmt.Println("] ")
}

func testSort(name string, sort Sort, decLen bool) {
	fmt.Println("-=| TESTING ", name, " SORT |=-")
	var data []int = genRandomData(20)
	printData(data)
	if decLen {
		sort.sort(data, 0, len(data)-1)
	} else {
		sort.sort(data, 0, len(data))
	}

	printData(data)
}

func readDataFromFile(path string) {

}

func main() {
	var selSort SelectionSort
	testSort("SELECTION", &selSort, false)
	var insSort InsertionSort
	testSort("INSERTION", &insSort, false)
	var mergeSort MergeSort
	testSort("MERGE", &mergeSort, true)
	var quickSort QuickSort
	testSort("QUICK", &quickSort, true)
}
