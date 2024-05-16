//https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

#include <bits/stdc++.h>
using namespace std;

//Directly GO to iterative solution

//Time Complexity: O(n*m)
//Space Complexity: O(n*m)

// https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

    int lcs(int n, int m, string s1, string s2)
    {
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        bool check = 0;
        for(int i=0;i<m;i++)
        {
            if(s1[0]==s2[i] || check){
                dp[0][i] = 1;
                check = 1;
            }
        }
        check = 0;
        for(int i=0;i<n;i++)
        {
            if(s1[i]==s2[0] || check)
            {
                dp[i][0] = 1;
                check  = 1;
            }
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(s1[i]==s2[j]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                    dp[i][j] = max(dp[i][j],max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1])));
                    /*
                    other way to write above line
                    else{
                        dp[i][j] = max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1])); 
                    }
                    */
            }
        }

        return dp[n-1][m-1];
    }

/*
Intution:
1. DP[i][j] represents the LCS of s1[0...i] and s2[0...j] , either including s1[i] and s2[j] or not including s1[i] and s2[j]
2. Itertion ; 
    a. If s1[i] == s2[j] , then DP[i][j] = DP[i-1][j-1] + 1 ; If letter are same then we can add 1 to lcs of s1[0...i-1] and s2[0...j-1]
    b. Else DP[i][j] = max(DP[i-1][j],DP[i][j-1],DP[i-1][j-1]) ; If letter are not same then we take max of lcs of s1[0...i-1] and s2[0...j] , s1[0...i] and s2[0...j-1] , s1[0...i-1] and s2[0...j-1]
*/

//We can Remove base case from above code by Shifting the indexs of both strings

    int lcs(int n, int m, string s1, string s2)
    {
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
   
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]));
                    
                }
            }
        }

        return dp[n][m];
    }

//Time Complexity: O(n*m)
//Space Complexity: O(n*m)

//Space optimization

    int lcs(int n, int m, string s1, string s2)
    {
        vector<int>curr(m+1,0);
        vector<int>prev(m+1,0);
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1]){
                    curr[j] =prev[j-1] + 1;
                }
                else{
                    curr[j] = max(prev[j],max(curr[j-1],prev[j-1]));
                    
                }
            }
            prev = curr;
        }

        return prev[m];
    }

//Time Complexity: O(n*m)
//Space Complexity: O(m)

