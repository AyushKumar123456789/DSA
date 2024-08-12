// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

// dp[i][0]-> max profit upto index i such that you stil have to sell that you buyed in past.
// dp[i][1]-> max profit upto index i such that you dont have stock to sold and cooling down on yhis index
// dp[i][2]-> max profit upto index i such that index cooldown period of 1 day is passed.
/*
Transition :
dp[i][0] = max(dp[i-1][0],dp[i-1][2] - prices[i])
dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
// Sold state of previous day
dp[i][2] = dp[i - 1][1];

Base Case:
dp[0][0] -> max profit upto index 0 such that not sell at index 0 so,
dp[0][0] = 0 dp[0][1] -> max profit upto index 0 such that sell at index
0, so dp[0][1] = 0;
*/

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    dp[0][0] = -prices[0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        dp[i][2] = dp[i - 1][1];
    }
    return max(dp[n - 1][0], dp[n - 1][1]);
}