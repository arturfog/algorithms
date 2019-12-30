class Sort {
    func sort(data: inout [Int], low: Int, high: Int) {}
}

class SelectionSort: Sort {
    override func sort(data: inout [Int], low: Int, high: Int) {
        let N = high - low
        var min = 0
        for i in 0...N {
            min = i
            for j in i...N {
                if data[j] < data[min] {
                    min = j
                }
            }
            data.swapAt(i, min)
        }
    }
}

class InsertionSort: Sort {
    override func sort(data: inout [Int], low: Int, high: Int) {
        let N = high - low

        for i in 1...N {
            var j = i - 1
            let key = data[i]
            while j >= 0 && data[j] > key {
                data[j+1] = data[j]
                j-=1
            }
            data[j + 1] = key
        }
    }
}

class MergeSort: Sort {
    override func sort(data: inout [Int], low: Int, high: Int) {
        if high <= low {
            return
        }

        let mid = low + (high - low) / 2
        sort(data:&data, low:low, high: mid)
        sort(data:&data, low:mid+1, high: high)
        merge(data:&data, low: low, mid: mid, high: high)
    }

    func merge(data: inout [Int], low: Int, mid: Int, high: Int) {
	    let leftHalfSize = mid - low + 1
	    let rightHalfSize = high - mid

        var i = 0
	    var j = 0
	    var k = low

        var left = [Int]()
        for i in 0...leftHalfSize {
            left.append(data[low + i])
        }
        var right = [Int]()
        for j in 0...rightHalfSize {
            right.append(data[mid + j + 1])
        }

        i = 0
	    j = 0

        while i < leftHalfSize && j < rightHalfSize {
            if left[i] <= right[j] {
                data[k] = left[i]
                i+=1
            } else {
                data[k] = right[j]
                j+=1
            }
            k+=1
        }

        while i < leftHalfSize {
            data[k] = left[i]
            i+=1
            k+=1
	    }

	    while j < rightHalfSize {
            data[k] = right[j]
            j+=1
            k+=1
	    }
    }
}

class QuickSort: Sort {
    override func sort(data: inout [Int], low: Int, high: Int) {
        if high <= low {
            return
        }

        let part:Int = partition(data:&data, low:low, high:high)
        sort(data:&data, low:low, high: part - 1)
        sort(data:&data, low: part + 1, high: high)
    }

    func partition(data: inout [Int], low: Int, high: Int) -> Int {
        var i: Int = low
        var j: Int = high + 1
        let tmp = data[low]

        while true {
            i+=1
            while data[i] < tmp {
                i+=1
                if i == high {
                    break
                }
		    }
		    j-=1
		    while tmp < data[j] {
                j-=1
                if j == low {
                    break
                }
		    }
        
            if i >= j {
			    break
            }
            data.swapAt(i,j)
        }
        data.swapAt(low, j)
        return j
    }
}

func generateRandomData(size: Int) -> [Int] {
    var data = [Int]()
    for _ in 0...size {
        data.append(Int.random(in: 0 ..< 1000))
    }

    return data
}

func printData(data: [Int]) {
    print(data)
}

func testSort(sort: Sort, name: String, decLen: Bool) {
    print("-=| " + name + " SORT |=-")
    var data = generateRandomData(size:20)
    printData(data: data)
    if decLen {
        sort.sort(data: &data, low:0, high:19)
    } else {
        sort.sort(data: &data, low:0, high:20)
    }
    
    printData(data: data)
}

func main() {
    let selSort = SelectionSort()
    testSort(sort: selSort, name:"SELECTION", decLen:false)
    let insSort = InsertionSort()
    testSort(sort: insSort, name:"INSERTION", decLen:false)
    let mergeSort = MergeSort()
    testSort(sort: mergeSort, name: "MERGE", decLen:true)
    let quickSort = QuickSort()
    testSort(sort: quickSort, name: "QUICK", decLen: true)
}

main()
