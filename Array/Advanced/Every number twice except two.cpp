// https://leetcode.com/problems/single-number-iii/?envType=daily-question&envId=2024-05-31

// https://leetcode.com/problems/single-number-iii/solutions/5233120/find-significant-bit-of-xor-split-in-2-group-with-math-proof-0ms-beats-100/?envType=daily-question&envId=2024-05-31

/*
Problem:
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice.
Find the two elements that appear only once
    Good Question
*/

vector<int> singleNumber(vector<int> &nums)
{
    long long XOR = accumulate(nums.begin(), nums.end(), 0ll, bit_xor<int>());

    XOR = (XOR & (-XOR)); // This is used to find the least significant bit that is ON or the first bit that is ON.
    int A = 0, B = 0;
    for (auto it : nums)
    {
        if ((it & XOR) == 0)
        {
            A ^= it;
        }
        else
        {
            B ^= it;
        }
    }

    return {A, B};
}