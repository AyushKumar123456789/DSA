// https : // leetcode.com/problems/coin-change/

int coinChange(vector<int> &coins, int amount)
{
    vector<vector<long long>> dp(coins.size() + 1, vector<long long>(amount + 1, INT_MAX));

    for (long long i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
        {
            dp[0][i] = i / coins[0];
        }
    }

    for (long long i = 1; i < coins.size(); i++)
    {
        dp[i][0] = 0;
        for (long long j = 0; j <= amount; j++)
        {
            long long take = INT_MAX;
            long long not_take = INT_MAX;
            if (coins[i] <= j)
            {
                take = dp[i][j - coins[i]] + 1;
            }
            not_take = dp[i - 1][j];
            dp[i][j] = min(take, not_take);
        }
    }
    return dp[coins.size() - 1][amount] == INT_MAX ? -1 : dp[coins.size() - 1][amount];
}