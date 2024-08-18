#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

/*

Easy Peasy Lemon Squeezy Problem

Just Dont forget that :
 dp[i][val] = dp[i][val] || dp[i - 1][val - arr[i]]; not  dp[i][val] = dp[i][val] || dp[i][val - arr[i]]; (My Common Mistake)
 AND
 in base case dont forget to check if arr[i] <= sum then dp[i][arr[i]] = 1;

*/

int equalPartition(int N, int arr[])
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
    }
    if (sum % 2 == 1)
    {
        return 0;
    }
    sum /= 2;
    vector<vector<int>> dp(N + 1, vector<int>(sum + 1, 0));
    for (int i = 0; i < N; i++)
    {
        dp[i][0] = 1;
        if (arr[i] <= sum)
        {
            dp[i][arr[i]] = 1;
        }
    }

    for (int i = 1; i < N; i++)
    {
        for (int val = 0; val <= sum; val++)
        {
            if (val >= arr[i])
            {
                dp[i][val] = dp[i][val] || dp[i - 1][val - arr[i]];
            }
            dp[i][val] = dp[i][val] || dp[i - 1][val];
        }
    }
    return dp[N - 1][sum];
}