// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include <bits/stdc++.h>
using namespace std;

/*
Find the maximum profit you can achieve. You may complete at most two transactions.
*/

/*

Easy Pesy Ass Squeezy

Approach:
1. Create a vecotr rt_profit which stores the max profit that can be mad if buy and sell happend on from index i to n-1
2. Again run a iteration from 0 to n-1 , which calculate the ans by making transaction buying min and selling at index i and adding it to rt_profit[i]
*/

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int maxi = prices[n - 1];
    vector<int> rt_profit(n, 0);
    for (int i = n - 2; i >= 0; i--)
    {
        rt_profit[i] = max(rt_profit[i + 1], maxi - prices[i]);
        maxi = max(maxi, prices[i]);
    }
    int mini = prices[0];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, rt_profit[i] + max(0, prices[i] - mini));
        mini = min(mini, prices[i]);
    }
    return ans;
}