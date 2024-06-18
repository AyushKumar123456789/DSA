#include <bits/stdc++.h>
using namespace std;

/*
Also , Done using Priority Queue
Create a priority queue and keep inserting elements into it, when the size of the priority queue becomes greater than k,
then pop the top element.

For Kth largest element, Use Min priority queue
For Kth smallest element, Use Max priority queue
*/

void heapify(vector<int> &nums, int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < n && nums[largest] < nums[left])
    {
        largest = left;
    }
    if (right < n && nums[largest] < nums[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(nums[largest], nums[i]);
        heapify(nums, n, largest);
    }
}
int findKthLargest(vector<int> &nums, int k)
{
    int n = nums.size();
    for (int i = n - 1; i >= 0; i--)
    {
        heapify(nums, n, i);
    }
    for (int i = 0; i < k - 1; i++)
    {
        nums[0] = nums[n - 1 - i];
        heapify(nums, n - i, 0);
    }
    return nums[0];
}

int main()
{
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << findKthLargest(nums, k) << endl;
    return 0;
}