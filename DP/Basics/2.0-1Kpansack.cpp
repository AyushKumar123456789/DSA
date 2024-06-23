// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

// Recursive -> top down

#include <bits/stdc++.h>
using namespace std;

int f(int w, vector<int> &weight, vector<int> &value, int idx, vector<vector<int>> &dp)
{
    if (idx < 0)
    {
        return 0;
    }
    if (dp[idx][w] != -1)
    {
        return dp[idx][w];
    }
    int take = 0;
    if (weight[idx] <= w)
    {
        take = (value[idx] + f(w - weight[idx], weight, value, idx - 1, dp));
    }
    int not_take = f(w, weight, value, idx - 1, dp);
    return dp[idx][w] = max(take, not_take);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, -1));
    int ans = f(maxWeight, weight, value, n - 1, dp);
    return ans;
}

// Time Complexity: O(N*W) where N is the number of items and W is the capacity of the knapsack.
// Space Complexity: O(N*W) + O(N) , We are using a recursion stack space(O(N)) and a 2D array ( O(N*W)).

// Iterative -> bottom up

int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 0; i <= W; i++)
    {
        if (i >= wt[0])
        {
            dp[0][i] = val[0];
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            int take = 0;
            if (j >= wt[i])
            {
                take = dp[i - 1][j - wt[i]] + val[i];
            }
            int not_take = dp[i - 1][j];
            dp[i][j] = max(take, not_take);
        }
    }
    return dp[n - 1][W];
}
// Space optimization in iterative approach

int knapSack(int W, int wt[], int val[], int n)
{
    vector<int> prev(W + 1, 0);
    vector<int> curr(W + 1, 0);
    for (int i = 0; i <= W; i++)
    {
        if (i >= wt[0])
        {
            prev[i] = val[0];
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            int take = 0;
            if (j >= wt[i])
            {
                take = prev[j - wt[i]] + val[i];
            }
            int not_take = prev[j];
            curr[j] = max(take, not_take);
        }
        prev = curr;
    }
    return prev[W];
}

// Time Complexity: O(N*W) where N is the number of items and W is the capacity of the knapsack.
// Space Complexity: O(W) , We are using a 1D array O(W).