// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

#include <bits/stdc++.h>
using namespace std;

/*
Good Question Solve Again

Question : Buy and Sell Stock , atmost k transactions.
*/

/*
Approach:
1. If k >= n/2, then we can make as many transactions as we want.
2. If k < n/2, then we can use the same approach as Buy and Sell Stock III, but with a slight modification.
3. We can use a 2D dp array, where dp[i][j] represents the maximum profit that can be made with atmost i transactions till jth day.
4. dp[i][j] = max(dp[i][j-1], prices[j] + maxDiff), where maxDiff = max(maxDiff, dp[i-1][j] - prices[j])
here maxDiff is the maximum difference that can be made with atmost i-1 transactions till jth day. This technique is used to remove the use of two for loop of n size.

Why add maxDiff to prices[j]?
- If we buy the stock at prices[j], then we can sell it at prices[j] + maxDiff, which will give us the maximum profit till jth day with atmost i transactions.
- If we don't buy the stock at prices[j], then we can sell it at prices[j-1], which will give us the maximum profit till j-1th day with atmost i transactions.
*/

int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    if (n == 0)
        return 0;
    if (k >= n / 2)
    {
        int profit = 0;
        for (int i = 1; i < n; i++)
        {
            if (prices[i] > prices[i - 1])
            {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
    vector<vector<int>> dp(k + 1, vector<int>(n, 0));
    for (int i = 1; i <= k; i++)
    {
        int maxDiff = -prices[0];
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = max(dp[i][j - 1], prices[j] + maxDiff);
            maxDiff = max(maxDiff, dp[i - 1][j] - prices[j]);
        }
    }
    return dp[k][n - 1];
}