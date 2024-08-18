#include <bits/stdc++.h>
using namespace std;

/*
Took Time and Good Question:

Easy two line code but need to think about it.

Do again

*/

// https://www.geeksforgeeks.org/problems/cutted-segments1642/1

int maximizeTheCuts(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i - x >= 0 && dp[i - x] != -1)
        {
            dp[i] = max(dp[i], dp[i - x] + 1);
        }
        if (i - y >= 0 && dp[i - y] != -1)
        {
            dp[i] = max(dp[i], dp[i - y] + 1);
        }
        if (i - z >= 0 && dp[i - z] != -1)
        {
            dp[i] = max(dp[i], dp[i - z] + 1);
        }
    }
    return max(0, dp[n]);
}