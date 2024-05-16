//https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1

#include<bits/stdc++.h>
using namespace std;

//Recursion with memoization

    bool f(int sum,int idx,int arr[],vector<vector<int>>&dp)
    {
        if(idx<0)
        {
            if(sum==0){
                return 1;
            }
            return 0;
        }
        
        if(dp[idx][sum]!=-1){
            return dp[idx][sum];
        }
        
        bool take = 0;
        if(sum>=arr[idx])
        {
            take = f(sum-arr[idx],idx-1,arr,dp);
        }
        bool not_take = f(sum,idx-1,arr,dp);
        return dp[idx][sum] = (take||not_take);
        
    }

    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
        vector<vector<int>>dp(N+1,vector<int>(sum+1,-1));
        if(sum%2==0)
        {
            return f(sum/2,N-1,arr,dp);
        }
        return 0;
    }

//Time complexity: O(N*sum)
//Space complexity: O(N*sum) for dp vector + O(N) for recursion stack


//Iterative approach Remove exptra recustion stack space 


    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
        vector<vector<int>>dp(N+1,vector<int>(sum+1,0));
        if(sum%2==0)
        {
            sum/=2;
            
            for(int i=0;i<=sum;i++)
            {
                if(i==arr[0])
                {
                    dp[0][i] = 1;
                }
            }
            
            for(int i=1;i<N;i++)
            {
                for(int j=0;j<=sum;j++)
                {
                    bool take = 0;
                    if(j>=arr[i])
                    {
                        take = dp[i-1][j-arr[i]];
                    }
                    bool not_take = dp[i-1][j];
                    dp[i][j] = (take || not_take);
                }
            }
            return dp[N-1][sum];
        }
        return 0;
    }

//Time complexity: O(N*sum)
//Space complexity: O(N*sum) for dp vector

//Optimized space complexity in iterative approach using prev and curr 1D vector of size sum+1

    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
        vector<int>prev(sum+1,0);
        vector<int>curr(sum+1,0);
        if(sum%2==0)
        {
            sum/=2;
            
            for(int i=0;i<=sum;i++)
            {
                if(i==arr[0])
                {
                    prev[i] = 1;
                }
            }
            
            for(int i=1;i<N;i++)
            {
                for(int j=0;j<=sum;j++)
                {
                    bool take = 0;
                    if(j>=arr[i])
                    {
                        take = prev[j-arr[i]];
                    }
                    bool not_take = prev[j];
                    curr[j] = (take || not_take);
                }
                prev = curr;;
            }
            return prev[sum];
        }
        return 0;
    }

    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
        if(sum%2==0)
        {
            sum/=2;
            vector<int>dp(sum+1,0);
            dp[0] = 1;
            for(int i=0;i<N;i++)
            {
                for(int j=sum;j>=0;j--)
                {
                    if(j>=arr[i])
                    {
                        dp[j] = dp[j] || dp[j-arr[i]];
                    }
                }
            }
            return dp[sum];
        }
        return 0;
    }

//Time complexity: O(N*sum)
//Space complexity: O(sum) for 1D dp vector