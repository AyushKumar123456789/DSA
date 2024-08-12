// https://www.geeksforgeeks.org/problems/buy-maximum-stocks-if-i-stocks-can-be-bought-on-i-th-day/1

/*
Very Easy Question


You are given an array prices where prices[i] is the price of a given stock on the ith day and you can buy at most i stock on ith day.
You dont have to sell the stock just the max number of stock you can buy .
*/

#include <bits/stdc++.h>
using namespace std;

int buyMaximumProducts(int n, int k, int price[])
{
    vector<pair<int, int>> price_index(n);
    for (int i = 0; i < n; i++)
    {
        price_index[i] = {price[i], i + 1};
    }
    sort(price_index.begin(), price_index.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int val = price_index[i].first;
        int cnt = price_index[i].second;
        int max_buy = k / val;
        int buy = min(cnt, max_buy);
        ans += (buy);
        k -= (buy * val);
        if (k <= 0)
            break;
    }
    return ans;
}