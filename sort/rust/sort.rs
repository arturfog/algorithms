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
        let n = high - low;
        for i in 1..n {
            let key = vec[i];
            let mut j: isize = (i as isize - 1) as isize;
            while j >= 0 && vec[j as usize] > key {
                vec[(j + 1) as usize] = vec[j as usize];
                j-=1;
            }
            vec[(j + 1) as usize] = key;
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
        self.merge(vec, low, mid, high)
    }
}

impl MergeSort {
    fn merge(&self, vec: &mut Vec<i32>, low: usize, mid: usize, high: usize) {
        let left_half_size = mid - low + 1;
        let right_half_size = high - mid;

        let mut i = 0;
        let mut j = 0;
        let mut k = low;

        let mut left: Vec<i32> = Vec::new();
        let mut right: Vec<i32> = Vec::new();

        for i in 0..left_half_size {
            left.push(vec[low + i]);
        }
        for j in 0..right_half_size {
            right.push(vec[mid + j + 1]);
        }

        while i < left_half_size && j < right_half_size {
            if left[i] <= right[j] {
                vec[k] = left[i];
                i+=1;
            } else {
                vec[k] = right[j];
                j+=1;
            }
            k+=1;
        }

        while i < left_half_size {
            vec[k] = left[i];
            i+=1;
            k+=1;
        }

        while j < right_half_size {
            vec[k] = right[j];
            j+=1;
            k+=1;
        }
    }
}

impl Sort for QuickSort {
    fn sort(&self, vec: &mut Vec<i32>, low: usize, high: usize) {
        if high <= low {
            return
        }

        let part: usize = self.partition(vec, low, high);
        self.sort(vec, low, part - 1);
        self.sort(vec, part + 1, high);
    }
}

impl QuickSort {
    fn partition(&self, vec: &mut Vec<i32>, low: usize, high: usize) -> usize {
        let mut i = low;
        let mut j: isize = high as isize + 1;
        let tmp = vec[low];
        loop {
            i+=1;
            while vec[i] < tmp {
                i+=1;
                if i >= high {
                    break;
                }                
            }
            j-=1;
            while tmp < vec[j as usize] {
                j-=1;
                if j as usize <= low {
                    break;
                }
            }
            if i>=j as usize {
                break;
            }
            //
            let tmp = vec[i];
            vec[i] = vec[j as usize];
            vec[j as usize] = tmp;
        }
        let tmp = vec[low];
        vec[low] = vec[j as usize];
        vec[j as usize] = tmp;
        return j as usize;
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
    for _ in 0..size {
        unsafe {
            vec.push(rand() % 1000);
        }
    }
    return vec;
}

fn test_sort(sort: &dyn Sort, name: &str, dec_len: bool) {
    println!("-=| TESTING {} SORT |=-", name);
    let mut vec: Vec<i32> = gen_random_data(20);
    print_data(&vec);
    if dec_len {
        sort.sort(&mut vec, 0, 19);
    } else {
        sort.sort(&mut vec, 0, 20);
    }
    print_data(&vec);
}

extern "C" {
    fn srand() -> u32;
    fn rand() -> i32;
}

fn main() {
    let sel_sort: SelectionSort = SelectionSort{};
    test_sort(&sel_sort, "SELECTION", false);
    let ins_sort: InsertionSort = InsertionSort{};
    test_sort(&ins_sort, "INSERTION", false);
    let merge_sort: MergeSort = MergeSort{};
    test_sort(&merge_sort, "MERGE", true);
    let quick_sort: QuickSort = QuickSort{};
    test_sort(&quick_sort, "QUICK", true);
}