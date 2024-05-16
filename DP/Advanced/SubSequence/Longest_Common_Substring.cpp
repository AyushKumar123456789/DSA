//https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

#include <bits/stdc++.h>
using namespace std;

//FIRST GO WITH BASIC CONSTRUCTIVE SOLUTION

int longestCommonSubstr (string S1, string S2, int n, int m)
{
    
    unordered_map<string,bool>str2;
    for(int i=0;i<m;i++)
    {
        string temp = "";
        for(int j=i;j<m;j++)
        {
            temp.push_back(S2[j]);
            str2[temp] = 1;
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        string temp = "";
        for(int j=i;j<n;j++)
        {
            temp.push_back(S1[j]);
            if(str2[temp])
            {
                ans = max(ans,j-i+1);
            }
        }
    }
    return ans;
}

//Time Complexity: O(n*n + m*m)
//Space Complexity: O(m*m)

/*
APPROACH: (Isme DP[i][j] k defination common LCS se alag hota h)
1. Agar DP[i][j] max substring length from S1[0...i] and S2[0...j] hai toh, we can't write relation between DP[i][j] and its previoius value because DP[i][j] can't take in acocount of continous string.
2. To DP[i][j] k dusra defination use krna pdega , DP[i][j] represent max substring length from S1[0...i] and S2[0...j] such that S1[i] & S2[j] ko lia gya hai substring bnane m , 
kyonki fir hm likh skte hai dp[i][j] = dp[i-1][j-1] + 1 -> if(s1[i]==s2[j]) , or agar not equal ho to dp[i][j] = 0 hoga to 
3. Ans wo 2D DP array k max value hoga    
*/

    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(S1[i-1]==S2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = 0;
                }
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }

//Time Complexity : O(n*m)
//Space Complexity : O(n*m)

//Space Optimizatoin Can be Done

    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<int>prev(m+1,0);
        vector<int>curr(m+1,0);
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(S1[i-1]==S2[j-1])
                {
                    curr[j] = prev[j-1] + 1;
                }
                else{
                    curr[j] = 0;
                }
                ans = max(ans,curr[j]);
            }
            prev = curr;
        }
        for(int i=1;i<=m;i++)
        {
            ans = max(ans,prev[i]);
        }
        return ans;
    }
    
//Time Complexity : O(n*m)
//Space Complexity : O(m)
