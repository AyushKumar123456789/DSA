//https://leetcode.com/discuss/general-discussion/1349122/friends-pairing-problem

#include <bits/stdc++.h>
using namespace std;


/*
LOGIC:

f(n) = ways n people can remain single 
       or pair up.

For n-th person there are two choices:
1) n-th person remains single, so only 1 way so  we recur 
   for remaining i.e f(n - 1)   or you can say 1*f(n-1)
2) n-th person pairs up with any of the 
   remaining n - 1 persons. So apart from the 2 people forming a pair for remaining n-2 persons we We get (n - 1) * f(n - 2) ways

Therefore we can recursively write f(n) as:
f(n) = f(n - 1) + (n - 1) * f(n - 2)
*/

// Recursive

    int countFriendsPairings(int n) 
    { 
        if(n==1 || n==2){
            return n;
        }
        return countFriendsPairings(n-1) + (n-1)*countFriendsPairings(n-2);
    }

//Time Complexity: O(2^n)
//Space Complexity: O(n) Recursive Stack

// Memoization

      long long int f(long long int n,vector<long long int>&dp)
    {
        if(n<=2){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n] = (f(n-1,dp)%(1000000007ll) + (n-1)*f(n-2,dp)%(1000000007ll))%(1000000007ll);
    }
    
    int countFriendsPairings(int n) 
    { 
        vector<long long int>dp(n+1,-1);
        long long int ans = f(n,dp);
        return ans;
    }

//Time Complexity: O(n)
//Space Complexity: O(n) + O(n) recursive stack

// Tabulation

    int countFriendsPairings(int n) 
    { 
        vector<long long int>dp(n+1,-1);
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<=n;i++){
            dp[i] = (dp[i-1]%(1000000007ll) + (i-1)*dp[i-2]%(1000000007ll))%(1000000007ll);
        }
        return dp[n];
    }

//Time Complexity: O(n)
//Space Complexity: O(n)

// Optimized

    int countFriendsPairings(int n) 
    { 
        long long int a = 1;
        long long int b = 2;
        long long int c;
        if(n<=2){
            return n;
        }
        for(int i=3;i<=n;i++){
            c = (b%(1000000007ll) + (i-1)*a%(1000000007ll))%(1000000007ll);
            a = b;
            b = c;
        }
        return c;
    }