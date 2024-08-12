// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <bits/stdc++.h>
using namespace std;

/*
Easy Peasy

Given an array prices where prices[i] is the price of a given stock on the ith day, return the maximum profit you can achieve.
You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Approach:
1. We will iterate over the array and if the current price is greater than the previous price, we will add the difference to the profit.
2. We will return the profit.

*/

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int ans = 0;
    int mini = prices[0];
    for (int i = 1; i < n; i++)
    {
        if (prices[i] > mini)
        {
            ans += (prices[i] - mini);
        }
        mini = prices[i];
    }
    return ans;
}