# SORTING ALGORITHMS

- [Bubble Sort](#bubble-sort)
- [Selection Sort](#selection-sort)
- [Insertion Sort](#insertion-sort)
- [Merge Sort](#merge-sort)
- [Quick Sort](#quick-sort)
- [Heap Sort](#heap-sort)
- [Counting Sort](#counting-sort)
- [Radix Sort](#radix-sort)
- [Bucket Sort](#bucket-sort)
- [Shell Sort](#shell-sort)

## Bubble Sort

Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.

```cpp
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
```

Time Complexity: O(n^2)
Space Complexity: O(1)

## Selection Sort

Selection Sort is an in-place comparison sorting algorithm that divides the input list into two parts: the sublist of items already sorted and the sublist of items remaining to be sorted.

```cpp

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
```

Time Complexity: O(n^2)
Space Complexity: O(1)

## Insertion Sort

Insertion Sort is a simple sorting algorithm that builds the final sorted array one item at a time.

```cpp
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
```

Time Complexity: O(n^2)
Space Complexity: O(1)
