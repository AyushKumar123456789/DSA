// https://leetcode.com/problems/maximize-total-cost-of-alternating-subarrays/description/

#define ll long long

class Solution
{
public:
    long long maximumTotalCost(vector<int> &nums)
    {
        ll n = nums.size();
        vector<vector<ll>> dp(n, vector<ll>(2, 0));
        // dp[i][0] = max sum upto i such that ith index is added
        // dp[i][1] = max sum upto i such that ith index is subtracted
        // if ith index is added then next index can either added or subtracted
        // if ith index is subtracted then next index can only added
        // there for dp[i][0] = max(dp[i-1][1],dp[i-1][0]) + nums[i]
        // there for dp[i][1] = dp[i-1][0]-nums[i];
        // Base case dp[0][0] = nums[0] , dp[0][1] = -inf
        dp[0][0] = nums[0];
        dp[0][1] = -1000000001ll;
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]) + nums[i];
            dp[i][1] = dp[i - 1][0] - nums[i];
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};