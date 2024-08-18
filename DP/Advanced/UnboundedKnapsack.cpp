// https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

/*
Greedy approach will not work here as we can take the same item multiple times.

*/

#include <bits/stdc++.h>
using namespace std;

int knapSack(int N, int W, int val[], int wt[])
{
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            int take = 0;
            if (j >= wt[i])
            {
                take = dp[i][j - wt[i]] + val[i];
            }
            int not_take = 0;
            if (i > 0)
            {
                not_take = dp[i - 1][j];
            }
            dp[i][j] = max(not_take, take);
        }
    }
    return dp[N - 1][W];
}
