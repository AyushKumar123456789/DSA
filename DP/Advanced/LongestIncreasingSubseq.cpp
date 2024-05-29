// https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

// Directly GO to iterative approach
/*
IMPORTANT : Vector initialization is different ans for Max you have to go to every take and not_take
*/

#include <bits/stdc++.h>
using namespace std;

int longestSubsequence(int n, int a[])
{
    vector<int> take(n, 1);
    vector<int> not_take(n, 0);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
            {
                take[i] = max(take[i], take[j] + 1);
            }
            else
            {
                not_take[i] = max(not_take[i], not_take[j]);
            }
        }
    }

    return max(*max_element(take.begin(), take.end()), *max_element(not_take.begin(), not_take.end()));
}

// Time Complexity : O(N^2)
// Space Complexity : O(N)

// Time Complexity Can be reduced to O(NlogN) using Binary Search Approach
// https://www.youtube.com/watch?v=on2hvxBXJH4

int longestSubsequence(int n, int a[])
{
    vector<int> arr;
    arr.push_back(a[0]);
    for (int i = 1; i < n; i++)
    {
        if (a[i] > arr.back())
        {
            arr.push_back(a[i]);
        }
        else
        {
            int idx = lower_bound(arr.begin(), arr.end(), a[i]) - arr.begin();
            arr[idx] = a[i];
        }
    }
    return arr.size();
}

// Time Complexity : O(NlogN)
// Space Complexity : O(N)
