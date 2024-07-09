// https://leetcode.com/problems/3sum/description/

/*
Question is to found All unique triplets that form sum S.

*/

/*
Approach 1 :
Three For Loop
Time Complexity : O(N^3 * log(M)) M is max size of triplets
Space Complexity : O(M) + O(M)
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum_brute(vector<int> &nums, int val)
{
    set<vector<int>> st;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] + nums[k] == val)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

/*
Approach 2 :
        Hash Table Use , put element of between index i and j in hash table & check
        Time Complexity : O(N^2 * log(M)) M is max size of triplets
        Space Complexity : O(N) + O(M) + O(M)

*/

vector<vector<int>> threeSum_hash(vector<int> &nums, int val)
{
    set<vector<int>> st;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        unordered_map<int, int> freq;
        for (int j = i + 1; j < n; j++)
        {
            if (freq[val - nums[i] - nums[j]] > 0)
            {
                vector<int> temp = {nums[i], nums[j], val - nums[i] - nums[j]};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            freq[nums[j]]++;
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
}

/*
Approach 3 : Optimum Approach
First Sort the array and use two sum approach by fixing the ith element

Time Complexity : O(nlogn) + O(n^2) = O(n^2)
Space Complixity : O(M)
*/

vector<vector<int>> threeSum_optimum(vector<int> &nums, int val)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (i != 0 && nums[i] == nums[i - 1])
            continue;
        int l = i + 1;
        int h = n - 1;
        while (l < h)
        {
            int sum = nums[i] + nums[l] + nums[h];
            if (sum > val)
            {
                h--;
            }
            else if (sum < val)
            {
                l++;
            }
            else
            {
                ans.push_back({nums[i], nums[l], nums[h]});
                l++;
                h--;
                while (nums[l] == nums[l - 1] && l < h)
                    l++;
                while (nums[h] == nums[h + 1] && l < h)
                    h--;
            }
        }
    }
    return ans;
}
