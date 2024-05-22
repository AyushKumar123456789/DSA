// https://www.naukri.com/code360/problems/minimum-cash-flow_975372?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTabValue=PROBLEM

/*
Simple Approach: Find the net amount get or give by each person.
And don't forget to divide the final answer by 2 because the final answer is the sum of all the transactions and each transaction is counted twice.
*/

#include <bits/stdc++.h>
using namespace std;

int minCashFlow(vector<vector<int>> &money, int n)
{

    vector<int> val(n, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            val[i] += (money[i][j] - money[j][i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(val[i]);
    }
    return ans / 2;
}
