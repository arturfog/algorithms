use std::vec::Vec;

struct SelectionSort {}
struct InsertionSort {}
struct MergeSort {}
struct QuickSort {}

trait Sort {
    fn sort(&self, vec: &mut Vec<i32>, low: usize, high: usize);
}

impl Sort for SelectionSort {
    fn sort(&self, vec: &mut Vec<i32>, low: usize, high: usize) {
        for i in low..high {
            let mut min = i;
            for j in i+1..high {
                if vec[j] < vec[min] {
                    min = j;
                }
            }
            let tmp = vec[i];
            vec[i] = vec[min];
            vec[min] = tmp;
        }
    }
}

impl Sort for InsertionSort {
    fn sort(&self, vec: &mut Vec<i32>, low: usize, high: usize) {
        for i in low..high {
            let key = vec[i];
            let mut j = 0;
            if(low > 0) {
                j = i - 1
            }
            while j > 0 && vec[j] > key {
                vec[j + 1] = vec[j];
                if j > 0 {
                    j-=1;
                }
            }
            vec[j + 1] = key;
        }
    }
}

impl Sort for MergeSort {
    fn sort(&self, vec: &mut Vec<i32>, low: usize, high: usize){
        if high <= low {
            return
        }

        let mid: usize = low + (high - low) / 2;
        self.sort(vec, low, mid);
        self.sort(vec, mid + 1, high);
    }
}

impl Sort for QuickSort {
    fn sort(&self, vec: &mut Vec<i32>, low: usize, high: usize) {
        if high <= low {
            return
        }

        let part: usize = 0;
        self.sort(vec, low, part - 1);
        self.sort(vec, part + 1, high);
    }
}

fn print_data(vec: &Vec<i32>) {
    print!("[");
    for i in 0..vec.len() {
        print!("{} ", vec[i]);
    }
    println!("]");
}

fn gen_random_data(size: i32) -> Vec<i32> {
    unsafe {
        srand();
    }
    let mut vec: Vec<i32> = Vec::new();
    for i in 0..size {
        unsafe {
            vec.push(rand() % 1000);
        }
    }
    return vec;
}

fn test_sort(sort: &Sort, name: &str) {
    println!("-=| TESTING {} SORT |=-", name);
    let mut vec: Vec<i32> = gen_random_data(20);
    print_data(&vec);
    sort.sort(&mut vec, 0, 20);
    print_data(&vec);
}

extern "C" {
    fn srand() -> u32;
    fn rand() -> i32;
}

fn main() {
    let sel_sort: SelectionSort = SelectionSort{};
    test_sort(&sel_sort, "SELECTION");
    let ins_sort: InsertionSort = InsertionSort{};
    test_sort(&ins_sort, "INSERTION");
    let merge_sort: MergeSort;
    let quick_sort: QuickSort;
}