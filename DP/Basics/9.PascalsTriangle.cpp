//https://leetcode.com/problems/pascals-triangle/submissions/1256164614/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>dp(numRows);
        dp[0].push_back(1);
        for(int i=2;i<=numRows;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(j==0 || j==i-1)
                {
                    dp[i-1].push_back(1);
                }
                else{
                    dp[i-1].push_back(dp[i-2][j-1] + dp[i-2][j]);
                }
            }
        }
        return dp;

    }
};