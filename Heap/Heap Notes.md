## [My custom Libray for Heap ](/Heap/Basic/Heap_Library.cpp)

## Questions :

- [Basic](/Heap/Basic/)
- [Advanced](/Heap/Advanced/)

## Basic

- **Heap** is a [complete binary](https://www.geeksforgeeks.org/complete-binary-tree/) tree that satisfies the heap property (i.e the key of the parent node is either always greater or always smaller than the keys of the children nodes).

- **Representation** of heap in memory is an array.

- **Root** is at index 0 in array.

- **Parent** of node at index `i` is at index `(i-1)/2`.

- **Left child** of node at index `i` is at index `2*i + 1`.

- **Right child** of node at index `i` is at index `2*i + 2`.

- [**Heapify :**](/Heap/Basic/Heapify.cpp) The process of converting a binary tree into a heap is called heapify operation , It is To build a Max-Heap from the given array elements So, the idea is to heapify the complete binary tree formed from the array in reverse level order following a top-down approach. That is first heapify, the last node in level order traversal of the tree, then heapify the second last node and so on.

  - Time complexity of heapify single node is O(log n) , and there are total n nodes so time complexity of heapify is O(n log n) , but in reality it is O(n).[Read More](https://www.geeksforgeeks.org/time-complexity-of-building-a-heap/)

- [**Insertion :**](/Heap/Basic/Insertion.cpp) In this you are given a heap and you have to insert an element in the heap maintaining the heap property.

  - Insert the element at the end of the heap.
  - Heapify the element from `bottom to top`.
  - Time complexity of insertion is O(log n).

  [**Deletion :**](/Heap/Basic/Insertion.cpp) (Only Delete the root element) In Deletion, we remove the root element and replace it with the last element of the heap followed by heapifying the element from `top to bottom`.

- [**Heap Sort :**](/Heap/Basic/3.%20Heap_sort.cpp) Heap sort is a comparison-based sorting technique based on Binary Heap data structure. It is similar to selection sort .

  - **Algorithm**
    - First , convert the input array to max heap . _(Heapify the array , starting from the last non-leaf node to the root node , in reverse level order its takes O(n) time)_.
    - At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of heap by 1.
      And Run the Heapify algorithm from top to bottom , which again bring the largest element in array from index 0 to n-i.
    - Repeat above steps while size of heap is greater than 1.
  - **Time Complexity** : O(n log n) , In-place sorting algorithm.

- **Applications** of Heap:

  - **Priority Queue** : Priority queues can be efficiently implemented using Binary Heap because it supports insert(), delete() and extractmax(), decreaseKey() operations in O(log n) time.
  - **Heap Sort** : Heap sort algorithm has limited uses because Quicksort and Mergesort are better in practice. Nevertheless, the Heap data structure itself is enormously used.
  - **Graph Algorithms** : The priority queues are especially used in Graph Algorithms like Dijkstra’s Shortest Path and Prim’s Minimum Spanning Tree.
  - **K’th Largest Element in an array** : The Binary Heap can be used to efficiently find the K’th largest (or smallest) element in an array.
  - **Merge K sorted arrays** : The Binary Heap is used to merge K sorted arrays.
  - **Order statistics** : The Heap data structure can be used to efficiently find the k’th smallest (or largest) element in an array.
  - **Median in a stream of integers** : The Heap can be used to maintain the median of a stream of integers.

- **Types of Heap**:

  - **Min Heap** : The key at root must be minimum among all keys present in Binary Heap.
  - **Max Heap** : The key at root must be maximum among all keys present in Binary Heap.

- **Kth largest element in an array** : [**Code**](/Heap/Advanced/2.%20Kth_largest.cpp)

  - We can use min heap to find kth largest element in an array.
  - Run a loop from 0 to n-1 and insert elements in min heap priority queue.
  - If size of min heap becomes greater than k , then remove the top element.
  - At the end , top element of min heap will be kth largest element and the Last K elements that are left in min heap will be k largest elements.

- **Check if a given Binary Tree is Heap** : [**Code**](/Heap/Basic/4.%20Check_Binary_tree_Heap.cpp)

  - A Binary Tree is a Complete Binary Tree if all levels are completely filled except possibly the last level and all nodes are as left as possible.
  - A Binary Tree is a Heap if it is a complete binary tree and its nodes are in max heap order.
  - Time complexity of this approach is O(n).

- **Merge Two Binary Max Heaps** : [**Code**](/Heap/Advanced/3.%20Merge_two_Max_Heap.cpp)
  - We can merge two max heaps by inserting all elements of one heap into another heap.
  - Time complexity of this approach is O(n log n).

## Advanced

- **Convert BST To HEAP :** [**Code**](/Heap/Advanced/4.%20Convert_Bst_to_Min_Heap.cpp) -**Given BST is Complete Binary Tree**

  - **Approach** : Inorder traversal of BST gives elements in sorted order , So we can store the inorder traversal of BST in an array & Then run preorder Traversal of BST and replace the elements of BST with the sorted elements of array in preorder traversal.
  - **Time Complexity** : O(n) , where n is the number of nodes in BST.

- **Merge K sorted**

  - Merge K sorted arrays : [**Code**](/Heap/Advanced/5.%20Merge_K_Sorted_array.cpp)

    - **Approach** :
      - First , create a structure of 3 elements (value , array number , index), that can store the value of element , array number and index of element.
      - Create a min heap/Priority_queue and insert the first elements of all the k arrays.
      - Run a loop until the size of min heap is greater than 0.
      - Inside that loop , Remove the top element of min heap/priority_queue and insert the next element from the same array.
      - **Time Complexity** : O(n\*k log k) , where n is the number of elements in each array.

  - Merge K sorted linked lists : [**Code**](/Heap/Advanced/6.%20Merge_k_sorted_LL.cpp)
    - **Approach** :
      - Create a `min heap/priority_queue<Node*>` and insert the head of all the k linked lists.
      - Run a loop until the size of min heap is greater than 0.
      - Inside that loop , Remove the top element of min heap/priority_queue and insert the next element from the same linked list.
      - **Time Complexity** : O(n\*k log k) , where n is the number of elements in each linked list.
