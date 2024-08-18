// https://www.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

#include <bits/stdc++.h>
using namespace std;

/*
Things to remember:
Don't forget initialisation of dp[0] = arr[0] and ans = arr[0] & taking ans = max(ans,dp[i]) in the end
*/

int maxSumIS(int arr[], int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = arr[0];
    int ans = arr[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = arr[i];
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}