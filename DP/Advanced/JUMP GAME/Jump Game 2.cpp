// https: // leetcode.com/problems/jump-game-ii/description/

/*
Logic : Find the maxindex reach possible at any time
Time Complexity : O(N)
Space Complexity: O(1)
*/

int jump(vector<int> &nums)
{
    if (nums.size() <= 1)
        return 0;
    int prev_max = 0;
    int maxi = nums[0];
    int ans = 1;
    while (maxi < nums.size() - 1)
    {
        int temp = prev_max;
        prev_max = maxi;
        int temp1 = maxi;
        for (int i = temp + 1; i <= maxi; i++)
        {
            temp1 = max(temp1, nums[i] + i);
        }
        maxi = temp1;
        ans++;
    }
    return ans;
}