/*
Problem : You can buy and sell stock at most 2 times. Find the maximum profit. And you can't buy stock before selling it.

Logic :
1. Create 2 arrays, left and right. left[i] will store the maximum profit that can be made by buying and selling stock from 0 to i.
2. right[i] will store the maximum profit that can be made by buying and selling stock from i to n-1.
3. To calculate right[i] run loop from n-2 to 0 and keep track of maximum stock price from i to n-1 - prices[i]. and maximum value of it will be stored in right[i].
4. left[i] will store the maximum profit that can be made by buying and selling stock from 0 to i.
5. To calculate left[i] run loop from 1 to n-1 and keep track of minimum stock price from 0 to i - prices[i]. and maximum value of it will be stored in left[i].
6. Now run a loop from 0 to n-1 and find the maximum of left[i] + right[i] and store it in ans.
*/

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    if (n == 0)
        return 0;
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    int minPrice = prices[0];
    for (int i = 1; i < n; i++)
    {
        minPrice = min(minPrice, prices[i]);
        left[i] = max(left[i - 1], prices[i] - minPrice);
    }
    int maxPrice = prices[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        maxPrice = max(maxPrice, prices[i]);
        right[i] = max(right[i + 1], maxPrice - prices[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, left[i] + right[i]);
    }
    return ans;
}

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << maxProfit(prices) << endl;
    return 0;
}