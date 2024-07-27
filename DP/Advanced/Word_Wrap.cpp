// https://www.geeksforgeeks.org/problems/word-wrap1646/1

/*
Logic :

    You can add break anywhere, so we try to add and not add break every where

*/

#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &nums, vector<int> &pre, int k, int last_break, int idx, vector<vector<int>> &dp)
{
    // last_break will be from before index to idx
    if (idx == nums.size() - 1)
    {
        int add_letter = pre[idx + 1] - pre[last_break] + (idx - last_break);
        if (add_letter <= k)
        {
            return 0;
        }
        return INT_MAX;
    }
    if (dp[last_break][idx] != -1)
    {
        return dp[last_break][idx];
    }

    int add_letter = pre[idx + 1] - pre[last_break] + (idx - last_break);
    int break_idx = INT_MAX;
    if (add_letter <= k)
    {
        int next = f(nums, pre, k, idx + 1, idx + 1, dp);
        if (next != INT_MAX)
        {
            break_idx = next + (k - add_letter) * (k - add_letter);
        }
    }
    int no_break = f(nums, pre, k, last_break, idx + 1, dp);

    return dp[last_break][idx] = min(break_idx, no_break);
}

int solveWordWrap(vector<int> nums, int k)
{
    int n = nums.size();
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + nums[i - 1];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    int ans = f(nums, pre, k, 0, 0, dp);
    return ans;
}

int wordWrapIterative(vector<int> &nums, int k)
{
    /*
        Iterative approach is going to be little bit tricky,
        We have to form 2 DP array
        1. A 2D dp which is dp[i][j] , which stores the minimum cost to create word wrap such that index j is the last index where break happens it taking index j to i
        inculding in one wrap
        2. A 1D dp which is cost[i] , which stores the minimum cost to create word wrap upto to index i , it will stoes the answer of each index.

        Now, iteration dp[i][j] = wrap from j to i if possible + cost[j-1] , now due to indexing we cant do j-1 so , for j==0 cost[j-1] =0
        and one edge case is last wrap will be of zero cost .

        there is no need of initialization , making INT_MAX every index is enough
    */
    int n = nums.size();
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        pre[i + 1] = pre[i] + nums[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
    vector<int> cost(n, INT_MAX);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int add_letter = pre[i + 1] - pre[j] + (i - j);
            int cost_adding = INT_MAX;
            if (i == n - 1 && add_letter <= k)
            {
                cost_adding = 0;
                if (j - 1 >= 0)
                {
                    dp[i][j] = cost_adding + cost[j - 1];
                }
                else
                {
                    dp[i][j] = cost_adding;
                }
            }
            else if (add_letter <= k)
            {
                cost_adding = (k - add_letter) * (k - add_letter);
                if (j - 1 >= 0)
                {
                    dp[i][j] = cost_adding + cost[j - 1];
                }
                else
                {
                    dp[i][j] = cost_adding;
                }
            }

            cost[i] = min(cost[i], dp[i][j]);
        }
        // cout<<i<<" = "<<cost[i]<<endl;
    }
    return cost[n - 1];
}

int main()
{
    vector<int> nums = {6, 6, 7, 4, 4};
    int k = 9;
    // cout << solveWordWrap(nums, k);
    cout << wordWrapIterative(nums, k) << endl;
    return 0;
}

// Time Complexity: O(N^2)
// Space Complexity: O(N^2) + O(N)  = O(N^2)
