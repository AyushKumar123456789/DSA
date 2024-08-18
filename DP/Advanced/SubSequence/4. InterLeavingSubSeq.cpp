// https://leetcode.com/problems/interleaving-string/description/

/*

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Good Question 2D DP, dont go for 3d DP, it will be a waste of time.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int n = s1.size();
        int m = s2.size();
        int c = s3.size();

        if (c != n + m)
        {
            return false;
        }

        // dp[i][j] -> Does string s3 upto index i+j-1, can be formed by s1 upto index i-1 and s2 upto index j-1
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;

        // Fill the first row (s1 is empty)
        for (int j = 1; j <= m; j++)
        {
            dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
        }

        // Fill the first column (s2 is empty)
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        }

        // Fill the rest of the DP table
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                           (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }

        return dp[n][m];
    }
};
