// https://www.geeksforgeeks.org/problems/smallest-sum-contiguous-subarray/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include <bits/stdc++.h>
using namespace std;

/*
Easy Peasy Lemon Squeezy

Problem Statement:
Given an array containing both negative and positive integers. Find the contiguous sub-array with the smallest sum.

Approach:
Using Kadane's Algorithm
Make negative elements positive and positive elements negative , and apply Kadane's Algorithm and return negative of max sum.
*/
int smallestSumSubarray(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {

        a[i] = -a[i];
    }
    int sum = -1000000;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += a[i];
        sum = max(sum, ans);
        if (ans < 0)
        {
            ans = 0;
        }
    }
    return -sum;
}

int main()
{
    vector<int> a = {3, -4, 2, -3, -1, 7, -5};
    cout << smallestSumSubarray(a) << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)

// Input:
// 7
// 3 -4 2 -3 -1 7 -5
// Output:
// -6