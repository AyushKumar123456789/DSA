//https://www.geeksforgeeks.org/problems/coin-change2448/1


//Recursive Solution -> Top Down

long long int f(int coins[],int idx,int sum,vector<vector<long long int>>&dp)
{
    if(idx<0){
        if(sum==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    
    if(dp[idx][sum]!=-1){
        return dp[idx][sum];
    }
    
    long long int take = 0;
    long long int temp = sum;
    while(sum>=coins[idx])
    {
        sum-=coins[idx];
        take+=f(coins,idx-1,sum,dp);
    }
        long long int not_take = f(coins,idx-1,temp,dp);
    return dp[idx][temp] = take+not_take;
}

long long int count(int coins[], int N, int sum) {
    vector<vector<long long int>>dp(N+1,vector<long long int>(sum+1,-1));
    long long int ans = f(coins,N-1,sum,dp);
    return ans;
}

//Time Complexity: O(N*sum) where N is the number of coins and sum is the amount.
//Space Complexity: O(N*sum) + O(N) , We are using a recursion stack space(O(N)) and a 2D array ( O(N*sum)).


//Iterative Solution -> Bottom Up

//For Iterative solution, 
//We first think of that DP[i][j] will store the number of ways to form amount j using first i coins.
//Then we think of the base case, if we can use only index 0 coin, then we can form amount j only if j is divisible by coins[0].


    long long int count(int coins[], int N, int sum) {
        vector<vector<long long int>>dp(N+1,vector<long long int>(sum+1,0));
        for(int i=0;i<=sum;i++)
        {
            if(i%coins[0]==0)
            {
                dp[0][i] = 1;
            }
        }
        
        for(int i=1;i<N;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                long long int temp = j;
                long long int take = 0;
                while(temp>=coins[i])
                {
                    temp-=coins[i];
                    take+=dp[i-1][temp];
                }
                long long int not_take = dp[i-1][j];
            
                dp[i][j] = take + not_take;
            }
        }
        return dp[N-1][sum];
    }

//Iterative Solution(Space Optimized) -> Bottom Up
//Since only last index is used in the above solution, we can optimize the space complexity by using 1D array.
  
    long long int count(int coins[], int N, int sum) {
        vector<long long int>prev(sum+1,0);
        vector<long long int>curr(sum+1,0);
        for(int i=0;i<=sum;i++)
        {
            if(i%coins[0]==0)
            {
                prev[i] = 1;
            }
        }
        
        for(int i=1;i<N;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                long long int temp = j;
                long long int take = 0;
                while(temp>=coins[i])
                {
                    temp-=coins[i];
                    take+=prev[temp];
                }
                long long int not_take = prev[j];
            
                curr[j] = take + not_take;
            }
            prev = curr;
        }
        return prev[sum];
    }

//Time Complexity: O(N*sum) where N is the number of coins and sum is the amount.
//Space Complexity: O(sum) , We are using a 1D array ( O(sum)).   