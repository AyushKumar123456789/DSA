// https://leetcode.com/problems/minimum-path-sum/description/

/*

Problem:
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
And you can only move either down or right at any point in time.

Easily we can solve this problem using DP.
1. DP[i][j] represents the minimum path sum from grid[0][0] to grid[i][j]
2. At i,j we can come from i-1,j or i,j-1
3. So, DP[i][j] = min(DP[i-1][j],DP[i][j-1]) + grid[i][j]
4. Base case is DP[0][0] = grid[0][0]
5. DP[0][j] = DP[0][j-1] + grid[0][j] , DP[i][0] = DP[i-1][0] + grid[i][0]


*/

#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int i = 1; i < m; i++)
    {
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[n - 1][m - 1];
}