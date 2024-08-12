/*
Problem statement: You are given an array prices where prices[i] is the price of a given stock on the ith day,
and an integer fee representing a transaction fee.

Approach: Use DP to solve the problem.

    dp[i][0] -> max profit upto index i and you dont have any stock to sell , So that you can either buy or not buy
    dp[i][1] -> max profit upto index i and you have a stock to sell,  So you can either sell or not sell
    transition :
        dp[i][0] = max(prices[i] + dp[i-1][1],dp[i-1][0]) ; Either you not buy and carry the profit of last index or you sell the stock at ith index that you bought at some previous index.
        dp[i][1] = max(dp[i][0] - prices[i] - fee,dp[i-1][1]) ; Either you carry the un-sold stock of last index or you buy a new stock at ith index and sell later.

    Base Case :
        dp[0][0] -> 0
        dp[0][1] -> -prices[0] - fee
*/

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

// Easy but Nice Question , Do again during revision

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[0][1] = -prices[0] - fee;
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(prices[i] + dp[i - 1][1], dp[i - 1][0]);
        dp[i][1] = max(dp[i - 1][1], dp[i][0] - prices[i] - fee);
    }
    return dp[n - 1][0];
}

int main()
{
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << maxProfit(prices, fee) << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)

// Test case 1:
// prices = {1, 3, 2, 8, 4, 9}
// fee = 2
// Output: 8