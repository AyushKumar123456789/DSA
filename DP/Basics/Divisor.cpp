//https://leetcode.com/problems/divisor-game/description/

//DP solution

int dp[10001] = {0};

bool fun(int n)
{
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            dp[i] |= (!dp[i-j]); 
        }
    }
    return dp[n];
}

//Constructive

bool fun2(int n)
{
    return !(n&1);
}
