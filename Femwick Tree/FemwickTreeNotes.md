# Femwick Tree / Binary Indexed Tree

## Introduction

### Where is it used?

- Consider a problem where you have an array of numbers with length upto 1e6 and you have to perform two types of queries:
  1. Update the value at a particular index.
  2. Find the sum of all elements from index l to a particular index.
- This can be done using a Fenwick Tree in O(logn) time complexity.

### What is it?

- A Fenwick Tree is a data structure that can efficiently update elements and calculate prefix sums in a table of numbers.
- It is also known as a Binary Indexed Tree (BIT).

### Some Background

- **BIT uses one-based indexing.**
- Calculating the Rightmost Set Bit:

  - The rightmost set bit of a number can be calculated using the formula `x & -x`.
  - Example: `x = 10 (1010)`, then `-x = -10 = 2's complement of 10 = complement of(10) + 1 = 0101 + 1 = (0110) ` and `x & -x = (0010)` which is the rightmost set bit.

- Removing the Rightmost Set Bit:
  - The rightmost set bit of a number can be removed using the formula `x = x - (x & -x)`.
  - Example: `x = 10 (1010)`, then `x & -x = (0010)` and `x - (x & -x) = 10 - 2 = 8`.

## Construction

### What Fenwick Tree Represents?

- Consider an array `arr` of length `n` and a Fenwick Tree or array `BIT` of length `n+1`.
- Every index of the BIT array represents the sum of elements from a particular range.
- The index `i` of the BIT array represents the sum of elements from index `j to i` of the original array `arr`.
- Index `j` can be calculated by removing the rightmost set bit from the index `i` and adding 1 to it, Therefore `j = i - (i & -i) + 1 `.

Example:

- Consider an array `arr = [1, 2, 3, 4, 5, 6, 7, 8]` and a BIT array of size 9 `BIT = [0, 0, 0, 0, 0, 0, 0, 0, 0]`.
- The BIT array will be updated as follows:
  - **Array is onebased Indexed aswell the BIT**
  - `BIT[1] = sum of elements from index 1 to 1 = 1`
  - `BIT[2] = sum of elements from index 1 to 2 = 3`
  - `BIT[3] = sum of elements from index 3 to 3 = 3`
  - `BIT[4] = sum of elements from index 1 to 4 = 10`
  - `BIT[5] = sum of elements from index 5 to 5 = 5`
  - `BIT[6] = sum of elements from index 5 to 6 = 11`
  - `BIT[7] = sum of elements from index 7 to 7 = 7`
  - `BIT[8] = sum of elements from index 1 to 8 = 36`
  - The BIT array will look like this: `BIT = [0, 1, 3, 3, 10, 5, 11, 7, 36]`.

## Now What to Do With BIT.

### Querying

- If we want to find the sum of elements from index 1 to 5, we can calculate it by :
  - Start from index 5 and keep removing the rightmost set bit and adding the BIT[i] value at that index to the sum.
  - Sum will represent the sum of elements from index 1 to 5.
  - i.e. `sum = BIT[5] + BIT[4] + BIT[0] = 5 + 10 + 0 = 15` Which is the sum of elements from index 1 to 5, (1 + 2 + 3 + 4 + 5 = 15).
  ```cpp
  int query(int index){
      int sum = 0;
      while(index > 0){
          sum += BIT[index];
          index = index - (index & -index);
      }
      return sum;
  }
  ```
- The time complexity of querying is O(logn).

- So the sum of elements from index `l` to `r` can be calculated by `sum = query(r) - query(l-1)`.

### Updating

- Now Think like you have created BIT , and you want to update the value at index `i` by `val` updating means adding `val` to the value at index `i` and updating the BIT array accordingly.
- To update the BIT array , Since, BIT array stores the sum of elements prior to that index, so updating the value at any index will affect the BIT array at that index and indexes after that index which contains sum which indcludes that element of array.
- So, to find the indexes which will be affected by updating the value at index `i`, we can calculate the indexes by adding the rightmost set bit to the index `i` and updating the BIT array at that index.

- Example:

  - Consider the array `arr = [1, 2, 3, 4, 5, 6, 7, 8]` and the BIT array `BIT = [0, 1, 3, 3, 10, 5, 11, 7, 36]`.
  - If we want to update the value at index 5 by 2, then the BIT array will be updated as follows:

    - `BIT[5] = BIT[5] + 2 = 5 + 2 = 7` then next index to update is `5 + (5 & -5) = 5 + 1 = 6`
    - `BIT[6] = BIT[6] + 2 = 11 + 2 = 13` then next index to update is `6 + (6 & -6) = 6 + 2 = 8`
    - `BIT[8] = BIT[8] + 2 = 36 + 2 = 38` then next index to update is `8 + (8 & -8) = 8 + 8 = 16` which is out of range.

    ```cpp
    void update(int index, int val){
        while(index <= n){
            BIT[index] += val;
            index = index + (index & -index);
        }
    }
    ```

- The time complexity of updating is O(logn).

## Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

void update(int index, int val, vector<int> &BIT)
{
    int n = BIT.size();
    while (index <= n)
    {
        BIT[index] += val;
        index = index + (index & -index);
    }
}

int query(int index, vector<int> &BIT)
{
    int sum = 0;
    while (index > 0)
    {
        sum += BIT[index];
        index = index - (index & -index);
    }
    return sum;
}

int main()
{
    cout << "Enter the size of array: ";
    int n;
    cin >> n;
    vector<int> arr(n + 1, 0);
    vector<int> BIT(n + 1, 0);

    cout << "Enter the elements of array: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        update(i, arr[i], BIT);
    }

    cout << "Enter the number of queries: ";
    int q;
    cin >> q;
    while (q--)
    {
        cout << "Enter the type of query (1 for update, 2 for query): ";
        int type;
        cin >> type;
        if (type == 1)
        {
            cout << "Enter the index and value to update: ";
            int index, val;
            cin >> index >> val;
            update(index, val, BIT);
        }
        else
        {
            cout << "Enter the left index : ";
            int l, r;
            cin >> l;
            cout << "Enter the right index : ";
            cin >> r;
            cout << "Sum of elements from l  " << l << " to " << r << " is: " << query(r, BIT) - query(l - 1, BIT) << endl;
        }
    }
}

```

## Applications

- [**Range Sum Queries**](/Femwick%20Tree/Implementation.cpp): Fenwick Tree can be used to find the sum of elements from index `l` to `r` in an array.
- [**Inversion Count**](/Femwick%20Tree/InversionCount.cpp): Fenwick Tree can be used to find the number of inversions in an array.
