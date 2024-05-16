//https://www.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
/*
FIRST DO LCS BEFORE THIS
*/


#include <bits/stdc++.h>
using namespace std;


/*
CODE IS SIMILAR TO LCS just one change , SKIP THE ITERATION WHEN i==j , because we are looking for repeating subsequence with no same index in string from which it is derived
*/
    int LongestRepeatingSubsequence(string str){
    int n = str.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)continue;
            if(str[i-1]==str[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]));
                
            }
            ans = max(ans,dp[i][j]);
        }
    }

    return ans;
    }
//Time Complexity: O(n*n)
//Space Complexity: O(n*n)

//SPACE OPTIMIZATION

		int LongestRepeatingSubsequence(string str){
		int n = str.size();
        vector<int>curr(n+1,0);
        vector<int>prev(n+1,0);
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j)continue;
                if(str[i-1]==str[j-1]){
                    curr[j] =prev[j-1] + 1;
                }
                else{
                    curr[j] = max(prev[j],max(curr[j-1],prev[j-1]));
                    
                }
                ans = max(ans,prev[j]);
            }
            prev = curr;
        }
        for(int i=1;i<=n;i++)
        {
            ans = max(ans,prev[i]);//Last row KO alag se calculate karna padega yani DP[n][1....n] me se max nikalna padega agar uper se compare kare to
        }

        return ans;
		}

//Time Complexity: O(n*n)
//Space Complexity: O(n)