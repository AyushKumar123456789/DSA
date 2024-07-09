// https://leetcode.com/problems/find-the-duplicate-number/description/

/*

GOOD QUESTIONS

Approach 1 : Use hashing
Time Complexity : O(n)
Space Complexity : O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &nums)
{
    int sum = 0;
    unordered_map<int, int> freq;
    for (int i = 0; i < nums.size(); i++)
    {
        freq[nums[i]]++;
        if (freq[nums[i]] > 1)
        {
            return nums[i];
        }
    }
    return 0;
}

/*
Decrease the space complexity to O(1)

Floyd's Cylce Method : Tortouis and rabbit method

If there is repeated number then only cycle will form.

remember to use do while loop , because in starting fast == slow.


*/

int findDuplicate(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];

    do
    {
        fast = nums[nums[fast]];
        slow = nums[slow];
    } while (fast != slow);
    fast = nums[0];
    while (fast != slow)
    {
        fast = nums[fast];
        slow = nums[slow];
    }
    return fast;
}