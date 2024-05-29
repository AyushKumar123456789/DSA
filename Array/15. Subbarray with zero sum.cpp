// https://www.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1

/*
Time Complexity: O(N)
Space Complexity: O(N)

Approach: Prefix array concept used , if any of prefix sum = total + arr[current index] then there is a subarray with sum 0. Keep in mind you should not add the total in
the heap before checking if it is present in the heap or not.
*/

#include <bits/stdc++.h>
using namespace std;

bool subArrayExists(int arr[], int n)
{
    unordered_map<int, int> val;
    int total = 0;
    val[0] = 1;
    for (int i = 0; i < n; i++)
    {
        total += arr[i];
        if (val[total] != 0)
        {
            return 1;
        }
        val[total] = 1;
    }
    return 0;
}