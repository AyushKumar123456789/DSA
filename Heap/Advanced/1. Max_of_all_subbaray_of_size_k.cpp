/*
Given an array and an integer K, find the maximum for each and every contiguous subarray of size K.
*/

/*
Approach 1 :
Using Heap (Priority Queue)
Time Complexity : O(nlogn)
Space Complexity : O(n) , where N is the size of the array, this method requires O(N) space in the worst case when the input array is an increasing array
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> result;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push({nums[i], i});
    }
    result.push_back(pq.top().first);
    for (int i = k; i < nums.size(); i++)
    {
        pq.push({nums[i], i});
        while (pq.top().second <= i - k)
        {
            pq.pop();
        }
        result.push_back(pq.top().first);
    }
    return result;
}

/*
Approach 2 :
Decrease space complexity by using set. becuase it can remove , kth element in O(logn) time.
Time Complexity : O(nlogn)
Space Complexity : O(k)
*/

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> result;
    set<pair<int, int>> s;
    for (int i = 0; i < k; i++)
    {
        s.insert({nums[i], i});
    }
    result.push_back(s.rbegin()->first);
    for (int i = k; i < nums.size(); i++)
    {
        s.insert({nums[i], i});
        s.erase({nums[i - k], i - k});
        result.push_back(s.rbegin()->first);
    }
    return result;
}

/*
Approach 3 :
Using Deque
Time Complexity : O(n)
Space Complexity : O(k)

Logic :
1. We will use deque to store the index of the elements in the window.
2. We will keep the deque in decreasing order of the elements by removing the elements which are smaller than the current element.
3. We will remove the elements which are out of the window.
4. The front of the deque will have the maximum element of the window.

*/

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> result;
    deque<int> dq;
    // First run a for loop from 0 to min(k, n) and store the index of the elements in the deque.
    // Store the index of the elements in the deque in decreasing order from front to back while going ahead in index because any element that is smaller than element at
    // index ith and lies before index i there is no use for it becuase it was taken out from the window before ith element, so that the front of the deque will have the maximum element of the window.
    for (int i = 0; i < min(k, (int)nums.size()); i++)
    {
        while (!dq.empty() && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    // Now run a for loop from k to n and do the following:
    // 1. Store the front of the deque in the result vector.
    // 2. Run first while loop and Remove the elements which are out of the window from the front of the deque(i.e. the elements which are less than or equal i-k).
    // 3. Run second while loop and Remove the elements which are smaller than the current element from the back of the deque.
    // 4. Push the current element index in the deque.
    for (int i = k; i < nums.size(); i++)
    {
        result.push_back(nums[dq.front()]);
        while (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    result.push_back(nums[dq.front()]);
    return result;
}