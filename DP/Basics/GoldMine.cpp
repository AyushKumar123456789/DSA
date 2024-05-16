//https://www.geeksforgeeks.org/problems/gold-mine-problem2608/1

#include <bits/stdc++.h>
using namespace std;

/*
    For this type of questions directly GO for iterative approach
*/

    int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++)
        {
            dp[i][0] = M[i][0];
        }
        int ans = 0;
        for(int col=1;col<m;col++)
        {
            for(int row=0;row<n;row++)
            {
                int val = 0;
                if(row-1>=0 && row-1<n && col-1>=0 && col-1<m)
                {
                    val = max(val,dp[row-1][col-1]);
                }
                if(row+1>=0 && row+1<n && col-1>=0 && col-1<m)
                {
                    val = max(val,dp[row+1][col-1]);
                }
                if(col-1>=0 && col-1<m)
                {
                    val = max(val,dp[row][col-1]);
                }
                dp[row][col]= M[row][col] + val;
                if(col==m-1){
                    ans = max(ans,dp[row][col]);
                }
            }
        }
        return ans;
    }

//Time Complexity: O(n*m)
//Space Complexity: O(n*m)

//Space optimization just use two 1D vector of size ROw

    int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<int>prev(n+1,0);
        vector<int>curr(n+1,0);
        for(int i=0;i<n;i++)
        {
            prev[i] = M[i][0];
        }
        int ans = 0;
        for(int col=1;col<m;col++)
        {
            for(int row=0;row<n;row++)
            {
                int val = 0;
                if(row-1>=0 && row-1<n )
                {
                    val = max(val,prev[row-1]);
                }
                if(row+1>=0 && row+1<n )
                {
                    val = max(val,prev[row+1]);
                }
                if(row>=0 && row<n)
                {
                    val = max(val,prev[row]);
                }
                curr[row]= M[row][col] + val;
                if(col==m-1){
                    ans = max(ans,curr[row]);
                }
            }
            prev = curr;
        }
        return ans;
    }

//Time Complexity: O(n*m)
//Space Complexity: O(row)