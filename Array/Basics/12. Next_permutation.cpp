// https://leetcode.com/problems/next-permutation/description/

/*
Inbuilt next_permutation(arr.begin(),arr.end()); -> return 1 if next permutation possible and convert arr to next permutaion of arr

Inbuilt prev_permutation(arr.begin(),arr.end()); -> return 1 if prev permutation possible and convert arr to prev permutaion of arr

*/

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {

        if (next_permutation(nums.begin(), nums.end()))
        {
            return;
        }
        else
        {
            sort(nums.begin(), nums.end());
        }
    }
};

// Time Complexity : O(N)
// Space Complexity: O(1)

/*
Logic : From end find the first digit from end where , number is greater then agae wala number and then reverse the arr from there to end and SO on
Dkhlo easy logic hai likhne k mann nhi hai
*/

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int pos = -1;
        for (int i = n - 1; i > 0; i--)
        {
            if (nums[i - 1] < nums[i])
            {
                pos = i;
                break;
            }
        }
        if (pos == -1)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {

            reverse(nums.begin() + pos, nums.end());
            int idx = upper_bound(nums.begin() + pos, nums.end(), nums[pos - 1]) - nums.begin();
            swap(nums[pos - 1], nums[idx]);
        }
    }
};

// Time Complexity : O(N)
// Space Complxity : O(1)