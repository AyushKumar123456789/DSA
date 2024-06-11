// https://leetcode.com/problems/continuous-subarray-sum/description/?envType=daily-question&envId=2024-06-08

/*
Question Is there any subbaray of size more than 1 whose sum is divisible by K.
*/

/*
Logic is If two prefix array sum value has same reminder when devided by K then, their difference is divisible by k i.e prefix array sum upto i and any prefix array sum before i-2 has same reminder then there is a subarray sum from tath index to i is divisible by k.
*/

bool checkSubarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == 1)
        return 0;
    int sum = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    sum = nums[0];
    for (int i = 1; i < n; i++)
    {
        sum += nums[i];

        mp[(sum - nums[i] - nums[i - 1]) % k]++;

        if (mp[sum % k])
        {
            return 1;
        }
    }
    return 0;
}