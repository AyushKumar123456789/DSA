// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

/*
Question:
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You can complete at most one transaction, i.e., buy one and sell one share of the stock.

Very Easy Question.
*/

int maxProfit(vector<int> &prices)
{
    int mini = 1e9;
    int ans = -1e9;
    for (int i = 0; i < prices.size(); i++)
    {
        mini = min(mini, prices[i]);
        ans = max(ans, prices[i] - mini);
    }
    return ans;
}
