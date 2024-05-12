//Memoization on febonacii

#include<bits/stdc++.h>

using namespace std;

int dp[1000] = {0};
//Bottom Up approach
int fib(int n, int dp[]){
    if(n==0 || n==1){
        return n;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int ans;
    ans = fib(n-1, dp) + fib(n-2, dp);
    return dp[n] = ans;
}

//Top Down approach
int fib_top_down(int n){
    int dp[3] = {0};
    dp[0] = 0;
    dp[1] = 1;
    //because we only need last two values
    for(int i=2; i<=n; i++){
        dp[i%3] = dp[(i-1)%3] + dp[(i-2)%3];
    }
    return dp[n%3];
}