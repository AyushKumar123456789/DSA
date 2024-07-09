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

`Time Complexity: O(n^2)`
`Best Time Complexity: O(n^2)`
`Space Complexity: O(1)`

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

`Average Time Complexity: O(n^2)`
`Best Time Complexity: O(n^2)`
`Worst Time Complexity: O(n^2)`
`Space Complexity: O(1)`

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

`Average Time Complexity: O(n^2)`
`Best Time Complexity: O(n)`
`Worst Time Complexity: O(n^2)`
`Space Complexity: O(1)`

## Merge Sort

Merge Sort is a divide and conquer algorithm that divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves.

```cpp
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
```

`Average Time Complexity: O(n log n)`
`Best Time Complexity: O(n log n)`
`Worst Time Complexity: O(n log n)`
`Space Complexity:` O(n) auxiliary space and O(n) stack space for function calls , auxiliary space is required for merging two halves of the array. But LinkedList can be used to reduce the auxiliary space to O(1).

## Quick Sort

Quick Sort is a divide and conquer algorithm that picks an element as pivot and partitions the given array around the picked pivot.
The key process in quickSort is a partition() . The target of partitions is to place the pivot (any element can be chosen to be a pivot) at its correct position in the sorted array and put all smaller elements to the left of the pivot, and all greater elements to the right of the pivot.

Partition is done recursively on each side of the pivot after the pivot is placed in its correct position and this finally sorts the array.

Choice of pivot is important in quickSort.

- Always pick first element as pivot.
- Always pick last element as pivot.
- Pick a random element as pivot.
- Pick middle element as pivot.

```cpp

int partition(int arr[],int low,int high)
{
  //choose the pivot

  int pivot=arr[high];
  //Index of smaller element and Indicate
  //the right position of pivot found so far
  int i=(low-1);

  for(int j=low;j<=high-1;j++)
  {
    //If current element is smaller than the pivot
    /*
    Doing this because every element which is smaller than pivot should be from low to i
    and then we will put pivot on i+1
    */
    if(arr[j]<pivot)
    {
      //Increment index of smaller element
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[high]);
  return (i+1);
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    return 0;
}

```

`Average Time Complexity: O(n log n)` : The best-case scenario for quicksort occur when the pivot chosen at the each step divides the array into roughly equal halves.
In this case, the algorithm will make balanced partitions, leading to efficient Sorting.

`Best Time Complexity: O(n log n)` : Quicksort’s average-case performance is usually very good in practice, making it one of the fastest sorting Algorithm.

`Worst Time Complexity: O(n^2) ` : The worst-case Scenario for Quicksort occur when the pivot at each step consistently results in highly unbalanced partitions. When the array is already sorted and the pivot is always chosen as the smallest or largest element. To mitigate the worst-case Scenario, various techniques are used such as choosing a good pivot (e.g., median of three) and using Randomized algorithm (Randomized Quicksort ) to shuffle the element before sorting.

`Space Complexity`: Auxiliary Space: O(1), if we don’t consider the recursive stack space. If we consider the recursive stack space then, in the worst case quicksort could make O ( N ).

### Advantages of Quick Sort:

- It is a divide-and-conquer algorithm that makes it easier to solve problems.
- It is efficient on large data sets.
- It has a low overhead, as it only requires a small amount of memory to function.

### Applications of Quick Sort:

- Quick Sort is used in the Unix operating system for sorting files.
- It is used in the C library function qsort() for sorting arrays.
- It is used in the Java library for sorting arrays.

### Disadvantages of Quick Sort:

- It has a worst-case time complexity of O(N 2 ), which occurs when the pivot is chosen poorly.
- It is not a good choice for small data sets.
- It is not a stable sort, meaning that if two elements have the same key, their relative order will not be preserved in the sorted output in case of quick sort, because here we are swapping elements according to the pivot’s position (without considering their original positions).

### Quick Sort vs Merge Sort:

- Quick Sort (i.e., it doesn’t require any extra storage) while Merge Sort requires O(N) extra storage, N denoting the array size which may be quite expensive.
- Merge Sort is more stable than Quick Sort because it is not affected by the pivot selection.
- Merge sort time complexity is O(n log n) in all cases, whereas quick sort has a worst-case time complexity of O(n^2).

## Heap Sort

First convert the array into heap data structure using heapify, then one by one delete the root node of the Max-heap and replace it with the last node in the heap and then heapify the root of the heap. Repeat this process until size of heap is greater than 1.

- Build a max heap from the input data.
- At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of heap by 1. Finally, heapify the root of the tree.
- Repeat the above process until the size of the heap is greater than 1.

```cpp
void heapify(int arr[], int n, int i) {
    while (i < n) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(arr[i], arr[largest]);
            i = largest;
        } else {
            break;
        }
    }
}

void heapSort(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
```

`Average Time Complexity: O(n log n)`
`Best Time Complexity: O(n log n)`
`Worst Time Complexity: O(n log n)`
`Space Complexity: O(1)`
Heap Sort is not a stable sort as it changes the relative order of equal elements.
What is stable sort?
A sorting algorithm is said to be stable if two objects with equal keys appear in the same order in sorted output as they appear in the input array to be sorted.

## Counting Sort

Counting Sort is a non-comparison-based sorting algorithm that works well when there is limited range of input values. It is particularly efficient when the range of input values is small compared to the number of elements to be sorted. The basic idea behind Counting Sort is to count the frequency of each distinct element in the input array and use that information to place the elements in their correct sorted positions.

```cpp
void countingSort(int arr[], int n) {
    int max = *max_element(arr, arr+n);
    int min = *min_element(arr, arr+n);
    int range = max - min + 1;
    int count[range] = {0};
    int output[n];
    for (int i = 0; i < n; i++) {
        count[arr[i] - min]++;
    }
    for (int i = 1; i < range; i++) {
        count[i] += count[i-1];
    }
    for (int i = n-1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

```
