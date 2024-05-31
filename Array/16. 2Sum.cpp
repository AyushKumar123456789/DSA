// https://leetcode.com/problems/two-sum/description/

/*
1. Approach : Use Hsahtable, Time Complexity: O(N) , Space Complexity: O(N)
*/

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> numMap;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int complement = target - nums[i];
        if (numMap.count(complement))
        {
            return {numMap[complement], i};
        }
        numMap[nums[i]] = i;
    }

    return {}; // No solution found
}

/*
2. Approach : Use Sorting, Time Complexity: O(NlogN) , Space Complexity: O(1)
*/

vector<int> twoSum(vector<int> &nums, int target)
{

    vector<pair<int, int>> val(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        val[i].first = nums[i];
        val[i].second = i;
    }
    sort(val.begin(), val.end());
    int l = 0, r = nums.size() - 1;
    while (l < r)
    {
        if (val[l].first + val[r].first < target)
        {
            l++;
        }
        else if (val[l].first + val[r].first > target)
        {
            r--;
        }
        else
        {
            return {val[l].second, val[r].second};
        }
    }
    return {0};
}
