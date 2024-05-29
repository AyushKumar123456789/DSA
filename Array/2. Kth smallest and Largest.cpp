// https://takeuforward.org/data-structure/kth-largest-smallest-element-in-an-array/

#include <bits/stdc++.h>
using namespace std;

/*
1. Approack : Sorting Time Complexity : O(NlogN)
2. Approach : Use Priority Queue Time Complexity: O(NlogK)
3. Approach : Use Pivot/Quick Sort , worst-case time complexity of this method is O(n^2) but its Average time complexity is O(n)
*/

// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function
int kthSmallest(int arr[], int l, int r, int k)
{
    priority_queue<int> pq;
    for (int i = l; i <= r; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    return pq.top();
}

/*
2. Approach : Use Quick Select Time Complexity: O(N)
The worst-case time complexity of this method is O(n^2) but its Average time complexity is O(n).
*/

int partition(vector<int> &arr, int left, int right)
{
    int pivot = arr[left];
    int l = left + 1;
    int r = right;
    while (l <= r)
    {
        if (arr[l] < pivot && arr[r] > pivot)
        {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
        if (arr[l] >= pivot)
        {
            l++;
        }
        if (arr[r] <= pivot)
        {
            r--;
        }
    }
    swap(arr[left], arr[r]);
    return r;
}

int kth_Largest_Element(vector<int> &arr, int k)
{
    int left = 0, right = arr.size() - 1, kth;
    while (1)
    {
        int idx = partition(arr, left, right);
        if (idx == k - 1)
        {
            kth = arr[idx];
            break;
        }
        if (idx < k - 1)
        {
            left = idx + 1;
        }
        else
        {
            right = idx - 1;
        }
    }
    return kth;
}
